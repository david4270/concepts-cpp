import math
import random
import numpy as np
import pandas as pd
import os

# Set up nodes and edges - save in csv

current = os.getcwd()
current2 = os.path.join(current,"intermediate-1\\")
if(os.path.isdir(current2)):
    current = current2
print(current)

arr = []

size = random.randint(45,100)+1

for i in range(1,size):
    x = random.random()
    y = random.random()
    arr.append([i,x,y])

nparr = np.array(arr)
data = pd.DataFrame(nparr,columns=['index','xCoord','yCoord'])
data['index'] = data['index'].astype(int)
data = data.set_index('index')
print(data)

edgeArr = []

for i in range(1,size):
    lenArr = []
    for j in range(1,size):
        len = math.sqrt((data.loc[j]['xCoord'] - data.loc[i]['xCoord'])**2 + (data.loc[j]['yCoord'] - data.loc[i]['yCoord'])**2)
        lenArr.append(len)
    #print(lenArr)
    lenArrnp = np.array(lenArr)
    lAr = np.argsort(lenArrnp)[1:random.randint(4,7)]+1
    lAr = lAr.tolist()
    #print(lAr)
    for k in lAr:
        edgePartArr = [i,k]
        edgeArr.append(edgePartArr)

edgenpArr = np.array(edgeArr)
edgeData = pd.DataFrame(edgenpArr, columns = ['startID','endID'])

edgeIDArr = []
for i in range(1,edgeData.shape[0]+1):
    edgeIDArr.append(i)

edgeData['edgeID'] = edgeIDArr
edgeData = edgeData.set_index('edgeID')
    
print(edgeData)

data.to_csv(current+'/node.csv')
edgeData.to_csv(current+'/edge.csv')
