package com.j2cpp;

import android.app.Activity;
import android.os.Bundle;
import android.opengl.GLSurfaceView;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class CameraTest extends Activity implements GLSurfaceView.Renderer {
	
	static {
		System.loadLibrary("j2cppCameraTest");
	}
    
	@Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mGLSurfaceView = new GLSurfaceView(this);
        mGLSurfaceView.setRenderer(this);
        
        setContentView(mGLSurfaceView);
    }
    
    @Override
    protected void onResume()
    {
    	super.onResume();
        mGLSurfaceView.onResume();
        handleOnResume();
    }
    
    @Override
    protected void onPause()
    {
    	super.onPause();
        mGLSurfaceView.onPause();
        handleOnPause();
    }
    
    public void onDrawFrame(GL10 gl)
    {
    	handleOnDrawFrame(gl);
    }
    
    public void onSurfaceChanged(GL10 gl, int width, int height)
    {
    	handleOnSurfaceChanged(gl,width,height);
    }
    
    public void onSurfaceCreated(GL10 gl, EGLConfig config)
    {
    	handleOnSurfaceCreated(gl,config);
    }
    
    private GLSurfaceView	mGLSurfaceView;
    private long			mNative;
    
    
    private native void handleOnResume();
    private native void handleOnPause();
    private native void handleOnDrawFrame(GL10 gl);
	private native void handleOnSurfaceChanged(GL10 gl, int width, int height);
	private native void handleOnSurfaceCreated(GL10 gl, EGLConfig config);
}