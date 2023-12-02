#include "MemoryManager.h"

int main() {
    MemoryManager manager;
    manager.readSlotsFromFile("InputFileBaseDisp.txt");
    manager.readProcessesFromFile("InputFileProc.txt");
    manager.allocateMemory();
    return 0;
}
