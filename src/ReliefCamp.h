#pragma once
// ReliefCamp.h — Bakhtawar
#include <string>
using namespace std;
class ReliefCamp {
private:
    string campId, campName, district;
    int capacity, occupied, foodStock, medicineStock, tentStock;
public:
    ReliefCamp();
    ReliefCamp(string id, string name, string district, int capacity, int food, int med, int tents);
    string getCampId() const { return campId; }
    string getCampName() const { return campName; }
    string getDistrict() const { return district; }
    int getCapacity() const { return capacity; }
    int getOccupied() const { return occupied; }
    int getAvailable() const { return capacity - occupied; }
    bool hasSpace() const { return occupied < capacity; }
    bool isFull() const { return occupied >= capacity; }
    void assignVictim() { if (hasSpace()) occupied++; }
    void displayDetails() const;
    string toFileString() const;
    static bool fromFileString(const string& line, ReliefCamp& out);
};
