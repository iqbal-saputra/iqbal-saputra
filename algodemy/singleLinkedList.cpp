#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	//define data" yang akan dimasukan dalam sebuah node
	int data; 
//	char nama[100]; 
	
	Node *next; // pointer untuk nunjuk ke next node
	
} *head, *tail; // *head: pointer yang nunjuk ke node paling pertama dalam list, *tail: pointer yang nunjuk ke node paling 
// fungsi untuk membuat node baru
Node *newNode(int data/*, char nama[]*/){ 
	
	Node *temp = (Node*)malloc(sizeof(Node) * 1 ); // malloc untuk simpan data sementara yang akan dimasukan ke dalam new node
	
	
	temp->data  = data; // masukkan data
	temp->next = NULL; // temp->next awalnya kosong
//	strcpy(temp->nama, nama);
	
	return temp; // return temp node untuk ditambahkan ke list
}
// Push: insert data
// Push: 1. -> head (insert data dari paling depan)
void pushHead(Node *newNode){
	
	if(head == NULL){ // cek apakah linked list kosong
		head = tail = newNode; // jadikan newNode sbg head & tail awal
	} else {
		newNode->next = head; // hubungkan newNode ke head
		head = newNode; // jadikan newNode sebagai head baru
	} 
}
// Push: 2. -> tail (cari posisi di tengah" list untuk insert data)
void pushTail(Node *newNode){
	if(head == NULL){ // cek apakah linked list kosong
		head = tail = newNode; // jadikan newNode sbg head & tail awal
	} else {
		tail->next = newNode; // hubungkan tail ke newNode
		tail = newNode; // jadikan newNode sebagai head baru
	} 
}
// Push: 3. -> mid (insert data dari paling belakang)
void pushMid(Node *newNode){
	
	if(head == NULL){ // cek apakah linked list kosong
		head = tail = newNode; // jadikan newNode sbg head & tail awal
	} else if(head->data > newNode->data){ // jika newNode < head
		pushHead(newNode); // newNode jadi head baru
	} else if(tail->data < newNode->data){ // jika newNode > head
		pushTail(newNode); // newNode jadi tail
	} else { // selain kondisi" di atas
		Node *curr = head; // cek mulai dari head
		
		while( (curr->next != NULL) && (curr->next->data < newNode->data) ){ // jika next ada node ada yang bisa dicheck && next node < newNode
			curr = curr->next; // geser ke kanan
		}
		
		newNode->next = curr->next;
		curr->next = newNode;
	}
	
}
// Pop: delete data
// Pop: 1. -> head (delete data paling depan)
void popHead(){
	
	if(head == NULL){ //cek apakah linked list kosong
		return; // tidak perlu pop karna list kosong
	} else if(head == tail){ // jika node dalam list hanya 1 (head == tail)
		free(head);
		head = tail = NULL;
	} else {
		Node *temp = head; //simpan head awal ke temp
		head = head->next; //jadikan next sebagai head baru
		
		free(temp); // hapus head awal
	}
}
// Pop: 2. -> tail (delete data paling belakang)
void popTail(){
	
	if(head == NULL){ //cek apakah linked list kosong
		return; // tidak perlu pop karna list kosong
	} else if(head == tail){ // jika node dalam list hanya 1 (head == tail)
		free(head);
		head = tail = NULL;
	} else{
		Node *curr = head; // untuk simpan posisi sekarang dimulai dari head
		
		while(curr->next != tail){ // looping sampai satu node sebelum tail
			curr = curr->next; // geser curr
		}
		Node *temp = tail; // simpan tail awal ke temp
		curr->next = NULL; // curr->next akan dihapus
		tail = curr; // jadikan satu node sebelum tail sebagai tail baru
		free(temp); // hapus tail awal yang disimpan di temp
	}	
	
}
// Pop: 3. -> mid (delete data yang kita spesifikan/targetkan)
void popMid(int data){
	
	if(head == NULL){ //cek apakah linked list kosong
		return; // tidak perlu pop karna list kosong
	} else if(head->data == data){
		popHead();
	} else if(tail->data == data){
		popTail();
	} else {
		Node *curr = head; //untuk simpan posisi sekarang dimulai dari head
		
		while( (curr->next != NULL) && (curr->next->data != data) ){ // jika next ada node yang bisa di check, looping sampai satu node sebelum data ditemukan
			curr = curr->next; // geser curr
		}
		if(curr->next != NULL){ // jika curr->next ada isi, itulah yang akan di-pop
			Node *temp = curr->next; //  simpan curr->next ke temp
			
			curr->next = temp->next; // hubungkan satu node sebelum (will be) deletedNode->next
			
			free(temp); // hapus deletedNode
		}
	}
}
//Tips: 4) Pop All: delete all node
void popAll(){
	
	if(head == NULL){ //cek apakah linked list kosong
		return; // tidak perlu pop karna list kosong
	} else { // linked listnya ada isi
		free(head);
		head = tail = NULL; // langsung hapus head & tail
	}
}

void search(int data){
	
	Node *curr = head;
	
	while( (curr != NULL) && (curr->data != data) ){
		curr = curr->next;
	}
	
	if(curr == NULL){
		printf("%d was not found in the linked list\n", data);
	} else {
		printf("%d was found in the linked list!\n", data);
	}
	
}

void print(){
	
	Node *curr = head;
	
	while( (curr != NULL)){
		printf("%d -> ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

int main(){
	
	pushHead(newNode(8));
	pushHead(newNode(10));
	pushHead(newNode(7));
	
//	pushTail(newNode(8));
//	pushTail(newNode(10));
//	pushTail(newNode(7));
	
//	pushMid(newNode(8));
//	pushMid(newNode(10));
//	pushMid(newNode(9));
	
//	search(8);
//	search(10);
//	search(9);
//	search(100);
	
	print();
	
//	popHead();
//	print();
//	
//	popTail();
//	print();
	
//	popMid(9);
//	print();
	
//	popMid(100);
//	print();
	
	return 0;
}
