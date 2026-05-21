TARGET = tcs_observer
CC = g++
CFLAGS = -std=c++14 -g -w -O1

.PHONY: default all clean
default: $(TARGET)
all: default

HEADERS = *.h
OBJECTS = tcs_observer.o

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< 

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean: 
	-rm -f *.o
	-rm -f $(filter-out,$(wildcard *.h))
	-rm -f $(filter-out,$(wildcard *.hpp))
	-rm -f $(filter-out pugixml.cpp utils.cpp,$(wildcard *.cpp))
	-rm -f $(TARGET)