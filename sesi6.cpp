#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define SIZE 1007

struct Book{
	
	char id[101];
	char title[101];
	char author[101];
	char isbn[101];
	int pageNumber; 
	
	Book *next;
	
} *table[SIZE];

char globalID[101];
char globalTitle[101];
char globalAuthor[101];
char globalISBN[101];
int globalPageNumber;
int count = 0;

void generateISBN(){
	
	globalISBN[0] = '9';
	globalISBN[1] = '7';
	globalISBN[2] = '8';
	globalISBN[3] = '0';
	
	for(int i = 4; i < 13; i++){
		globalISBN[i] = rand() % 10 + '0';
	}
	
}

void generateID(){
	
	srand(time(NULL));
	count++;
	int x = count;
	
	char isbn[101];
	strcpy(isbn, globalISBN);
	
	
	if((globalAuthor[0] >= 'a') && (globalAuthor[0]) <= 'z'){
		globalAuthor[0] -= ('a' - 'A');
	}
	char a = globalAuthor[0];
	
	if((globalTitle[0] >= 'a') && (globalTitle[0]) <= 'z'){
		globalTitle[0] -= ('a' - 'A');
	}
	char t = globalTitle[0];
	
	sprintf(globalID, "B%05d-%s-%c%c", x, isbn, a, t);
}

Book *newBook(char title[], char author[], char isbn[], int pageNumber){
	
	Book *temp = (Book*)malloc(sizeof(Book) * 1);
//	generateISBN();
	strcpy(globalISBN, isbn);
	strcpy(globalAuthor, author);
	strcpy(globalTitle, title);
//	strcpy(globalISBN, isbn);
	generateID();
	strcpy(temp->id, globalID);
	strcpy(temp->title, title);
	strcpy(temp->author, author);
	strcpy(temp->isbn, isbn);
	temp->pageNumber = pageNumber;
	
	temp->next = NULL;
	
	return temp;
}

int hash(char id[]){
	
	int key;
	int sum = 0;
	int len = strlen(id);
	for(int i = 0; i < len; i++){
		key += id[i];
	}
	
	key = sum % SIZE;
	return key;
	
}

