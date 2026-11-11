#include "Volunteer.h"
#include <iostream>
#include <sstream>
using namespace std;
Volunteer::Volunteer() : Person(), skill("General"), availability(""), assignedCampId("None") {}
Volunteer::Volunteer(string n, string c, string p, string d, string s, string a)
    : Person(n, c, p, d), skill(s), availability(a), assignedCampId("None") {}
void Volunteer::displayDetails() const {
    cout << "Volunteer: " << name << " | CNIC: " << cnic << " | District: " << district
         << " | Skill: " << skill << " | Available: " << availability
         << " | Camp: " << assignedCampId << endl;
}
string Volunteer::toFileString() const {
    return cnic + "|" + name + "|" + phone + "|" + district + "|" + skill + "|" + availability + "|" + assignedCampId;
}
bool Volunteer::fromFileString(const string& line, Volunteer& out) {
    stringstream ss(line);
    string c, n, p, d, s, a, camp;
    if (!getline(ss, c, '|')) return false;
    if (!getline(ss, n, '|')) return false;
    if (!getline(ss, p, '|')) return false;
    if (!getline(ss, d, '|')) return false;
    if (!getline(ss, s, '|')) return false;
    if (!getline(ss, a, '|')) return false;
    if (!getline(ss, camp, '|')) return false;
    out = Volunteer(n, c, p, d, s, a);
    out.setAssignedCampId(camp);
    return true;
}
