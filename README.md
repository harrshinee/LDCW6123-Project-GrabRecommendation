# Grab Ride Selection System

This console-based C++ program demonstrates how a simple ride-hailing system can
recommend a ride category based on a user's trip requirements.

The program asks for:

- Number of passengers
- Travel distance in kilometres
- Main priority: Budget, Comfort, or Speed
- Whether the user has luggage

It recommends one of four demo ride categories: Motorcycle Ride, Standard Car,
Premium Car, or 6-Seater. The result also includes a short reason for the
recommendation.

## Compile and Run

Using the Visual Studio Developer Command Prompt:

```powershell
cl /EHsc main.cpp /Fe:grab_system.exe
.\grab_system.exe
```

Alternatively, using `g++` on Windows:

```powershell
g++ main.cpp -o grab_system
.\grab_system.exe
```

This program is an educational simulation and does not represent Grab's actual
ride recommendation algorithm.
