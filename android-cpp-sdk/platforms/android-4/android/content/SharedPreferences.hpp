/*================================================================================
  code generated by: java2cpp
  author: Zoran Angelov, mailto://baldzar@gmail.com
  class: android.content.SharedPreferences
================================================================================*/


#ifndef J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_ANDROID_CONTENT_SHAREDPREFERENCES_HPP_DECL
#define J2CPP_ANDROID_CONTENT_SHAREDPREFERENCES_HPP_DECL


namespace j2cpp { namespace android { namespace content { namespace SharedPreferences_ { class Editor; } } } }
namespace j2cpp { namespace android { namespace content { namespace SharedPreferences_ { class OnSharedPreferenceChangeListener; } } } }
namespace j2cpp { namespace java { namespace util { class Map; } } }
namespace j2cpp { namespace java { namespace lang { class String; } } }
namespace j2cpp { namespace java { namespace lang { class Object; } } }


#include <android/content/SharedPreferences.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/util/Map.hpp>


namespace j2cpp {

namespace android { namespace content {

	class SharedPreferences;
	namespace SharedPreferences_ {

		class Editor;
		class Editor
			: public object<Editor>
		{
		public:

			J2CPP_DECLARE_CLASS

			J2CPP_DECLARE_METHOD(0)
			J2CPP_DECLARE_METHOD(1)
			J2CPP_DECLARE_METHOD(2)
			J2CPP_DECLARE_METHOD(3)
			J2CPP_DECLARE_METHOD(4)
			J2CPP_DECLARE_METHOD(5)
			J2CPP_DECLARE_METHOD(6)
			J2CPP_DECLARE_METHOD(7)

			explicit Editor(jobject jobj)
			: object<Editor>(jobj)
			{
			}

			operator local_ref<java::lang::Object>() const;


			local_ref< android::content::SharedPreferences_::Editor > putString(local_ref< java::lang::String >  const&, local_ref< java::lang::String >  const&);
			local_ref< android::content::SharedPreferences_::Editor > putInt(local_ref< java::lang::String >  const&, jint);
			local_ref< android::content::SharedPreferences_::Editor > putLong(local_ref< java::lang::String >  const&, jlong);
			local_ref< android::content::SharedPreferences_::Editor > putFloat(local_ref< java::lang::String >  const&, jfloat);
			local_ref< android::content::SharedPreferences_::Editor > putBoolean(local_ref< java::lang::String >  const&, jboolean);
			local_ref< android::content::SharedPreferences_::Editor > remove(local_ref< java::lang::String >  const&);
			local_ref< android::content::SharedPreferences_::Editor > clear();
			jboolean commit();
		}; //class Editor

		class OnSharedPreferenceChangeListener;
		class OnSharedPreferenceChangeListener
			: public object<OnSharedPreferenceChangeListener>
		{
		public:

			J2CPP_DECLARE_CLASS

			J2CPP_DECLARE_METHOD(0)

			explicit OnSharedPreferenceChangeListener(jobject jobj)
			: object<OnSharedPreferenceChangeListener>(jobj)
			{
			}

			operator local_ref<java::lang::Object>() const;


			void onSharedPreferenceChanged(local_ref< android::content::SharedPreferences >  const&, local_ref< java::lang::String >  const&);
		}; //class OnSharedPreferenceChangeListener

	} //namespace SharedPreferences_

	class SharedPreferences
		: public object<SharedPreferences>
	{
	public:

		J2CPP_DECLARE_CLASS

		J2CPP_DECLARE_METHOD(0)
		J2CPP_DECLARE_METHOD(1)
		J2CPP_DECLARE_METHOD(2)
		J2CPP_DECLARE_METHOD(3)
		J2CPP_DECLARE_METHOD(4)
		J2CPP_DECLARE_METHOD(5)
		J2CPP_DECLARE_METHOD(6)
		J2CPP_DECLARE_METHOD(7)
		J2CPP_DECLARE_METHOD(8)
		J2CPP_DECLARE_METHOD(9)

		typedef SharedPreferences_::Editor Editor;
		typedef SharedPreferences_::OnSharedPreferenceChangeListener OnSharedPreferenceChangeListener;

		explicit SharedPreferences(jobject jobj)
		: object<SharedPreferences>(jobj)
		{
		}

		operator local_ref<java::lang::Object>() const;


		local_ref< java::util::Map > getAll();
		local_ref< java::lang::String > getString(local_ref< java::lang::String >  const&, local_ref< java::lang::String >  const&);
		jint getInt(local_ref< java::lang::String >  const&, jint);
		jlong getLong(local_ref< java::lang::String >  const&, jlong);
		jfloat getFloat(local_ref< java::lang::String >  const&, jfloat);
		jboolean getBoolean(local_ref< java::lang::String >  const&, jboolean);
		jboolean contains(local_ref< java::lang::String >  const&);
		local_ref< android::content::SharedPreferences_::Editor > edit();
		void registerOnSharedPreferenceChangeListener(local_ref< android::content::SharedPreferences_::OnSharedPreferenceChangeListener >  const&);
		void unregisterOnSharedPreferenceChangeListener(local_ref< android::content::SharedPreferences_::OnSharedPreferenceChangeListener >  const&);
	}; //class SharedPreferences

} //namespace content
} //namespace android

} //namespace j2cpp

