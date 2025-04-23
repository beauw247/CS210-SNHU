// CS210 - Corner Grocer Item Tracker
// Author: Beau Welchel
// Week 7 Project
// Header file for ItemTracker class

#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <string>
#include <map>

class ItemTracker {
private:
    std::map<std::string, int> itemFrequency; // stores item names and counts

public:
    void LoadItemsFromFile(const std::string& filename); // reads from input file
    int GetItemFrequency(const std::string& item) const; // returns item count
    void PrintAllFrequencies() const; // prints all items and counts
    void PrintHistogram() const; // prints item histogram using asterisks
    void WriteBackupFile(const std::string& filename) const; // saves backup to frequency.dat
};

#endif
