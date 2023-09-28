#!/usr/bin/python3
# challenge source: https://www.codewars.com/kata/55e1990978c60e5052000011

dim = 0


def canBeMerged(thisElement: int, nextElement: int) -> bool:
    return (thisElement == nextElement and thisElement != 0)

def canBeSlided(thisElement: int, nextElement: int) -> bool:
    return (nextElement != 0 and thisElement == 0)
        
def slideLineLeft(line: list) -> list:
    for i in range(0, dim-1, 1):
        for j in range(i, dim, 1):
            if canBeSlided(line[i], line[j]):   
                line[i] = line[j]
                line[j] = 0
    return line

def mergeLineLeft(line: list) -> list:
    for i in range(0, dim-1, 1):
        if canBeMerged(line[i], line[i+1]):
            line[i] = line[i] + line[i+1];
            line[i+1] = 0
    return line

def merge(line: list) -> list:
    global dim
    dim = len(line)
    line = slideLineLeft(line);
    line = mergeLineLeft(line);
    line = slideLineLeft(line);
    return line


# testcode:
testline = [4,2,2,2]
print(testline)
testline = merge(testline)
print("dimension: ", dim)
print(testline)
