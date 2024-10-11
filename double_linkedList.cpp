#include <stdio.h>
#include <stdlib.h>
// Double linked list

struct Node{
	int num;
	struct Node *next;
	struct Node *prev;
}*head = NULL, *tail = NULL;

struct Node *createNode(int num){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	
	newNode->num = num;
	newNode->next = newNode->prev = NULL;
	
	return newNode;
}

void pushHead(int num){
	struct Node *newNode = createNode(num);
	
	if(head == NULL){
		head = newNode;
		tail = newNode;
	} else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

void pushTail(int num){
	struct Node *newNode = createNode(num);
	
	if(head == NULL){
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	
}

void popHead(){
	
	if(head != NULL){
		if(head == tail){
			free(head);
			head = NULL;
			tail = NULL;
		} else {
			head = head->next;
			free(head->prev);
			head->prev = NULL;
		}
	}
	
}

void popTail(){
	if(head != NULL){
		if(head == tail){
			free(head);
			head = NULL;
			tail = NULL;
		} else {
			tail = tail->prev;
			free(tail->next);
			tail->next = NULL;
		}
	}
}

void pushMid(int num){
	
	struct Node *newNode = createNode(num);
	struct Node *current = head;
	
	if(head == NULL){
		head = newNode;
		tail = newNode;
	} else {
		while(current != NULL && current->num < num){
			current = current->next;
		}
		
		if(current == head){
			pushHead(num);
		}
		else if(current == NULL){
			pushTail(num);
		}
		else {
			current->prev->next = newNode;
			newNode->prev = current->prev;
			current->prev = newNode;
			newNode->next = current;
		}
	}
}

void popMid(int target){
	
	
	if(head != NULL){
		struct Node *current = head;
		
		while(current != NULL && current->num != target){
			current = current->next;
		}
		
		if(current != NULL){
			if(current == head){
				popHead();
			}
			else if(current == tail){
				popTail();
			}
			else {
				current->prev->next = current->next;
				current->next->prev = current->prev;
				free(current);
				current = NULL;
			}
		} else {
			printf("Target %d was not found\n", target);
		}
	}
}

void printAll(){
	struct Node *current = head;
	
	while(current != NULL){
		printf("%d <=> ", current->num);
		current = current->next;
	}
	printf("\n");
}
int main(){
	
//	pushHead(5);
//	printAll();
//	pushHead(4);
//	printAll();
//	pushHead(3);
//	printAll();
//	pushHead(2);
//	printAll();
//	pushHead(1);
//	printAll();
//	
//	pushTail(6);
//	printAll();
//	
//	popHead();
//	printAll();

	pushMid(2);
	printAll();
	pushMid(1);
	printAll();
	pushMid(6);
	printAll();
	pushMid(3);
	printAll();
	pushMid(5);
	printAll();
	
	popMid(3);
	printAll();
	
	return 0;
};
