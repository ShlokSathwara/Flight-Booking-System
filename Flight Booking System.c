#include <stdio.h>
#include <unistd.h> 

int main() {
    printf("WELCOME TO MAKE.YOUR.TRIP\n\n");

    char EMAIL[50], Password[50], CONTACT_NO[15], FIRST_NAME[50], LAST_NAME[50];
    int choice;

    printf("LOG IN / SIGN UP\n");
    printf("1 = LOG IN \n2 = SIGN UP\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter your email address: ");
        scanf("%s", EMAIL);
        printf("Enter your password: ");
        scanf("%s", Password);
        printf("\nSUCCESSFUL LOG IN\n");
    } else if (choice == 2) {
        printf("Enter your first name: ");
        scanf("%s", FIRST_NAME);
        printf("Enter your last name: ");
        scanf("%s", LAST_NAME);
        printf("Enter your contact number: ");
        scanf("%s", CONTACT_NO);
        printf("Enter your email address: ");
        scanf("%s", EMAIL);
        printf("Enter your password: ");
        scanf("%s", Password);
        printf("SUCCESSFUL SIGN UP COMPLETE.\n");
    }

    char From[100], To[100], Benefits[100];
    int Date, Date_return, Travellers, KIDS, INFANTS;
    int trip;

    printf("\nChoose Trip Type:\n1 = One way trip\n2 = Round trip\n");
    printf("Enter your choice: ");
    scanf("%d", &trip);

    printf("FROM: ");
    scanf("%s", From);

    printf("TO: ");
    scanf("%s", To);

    printf("Departure Date (YYYYMMDD): ");
    scanf("%d", &Date);

    if (trip == 2) {
        printf("Return Date (YYYYMMDD): ");
        scanf("%d", &Date_return);
    }

    printf("Number of adult travellers: ");
    scanf("%d", &Travellers);

    printf("Number of kids: ");
    scanf("%d", &KIDS);

    printf("Number of infants: ");
    scanf("%d", &INFANTS);

    int classChoice;
    printf("\nChoose Class:\n1. Economy\n2. Premium Economy\n3. Business\n4. First Class\n");
    scanf("%d", &classChoice);

    printf("\nMore Benefits:\n1. Student\n2. Senior Citizen / Armed Forces / Doctors\n0. None\n");
    scanf(" %[^\n]", Benefits);

    int airline, decision;

repeat:
    printf("\nChoose Airline:\n1. Indigo\n2. Air India\n");
    scanf("%d", &airline);

    printf("\nFlight Time Options:\n");
    printf("1. Before 7:00 AM\n2. Before 12:00 PM\n3. Before 4:00 PM\n");
    printf("4. Before 9:00 PM\n5. Before 11:00 PM\n6. Before 2:00 AM\n");

    printf("\nWant to change airline? (1 = No, 2 = Yes): ");
    scanf("%d", &decision);

    if (decision == 2) {
        goto repeat;
    }

    int TiMe;
    printf("Enter your time slot (1-6): ");
    scanf("%d", &TiMe);

    int cost;

    if (airline == 1) {  // Indigo
        int indigo_costs[6] = {2324, 2568, 2978, 2680, 3597, 1996};
        cost = indigo_costs[TiMe - 1];
    } else {             // Air India
        int airindia_costs[6] = {2394, 2868, 2948, 2660, 3097, 1296};
        cost = airindia_costs[TiMe - 1];
    }

    float total_cost = (Travellers * cost) 
                     + (KIDS * 0.9 * cost)       // 10% discount for kids
                     + (INFANTS * 0.4 * cost);   // 60% discount for infants

    printf("\n===== FINAL BOOKING DETAILS =====\n");
    printf("From: %s\n", From);
    printf("To: %s\n", To);
    printf("Adults: %d\nKids: %d\nInfants: %d\n", Travellers, KIDS, INFANTS);
    printf("Selected Airline: %s\n", (airline == 1) ? "Indigo" : "Air India");
    printf("Total Cost: %.2f\n", total_cost);

    printf("\nLOADING, PLEASE WAIT...\n");
    for (int t = 1; t <= 3; t++) {
        printf("%d\n", t);
        sleep(1);
    }

    printf("\nFlight successfully booked!\nEnjoy your trip!\n");

    return 0;
}
