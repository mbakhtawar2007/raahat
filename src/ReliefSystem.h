#pragma once
// ReliefSystem.h — Bakhtawar (manager class)
#include "Victim.h"
#include "Volunteer.h"
#include "Donor.h"
#include "ReliefCamp.h"
#include "Donation.h"
#include <vector>
#include <string>
using namespace std;

class ReliefSystem {
private:
    vector<Victim> victims;
    vector<Volunteer> volunteers;
    vector<Donor> donors;
    vector<ReliefCamp> camps;
    vector<Donation> donations;
    int donationCounter;
    void loadVictims(); void loadCamps(); void loadDonations(); void loadVolunteers(); void loadDonors();
    void saveVictims(); void saveCamps(); void saveDonations(); void saveVolunteers(); void saveDonors();
public:
    ReliefSystem();
    void loadAll();
    void saveAll();
    static bool isValidCNIC(const string& cnic);
    static string readLine(const string& prompt);
    static int readInt(const string& prompt, int minV, int maxV);
    void registerVictim();
    void addCamp();
    void addDonation();
    void registerVolunteer();
    void registerDonor();
    void assignCamps();
    void distributeRelief();
    void searchByCNIC();
    void searchByDistrict();
    void showDashboard();
    void showAllVictims();
    void showAllCamps();
    void showAllDonations();
    void showAllVolunteers();
    int totalFoodAvailable() const;
};
