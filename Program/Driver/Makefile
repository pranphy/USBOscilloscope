#This is a makefile for a c++ file with function used form libusb
#This is intended to make compilation easier
COMPILER=g++
FLAGS=-Wall -Os
LIBRARY=usb
OBJECTS=CommandLine.o
EXECUTABLE=CommandLine
SOURCES=CommandLine.cpp

$(EXECUTABLE):$(OBJECTS)
	$(COMPILER) -o $(EXECUTABLE) $(OBJECTS) -l$(LIBRARY)
$(OBJECTS):$(SOURCES)
	$(COMPILER) $(FLAGS) -c $^
clean:
	rm $(OBJECTS)
