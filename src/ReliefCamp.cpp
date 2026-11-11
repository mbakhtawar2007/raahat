#include "ReliefCamp.h"
#include <iostream>
#include <sstream>
using namespace std;
ReliefCamp::ReliefCamp() : campId(""), campName(""), district(""), capacity(0), occupied(0), foodStock(0), medicineStock(0), tentStock(0) {}
ReliefCamp::ReliefCamp(string id, string n, string d, int cap, int food, int med, int tents)
    : campId(id), campName(n), district(d), capacity(cap), occupied(0), foodStock(food), medicineStock(med), tentStock(tents) {}
void ReliefCamp::displayDetails() const {
    cout << campId << " | " << campName << " | " << district
         << " | Capacity: " << occupied << "/" << capacity
         << " | Available: " << getAvailable()
         << " | Food: " << foodStock << " | Medicine: " << medicineStock << " | Tents: " << tentStock
         << (isFull() ? " | *** FULL ***" : "") << endl;
}
string ReliefCamp::toFileString() const {
    return campId + "|" + campName + "|" + district + "|" + to_string(capacity) + "|" +
           to_string(occupied) + "|" + to_string(foodStock) + "|" + to_string(medicineStock) + "|" + to_string(tentStock);
}
bool ReliefCamp::fromFileString(const string& line, ReliefCamp& out) {
    stringstream ss(line);
    string id, n, d, cap, occ, food, med, tents;
    if (!getline(ss, id, '|')) return false;
    if (!getline(ss, n, '|')) return false;
    if (!getline(ss, d, '|')) return false;
    if (!getline(ss, cap, '|')) return false;
    if (!getline(ss, occ, '|')) return false;
    if (!getline(ss, food, '|')) return false;
    if (!getline(ss, med, '|')) return false;
    if (!getline(ss, tents, '|')) return false;
    out = ReliefCamp(id, n, d, stoi(cap), stoi(food), stoi(med), stoi(tents));
    // restore occupied by assigning that many times
    for (int i = 0; i < stoi(occ); i++) out.assignVictim();
    return true;
}
