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
offset = np.array([])
resultOff = np.array([])
printOff = np.array([])
rootOff = np.array([])
channel = np.array([])
trans = np.array([(0,3,3)])
rotate = np.empty((0,42))
zxy = 0
xyz = 0
xzy = 0
yzx = 0
yxz = 0
zyx = 0
rootPoX = np.array([])
rootPoY = np.array([])
rootPoZ = np.array([])
rootRoX = np.array([])
rootRoY = np.array([])
rootRoZ = np.array([])
numCh = np.array([])
isEnd = np.array([],dtype='int')
parent = np.array([], dtype = 'int')
frame = 0
frametime = 0
joint = 0
jName = np.array([])
RTx = np.array([])
RTy = np.array([])
RTz = np.array([])
R = np.array([])

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
       

    glColor3ub(0, 0, 255)
        
    if filename != '' : 
        gVertexArraySeparate = createVertexArraySeparate()
        drawCube_glDrawArray()
        if ~sOn : 
            drawHierarchy()
        elif sOn :
            moveHierarchy()
      
        
        
            
def makeHierarchy() :
            global frame, frametime, joint, jName, offset, rootOff, channel, rootCh, numCh, rootPoX, rootPoY, rootPoZ, rootRoZ,rootRoX, rootRoY, trans, rotate, isEnd, parent, resultOff, printOff
            i = 0
            end = 0
            numJoint = 0
            num = 0
            save = 0
            f = open(str(filename), 'r')
            line = f.readline()
            line = line.lstrip()
            if line[0] == 'H' :
                line = f.readline()
                if line == "\n" :
                    line = f.readline()
                arr = line.split(" ")
                if(arr[0][0] == 'R') :
                    joint = joint + 1
                    line = line.rstrip()
                    arr = line.split(" ")
                    jName = np.append(jName, arr[1])
                    line = f.readline()
                    if(line[0]=='{') :
                        numJoint = numJoint + 1
                        save = numJoint
                    line = f.readline()
                    line = line.lstrip()
                    arr = line.split(" ")
                    if(arr[0] == "OFFSET") :
                        rootOff = np.append(rootOff, float(arr[1]))
                        rootOff = np.append(rootOff, float(arr[2]))
                        rootOff = np.append(rootOff, float(arr[3]))
                        line = f.readline()
                        line = line.lstrip()
                        arr = line.split(" ")
                        if arr[0] == "CHANNELS" :
                            rootCh = arr[1]
                            if arr[5] == "ZROTATION" and arr[6] == "XROTATION" and arr[7] == "YPOSITION" :
                                 Rzxy = 1
                            elif arr[5] == "ZROTATION" and arr[6] == "YROTATION" and arr[7] == "XPOSITION" :
                                 Rzyx = 1
                            elif arr[5] == "XROTATION" and arr[6] == "YROTATION" and arr[7] == "ZPOSITION" :
                                 Rxyz = 1
                            elif arr[5] == "XROTATION" and arr[6] == "ZROTATION" and arr[7] == "YPOSITION" :
                                 Rxzy = 1
                            elif arr[5] == "YROTATION" and arr[6] == "XROTATION" and arr[7] == "ZPOSITION" :
                                 Ryxz = 1
                            elif arr[5] == "YROTATION" and arr[6] == "ZROTATION" and arr[7] == "XPOSITION" :
                                 Ryzx = 1
                            offset = np.array([[rootOff[0], rootOff[1], rootOff[2]]])
                            resultOff = np.array([[rootOff[0], rootOff[1], rootOff[2]]])
                            printOff = np.array([[rootOff[0], rootOff[1], rootOff[2]]])
                            line = f.readline()
                            line = line.lstrip()
                     
                            while True :
                                if not line : break
                                if line[0] == 'J' :
                                    joint = joint + 1
                                    line = line.rstrip()
                                    arr = line.split(" ")
                                    jName = np.append(jName, arr[1])
                               
                                    line = f.readline()
                                    
                                    line = line.lstrip()
                                    if(line[0] == '{') :
                                        numJoint = save - 1
                             
                                        save = save + 1 
                                    while(line[0] != 'E') :
                                        
                                        line = f.readline()
                                        line = line.lstrip()
                                        if line[0] == 'J' :
                                            joint = joint + 1
                                            line = line.rstrip()
                                            arr = line.split(" ")
                                            jName = np.append(jName, arr[1])
                                        if not line : break
                                        if line[0] == '{' :
                                            numJoint = num
                                            save = save + 1
                                        elif line[0] == '}' :
                                            save = save - 1
                                        
                                        elif line[0] == 'O' :
                                            end = end +1
                                            arr = line.split(" ")
                                            tem = np.array([[float(arr[1]), float(arr[2]), float(arr[3])]])
                                         
                                            parent = np.append(parent, numJoint)
                                            offset = np.append(offset, tem, axis = 0)
                                            num = num + 1
                                      
                                            resultOff = np.append(resultOff, np.array([resultOff[parent[num-1]] + offset[num]]),axis = 0)
                                            
                                            printOff = np.append(printOff, np.array([resultOff[parent[num-1]]]),axis = 0)
                                            printOff = np.append(printOff, np.array([resultOff[num]]), axis = 0)
                                    
                                        elif line[0] == 'C' :
                                            arr = line.split(" ")
                                            if arr[1] == '3' :
                                                
                                                if arr[2][1] == 'R' :
                                                    channel = np.append(channel, arr[2][0])
                                                    channel = np.append(channel, arr[3][0])
                                                    channel = np.append(channel, arr[4][0])
                                                    numCh = np.append(numCh, 3)
                                        
                                                 
                                                elif arr[2][1] == 'P' :
                                                    channel = np.append(channel, arr[2][0])
                                                    channel = np.append(channel, arr[3][0])
                                                    channel = np.append(channel, arr[4][0])
                                                    numCh = np.append(numCh, -3)
                                               
                                            elif arr[1] == '6' :
                                                numCh = np.append(numCh, 6)
                                                channel = np.append(channel, arr[2][0])
                                                channel = np.append(channel, arr[3][0])
                                                channel = np.append(channel, arr[4][0])
                                                channel = np.append(channel, arr[5][0])
                                                channel = np.append(channel, arr[6][0])
                                                channel = np.append(channel, arr[7][0])
                                    
                                    if not line : break
                                    if line[0] == 'E' :
                                        isEnd = np.append(isEnd, end)
                                        end = 0
                                        line = f.readline()
                                        line = line.lstrip()
                                        if line[0] == '{' :
                                            numJoint = numJoint + 1
                                            save = save + 1
                                        line = f.readline()
                                        line = line.lstrip()
                                        arr = line.split(" ")
                                        if arr[0] == "OFFSET" :
                                            tem = np.array([[float(arr[1]), float(arr[2]), float(arr[3])]])
                                            parent = np.append(parent, numJoint)
                                            num = num + 1
                                            offset = np.append(offset, tem,axis = 0)
                                            resultOff = np.append(resultOff, np.array([resultOff[parent[num-1]] + offset[num]]),axis = 0)
                                            printOff = np.append(printOff, np.array([resultOff[parent[num-1]]]),axis = 0)
                                            printOff = np.append(printOff, np.array([resultOff[num]]), axis = 0)
                                            channel = np.append(channel, '-1')
                                            channel = np.append(channel, '-1')
                                            channel = np.append(channel, '-1')
                                            line = f.readline()
                                            line = line.lstrip()
                                        while line[0] == '}' :
                                            save = save - 1
                                            line = f.readline()
                                            line = line.lstrip()
                                            
                                if line[0] == 'M' :
                                        line = f.readline()
                                        if "\t" in line :
                                            arr = line.split("\t")
                                        elif " " in line : 
                                            arr = line.split(" ")
                                      
                                      
                                        fr = arr[1].rstrip()
                               
                                        print(fr)
                                        frame = int(fr)
                                        line = f.readline()
                                        line = line.rstrip()
                                        line = line.replace("\t", " ")
                                        print(line)
                                        arr = line.split(" ")
                                        
                                        frametime = 1/float(arr[2])
                            
                                        line = f.readline()
                                        if "\t" in line: 
                                                arr = line.split("\t")
                                        if " " in line: 
                                                arr = line.split(" ")
                                   
                                        i = 6
                                        j = 0
                                        while True :
                                            if not line : break
                                            rootPoX = np.append(rootPoX, arr[0])
                                   
                                            rootPoY = np.append(rootPoY, arr[1])
                                            rootPoZ = np.append(rootPoZ, arr[2])
                                            rootRoZ = np.append(rootRoZ, arr[3])
                                            rootRoX = np.append(rootRoX, arr[4])
                                            rootRoY = np.append(rootRoY, arr[5])
                                            tem = np.array([[]])
                                        
                                            for item in numCh :
                                                if item == 3 :
                                                    iden = np.identity(3)
                                              
                                                    trans = np.append(trans, iden, axis = 0)
                                                    trans = np.append(trans, iden, axis = 0)
                                                    trans = np.append(trans, iden, axis = 0)
                                                    for k in range(3) :
                                                        
                                                        tem = np.append(tem, np.array([float(arr[i])]))
                                                        i = i+1
                                                        j = j+1
                                            line = f.readline()
                                            if "\t" in line: 
                                                arr = line.split("\t")
                                            if " " in line: 
                                                arr = line.split(" ")
                                            
                                            rotate = np.append(rotate, np.array([tem]), axis = 0)
                                        
                                            i = 6
                                            j = 0
            temp = filename.split("/")
            temp = temp[len(temp)-1]
            print("File name : ",temp, "\nNumber of frames : ", frame, "\nFPS : ", frametime, "\nNumber of joints : ",joint + 1,"\nList of all joint names : ")
            for item in range(jName.size) :
                    print(jName[item])
                                         
                                                
                                        
