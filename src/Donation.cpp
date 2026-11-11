#include "Donation.h"
#include <iostream>
#include <sstream>
using namespace std;
Donation::Donation() : donationId(""), donorName(""), donorCNIC(""), type("Food"), status("Collected"), quantity(0) {}
Donation::Donation(string id, string dn, string dc, string t, int q)
    : donationId(id), donorName(dn), donorCNIC(dc), type(t), status("Collected"), quantity(q) {}
void Donation::displayDetails() const {
    cout << donationId << " | Donor: " << donorName << " | Type: " << type
         << " | Qty: " << quantity << " | Status: " << status << endl;
}
string Donation::toFileString() const {
    return donationId + "|" + donorName + "|" + donorCNIC + "|" + type + "|" + to_string(quantity) + "|" + status;
}
bool Donation::fromFileString(const string& line, Donation& out) {
    stringstream ss(line);
    string id, dn, dc, t, q, s;
    if (!getline(ss, id, '|')) return false;
    if (!getline(ss, dn, '|')) return false;
    if (!getline(ss, dc, '|')) return false;
    if (!getline(ss, t, '|')) return false;
    if (!getline(ss, q, '|')) return false;
    if (!getline(ss, s, '|')) return false;
    out = Donation(id, dn, dc, t, stoi(q));
    out.setStatus(s);
    return true;
}
