import glfw
from OpenGL.GL import *
import numpy as np
from OpenGL.GLU import *
gCamAng = 0.
gCamHeight = 1.
α = 0
β = 0
γ = 0

def render():
    global gCamAng, gCamHeight
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
    glEnable(GL_DEPTH_TEST)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    gluPerspective(45, 1, 1,10)
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()
    
    gluLookAt(5*np.sin(gCamAng),gCamHeight,5*np.cos(gCamAng), 0,0,0, 0,1,0)
    
    # draw global frame
    drawFrame()
    glEnable(GL_LIGHTING)
    glEnable(GL_LIGHT0)
    glEnable(GL_RESCALE_NORMAL)
    
    # set light properties
    lightPos = (4.,5.,6.,1.)
    glLightfv(GL_LIGHT0, GL_POSITION,lightPos)
    ambientLightColor = (.1,.1,.1,1.)
    diffuseLightColor = (1.,1.,1.,1.)
    specularLightColor = (1.,1.,1.,1.)
    glLightfv(GL_LIGHT0, GL_AMBIENT,ambientLightColor)
    glLightfv(GL_LIGHT0, GL_DIFFUSE,diffuseLightColor)
    glLightfv(GL_LIGHT0, GL_SPECULAR,specularLightColor)
    
    # ZXZ Euler angles
   
    M = np.identity(4)

    Rz1 = np.array([[np.cos(np.radians(α)), -np.sin(np.radians(α)), 0],
                   [np.sin(np.radians(α)), np.cos(np.radians(α)), 0],
                   [0,0,1]])
    Rx = np.array([[1,0,0],
                   [0, np.cos(np.radians(β)), -np.sin(np.radians(β))],
                   [0, np.sin(np.radians(β)), np.cos(np.radians(β))]])
    Rz2 = np.array([[np.cos(np.radians(γ)), -np.sin(np.radians(γ)), 0],
                   [np.sin(np.radians(γ)), np.cos(np.radians(γ)), 0],
                   [0,0,1]])
    M[:3,:3] = Rz1 @ Rx @ Rz2
    glMultMatrixf(M.T)
    
    glScalef(.25,.25,.25)
    # draw cubes
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, (.5,.5,.5,1.))
    drawCube_glDrawArray()
    glTranslatef(3,0,0)
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, (1.,0.,0.,1.))
    drawCube_glDrawArray()
    glTranslatef(-3,3,0)
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, (0.,1.,0.,1.))
    drawCube_glDrawArray()
    glTranslatef(0,-3,3)
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, (0.,0.,1.,1.))
    drawCube_glDrawArray()
    glDisable(GL_LIGHTING)

def drawFrame():
    # draw coordinate: x in red, y in green, z in blue
    glBegin(GL_LINES)
    glColor3ub(255, 0, 0)
    glVertex3fv(np.array([0.,0.,0.]))
    glVertex3fv(np.array([1.,0.,0.]))
    glColor3ub(0, 255, 0)
    glVertex3fv(np.array([0.,0.,0.]))
    glVertex3fv(np.array([0.,1.,0.]))
    glColor3ub(0, 0, 255)
    glVertex3fv(np.array([0.,0.,0]))
    glVertex3fv(np.array([0.,0.,1.]))
    glEnd()

