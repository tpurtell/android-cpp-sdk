#include "Precompile.h"
#include "CPPCodeGenerator.h"
#include "model/Class.h"
#include "model/Namespace.h"
#include "model/Type.h"
#include "model/Method.h"
#include "model/Field.h"
#include "model/ProperClassMethods.h"

std::size_t CPPCodeGenerator::s_default_comment_eq_width=80;
std::string CPPCodeGenerator::s_default_generator("java2cpp");

CPPCodeGenerator::CPPCodeGenerator(shared_ptr<model::Namespace> const &rns, shared_ptr<model::Class> const &c)
: m_RootNS(rns)
, m_Class(c)
, m_comment_eq_width(s_default_comment_eq_width)
, m_generator(s_default_generator)
{
	BOOST_ASSERT(m_RootNS);
	BOOST_ASSERT(m_Class);
	BOOST_ASSERT(!m_Class->is_nested());
}


CPPCodeGenerator::~CPPCodeGenerator()
{
}

std::ostream& CPPCodeGenerator::operator ()(std::ostream &os) const
{
	begin_comment(os);
	write_header(os);
	end_comment(os);

	os << std::endl <<std::endl;
	

	std::set< shared_ptr<model::Class> > class_dependencies;
	m_Class->visit(bind(&CPPCodeGenerator::collect_class_dependencies, this, _1, ref(class_dependencies)));

	os << "#ifndef J2CPP_INCLUDE_IMPLEMENTATION" << std::endl << std::endl;

	std::string strIFNDEF=m_Class->get_cxx_include_path();
	algorithm::to_upper(strIFNDEF);
	algorithm::replace_all(strIFNDEF,"/","_");



	os << "#ifndef J2CPP_" << strIFNDEF << "_HPP_DECL" << std::endl;
	os << "#define J2CPP_" << strIFNDEF << "_HPP_DECL" << std::endl;

	os << std::endl << std::endl;



	BOOST_FOREACH(shared_ptr<model::Class> dependend_class, class_dependencies)
	{
		if(dependend_class==m_Class) continue;
		std::vector< shared_ptr<model::Entity> > parentEntities;
		if(shared_ptr<model::Entity> parentEntity=dependend_class->get_parent())
		{
			do
			{
				parentEntities.push_back(parentEntity);
				parentEntity=parentEntity->get_parent();
			}
			while(parentEntity && parentEntity!=m_RootNS);
		}
		os << "namespace j2cpp { ";
		for(std::size_t ns=0;ns<parentEntities.size();++ns)
		{
			if(shared_ptr<model::Namespace> enclosingNamespace=shared_ptr<model::Namespace>(parentEntities[parentEntities.size()-ns-1],detail::dynamic_cast_tag()))
			{
				os << "namespace " << enclosingNamespace->get_name() << " { ";
			}
			else
			if(shared_ptr<model::Class> enclosingClass=shared_ptr<model::Class>(parentEntities[parentEntities.size()-ns-1],detail::dynamic_cast_tag()))
			{
				os << "namespace " << enclosingClass->get_name() << "_ { ";
			}
		}
		os << "class " << dependend_class->get_name() << ";";
		for(std::size_t ns=0;ns<parentEntities.size();++ns)
			os << " }";		
		os << " }" << std::endl;
	}
	os << std::endl << std::endl;

	std::set<std::string> dependenciesIncludes;

	BOOST_FOREACH(shared_ptr<model::Class> dependend_class, class_dependencies)
	{
		if(dependend_class==m_Class) continue;
		dependenciesIncludes.insert(dependend_class->get_cxx_include_path());
	}

	BOOST_FOREACH(std::string incPath, dependenciesIncludes)
	{
		os << "#include <" << incPath << ".hpp>" << std::endl;
	}
	os << std::endl << std::endl;


	std::vector< shared_ptr<model::Namespace> > enclosingNamespaces;
	if(shared_ptr<model::Namespace> enclosingNamespace=m_Class->get_namespace())
	{
		do
		{
			enclosingNamespaces.push_back(enclosingNamespace);
			enclosingNamespace=enclosingNamespace->get_parent_namespace();
		}
		while(enclosingNamespace && enclosingNamespace!=m_RootNS);
	}
	

	os << "namespace j2cpp {" << std::endl << std::endl;

	for(std::size_t ns=0;ns<enclosingNamespaces.size();++ns)
	{
		if(ns) os << " ";
		os << "namespace " << enclosingNamespaces[enclosingNamespaces.size()-ns-1]->get_name() << " {";
	}
	os << std::endl << std::endl;

	write_class(os,1,m_Class);
	
	for(std::size_t ns=0;ns<enclosingNamespaces.size();++ns)
		os << "} //namespace " << enclosingNamespaces[ns]->get_name() << std::endl;

	os << std::endl;
	
	os << "} //namespace j2cpp" << std::endl << std::endl;

	


	os << "#endif //J2CPP_" << strIFNDEF << "_HPP_DECL" << std::endl << std::endl;
	
	os << "#else //J2CPP_INCLUDE_IMPLEMENTATION" << std::endl << std::endl;

	os << "#ifndef J2CPP_" << strIFNDEF << "_HPP_IMPL" << std::endl;
	os << "#define J2CPP_" << strIFNDEF << "_HPP_IMPL" << std::endl << std::endl;

	//BOOST_FOREACH(shared_ptr<model::Class> dependend_class, class_dependencies)
	//{
	//	if(dependend_class==m_Class) continue;
	//	os << "#include <" << dependend_class->get_cxx_include_path() << ".hpp>" << std::endl;
	//}

	//os << std::endl << std::endl;

	os << "namespace j2cpp {" << std::endl << std::endl;

	write_class_definitions(os,m_Class) << std::endl;
	

	os << "} //namespace j2cpp" << std::endl << std::endl;

	os << "#endif //J2CPP_" << strIFNDEF << "_HPP_IMPL" << std::endl << std::endl;

	os << "#endif //J2CPP_INCLUDE_IMPLEMENTATION" << std::endl;
	
	return os;
}


