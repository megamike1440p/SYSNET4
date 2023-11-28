#include "MemoryManager.h"
#include <iostream>
#include <fstream>
#include <climits>

void MemoryManager::readSlotsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    int base, displacement;
    while (file >> base >> displacement) {
        slots.emplace_back(base, displacement);
    }
}

void MemoryManager::readProcessesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    int size;
    char id = 'A';
    while (file >> size) {
        processes.emplace_back(size, id++);
    }
}

int MemoryManager::findBestFitSlot(int processSize) {
    int bestIndex = -1;
    int minDisplacement = INT_MAX;
    for (size_t i = 0; i < slots.size(); ++i) {
        if (slots[i].displacement >= processSize && slots[i].displacement - processSize < minDisplacement) {
            bestIndex = int(i);
            minDisplacement = slots[i].displacement - processSize;
        }
    }
    return bestIndex;
}

void MemoryManager::allocateMemory() {
    for (auto& process : processes) {
        int index = findBestFitSlot(process.size);
        if (index != -1) {
            Slot& slot = slots[index];
            std::cout << "Allocating Process " << process.id << " of size " << process.size
                      << " to slot at base " << slot.base << '\n';
            slot.base += process.size;
            slot.displacement -= process.size;
            if (slot.displacement == 0) {
                slots.erase(slots.begin() + index);
            }
        } else {
            std::cout << "Cannot allocate Process " << process.id << " of size " << process.size << '\n';
            break;
        }
    }
}