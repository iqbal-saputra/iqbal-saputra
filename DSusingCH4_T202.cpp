#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

struct Dish {
    char id[10];
    char name[101];
    int price;
    int stock;
    struct Dish *next;
};
struct Dish *dishHead, *dishTail;

struct Order {
    char dishName[101];
    int quantity;
    int dishPrice;
    struct Order *nextOrder;
};

struct Customer {
    char name[101];
    struct Order *customerOrders;
    int orderCount;
    struct Customer *next;
};
struct Customer *customerHead, *customerTail;

struct Dish *createDish(char *id, char *name, int price, int stock) {
    struct Dish *newDish = (struct Dish*)malloc(sizeof(struct Dish));
    strcpy(newDish->id, id);
    strcpy(newDish->name, name);
    newDish->price = price;
    newDish->stock = stock;
    newDish->next = NULL;
    return newDish;
}

struct Customer *createCustomer(char *name) {
    struct Customer *newCustomer = (struct Customer *)malloc(sizeof(struct Customer));
    strcpy(newCustomer->name, name);
    newCustomer->customerOrders = NULL;
    newCustomer->orderCount = 0;
    newCustomer->next = NULL;
    return newCustomer;
}

struct Order *createOrder(char *dishName, int quantity, int dishPrice) {
    struct Order *newOrder = (struct Order *)malloc(sizeof(struct Order));
    strcpy(newOrder->dishName, dishName);
    newOrder->quantity = quantity;
    newOrder->dishPrice = dishPrice;
    newOrder->nextOrder = NULL;
    return newOrder;
}

void addOrderToCustomer(struct Customer *customer, struct Order *order) {
    if (customer->customerOrders == NULL) {
        customer->customerOrders = order;
    } else {
        struct Order *currOrder = customer->customerOrders;
        while (currOrder->nextOrder != NULL) {
            currOrder = currOrder->nextOrder;
        }
        currOrder->nextOrder = order;
    }
    customer->orderCount++;
}

void updateFile() {
    FILE *fp = fopen("dish.txt", "w");
    struct Dish *curr = dishHead;
    while(curr) {
        fprintf(fp, "%s#%d#%d\n", curr->name, curr->price, curr->stock);
        curr = curr->next;
    }
    fclose(fp);
}

void pushDishHead(char *id, char *name, int price, int stock) {
    if (dishHead == NULL) {
        dishHead = dishTail = createDish(id, name, price, stock);
    } else {
        struct Dish *newDish = createDish(id, name, price, stock);
        newDish->next = dishHead;
        dishHead = newDish;
    }
}

void deleteDish(char *id) {
    if (strcmp(dishHead->id, id) == 0) {
        struct Dish *temp = dishHead->next;
        free(dishHead);
        dishHead = temp;
        if (dishHead == NULL) {
            dishTail = NULL;
        }
    } else {
        struct Dish *curr = dishHead;
        while (curr->next && strcmp(curr->next->id, id) != 0) {
            curr = curr->next;
        }
        if (curr->next) {
            struct Dish *temp = curr->next;
            curr->next = curr->next->next;
            if (temp == dishTail) {
                dishTail = curr;
            }
            free(temp);
        }
    }
}

char *generateID(char *name) {
    char *generatedID = (char *)malloc(10 * sizeof(char));
    char firstWord[101];
    char secondWord[101];
    sscanf(name, "%s %[^\n]", firstWord, secondWord);
    int randNum = rand() % 1000;
    sprintf(generatedID, "%c%c%03d", firstWord[0], secondWord[0], randNum);
    return generatedID;
}

void readFile() {
    FILE *fp = fopen("dish.txt", "r");
    while(!feof(fp)) {
        char newID[10];
        char newName[101];
        int newPrice;
        int newStock;
        fscanf(fp, "%[^#]#%d#%d\n", newName, &newPrice, &newStock);
        strcpy(newID, generateID(newName));
        pushDishHead(newID, newName, newPrice, newStock);
    }
    fclose(fp);
}

