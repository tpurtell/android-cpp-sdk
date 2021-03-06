/*================================================================================
  code generated by: java2cpp
  author: Zoran Angelov, mailto://baldzar@gmail.com
  class: junit.runner.BaseTestRunner
================================================================================*/


#ifndef J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_JUNIT_RUNNER_BASETESTRUNNER_HPP_DECL
#define J2CPP_JUNIT_RUNNER_BASETESTRUNNER_HPP_DECL


namespace j2cpp { namespace junit { namespace framework { class TestListener; } } }
namespace j2cpp { namespace junit { namespace framework { class Test; } } }
namespace j2cpp { namespace junit { namespace framework { class AssertionFailedError; } } }
namespace j2cpp { namespace junit { namespace runner { class TestSuiteLoader; } } }
namespace j2cpp { namespace java { namespace lang { class String; } } }
namespace j2cpp { namespace java { namespace lang { class Object; } } }
namespace j2cpp { namespace java { namespace lang { class Throwable; } } }


#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/Throwable.hpp>
#include <junit/framework/AssertionFailedError.hpp>
#include <junit/framework/Test.hpp>
#include <junit/framework/TestListener.hpp>
#include <junit/runner/TestSuiteLoader.hpp>


namespace j2cpp {

namespace junit { namespace runner {

	class BaseTestRunner;
	class BaseTestRunner
		: public object<BaseTestRunner>
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
		J2CPP_DECLARE_METHOD(10)
		J2CPP_DECLARE_METHOD(11)
		J2CPP_DECLARE_METHOD(12)
		J2CPP_DECLARE_METHOD(13)
		J2CPP_DECLARE_METHOD(14)
		J2CPP_DECLARE_METHOD(15)
		J2CPP_DECLARE_METHOD(16)
		J2CPP_DECLARE_METHOD(17)
		J2CPP_DECLARE_METHOD(18)
		J2CPP_DECLARE_METHOD(19)
		J2CPP_DECLARE_METHOD(20)
		J2CPP_DECLARE_METHOD(21)
		J2CPP_DECLARE_METHOD(22)
		J2CPP_DECLARE_METHOD(23)
		J2CPP_DECLARE_METHOD(24)
		J2CPP_DECLARE_METHOD(25)
		J2CPP_DECLARE_METHOD(26)
		J2CPP_DECLARE_METHOD(27)
		J2CPP_DECLARE_METHOD(28)
		J2CPP_DECLARE_FIELD(0)

		explicit BaseTestRunner(jobject jobj)
		: object<BaseTestRunner>(jobj)
		{
		}

		operator local_ref<junit::framework::TestListener>() const;
		operator local_ref<java::lang::Object>() const;


		BaseTestRunner();
		void startTest(local_ref< junit::framework::Test >  const&);
		static void savePreferences();
		void setPreference(local_ref< java::lang::String >  const&, local_ref< java::lang::String >  const&);
		void endTest(local_ref< junit::framework::Test >  const&);
		void addError(local_ref< junit::framework::Test >  const&, local_ref< java::lang::Throwable >  const&);
		void addFailure(local_ref< junit::framework::Test >  const&, local_ref< junit::framework::AssertionFailedError >  const&);
		void testStarted(local_ref< java::lang::String >  const&);
		void testEnded(local_ref< java::lang::String >  const&);
		void testFailed(jint, local_ref< junit::framework::Test >  const&, local_ref< java::lang::Throwable >  const&);
		local_ref< junit::framework::Test > getTest(local_ref< java::lang::String >  const&);
		local_ref< java::lang::String > elapsedTimeAsString(jlong);
		void setLoading(jboolean);
		local_ref< java::lang::String > extractClassName(local_ref< java::lang::String >  const&);
		static local_ref< java::lang::String > truncate(local_ref< java::lang::String >  const&);
		local_ref< junit::runner::TestSuiteLoader > getLoader();
		static local_ref< java::lang::String > getPreference(local_ref< java::lang::String >  const&);
		static jint getPreference(local_ref< java::lang::String >  const&, jint);
		static jboolean inVAJava();
		static local_ref< java::lang::String > getFilteredTrace(local_ref< java::lang::Throwable >  const&);
		static local_ref< java::lang::String > getFilteredTrace(local_ref< java::lang::String >  const&);

