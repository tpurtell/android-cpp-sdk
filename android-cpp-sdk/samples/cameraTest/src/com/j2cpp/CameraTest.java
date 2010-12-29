package com.j2cpp;

import android.app.Activity;
import android.os.Bundle;
import android.opengl.GLSurfaceView;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;
import java.nio.ByteBuffer;

import android.graphics.PixelFormat;
import android.hardware.Camera;


public class CameraTest extends Activity implements GLSurfaceView.Renderer, Camera.PreviewCallback {
	
	static {
		System.loadLibrary("j2cppCameraTest");
	}
    
	@Override
    public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		m_TexId=-1;
		m_GLSurfaceView = new GLSurfaceView(this);
		m_GLSurfaceView.setRenderer(this);
		setContentView(m_GLSurfaceView);
		
	}
    
    @Override
    protected void onResume()
    {
    	super.onResume();
    	m_GLSurfaceView.onResume();
    	try
    	{
    		handleOnResume();
    	}
    	catch(java.lang.Exception e)
    	{
    		java.lang.String strReason=e.getMessage();
    	}
    }
    
    @Override
    protected void onPause()
    {
    	super.onPause();
    	m_GLSurfaceView.onPause();
        handleOnPause();
    }
    
    public void onDrawFrame(GL10 gl)
    {
    	try
    	{
    		handleOnDrawFrame(gl);
    	}
    	catch(java.lang.Exception e)
    	{
    		java.lang.String strReason=e.getMessage();
    	}
    }
    
    public void onSurfaceChanged(GL10 gl, int width, int height)
    {
    	handleOnSurfaceChanged(gl,width,height);
    }
    
    public void onSurfaceCreated(GL10 gl, EGLConfig config)
    {
    	handleOnSurfaceCreated(gl,config);
    }
    
    public void onPreviewFrame(byte[] data, Camera camera)
    {
    	handleOnPreviewFrame(data,camera);
    }
    
    
    protected GLSurfaceView	m_GLSurfaceView;
    public Camera			m_Camera;
    public int				m_TextureWidth;
    public int				m_TextureHeight;
    public byte[]			m_TextureBuffer;
    public int				m_TexId;
    
    
    private native void handleOnResume();
    private native void handleOnPause();
    private native void handleOnDrawFrame(GL10 gl);
	private native void handleOnSurfaceChanged(GL10 gl, int width, int height);
	private native void handleOnSurfaceCreated(GL10 gl, EGLConfig config);
	private native void handleOnPreviewFrame(byte[] data, Camera camera);
}