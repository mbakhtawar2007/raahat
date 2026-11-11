#pragma once
// Person.h — Bakhtawar
// Abstract base class. Every person in Raahat IS-A Person.
// Demonstrates: Abstraction + Inheritance + Polymorphism (virtual displayDetails)
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string cnic;      // format: 42101-1234567-1
    string phone;
    string district;
public:
    Person();
    Person(string name, string cnic, string phone, string district);
    virtual ~Person() {}
    string getName() const { return name; }
    string getCNIC() const { return cnic; }
    string getPhone() const { return phone; }
    string getDistrict() const { return district; }
    void setName(string n) { name = n; }
    void setPhone(string p) { phone = p; }
    void setDistrict(string d) { district = d; }
    virtual void displayDetails() const = 0; // pure virtual -> abstract
};
