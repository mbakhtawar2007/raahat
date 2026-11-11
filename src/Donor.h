#pragma once
// Donor.h — Raza Ahmed
#include "Person.h"
#include <string>
using namespace std;

class Donor : public Person {
private:
    string email;
    string preferredType; // Cash / Food / Tents / Medicine / Clothes
public:
    Donor();
    Donor(string name, string cnic, string phone, string district, string email, string pref);
    string getEmail() const { return email; }
    string getPreferredType() const { return preferredType; }
    void displayDetails() const override;
    string toFileString() const;
    static bool fromFileString(const string& line, Donor& out);
};