bool searchDish(char *id) {
    struct Dish *curr = dishHead;
    while (curr) {
        if (strcmp(curr->id, id) == 0) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

int searchDishQuantity(char *name) {
    struct Dish *curr = dishHead;
    while (curr) {
        if (strcmp(curr->name, name) == 0) {
            return curr->stock;
        }
        curr = curr->next;
    }
    return -1;
}

int searchDishPrice(char *name) {
    struct Dish *curr = dishHead;
    while (curr) {
        if (strcmp(curr->name, name) == 0) {
            return curr->price;
        }
        curr = curr->next;
    }
    return -1;
}

void updateDish(char *id, int newStock) {
    struct Dish *curr = dishHead;
    while (curr) {
        if (strcmp(curr->id, id) == 0) {
            curr->stock = newStock;
            return;
        }
        curr = curr->next;
    }
}

void decreaseDishStock(char *name, int reduction) {
    struct Dish *curr = dishHead;
    while (curr) {
        if (strcmp(curr->name, name) == 0) {
            curr->stock -= reduction;
            return;
        }
        curr = curr->next;
    }
}

struct Customer *getCustomerByName(const char *targetName) {
    struct Customer *curr = customerHead;
    while (curr) {
        if (strcmp(curr->name, targetName) == 0) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

int countDishes() {
    int count = 0;
    struct Dish *curr = dishHead;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

void viewDish() {
    struct Dish *curr = dishHead;
    printf("%-20s %-20s %-10s %-10s\n", "ID", "Name", "Price", "Stock");
    while(curr) {
        printf("%-20s %-20s %-10d %-10d\n", curr->id, curr->name, curr->price, curr->stock);
        curr = curr->next;
    }
}

void pushCustomer(char *name) {
    struct Customer *newCustomer = createCustomer(name);
    if (customerHead == NULL) {
        customerHead = customerTail = newCustomer;
    } else if (strcmp(name, customerHead->name) <= 0) {
        newCustomer->next = customerHead;
        customerHead = newCustomer;
    } else {
        struct Customer *prev = customerHead;
        struct Customer *curr = customerHead->next;
        while (curr && strcmp(name, curr->name) > 0) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = newCustomer;
        newCustomer->next = curr;
        if (curr == NULL) {
            customerTail = newCustomer;
        }
    }
}

void deleteCustomer(char *name) {
    struct Customer *curr = customerHead;
    struct Customer *prev = NULL;
    while (curr != NULL && strcmp(curr->name, name) != 0) {
        prev = curr;
        curr = curr->next;
    }
    struct Order *order = curr->customerOrders;
    while (order != NULL) {
        struct Order *temp = order;
        order = order->nextOrder;
        free(temp);
    }
    if (prev == NULL) {
        customerHead = curr->next;
    } else {
        prev->next = curr->next;
    }
    if (curr == customerTail) {
        customerTail = prev;
    }
}

struct Customer *searchCustomer(char *targetName) {
    struct Customer *curr = customerHead;
    while(curr) {
        if(strcmp(curr->name, targetName) == 0) {
            return curr;
        } 
        curr = curr->next;
    }
    return NULL;
}

void viewCustomer() {
    struct Customer *curr = customerHead;
    printf("%-20s\n","Name");
    while(curr) {
        printf("%-20s\n", curr->name);
        curr = curr->next;
    }
}

void viewCustomerOrder(struct Customer *customer) {
    printf("Customer: %s\n", customer->name);
    printf("%-20s %-10s %-10s\n", "Dish Name", "Quantity", "Price");
    struct Order *currOrder = customer->customerOrders;
    while (currOrder != NULL) {
        printf("%-20s %-10d %-10d\n", currOrder->dishName, currOrder->quantity, currOrder->dishPrice);
        currOrder = currOrder->nextOrder;
    }
}

int calculateTotalPrice(struct Customer *customer) {
    int totalPrice = 0;
    struct Order *currOrder = customer->customerOrders;
    while (currOrder != NULL) {
        totalPrice += currOrder->dishPrice;
        currOrder = currOrder->nextOrder;
    }
    return totalPrice;
}

void mainMenu() {
    system("cls");
    puts("1. Insert New Dish");
    puts("2. Update Dish");
    puts("3. Delete Dish");
    puts("4. Add Customer");
    puts("5. Customer List");
    puts("6. Order");
    puts("7. Payment");
    puts("8. Exit");
    printf(">> ");
}

int main()
{
    srand(time(NULL));
    readFile();
    int choice = 0;
    do {
        choice = 0;
        do {
            mainMenu();
            scanf("%d", &choice);
            getchar();
        } while(choice < 0 || choice > 8);
        if(choice == 1) {
            char newID[10];
            char newName[101];
            int newPrice;
            int newStock;
            bool validName = false;
            do {
                validName = false;
                printf("Enter Name: ");
                scanf("%[^\n]s", newName);
                getchar();
                char firstWord[101];
                char secondWord[101];
                sscanf(newName, "%s %[^\n]", firstWord, secondWord);
                if(firstWord[0] > 64 && firstWord[0] < 91 && secondWord[0] > 64 && secondWord[0] < 91) {
                    validName = true;
                }
            } while(!validName);
            do {
                printf("Enter price: ");
                scanf("%d", &newPrice);
                getchar();
            } while(newPrice < 10000 || newPrice > 100000);
            do {
                printf("Enter stock: ");
                scanf("%d", &newStock);
                getchar();
            } while(newStock < 1 || newStock > 999);
            strcpy(newID, generateID(newName));
            pushDishHead(newID, newName, newPrice, newStock);
            updateFile();
        } else if(choice == 2) {
            if(!dishHead) {
                printf("List is empty!\n\nPress enter to continue...");
                getchar();
            } else {
                char idToSearch[10];
                system("cls");
                viewDish();
                printf("Enter ID: ");
                scanf("%s", idToSearch);
                getchar();
                if(!searchDish(idToSearch)) {
                    printf("ID Not found!\n\nPress enter to continue...");
                    getchar();
                } else {
                    int newStock = 0;
                    do {
                        printf("Enter stock: ");
                        scanf("%d", &newStock);
                        getchar();
                    } while(newStock < 1 || newStock > 999);
                    updateDish(idToSearch, newStock);
                    updateFile();
                    printf("Updated!\n\nPress enter to continue...");
                    getchar();
                }
            }
        } else if(choice == 3) {
            if(!dishHead) {
                printf("List is empty!\n\nPress enter to continue...");
                getchar();
            } else {
                char idToSearch[10];
                system("cls");
                viewDish();
                printf("Enter ID: ");
                scanf("%s", idToSearch);
                getchar();
                deleteDish(idToSearch);
                updateFile();
                printf("Deleted!\n\nPress enter to continue...");
                getchar();
            }
        } else if(choice == 4) {
            char newName[101];
            bool validName = true;
            do {
                printf("Enter name: ");
                scanf("%s", newName);
                getchar();
                for(int i=0; i<strlen(newName); i++) {
                    if(!isalpha(newName[i]) && newName[i] != ' ') {
                        validName = false;
                    }
                }
            } while(!validName);
            pushCustomer(newName);
            printf("Insert success!\nPress enter to continue...");
            getchar();
        } else if(choice == 5) {
            if(!customerHead) {
                printf("No Customers!\nPress enter to continue...");
                getchar();
            } else {
                system("cls");
                viewCustomer();
                printf("\nPress enter to continue...");
                getchar();
            }
        } else if(choice == 6) {
            if(!dishHead) {
                printf("No Dishes!\nPress enter to continue...");
                getchar();
            } else if(!customerHead){
                printf("No Customers!\nPress enter to continue...");
                getchar();
            } else {
                system("cls");
                viewDish();
                char targetCustomer[101];
                int dishQuantity = 0;
                do {
                    printf("\nEnter Customer Name: ");
                    scanf("%s", targetCustomer);
                    getchar();
                } while(!searchCustomer(targetCustomer));
                do {
                    printf("Enter dish quantity: ");
                    scanf("%d", &dishQuantity);
                    getchar();
                } while(dishQuantity == 0 || dishQuantity > countDishes());
                for(int i=0; i<dishQuantity; i++) {
                    struct Order newOrder;
                    bool validOrder = false;
                    char tempDishName[101] = {};
                    int delimeterIndex = -1;
                    do {
                        char fullString[101];
                        validOrder = false;
                        printf("Input Dish No. %d: ", i);
                        scanf("%[^\n]", fullString);
                        getchar();
                        if (sscanf(fullString, "%100[^-] - %d", tempDishName, &newOrder.quantity) == 2) {
                            validOrder = true;
                        }
                    } while(!validOrder);
                    for(int i=0; i<strlen(tempDishName)-1; i++) {
                        newOrder.dishName[i] = tempDishName[i];
                    }
                    for(int i=0; i<101; i++) {
                        if(newOrder.dishName[i] != ' ' && !isalpha(newOrder.dishName[i])) {
                            newOrder.dishName[i] = '\0';
                        }
                    }
                    newOrder.dishPrice = searchDishPrice(newOrder.dishName) * newOrder.quantity;
                    printf("%s %d %d\n", newOrder.dishName, newOrder.quantity, newOrder.dishPrice);
                    addOrderToCustomer(searchCustomer(targetCustomer), createOrder(newOrder.dishName, newOrder.quantity, newOrder.dishPrice));
                    decreaseDishStock(newOrder.dishName, newOrder.quantity);
                }
                updateFile();
                printf("Order Added!\nPress enter to continue...");
                getchar();
            }
        } else if(choice == 7) {
            if(!customerHead) {
                printf("No Customers\nPress enter to continue...");
                getchar();
            } else {
                char targetCustomer[101];
                do {
                    printf("Enter Customer Name: ");
                    scanf("%s", targetCustomer);
                    getchar();
                } while(!searchCustomer(targetCustomer));
                system("cls");
                viewCustomerOrder(getCustomerByName(targetCustomer));
                printf("Total Price: %d\n", calculateTotalPrice(getCustomerByName(targetCustomer)));
                deleteCustomer(targetCustomer);
                printf("Order Completed!\nPress enter to continue...");
                getchar();
            }
        }
    } while(choice != 8);
    updateFile();
    printf("Thank you for using!");

    return 0;
}