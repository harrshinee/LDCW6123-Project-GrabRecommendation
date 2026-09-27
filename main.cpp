#include <iostream>
#include <limits>
#include <string>

using namespace std;

void displayWelcome();
int getPassengerCount();
double getDistance();
int getPriority();
int getLuggageOption();
string recommendRide(int passengerCount, double distance, int priority,
                     int luggageOption, string &reason);
void displayRecommendation(int passengerCount, double distance, int priority,
                           int luggageOption, const string &recommendedRide,
                           const string &reason);
bool askToContinue();

int main()
{
    displayWelcome();

    bool continueProgram;

    do
    {
        int passengerCount = getPassengerCount();
        if (passengerCount == 0)
        {
            return 1;
        }

        double distance = getDistance();
        if (distance == 0)
        {
            return 1;
        }

        int priority = getPriority();
        if (priority == 0)
        {
            return 1;
        }

        int luggageOption = getLuggageOption();
        if (luggageOption == 0)
        {
            return 1;
        }

        string reason;
        string recommendedRide = recommendRide(passengerCount, distance, priority,
                                               luggageOption, reason);

        displayRecommendation(passengerCount, distance, priority, luggageOption,
                              recommendedRide, reason);

        continueProgram = askToContinue();
    } while (continueProgram);

    cout << endl;
    cout << "Thank you for using the system." << endl;

    return 0;
}

void displayWelcome()
{
    cout << "========================================" << endl;
    cout << "        GRAB RIDE SELECTION SYSTEM" << endl;
    cout << "========================================" << endl;
    cout << endl;
    cout << "Welcome to the Grab Ride Selection System." << endl;
    cout << "This program will help recommend a ride option." << endl;
    cout << endl;
}

int getPassengerCount()
{
    int passengerCount;

    while (true)
    {
        cout << "Enter the number of passengers (1-6): ";
        if (cin >> passengerCount && passengerCount >= 1 && passengerCount <= 6)
        {
            return passengerCount;
        }

        if (cin.eof())
        {
            cerr << "Unable to read the passenger count." << endl;
            return 0;
        }

        cout << "Invalid input. Please enter a whole number from 1 to 6." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double getDistance()
{
    double distance;

    while (true)
    {
        cout << "Enter the travel distance in kilometres: ";
        if (cin >> distance && distance > 0)
        {
            return distance;
        }

        if (cin.eof())
        {
            cerr << "Unable to read the travel distance." << endl;
            return 0;
        }

        cout << "Invalid input. Please enter a distance greater than 0." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int getPriority()
{
    int priority;

    while (true)
    {
        cout << endl;
        cout << "Select your ride priority:" << endl;
        cout << "1. Budget" << endl;
        cout << "2. Comfort" << endl;
        cout << "3. Speed" << endl;
        cout << "Enter your choice (1-3): ";

        if (cin >> priority && priority >= 1 && priority <= 3)
        {
            return priority;
        }

        if (cin.eof())
        {
            cerr << "Unable to read the ride priority." << endl;
            return 0;
        }

        cout << "Invalid choice. Please enter a whole number from 1 to 3." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int getLuggageOption()
{
    int luggageOption;

    while (true)
    {
        cout << endl;
        cout << "Do you have luggage?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Enter your choice (1-2): ";

        if (cin >> luggageOption && luggageOption >= 1 && luggageOption <= 2)
        {
            return luggageOption;
        }

        if (cin.eof())
        {
            cerr << "Unable to read the luggage option." << endl;
            return 0;
        }

        cout << "Invalid choice. Please enter 1 for Yes or 2 for No." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string recommendRide(int passengerCount, double distance, int priority,
                     int luggageOption, string &reason)
{
    if (passengerCount >= 5)
    {
        reason = "A larger vehicle is needed for five or more passengers.";
        return "6-Seater";
    }
    else if (luggageOption == 1 && passengerCount >= 3)
    {
        reason = "A larger vehicle provides more room for the passengers and luggage.";
        return "6-Seater";
    }
    else if (passengerCount == 1 && priority == 1 && distance <= 5)
    {
        reason = "A motorcycle is suitable for one passenger taking a short budget trip.";
        return "Motorcycle Ride";
    }
    else if (priority == 2)
    {
        reason = "A premium car is recommended because comfort is the main priority.";
        return "Premium Car";
    }
    else if (passengerCount == 1 && priority == 3)
    {
        reason = "A motorcycle is suitable for one passenger who prioritises speed.";
        return "Motorcycle Ride";
    }

    reason = "A standard car is suitable for the selected trip requirements.";
    return "Standard Car";
}

void displayRecommendation(int passengerCount, double distance, int priority,
                           int luggageOption, const string &recommendedRide,
                           const string &reason)
{
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

    if (luggageOption == 1)
    {
        cout << "Luggage: Yes" << endl;
    }
    else
    {
        cout << "Luggage: No" << endl;
    }

    cout << "Recommended ride: " << recommendedRide << endl;
    cout << "Reason: " << reason << endl;
}

bool askToContinue()
{
    int choice;

    while (true)
    {
        cout << endl;
        cout << "Would you like to make another recommendation?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Enter your choice (1-2): ";

        if (cin >> choice && choice >= 1 && choice <= 2)
        {
            return choice == 1;
        }

        if (cin.eof())
        {
            return false;
        }

        cout << "Invalid choice. Please enter 1 for Yes or 2 for No." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
