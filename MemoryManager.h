#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include "Slot.h"
#include "Process.h"
#include <vector>
#include <string>

class MemoryManager {
private:
    std::vector<Slot> slots;
    std::vector<Process> processes;

public:
    void readSlotsFromFile(const std::string& filename);
    void readProcessesFromFile(const std::string& filename);
    void allocateMemory();
private:
    int findBestFitSlot(int processSize);
};

#endif // MEMORY_MANAGER_H