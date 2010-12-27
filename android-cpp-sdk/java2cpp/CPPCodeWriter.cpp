#include "Precompile.h"
#include "CPPCodeWriter.h"
#include "model/Class.h"
#include "model/Namespace.h"
#include "model/Type.h"
#include "model/Method.h"
#include "model/Field.h"
#include "CPPCodeGenerator.h"

CPPCodeWriter::CPPCodeWriter(shared_ptr<model::Namespace> const &rns, filesystem::path const &dir)
: m_RootNS(rns)
, m_Dir(dir)
{

}

CPPCodeWriter::~CPPCodeWriter()
{
}

CPPCodeWriter::work_ammount_sig_t& CPPCodeWriter::workAmmount()
{
	return m_WorkAmmount;
}

CPPCodeWriter::work_progress_sig_t& CPPCodeWriter::workProgress()
{
	return m_WorkProgress;
}

void CPPCodeWriter::operator ()() const
{
	std::size_t num_classes(0);
	m_RootNS->visit(bind(&CPPCodeWriter::write_entity, this, _1, &num_classes, true));
	m_WorkAmmount(num_classes);
	num_classes=0;
	m_RootNS->visit(bind(&CPPCodeWriter::write_entity, this, _1, &num_classes, false));

}

void CPPCodeWriter::write_class(shared_ptr<model::Class> const &c, filesystem::path const &dir) const
{
	try
	{
		std::stack<filesystem::path> non_existing_dirs;
		filesystem::path tmp_dir(dir);
		while(!filesystem::exists(tmp_dir))
		{
			non_existing_dirs.push(tmp_dir);
			if(!tmp_dir.has_parent_path())
				break;
			tmp_dir=tmp_dir.parent_path();
		}
		
		while(!non_existing_dirs.empty())
		{
			filesystem::create_directory(non_existing_dirs.top());
			non_existing_dirs.pop();
		}
		
		filesystem::path header_file_path(dir);
		header_file_path/=(c->get_name()+".hpp");
		std::ofstream generated_file(header_file_path.native_file_string().c_str(),std::ios_base::out | std::ios_base::trunc);
		if(generated_file.is_open())
			CPPCodeGenerator(m_RootNS,c)(generated_file);
	}
	catch(std::exception const &e)
	{
		std::string strWhat=e.what();	
	}
}

void CPPCodeWriter::write_entity(shared_ptr<model::Entity> entity, std::size_t *progress_cnter, bool count_only) const
{
	if(shared_ptr<model::Class> classEntity=shared_ptr<model::Class>(entity,detail::dynamic_cast_tag()))
	{
		if(shared_ptr<model::Namespace> classNamespace=shared_ptr<model::Namespace>(classEntity->get_parent(), detail::dynamic_cast_tag()))
		{
			*progress_cnter=*progress_cnter+1;
			if(!count_only)
			{
				write_class(classEntity,m_Dir/classNamespace->get_java_class_path());
				m_WorkProgress(*progress_cnter);
			}
		}
	}
}