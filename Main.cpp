//Benjamin Salvesen and Michael Whitten
//Main.cpp
#include "MemoryManager.h"

int main() {
    MemoryManager manager;
    manager.readSlotsFromFile("23F_COP4634_Project4_InputFileBaseDisp.txt");
    manager.readProcessesFromFile("23F_COP4634_Project4_InputFileProc.txt");
    manager.allocateMemory();
    return 0;
}
