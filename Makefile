CC = g++
FILE = main.cpp
OUTPUT = tictacbot

help:
  @echo "Commands: build, clean, help"

build:
  @$(CC) $(FILE) -o $(OUTPUT)

clean:
  @rm $(OUTPUT)
