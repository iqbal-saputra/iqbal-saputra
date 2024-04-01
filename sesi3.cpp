#include <stdio.h>
#include <stdlib.h>

struct Node{
	
	int data;
	
	Node *next, *prev; // *next: pointer untuk next node, *prev: pointer untuk previous node
}*head, *tail;

Node *newNode(int data){
	
	Node *temp = (Node*)malloc(sizeof(Node) * 1);
	
	temp->data = data;
	temp->next = temp->prev = NULL; //temp->next & temp->prev awalnya kosong
	
	return temp;
}

void pushHead(Node *newNode){
	
	if(head == NULL){
		head = tail = newNode;
	} else {
		newNode->next = head;
		head->prev = newNode; // hubungkan newNode ke sebelum head
		head = newNode;
	}
	
}

void pushTail(Node *newNode){
	
	if(head == NULL){
		head = tail = newNode;
	} else {
		tail->next = newNode;
		newNode->prev = tail; // hubungkan newNode ke posisi setelah tail
		tail = newNode;
	}
	
}

void pushMid(Node *newNode){
	
	if(head == NULL){
		head = tail = newNode;
	} else if(head->data > newNode->data){
		pushHead(newNode);
	} else if(tail->data < newNode->data){
		pushTail(newNode);
	} else {
		Node *curr = head;
		
		while( (curr->next != NULL) && (curr->next->data < newNode->data) ){
			curr = curr->next;
		}
		
		newNode->next = curr->next;
		curr->next->prev = newNode;
		curr->next = newNode; // pointer hanya bisa menunjuk 1 node
		newNode->prev = curr;
		
	}
	
}

void popHead(){
	
	if(head == NULL){
		return;
	} else if(head == tail){
		free(head);
		head = tail = NULL;
	} else {
		Node *temp = head;
		
		head = head->next;
		head->prev = NULL; // memberi tahu bahwa sebelum posisi head baru sudah tidak ada node lagi
		
		free(temp);
	}

}

void popTail(){
	
	if(head == NULL){
		return;
	} else if(head == tail){
		free(head);
		head = tail = NULL;
	} else {
		
		Node *temp = tail; // menyimpan tail awal (curr diganti jadi temp)
		
		// while loop nya dihapus, karna tidak memakai current lagi
		tail = tail->prev; // jadikan satu node sebelum tail menjadi tail baru
		tail->next = NULL;
		// Node *temp dihapus;
		
		free(temp);
	}
	
}

void popMid(int data){
	
	if(head == NULL){
		return;
	} else if(head->data == data){
		popHead();
	} else if(tail->data == data){
		popTail();
	} else {
		Node *curr = head;
		
		while((curr->next != NULL) && (curr->next->data != data )){
			curr = curr->next;
		}
		
		if(curr->next != NULL){
			Node *temp = curr->next;
			
			curr->next = temp->next;
			temp->next->prev = curr; // jadikan curr sebagai posisi sblm temp->next (curr jadi prev nya si temp->next)
			
			free(temp);
		}
	}
}

void popAll(){
	
	if(head == NULL){
		return;
	} else {
		head = tail = NULL;
		free(head);
	}
	
}

void search(int data){
	
	Node *curr = head;
	
	while((curr != NULL) && (curr->data != data)){
		curr = curr->next;
	}
	
	if(curr == NULL){
		printf("%d was not found in the linked list\n", data);
	} else {
		printf("%d was found in the linked list\n", data);
	}
	
}

void print(){
	
	Node *curr = head;
	
	while((curr != NULL)){
		printf("%d <- -> ", curr->data);
		curr = curr->next;
	}
	printf("\n");
	
}
int main(){
	
//	pushHead(newNode(8));
//	pushHead(newNode(2));
//	pushHead(newNode(5));
	
//	pushTail(newNode(1));
//	pushTail(newNode(3));
//	pushTail(newNode(7));
	
//	pushMid(newNode(1));
//	pushMid(newNode(3));
//	pushMid(newNode(2));
	
//	search(2);
//	search(10);
	
//	print();
	
//	popHead();
//	print();

//	popTail();
//	print();

//	popMid(2);
//	print();
	
	
	
	return 0;
}
