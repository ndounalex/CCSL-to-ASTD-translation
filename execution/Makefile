TARGET = tcs
CC = g++
CFLAGS = -std=c++14 -g -w -O1

.PHONY: default all clean
default: $(TARGET)
all: default

HEADERS = *.h
OBJECTS = tcs.o

%.o: ..\Ccsl translation\delayForModule.cpp utils.cpp tcs.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c ..\Ccsl translation\delayForModule.cpp utils.cpp tcs.cpp

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean: 
	-del /F /Q *.o 2>nul
	-del /F /Q *.h 2>nul
	-del /F /Q *.hpp 2>nul
	-del /F /Q  ..\Ccsl translation\delayForModule.cpp utils.cpp*.cpp 2>nul
	-del /F /Q $(TARGET).exe 2>nul