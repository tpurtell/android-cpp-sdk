#ifndef J2CPP_FIELD_HPP
#define J2CPP_FIELD_HPP

#include <j2cpp/config.hpp>
#include <j2cpp/environment.hpp>
#include <j2cpp/get_class.hpp>
#include <j2cpp/get_field_id.hpp>
#include <j2cpp/local_ref.hpp>

namespace j2cpp {

	template < typename Type >
	struct static_field_access
	{
	};

	template < typename Type >
	struct field_access
	{
	};

	template < const char *Class, const char *Name, const char *Signature, typename Type >
	class static_field
	{
	public:

		inline static_field& operator =(Type const &v)
		{
			static_field_access<Type>::set(
				get_class<Class>(),
				get_field_id<Class,Name,Signature,true>(),
				v.get_jtype()
			);
			return *this;
		}

		inline operator Type ()
		{
			return static_field_access<Type>::get(
				get_class<Class>(),
				get_field_id<Class,Name,Signature,true>()
			);
		}
	};

	template < const char *Class, const char *Name, const char *Signature, typename Type >
	class field
	{
	public:
		field(jobject jobj): m_jobject(jobj) {}

		template < typename AssignType >
		inline field& operator =(AssignType const &v)
		{
			field_access<Type>::set(
				m_jobject,
				get_field_id<Class,Name,Signature,false>(),
				v
			);
			return *this;
		}

		template < typename CastType >
		inline operator CastType ()
		{
			return field_access<Type>::get(
				m_jobject,
				get_field_id<Class,Name,Signature,false>()
			);
		}

	private:
		jobject m_jobject;
	};


	template < typename Type >
	struct static_field_access< local_ref<Type> >
	{
		static void set(jclass c, jfieldID f, local_ref<Type> const &v)
		{
			environment::get().get_jenv()->SetStaticObjectField(c, f, v.get_jtype());
		}

		static local_ref<Type> get(jclass c, jfieldID f)
		{
			return local_ref<Type>(
				environment::get().get_jenv()->GetStaticObjectField(c, f)
			);
		}
	};

	template < typename Type >
	struct field_access< local_ref<Type> >
	{
		static void set(jobject o, jfieldID f, local_ref<Type> const &v)
		{
			environment::get().get_jenv()->SetObjectField(o, f, v.get_jtype());
		}

		static local_ref<Type> get(jobject o, jfieldID f)
		{
			return local_ref<Type>(
				environment::get().get_jenv()->GetObjectField(o, f)
			);
		}
	};

	template <>
	struct static_field_access<cpp_boolean>
	{
		static void set(jclass c, jfieldID f, cpp_boolean const &v)
		{
			environment::get().get_jenv()->SetStaticBooleanField(c,f,v.get_jtype());
		}

		static cpp_boolean get(jclass c, jfieldID f)
		{
			return cpp_boolean(
				environment::get().get_jenv()->GetStaticBooleanField(c,f)
			);
		}
	};

	template <>
	struct static_field_access<cpp_byte>
	{
		static void set(jclass c, jfieldID f, cpp_byte const &v)
		{
			environment::get().get_jenv()->SetStaticByteField(c,f,v.get_jtype());
		}

		static cpp_byte get(jclass c, jfieldID f)
		{
			return cpp_byte(
					environment::get().get_jenv()->GetStaticByteField(c,f)
			);
		}
	};

	template <>
	struct static_field_access<cpp_char>
	{
		static void set(jclass c, jfieldID f, cpp_char const &v)
		{
			environment::get().get_jenv()->SetStaticCharField(c,f,v.get_jtype());
		}

		static cpp_char get(jclass c, jfieldID f)
		{
			return cpp_char(
				environment::get().get_jenv()->GetStaticCharField(c,f)
			);
		}
	};

	template <>
	struct static_field_access<cpp_double>
	{
		static void set(jclass c, jfieldID f, cpp_double const &v)
		{
			environment::get().get_jenv()->SetStaticDoubleField(c,f,v.get_jtype());
		}

		static cpp_double get(jclass c, jfieldID f)
		{
			return cpp_double(
				environment::get().get_jenv()->GetStaticDoubleField(c,f)
			);
		}
	};


	template <>
	struct static_field_access<cpp_float>
	{
		static void set(jclass c, jfieldID f, cpp_float const &v)
		{
			environment::get().get_jenv()->SetStaticFloatField(c,f,v.get_jtype());
		}

		static cpp_float get(jclass c, jfieldID f)
		{
			return cpp_float(
				environment::get().get_jenv()->GetStaticFloatField(c,f)
			);
		}
	};

	template <>
	struct static_field_access<cpp_int>
	{
		static void set(jclass c, jfieldID f, cpp_int const &v)
		{
			environment::get().get_jenv()->SetStaticIntField(c,f,v.get_jtype());
		}

