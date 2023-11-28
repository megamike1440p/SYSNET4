#include "MemoryManager.h"

int main() {
    MemoryManager manager;
    manager.readSlotsFromFile("base_disp.txt");
    manager.readProcessesFromFile("input_proc.txt");
    manager.allocateMemory();
    return 0;
}