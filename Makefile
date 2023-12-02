CXX=g++
CXXFLAGS=-g -Wall

all: main run

main: Main.o Slot.o Process.o MemoryManager.o
	$(CXX) $(CXXFLAGS) Main.o Slot.o Process.o MemoryManager.o -o main

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: run
run:
	./main

# Target to clean the build
clean:
	rm -f *.o main
