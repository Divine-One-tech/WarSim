#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

#define SIZE 10
#define NUM_OF_STATS 8 
#define COUNTRYSELECTIONSIZE 2

string countries[SIZE] =
{
    "United States of America",
    "United Kingdom", "Russia",
    "Taiwan", "South Korea", "China",
    "North Korea", "Indonesia",
    "Singapore", "Ukraine"
};

string locationsForSimulation[] =
{
    "Iwo Jima", "Streets of New York", "Shores of North Korea", "Normandy", "Taiwan"
};

int terrainDefenseAdvantage[] =
{
    4, 1, 3, 3, 4
};

int terrainOffenseAdvantage[] =
{
    1, 1, 2, 2, 1
};

float dmgTMultiplier[] =
{
    0.35, 0.3, 0.025, 0.02, 0.015, 0.01
};

void selectCountry(int *arr)
{
    int numero1, numero2;
    cout << "Please choose aggressor and defending country from this list" << endl;
    
    for (int i = 0; i < SIZE; i++)
    {
        cout << i + 1 << ". " << countries[i] << endl;
    }
    cout << "Enter the number: ";
    cin >> numero1 >> numero2;
    arr[0] = numero1;
    arr[1] = numero2;
}

int errorhandling(int i)
{
    int num;
    bool check = true;
    while ((check))
    {
        if ((i < 1 || i > SIZE) || (num < 1 || num > SIZE) || cin.fail())
        {
            cout << "Invalid Number" << endl;
            cin.clear();
            cin.ignore(INT64_MAX, '\n');
            cout << "Enter the number again: ";
        }
        else
            check = false;
        cin >> num;
    }
    return num;
}

int getLocation()
{
    bool check = true;
    int choice;
    cout << "Please choose a location u would like to simulate from this list" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << locationsForSimulation[i] << endl;
    }
    cout << "Please enter the corresponding number: ";
    while ((check))
    {
        cin >> choice;
        if ((choice < 1 || choice > SIZE) || cin.fail())
        {            
            cout << "Invalid Number" << endl;
            cin.clear();
            cin.ignore(INT64_MAX, '\n');
            cout << "Enter the number again: ";
        }
        else
            check = false;
    }
    return choice - 1;
}

int getArmyOffense(int i)
{
    ifstream inFileA1;
    string milEquipment;
    int equipmentAmount;
    int totalArmyvehicles = 0;
    inFileA1.open(countries[i].insert(countries[i].length(), "Army.txt"));

    while (true)
    {
        inFileA1 >> milEquipment >> equipmentAmount;
        if (inFileA1.fail()) break;
        totalArmyvehicles += equipmentAmount;
        if (inFileA1.eof())
            break;
    }
    return totalArmyvehicles;
}

int getArmyLog(int i)
{
    ifstream inFileA1;
    string logEquipment;
    int equipmentAmount;
    int totalArmylogVehicles = 0;
    inFileA1.open(countries[i].insert(countries[i].length(), "ArmyL.txt"));

    while (true)
    {
        inFileA1 >> logEquipment >> equipmentAmount;
        if (inFileA1.fail()) break;
        totalArmylogVehicles += equipmentAmount;
        if (inFileA1.eof())
            break;
    }
    return totalArmylogVehicles;
}

int getAirForceOffense(int i)
{
    ifstream inFileA2;
    string milEquipment;
    int equipmentAmount;
    int totalCombatAircraft = 0;
    inFileA2.open(countries[i].insert(countries[i].length(), "AirForce.txt"));

    while (true)
    {
        inFileA2 >> milEquipment >> equipmentAmount;
        if (inFileA2.fail()) break;
        totalCombatAircraft += equipmentAmount;
        if (inFileA2.eof())
            break;
    }
    return totalCombatAircraft;
}

int getAirForceLog(int i)
{
    ifstream inFileA2;
    string logEquipment;
    int equipmentAmount;
    int totalLogVehicle = 0;
    inFileA2.open(countries[i].insert(countries[i].length(), "AirForceL.txt"));

    while (true)
    {
        inFileA2 >> logEquipment >> equipmentAmount;
        if (inFileA2.fail()) break;
        totalLogVehicle += equipmentAmount;
        if (inFileA2.eof())
            break;
    }
    return totalLogVehicle;
}