#endif //J2CPP_ANDROID_CONTENT_SHAREDPREFERENCES_HPP_DECL

#else //J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_ANDROID_CONTENT_SHAREDPREFERENCES_HPP_IMPL
#define J2CPP_ANDROID_CONTENT_SHAREDPREFERENCES_HPP_IMPL

namespace j2cpp {




android::content::SharedPreferences_::Editor::operator local_ref<java::lang::Object>() const
{
	return local_ref<java::lang::Object>(get_jobject());
}

local_ref< android::content::SharedPreferences_::Editor > android::content::SharedPreferences_::Editor::putString(local_ref< java::lang::String > const &a0, local_ref< java::lang::String > const &a1)
{
	return call_method<
		android::content::SharedPreferences_::Editor::J2CPP_CLASS_NAME,
		android::content::SharedPreferences_::Editor::J2CPP_METHOD_NAME(0),
		android::content::SharedPreferences_::Editor::J2CPP_METHOD_SIGNATURE(0), 
		local_ref< android::content::SharedPreferences_::Editor >
	>(get_jobject(), a0, a1);
}

local_ref< android::content::SharedPreferences_::Editor > android::content::SharedPreferences_::Editor::putInt(local_ref< java::lang::String > const &a0, jint a1)
{
	return call_method<
		android::content::SharedPreferences_::Editor::J2CPP_CLASS_NAME,
		android::content::SharedPreferences_::Editor::J2CPP_METHOD_NAME(1),
		android::content::SharedPreferences_::Editor::J2CPP_METHOD_SIGNATURE(1), 
		local_ref< android::content::SharedPreferences_::Editor >
	>(get_jobject(), a0, a1);
}

local_ref< android::content::SharedPreferences_::Editor > android::content::SharedPreferences_::Editor::putLong(local_ref< java::lang::String > const &a0, jlong a1)
{
	return call_method<
		android::content::SharedPreferences_::Editor::J2CPP_CLASS_NAME,
		android::content::SharedPreferences_::Editor::J2CPP_METHOD_NAME(2),
		android::content::SharedPreferences_::Editor::J2CPP_METHOD_SIGNATURE(2), 
		local_ref< android::content::SharedPreferences_::Editor >
	>(get_jobject(), a0, a1);
}

local_ref< android::content::SharedPreferences_::Editor > android::content::SharedPreferences_::Editor::putFloat(local_ref< java::lang::String > const &a0, jfloat a1)
{
	return call_method<
		android::content::SharedPreferences_::Editor::J2CPP_CLASS_NAME,
		android::content::SharedPreferences_::Editor::J2CPP_METHOD_NAME(3),
		android::content::SharedPreferences_::Editor::J2CPP_METHOD_SIGNATURE(3), 
		local_ref< android::content::SharedPreferences_::Editor >
	>(get_jobject(), a0, a1);
}

local_ref< android::content::SharedPreferences_::Editor > android::content::SharedPreferences_::Editor::putBoolean(local_ref< java::lang::String > const &a0, jboolean a1)
{
	return call_method<
		android::content::SharedPreferences_::Editor::J2CPP_CLASS_NAME,
		android::content::SharedPreferences_::Editor::J2CPP_METHOD_NAME(4),
		android::content::SharedPreferences_::Editor::J2CPP_METHOD_SIGNATURE(4), 
		local_ref< android::content::SharedPreferences_::Editor >
	>(get_jobject(), a0, a1);
}

local_ref< android::content::SharedPreferences_::Editor > android::content::SharedPreferences_::Editor::remove(local_ref< java::lang::String > const &a0)
{
	return call_method<
		android::content::SharedPreferences_::Editor::J2CPP_CLASS_NAME,
		android::content::SharedPreferences_::Editor::J2CPP_METHOD_NAME(5),
		android::content::SharedPreferences_::Editor::J2CPP_METHOD_SIGNATURE(5), 
		local_ref< android::content::SharedPreferences_::Editor >
	>(get_jobject(), a0);
}

local_ref< android::content::SharedPreferences_::Editor > android::content::SharedPreferences_::Editor::clear()
{
	return call_method<
		android::content::SharedPreferences_::Editor::J2CPP_CLASS_NAME,
		android::content::SharedPreferences_::Editor::J2CPP_METHOD_NAME(6),
		android::content::SharedPreferences_::Editor::J2CPP_METHOD_SIGNATURE(6), 
		local_ref< android::content::SharedPreferences_::Editor >
	>(get_jobject());
}

jboolean android::content::SharedPreferences_::Editor::commit()
{
	return call_method<
		android::content::SharedPreferences_::Editor::J2CPP_CLASS_NAME,
		android::content::SharedPreferences_::Editor::J2CPP_METHOD_NAME(7),
		android::content::SharedPreferences_::Editor::J2CPP_METHOD_SIGNATURE(7), 
		jboolean
	>(get_jobject());
}


J2CPP_DEFINE_CLASS(android::content::SharedPreferences_::Editor,"android/content/SharedPreferences$Editor")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences_::Editor,0,"putString","(Ljava/lang/String;Ljava/lang/String;)Landroid/content/SharedPreferences$Editor;")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences_::Editor,1,"putInt","(Ljava/lang/String;I)Landroid/content/SharedPreferences$Editor;")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences_::Editor,2,"putLong","(Ljava/lang/String;J)Landroid/content/SharedPreferences$Editor;")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences_::Editor,3,"putFloat","(Ljava/lang/String;F)Landroid/content/SharedPreferences$Editor;")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences_::Editor,4,"putBoolean","(Ljava/lang/String;Z)Landroid/content/SharedPreferences$Editor;")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences_::Editor,5,"remove","(Ljava/lang/String;)Landroid/content/SharedPreferences$Editor;")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences_::Editor,6,"clear","()Landroid/content/SharedPreferences$Editor;")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences_::Editor,7,"commit","()Z")


