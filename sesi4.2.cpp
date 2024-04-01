#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int SIZE = 10; // max size dari hash table

struct Book{
	char id[6]; // BK*** ex: BK012, BK053, BK512
	char title[51]; 
	double price;
	
	Book *next;
	
} *table[SIZE];

char globalID[6];

void generateID(){
	
	globalID[0] = 'B';
	globalID[1] = 'K';
	globalID[2] = (rand() % 10) + '0';
	globalID[3] = (rand() % 10) + '0';
	globalID[4] = (rand() % 10) + '0';
	
}

Book *newBook(char title[], double price){
	
	Book *temp = (Book*)malloc(sizeof(Book) * 1);
	
	strcpy(temp->title, title);
	temp->price = price;
	
	generateID();
	strcpy(temp->id, globalID);
	
	temp->next = NULL;
	
	return temp;
}

int hash(char id[]){ // hash function
	
	int len = strlen(id);
	int sum = 0;
	
	for(int i = 0; i < len; i++){
		sum += id[i];
	}
	
	return (sum % SIZE);
}

Book *insertRec(Book *curr, Book *newBook){
	
	if(curr == NULL){ // jika ketemu slot kosong dalam linked list
		return newBook;
	} else if(strcmp(curr->id, newBook->id) == 0){ // jika ada data yang sama
		strcpy(curr->title, newBook->title); // update title
		curr->price = newBook->price; // update price
		
		return curr;
	} else {
		curr->next = insertRec(curr->next, newBook);
	}
	
}
void insert(Book *newBook){
	
	int key = hash(newBook->id);
	
	table[key] = insertRec(table[key], newBook);
	
}

Book *searchRec(Book *curr, char id[]){
	
	if(curr == NULL){
		return NULL;
	} else if(strcmp(curr->id, id) == 0){
		return curr;
	} else {
		return searchRec(curr->next, id);
	} 
	
}
void search(char id[]){
	
	int key = hash(id);
	
	Book *search = searchRec(table[key], id);
	
	if(search == NULL){
		printf("Book with ID %s was not found in the table\n", id);
	} else {
		printf("Book with ID %s wa found in index %d\n", id, key);
	}
}

Book *deleteRec(Book *curr, char id[]){
	
	if(curr == NULL){
		return NULL;
	} else if(strcmp(curr->id, id) == 0){
		Book *temp = curr->next;
		
		free(curr);
		
		return temp;
	} else {
		curr->next = deleteRec(curr->next, id);
		
		return curr;
	} 
	
}
void del(char id[]){
	
	int key = hash(id);
	
	Book *search = searchRec(table[key], id);
	
	if(search == NULL){
		printf("Book with ID %s was not found in the table\n", id);
	} else {
		table[key] = deleteRec(table[key], id);
	}
}

void print(){
	
	for(int i = 0 ; i < SIZE; i++){
		printf("%d. \n", i);
		Book *curr = table[i];
		
		int count = 1;
		while(curr != NULL){
			
			printf("Book #%d\n", count);
			printf("Book ID: %s\n", curr->id);
			printf("Book Title: %s\n", curr->title);
			printf("Book Price: %.2lf\n", curr->price);
			printf("=================\n");
			
			count++;
			
			curr = curr->next;
		}
		printf("--------------------------\n");
	}
	
}

int main(){
	
	srand(time(NULL));
	
	insert(newBook("Data Structure", 300));	
	insert(newBook("Scientific Computing", 500));	
	insert(newBook("Human and Computer Interaction", 250));
	
	print();

//	char id[6];
//	printf("Enter book ID to search: ");
//	scanf("%[^\n]", id);
//	getchar();
//	search(id);	

	char id[6];
	printf("Enter book ID to search: ");
	scanf("%[^\n]", id);
	getchar();
	del(id);
	system("cls");
	print();	
	
	
	return 0;
}