int getNavyOffense(int i)
{
    ifstream inFileA3;
    string milEquipment;
    int equipmentAmount;
    int totalNavalVessels = 0;
    inFileA3.open(countries[i].insert(countries[i].length(), "Navy.txt"));

    while (true)
    {
        inFileA3 >> milEquipment >> equipmentAmount;
        if (inFileA3.fail()) break;
        totalNavalVessels += equipmentAmount;
        if (inFileA3.eof())
            break;
    }
    return totalNavalVessels;
}

int getNavyLog(int i)
{
    ifstream inFileA3;
    string logEquipment;
    int equipmentAmount;
    int totalLogVehicles = 0;
    inFileA3.open(countries[i].insert(countries[i].length(), "NavyL.txt"));

    while (true)
    {
        inFileA3 >> logEquipment >> equipmentAmount;
        if (inFileA3.fail()) break;
        totalLogVehicles += equipmentAmount;
        if (inFileA3.eof())
            break;
    }
    return totalLogVehicles;
}

int getMarinesOffense(int i)
{
    ifstream inFileA4;
    string milEquipment;
    int equipmentAmount;
    int totalCombatCapability = 0;
    inFileA4.open(countries[i].insert(countries[i].length(), "Marine.txt"));

    while (true)
    {
        inFileA4 >> milEquipment >> equipmentAmount;
        if (inFileA4.fail()) break;
        totalCombatCapability += equipmentAmount;
        if (inFileA4.eof())
            break;
    }
    return totalCombatCapability;
}

int getMarinesLog(int i)
{
    ifstream inFileA4;
    string logEquipment;
    int equipmentAmount;
    int totalLogVehicle = 0;
    inFileA4.open(countries[i].insert(countries[i].length(), "MarineL.txt"));

    while (true)
    {
        inFileA4 >> logEquipment >> equipmentAmount;
        if (inFileA4.fail()) break;
        totalLogVehicle += equipmentAmount;
        if (inFileA4.eof())
            break;
    }
    return totalLogVehicle;
}

float calcDmgTMultiplier(int i)
{
    int identifier;
    float dmgMultiplier;

    identifier = i / 500;
    if (identifier > 5)
    {
        identifier = 5;
    }
    dmgMultiplier = dmgTMultiplier[identifier];

    return dmgMultiplier;
}

int calcDmgOMultiplier(int i)
{
    int dmgMultiplier;
    dmgMultiplier = i / 500;
    if (dmgMultiplier == 0)
    {
        dmgMultiplier = 1;
    }
    if (dmgMultiplier > 6)
    {
        dmgMultiplier = 6;
    }
    return dmgMultiplier;
}

float calcLandOccupied(int totalArComCapA, int finalArComCapA, int totalArComCapB, int finalArComCapB)
{
    float percent;
    if (finalArComCapA > finalArComCapB)
    {
        return (totalArComCapA - finalArComCapA) / totalArComCapA * 100;
    }
    else if (finalArComCapA < finalArComCapB)
    {
        return (totalArComCapA - finalArComCapA) / totalArComCapA * 100 * 0.5;
    }
}

void getCountryAStats(int *arr, int i)
{
    arr[0] = getArmyOffense(i);
    arr[1] = getArmyLog(i);
    arr[2] = getAirForceOffense(i);
    arr[3] = getAirForceLog(i);
    arr[4] = getNavyOffense(i);
    arr[5] = getNavyLog(i);
    arr[6] = getMarinesOffense(i);
    arr[7] = getMarinesLog(i);
}

void getCountryBStats(int *arr, int i)
{
    arr[0] = getArmyOffense(i);
    arr[1] = getArmyLog(i);
    arr[2] = getAirForceOffense(i);
    arr[3] = getAirForceLog(i);
    arr[4] = getNavyOffense(i);
    arr[5] = getNavyLog(i);
    arr[6] = getMarinesOffense(i);
    arr[7] = getMarinesLog(i);
}

int dmgModel(int t, int m)
{
    return t - (t * m);
}