android::content::SharedPreferences_::OnSharedPreferenceChangeListener::operator local_ref<java::lang::Object>() const
{
	return local_ref<java::lang::Object>(get_jobject());
}

void android::content::SharedPreferences_::OnSharedPreferenceChangeListener::onSharedPreferenceChanged(local_ref< android::content::SharedPreferences > const &a0, local_ref< java::lang::String > const &a1)
{
	return call_method<
		android::content::SharedPreferences_::OnSharedPreferenceChangeListener::J2CPP_CLASS_NAME,
		android::content::SharedPreferences_::OnSharedPreferenceChangeListener::J2CPP_METHOD_NAME(0),
		android::content::SharedPreferences_::OnSharedPreferenceChangeListener::J2CPP_METHOD_SIGNATURE(0), 
		void
	>(get_jobject(), a0, a1);
}


J2CPP_DEFINE_CLASS(android::content::SharedPreferences_::OnSharedPreferenceChangeListener,"android/content/SharedPreferences$OnSharedPreferenceChangeListener")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences_::OnSharedPreferenceChangeListener,0,"onSharedPreferenceChanged","(Landroid/content/SharedPreferences;Ljava/lang/String;)V")



android::content::SharedPreferences::operator local_ref<java::lang::Object>() const
{
	return local_ref<java::lang::Object>(get_jobject());
}

local_ref< java::util::Map > android::content::SharedPreferences::getAll()
{
	return call_method<
		android::content::SharedPreferences::J2CPP_CLASS_NAME,
		android::content::SharedPreferences::J2CPP_METHOD_NAME(0),
		android::content::SharedPreferences::J2CPP_METHOD_SIGNATURE(0), 
		local_ref< java::util::Map >
	>(get_jobject());
}

local_ref< java::lang::String > android::content::SharedPreferences::getString(local_ref< java::lang::String > const &a0, local_ref< java::lang::String > const &a1)
{
	return call_method<
		android::content::SharedPreferences::J2CPP_CLASS_NAME,
		android::content::SharedPreferences::J2CPP_METHOD_NAME(1),
		android::content::SharedPreferences::J2CPP_METHOD_SIGNATURE(1), 
		local_ref< java::lang::String >
	>(get_jobject(), a0, a1);
}

jint android::content::SharedPreferences::getInt(local_ref< java::lang::String > const &a0, jint a1)
{
	return call_method<
		android::content::SharedPreferences::J2CPP_CLASS_NAME,
		android::content::SharedPreferences::J2CPP_METHOD_NAME(2),
		android::content::SharedPreferences::J2CPP_METHOD_SIGNATURE(2), 
		jint
	>(get_jobject(), a0, a1);
}

