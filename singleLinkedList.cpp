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
	else{
		tail->next = newNode;
		tail = newNode;
	}
}

void pushMid(struct Node *newNode){
	
	if(head == NULL){
		pushHead(newNode);
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
		
		while(curr->next != tail){
			curr = curr->next;
		}
		free(tail);
		tail = curr;
		tail->next = NULL;
	}
}

void popMid(int data){
	
	if(head == NULL){
		return;
	}
	else if(head->data == data){
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
		}
		else {
			printf("%d wasn't in the linked list", data);
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
		printf("All nodes have been deleted\n");
	}
}

void search(int data){
	
	struct Node *curr = head;
	
	while((curr != NULL) && (curr->data != data)){
		curr = curr->next;
	}
	
	if(curr == NULL){
		printf("%d wasn't found in the linked list\n", data);
	}
	else {
		printf("%d found in the linked list\n", data);
	}
}

void print(){
	
	if(head == NULL){
		printf("There is no data in linked list\n");
	} else {
		struct Node *curr = head;
		
		while(curr != NULL){
			printf("%d -> ", curr->data);
			curr = curr->next;
		}
		
		puts("NULL");
	}
}

int main(){
	
	pushHead(newNode(1));
	getchar();
	print();

	pushTail(newNode(10));
	getchar();
	print();

	pushMid(newNode(2));
	getchar();
	print();

	pushMid(newNode(5));
	getchar();
	print();

	pushMid(newNode(4));
	getchar();
	print();
	
	pushMid(newNode(3));
	getchar();
	print();

	pushMid(newNode(7));
	getchar();
	print();

	pushMid(newNode(8));
	getchar();
	print();
	
	popHead();
	getchar();
	print();
	
	popTail();
	getchar();
	print();
	
	popMid(5);
	getchar();
	print();
	
	puts("");
	search(3);
	getchar();
	
	search(1);
	getchar();
	
	print();
	puts("");
		
	popAll();
	getchar();

	print();
	
	return 0;
}