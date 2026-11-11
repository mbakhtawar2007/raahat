#include "Victim.h"
#include <iostream>
#include <sstream>
using namespace std;

Victim::Victim() : Person(), familySize(0), medicalNeed(0), damageLevel(0),
                   assignedCampId("None"), reliefReceived(false) {}
Victim::Victim(string n, string c, string p, string d, int f, int m, int dmg)
    : Person(n, c, p, d), familySize(f), medicalNeed(m), damageLevel(dmg),
      assignedCampId("None"), reliefReceived(false) {}

int Victim::calculatePriority() const {
    return familySize * 2 + medicalNeed + damageLevel;
}
void Victim::displayDetails() const {
    cout << "Victim: " << name << " | CNIC: " << cnic
         << " | District: " << district << " | Family: " << familySize
         << " | Medical: " << medicalNeed << "/10 | Damage: " << damageLevel << "/10"
         << " | Priority Score: " << calculatePriority()
         << " | Camp: " << assignedCampId
         << " | Relief: " << (reliefReceived ? "Received" : "Pending") << endl;
}
string Victim::toFileString() const {
    return cnic + "|" + name + "|" + phone + "|" + district + "|" +
           to_string(familySize) + "|" + to_string(medicalNeed) + "|" +
           to_string(damageLevel) + "|" + assignedCampId + "|" +
           (reliefReceived ? "1" : "0");
}
bool Victim::fromFileString(const string& line, Victim& out) {
    stringstream ss(line);
    string cnic_, name_, phone_, district_, camp_;
    string f, m, d, r;
    if (!getline(ss, cnic_, '|')) return false;
    if (!getline(ss, name_, '|')) return false;
    if (!getline(ss, phone_, '|')) return false;
    if (!getline(ss, district_, '|')) return false;
    if (!getline(ss, f, '|')) return false;
    if (!getline(ss, m, '|')) return false;
    if (!getline(ss, d, '|')) return false;
    if (!getline(ss, camp_, '|')) return false;
    if (!getline(ss, r, '|')) return false;
    out = Victim(name_, cnic_, phone_, district_, stoi(f), stoi(m), stoi(d));
    out.setAssignedCampId(camp_);
    out.setReliefReceived(r == "1");
    return true;
}
