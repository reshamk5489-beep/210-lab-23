#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;
    int choice;
    bool exit = false;
    list<Goat> trip;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    while (exit == false)
    {
        choice = main_menu();
        switch(choice)
        {
            case 1:
                add_goat(trip, names, colors);
                break;
            case 2:
                delete_goat(trip);
                break;
            case 3:
                display_trip(trip);
                break;
            case 4:
                exit = true;
                break;
        }
    }

    return 0;
}

int main_menu()
{
    int choice;

    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl;
    cout << "Choice -->" << endl;

    while(true)
    {
        cin >> choice;

        if (choice > 4 || choice < 1)
        {
            cout << "Please enter a valid choice (between 1-4)" << endl;
        }
        else
        {
            return choice;
        }
    }
}

void add_goat(list<Goat> &trip, string names[], string colors[])
{
    string name = names[rand() % SZ_NAMES];
    string color = colors[rand() % SZ_COLORS];
    int age = rand() % MAX_AGE;

    Goat goat(name, age, color);

    trip.push_back(goat);
}

void display_trip(list<Goat> trip)
{
    int count = 1;
    for (auto goat : trip)
    {
        cout << "\t[" << count << "] " << goat.get_name() 
            << " (" << goat.get_age() << ", " << goat.get_color() 
            << ")" << endl;
        count++;
    }
}

int select_goat(list<Goat> trip)
{
    int choice;
    display_trip(trip);

    if (trip.size() == 0)
    {
        cout << "The goat list is empty. Nothing to select." << endl;
        return 0;
    }

    while(true)
    {
        cout << "Please choose a number to select a goat: ";

        cin >> choice;

        if (choice > trip.size() || choice < 1)
        {
            cout << "Please enter a valid choice" << endl;
        }
        else
        {
            return choice;
        }
    } 
}

void delete_goat(list<Goat> &trip)
{
    int choice;
    choice = select_goat(trip);
    trip.
}
