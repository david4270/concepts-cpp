import math
from random import random
import numpy as np
import pandas as pd

arr = []

size = 50+1

for i in range(1,size):
    x = random()
    y = random()
    arr.append([i,x,y])

nparr = np.array(arr)
data = pd.DataFrame(nparr,columns=['index','xCoord','yCoord'])
data['index'] = data['index'].astype(int)
data = data.set_index('index')
print(data)

for i in range(1,2):
    lenArr = []
    for j in range(1,size):
        len = math.sqrt((data.loc[j]['xCoord'] - data.loc[i]['xCoord'])**2 + (data.loc[j]['yCoord'] - data.loc[i]['yCoord'])**2)
        lenArr.append(len)
    print(lenArr)