		static static_field< J2CPP_CLASS_NAME, J2CPP_FIELD_NAME(0), J2CPP_FIELD_SIGNATURE(0), local_ref< java::lang::String > > SUITE_METHODNAME;
	}; //class BaseTestRunner

} //namespace runner
} //namespace junit

} //namespace j2cpp

#endif //J2CPP_JUNIT_RUNNER_BASETESTRUNNER_HPP_DECL

#else //J2CPP_INCLUDE_IMPLEMENTATION

#ifndef J2CPP_JUNIT_RUNNER_BASETESTRUNNER_HPP_IMPL
#define J2CPP_JUNIT_RUNNER_BASETESTRUNNER_HPP_IMPL

namespace j2cpp {



junit::runner::BaseTestRunner::operator local_ref<junit::framework::TestListener>() const
{
	return local_ref<junit::framework::TestListener>(get_jobject());
}

junit::runner::BaseTestRunner::operator local_ref<java::lang::Object>() const
{
	return local_ref<java::lang::Object>(get_jobject());
}


junit::runner::BaseTestRunner::BaseTestRunner()
: object<junit::runner::BaseTestRunner>(
	call_new_object<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(0),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(0)
	>()
)
{
}


void junit::runner::BaseTestRunner::startTest(local_ref< junit::framework::Test > const &a0)
{
	return call_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(1),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(1), 
		void
	>(get_jobject(), a0);
}



void junit::runner::BaseTestRunner::savePreferences()
{
	return call_static_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(4),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(4), 
		void
	>();
}

void junit::runner::BaseTestRunner::setPreference(local_ref< java::lang::String > const &a0, local_ref< java::lang::String > const &a1)
{
	return call_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(5),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(5), 
		void
	>(get_jobject(), a0, a1);
}

void junit::runner::BaseTestRunner::endTest(local_ref< junit::framework::Test > const &a0)
{
	return call_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(6),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(6), 
		void
	>(get_jobject(), a0);
}

void junit::runner::BaseTestRunner::addError(local_ref< junit::framework::Test > const &a0, local_ref< java::lang::Throwable > const &a1)
{
	return call_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(7),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(7), 
		void
	>(get_jobject(), a0, a1);
}

void junit::runner::BaseTestRunner::addFailure(local_ref< junit::framework::Test > const &a0, local_ref< junit::framework::AssertionFailedError > const &a1)
{
	return call_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(8),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(8), 
		void
	>(get_jobject(), a0, a1);
}

void junit::runner::BaseTestRunner::testStarted(local_ref< java::lang::String > const &a0)
{
	return call_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(9),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(9), 
		void
	>(get_jobject(), a0);
}

void junit::runner::BaseTestRunner::testEnded(local_ref< java::lang::String > const &a0)
{
	return call_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(10),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(10), 
		void
	>(get_jobject(), a0);
}

void junit::runner::BaseTestRunner::testFailed(jint a0, local_ref< junit::framework::Test > const &a1, local_ref< java::lang::Throwable > const &a2)
{
	return call_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(11),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(11), 
		void
	>(get_jobject(), a0, a1, a2);
}

local_ref< junit::framework::Test > junit::runner::BaseTestRunner::getTest(local_ref< java::lang::String > const &a0)
{
	return call_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(12),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(12), 
		local_ref< junit::framework::Test >
	>(get_jobject(), a0);
}

local_ref< java::lang::String > junit::runner::BaseTestRunner::elapsedTimeAsString(jlong a0)
{
	return call_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(13),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(13), 
		local_ref< java::lang::String >
	>(get_jobject(), a0);
}


void junit::runner::BaseTestRunner::setLoading(jboolean a0)
{
	return call_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(15),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(15), 
		void
	>(get_jobject(), a0);
}

local_ref< java::lang::String > junit::runner::BaseTestRunner::extractClassName(local_ref< java::lang::String > const &a0)
{
	return call_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(16),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(16), 
		local_ref< java::lang::String >
	>(get_jobject(), a0);
}

local_ref< java::lang::String > junit::runner::BaseTestRunner::truncate(local_ref< java::lang::String > const &a0)
{
	return call_static_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(17),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(17), 
		local_ref< java::lang::String >
	>(a0);
}




local_ref< junit::runner::TestSuiteLoader > junit::runner::BaseTestRunner::getLoader()
{
	return call_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(21),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(21), 
		local_ref< junit::runner::TestSuiteLoader >
	>(get_jobject());
}


local_ref< java::lang::String > junit::runner::BaseTestRunner::getPreference(local_ref< java::lang::String > const &a0)
{
	return call_static_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(23),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(23), 
		local_ref< java::lang::String >
	>(a0);
}

jint junit::runner::BaseTestRunner::getPreference(local_ref< java::lang::String > const &a0, jint a1)
{
	return call_static_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(24),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(24), 
		jint
	>(a0, a1);
}

jboolean junit::runner::BaseTestRunner::inVAJava()
{
	return call_static_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(25),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(25), 
		jboolean
	>();
}

local_ref< java::lang::String > junit::runner::BaseTestRunner::getFilteredTrace(local_ref< java::lang::Throwable > const &a0)
{
	return call_static_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(26),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(26), 
		local_ref< java::lang::String >
	>(a0);
}

local_ref< java::lang::String > junit::runner::BaseTestRunner::getFilteredTrace(local_ref< java::lang::String > const &a0)
{
	return call_static_method<
		junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
		junit::runner::BaseTestRunner::J2CPP_METHOD_NAME(27),
		junit::runner::BaseTestRunner::J2CPP_METHOD_SIGNATURE(27), 
		local_ref< java::lang::String >
	>(a0);
}



static_field<
	junit::runner::BaseTestRunner::J2CPP_CLASS_NAME,
	junit::runner::BaseTestRunner::J2CPP_FIELD_NAME(0),
	junit::runner::BaseTestRunner::J2CPP_FIELD_SIGNATURE(0),
	local_ref< java::lang::String >
> junit::runner::BaseTestRunner::SUITE_METHODNAME;


J2CPP_DEFINE_CLASS(junit::runner::BaseTestRunner,"junit/runner/BaseTestRunner")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,0,"<init>","()V")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,1,"startTest","(Ljunit/framework/Test;)V")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,2,"setPreferences","(Ljava/util/Properties;)V")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,3,"getPreferences","()Ljava/util/Properties;")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,4,"savePreferences","()V")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,5,"setPreference","(Ljava/lang/String;Ljava/lang/String;)V")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,6,"endTest","(Ljunit/framework/Test;)V")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,7,"addError","(Ljunit/framework/Test;Ljava/lang/Throwable;)V")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,8,"addFailure","(Ljunit/framework/Test;Ljunit/framework/AssertionFailedError;)V")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,9,"testStarted","(Ljava/lang/String;)V")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,10,"testEnded","(Ljava/lang/String;)V")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,11,"testFailed","(ILjunit/framework/Test;Ljava/lang/Throwable;)V")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,12,"getTest","(Ljava/lang/String;)Ljunit/framework/Test;")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,13,"elapsedTimeAsString","(J)Ljava/lang/String;")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,14,"processArguments","([java.lang.String)Ljava/lang/String;")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,15,"setLoading","(Z)V")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,16,"extractClassName","(Ljava/lang/String;)Ljava/lang/String;")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,17,"truncate","(Ljava/lang/String;)Ljava/lang/String;")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,18,"runFailed","(Ljava/lang/String;)V")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,19,"loadSuiteClass","(Ljava/lang/String;)Ljava/lang/Class;")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,20,"clearStatus","()V")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,21,"getLoader","()Ljunit/runner/TestSuiteLoader;")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,22,"useReloadingTestSuiteLoader","()Z")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,23,"getPreference","(Ljava/lang/String;)Ljava/lang/String;")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,24,"getPreference","(Ljava/lang/String;I)I")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,25,"inVAJava","()Z")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,26,"getFilteredTrace","(Ljava/lang/Throwable;)Ljava/lang/String;")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,27,"getFilteredTrace","(Ljava/lang/String;)Ljava/lang/String;")
J2CPP_DEFINE_METHOD(junit::runner::BaseTestRunner,28,"showStackRaw","()Z")
J2CPP_DEFINE_FIELD(junit::runner::BaseTestRunner,0,"SUITE_METHODNAME","Ljava/lang/String;")

} //namespace j2cpp

#endif //J2CPP_JUNIT_RUNNER_BASETESTRUNNER_HPP_IMPL

#endif //J2CPP_INCLUDE_IMPLEMENTATION
