import numpy as np
M=np.array([2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26])
print(M)

M=M.reshape(5,5)
print(M)

for i in range(1,4):
    for j in range(1,4):
        M[i][j]=0
print(M)


M = M @ M
print(M)

mul=0
for i in range(0,5):
    mul=mul + (M[0][i]*M[0][i])
print(np.sqrt(mul))
