#include "ReliefSystem.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <cctype>
#include <limits>
#include <stdexcept>
using namespace std;

ReliefSystem::ReliefSystem() : donationCounter(100) {}
bool ReliefSystem::isValidCNIC(const string& c) {
    if (c.size() != 15) return false;
    if (c[5] != '-' || c[13] != '-') return false;
    for (size_t i = 0; i < c.size(); i++) {
        if (i == 5 || i == 13) continue;
        if (!isdigit((unsigned char)c[i])) return false;
    }
    return true;
}
string ReliefSystem::readLine(const string& prompt) {
    cout << prompt;
    string s; getline(cin, s);
    return s;
}
int ReliefSystem::readInt(const string& prompt, int minV, int maxV) {
    while (true) {
        cout << prompt;
        int v;
        if (cin >> v && v >= minV && v <= maxV) { cin.ignore(numeric_limits<streamsize>::max(), '\n'); return v; }
        cout << "Invalid input. Enter a number between " << minV << " and " << maxV << ".\n";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
void ReliefSystem::loadVictims() { ifstream f("data/victims.txt"); string l; while (getline(f, l)) { Victim v; if (Victim::fromFileString(l, v)) victims.push_back(v); } }
void ReliefSystem::loadCamps() { ifstream f("data/camps.txt"); string l; while (getline(f, l)) { ReliefCamp c; if (ReliefCamp::fromFileString(l, c)) camps.push_back(c); } }
void ReliefSystem::loadDonations() { ifstream f("data/donations.txt"); string l; while (getline(f, l)) { Donation d; if (Donation::fromFileString(l, d)) { donations.push_back(d); donationCounter++; } } }
void ReliefSystem::loadVolunteers() { ifstream f("data/volunteers.txt"); string l; while (getline(f, l)) { Volunteer v; if (Volunteer::fromFileString(l, v)) volunteers.push_back(v); } }
void ReliefSystem::loadDonors() { ifstream f("data/donors.txt"); string l; while (getline(f, l)) { Donor d; if (Donor::fromFileString(l, d)) donors.push_back(d); } }
void ReliefSystem::loadAll() { loadVictims(); loadCamps(); loadDonations(); loadVolunteers(); loadDonors(); }
void ReliefSystem::saveVictims() { ofstream f("data/victims.txt"); for (auto& v : victims) f << v.toFileString() << "\n"; }
void ReliefSystem::saveCamps() { ofstream f("data/camps.txt"); for (auto& c : camps) f << c.toFileString() << "\n"; }
void ReliefSystem::saveDonations() { ofstream f("data/donations.txt"); for (auto& d : donations) f << d.toFileString() << "\n"; }
void ReliefSystem::saveVolunteers() { ofstream f("data/volunteers.txt"); for (auto& v : volunteers) f << v.toFileString() << "\n"; }
void ReliefSystem::saveDonors() { ofstream f("data/donors.txt"); for (auto& d : donors) f << d.toFileString() << "\n"; }
void ReliefSystem::saveAll() { saveVictims(); saveCamps(); saveDonations(); saveVolunteers(); saveDonors(); }

void ReliefSystem::registerVictim() {
    string name = readLine("Name: ");
    string cnic = readLine("CNIC (42101-1234567-1): ");
    if (!isValidCNIC(cnic)) throw invalid_argument("Invalid CNIC format. Use 42101-1234567-1.");
    for (auto& v : victims) if (v.getCNIC() == cnic) throw invalid_argument("Duplicate CNIC. This victim is already registered.");
    string phone = readLine("Phone: ");
    string district = readLine("District (e.g. Sukkur): ");
    int fam = readInt("Family size (1-20): ", 1, 20);
    int med = readInt("Medical need 0-10 (10 = critical): ", 0, 10);
    int dmg = readInt("House damage 0-10 (10 = fully destroyed): ", 0, 10);
    Victim v(name, cnic, phone, district, fam, med, dmg);
    victims.push_back(v);
    cout << "Registered! Priority Score = " << v.calculatePriority() << " (family*2 + medical + damage)\n";
}
void ReliefSystem::addCamp() {
    string id = readLine("Camp ID (e.g. CAMP-04): ");
    string name = readLine("Camp name: ");
    string district = readLine("District: ");
    int cap = readInt("Capacity (1-1000): ", 1, 1000);
    int food = readInt("Food packs in stock: ", 0, 100000);
    int med = readInt("Medicine kits: ", 0, 100000);
    int tents = readInt("Tents: ", 0, 100000);
    camps.push_back(ReliefCamp(id, name, district, cap, food, med, tents));
    cout << "Camp added.\n";
}
void ReliefSystem::addDonation() {
    string name = readLine("Donor name: ");
    string cnic = readLine("Donor CNIC (42101-1234567-1): ");
    if (!isValidCNIC(cnic)) throw invalid_argument("Invalid CNIC format.");
    cout << "Type: 1 Food  2 Cash  3 Tents  4 Medicine  5 Clothes\n";
    int t = readInt("Choose type (1-5): ", 1, 5);
    string types[] = {"", "Food", "Cash", "Tents", "Medicine", "Clothes"};
    int qty = readInt("Quantity (must be > 0): ", 1, 1000000);
    string id = "DON-" + to_string(++donationCounter);
    donations.push_back(Donation(id, name, cnic, types[t], qty));
    cout << "Donation " << id << " recorded: " << qty << " x " << types[t] << " (Collected)\n";
}
void ReliefSystem::registerVolunteer() {
    string name = readLine("Name: ");
    string cnic = readLine("CNIC (42101-1234567-1): ");
    if (!isValidCNIC(cnic)) throw invalid_argument("Invalid CNIC format.");
    string phone = readLine("Phone: ");
    string district = readLine("District: ");
    string skill = readLine("Skill (Medical / Driver / Cook / General): ");
    string avail = readLine("Availability (e.g. Mon-Fri): ");
    volunteers.push_back(Volunteer(name, cnic, phone, district, skill, avail));
    cout << "Volunteer registered.\n";
}
void ReliefSystem::registerDonor() {
    string name = readLine("Name: ");
    string cnic = readLine("CNIC (42101-1234567-1): ");
    if (!isValidCNIC(cnic)) throw invalid_argument("Invalid CNIC format.");
    string phone = readLine("Phone: ");
    string district = readLine("District: ");
    string email = readLine("Email: ");
    string pref = readLine("Preferred donation type: ");
    donors.push_back(Donor(name, cnic, phone, district, email, pref));
    cout << "Donor registered.\n";
}
void ReliefSystem::assignCamps() {
    int assigned = 0;
    for (auto& v : victims) {
        if (v.getAssignedCampId() != "None") continue;
        ReliefCamp* chosen = nullptr;
        for (auto& c : camps) if (c.getDistrict() == v.getDistrict() && c.hasSpace()) { chosen = &c; break; }
        if (!chosen) for (auto& c : camps) if (c.hasSpace()) { chosen = &c; break; }
        if (chosen) { chosen->assignVictim(); v.setAssignedCampId(chosen->getCampId()); assigned++; }
    }
    cout << assigned << " victim(s) assigned to camps. Others are on the waiting list (all camps full).\n";
}
int ReliefSystem::totalFoodAvailable() const {
    int total = 0;
    for (auto& d : donations) if (d.getType() == "Food" && d.getStatus() == "Collected") total += d.getQuantity();
    return total;
}
void ReliefSystem::distributeRelief() {
    int available = totalFoodAvailable();
    if (available <= 0) { cout << "No Food donations available. Add a Food donation first.\n"; return; }
    if (victims.empty()) { cout << "No victims registered.\n"; return; }
    // Priority queue logic: sort indices by priority score, highest first
    vector<int> idx;
    for (size_t i = 0; i < victims.size(); i++) idx.push_back((int)i);
    sort(idx.begin(), idx.end(), [&](int a, int b){ return victims[a].calculatePriority() > victims[b].calculatePriority(); });
    cout << "\n--- Distribution by Priority (highest first) ---\n";
    cout << "Food available: " << available << " packs\n";
    int remaining = available;
    for (int i : idx) {
        int need = victims[i].getFamilySize(); // 1 pack per family member
        if (remaining <= 0) break;
        int given = min(need, remaining);
        remaining -= given;
        if (given >= need) victims[i].setReliefReceived(true);
        cout << victims[i].getName() << " (Score " << victims[i].calculatePriority() << ") -> " << given << " packs"
             << (given >= need ? " [Fully served]" : " [Partial]") << "\n";
    }
    // Mark food donations as distributed as stock is used
    int used = available - remaining;
    for (auto& d : donations) {
        if (used <= 0) break;
        if (d.getType() == "Food" && d.getStatus() == "Collected") {
            int take = min(d.getQuantity(), used);
            d.setQuantity(d.getQuantity() - take); used -= take;
            if (d.getQuantity() == 0) d.setStatus("Distributed");
        }
    }
    cout << "Remaining food: " << remaining << " packs\n";
}
void ReliefSystem::searchByCNIC() {
    string cnic = readLine("Enter CNIC to search: ");
    for (auto& v : victims) if (v.getCNIC() == cnic) { v.displayDetails(); return; }
    cout << "No victim found with CNIC " << cnic << ".\n";
}
void ReliefSystem::searchByDistrict() {
    string d = readLine("Enter district: ");
    bool found = false;
    for (auto& v : victims) if (v.getDistrict() == d) { v.displayDetails(); found = true; }
    if (!found) cout << "No victims from " << d << ".\n";
}
void ReliefSystem::showDashboard() {
    int collected = 0, distributed = 0;
    for (auto& d : donations) { if (d.getStatus() == "Collected") collected += d.getQuantity(); else distributed += d.getQuantity(); }
    int served = 0; for (auto& v : victims) if (v.hasReceivedRelief()) served++;
    cout << "\n========== RAAHAT DASHBOARD ==========\n";
    cout << "Total Victims: " << victims.size() << " | Served: " << served << " | Pending: " << (victims.size() - served) << "\n";
    cout << "Total Camps: " << camps.size() << " | Volunteers: " << volunteers.size() << " | Donors: " << donors.size() << "\n";
    cout << "Donations Collected: " << collected << " | Distributed: " << distributed << "\n";
    cout << "--- Victims by District ---\n";
    map<string,int> byDistrict;
    for (auto& v : victims) byDistrict[v.getDistrict()]++;
    for (auto& p : byDistrict) cout << "  " << p.first << ": " << p.second << "\n";
    cout << "--- Camps ---\n";
    for (auto& c : camps) c.displayDetails();
}
void ReliefSystem::showAllVictims() { if (victims.empty()) { cout << "No victims yet.\n"; return; } for (auto& v : victims) v.displayDetails(); }
void ReliefSystem::showAllCamps() { if (camps.empty()) { cout << "No camps yet.\n"; return; } for (auto& c : camps) c.displayDetails(); }
void ReliefSystem::showAllDonations() { if (donations.empty()) { cout << "No donations yet.\n"; return; } for (auto& d : donations) d.displayDetails(); }
void ReliefSystem::showAllVolunteers() { if (volunteers.empty()) { cout << "No volunteers yet.\n"; return; } for (auto& v : volunteers) v.displayDetails(); }
