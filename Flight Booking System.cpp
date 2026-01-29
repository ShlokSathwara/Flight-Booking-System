#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

int main() {
    cout << "WELCOME TO MAKE.YOUR.TRIP\n\n";

    string EMAIL, Password, CONTACT_NO, FIRST_NAME, LAST_NAME;
    int choice;

    cout << "LOG IN / SIGN UP\n";
    cout << "1 = LOG IN \n2 = SIGN UP\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter your email address: ";
        cin >> EMAIL;
        cout << "Enter your password: ";
        cin >> Password;
        cout << "\nSUCCESSFUL LOG IN\n";
    } else if (choice == 2) {
        cout << "Enter your first name: ";
        cin >> FIRST_NAME;
        cout << "Enter your last name: ";
        cin >> LAST_NAME;
        cout << "Enter your contact number: ";
        cin >> CONTACT_NO;
        cout << "Enter your email address: ";
        cin >> EMAIL;
        cout << "Enter your password: ";
        cin >> Password;
        cout << "SUCCESSFUL SIGN UP COMPLETE.\n";
    }

    string From, To, Benefits;
    int Date, Date_return, Travellers, KIDS, INFANTS;
    int trip;

    cout << "\nChoose Trip Type:\n1 = One way trip\n2 = Round trip\n";
    cout << "Enter your choice: ";
    cin >> trip;

    cout << "FROM: ";
    cin >> From;

    cout << "TO: ";
    cin >> To;

    cout << "Departure Date (YYYYMMDD): ";
    cin >> Date;

    if (trip == 2) {
        cout << "Return Date (YYYYMMDD): ";
        cin >> Date_return;
    }

    cout << "Number of adult travellers: ";
    cin >> Travellers;

    cout << "Number of kids: ";
    cin >> KIDS;

    cout << "Number of infants: ";
    cin >> INFANTS;

    int classChoice;
    cout << "\nChoose Class:\n1. Economy\n2. Premium Economy\n3. Business\n4. First Class\n";
    cin >> classChoice;

    cout << "\nMore Benefits:\n1. Student\n2. Senior Citizen / Armed Forces / Doctors\n0. None\n";
    cin.ignore();
    getline(cin, Benefits);

    int airline, decision;
repeat:
    cout << "\nChoose Airline:\n1. Indigo\n2. Air India\n";
    cin >> airline;

    cout << "\nFlight Time Options:\n";
    cout << "1. Before 7:00 AM\n2. Before 12:00 PM\n3. Before 4:00 PM\n";
    cout << "4. Before 9:00 PM\n5. Before 11:00 PM\n6. Before 2:00 AM\n";

    cout << "\nWant to change airline? (1 = No, 2 = Yes): ";
    cin >> decision;

    if (decision == 2) {
        goto repeat;
    }

    int TiMe;
    cout << "Enter your time slot (1-6): ";
    cin >> TiMe;

    int cost;
    if (airline == 1) { // Indigo
        int indigo_costs[6] = {2324, 2568, 2978, 2680, 3597, 1996};
        cost = indigo_costs[TiMe - 1];
    } else { // Air India
        int airindia_costs[6] = {2394, 2868, 2948, 2660, 3097, 1296};
        cost = airindia_costs[TiMe - 1];
    }

    double total_cost = (Travellers * cost)
                      + (KIDS * 0.9 * cost)
                      + (INFANTS * 0.4 * cost);

    cout << "\n===== FINAL BOOKING DETAILS =====\n";
    cout << "From: " << From << endl;
    cout << "To: " << To << endl;
    cout << "Adults: " << Travellers << "\nKids: " << KIDS << "\nInfants: " << INFANTS << endl;
    cout << "Selected Airline: " << (