Book *insertRec(Book *curr, Book *newBook){
	
	 if(curr == NULL){
	 	return newBook;
	 } else if(strcmp(curr->id, newBook->id) == 0){
	 	return NULL;
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

Book *delRec(Book *curr, char id[]){
	
	if(strcmp(curr->id, id) == 0){
		Book *temp = curr->next;
		free(curr);
//		printf("Delete success!\n");
		return temp;
	} else {
		curr->next = delRec(curr->next, id);
	}
	
}

int del(char id[]){
	
	int key = hash(id);
	
	if(searchRec(table[key], id) == NULL){
		return -1;
	} else {
		table[key] = delRec(table[key], id);
	}
	
}

void print(){
	
	if(count == 0){
		printf("There is no book(s) !\n\n");
		
		printf("Press enter to continue ...");
		getch();
	} else {
		printf("------------------------------------------------------------------------------------------------------------------\n");
		printf("| Book ID\t\t  | Book Title\t\t\t | Book Author\t | ISBN\t\t\t | Page Number\t |\n");
		printf("------------------------------------------------------------------------------------------------------------------\n");
		for(int i = 0; i < SIZE; i++){
			Book *curr = table[i];
			
			while(curr != NULL){
				printf("| %s | %s\t\t | %s\t | %s\t | %7d\t |\n", curr->id, curr->title, curr->author, curr->isbn, curr->pageNumber);
				printf("------------------------------------------------------------------------------------------------------------------\n");
				
				curr = curr->next;
			}
		}
	}
}
void displayMenu(){
	
	printf("\nAlgodemy Library\n");
	printf("=================\n");
	printf("1. View Book\n");
	printf("2. Insert Book\n");
	printf("3. Remove Book\n");
	printf("4. Exit Book\n");
	printf(">> ");
	
}

int main(){
	
//	print();
	insert(newBook("Hello, World!", "Jonathan", "9708123456789", 123));
	insert(newBook("Hello, World! 2", "Jonathan", "9708223456789", 123));
	insert(newBook("Hello, World! 3", "Jonathan", "9708323456789", 123));
//	print();

//	int remove = del("B00000-12345-JH");
//	print();
//	generateID();	
//	printf("%s\n\n", globalID);
	
	int runApp = 0;
	
	while(runApp != 4){
		displayMenu();
		scanf("%d", &runApp);
		getchar();
		
		switch(runApp){
			case 1:{
				print();
				printf("\nPress enter to continue...");
				getch();
				break;
			}
			case 2:{
				int titleLen;
				int isUnique;
				do{
					isUnique = 1;
					printf("Input book title [5 - 50 characters] [unique]: ");
					scanf("%[^\n]", globalTitle);
					getchar();
					titleLen = strlen(globalTitle);
					
					for(int i = 0; i < SIZE; i++){
						Book *curr = table[i];
						while(curr != NULL){
							if(strcmp(curr->title, globalTitle) == 0){
								isUnique = 0;
								printf("The book's title already exist!\n");
							}
							curr = curr->next;
						}
					}
				}while((titleLen < 5) || (titleLen > 50) || (isUnique == 0));
				
				int authorLen;
				int isAuthorTitle = 0;
				do{
					printf("Input author's name [3-25 characters] [Mr. | Mrs. ]:  ");
					scanf("%[^\n]");
					getchar();
					authorLen = strlen(globalAuthor);
					
					if(strncmp("Mr. ", globalAuthor, 4) == 0){
						authorLen -= 4;
						isAuthorTitle = 1;
						
//						char temp[101];
//						strcpy(temp, globalAuthor);
//						globalAuthor = NULL;
//						for(int i = 4; i < strlen(temp); i++){
//							
//						}
						
					} else if(strncmp("Mrs. ", globalAuthor, 5) == 0) {
						authorLen -= 5;	
						isAuthorTitle = 1;					
					}
				}while((authorLen < 3) || (authorLen > 25) || (isAuthorTitle = 0));
				
				int isNum = 1;
				int isbnLen;
				do{
					printf("Input ISBN [10 - 13] [numeric]: ");
					scanf("%[^\n]", globalISBN);
					getchar();
					isbnLen = strlen(globalISBN);
					
					for(int i = 0; i < isbnLen; i++){
						if((globalISBN[i] < '0') || (globalISBN[i] > '9')){
							isNum = 0;
							break;
						}
					}
				}while((isNum == 0) || (isbnLen < 10) || (isbnLen > 13));
				
				do{
					printf("Input page number [>= 16]: ");
					scanf("%d", &globalPageNumber);
					getchar();
				}while(globalPageNumber < 16);
				
				insert(newBook(globalTitle, globalAuthor, globalISBN, globalPageNumber));
				printf("\nInsert success!\n");
				getch();
				break;
			}
			case 3:{
				char id[101];
				
				if(count != 0){
					printf("Input book ID to delete: ");
					scanf("%[^\n]", id);
					getchar();
					
					int key = hash(id);
					Book *find = searchRec(table[key], id);
					if(find == NULL){
						printf("Book doesn't exist!\n");
						printf("Press enter to continue...");
						getchar();
					} else {
						printf("Book ID: %s\n", find->id);
						printf("Book Title: %s\n", find->title);
						printf("Book Author: %s\n", find->author);
						printf("Book ISBN: %s\n", find->isbn);
						printf("Page Number: %d\n", find->pageNumber);
						char confirm[101];
						
						do{
							printf("Are you sure? [y | n]? ");
							scanf("%[^\n]", confirm);
							getchar();
							if(strcmp(confirm, "y") == 0){
								del(id);
								printf("Delete success!\n");
								printf("Press enter to continue...");
								getchar();
							} else if(strcmp(confirm,"n") == 0){
								printf("Press enter to continue...");
								getchar();
								
							}
						}while( (strcmp(confirm,"y") != 0) && (strcmp(confirm, "n") != 0));
						
						
					}
				}
				
				break;
			}
			case 4:{
				return 0;
				break;
			}
			default:{
				printf("Wrong Input!\n");
				getch();
				break;
			}
		}
	}
	
	return 0;
}
