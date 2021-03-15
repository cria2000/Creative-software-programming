import glfw
from OpenGL.GL import *
import numpy as np
from OpenGL.GLU import *


gCamAng = 0
gCamHeight =1.5
gVerticalAng = 0
cameraX = 0
cameraY = 0
targetX = 0
targetY = 0
targetZ = 0
zoom = 1
pan = 0
orbit = 0
preXPosition = 0
preYPosition = 0
u = np.array([0,0,0])
v = np.array([0,0,0])
w = np.array([0,0,0])
up = 1
preup = 0


def drawHuman() :

    t = glfw.get_time()
    
    #hip transformation
    glPushMatrix()
    glTranslatef(0, 1, 0)
    glRotatef(2*np.sin(t*4),0,0,1)
    
    #hip drawing
    glPushMatrix()
    glScalef(0.1, .05, .1)
    drawCube()
    glPopMatrix()

    #body transformation
    glPushMatrix()
    glTranslatef(0, .290, 0)
    glRotatef(2*np.sin(t*4),0,0,1)

    #body drawing
    glPushMatrix()
    glScalef(.1, .2, .1)
    drawCube()
    glPopMatrix()

    #head transformation
    glPushMatrix()
    glTranslatef(0, .350, 0)
    glRotatef(5*np.sin(t*4),0,0,1)

    #head drawing
    glPushMatrix()
    glScalef(.1, .1, .1)
    drawCube()
    glPopMatrix()
    
    glPopMatrix()   #head pop
    glPopMatrix()   #body pop
    
    #left shoulder transforamtion
    glPushMatrix()
    glTranslatef(0.2, 0.34, 0)
    glRotatef(50*np.sin(t*3.95),1,0,0)

    #left shoulder drawing
    glPushMatrix()
    glScalef(0.03, 0.15, 0.03)
    drawCube()
    glPopMatrix()

    #left arm transformation
    glPushMatrix()
    glRotatef(-abs(20*np.sin(t*3.95)),1,0,0)
    glTranslatef(0, -0.35, 0)

    #left arm drawing
    glPushMatrix()
    glScalef(0.03, 0.15, 0.03)
    drawCube()
    glPopMatrix()
    
    glPopMatrix()   #left arm pop
    glPopMatrix()   #left shoulder pop

    #right shoulder transformation
    glPushMatrix()
    glTranslatef(-0.2, 0.34, 0)
    glRotatef(50*np.cos(t*3.95),1,0,0)
   
    #right shoulder drawing
    glPushMatrix()
    glScalef(0.03, 0.15, 0.03)
    drawCube()
    glPopMatrix()

    #right arm transformation
    glPushMatrix()
    glRotatef(-abs(20*np.cos(t*3.95)),1,0,0)
    glTranslatef(0, -0.35, 0)

    #right arm drawing
    glPushMatrix()
    glScalef(0.03, 0.15, 0.03)
    drawCube()
    glPopMatrix()
    
    glPopMatrix()   #right arm pop
    glPopMatrix()   #right shoulder pop

    #left thigh transformation
    glPushMatrix()
    glTranslatef(0.1, -0.33, 0)
    glRotatef(-(abs(30*np.sin(t*2))),1,0,0)

    #left thigh drawing
    glPushMatrix()
    glScalef(0.05, 0.23, 0.05)
    drawCube()
    glPopMatrix()

    #left calf transformation
    glPushMatrix()
    glRotatef(abs(30*np.cos(t*2)),1,0,0)
    glTranslatef(0, -0.43, 0)
    
    #left calf drawing
    glPushMatrix()
    glScalef(0.05, 0.17, 0.05)
    drawCube()
    glPopMatrix()

    #left foot transformation
    glPushMatrix()
    glTranslatef(0,-0.23, 0.03)
    glRotatef(-(abs(15*np.cos(t*2))),1,0,0)
    
    #left foot drawing
    glPushMatrix()
    glScalef(0.05, 0.02, 0.12)
    drawCube()
    glPopMatrix()
    
    glPopMatrix()   #left thigh pop
    glPopMatrix()   #left calf pop
    glPopMatrix()   #left foot pop

    #right thigh transformation
    glPushMatrix()
    glTranslatef(-0.1, -0.33, 0)
    glRotatef(-(abs(30*np.cos(t*2))),1,0,0)
   
    #right thigh drawing
    glPushMatrix()
    glScalef(0.05, 0.23, 0.05)
    drawCube()
    glPopMatrix()

    #right calf transformation
    glPushMatrix()
    glRotatef(abs(30*np.sin(t*2)),1,0,0)
    glTranslatef(0, -0.43, 0)
   
    #right calf drawing
    glPushMatrix()
    glScalef(0.05, 0.17, 0.05)
    drawCube()
    glPopMatrix()

    #right foot transformation
    glPushMatrix()
    glTranslatef(0,-0.23, 0.03)
    glRotatef(-(abs(15*np.sin(t*2))),1,0,0)

    #right foot drawing
    glPushMatrix()
    glScalef(0.05, 0.02, 0.12)
    drawCube()
    glPopMatrix()
    
    glPopMatrix()   #right thigh pop
    glPopMatrix()   #right calf pop
    glPopMatrix()   #right foot pop
  
    glPopMatrix()   #hip pop
  
