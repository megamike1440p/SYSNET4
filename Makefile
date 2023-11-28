CXX=g++
CXXFLAGS=-g -Wall

all: memory_manager

memory_manager: Main.o Slot.o Process.o MemoryManager.o
	$(CXX) $(CXXFLAGS) Main.o Slot.o Process.o MemoryManager.o -o memory_manager

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o memory_manager
