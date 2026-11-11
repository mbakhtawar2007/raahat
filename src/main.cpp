// main.cpp — Raahat, Flood Relief & Donation Management System
// Team: Muhammad Bakhtawar (Lead), Muhammad Kaif, Raza Ahmed, Fiza
// C++ Finals — OOP, Data Structures, File Handling
// Compile: g++ -std=c++17 src/*.cpp -o raahat   (or run compile.sh)
// Run: ./raahat   (run from the project folder so data/ files are found)
#include "ReliefSystem.h"
#include <iostream>
#include <limits>
using namespace std;

void showMenu() {
    cout << "\n========== RAAHAT — Flood Relief System ==========\n";
    cout << "1. Register Victim\n";
    cout << "2. Add Relief Camp\n";
    cout << "3. Add Donation\n";
    cout << "4. Register Volunteer\n";
    cout << "5. Register Donor\n";
    cout << "6. Assign Camps (auto, nearest with space)\n";
    cout << "7. Distribute Relief (by priority)\n";
    cout << "8. Search Victim by CNIC\n";
    cout << "9. Search Victims by District\n";
    cout << "10. Dashboard / Reports\n";
    cout << "11. View All Victims\n";
    cout << "12. View All Camps\n";
    cout << "13. View All Donations\n";
    cout << "14. Save & Exit\n";
    cout << "Enter choice: ";
}

int main() {
    ReliefSystem system;
    system.loadAll();
    cout << "Welcome to Raahat — Flood Relief & Donation Management System\n";
    cout << "Data loaded from data/ files. All changes are saved on exit.\n";
    while (true) {
        showMenu();
        int choice;
        if (!(cin >> choice)) {
            cout << "Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        try {
            switch (choice) {
                case 1: system.registerVictim(); break;
                case 2: system.addCamp(); break;
                case 3: system.addDonation(); break;
                case 4: system.registerVolunteer(); break;
                case 5: system.registerDonor(); break;
                case 6: system.assignCamps(); break;
                case 7: system.distributeRelief(); break;
                case 8: system.searchByCNIC(); break;
                case 9: system.searchByDistrict(); break;
                case 10: system.showDashboard(); break;
                case 11: system.showAllVictims(); break;
                case 12: system.showAllCamps(); break;
                case 13: system.showAllDonations(); break;
                case 14: system.saveAll(); cout << "Data saved. Thank you — Raahat.\n"; return 0;
                default: cout << "Invalid choice. Enter 1-14.\n"; break;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << "\nNothing was saved for that entry. Try again.\n";
        }
        system.saveAll(); // auto-save after every action
    }
}