def drawHierarchy() :
 
    index = 0
    sum = 0
    item = 2
    for num in isEnd :
        sum = sum+num
    while True :
  
        if item * 3 >= printOff.size: break
      
        drawLine(printOff[item-1], printOff[item])
   
        item = item + 2


def setRT(index, t):
    global RTx, RTy, RTz, R
    R = np.identity(4)
    if t < 41 and index < 42 :
        radArr = np.radians(float(rotate[int(t)][index]))
  
        if channel[index] == 'X' :  
              RTx = np.array([[1,0,0],
                            [0,np.cos(radArr),-np.sin(radArr)],
                            [0, np.sin(radArr), np.cos(radArr)]])
        elif channel[index] == 'Y' :
                RTx = np.array([[np.cos(radArr), 0, np.sin(radArr)],
                        [0,1,0],
                        [-np.sin(radArr), 0, np.cos(radArr)]])
        
        elif channel[index] == 'Z' :
                RTx = np.array([[np.cos(radArr), -np.sin(radArr), 0],
                        [np.sin(radArr), np.cos(radArr), 0],
                      [0,0,1]])
        radArr = np.radians(float(rotate[int(np.sin(t))][index+1]))
        if channel[index+1] == 'X' :  
              RTy = np.array([[1,0,0],
                        [0,np.cos(radArr),-np.sin(radArr)],
                        [0, np.sin(radArr), np.cos(radArr)]])
        elif channel[index+1] == 'Y' :
                RTy = np.array([[np.cos(radArr), 0, np.sin(radArr)],
                        [0,1,0],
                        [-np.sin(radArr), 0, np.cos(radArr)]])
        
        elif channel[index+1] == 'Z' :
                    RTy = np.array([[np.cos(radArr), -np.sin(radArr), 0],
                        [np.sin(radArr), np.cos(radArr), 0],
                      [0,0,1]])
        radArr = np.radians(float(rotate[int(np.sin(t))][index+2]))
        if channel[index+2] == 'X' :  
              RTz = np.array([[1,0,0],
                        [0,np.cos(radArr),-np.sin(radArr)],
                        [0, np.sin(radArr), np.cos(radArr)]])
        elif channel[index+2] == 'Y' :
            RTz = np.array([[np.cos(radArr), 0, np.sin(radArr)],
                            [0,1,0],
                        [-np.sin(radArr), 0, np.cos(radArr)]])
        
        elif channel[index+2] == 'Z' :
            RTz = np.array([[np.cos(radArr), -np.sin(radArr), 0],
                        [np.sin(radArr), np.cos(radArr), 0],
                      [0,0,1]])
    R[:3,:3] = RTz @ RTx @ RTy
           

