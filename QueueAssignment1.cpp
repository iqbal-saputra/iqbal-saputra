#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Quasar{
	char name[25];
	int priorityLevel;
	int age;
	Quasar *next, *prev;
} *head = NULL, *tail=NULL;

Quasar *createNewQuasar(char name[], int priorityLevel, int age){
	Quasar *newQuasar = (Quasar *)malloc(sizeof(Quasar));
	
	strcpy(newQuasar->name,name);
	newQuasar->priorityLevel = priorityLevel;
	newQuasar->age = age;
	newQuasar->next = NULL;
	newQuasar->prev = NULL;
	
	return newQuasar;
}

void pushHead(char name[], int priorityLevel, int age){
	Quasar *quasar = createNewQuasar(name, priorityLevel, age);
	
	if(head==NULL){
		head = tail = quasar;
	}else{
		head->prev = quasar;
		quasar->next = head;
		head = quasar;
	}
}

void pushTail(char name[], int priorityLevel, int age){
	Quasar *quasar = createNewQuasar(name, priorityLevel, age);
	
	if(!head){
		pushHead(name, priorityLevel, age);
	}else{
		tail->next = quasar;
		quasar->prev = tail;
		tail = quasar;
	}
}

void pushMid(char name[], int priorityLevel, int age){
	Quasar *quasar = createNewQuasar(name, priorityLevel, age);
	Quasar *curr = head;
	
	if(!head){
		pushHead(name, priorityLevel, age);
	}else if(head == tail){
		if(head->priorityLevel > quasar->priorityLevel){
			pushHead(name, priorityLevel, age);
		}else pushTail(name, priorityLevel, age);
	}else{
		while(curr){
			if(curr->priorityLevel > quasar->priorityLevel){
				quasar -> prev = curr->prev;
				quasar -> next = curr;
				curr->prev->next = quasar;
				curr->prev = quasar;
				return;
			}else if(curr==tail){
				pushTail(name, priorityLevel, age);
				return;
			}else{
				curr = curr->next;
			}
		}
	}
}

void popHead(){
	if(head==NULL){
		puts("No patient to be called...");
		getchar();
		return;
	}else if(head == tail){
		free(head);
		head = tail = NULL;
	}else{
		Quasar *temp = head;
		head = head->next;
		head->prev = NULL;
		temp->next = NULL;
		free(temp);
	}
}

void printAll(){
	int index = 0;
	char level[21];
	if(head){	
		Quasar *curr = head;
		while(curr){
			index++;
			switch(curr->priorityLevel){
				case 1:
					strcpy(level, "Emergency");
					break;
				case 2:
					strcpy(level, "Super VIP");
					break;
				case 3:
					strcpy(level, "VIP");
					break;
				case 4:
					strcpy(level, "Basic");
			}
			printf("%d. %s :\t%s <%d>\n",index, level, curr->name, curr->age);
			curr = curr->next;
		}
	}
	puts("");
	printf("Patient : %d people(s)\n",index);
}

void addPatient(){
	char name[101];
	int priorityLevel, age;
	puts("");
	while(true){
		puts("Input patient name [1..25]: ");
		scanf("%[^\n]",name); getchar();
		if(strlen(name)>1 && strlen(name)<25) break;
	}
	
	puts("1. Emergency");
	puts("2. Super VIP");
	puts("3. VIP");
	puts("4. Basic");
	while(true){
		puts("Select class [1..4]: ");
		scanf("%d",&priorityLevel); getchar();
		if(priorityLevel<5 && priorityLevel > 0) break;	
	}
	
	while(true){
		puts("Input age [1..110]: ");
		scanf("%d",&age); getchar();
		if(age>0 && age<111) break;
	}
	
	switch(priorityLevel){
		case 1:
			pushMid(name, priorityLevel, age);
			break;
		case 2:
			pushMid(name, priorityLevel, age);
			break;
		case 3:
			pushMid(name, priorityLevel, age);
			break;
		case 4:
			pushTail(name, priorityLevel, age);
			break;
	}
}

void callPatient(){
	
	if(head==NULL){
		puts("No patient to be called!");
		puts("Press ENTER to continue..."); getchar();
	}else{
	char level[21];
	switch(head->priorityLevel){
		case 1:
			strcpy(level, "Emergency");
			break;
		case 2:
			strcpy(level, "Super VIP");
			break;
		case 3:
			strcpy(level, "VIP");
			break;
		case 4:
			strcpy(level, "Basic");
	}
		printf("Patient from %s room,\n",level);
		printf("With name %s, %d years\n",head->name, head->age);
		printf("Please moving ahead to Administration room!\n");
		printf("Press ENTER to continue..."); getchar();
		popHead();
	}
}

void removeAll(){
	if(head==NULL){
		puts("No patient data to be removed!");
		puts("Press ENTER to continue..."); getchar();
	}else{
		while(head){
			popHead();
		}
	}
}

void mainMenu(){
	system("cls");
	int input;
	
	while(true){
		puts("Quasar Hospital Queue");
		puts("-----------------------------------------------");
		printAll();
		puts("");
		
		puts("Quasar Queue 1.3");
		puts("-----------------------");
		puts("1. Add patient");
		puts("2. Call patient");
		puts("3. Remove all patient list");
		puts("4. exit");
		
		while(true){
			puts("Select [1..4]: ");
			scanf("%d",&input); getchar();
			if(input<5 && input>0) break;
		}
		
		switch(input){
			case 1:
				addPatient();
				break;
			case 2:
				callPatient();
				break;
			case 3:
				removeAll();
				break;
			case 4:
				return;
				break;
		}
	system("cls");
	}
}

int main(){
	mainMenu();

//	pushHead("jaki",1, 13);
//	pushHead("jaki",1, 13);
//	pushTail("jaki",2, 13);
//	pushMid("jaki",4, 13);
//	pushMid("jaki",4, 13);
//	pushMid("jaki",4, 13);
//	pushMid("jaki",4, 13);
//	pushMid("jaki",4, 13);
//	pushTail("jaki",2, 13);
//	pushHead("jaki",1, 13);
//	pushMid("jaki",2, 13);
//	pushMid("jaki",2, 13);
//	printAll();
	
	return 0;
}
