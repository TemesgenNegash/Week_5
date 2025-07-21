// Assignment_12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class FifaRanking {
public:
    int rank;
    string country_full;
    string country_abrv;
    float total_points;
    int previous_points;
    int rank_change;

    //constructor to initialize ranking data
    FifaRanking(int r, string cf, string ca, float tp, int pp, int rc)
        : rank(r), country_full(cf), country_abrv(ca), total_points(tp),
        previous_points(pp), rank_change(rc) {}

    //display
    void display() const {
        cout << "Rank: " << rank << "\n"
            << "Country: " << country_full << "\n"
            << "Abbreviation: " << country_abrv << "\n"
            << "Total Points: " << total_points << "\n"
            << "Previous Points: " << previous_points << "\n"
            << "Rank Change: " << rank_change << "\n"
            << "-----------------------------\n";
    }
};
int main() {
    ifstream file("fifa_ranking.csv"); //opens .cvs file
    
    // Check that file opened successfully
    if (!file.is_open()) {
        cerr << "Error, could not open file." << endl;
        return 1;
    }

    string line;
    vector<FifaRanking> rankings;

    getline(file, line); //skips header line

    int count = 0;
    while (getline(file, line) && count < 10) {
        stringstream ss(line);
        string rankStr, country_full, country_abrv, totalStr, previousStr, changeStr;

        //extract-> separated by commas
        getline(ss, rankStr, ',');
        getline(ss, country_full, ',');
        getline(ss, country_abrv, ',');
        getline(ss, totalStr, ',');
        getline(ss, previousStr, ',');
        getline(ss, changeStr, ',');

        int rank = stoi(rankStr);
        float total_points = stof(totalStr);
        int previous_points = stoi(previousStr);
        int rank_change = stoi(changeStr);
        // Create object and store it
        rankings.emplace_back(rank, country_full, country_abrv, total_points, previous_points, rank_change);
        count++;
    }

    for (const auto& team : rankings) {
        team.display();
    }

    return 0;
}
/*Rank: 1
Country: Germany
Abbreviation: GER
Total Points: 0
Previous Points: 57
Rank Change: 0
-----------------------------
Rank: 2
Country: Italy
Abbreviation: ITA
Total Points: 0
Previous Points: 57
Rank Change: 0
-----------------------------
Rank: 3
Country: Switzerland
Abbreviation: SUI
Total Points: 0
Previous Points: 50
Rank Change: 9
-----------------------------
Rank: 4
Country: Sweden
Abbreviation: SWE
Total Points: 0
Previous Points: 55
Rank Change: 0
-----------------------------
Rank: 5
Country: Argentina
Abbreviation: ARG
Total Points: 0
Previous Points: 51
Rank Change: 5
-----------------------------
Rank: 6
Country: Republic of Ireland
Abbreviation: IRL
Total Points: 0
Previous Points: 54
Rank Change: 0
-----------------------------
Rank: 7
Country: Russia
Abbreviation: RUS
Total Points: 0
Previous Points: 52
Rank Change: 1
-----------------------------
Rank: 8
Country: Brazil
Abbreviation: BRA
Total Points: 0
Previous Points: 55
Rank Change: -5
-----------------------------
Rank: 9
Country: Norway
Abbreviation: NOR
Total Points: 0
Previous Points: 49
Rank Change: 5
-----------------------------
Rank: 10
Country: Denmark
Abbreviation: DEN
Total Points: 0
Previous Points: 51
Rank Change: -1
-----------------------------

C:\CIS-25\Assignment_12\x64\Debug\Assignment_12.exe (process 19992) exited with code 0 (0x0).
Press any key to close this window . . .*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
