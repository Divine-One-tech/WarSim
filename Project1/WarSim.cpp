#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

#define SIZE 10

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

int getCountryA()
{
    bool check = true;
    int numero;
    cout << "Please choose aggressor country from this list: " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << i + 1 << ". " << countries[i] << endl;
    }
    cout << "Enter the number: ";
    while ((check))
    {
        cin >> numero;
        if ((numero < 1 || numero > SIZE) || cin.fail())
        {
            cout << "Invalid Number" << endl;
            cin.clear();
            cin.ignore(INT64_MAX, '\n');
            cout << "Enter the number again: ";
        }
        else
            check = false;
    }
    return numero - 1;
}

int getCountryB()
{
    bool check = true;
    int numero;
    cout << "Please choose defensive country from this list: " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << i + 1 << ". " << countries[i] << endl;
    }
    cout << "Enter the number: ";
    while ((check))
    {
        cin >> numero;
        if ((numero < 1 || numero > SIZE) || cin.fail())
        {
            cout << "Invalid Number" << endl;
            cin.clear();
            cin.ignore(INT64_MAX, '\n');
            cout << "Enter the number again: ";
        }
        else
            check = false;
    }
    return numero - 1;
}

int getLocation()
{
    int choice;
    cout << "Please choose a location u would like to simulate from this list" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << locationsForSimulation[i] << endl;
    }
    cout << "Please enter the corresponding number: ";
    cin >> choice;
    return choice - 1;
}