def moveHierarchy() :
    glDisable(GL_LIGHTING)
 
    item = 2
    index = 0
    num = 0
    M = np.identity(4)
    T = np.identity(4)
    prevR = np.array([])
    t = glfw.get_time()
    if (t > rootRoZ.size) :
        t = 0
 
    T[:3,3] = [float(rootPoX[int(t)]), float(rootPoY[int(t)]), float(rootPoZ[int(t)])]

    zang = np.radians(float(rootRoZ[int(t)]))
    xang = np.radians(float(rootRoX[int(t)]))
    yang = np.radians(float(rootRoY[int(t)]))
    if zxy == 0 :
        Rz = np.array([[np.cos(zang), -np.sin(zang), 0],
                      [np.sin(zang), np.cos(zang), 0],
                      [0,0,1]])
        Rx = np.array([[1,0,0],
                      [0, np.cos(xang), -np.sin(xang)],
                      [0, np.sin(xang), np.cos(xang)]])
        Ry = np.array([[np.cos(yang), 0, np.sin(yang)],
                      [0,1,0],
                      [-np.sin(yang), 0, np.cos(yang)]])
        M[:3,:3] = Rz @ Rx @ Ry
        glPushMatrix()
        glMultMatrixf(M.T)
        glMultMatrixf(T.T)
       
        push = 0
    for f in range (0, len(rotate)) : 
        for i in range(0,100):
        
 
            if item * 3 >=printOff.size : break
           
       
            setRT(index, t)
    
            glPushMatrix()
      
            push = push + 1
         
            drawLine(printOff[item-1],printOff[item])
           
            if num < 18 : 
                if parent[num] > parent[num+1] :
                    while push != parent[num+1] :
                        glPopMatrix()
                        push = push - 1
            index = index + 3
            item = item +2
            num = num+1
        t = t + 1
        if push > 0 :
            while push != 0 :
                glPopMatrix()
                push = push -1
    glPopMatrix()
    


    
        

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

