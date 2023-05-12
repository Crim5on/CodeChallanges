#!/usr/bin/python3

import os
import subprocess

sampleFilePath = "./testSamples/"
inputFiles = ["1.input", "2.input", "3.input", "4.input", "5.input", "99.input"]
outputFiles = ["1.output", "2.output", "3.output", "4.output", "5.output", "99.output"]
TESTCOUNTER = 0


def getSampleFromFile(filePath: str) -> str:
    fileStream = open(file=filePath, mode='r')
    sampleString = fileStream.read()
    fileStream.close()
    return sampleString
 

def validateOutput(isValue: str, expectedValue: str) -> bool:
    return (isValue == expectedValue)


def validateSamples(inputSample: str, outputSample: str) -> None:
    global TESTCOUNTER
    TESTCOUNTER = TESTCOUNTER + 1
    # start program as sub process
    myProgramm = subprocess.Popen(["./main.o"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = myProgramm.communicate(input=bytes(inputSample, 'utf-8'))

    if(stderr):
        print("Error Occured! (Did you compile?)")
        print(stderr.decode("utf-8"))
    elif(stdout):
        outputString = stdout.decode("utf-8")
        if(outputString == outputSample):
            print("Test Case " + str(TESTCOUNTER) + " Passed.")
        else:
            print("Test Case " + str(TESTCOUNTER) + " Failed!")
            print("Expected: '" + outputSample + "'")
            print("Actually: '" + outputString + "'")
    else:
        print("Error: Got no output from programm.")




# re-compile
print("Starting Tests ..\n")
os.system("make clean")
os.system("make")

print("Starting Tests ..\n")

for inputFile, outputFile in zip(inputFiles, outputFiles):
    inputSample = getSampleFromFile(sampleFilePath + inputFile)
    outputSample = getSampleFromFile(sampleFilePath + outputFile)
    validateSamples(inputSample, outputSample)

print("\nAll tests finished.")