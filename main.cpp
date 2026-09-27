#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Function declarations
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
    // Display the system title and introduction
    displayWelcome();

    bool continueProgram;

    // Repeat the ride selection process until the user chooses to stop
    do
    {
        cout << "----------------------------------------" << endl;
        cout << "              TRIP DETAILS" << endl;
        cout << "----------------------------------------" << endl;

        // Collect and validate trip information from the user
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

        // Process the inputs and determine the recommended ride
        string reason;
        string recommendedRide = recommendRide(passengerCount, distance, priority,
                                               luggageOption, reason);

         // Display the user's trip details and final recommendation
        displayRecommendation(passengerCount, distance, priority, luggageOption,
                              recommendedRide, reason);

        continueProgram = askToContinue();
    } while (continueProgram);

    cout << endl;
    cout << "Thank you for using the system." << endl;

    return 0;
}
// Displays the program title, purpose and simulation disclaimer
void displayWelcome()
{
    cout << "========================================" << endl;
    cout << "        GRAB RIDE SELECTION SYSTEM" << endl;
    cout << "========================================" << endl;
    cout << endl;
    cout << "Welcome to the Grab Ride Selection System." << endl;
    cout << "This program will help recommend a ride option." << endl;
    cout << "Educational simulation only; this is not Grab's actual algorithm." << endl;
    cout << endl;
}

// Gets the number of passengers and ensures the value is between 1 and 6
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
 
        // Stop the program safely if the input stream cannot be read
        if (cin.eof())
        {
            cerr << "Unable to read the passenger count." << endl;
            return 0;
        }

        // Clear invalid input so the user can try again
        cout << "Invalid input. Please enter a whole number from 1 to 6." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Gets the travel distance and ensures that it is greater than zero
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

        // Clear invalid input before requesting the distance again
        cout << "Invalid input. Please enter a distance greater than 0." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Displays the priority menu and validates the user's selection
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

// Asks whether the passenger has luggage and validates the selection
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

// Applies the ride-selection rules using passenger count, luggage,
// priority and distance. The rules are checked in order of importance.
string recommendRide(int passengerCount, double distance, int priority,
                     int luggageOption, string &reason)
{
    // Five or more passengers require the larger 6-seater
    if (passengerCount >= 5)
    {
        reason = "A larger vehicle is needed for five or more passengers.";
        return "6-Seater";
    }
     // Three or more passengers with luggage need additional space
    else if (luggageOption == 1 && passengerCount >= 3)
    {
        reason = "A larger vehicle provides more room for the passengers and luggage.";
        return "6-Seater";
    }

    // A motorcycle is recommended for a single passenger taking
    // a short trip when budget is the main priority
    else if (passengerCount == 1 && priority == 1 && distance <= 5)
    {
        reason = "A motorcycle is suitable for one passenger taking a short budget trip.";
        return "Motorcycle Ride";
    }
    // Comfort takes priority when vehicle capacity is not an issue
    else if (priority == 2)
    {
        reason = "A premium car is recommended because comfort is the main priority.";
        return "Premium Car";
    }

    // A motorcycle is recommended to a single passenger prioritising speed
    else if (passengerCount == 1 && priority == 3)
    {
        reason = "A motorcycle is suitable for one passenger who prioritises speed.";
        return "Motorcycle Ride";
    }

      // Standard Car acts as the default recommendation
    reason = "A standard car is suitable for the selected trip requirements.";
    return "Standard Car";
}

// Displays the trip information and recommendation in a formatted summary
void displayRecommendation(int passengerCount, double distance, int priority,
                           int luggageOption, const string &recommendedRide,
                           const string &reason)
{
    string priorityName;

     // Convert the numeric priority into text for easier understanding
    switch (priority)
    {
    case 1:
        priorityName = "Budget";
        break;
    case 2:
        priorityName = "Comfort";
        break;
    case 3:
        priorityName = "Speed";
        break;
    }

    cout << endl;
    cout << "========================================" << endl;
    cout << "           RIDE RECOMMENDATION" << endl;
    cout << "========================================" << endl;
    cout << endl;
    cout << left << setw(18) << "Passengers" << ": " << passengerCount << endl;
    cout << left << setw(18) << "Distance" << ": " << fixed << setprecision(1)
         << distance << " km" << endl;
    cout << left << setw(18) << "Priority" << ": " << priorityName << endl;
    cout << left << setw(18) << "Luggage" << ": "
         << (luggageOption == 1 ? "Yes" : "No") << endl;
    cout << endl;
    cout << left << setw(18) << "Recommended Ride" << ": " << recommendedRide << endl;
    cout << endl;
    cout << "Reason:" << endl;
    cout << reason << endl;
    cout << endl;
    cout << "========================================" << endl;
}

// Asks whether the user wants another recommendation.
// Returns true to repeat the program and false to exit.
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