		static cpp_int get(jclass c, jfieldID f)
		{
			return cpp_int(
				environment::get().get_jenv()->GetStaticIntField(c,f)
			);
		}
	};

	template <>
	struct static_field_access<cpp_long>
	{
		static void set(jclass c, jfieldID f, cpp_long const &v)
		{
			environment::get().get_jenv()->SetStaticLongField(c,f,v.get_jtype());
		}

		static cpp_long get(jclass c, jfieldID f)
		{
			return cpp_long(
				environment::get().get_jenv()->GetStaticLongField(c,f)
			);
		}
	};

	template <>
	struct static_field_access<cpp_short>
	{
		static void set(jclass c, jfieldID f, cpp_short const &v)
		{
			environment::get().get_jenv()->SetStaticShortField(c,f,v.get_jtype());
		}

		cpp_short get(jclass c, jfieldID f)
		{
			return cpp_short(
				environment::get().get_jenv()->GetStaticShortField(c,f)
			);
		}
	};

	//fields
	template <>
	struct field_access<cpp_boolean>
	{
		static void set(jobject o, jfieldID f, cpp_boolean const &v)
		{
			environment::get().get_jenv()->SetBooleanField(o,f,v.get_jtype());
		}

		static cpp_boolean get(jobject o, jfieldID f)
		{
			return cpp_boolean(
				environment::get().get_jenv()->GetBooleanField(o,f)
			);
		}
	};

	template <>
	struct field_access<cpp_byte>
	{
		static void set(jobject o, jfieldID f, cpp_byte const &v)
		{
			environment::get().get_jenv()->SetByteField(o,f,v.get_jtype());
		}

		static cpp_byte get(jobject o, jfieldID f)
		{
			return cpp_byte(
					environment::get().get_jenv()->GetByteField(o,f)
			);
		}
	};

	template <>
	struct field_access<cpp_char>
	{
		static void set(jobject o, jfieldID f, cpp_char const &v)
		{
			environment::get().get_jenv()->SetCharField(o,f,v.get_jtype());
		}

		static cpp_char get(jobject o, jfieldID f)
		{
			return cpp_char(
				environment::get().get_jenv()->GetCharField(o,f)
			);
		}
	};

	template <>
	struct field_access<cpp_double>
	{
		static void set(jobject o, jfieldID f, cpp_double const &v)
		{
			environment::get().get_jenv()->SetDoubleField(o,f,v.get_jtype());
		}

		static cpp_double get(jobject o, jfieldID f)
		{
			return cpp_double(
				environment::get().get_jenv()->GetDoubleField(o,f)
			);
		}
	};


	template <>
	struct field_access<cpp_float>
	{
		static void set(jobject o, jfieldID f, cpp_float const &v)
		{
			environment::get().get_jenv()->SetFloatField(o,f,v.get_jtype());
		}

		static cpp_float get(jobject o, jfieldID f)
		{
			return cpp_float(
				environment::get().get_jenv()->GetFloatField(o,f)
			);
		}
	};

	template <>
	struct field_access<cpp_int>
	{
		static void set(jobject o, jfieldID f, cpp_int const &v)
		{
			environment::get().get_jenv()->SetIntField(o,f,v.get_jtype());
		}

		static cpp_int get(jobject o, jfieldID f)
		{
			return cpp_int(
				environment::get().get_jenv()->GetIntField(o,f)
			);
		}
	};

	template <>
	struct field_access<cpp_long>
	{
		static void set(jobject o, jfieldID f, cpp_long const &v)
		{
			environment::get().get_jenv()->SetLongField(o,f,v.get_jtype());
		}

		static cpp_long get(jobject o, jfieldID f)
		{
			return cpp_long(
				environment::get().get_jenv()->GetLongField(o,f)
			);
		}
	};

	template <>
	struct field_access<cpp_short>
	{
		static void set(jobject o, jfieldID f, cpp_short const &v)
		{
			environment::get().get_jenv()->SetShortField(o,f,v.get_jtype());
		}

		cpp_short get(jobject o, jfieldID f)
		{
			return cpp_short(
				environment::get().get_jenv()->GetShortField(o,f)
			);
		}
	};



} //namespace j2cpp

#define J2CPP_DECLARE_FIELD(id)\
		static const char _j2cpp_field_name_##id[];\
		static const char _j2cpp_field_signature_##id[];

#define J2CPP_FIELD_NAME(id) _j2cpp_field_name_##id
#define J2CPP_FIELD_SIGNATURE(id) _j2cpp_field_signature_##id

#define J2CPP_DEFINE_FIELD(fqc, id, name, signature)\
		const char fqc::_j2cpp_field_name_##id[]=name;\
		const char fqc::_j2cpp_field_signature_##id[]=signature;

#endif //J2CPP_STATIC_FIELD_HPP
