#include "Precompile.h"
#include "JarScanner.h"
#include "model/Namespace.h"
#include "model/Class.h"
#include "JavaClassScanner.h"

JarScanner::JarScanner(QFileInfo const &jar)
: m_JarPath(jar)
{
}

JarScanner::~JarScanner()
{
}

JarScanner::work_ammount_sig_t& JarScanner::workAmmount()
{
	return m_WorkAmmount;
}

JarScanner::work_progress_sig_t& JarScanner::workProgress()
{
	return m_WorkProgress;
}

shared_ptr<model::Namespace> JarScanner::operator ()()
{
	std::string strJarAbsolutePath(m_JarPath.absoluteFilePath().toStdString());
	
	std::size_t numClasses(0);
	if(shared_ptr<JarFile> pJarFile=shared_ptr<JarFile>(jclass_jar_open(strJarAbsolutePath.c_str()), bind(&jclass_jar_close, _1)))
	{
		shared_ptr<model::Namespace> pRootNS=model::Entity::create<model::Namespace>(model::name = std::string());
		jclass_jar_rewind(pJarFile.get());
		
		for(const JarEntry *jEntry=jclass_jar_get_next_entry(pJarFile.get());jEntry;jEntry=jclass_jar_get_next_entry(pJarFile.get()))
		{
			std::string strEntryName(jclass_jar_entry_get_name(jEntry));
			
			if(algorithm::iends_with(strEntryName,".class")) //handle class file
			{
				iterator_range<std::string::iterator> classSuffix=algorithm::find_last(strEntryName,".class");
				iterator_range<std::string::iterator> embClass=algorithm::find_last(strEntryName,"$");

				if(embClass.empty()) //if it is not an embedded class
				{
					iterator_range<std::string::iterator> lastSlash=algorithm::find_last(strEntryName,"/");
					std::string strClassName(
						lastSlash.empty()?strEntryName.begin():lastSlash.end(),
						classSuffix.begin()
					);

					std::string strClassNamespaceName=lastSlash.empty()?
						std::string():
						std::string(strEntryName.begin(), lastSlash.begin()
					);
					
					algorithm::replace_all(strClassNamespaceName,"/",".");
					
					if(shared_ptr<model::Entity> pEntityExists=pRootNS->find_entity(strClassNamespaceName+"."+strClassName))
					{
						BOOST_ASSERT(shared_ptr<model::Class>(pEntityExists, detail::dynamic_cast_tag()));
						continue;
					}

					shared_ptr<model::Namespace> pNamespace=strClassNamespaceName.empty()?pRootNS:
						shared_ptr<model::Namespace>(pRootNS->find_entity(strClassNamespaceName) , detail::dynamic_cast_tag());
					BOOST_ASSERT(pNamespace);

					shared_ptr<model::Class> pNewClass=pNamespace->add_entity<model::Class>(model::name = strClassName); numClasses++;
					BOOST_ASSERT(pNewClass);
				}
				else
				{
					std::string strClassName(
						embClass.end(),
						classSuffix.begin()
					);

					std::string strParentClassName(
						strEntryName.begin(),
						embClass.begin()
					);
					
					algorithm::replace_all(strParentClassName,"/",".");
					algorithm::replace_all(strParentClassName,"$",".");
																	
					if(shared_ptr<model::Entity> pEntityExists=pRootNS->find_entity(strParentClassName+"."+strClassName))
					{
						BOOST_ASSERT(shared_ptr<model::Class>(pEntityExists, detail::dynamic_cast_tag()));
						continue;
					}

					BOOST_ASSERT(!strParentClassName.empty());
					shared_ptr<model::Class> pParentClass=shared_ptr<model::Class>(pRootNS->find_entity(strParentClassName), detail::dynamic_cast_tag());
					if(!pParentClass)
					{
						iterator_range<std::string::iterator> lastSlash=algorithm::find_last(strEntryName,"/");
						std::string strTopClassNamespaceName=lastSlash.empty()?
							std::string():
							std::string(strEntryName.begin(), lastSlash.begin()
						);
						
						algorithm::replace_all(strTopClassNamespaceName,"/",".");
						BOOST_ASSERT(!algorithm::is_equal()(strTopClassNamespaceName,strParentClassName));

						shared_ptr<model::Namespace> pTopClassNamespace=strTopClassNamespaceName.empty()?pRootNS:
							shared_ptr<model::Namespace>(pRootNS->find_entity(strTopClassNamespaceName) , detail::dynamic_cast_tag());
						BOOST_ASSERT(pTopClassNamespace);
													
						std::stack< std::pair<std::string, std::string> > parentClasses;
						do
						{
							iterator_range<std::string::iterator> lastDot=algorithm::find_last(strParentClassName,".");
							BOOST_ASSERT(!lastDot.empty());

							parentClasses.push( make_pair(
								std::string(lastDot.end(), strParentClassName.end()),
								strParentClassName )
							);
							
							strParentClassName=std::string(strParentClassName.begin(),lastDot.begin());
							if(algorithm::is_equal()(strParentClassName,strTopClassNamespaceName)) break;
							pParentClass=shared_ptr<model::Class>(pRootNS->find_entity(strParentClassName), detail::dynamic_cast_tag());
						}
						while(!pParentClass);

						BOOST_ASSERT(!parentClasses.empty());
						if(!pParentClass)
						{
							pParentClass=pTopClassNamespace->add_entity<model::Class>(model::name = parentClasses.top().first); numClasses++;
							parentClasses.pop();
						}

						BOOST_ASSERT(pParentClass);
													
						while(!parentClasses.empty())
						{
							pParentClass=pParentClass->add_entity<model::Class>(model::name = parentClasses.top().first); numClasses++;
							BOOST_ASSERT(pParentClass);
							parentClasses.pop();
						}
					}

					BOOST_ASSERT(pParentClass);
					shared_ptr<model::Class> pNewEmbeddedClass=pParentClass->add_entity<model::Class>(model::name = strClassName); numClasses++;
					BOOST_ASSERT(pNewEmbeddedClass);
				}					
			}
			else
			if(algorithm::iends_with(strEntryName,"/") && !algorithm::icontains(strEntryName,"-")) //handle namespace folder
			{
				std::string strNamespacePath=algorithm::erase_last_copy(strEntryName,"/");
				iterator_range<std::string::iterator> lastSlash=algorithm::find_last(strNamespacePath,"/");

				std::string strNamespaceName(
					lastSlash.empty()?strNamespacePath.begin():lastSlash.end(),
					strNamespacePath.end()
				);

				std::string strParentNamespaceName=lastSlash.empty()?
					std::string():
					std::string(strNamespacePath.begin(), lastSlash.begin()
				);

				algorithm::replace_all(strParentNamespaceName,"/",".");
				shared_ptr<model::Namespace> pParentNamespace=strParentNamespaceName.empty()?pRootNS:shared_ptr<model::Namespace>(pRootNS->find_entity(strParentNamespaceName) , detail::dynamic_cast_tag());
				BOOST_ASSERT(pParentNamespace);
				shared_ptr<model::Namespace> pNewNamespace=pParentNamespace->add_entity<model::Namespace>(model::name = strNamespaceName);
				BOOST_ASSERT(pNewNamespace);
			}
		}
		m_WorkAmmount(numClasses);
		std::size_t classProgress(0);
		pRootNS->visit(bind(&JarScanner::visitEntity, this, pJarFile, pRootNS, _1, &classProgress));
		return pRootNS;
	}
	return shared_ptr<model::Namespace>();
}

void JarScanner::visitEntity(shared_ptr<JarFile> jarFile, shared_ptr<model::Namespace> ns, shared_ptr<model::Entity> entity, std::size_t *progress_cnter) const
{
	if(shared_ptr<model::Class> classEntity=shared_ptr<model::Class>(entity,detail::dynamic_cast_tag()))
	{
		*progress_cnter=*progress_cnter+1;
		std::string strClassPath=classEntity->get_java_class_path()+".class";
		if(const JarEntry *jEntry=jclass_jar_get_entry(jarFile.get(),strClassPath.c_str()))
		{
			if(shared_ptr<char> pClassData=shared_ptr<char>(jclass_jar_entry_read(jarFile.get(),jEntry), bind(&free, _1)))
			{
				if(JavaClassScanner(ns,classEntity,pClassData).scan())
				{
									
				}
			}
		}
		m_WorkProgress(*progress_cnter);
	}
}