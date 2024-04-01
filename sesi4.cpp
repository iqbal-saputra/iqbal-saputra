#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int SIZE = 10; // max size dari hash table

struct Book{
	char id[6]; // BK*** ex: BK012, BK053, BK512
	char title[51]; 
	double price;
	
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

int count = 0; // jumlah book dalam table

void insert(Book *newBook){
	
	if(count == SIZE){
		printf("The table is full!\n");
		
		return;
	} else {
		int key = hash(newBook->id);
		
		
		for(int i = 0; i < SIZE; i++){
			if(table[key] == NULL){ // jika index ke key kosong
				break; // key dijadikan index tempat menyimpan data
			} else {
				key = (key + 1) % SIZE; // cari cell kosong selanjutnya
			}
		}
		
		table[key] = newBook;
		count++;
		
	}
}

void search(char id[]){
	
	for(int i = 0; i < SIZE; i++){
		if((table[i] != NULL) && (strcmp(table[i]->id, id) == 0)){
			printf("Book with ID %s was found in index\n", table[i]->id, i);
			return;
		} 
	}
	
	printf("Book with ID %s was not found in the table!\n", id);
	
}

void del(char id[]){
	
	for(int i = 0; i < SIZE; i++){
		if((table[i] != NULL) && (strcmp(table[i]->id, id) == 0)){
			free(table[i]);
			table[i] = NULL;
			
			return;
		} 
	}
	
	printf("Book with ID %s was not found in the table!\n", id);
	
}

void print(){
	
	for(int i = 0 ; i < SIZE; i++){
		if(table[i] != NULL){
			printf("%d. \n", i);
			printf("Book ID: %s\n", table[i]->id);
			printf("Book Title: %s\n", table[i]->title);
			printf("Book Price: %.2lf\n", table[i]->price);
			printf("=================\n");
		}
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
	printf("Enter book ID to delete: ");
	scanf("%[^\n]", id);
	getchar();
	del(id);
	system("cls");
	print();	
	
	
	return 0;
}
