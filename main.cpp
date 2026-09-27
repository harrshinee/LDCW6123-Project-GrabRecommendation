#include <iostream>

using namespace std;

int main()
{
    int passengerCount;
    double distance;

    cout << "========================================" << endl;
    cout << "        GRAB RIDE SELECTION SYSTEM" << endl;
    cout << "========================================" << endl;
    cout << endl;
    cout << "Welcome to the Grab Ride Selection System." << endl;
    cout << "This program will help recommend a ride option." << endl;
    cout << endl;

    cout << "Enter the number of passengers (1-6): ";
    if (!(cin >> passengerCount))
    {
        cerr << "Unable to read the passenger count." << endl;
        return 1;
    }

    while (passengerCount < 1 || passengerCount > 6)
    {
        cout << "Invalid number of passengers. Please enter a value from 1 to 6: ";
        if (!(cin >> passengerCount))
        {
            cerr << "Unable to read the passenger count." << endl;
            return 1;
        }
    }

    cout << "Enter the travel distance in kilometres: ";
    if (!(cin >> distance))
    {
        cerr << "Unable to read the travel distance." << endl;
        return 1;
    }

    while (distance <= 0)
    {
        cout << "Invalid distance. Please enter a value greater than 0: ";
        if (!(cin >> distance))
        {
            cerr << "Unable to read the travel distance." << endl;
            return 1;
        }
    }

    cout << endl;
    cout << "Passenger count: " << passengerCount << endl;
    cout << "Travel distance: " << distance << " km" << endl;
    cout << endl;
    cout << "Thank you for using the system." << endl;

    return 0;
}