std::ostream& CPPCodeGenerator::indent(std::ostream &os, std::size_t n) const
{
	for(std::size_t i=0;i<n;++i)
		os << "\t";
	return os;
}

std::ostream& CPPCodeGenerator::begin_comment(std::ostream &os) const
{
	os << "/*";
	for(std::size_t n=0;n<m_comment_eq_width;++n) os << "=";
	os << std::endl;
	return os;
}

std::ostream& CPPCodeGenerator::end_comment(std::ostream &os) const
{
	for(std::size_t n=0;n<m_comment_eq_width;++n) os << "=";
	os << "*/";
	os << std::endl;
	return os;
}

std::ostream& CPPCodeGenerator::write_header(std::ostream &os) const
{
	os <<
		"  code generated by: " << m_generator << std::endl;
	os <<
		"  class: " << m_Class->get_java_class_name() << ::std::endl;
	return os;
}

std::ostream& CPPCodeGenerator::write_class(std::ostream &os, std::size_t indent_pos, shared_ptr<model::Class> const &clazz) const
{
	iterator_range<model::Entity::children_by_kind_t::const_iterator>
		embeddedClasses=clazz->get_children_of_kind(model::Entity::kClass);

	indent(os,indent_pos) << "class " << clazz->get_name() << ";" << std::endl;

	if(!embeddedClasses.empty())
	{
		indent(os,indent_pos) << "namespace " << clazz->get_name() << "_ {" << std::endl << std::endl;
		
		BOOST_FOREACH(shared_ptr<model::Entity> entity, embeddedClasses)
		{
			shared_ptr<model::Class> embeddedClass=shared_ptr<model::Class>(entity, detail::dynamic_cast_tag());
			BOOST_ASSERT(embeddedClass);
			write_class(os,indent_pos+1,embeddedClass);
		}
		indent(os,indent_pos) << "} //namespace " << clazz->get_name() << "_" << std::endl << std::endl;
	}

	indent(os,indent_pos) <<
		"class " << clazz->get_name() << std::endl;
	indent(os,indent_pos+1) <<
		": public cpp_object<" << clazz->get_name() << ">" << std::endl;
	indent(os,indent_pos) <<
		"{" << std::endl;
	indent(os,indent_pos) <<
		"public:" << std::endl << std::endl;

	//declare j2cpp class
	indent(os,indent_pos+1) <<
		"J2CPP_DECLARE_CLASS" << std::endl << std::endl;
	
	//declare j2cpp class methods
	for(std::size_t m=0;m<clazz->get_methods_count();++m)
	{
		shared_ptr<model::Method> pMethod=clazz->get_method(m);
		BOOST_ASSERT(pMethod);
		indent(os,indent_pos+1) << "J2CPP_DECLARE_METHOD(" << m << ")" << std::endl;
	}

	for(std::size_t f=0;f<clazz->get_fields_count();++f)
	{
		shared_ptr<model::Field> pField=clazz->get_field(f);
		BOOST_ASSERT(pField);
		indent(os,indent_pos+1) << "J2CPP_DECLARE_FIELD(" << f << ")" << std::endl;
	}


	if(!embeddedClasses.empty())
	{
		os << std::endl;
		BOOST_FOREACH(shared_ptr<model::Entity> entity, embeddedClasses)
		{
			shared_ptr<model::Class> embeddedClass=shared_ptr<model::Class>(entity, detail::dynamic_cast_tag());
			BOOST_ASSERT(embeddedClass);
			indent(os,indent_pos+1) <<
				"typedef " << clazz->get_name() << "_::" << embeddedClass->get_name() << " " << embeddedClass->get_name() << ";" << std::endl;
		}
	}
	
	os << std::endl;
	indent(os,indent_pos+1) << "explicit " << clazz->get_name() << "(jobject jobj)" << std::endl;
	indent(os,indent_pos+1) << ": cpp_object<" << clazz->get_name() << ">(jobj)" << std::endl;
	if(clazz->get_fields_count())
	{
		for(std::size_t f=0;f<clazz->get_fields_count();++f)
		{
			shared_ptr<model::Field> pField=clazz->get_field(f);
			BOOST_ASSERT(pField);
			if(!pField->test_access_flag(model::ClassMember::kPrivate))
			{
				if(!pField->test_access_flag(model::ClassMember::kStatic))
				{
					indent(os,indent_pos+1);
					os << ", " << pField->get_name() << "(jobj)" << std::endl;
				}
			}
		}
	}
	indent(os,indent_pos+1) << "{" << std::endl;
	indent(os,indent_pos+1) << "}" << std::endl;

	os << std::endl;

	if(shared_ptr<model::Class> pSuper=clazz->get_super())
	{
		indent(os,indent_pos+1) << "operator local_ref<" << pSuper->get_cxx_class_name() << ">() const;" << std::endl;
	}

	for(std::size_t iface=0;iface<clazz->get_interfaces_count();++iface)
	{
		shared_ptr<model::Class> pInterface=clazz->get_interface(iface);
		BOOST_ASSERT(pInterface);
		indent(os,indent_pos+1) << "operator local_ref<" << pInterface->get_cxx_class_name() << ">() const;" << std::endl;
	}

	os << std::endl;

	
	model::ProperClassMethods properMethods(clazz);
	
	if(properMethods.get_methods_count())
	{
		os << std::endl;
		
		for(std::size_t m=0;m<properMethods.get_methods_count();++m)
		{
			model::ProperClassMethods::proper_method pm=properMethods.get_method(m);

			shared_ptr<model::Method> pMethod=pm.m_method;
			BOOST_ASSERT(pMethod);
			if(pMethod->test_access_flag(model::ClassMember::kPublic))
			{
				if(pMethod->is_constructor())
				{
					if(pMethod->test_access_flag(model::ClassMember::kStatic))
						continue;

					indent(os,indent_pos+1);

					os << clazz->get_name() << "(";
					
					//method arguments
					for(std::size_t arg=0;arg<pMethod->get_argument_types().size();++arg)
					{
						if(arg) os << ", ";
						shared_ptr<model::Type> methodArgType=pMethod->get_argument_types()[arg];
						BOOST_ASSERT(methodArgType);
						if(methodArgType->is_intrinsic())
							os << methodArgType->get_cxx_type();						
						else
							os << "local_ref< " << methodArgType->get_cxx_type() << " >";
						os << " const&";
					}
					os << ");" << std::endl;
				}
				else
				{
					indent(os,indent_pos+1);
				
					if(pMethod->test_access_flag(model::ClassMember::kStatic))
						os << "static ";

					//return type
					if(pMethod->get_return_type()->is_intrinsic())
						os << pMethod->get_return_type()->get_cxx_type();
					else
						os << "local_ref< " << pMethod->get_return_type()->get_cxx_type() << " >";
					
					//method name
					os << " " << transform_method_name(pm.m_proper_name) << "(";
					
					//method arguments
					for(std::size_t arg=0;arg<pMethod->get_argument_types().size();++arg)
					{
						if(arg) os << ", ";
						shared_ptr<model::Type> methodArgType=pMethod->get_argument_types()[arg];
						BOOST_ASSERT(methodArgType);
						if(methodArgType->is_intrinsic())
							os << methodArgType->get_cxx_type();						
						else
							os << "local_ref< " << methodArgType->get_cxx_type() << " >";
							
						os << " const&";
					}
					os << ");" << std::endl;
				}
			}
		}
	}

	if(clazz->get_fields_count())
	{
		os << std::endl;
		for(std::size_t f=0;f<clazz->get_fields_count();++f)
		{
			shared_ptr<model::Field> pField=clazz->get_field(f);
			BOOST_ASSERT(pField);

			if(pField->test_access_flag(model::ClassMember::kPublic))
			{
				indent(os,indent_pos+1);
				if(pField->test_access_flag(model::ClassMember::kStatic))
				{
					os << "static static_field< J2CPP_CLASS_NAME, J2CPP_FIELD_NAME(" << f << "), J2CPP_FIELD_SIGNATURE(" << f << "), ";
					if(pField->get_type()->is_intrinsic())
						os << pField->get_type()->get_cxx_type();
					else
						os << "local_ref< " << pField->get_type()->get_cxx_type() << " >";
					os << " > " << pField->get_name() << ";" << std::endl;
				}
				else
				{
					os << "field< J2CPP_CLASS_NAME, J2CPP_FIELD_NAME(" << f << "), J2CPP_FIELD_SIGNATURE(" << f << "), ";
					if(pField->get_type()->is_intrinsic())
						os << pField->get_type()->get_cxx_type();
					else
						os << "local_ref< " << pField->get_type()->get_cxx_type() << " >";
					os << " > " << pField->get_name() << ";" << std::endl;
				}
			}
		}
	}
	
	indent(os,indent_pos) <<
		"}; //class " << clazz->get_name() << std::endl << std::endl;

	return os;
}

