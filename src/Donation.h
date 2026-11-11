#pragma once
// Donation.h — Kaif
#include <string>
using namespace std;
class Donation {
private:
    string donationId, donorName, donorCNIC, type, status; // type: Cash/Food/Tents/Medicine/Clothes
    int quantity;
public:
    Donation();
    Donation(string id, string donorName, string donorCNIC, string type, int qty);
    string getId() const { return donationId; }
    string getDonorName() const { return donorName; }
    string getType() const { return type; }
    int getQuantity() const { return quantity; }
    string getStatus() const { return status; }
    void setQuantity(int q) { quantity = q; }
    void setStatus(string s) { status = s; }
    void displayDetails() const;
    string toFileString() const;
    static bool fromFileString(const string& line, Donation& out);
};
