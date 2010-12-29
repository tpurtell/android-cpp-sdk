#include "CameraTest.h"

J2CPP_DEFINE_CLASS(CameraTest,"com/j2cpp/CameraTest")
J2CPP_DEFINE_FIELD(CameraTest,0,"m_GLSurfaceView","Landroid/opengl/GLSurfaceView;")
J2CPP_DEFINE_FIELD(CameraTest,1,"m_Camera","Landroid/hardware/Camera;")
J2CPP_DEFINE_FIELD(CameraTest,2,"m_TextureWidth","I")
J2CPP_DEFINE_FIELD(CameraTest,3,"m_TextureHeight","I")
J2CPP_DEFINE_FIELD(CameraTest,4,"m_TextureBuffer","[B")
J2CPP_DEFINE_FIELD(CameraTest,5,"m_TexId","I")


CameraTest::CameraTest(jobject jobj)
: cpp_object<CameraTest>(jobj)
, m_GLSurfaceView(jobj)
, m_Camera(jobj)
, m_TextureWidth(jobj)
, m_TextureHeight(jobj)
, m_TextureBuffer(jobj)
, m_TexId(jobj)
{
}

CameraTest::operator local_ref<android::app::Activity> () const
{
	return local_ref<android::app::Activity>(get_jtype());
}

CameraTest::operator local_ref<android::hardware::Camera::PreviewCallback> () const
{
	return local_ref<android::hardware::Camera::PreviewCallback>(get_jtype());
}
