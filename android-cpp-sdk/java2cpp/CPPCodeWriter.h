#ifndef JAVA2CPP_CPP_CODE_WRITER_H
#define JAVA2CPP_CPP_CODE_WRITER_H

namespace model {

	class Entity;
	class Namespace;
	class Class;

} //namespace model

class CPPCodeWriter
{
public:
	typedef signals2::signal<void (std::size_t)> work_ammount_sig_t;
	typedef signals2::signal<void (std::size_t)> work_progress_sig_t;

	CPPCodeWriter(shared_ptr<model::Namespace> const &rns, filesystem::path const &dir);
	~CPPCodeWriter();

	void					operator()() const;

	work_ammount_sig_t&		workAmmount();
	work_progress_sig_t&	workProgress();

protected:
	void					write_class(shared_ptr<model::Class> const &c, filesystem::path const &dir) const;
	void					write_entity(shared_ptr<model::Entity> entity, std::size_t *progress_cnter, bool count_only) const;

private:
	shared_ptr<model::Namespace>	m_RootNS;
	filesystem::path				m_Dir;
	work_ammount_sig_t				m_WorkAmmount;
	work_progress_sig_t				m_WorkProgress;

};

#endif //JAVA2CPP_CPP_CODE_WRITER_H