std::ostream& CPPCodeGenerator::write_class_definitions(std::ostream &os, shared_ptr<model::Class> const &clazz) const
{
	iterator_range<model::Entity::children_by_kind_t::const_iterator>
		embeddedClasses=clazz->get_children_of_kind(model::Entity::kClass);

	if(!embeddedClasses.empty())
	{
		os << std::endl;
		BOOST_FOREACH(shared_ptr<model::Entity> entity, embeddedClasses)
		{
			shared_ptr<model::Class> embeddedClass=shared_ptr<model::Class>(entity, detail::dynamic_cast_tag());
			BOOST_ASSERT(embeddedClass);
			write_class_definitions(os,embeddedClass);
		}
		os << std::endl;
	}

	os << std::endl;

	if(shared_ptr<model::Class> pSuper=clazz->get_super())
	{
		os << std::endl;
		indent(os,0) << clazz->get_cxx_class_name() << "::operator local_ref<" << pSuper->get_cxx_class_name() << ">() const" << std::endl;
		indent(os,0) << "{" << std::endl;
		indent(os,1) << "return local_ref<" << pSuper->get_cxx_class_name() << ">(get_jtype());" << std::endl;
		indent(os,0) << "}" << std::endl;
	}

	for(std::size_t iface=0;iface<clazz->get_interfaces_count();++iface)
	{
		os << std::endl;
		shared_ptr<model::Class> pInterface=clazz->get_interface(iface);
		BOOST_ASSERT(pInterface);
		indent(os,0) << clazz->get_cxx_class_name() << "::operator local_ref<" << pInterface->get_cxx_class_name() << ">() const" << std::endl;
		indent(os,0) << "{" << std::endl;
		indent(os,1) << "return local_ref<" << pInterface->get_cxx_class_name() << ">(get_jtype());" << std::endl;
		indent(os,0) << "}" << std::endl;
	}
	
	model::ProperClassMethods properMethods(clazz);
	
	if(properMethods.get_methods_count())
	{
		os << std::endl;
		for(std::size_t m=0;m<properMethods.get_methods_count();++m)
		{
			model::ProperClassMethods::proper_method pm=properMethods.get_method(m);

			shared_ptr<model::Method> pMethod=pm.m_method;//clazz->get_method(m);
			BOOST_ASSERT(pMethod);

			if(pMethod->test_access_flag(model::ClassMember::kPublic))
			{
				if(pMethod->is_constructor())
				{
					if(pMethod->test_access_flag(model::ClassMember::kStatic))
						continue;

					if(!pMethod->test_access_flag(model::ClassMember::kPublic))
						continue;

					os << std::endl;
					
					indent(os,0) << clazz->get_cxx_class_name() << "::" << clazz->get_name() << "(";

					//method arguments
					for(std::size_t arg=0;arg<pMethod->get_argument_types().size();++arg)
					{
						if(arg) os << ", ";
						shared_ptr<model::Type> methodArgType=pMethod->get_argument_types()[arg];
						BOOST_ASSERT(methodArgType);
						if(methodArgType->is_intrinsic())
							os << methodArgType->get_cxx_type();						
						else
							os << "local_ref< " << methodArgType->get_cxx_type() << " >";

						format argNameFmt(" const &a%1%");
						argNameFmt % arg;
						os << argNameFmt.str();
					}
					os << ")" << std::endl;

					indent(os,0) << ": cpp_object<" << clazz->get_cxx_class_name() << ">(" << std::endl;
					indent(os,1) << "environment::get().get_jenv()->NewObject(" << std::endl;
					indent(os,2) << "get_class<" << clazz->get_cxx_class_name() << "::J2CPP_CLASS_NAME>()," << std::endl;
					indent(os,2) << "get_method_id<"
						<< clazz->get_cxx_class_name() << "::J2CPP_CLASS_NAME, "
						<< clazz->get_cxx_class_name() << "::J2CPP_METHOD_NAME(" << m << "), "
						<< clazz->get_cxx_class_name() << "::J2CPP_METHOD_SIGNATURE(" << m << "), false>()";
					
					if(!pMethod->get_argument_types().empty())
					{
						os << "," << std::endl;
						indent(os,2);

						//method arguments
						for(std::size_t arg=0;arg<pMethod->get_argument_types().size();++arg)
						{
							if(arg) os << ", ";
							os << "a" << arg << ".get_jtype()";
						}
					}
					
					os << std::endl;
					indent(os,1) << ")" << std::endl;
					indent(os,0) << ")" << std::endl;
					
					if(clazz->get_fields_count())
					{
						for(std::size_t f=0;f<clazz->get_fields_count();++f)
						{
							shared_ptr<model::Field> pField=clazz->get_field(f);
							BOOST_ASSERT(pField);
							if(pField->test_access_flag(model::ClassMember::kPublic))
							{
								if(!pField->test_access_flag(model::ClassMember::kStatic))
								{
									indent(os,0) << ", " << pField->get_name() << "(get_jtype())" << std::endl;
								}
							}
						}
					}
					indent(os,0) << "{" << std::endl;
					indent(os,0) << "}" << std::endl;
					os << std::endl;
				}
				else
				{
					indent(os,0);
					
					//return type
					if(pMethod->get_return_type()->is_intrinsic())
						os << pMethod->get_return_type()->get_cxx_type();
					else
						os << "local_ref< " << pMethod->get_return_type()->get_cxx_type() << " >";

					os << " " << clazz->get_cxx_class_name() << "::" << transform_method_name(pm.m_proper_name) << "(";
					
					//method arguments
					for(std::size_t arg=0;arg<pMethod->get_argument_types().size();++arg)
					{
						if(arg) os << ", ";
						shared_ptr<model::Type> methodArgType=pMethod->get_argument_types()[arg];
						BOOST_ASSERT(methodArgType);
						if(methodArgType->is_intrinsic())
							os << methodArgType->get_cxx_type();						
						else
							os << "local_ref< " << methodArgType->get_cxx_type() << " >";


						format argNameFmt(" const &a%1%");
						argNameFmt % arg;
						os << argNameFmt.str();
					}
					os << ")" << std::endl;


					//begin method implementation
					indent(os,0) << "{" << std::endl;

					//actual implementation
					indent(os,1);

					os << "return ";

					if(pMethod->get_return_type()->is_intrinsic())
						os << pMethod->get_return_type()->get_cxx_type();
					else
						os << "local_ref< " << pMethod->get_return_type()->get_cxx_type() << " >";

					os << "(" << std::endl;

					indent(os,2) << "environment::get().get_jenv()->Call";

					if(pMethod->test_access_flag(model::ClassMember::kStatic))
						os << "Static";

					os << pMethod->get_return_type()->get_jni_call_type() << "Method(" << std::endl;

					if(pMethod->test_access_flag(model::ClassMember::kStatic))
						indent(os,3) << "get_class<J2CPP_CLASS_NAME>()," << std::endl;
					else
						indent(os,3) << "get_jtype(),"  << std::endl;
					
					indent(os,3) << "get_method_id<J2CPP_CLASS_NAME, J2CPP_METHOD_NAME(" << m << "), J2CPP_METHOD_SIGNATURE(" << m << "), " << (pMethod->test_access_flag(model::ClassMember::kStatic)?"true":"false") << ">()";

					if(!pMethod->get_argument_types().empty())
					{
						os << "," << std::endl;
						indent(os,3);

						//method arguments
						for(std::size_t arg=0;arg<pMethod->get_argument_types().size();++arg)
						{
							if(arg) os << ", ";
							os << "a" << arg << ".get_jtype()";
						}
					}

					os << std::endl;
					indent(os,2) << ")" << std::endl;
					indent(os,1) << ");" << std::endl;

					//end method implementation
					indent(os,0) << "}" << std::endl;
				}
			}
			os << std::endl;
		}
	}

	if(clazz->get_fields_count())
	{
		os << std::endl;
		for(std::size_t f=0;f<clazz->get_fields_count();++f)
		{
			shared_ptr<model::Field> pField=clazz->get_field(f);
			BOOST_ASSERT(pField);
			indent(os,0);
			if(pField->test_access_flag(model::ClassMember::kPublic))
			{
				if(pField->test_access_flag(model::ClassMember::kStatic))
				{
					os << "static_field<" << std::endl;
					indent(os,1);
					os << clazz->get_cxx_class_name() << "::J2CPP_CLASS_NAME," << std::endl;
					indent(os,1);
					os << clazz->get_cxx_class_name() << "::J2CPP_FIELD_NAME(" << f << ")," << std::endl;
					indent(os,1);
					os << clazz->get_cxx_class_name() << "::J2CPP_FIELD_SIGNATURE(" << f << ")," << std::endl;
					indent(os,1);
					if(pField->get_type()->is_intrinsic())
						os << pField->get_type()->get_cxx_type();
					else
						os << "local_ref< " << pField->get_type()->get_cxx_type() << " >";
					os << std::endl;
					os << "> " << clazz->get_cxx_class_name() << "::" << pField->get_name() << ";" << std::endl << std::endl;
				}
			}
		}
	}

	os << std::endl;
	os << "J2CPP_DEFINE_CLASS(" << clazz->get_cxx_class_name() << ",\"" << clazz->get_java_signature() << "\")" << std::endl;
	
	for(std::size_t m=0;m<clazz->get_methods_count();++m)
	{
		shared_ptr<model::Method> pMethod=clazz->get_method(m);
		BOOST_ASSERT(pMethod);
		os <<
			"J2CPP_DEFINE_METHOD(" << clazz->get_cxx_class_name() << "," <<
			m << "," <<
			"\"" << pMethod->get_name() << "\"" << "," <<
			"\"" << pMethod->get_java_signature() << "\"" << ")" << std::endl;
	}

	for(std::size_t f=0;f<clazz->get_fields_count();++f)
	{
		shared_ptr<model::Field> pField=clazz->get_field(f);
		BOOST_ASSERT(pField);
		os <<
			"J2CPP_DEFINE_FIELD(" << clazz->get_cxx_class_name() << "," <<
			f << "," <<
			"\"" << pField->get_name() << "\"" << "," <<
			"\"" << pField->get_java_signature() << "\"" << ")" << std::endl;
	}

	return os;
}