def drawLine(first, second) :
    glColor3ub(0,0,255)
    glBegin(GL_LINES)
#    print(first, second)
    glVertex3fv(first)
    glVertex3fv(second)
 #   glVertex3f(second[0], second[1], second[2])
    glEnd()

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
    global filename, rootPoY, rootPoX, rootPoz, rootRoX, rootRoY, RootRoZ, rotate, offset, resultOff, printOff, rootOff, channel, zxy, zyx, xyz, xzy, yxz, yzx, numCh, isEnd, parent, frame, frametime, jName, joint, RTx, RTy, RTz, R
    offset = np.array([])
    resultOff = np.array([])
    printOff = np.array([])
    rootOff = np.array([])
    channel = np.array([])
    trans = np.array([(0,3,3)])
    rotate = np.empty((0,42))
    zxy = 0
    xyz = 0
    xzy = 0
    yzx = 0
    yxz = 0
    zyx = 0
    rootPoX = np.array([])
    rootPoY = np.array([])
    rootPoZ = np.array([])
    rootRoX = np.array([])
    rootRoY = np.array([])
    rootRoZ = np.array([])
    numCh = np.array([])
    isEnd = np.array([],dtype='int')
    parent = np.array([], dtype = 'int')
    frame = 0
    frametime = 0
    joint = 0
    jName = np.array([])
    RTx = np.array([])
    RTy = np.array([])
    RTz = np.array([])
    R = np.array([])
    file = str(callback).replace("\\\\","/")
    filename = file[2:-2]
    makeHierarchy()

def key_callback(window, key, scancode,action, mods):
    global zOn,sOn
    if action==glfw.PRESS or action==glfw.REPEAT:
        if key==glfw.KEY_SPACE :
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


