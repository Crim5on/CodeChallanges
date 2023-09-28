#!/bin/bash

# compile comand as on kattis server:
g++ -g -O2 -std=gnu++17 -static -lrt -Wl,--whole-archive -lpthread -Wl,--no-whole-archive ./2048.cpp 