int getArmyOffenseA(int a)
{
    ifstream inFileA1;
    string milEquipment;
    int equipmentAmount;
    int totalArmyvehicles = 0;
    inFileA1.open(countries[a].insert(countries[a].length(), "Army.txt"));

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

int getArmylogisticsA(int a)
{
    ifstream inFileA1;
    string logEquipment;
    int equipmentAmount;
    int totalArmylogVehicles = 0;
    inFileA1.open(countries[a].insert(countries[a].length(), "ArmyL.txt"));

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

int getAirForceOffenseA(int a)
{
    ifstream inFileA2;
    string milEquipment;
    int equipmentAmount;
    int totalCombatAircraft = 0;
    inFileA2.open(countries[a].insert(countries[a].length(), "AirForce.txt"));

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

int getAirForceLogA(int a)
{
    ifstream inFileA2;
    string logEquipment;
    int equipmentAmount;
    int totalLogVehicle = 0;
    inFileA2.open(countries[a].insert(countries[a].length(), "AirForceL.txt"));

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

int getNavyOffenseA(int a)
{
    ifstream inFileA3;
    string milEquipment;
    int equipmentAmount;
    int totalNavalVessels = 0;
    inFileA3.open(countries[a].insert(countries[a].length(), "Navy.txt"));

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

int getNavyLogA(int a)
{
    ifstream inFileA3;
    string logEquipment;
    int equipmentAmount;
    int totalLogVehicles = 0;
    inFileA3.open(countries[a].insert(countries[a].length(), "NavyL.txt"));

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

int getMarinesOffenseA(int a)
{
    ifstream inFileA4;
    string milEquipment;
    int equipmentAmount;
    int totalCombatCapability = 0;
    inFileA4.open(countries[a].insert(countries[a].length(), "Marine.txt"));

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

int getMarinesLogA(int a)
{
    ifstream inFileA4;
    string logEquipment;
    int equipmentAmount;
    int totalLogVehicle = 0;
    inFileA4.open(countries[a].insert(countries[a].length(), "MarineL.txt"));

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

int getArmyOffenseB(int b)
{
    ifstream inFileB1;
    string milEquipment;
    int equipmentAmount;
    int totalArmyvehicles = 0;
    inFileB1.open(countries[b].insert(countries[b].length(), "Army.txt"));

    while (true)
    {
        inFileB1 >> milEquipment >> equipmentAmount;
        if (inFileB1.fail())  break;
        totalArmyvehicles += equipmentAmount;
        if (inFileB1.eof())
            break;
    }
    return totalArmyvehicles;
}

int getArmylogisticsA(int b)
{
    ifstream inFileB1;
    string logEquipment;
    int equipmentAmount;
    int totalArmylogVehicles = 0;
    inFileB1.open(countries[b].insert(countries[b].length(), "ArmyL.txt"));

    while (true)
    {
        inFileB1 >> logEquipment >> equipmentAmount;
        if (inFileB1.fail()) break;
        totalArmylogVehicles += equipmentAmount;
        if (inFileB1.eof())
            break;
    }
    return totalArmylogVehicles;
}

int getAirForceOffenseA(int b)
{
    ifstream inFileB2;
    string milEquipment;
    int equipmentAmount;
    int totalCombatAircraft = 0;
    inFileB2.open(countries[b].insert(countries[b].length(), "AirForce.txt"));

    while (true)
    {
        inFileB2 >> milEquipment >> equipmentAmount;
        if (inFileB2.fail()) break;
        totalCombatAircraft += equipmentAmount;
        if (inFileB2.eof())
            break;
    }
    return totalCombatAircraft;
}

int getAirForceLogA(int b)
{
    ifstream inFileB2;
    string logEquipment;
    int equipmentAmount;
    int totalLogVehicle = 0;
    inFileB2.open(countries[b].insert(countries[b].length(), "AirForceL.txt"));

    while (true)
    {
        inFileB2 >> logEquipment >> equipmentAmount;
        if (inFileB2.fail()) break;
        totalLogVehicle += equipmentAmount;
        if (inFileB2.eof())
            break;
    }
    return totalLogVehicle;
}

int getNavyOffenseA(int b)
{
    ifstream inFileB3;
    string milEquipment;
    int equipmentAmount;
    int totalNavalVessels = 0;
    inFileB3.open(countries[b].insert(countries[b].length(), "Navy.txt"));

    while (true)
    {
        inFileB3 >> milEquipment >> equipmentAmount;
        if (inFileB3.fail()) break;
        totalNavalVessels += equipmentAmount;
        if (inFileB3.eof())
            break;
    }
    return totalNavalVessels;
}

int getNavyLogA(int b)
{
    ifstream inFileB3;
    string logEquipment;
    int equipmentAmount;
    int totalLogVehicles = 0;
    inFileB3.open(countries[b].insert(countries[b].length(), "NavyL.txt"));

    while (true)
    {
        inFileB3 >> logEquipment >> equipmentAmount;
        if (inFileB3.fail()) break;
        totalLogVehicles += equipmentAmount;
        if (inFileB3.eof())
            break;
    }
    return totalLogVehicles;
}

int getMarinesOffenseA(int b)
{
    ifstream inFileB4;
    string milEquipment;
    int equipmentAmount;
    int totalCombatCapability = 0;
    inFileB4.open(countries[b].insert(countries[b].length(), "Marine.txt"));

    while (true)
    {
        inFileB4 >> milEquipment >> equipmentAmount;
        if (inFileB4.fail()) break;
        totalCombatCapability += equipmentAmount;
        if (inFileB4.eof())
            break;
    }
    return totalCombatCapability;
}

int getMarinesLogA(int b)
{
    ifstream inFileB4;
    string logEquipment;
    int equipmentAmount;
    int totalLogVehicle = 0;
    inFileB4.open(countries[b].insert(countries[b].length(), "MarineL.txt"));

    while (true)
    {
        inFileB4 >> logEquipment >> equipmentAmount;
        if (inFileB4.fail()) break;
        totalLogVehicle += equipmentAmount;
        if (inFileB4.eof())
            break;
    }
    return totalLogVehicle;
}

float calcDmgTMultiplierArA(int aRlA)
{
    int identifier;
    float dmgMultiplier;

    identifier = aRlA / 500;
    if (identifier > 5)
    {
        identifier = 5;
    }
    dmgMultiplier = dmgTMultiplier[identifier];

    return dmgMultiplier;
}

float calcDmgTMultiplierAiA(int aIlA)
{
    int identifier;
    float dmgMultiplier;

    identifier = aIlA / 500;
    if (identifier > 5)
    {
        identifier = 5;
    }
    dmgMultiplier = dmgTMultiplier[identifier];

    return dmgMultiplier;
}

float calcDmgTMultiplierNA(int nLA)
{
    int identifier;
    float dmgMultiplier;

    identifier = nLA / 500;
    if (identifier > 5)
    {
        identifier = 5;
    }
    dmgMultiplier = dmgTMultiplier[identifier];

    return dmgMultiplier;
}

float calcDmgTMultiplierMA(int mLA)
{
    int identifier;
    float dmgMultiplier;

    identifier = mLA / 500;
    if (identifier > 5)
    {
        identifier = 5;
    }
    dmgMultiplier = dmgTMultiplier[identifier];

    return dmgMultiplier;
}

float calcDmgTMultiplierArB(int aRlB)
{
    int identifier;
    float dmgMultiplier;

    identifier = aRlB / 500;
    if (identifier > 5)
    {
        identifier = 5;
    }
    dmgMultiplier = dmgTMultiplier[identifier];

    return dmgMultiplier;
}

float calcDmgTMultiplierAiB(int aIlB)
{
    int identifier;
    float dmgMultiplier;

    identifier = aIlB / 500;
    if (identifier > 5)
    {
        identifier = 5;
    }
    dmgMultiplier = dmgTMultiplier[identifier];

    return dmgMultiplier;
}

float calcDmgTMultiplierNB(int nLB)
{
    int identifier;
    float dmgMultiplier;

    identifier = nLB / 500;
    if (identifier > 5)
    {
        identifier = 5;
    }
    dmgMultiplier = dmgTMultiplier[identifier];

    return dmgMultiplier;
}

float calcDmgTMultiplierMB(int mLB)
{
    int identifier;
    float dmgMultiplier;

    identifier = mLB / 500;
    if (identifier > 5)
    {
        identifier = 5;
    }
    dmgMultiplier = dmgTMultiplier[identifier];

    return dmgMultiplier;
}

int calcDmgOMultiplierArA(int aRlA)
{
    int dmgMultiplier;
    dmgMultiplier = aRlA / 500;
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

int calcdmgOMultiplierAiA(int aIlA)
{
    int dmgMultiplier;
    dmgMultiplier = aIlA / 500;
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

int calcDmgOMultiplierNA(int nLA)
{
    int dmgMultiplier;
    dmgMultiplier = nLA / 500;
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

int calcDmgOMultiplierMA(int mLA)
{
    int dmgMultiplier;
    dmgMultiplier = mLA / 500;
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

int calcDmgOMultiplierArB(int aRlB)
{
    int dmgMultiplier;
    dmgMultiplier = aRlB / 500;
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

int calcDmgOMultiplierAiB(int aIlB)
{
    int dmgMultiplier;
    dmgMultiplier = aIlB / 500;
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

int calcDmgOMultiplierNB(int nLB)
{
    int dmgMultiplier;
    dmgMultiplier = nLB / 500;
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

int calcDmgOMultiplierMB(int mLB)
{
    int dmgMultiplier;
    dmgMultiplier = mLB / 500;
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

float calcLandOccupiedB(int totalArComCapB, int finalArComCapB)
{
    float percent;
    percent = (totalArComCapB - finalArComCapB) / totalArComCapB * 100;
}

void runSim()
{
    int aRoA, aRlA, aIoA, aIlA, nOA, nLA, mOA, mLA, aRoB, aRlB, aIoB, aIlB, nOB, nLB, mOB, mLB;
    int a, b, l, totalArComCapA, totalAiComCapA, totalNComCapA, totalArComCapB, totalAiComCapB, totalNComCapB, finalArComCapA, finalAiComCapA, finalNComCapA, finalArComCapB, finalAiComCapB, finalNComCapB;
    a = getCountryA();
    b = getCountryB();
    l = getLocation();
    // Country A
    aRoA = getArmyOffenseA(a);
    aRlA = getArmylogisticsA(a);
    aIoA = getAirForceOffenseA(a);
    aIlA = getAirForceLogA(a);
    nOA = getNavyOffenseA(a);
    nLA = getNavyLogA(a);
    mOA = getMarinesOffenseA(a);
    mLA = getMarinesLogA(a);
    // Country B
    aRoB = getArmyOffenseA(b);
    aRlB = getArmylogisticsA(b);
    aIoA = getAirForceOffenseA(b);
    aIlA = getAirForceLogA(b);
    nOA = getNavyOffenseA(b);
    nLA = getNavyLogA(b);
    mOA = getMarinesOffenseA(b);
    mLA = getMarinesLogA(b);
    // Computation for troop value on both sides
    totalArComCapA = aRoA * calcDmgOMultiplierArA(aRlA) + (0.075 * aIoA) + (0.15 * nOA) + ((0.7 * mOA) * calcDmgOMultiplierMA(mLA)) * terrainOffenseAdvantage[l];
    totalAiComCapA = aIoA * calcDmgTMultiplierAiA(aIlA);
    totalNComCapA = nOA * calcDmgOMultiplierNA(nLA) + (0.075 * aIoA) + ((0.3 * mOA) * calcDmgOMultiplierMA(mLA));

    totalArComCapB = aRoB * calcDmgOMultiplierArB(aRlA) + (0.075 * aIoB) + (0.15 * nOB) + ((0.7 * mOB) * calcDmgOMultiplierMB(mLB)) * terrainDefenseAdvantage[l];
    totalAiComCapB = aIoB * calcDmgTMultiplierAiB(aIlA);
    totalNComCapB = nOB * calcDmgOMultiplierNB(nLB) + (0.075 * aIoB) + ((0.3 * mOB) * calcDmgOMultiplierMB(mLB));
    // Damage Model
    finalArComCapA = totalArComCapA - (totalArComCapA * calcDmgTMultiplierArA(aRlA));
    finalAiComCapA = totalAiComCapA - (totalAiComCapA * calcDmgTMultiplierAiA(aIlA));
    finalNComCapA = totalNComCapA - (totalNComCapA * calcDmgTMultiplierNA(nLA));

    finalArComCapB = totalArComCapB - (totalAiComCapB * calcDmgTMultiplierArB(aRlB));
    finalAiComCapB = totalAiComCapB - (totalAiComCapB * calcDmgTMultiplierAiB(aIlB));
    finalNComCapA = totalNComCapB - (totalNComCapB * calcDmgTMultiplierNB(nLB));
    // Occupation Percentage
    calcLandOccupied(totalArComCapA, finalArComCapA, totalArComCapB, finalArComCapB);
}

int main()
{
    cout << setprecision(2) << fixed << left;
    runSim();
    return 0;
}