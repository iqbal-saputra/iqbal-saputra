#include <stdio.h>
#include <stdlib.h>

struct Node{
	
	int data;
	struct Node *next;
	
}*head, *tail;

struct Node *newNode(int data){
	
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	
	temp->data = data;
	temp->next = NULL;
	return temp;
}
	
void pushHead(struct Node *newNode){
	
	if(head == NULL){
		head = tail = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
}

void pushTail(struct Node *newNode){
	
	if(head == NULL){
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
}

void pushMid(struct Node *newNode){
	
	if(head == NULL){
		head = tail = newNode;
	}
	else if(head->data > newNode->data){
		pushHead(newNode);
	}
	else if(tail->data < newNode->data){
		pushTail(newNode);
	}
	else {
		struct Node *curr = head;
		
		while((curr->next != NULL) && (curr->next->data < newNode->data)){
			curr = curr->next;
		}
		
		newNode->next = curr->next;
		curr->next = newNode;
	}
}

void popHead(){
	
	if(head == NULL){
		return;
	}
	else if(head == tail){
		free(head);
		head = tail = NULL;
	}
	else {
		struct Node *temp = head;
		head = temp->next;
		free(temp);
	}
}

void popTail(){
	
	if(head == NULL){
		return;
	}
	else if(head == tail){
		free(head);
		head = tail = NULL;
	}
	else {
		struct Node *curr = head;
		
		while((curr->next != tail)){
			curr = curr->next;
		}
		free(tail);
		curr->next = NULL;
		tail = curr;
	}
}

void popMid(int data){
	
	if(head->data == data){
		popHead();
	}
	else if(tail->data == data){
		popTail();
	}
	else {
		struct Node *curr = head;
		
		while((curr->next != NULL) && (curr->next->data != data)){
			curr = curr->next;
		}
		
		if(curr->next != NULL){
			struct Node *temp = curr->next;
			curr->next = temp->next;
			free(temp);
		} else {
			printf("%d wasn't found in linked list\n", data);
		}
	}
}

void popAll(){
	
	if(head == NULL){
		return;
	}
	else {
		free(head);
		head = tail = NULL;
	}
	
}

void search(int data){
	
	struct Node *curr = head;
	
	while(curr != NULL && curr->data != data){
		curr = curr->next;
	}
	if(curr == NULL){
		printf("Data wasn't found in the linked list!\n");
	}
	else {
		printf("%d was found in the linked list!\n", data);
	}
	
}

void print(){
	
	if(head == NULL){
		printf("There is no data in linked list!\n");
		return;
	}
	
	struct Node *curr = head;
	
	while(curr != NULL){
		printf("%d -> ", curr->data);
		curr = curr->next;
	}
	puts("NULL");
	
}

int main(){
	
	pushHead(newNode(20));
	pushTail(newNode(25));
	pushMid(newNode(22));
	pushMid(newNode(21));
	pushMid(newNode(23));
	pushMid(newNode(24));
	print();
	
	popHead();
	getchar();
	print();
	
	popTail();
	getchar();
	print();
	
	popMid(23);
	getchar();
	print();
	puts("");
	
	popMid(29);
	getchar();
	print();
	puts("");
	
	search(21);
	getchar();
	
	popAll();
	print();
	
	return 0;
}