#pragma once
// Victim.h — Kaif
// Victim IS-A Person. Priority = familySize*2 + medicalNeed + damageLevel.
#include "Person.h"
#include <string>
using namespace std;

class Victim : public Person {
private:
    int familySize;
    int medicalNeed;   // 0-10
    int damageLevel;   // 0-10
    string assignedCampId;
    bool reliefReceived;
public:
    Victim();
    Victim(string name, string cnic, string phone, string district,
           int familySize, int medicalNeed, int damageLevel);
    int calculatePriority() const;
    int getFamilySize() const { return familySize; }
    int getMedicalNeed() const { return medicalNeed; }
    int getDamageLevel() const { return damageLevel; }
    string getAssignedCampId() const { return assignedCampId; }
    bool hasReceivedRelief() const { return reliefReceived; }
    void setAssignedCampId(string id) { assignedCampId = id; }
    void setReliefReceived(bool v) { reliefReceived = v; }
    void displayDetails() const override;
    string toFileString() const;
    static bool fromFileString(const string& line, Victim& out);
};