def drawCube():
    glBegin(GL_QUADS)
    glVertex3f( 1.0, 1.0,-1.0)
    glVertex3f(-1.0, 1.0,-1.0)
    glVertex3f(-1.0, 1.0, 1.0)
    glVertex3f( 1.0, 1.0, 1.0)
    glVertex3f( 1.0,-1.0, 1.0)
    glVertex3f(-1.0,-1.0, 1.0)
    glVertex3f(-1.0,-1.0,-1.0)
    glVertex3f( 1.0,-1.0,-1.0)
    glVertex3f( 1.0, 1.0, 1.0)
    glVertex3f(-1.0, 1.0, 1.0)
    glVertex3f(-1.0,-1.0, 1.0)
    glVertex3f( 1.0,-1.0, 1.0)
    glVertex3f( 1.0,-1.0,-1.0)
    glVertex3f(-1.0,-1.0,-1.0)
    glVertex3f(-1.0, 1.0,-1.0)
    glVertex3f( 1.0, 1.0,-1.0)
    glVertex3f(-1.0, 1.0, 1.0)
    glVertex3f(-1.0, 1.0,-1.0)
    glVertex3f(-1.0,-1.0,-1.0)
    glVertex3f(-1.0,-1.0, 1.0)
    glVertex3f( 1.0, 1.0,-1.0)
    glVertex3f( 1.0, 1.0, 1.0)
    glVertex3f( 1.0,-1.0, 1.0)
    glVertex3f( 1.0,-1.0,-1.0)
    glEnd()
    
def render():
    global gCamAng, gCamHeight
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
    glEnable(GL_DEPTH_TEST)
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE )
    glMatrixMode(GL_PROJECTION)
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()
    glOrtho(-1,1, -1,1, -1,1)

    t = glfw.get_time()
  
    glLoadIdentity()
    gluPerspective(45, 1, 1,100)

    myLookAt(np.array([3*np.sin(gCamAng)*np.cos(gVerticalAng)+u[0]*cameraX + v[0]*cameraY,gCamHeight+3*np.sin(gVerticalAng)+u[1]*cameraX + v[1]*cameraY,3*np.cos(gCamAng)*np.cos(gVerticalAng)+u[2]*cameraX + v[2]*cameraY]),np.array([u[0]*targetX + v[0]*targetY,u[1]*targetX + v[1]*targetY,u[2]*targetX + v[2]*targetY]),np.array([0,up,0]))

    drawPlane()
    glColor3ub(255, 255, 255)
    drawHuman()   

def myLookAt(eye, at, up):
    global Eye, At, Up, u, v, w
    ww = (eye-at)/np.sqrt(np.dot(eye-at,eye-at))
    w = (eye-at)/np.sqrt(np.dot(eye-at,eye-at))
    if zoom != 0 :
        w = ww*zoom
    u = np.cross(up,ww)/np.sqrt(np.dot(np.cross(up,ww),np.cross(up,ww))) 
    v = np.cross(ww,u)
    M = np.array([[u[0],u[1],u[2],-np.dot(u,eye)],
                 [v[0],v[1],v[2],-np.dot(v,eye)],
                 [w[0],w[1],w[2],-np.dot(w,eye)],
                 [0,0,0,1]])
    glMultMatrixf(M.T)

def drawPlane():
    glBegin(GL_LINES)
    glColor3ub(50,50,50)
    i = -50
    for i in range(-50,50) :
        glVertex3fv(np.array([i*0.2,0,-10]))
        glVertex3fv(np.array([i*0.2, 0, 10]))
        glVertex3fv(np.array([-10,0,i*0.2]))
        glVertex3fv(np.array([10, 0, i*0.2]))
    glEnd()

def mouse_button_callback(window, button, action, mods):
    global cameraX, gCamheight, targetX,  targetY, Xpos, Ypos, panX, panY,pan, orbit, orX, orY
    if button == glfw.MOUSE_BUTTON_RIGHT :
            if action==glfw.PRESS:
                    pan = 1            
            elif action == glfw.RELEASE :
                pan = 0
            
    elif button == glfw.MOUSE_BUTTON_LEFT :
        if action == glfw.PRESS :
            orbit = 1
        elif action == glfw.RELEASE :
            orbit = 0

def cursor_pos_callback(window, xpos, ypos) :
        global Xpos,Ypos, cameraX, cameraY, targetX, targetY, x, y,gCamAng, gCamHeight,orX,orY, preXPosition, preYPosition
        global gVerticalAng,up, preup,prev
        if pan == 1 :
            cameraX = cameraX + (preXPosition - xpos)*0.005
            cameraY = cameraY - (preYPosition - ypos)*0.005
            targetX = targetX + (preXPosition - xpos)*0.005
            targetY = targetY - (preYPosition - ypos)*0.005
        if orbit == 1 :
            gCamAng = gCamAng + ((preXPosition - xpos)* 0.005)
            gVerticalAng = gVerticalAng - ((preYPosition - ypos) * 0.005)
            if preYPosition - ypos < 0 and np.sin(gVerticalAng) < preup :
                up = -1
            elif preYPosition - ypos > 0 and np.sin(gVerticalAng)> preup:
                up = -1
            else :
                up = 1
        preXPosition = xpos
        preYPosition = ypos
        preup = np.sin(gVerticalAng)           

def scroll_callback(window, xoffset, yoffset) :
    global zoom
    zoom = zoom - yoffset*.1
  
def main():
    if not glfw.init():
        return
    window = glfw.create_window(480,480,'2018008722', None,None)
    if not window:
        glfw.terminate()
        return
    glfw.make_context_current(window)
  
    glfw.set_mouse_button_callback(window, mouse_button_callback)
    glfw.set_cursor_pos_callback(window, cursor_pos_callback)
    
    glfw.set_scroll_callback(window, scroll_callback)
    glfw.swap_interval(1)
   
    while not glfw.window_should_close(window):
        glfw.poll_events()
        render()
        glfw.swap_buffers(window)
        
    glfw.terminate()

if __name__ == "__main__":
    main()

