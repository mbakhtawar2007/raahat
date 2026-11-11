#include "Donor.h"
#include <iostream>
#include <sstream>
using namespace std;
Donor::Donor() : Person(), email(""), preferredType("Food") {}
Donor::Donor(string n, string c, string p, string d, string e, string pref)
    : Person(n, c, p, d), email(e), preferredType(pref) {}
void Donor::displayDetails() const {
    cout << "Donor: " << name << " | CNIC: " << cnic << " | District: " << district
         << " | Email: " << email << " | Prefers: " << preferredType << endl;
}
string Donor::toFileString() const {
    return cnic + "|" + name + "|" + phone + "|" + district + "|" + email + "|" + preferredType;
}
bool Donor::fromFileString(const string& line, Donor& out) {
    stringstream ss(line);
    string c, n, p, d, e, pref;
    if (!getline(ss, c, '|')) return false;
    if (!getline(ss, n, '|')) return false;
    if (!getline(ss, p, '|')) return false;
    if (!getline(ss, d, '|')) return false;
    if (!getline(ss, e, '|')) return false;
    if (!getline(ss, pref, '|')) return false;
    out = Donor(n, c, p, d, e, pref);
    return true;
}
