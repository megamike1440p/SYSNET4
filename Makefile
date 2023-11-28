CXX=g++
CXXFLAGS=-g -Wall

all: memory_manager

memory_manager: main.o Slot.o Process.o MemoryManager.o
	$(CXX) $(CXXFLAGS) main.o Slot.o Process.o MemoryManager.o -o memory_manager

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o memory_manager