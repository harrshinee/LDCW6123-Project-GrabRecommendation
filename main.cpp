#include <iostream>
#include <string>

using namespace std;

void displayWelcome();
int getPassengerCount();
double getDistance();
int getPriority();
char getLuggageOption();
string recommendRide(int passengerCount, double distance, int priority,
                     char luggageOption, string &reason);
void displayRecommendation(int passengerCount, double distance, int priority,
                           char luggageOption, const string &recommendedRide,
                           const string &reason);

int main()
{
    displayWelcome();

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

    char luggageOption = getLuggageOption();
    if (luggageOption == '\0')
    {
        return 1;
    }

    string reason;
    string recommendedRide = recommendRide(passengerCount, distance, priority,
                                           luggageOption, reason);

    displayRecommendation(passengerCount, distance, priority, luggageOption,
                          recommendedRide, reason);

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

    cout << "Enter the number of passengers (1-6): ";
    if (!(cin >> passengerCount))
    {
        cerr << "Unable to read the passenger count." << endl;
        return 0;
    }

    while (passengerCount < 1 || passengerCount > 6)
    {
        cout << "Invalid number of passengers. Please enter a value from 1 to 6: ";
        if (!(cin >> passengerCount))
        {
            cerr << "Unable to read the passenger count." << endl;
            return 0;
        }
    }

    return passengerCount;
}

double getDistance()
{
    double distance;

    cout << "Enter the travel distance in kilometres: ";
    if (!(cin >> distance))
    {
        cerr << "Unable to read the travel distance." << endl;
        return 0;
    }

    while (distance <= 0)
    {
        cout << "Invalid distance. Please enter a value greater than 0: ";
        if (!(cin >> distance))
        {
            cerr << "Unable to read the travel distance." << endl;
            return 0;
        }
    }

    return distance;
}

int getPriority()
{
    int priority;

    cout << endl;
    cout << "Select your ride priority:" << endl;
    cout << "1. Budget" << endl;
    cout << "2. Comfort" << endl;
    cout << "3. Speed" << endl;
    cout << "Enter your choice (1-3): ";

    if (!(cin >> priority))
    {
        cerr << "Unable to read the ride priority." << endl;
        return 0;
    }

    while (priority < 1 || priority > 3)
    {
        cout << "Invalid choice. Please enter a value from 1 to 3: ";
        if (!(cin >> priority))
        {
            cerr << "Unable to read the ride priority." << endl;
            return 0;
        }
    }

    return priority;
}

char getLuggageOption()
{
    char luggageOption;

    cout << endl;
    cout << "Do you have luggage? (Y/N): ";

    if (!(cin >> luggageOption))
    {
        cerr << "Unable to read the luggage option." << endl;
        return '\0';
    }

    while (luggageOption != 'Y' && luggageOption != 'y' &&
           luggageOption != 'N' && luggageOption != 'n')
    {
        cout << "Invalid choice. Please enter Y for Yes or N for No: ";
        if (!(cin >> luggageOption))
        {
            cerr << "Unable to read the luggage option." << endl;
            return '\0';
        }
    }

    return luggageOption;
}

string recommendRide(int passengerCount, double distance, int priority,
                     char luggageOption, string &reason)
{
    if (passengerCount >= 5)
    {
        reason = "A larger vehicle is needed for five or more passengers.";
        return "6-Seater";
    }
    else if ((luggageOption == 'Y' || luggageOption == 'y') && passengerCount >= 3)
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
                           char luggageOption, const string &recommendedRide,
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

    if (luggageOption == 'Y' || luggageOption == 'y')
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