def createVertexArraySeparate():
    varr = np.array([
    (0,0,1), # v0 normal
    ( -1 , 1 , 1 ), # v0 position
    (0,0,1), # v2 normal
    ( 1 , -1 , 1 ), # v2 position
    (0,0,1), # v1 normal
    ( 1 , 1 , 1 ), # v1 position
    (0,0,1), # v0 normal
    ( -1 , 1 , 1 ), # v0 position
    (0,0,1), # v3 normal
    ( -1 , -1 , 1 ), # v3 position
    (0,0,1), # v2 normal
    ( 1 , -1 , 1 ), # v2 position
    (0,0,-1),
    ( -1 , 1 , -1 ), # v4
    (0,0,-1),
    ( 1 , 1 , -1 ), # v5
    (0,0,-1),
    ( 1 , -1 , -1 ), # v6
    (0,0,-1),
    ( -1 , 1 , -1 ), # v4
    (0,0,-1),
    ( 1 , -1 , -1 ), # v6
    (0,0,-1),
    ( -1 , -1 , -1 ), # v7
    (0,1,0),
    ( -1 , 1 , 1 ), # v0
    (0,1,0),
    ( 1 , 1 , 1 ), # v1
    (0,1,0),
    ( 1 , 1 , -1 ), # v5
    (0,1,0),
    ( -1 , 1 , 1 ), # v0
    (0,1,0),
    ( 1 , 1 , -1 ), # v5
    (0,1,0),
    ( -1 , 1 , -1 ), # v4
    (0,-1,0),
    ( -1 , -1 , 1 ), # v3
    (0,-1,0),
    ( 1 , -1 , -1 ), # v6
    (0,-1,0),
    ( 1 , -1 , 1 ), # v2
    (0,-1,0),
    ( -1 , -1 , 1 ), # v3
    (0,-1,0),
    ( -1 , -1 , -1 ), # v7
    (0,-1,0),
    ( 1 , -1 , -1 ), # v6
    (1,0,0),
    ( 1 , 1 , 1 ), # v1
    (1,0,0),
    ( 1 , -1 , 1 ), # v2
    (1,0,0),
    ( 1 , -1 , -1 ), # v6
    (1,0,0),
    ( 1 , 1 , 1 ), # v1
    (1,0,0),
    ( 1 , -1 , -1 ), # v6
    (1,0,0),
    ( 1 , 1 , -1 ), # v5
    (-1,0,0),
    ( -1 , 1 , 1 ), # v0
    (-1,0,0),
    ( -1 , -1 , -1 ), # v7
    (-1,0,0),
    ( -1 , -1 , 1 ), # v3
    (-1,0,0),
    ( -1 , 1 , 1 ), # v0
    (-1,0,0),
    ( -1 , 1 , -1 ), # v4
    (-1,0,0),
    ( -1 , -1 , -1 ), # v7
    ], 'float32')
    return varr

def drawCube_glDrawArray():
    global createVertexArraySeparate
    varr = createVertexArraySeparate()
    glEnableClientState(GL_VERTEX_ARRAY)
    glEnableClientState(GL_NORMAL_ARRAY)
    glNormalPointer(GL_FLOAT, 6*varr.itemsize, varr)
    glVertexPointer(3, GL_FLOAT, 6*varr.itemsize,
    ctypes.c_void_p(varr.ctypes.data + 3*varr.itemsize))
    glDrawArrays(GL_TRIANGLES, 0, int(varr.size/6))

def key_callback(window, key, scancode,action, mods):
    global gCamAng, gCamHeight, α,β,γ
    if action == glfw.PRESS or action == glfw.REPEAT:
        if key ==glfw.KEY_1 :
            gCamAng += np.radians(-10)
        elif key == glfw.KEY_3 :
            gCamAng += np.radians(10)
        elif key ==glfw.KEY_2 :
            gCamHeight += .1
        elif key == glfw.KEY_W: 
            gCamHeight += -.1
        elif key == glfw.KEY_A :
            α = α+10
        elif key == glfw.KEY_Z :
            α = α-10
        elif key == glfw.KEY_S :
            β = β+10
        elif key == glfw.KEY_X :
            β = β-10
        elif key == glfw.KEY_D :
            γ = γ+10
        elif key == glfw.KEY_C :
            γ = γ-10
        elif key == glfw.KEY_V :
            α = 0
            β = 0
            γ = 0

def main():
    if not glfw.init():
        return
    window = glfw.create_window(480,480,'2018008722', None,None)
    if not window:
        glfw.terminate()
        return
    glfw.make_context_current(window)
    glfw.set_key_callback(window,key_callback)
    glfw.swap_interval(1)
    
    while not glfw.window_should_close(window):
        glfw.poll_events()
        render()
        glfw.swap_buffers(window)
    glfw.terminate()
        
if __name__ == "__main__":
        main()
        
