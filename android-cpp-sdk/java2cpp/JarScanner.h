#ifndef JAVA2CPP_JAR_SCANNER_H
#define JAVA2CPP_JAR_SCANNER_H

namespace model {
	class Namespace;
	class Entity;
} //namespace model

class JarScanner
{
public:
	typedef signals2::signal<void (std::size_t)> work_ammount_sig_t;
	typedef signals2::signal<void (std::size_t)> work_progress_sig_t;

	JarScanner(QFileInfo const &jar);
	~JarScanner();


	work_ammount_sig_t&				workAmmount();
	work_progress_sig_t&			workProgress();

	shared_ptr<model::Namespace>	operator()();

protected:
	void							visitEntity(shared_ptr<JarFile> jarFile, shared_ptr<model::Namespace> ns, shared_ptr<model::Entity> entity, std::size_t *progress_cnter) const;

private:
	QFileInfo						m_JarPath;
	work_ammount_sig_t				m_WorkAmmount;
	work_progress_sig_t				m_WorkProgress;
};

#endif //JAVA2CPP_JAR_SCANNER_H