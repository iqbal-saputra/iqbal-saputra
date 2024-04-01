#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	
	int age;
	char name[51];
	Node *left, *right;
		
}*root;

Node *newNode(int age, char name[]){
	
	Node *temp = (Node*)malloc(sizeof(Node) * 1);
	
	temp->age = age;
	strcpy(temp->name, name);
	temp->left = temp->right = NULL;
	
	return temp;
}

Node *insert(Node *root, Node *newNode){
	
	if(root == NULL){
		return newNode;
	} else if(root->age > newNode->age){
		root->left = insert(root->left, newNode);
	} else {
		root->right = insert(root->right, newNode);
	}
	
}

Node *update(Node *root, int age, char newName[]){
	
	if(root == NULL){
		printf("Data with age %d was not found in the tree\n", age);
		return NULL;
	} else if(root->age > age){
		return update(root->left, age, newName);
	} else if(root->age < age){
		return update(root->right, age, newName);
	} else {
		strcpy(root->name, newName);
		
		return root;
	}
	
}

Node *search(Node *curr, int age){
	
	if(curr == NULL){
		return NULL;
	} else if(curr->age > age){
		return search(curr->left, age);
	} else if(curr->age < age){
		return search(curr->right, age);
	} else {
		return curr;
	}
	
}

Node *del(Node *curr, int age){
	
	if(curr == NULL){
		return NULL;
	} else if(curr->age > age){
		curr->left = del(curr->left, age);
	} else if(curr->age < age){
		curr->right = del(curr->right, age);
	} else {
		// Condition 1: node yang akan di-delete adalah leaf node (tidak punya child)
		if( (curr->left == NULL) && (curr->right == NULL) ){
			free(curr);
			curr = NULL;
		}
		// Condition 2: node yang akan di-delete hanya punya left child
		else if((curr->left != NULL) && (curr->right == NULL)){
			Node *temp = curr->left;
			
			*curr = *temp;
			
			free(temp);
		}
		// Condition 3: node yang akan di-delete hanya punya right child
		else if( (curr->left == NULL) && (curr->right != NULL) ){
			Node *temp = curr->right;
			
			*curr = *temp;
			
			free(temp);
		}
		// Condition 4: node yang akan di-delete punya left child & right child
		else {
			Node *temp = curr->left;
			
			while(temp->right != NULL){
				temp = temp->right;
			}
			curr->age = temp->age;
			strcpy(curr->name, temp->name);
			curr->left = del(curr->left, temp->age);
		}
		
		return curr;
	}
	
}

//Node *del(Node *curr, int age){
//	if(!curr) return NULL;
//	else if(curr->age > age) curr->left = del(curr->left, age);
//	else if(curr->age < age) curr->right = del(curr->right, age);
//	else{
////		case 1 -> tidak punya child
//		if(!curr->right && !curr->left){
//			free(curr);
//			curr = NULL;
//		}
////		case 2 -> punya right child saja
//		else if(curr->right && !curr->left){
//			Node *temp = curr->right;
//			*curr = *temp;
//			free(temp);
//		}
////		case 3 -> punya left child saja
//		else if(!curr->right && curr->left){
//			Node *temp = curr->left;
//			*curr = *temp;
//			free(temp);
//		}
////		case 4 -> punya 2 child
//		else{
//			Node *temp = curr->left;
//			while(temp->right != NULL){
//				temp = temp->right;
//			}
////			kita udh dapat largest node dari left subtrees
//			strcpy(curr->name, temp->name);
//			curr->age = temp->age;
//			curr->left = del(curr->left, temp->age);
//		}
//		return curr;
//	}
//}

void preOrder(Node *root){
	
	if(root == NULL){
		return;
	} else {
		printf("Age: %d, Name; %s\n", root->age, root->name);
		preOrder(root->left);
		preOrder(root->right);
	}
	
}

void inOrder(Node *root){
	
	if(root == NULL){
		return;
	} else {
		inOrder(root->left);
		printf("Age: %d, Name; %s\n", root->age, root->name);
		inOrder(root->right);
	}
	
}

void postOrder(Node *root){
	
	if(root == NULL){
		return;
	} else {
		postOrder(root->left);
		postOrder(root->right);
		printf("Age: %d, Name; %s\n", root->age, root->name);
	}
	
}

int main(){
	
	root = insert(root, newNode(19, "Andi"));
	root = insert(root, newNode(1, "Budi"));
	root = insert(root, newNode(21, "Cindy"));
	root = insert(root, newNode(3, "Dodi"));
	root = insert(root, newNode(2, "Edi"));
	root = insert(root, newNode(5, "Fendi"));
	root = insert(root, newNode(4, "Gerdy"));
	
//	printf("Pre Order: \n");
//	preOrder(root);
//	
//	printf("\nIn Order: \n");
//	inOrder(root);
//	
//	printf("\nPost Order: \n");
//	postOrder(root);
//	
//	update(root, 1, "Budi Setiawan");
//	printf("\nPre Order: \n");
//	preOrder(root);
	
//	printf("\n");
//	int searchAge = 0;
//	Node *searchNode = search(root,searchAge);
//	if(searchNode == NULL){
//		printf("Data with age %d was not found\n", searchAge);
//	} else {
//		printf("Age: %d, Name %s\n", searchNode->age, searchNode->name);
//	}
	
	root = del(root, 0);
	printf("\nIn Order: \n");
	inOrder(root);
	
	return 0;
}
