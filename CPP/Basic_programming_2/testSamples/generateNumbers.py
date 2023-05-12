#!/usr/bin/python3

import random

int32maxVal = 2147483647
fileStream = open(file="99.input", mode='a')
isFirstNumber = True
    
for _ in range(200000):
    if(not isFirstNumber):
        fileStream.write(' ')
    randomNumber = random.randint(0, int32maxVal)
    fileStream.write(str(randomNumber))
    isFirstNumber = False

fileStream.write('\n')
fileStream.close()

