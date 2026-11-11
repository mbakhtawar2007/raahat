#pragma once
// Volunteer.h — Raza Ahmed
#include "Person.h"
#include <string>
using namespace std;

class Volunteer : public Person {
private:
    string skill; // Medical / Driver / Cook / General
    string availability;
    string assignedCampId;
public:
    Volunteer();
    Volunteer(string name, string cnic, string phone, string district,
              string skill, string availability);
    string getSkill() const { return skill; }
    string getAvailability() const { return availability; }
    string getAssignedCampId() const { return assignedCampId; }
    void setAssignedCampId(string id) { assignedCampId = id; }
    void displayDetails() const override;
    string toFileString() const;
    static bool fromFileString(const string& line, Volunteer& out);
};
