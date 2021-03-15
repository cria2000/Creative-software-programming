import glfw
from OpenGL.GL import *
import numpy as np
from OpenGL.GLU import *
import ctypes
from OpenGL.arrays import vbo
import time
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
filename = ""
vertex = np.array([])
normal = np.array([])
pointV = np.array([])
pointN = np.array([])
zOn = 0
sOn = 0
smoothShading = np.array([])
normalShading = np.array([])
gVertexArraySeparate = None
def render():
    global gCamAng, gCamHeight, gVertexArraySeparate, filename, vertex, normal, pointV, pointN
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
    glEnable(GL_DEPTH_TEST)
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE )
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    gluPerspective(45, 1, 1,100)
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()
    myLookAt(np.array([3*np.sin(gCamAng)*np.cos(gVerticalAng)+u[0]*cameraX + v[0]*cameraY,gCamHeight+3*np.sin(gVerticalAng)+u[1]*cameraX + v[1]*cameraY,3*np.cos(gCamAng)*np.cos(gVerticalAng)+u[2]*cameraX + v[2]*cameraY]),np.array([u[0]*targetX + v[0]*targetY,u[1]*targetX + v[1]*targetY,u[2]*targetX + v[2]*targetY]),np.array([0,up,0]))
    drawPlane()
    glEnable(GL_LIGHTING)
    glEnable(GL_LIGHT0)
    glEnable(GL_LIGHT1)
    glEnable(GL_NORMALIZE)
 
    glPushMatrix()
    lightPos0 = (3.,4.,5.,1.)
    lightPos1 = (3.,4.,5.,0.)
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0)
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1)
    glPopMatrix()
    
    # light intensity for each color channel
    lightColor = (1.,1.,.5,1.)
    ambientLightColor = (.1,.1,.1,1.)
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor)
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightColor)
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLightColor)

    lightColor = (1.,1., 1.,1.)
    ambientLightColor = (.1,.1,.1,1.)
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor)
    glLightfv(GL_LIGHT1, GL_SPECULAR, lightColor)
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLightColor)

    # material reflectance for each color channel   
    objectColor = (0.7,0.5,0.7,1.)
    specularObjectColor = (1.,1.,1.,1.)
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, objectColor)
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, 10)
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularObjectColor)

    if zOn == -1 :
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL)
           
    elif zOn == 0 :
        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE )
        
    glColor3ub(255, 255, 255)
        
    if filename != '' : 
        gVertexArraySeparate = createVertexArraySeparate()
        drawCube_glDrawArray()
        

def createVertexArraySeparate() :
    global vertex, normal, pointN, pointV
    varr = []
    for item in range(0, len(pointV)) :
        for item2 in range(0,3) :
            if sOn == 0 : 
                varr.append(tuple(normal[pointN[item][item2]]))
                varr.append(tuple(vertex[pointV[item][item2]]))
            elif sOn == -1 :
                varr.append(tuple(smoothShading[pointV[item][item2]]))
                varr.append(tuple(vertex[pointV[item][item2]]))
    return np.asarray(varr)

def drawCube_glDrawArray() :
    global gVertexArraySeparate
    varr = gVertexArraySeparate
    varr = varr.astype('float32')

    glEnableClientState(GL_VERTEX_ARRAY)
    glEnableClientState(GL_NORMAL_ARRAY)
    glNormalPointer(GL_FLOAT, 6*varr.itemsize,varr)
    glVertexPointer(3,GL_FLOAT,6*varr.itemsize, ctypes.c_void_p(varr.ctypes.data + 3*varr.itemsize))
    glDrawArrays(GL_TRIANGLES, 0 , int(varr.size/6))

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
    glDisable(GL_LIGHTING)
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