void writeToText(int *arr, int i)
{
    ofstream outFile;
    outFile.open("Simulation_Result.txt");
    if (!outFile)
    {
        cerr << "Error\n";
    }
    else
    {
        outFile << setprecision(2) << fixed << left;
        outFile << "Initial Country A Strength\n" << setw(15) << "Army" << setw(15) << "Air Force" << "Navy\n";
        outFile << setw(15) << arr[0] << setw(15) << arr[1] << arr[2] << endl << endl;
        outFile << "Initial Country B Strength\n" << setw(15) << "Army" << setw(15) << "Air Force" << "Navy\n";
        outFile << setw(15) << arr[6] << setw(15) << arr[7] << arr[8] << endl << endl;
        outFile << "Final Country A Strength\n" << setw(15) << "Army" << setw(15) << "Air Force" << "Navy\n";
        outFile << setw(15) << arr[3] << setw(15) << arr[4] << arr[5] << endl << endl;
        outFile << "Final Country B Strength\n" << setw(15) << "Army" << setw(15) << "Air Force" << "Navy\n";
        outFile << setw(15) << arr[9] << setw(15) << arr[10] << arr[11] << endl << endl;
        outFile << "Area conquered by Country A: " << i << "%" << endl;
    }
}

int main()
{
    int  l, lO, totalArComCapA, totalAiComCapA, totalNComCapA, totalArComCapB, totalAiComCapB, totalNComCapB, finalArComCapA, finalAiComCapA, finalNComCapA, finalArComCapB, finalAiComCapB, finalNComCapB;
    int countryStatsAgressor[NUM_OF_STATS];
    int countryStatsDefender[NUM_OF_STATS];
    int selectCountries[COUNTRYSELECTIONSIZE];
    l = getLocation();
    selectCountry(selectCountries);
    for (int i = 0; i < 2; i++)
    {
        selectCountries[i] = errorhandling(selectCountries[i]);
    }
    // Country A
    getCountryAStats(countryStatsAgressor, selectCountries[0]);
    // Country B
    getCountryBStats(countryStatsDefender, selectCountries[1]);
    // Computation for troop value on both sides
    totalArComCapA = countryStatsAgressor[0] * calcDmgOMultiplier(countryStatsAgressor[1]) + (0.075 * countryStatsAgressor[2]) + (0.15 * countryStatsAgressor[4]) + ((0.7 * countryStatsAgressor[6]) * calcDmgOMultiplier(countryStatsAgressor[7])) * terrainOffenseAdvantage[l];
    totalAiComCapA = countryStatsAgressor[2] * calcDmgTMultiplier(countryStatsAgressor[3]);
    totalNComCapA = countryStatsAgressor[4] * calcDmgOMultiplier(countryStatsAgressor[5]) + (0.075 * countryStatsAgressor[2]) + ((0.3 * countryStatsAgressor[6]) * calcDmgOMultiplier(countryStatsAgressor[7]));

    totalArComCapB = countryStatsDefender[0] * calcDmgOMultiplier(countryStatsDefender[1]) + (0.075 * countryStatsDefender[2]) + (0.15 * countryStatsDefender[4]) + ((0.7 * countryStatsDefender[6]) * calcDmgOMultiplier(countryStatsDefender[7])) * terrainDefenseAdvantage[l];
    totalAiComCapB = countryStatsDefender[2] * calcDmgTMultiplier(countryStatsDefender[3]);
    totalNComCapB = countryStatsDefender[4] * calcDmgOMultiplier(countryStatsDefender[5]) + (0.075 * countryStatsDefender[2]) + ((0.3 * countryStatsDefender[6]) * calcDmgOMultiplier(countryStatsDefender[7]));
    // Damage Model
    finalArComCapA = dmgModel(totalArComCapA, calcDmgTMultiplier(countryStatsAgressor[1]));
    finalAiComCapA = dmgModel(totalAiComCapA, calcDmgTMultiplier(countryStatsAgressor[3]));
    finalNComCapA = dmgModel(totalNComCapA, calcDmgTMultiplier(countryStatsAgressor[5]));

    finalArComCapB = dmgModel(totalAiComCapB, calcDmgTMultiplier(countryStatsDefender[1]));
    finalAiComCapB = dmgModel(totalAiComCapB, calcDmgTMultiplier(countryStatsDefender[3]));
    finalNComCapA = dmgModel(totalNComCapB, calcDmgTMultiplier(countryStatsDefender[5]));
    // Occupation Percentage
    lO = calcLandOccupied(totalArComCapA, finalArComCapA, totalArComCapB, finalArComCapB);
    // Readout
    int arr[] = {
        totalArComCapA,
        totalAiComCapA,
        totalNComCapA,
        finalArComCapA,
        finalAiComCapA,
        finalNComCapA,
        totalArComCapB,
        totalAiComCapB,
        totalNComCapB,
        finalArComCapB,
        finalAiComCapB,
        finalNComCapA
    };
    writeToText(arr, lO);
    return 0;
}