jlong android::content::SharedPreferences::getLong(local_ref< java::lang::String > const &a0, jlong a1)
{
	return call_method<
		android::content::SharedPreferences::J2CPP_CLASS_NAME,
		android::content::SharedPreferences::J2CPP_METHOD_NAME(3),
		android::content::SharedPreferences::J2CPP_METHOD_SIGNATURE(3), 
		jlong
	>(get_jobject(), a0, a1);
}

jfloat android::content::SharedPreferences::getFloat(local_ref< java::lang::String > const &a0, jfloat a1)
{
	return call_method<
		android::content::SharedPreferences::J2CPP_CLASS_NAME,
		android::content::SharedPreferences::J2CPP_METHOD_NAME(4),
		android::content::SharedPreferences::J2CPP_METHOD_SIGNATURE(4), 
		jfloat
	>(get_jobject(), a0, a1);
}

jboolean android::content::SharedPreferences::getBoolean(local_ref< java::lang::String > const &a0, jboolean a1)
{
	return call_method<
		android::content::SharedPreferences::J2CPP_CLASS_NAME,
		android::content::SharedPreferences::J2CPP_METHOD_NAME(5),
		android::content::SharedPreferences::J2CPP_METHOD_SIGNATURE(5), 
		jboolean
	>(get_jobject(), a0, a1);
}

jboolean android::content::SharedPreferences::contains(local_ref< java::lang::String > const &a0)
{
	return call_method<
		android::content::SharedPreferences::J2CPP_CLASS_NAME,
		android::content::SharedPreferences::J2CPP_METHOD_NAME(6),
		android::content::SharedPreferences::J2CPP_METHOD_SIGNATURE(6), 
		jboolean
	>(get_jobject(), a0);
}

local_ref< android::content::SharedPreferences_::Editor > android::content::SharedPreferences::edit()
{
	return call_method<
		android::content::SharedPreferences::J2CPP_CLASS_NAME,
		android::content::SharedPreferences::J2CPP_METHOD_NAME(7),
		android::content::SharedPreferences::J2CPP_METHOD_SIGNATURE(7), 
		local_ref< android::content::SharedPreferences_::Editor >
	>(get_jobject());
}

void android::content::SharedPreferences::registerOnSharedPreferenceChangeListener(local_ref< android::content::SharedPreferences_::OnSharedPreferenceChangeListener > const &a0)
{
	return call_method<
		android::content::SharedPreferences::J2CPP_CLASS_NAME,
		android::content::SharedPreferences::J2CPP_METHOD_NAME(8),
		android::content::SharedPreferences::J2CPP_METHOD_SIGNATURE(8), 
		void
	>(get_jobject(), a0);
}

void android::content::SharedPreferences::unregisterOnSharedPreferenceChangeListener(local_ref< android::content::SharedPreferences_::OnSharedPreferenceChangeListener > const &a0)
{
	return call_method<
		android::content::SharedPreferences::J2CPP_CLASS_NAME,
		android::content::SharedPreferences::J2CPP_METHOD_NAME(9),
		android::content::SharedPreferences::J2CPP_METHOD_SIGNATURE(9), 
		void
	>(get_jobject(), a0);
}


J2CPP_DEFINE_CLASS(android::content::SharedPreferences,"android/content/SharedPreferences")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences,0,"getAll","()Ljava/util/Map;")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences,1,"getString","(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences,2,"getInt","(Ljava/lang/String;I)I")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences,3,"getLong","(Ljava/lang/String;J)J")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences,4,"getFloat","(Ljava/lang/String;F)F")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences,5,"getBoolean","(Ljava/lang/String;Z)Z")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences,6,"contains","(Ljava/lang/String;)Z")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences,7,"edit","()Landroid/content/SharedPreferences$Editor;")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences,8,"registerOnSharedPreferenceChangeListener","(Landroid/content/SharedPreferences$OnSharedPreferenceChangeListener;)V")
J2CPP_DEFINE_METHOD(android::content::SharedPreferences,9,"unregisterOnSharedPreferenceChangeListener","(Landroid/content/SharedPreferences$OnSharedPreferenceChangeListener;)V")

} //namespace j2cpp

#endif //J2CPP_ANDROID_CONTENT_SHAREDPREFERENCES_HPP_IMPL

#endif //J2CPP_INCLUDE_IMPLEMENTATION
