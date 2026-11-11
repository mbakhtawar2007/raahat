#include "Person.h"
Person::Person() : name(""), cnic(""), phone(""), district("") {}
Person::Person(string n, string c, string p, string d)
    : name(n), cnic(c), phone(p), district(d) {}
