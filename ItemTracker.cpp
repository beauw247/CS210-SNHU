// CS210 - Corner Grocer Item Tracker
// Author: Beau Welchel
// Week 7 Project
// Implementation of the ItemTracker class

#include "ItemTracker.h"
#include <fstream>
#include <iostream>

void ItemTracker::LoadItemsFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    std::string item;

    if (inputFile.is_open()) {
        while (inputFile >> item) {
            ++itemFrequency[item];
        }
        inputFile.close();
    }
    else {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
}

int ItemTracker::GetItemFrequency(const std::string& item) const {
    auto it = itemFrequency.find(item);
    if (it != itemFrequency.end()) {
        return it->second;
    }
    return 0;
}

void ItemTracker::PrintAllFrequencies() const {
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}

void ItemTracker::PrintHistogram() const {
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void ItemTracker::WriteBackupFile(const std::string& filename) const {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const auto& pair : itemFrequency) {
            outputFile << pair.first << " " << pair.second << std::endl;
        }
        outputFile.close();
    }
    else {
        std::cerr << "Error writing to file: " << filename << std::endl;
    }
}