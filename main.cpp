// CS210 - Corner Grocer Item Tracker
// Author: Beau Welchel
// Week 7 Project
// Main menu and user interaction logic

#include <iostream>
#include <string>
#include "ItemTracker.h"

int main() {
    ItemTracker tracker;
    tracker.LoadItemsFromFile("InputTextItemTracker.txt"); // Load data at startup
    tracker.WriteBackupFile("frequency.dat"); // Save backup immediately

    int choice = 0;
    std::string item;

    // Display menu until user exits
    while (choice != 4) {
        std::cout << "\n===== Corner Grocer Menu =====" << std::endl;
        std::cout << "1. Search for item frequency" << std::endl;
        std::cout << "2. Print all item frequencies" << std::endl;
        std::cout << "3. Print histogram of items" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Choose an option (1-4): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter item name: ";
            std::cin >> item;
            std::cout << item << " was purchased " << tracker.GetItemFrequency(item) << " times." << std::endl;
            break;
        case 2:
            tracker.PrintAllFrequencies();
            break;
        case 3:
            tracker.PrintHistogram();
            break;
        case 4:
            std::cout << "Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please enter 1-4." << std::endl;
        }
    }

    return 0;
}