void CPPCodeGenerator::collect_class_dependencies(shared_ptr<model::Entity> entity, std::set< shared_ptr<model::Class> > &dependencies) const
{
	if(shared_ptr<model::Class> clazz=shared_ptr<model::Class>(entity,detail::dynamic_cast_tag()))
	{
		if(shared_ptr<model::Class> pSuper=clazz->get_super())
			dependencies.insert(pSuper);

		for(std::size_t ifs=0;ifs<clazz->get_interfaces_count();++ifs)
		{
			if(shared_ptr<model::Class> pInterface=clazz->get_interface(ifs))
				dependencies.insert(pInterface);

		}

		for(std::size_t m=0;m<clazz->get_methods_count();++m)
		{
			if(shared_ptr<model::Method> classMethod=clazz->get_method(m))
			{
				if(classMethod->test_access_flag(model::ClassMember::kPublic))
				{
					for(std::size_t arg=0;arg<classMethod->get_argument_types().size();++arg)
					{
						if(shared_ptr<model::Type> pArgType=classMethod->get_argument_types()[arg])
						{
							if(pArgType->is_array())
							{
								if(shared_ptr<model::NDimArrayType> pArgArrayType=shared_ptr<model::NDimArrayType>(pArgType, detail::dynamic_cast_tag()))
								{
									if(shared_ptr<model::Type> pArgArrayElementType=pArgArrayType->get_element_type())
									{
										if(shared_ptr<model::Class> pArgArrayElementClass=pArgArrayElementType->get_class())
										{
											dependencies.insert(pArgArrayElementClass);
											//if(shared_ptr<model::Class> pParentClazz=pArgArrayElementClass->get_parent_class())
											//	dependencies.insert(pArgArrayElementClass->get_top_parent_class());
											//else
											//	dependencies.insert(pArgArrayElementClass);
										}
									}
								}
							}
							else
							{
								if(shared_ptr<model::Class> pArgTypeClass=pArgType->get_class())
								{
									dependencies.insert(pArgTypeClass);
									//if(shared_ptr<model::Class> pParentClazz=pArgTypeClass->get_parent_class())
									//	dependencies.insert(pArgTypeClass->get_top_parent_class());
									//else
									//	dependencies.insert(pArgTypeClass);
								}
									
							}
						}
					}
					if(shared_ptr<model::Type> pRetType=classMethod->get_return_type())
					{
						if(pRetType->is_array())
						{
							if(shared_ptr<model::NDimArrayType> pArgArrayType=shared_ptr<model::NDimArrayType>(pRetType, detail::dynamic_cast_tag()))
							{
								if(shared_ptr<model::Type> pArgArrayElementType=pArgArrayType->get_element_type())
								{
									if(shared_ptr<model::Class> pArgArrayElementClass=pArgArrayElementType->get_class())
									{
										dependencies.insert(pArgArrayElementClass);
										//if(shared_ptr<model::Class> pParentClazz=pArgArrayElementClass->get_parent_class())
										//	dependencies.insert(pArgArrayElementClass->get_top_parent_class());
										//else
										//	dependencies.insert(pArgArrayElementClass);
									}
								}
							}
						}
						else
						{
							if(shared_ptr<model::Class> pArgTypeClass=pRetType->get_class())
							{
								dependencies.insert(pArgTypeClass);
								//if(shared_ptr<model::Class> pParentClazz=pArgTypeClass->get_parent_class())
								//	dependencies.insert(pArgTypeClass->get_top_parent_class());
								//else
								//	dependencies.insert(pArgTypeClass);
							}
						}
					}
				}
			}
		}
		for(std::size_t f=0;f<clazz->get_fields_count();++f)
		{
			if(shared_ptr<model::Field> classField=clazz->get_field(f))
			{
				if(classField->test_access_flag(model::ClassMember::kPublic))
				{
					if(shared_ptr<model::Type> pFieldType=classField->get_type())
					{
						if(pFieldType->is_array())
						{
							if(shared_ptr<model::NDimArrayType> pArgArrayType=shared_ptr<model::NDimArrayType>(pFieldType, detail::dynamic_cast_tag()))
							{
								if(shared_ptr<model::Type> pArgArrayElementType=pArgArrayType->get_element_type())
								{
									if(shared_ptr<model::Class> pArgArrayElementClass=pArgArrayElementType->get_class())
									{
										dependencies.insert(pArgArrayElementClass);
										//if(shared_ptr<model::Class> pParentClazz=pArgArrayElementClass->get_parent_class())
										//	dependencies.insert(pArgArrayElementClass->get_top_parent_class());
										//else
										//	dependencies.insert(pArgArrayElementClass);
									}
								}
							}
						}
						else
						{
							if(shared_ptr<model::Class> pArgTypeClass=pFieldType->get_class())
							{
								dependencies.insert(pArgTypeClass);
								//if(shared_ptr<model::Class> pParentClazz=pArgTypeClass->get_parent_class())
								//	dependencies.insert(pArgTypeClass->get_top_parent_class());
								//else
								//	dependencies.insert(pArgTypeClass);
							}
						}
					}
				}
			}
		}
	}
}

std::string CPPCodeGenerator::transform_method_name(std::string const &original) const
{
	if(algorithm::is_equal()(original,"delete"))
		return std::string("deleteThe");
	if(algorithm::is_equal()(original,"and"))
		return std::string("And");
	if(algorithm::is_equal()(original,"or"))
		return std::string("Or");
	if(algorithm::is_equal()(original,"xor"))
		return std::string("Xor");
	if(algorithm::is_equal()(original,"union"))
		return std::string("Union");
	if(algorithm::is_equal()(original,"register"))
		return std::string("Register");
	return original;
}