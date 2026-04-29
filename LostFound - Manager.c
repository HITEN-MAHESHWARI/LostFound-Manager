#include <stdio.h>
#include <string.h>

// STRUCT TO STORE ITEM DATA
struct Item{
    char name[50];   // Name of the item
    char date[20];   // Date lost/found
    char place[50];  // Place lost/found
    char contact[30]; // Contact info
};

// ARRAYS TO STORE ITEMS
struct Item lost[100];   // Array of lost items
struct Item found[100];  // Array of found items
int lostCount = 0;       // Counter for lost items
int foundCount = 0;      // Counter for found items

// SAVE LOST ITEM TO FILE
void saveLostToFile(struct Item item){
    FILE *fp = fopen("lost.txt", "a"); // Open file in append mode
    if(fp == NULL) return;             // If file can't be opened.
    fprintf(fp, "%s | %s | %s | %s\n", item.name, item.date, item.place, item.contact); // Write item
    fclose(fp);                        // Close file
}

// SAVE FOUND ITEM TO FILE
void saveFoundToFile(struct Item item){
    FILE *fp = fopen("found.txt", "a"); // Open file in append mode
    if(fp == NULL) return;              // For any error or technical issues.
    fprintf(fp, "%s | %s | %s | %s\n", item.name, item.date, item.place, item.contact); // Write item
    fclose(fp);                         // Close file
}

// ADD LOST ITEM
void addLost(){
    printf("\n--- Add Lost Item ---\n");
    printf("Item Name: ");
    scanf(" %[^\n]", lost[lostCount].name);   // Read full line with spaces
    printf("Date (dd/mm/yyyy): ");
    scanf("%s", lost[lostCount].date);        // Date input
    printf("Place Lost: ");
    scanf(" %[^\n]", lost[lostCount].place);  // Place input
    printf("Contact: ");
    scanf("%s", lost[lostCount].contact);     // Contact input

    lostCount++;                              // Increase lost count

    saveLostToFile(lost[lostCount-1]);       // Save to file

    printf("Lost item added!\n");
}

// ADD FOUND ITEM
void addFound(){
    printf("\n--- Add Found Item ---\n");
    printf("Item Name: ");
    scanf(" %[^\n]", found[foundCount].name);
    printf("Date Found: ");
    scanf("%s", found[foundCount].date);
    printf("Place Found: ");
    scanf(" %[^\n]", found[foundCount].place);
    printf("Contact: ");
    scanf("%s", found[foundCount].contact);

    foundCount++;                             // Increase found count

    saveFoundToFile(found[foundCount-1]);    // Save to file

    printf("Found item added!\n");
}

// VIEW LOST ITEMS
void viewLost(){
    int i;
    printf("\n--- Lost Items ---\n");

    if(lostCount == 0) {                     // Check if empty
        printf("No lost items.\n");
        return;
    }

    for(i = 0; i < lostCount; i++) {        // Loop through items
        printf("\nItem %d\n", i+1);
        printf("Name: %s\n", lost[i].name);
        printf("Date: %s\n", lost[i].date);
        printf("Place: %s\n", lost[i].place);
        printf("Contact: %s\n", lost[i].contact);
    }
}

// VIEW FOUND ITEMS
void viewFound(){
    int i;
    printf("\n--- Found Items ---\n");

    if(foundCount == 0) {                    // Check if empty
        printf("No found items.\n");
        return;
    }

    for(i = 0; i < foundCount; i++){       // Loop through items
        printf("\nItem %d\n", i+1);
        printf("Name: %s\n", found[i].name);
        printf("Date: %s\n", found[i].date);
        printf("Place: %s\n", found[i].place);
        printf("Contact: %s\n", found[i].contact);
    }
}

// MAIN MENU
int main(){
    int choice;

    while(1){                               // Infinite menu loop
        printf("\n====================================\n");
        printf("   LOST & FOUND MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Lost Item\n");
        printf("2. Add Found Item\n");
        printf("3. View Lost Items\n");
        printf("4. View Found Items\n");
        printf("5. Exit\n");
        printf("------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1) addLost();          // Call add lost function
        else if(choice == 2) addFound();    // Call add found function
        else if(choice == 3) viewLost();    // Call view lost
        else if(choice == 4) viewFound();   // Call view found
        else if(choice == 5) break;         // Exit program
        else if(choice == 69) printf("\nHow did you find my secret..??,anyway hi!...\n");
        else printf("Invalid choice!\n");
    }
	
	printf("\n-Made by Danish Raheem & Hiten Kalani,ThankYou.\n");
	
    return 0;                                 // End program
}