def drop_callback(window, callback) :
    global filename, vertex, normal, pointN, pointV, sOn, smoothShading, normalShading
    file = str(callback).replace("\\\\","/")
    filename = file[2:-2]
    f = open(str(filename), 'r')
    listV, listN, listPV, listPN = [],[],[],[]
    while True :
            line = f.readline()
            if not line : break
            if line[0] == 'v' :
                if line[1] == 'n' :
                    temp = line[2:]
                    listN.append(tuple(map(float, temp.split())))
                elif line[1] == ' ' :
                    temp = line[2:]
                    listV.append(tuple(map(float, temp.split())))
            elif line[0] == 'f' :
                temp = line[2:]
                temp = temp.split()
                if len(temp) > 3 :
                    for i in range(0,len(temp)-2) :
                        if "//" not in temp :
                            arr = temp[0].split("/")
                            arr2 = temp[i+1].split("/")
                            arr3 = temp[i+2].split("/")
                            ver = (int(arr[0])-1,int(arr2[0])-1,int(arr3[0])-1)
                            listPV.append(ver)
                            nor = (int(arr[2])-1,int(arr2[2])-1,int(arr3[2])-1)
                            listPN.append(nor)
                        else :
                            arr = temp[0].split("//")
                            arr2 = temp[i+1].split("//")
                            arr3 = temp[i+2].split("//")
                            ver = (int(arr[0])-1,int(arr2[0])-1,int(arr3[0])-1)
                            listPV.append(ver)
                            nor = (int(arr[1])-1,int(arr2[1])-1,int(arr3[1])-1)
                            listPN.append(nor)
                elif len(temp) == 3:
                    if "//" not in temp :
                        arr = temp[0].split("/")
                        arr2 = temp[1].split("/")
                        arr3 = temp[2].split("/")
                        ver = (int(arr[0])-1,int(arr2[0])-1,int(arr3[0])-1)
                        listPV.append(ver)
                        nor = (int(arr[2])-1,int(arr2[2])-1,int(arr3[2])-1)
                        listPN.append(nor)
                    else :
                        arr = temp[0].split("//")
                        arr2 = temp[1].split("//")
                        arr3 = temp[2].split("//")
                        ver = (int(arr[0])-1,int(arr2[0])-1,int(arr3[0])-1)
                        listPV.append(ver)
                        nor = (int(arr[1])-1,int(arr2[1])-1,int(arr3[1])-1)
                        listPN.append(nor)
    vertex = np.asarray(listV)
    normal = np.asarray(listN)
    pointV = np.asarray(listPV)
    pointN = np.asarray(listPN)
  
    smoothShading = np.ones((len(vertex),3))
    normalShading = normal.copy()

    faceWith3, faceWith4, faceWithMore, num = 0, 0, 0, 1
    arr = []

    for i in range(0,len(pointN)) :
        temp = pointN[i]
        if arr : 
            for item in arr :
                if np.all(temp == item) :
                    num = -10000
                    break
        for j in range(i+1,len(pointN)) :
            if np.array_equal(temp, pointN[j]) :
                num = num+1
        if num == 1 : faceWith3 = faceWith3 + 1
        elif num == 2 :
            faceWith4 = faceWith4 + 1
            arr.append(temp)
        elif num > 2 :
            faceWithMore = faceWithMore + 1
            arr.append(temp)
        num = 1

    temp = filename.split("/")
    temp = temp[len(temp)-1]
    print("File name : " ,temp)
    print("Total number of faces : ",faceWith3+faceWith4+faceWithMore)
    print("Number of faces with 3 vertices : ",faceWith3)
    print("Number of faces with 4 vertices : ",faceWith4)
    print("Number of faces with more than 4 vertices : ",faceWithMore)

    #calculate normal average vector for smmoth shading
    arr = []
    add = [0,0,0]
    for i in range(0, len(vertex)) :
        index = np.where(pointV == i)
        for item in range(len(index[0])):
            add = add + (normal[pointN[index[0][item]][index[1][item]]])
        add = add / np.sqrt(sum(add*add))
        smoothShading[i] = add           
    f.close()

def key_callback(window, key, scancode,action, mods):
    global zOn,sOn
    if action==glfw.PRESS or action==glfw.REPEAT:
        if key==glfw.KEY_Z :
            zOn=~zOn
        elif key==glfw.KEY_S :
            sOn=~sOn
  
def main():
    if not glfw.init():
        return
    window = glfw.create_window(640,640,'2018008722', None,None)
    if not window:
        glfw.terminate()
        return
    glfw.make_context_current(window)
  
    glfw.set_mouse_button_callback(window, mouse_button_callback)
    glfw.set_cursor_pos_callback(window, cursor_pos_callback)
    glfw.set_key_callback(window,key_callback)
    glfw.set_scroll_callback(window, scroll_callback)

    glfw.set_drop_callback(window, drop_callback)
    glfw.swap_interval(1)

    while not glfw.window_should_close(window):
        glfw.poll_events()
        render()
        glfw.swap_buffers(window)
        
    glfw.terminate()

if __name__ == "__main__":
    main()

