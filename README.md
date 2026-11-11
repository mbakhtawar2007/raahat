# Raahat — Flood Relief & Donation Management System

C++ Finals Project — OOP, Data Structures, File Handling.
Team: Muhammad Bakhtawar (Lead Developer), Muhammad Kaif (Core Developer),
Raza Ahmed (Supporting Developer + Presentation), Fiza (UI / Reports / Presentation).

## The problem
Flood relief in Sindh / Punjab is still run on paper — who needs help most,
which camp has space, where donations went. Raahat replaces that with one
console system: register victims, score them by need, assign the nearest camp
with space, track donations, and distribute by priority, not first-come-first-served.

## Priority score
`Score = familySize × 2 + medicalNeed (0–10) + damageLevel (0–10)`
Example: Ayesha, family 6, medical 9, damage 8 → 29. She is served first.

## How to run
```bash
bash compile.sh
./raahat
```
Windows (MinGW / VS Code terminal):
```bash
g++ -std=c++17 src/*.cpp -o raahat.exe
raahat.exe
```
Run from the project folder so `data/` files are found. Data is auto-saved after every action.

## Menu
1 Register Victim · 2 Add Camp · 3 Add Donation · 4 Register Volunteer ·
5 Register Donor · 6 Assign Camps · 7 Distribute Relief · 8 Search by CNIC ·
9 Search by District · 10 Dashboard · 11–13 View All · 14 Save & Exit

## 3-minute demo for the teacher
1. View Dashboard (10) — 3 victims, 3 camps, 4 donations already loaded.
2. Assign Camps (6) — Ayesha → Sukkur camp, Ahmed → Larkana, Bilal → Dadu.
3. Distribute Relief (7) — 100 food packs go to Ayesha first (score 29), not first-registered.
4. Search by CNIC (8) — `42101-1111111-1` shows Ayesha, camp assigned, relief received.
5. Exit (14), run again — data is still there. That proves file handling.

## Classes (OOP coverage)
- `Person` (abstract) → `Victim`, `Volunteer`, `Donor` — inheritance, polymorphism (`displayDetails()`)
- `ReliefCamp`, `Donation`, `ReliefSystem` — encapsulation
- `vector`, `map`, sorting, priority order — data structures
- `victims.txt`, `camps.txt`, `donations.txt`, `volunteers.txt`, `donors.txt` — file handling
- CNIC validation, duplicate CNIC, negative donation, camp-full — exception handling

## Files
```
src/Person.h/.cpp  src/Victim.h/.cpp  src/Volunteer.h/.cpp  src/Donor.h/.cpp
src/ReliefCamp.h/.cpp  src/Donation.h/.cpp
src/ReliefSystem.h/.cpp  src/main.cpp
data/*.txt  compile.sh  README.md
```
