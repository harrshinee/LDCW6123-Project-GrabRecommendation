#include <iostream>

using namespace std;

int main()
{
    int passengerCount;
    double distance;
    int priority;
    char luggageOption;

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
    cout << "Select your ride priority:" << endl;
    cout << "1. Budget" << endl;
    cout << "2. Comfort" << endl;
    cout << "3. Speed" << endl;
    cout << "Enter your choice (1-3): ";

    if (!(cin >> priority))
    {
        cerr << "Unable to read the ride priority." << endl;
        return 1;
    }

    while (priority < 1 || priority > 3)
    {
        cout << "Invalid choice. Please enter a value from 1 to 3: ";
        if (!(cin >> priority))
        {
            cerr << "Unable to read the ride priority." << endl;
            return 1;
        }
    }

    cout << endl;
    cout << "Do you have luggage? (Y/N): ";

    if (!(cin >> luggageOption))
    {
        cerr << "Unable to read the luggage option." << endl;
        return 1;
    }

    while (luggageOption != 'Y' && luggageOption != 'y' &&
           luggageOption != 'N' && luggageOption != 'n')
    {
        cout << "Invalid choice. Please enter Y for Yes or N for No: ";
        if (!(cin >> luggageOption))
        {
            cerr << "Unable to read the luggage option." << endl;
            return 1;
        }
    }

    cout << endl;
    cout << "Passenger count: " << passengerCount << endl;
    cout << "Travel distance: " << distance << " km" << endl;
    cout << "Ride priority: ";

    switch (priority)
    {
    case 1:
        cout << "Budget" << endl;
        break;
    case 2:
        cout << "Comfort" << endl;
        break;
    case 3:
        cout << "Speed" << endl;
        break;
    }

    if (luggageOption == 'Y' || luggageOption == 'y')
    {
        cout << "Luggage: Yes" << endl;
    }
    else
    {
        cout << "Luggage: No" << endl;
    }

    cout << endl;
    cout << "Thank you for using the system." << endl;

    return 0;
}
