import java.util.Scanner;

public class MakeYourTrip {
    public static void main(String[] args) throws InterruptedException {
        Scanner sc = new Scanner(System.in);

        System.out.println("WELCOME TO MAKE.YOUR.TRIP\n");

        String EMAIL, Password, CONTACT_NO, FIRST_NAME, LAST_NAME;
        int choice;

        System.out.println("LOG IN / SIGN UP");
        System.out.println("1 = LOG IN \n2 = SIGN UP");
        System.out.print("Enter your choice: ");
        choice = sc.nextInt();
        sc.nextLine(); // consume newline

        if (choice == 1) {
            System.out.print("Enter your email address: ");
            EMAIL = sc.nextLine();
            System.out.print("Enter your password: ");
            Password = sc.nextLine();
            System.out.println("\nSUCCESSFUL LOG IN\n");
        } else if (choice == 2) {
            System.out.print("Enter your first name: ");
            FIRST_NAME = sc.nextLine();
            System.out.print("Enter your last name: ");
            LAST_NAME = sc.nextLine();
            System.out.print("Enter your contact number: ");
            CONTACT_NO = sc.nextLine();
            System.out.print("Enter your email address: ");
            EMAIL = sc.nextLine();
            System.out.print("Enter your password: ");
            Password = sc.nextLine();
            System.out.println("SUCCESSFUL SIGN UP COMPLETE.\n");
        }

        String From, To, Benefits;
        int Date, Date_return = 0, Travellers, KIDS, INFANTS;
        int trip;

        System.out.println("\nChoose Trip Type:\n1 = One way trip\n2 = Round trip");
        System.out.print("Enter your choice: ");
        trip = sc.nextInt();
        sc.nextLine();

        System.out.print("FROM: ");
        From = sc.nextLine();

        System.out.print("TO: ");
        To = sc.nextLine();

        System.out.print("Departure Date (YYYYMMDD): ");
        Date = sc.nextInt();

        if (trip == 2) {
            System.out.print("Return Date (YYYYMMDD): ");
            Date_return = sc.nextInt();
        }

        System.out.print("Number of adult travellers: ");
        Travellers = sc.nextInt();

        System.out.print("Number of kids: ");
        KIDS = sc.nextInt();

        System.out.print("Number of infants: ");
        INFANTS = sc.nextInt();

        System.out.println("\nChoose Class:\n1. Economy\n2. Premium Economy\n3. Business\n4. First Class");
        int classChoice = sc.nextInt();
        sc.nextLine();

        System.out.println("\nMore Benefits:\n1. Student\n2. Senior Citizen / Armed Forces / Doctors\n0. None");
        Benefits = sc.nextLine();

        int airline, decision;
        do {
            System.out.println("\nChoose Airline:\n1. Indigo\n2. Air India");
            airline = sc.nextInt();

            System.out.println("\nFlight Time Options:");
            System.out.println("1. Before 7:00 AM\n2. Before 12:00 PM\n3. Before 4:00 PM");
            System.out.println("4. Before 9:00 PM\n5. Before 11:00 PM\n6. Before 2:00 AM");

            System.out.print("\nWant to change airline? (1 = No, 2 = Yes): ");
            decision = sc.nextInt();
        } while (decision == 2);

        System.out.print("Enter your time slot (1-6): ");
        int TiMe = sc.nextInt();

        int cost;
        if (airline == 1) { // Indigo
            int[] indigo_costs = {2324, 2568, 2978, 2680, 3597, 1996};
            cost = indigo_costs[TiMe - 1];
        } else { // Air India
            int[] airindia_costs = {2394, 2868, 2948, 2660, 3097, 1296};
            cost = airindia_costs[TiMe - 1];
        }

        double total_cost = (Travellers * cost)
                          + (KIDS * 0.9 * cost)
                          + (INFANTS * 0.4 * cost);

        System.out.println("\n===== FINAL BOOKING DETAILS =====");
        System.out.println("From: " + From);
        System.out.println("To: " + To);
        System.out.println("Adults: " + Travellers + "\nKids: " + KIDS + "\nInfants: " + INFANTS);
        System.out.println("Selected Airline: " + (airline == 1 ? "Indigo" : "Air India"));
        System.out.printf("Total Cost: %.2f\n", total_cost);

        System.out.println("\nLOADING, PLEASE WAIT...");
        for (int t = 1; t <= 3; t++) {
            System.out.println(t);
            Thread.sleep(1000);
        }

        System.out.println("\nFlight successfully booked!\nEnjoy your trip!");
        sc.close();
    }
}