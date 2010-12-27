#ifndef JAVA2CPP_MODEL_CLASS_MEMBER_H
#define JAVA2CPP_MODEL_CLASS_MEMBER_H

namespace model {

	class Class;

	class ClassMember
		: public enable_shared_from_this2<ClassMember>
		, protected noncopyable
	{
	protected:
		ClassMember(shared_ptr<Class> const &c, std::string const &n);
	public:
		typedef enum
		{
			kPublic=0,
			kPrivate,
			kProtected,
			kStatic,
			kFinal,
			kSynchronized,
			kVolatile,
			kTransient,
			kNative,
			kInterface,
			kAbstract,
			kStrictfp,
			kAccessFlagsSize
		} eAccessFlags;

		typedef dynamic_bitset<> access_flags_t;

		virtual ~ClassMember();

		std::string const&	get_name() const;
		shared_ptr<Class>	get_class() const;
		virtual std::string	get_display_name() const;
		virtual std::string get_java_signature() const=0;
		
		bool				test_access_flag(eAccessFlags flag) const;
		void				set_access_flag(eAccessFlags flag, bool s);

	private:
		weak_ptr<Class>		m_class;
		std::string			m_name;
		access_flags_t		m_access_flags;
	};

} //namespace model

#endif //JAVA2CPP_MODEL_CLASS_MEMBER_H