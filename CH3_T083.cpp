#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>

struct Product{
	
	char ID[10];
	char name[30];
	char color[20];
	char size[5];
	int quantity;
	int price;
	
};
Product product[1000];
char newProduct[100];
int jumlahProduk = 0;
int binarySearch(struct Product data[], int left, int right, char target[]);
void readFile();
void mergeID(struct Product data[], int left, int right);
void mergeN(struct Product data[], int left, int right);
void mergeC(struct Product data[], int left, int right);
void mergeQ(struct Product data[], int left, int right);
void mergeS(struct Product data[], int left, int right);
void mergeSort(struct Product data[], int left, int right, int choice);
void bershka();
void displayMenu();
void displayProduct();
void displayCase2();
void getProduct(char *newProduct);
void addProduct(char *newProduct);
void resetAllProducts(struct Product *product, int *size);
bool isProductNameValid(char newProduct[]);
bool isProductPriceValid(int P);
bool isProductColorValid(char newProduct[]);
bool isProductQtyValid(int Q);
bool isProductSizeValid(char newProduct[]);
bool isDuplicateID(const char *newID, const struct Product data[], int jumlahProduk);
void updateProduct();
void removeProduct();
int main(){
	
	char target[30];
	readFile();
	int runApp = 1;
	
	while(runApp){
		int runMenu = 1;
		int menu;
		
		while(runMenu){
			system("cls");
			bershka();
			displayMenu();
//			menu = getch() - '0';
			scanf("%d", &menu);
			getchar();
			
			switch(menu){
				case 1:{
					system("cls");
					getProduct(newProduct);
					resetAllProducts(product,&jumlahProduk);
					readFile();
					displayProduct();
					newProduct[0] = '\0';
					break;
				}
				case 2:{
					
					int choice = -1;
					while(choice != 0){
						system("cls");
						if(choice == 1){
							printf("Sorted by: ID\n");
						} else if(choice == 2){
							printf("Sorted by: Name\n");
						} else if(choice == 3){
							printf("Sorted by: Color\n");
						} else if(choice == 4){
							printf("Sorted by: Quantity\n");
						} else if(choice == 5){
							printf("Sorted by: Size\n");
						} else {
							puts("");
						}
						displayProduct();
						displayCase2();
//						choice = getch() - '0';
						scanf("%d", &choice);
						getchar();
						
						switch(choice){
							case 1:
							case 2:
							case 3:
							case 4:
							case 5:
								mergeSort(product, 0, jumlahProduk-1, choice);
								break;
							case 0:{
								choice = 0;
								break;
							}
							default:{
								printf("Invalid input! . . .");
								getch();
								break;
							}
						}
					}
					break;
				}
				case 3:{
					updateProduct();
					break;
				}
				case 4:{
					removeProduct();
					break;
				}
				case 0:{
					return 0;
				}
			}
		}
	}
	
	return 0;
}
void bershka(){
	
	printf(" /$$$$$$$                    /$$$$$$  /$$$$$$  /$$       /$$					\n");
	printf("| $$__  $$                  |_  $$_/ /$$__  $$| $$      | $$					\n");
	printf("| $$  \\ $$  /$$$$$$   /$$$$$$ | $$  | $$  \\__/| $$$$$$$ | $$   /$$  /$$$$$$		\n");
	printf("| $$$$$$$  /$$__  $$ /$$__  $$| $$  |  $$$$$$ | $$__  $$| $$  /$$/ |____  $$	\n");
	printf("| $$__  $$| $$$$$$$$| $$  \\__/| $$   \\____  $$| $$  \\ $$| $$$$$$/   /$$$$$$$	\n");
	printf("| $$  \\ $$| $$_____/| $$      | $$   /$$  \\ $$| $$  | $$| $$_  $$  /$$__  $$	\n");
	printf("| $$$$$$$/|  $$$$$$$| $$     /$$$$$$|  $$$$$$/| $$  | $$| $$ \\  $$|  $$$$$$$	\n");
	printf("|_______/  \\_______/|__/    |______/ \\______/ |__/  |__/|__/  \\__/ \\_______/	\n\n");
	
}
void displayMenu(){
	
	printf("1. Add Product\n");
	printf("2. View Product\n");
	printf("3. Update Product\n");
	printf("4. Remove Product\n");
	printf("0. Exit\n");
	printf(">> ");
}
void displayCase2(){
	printf("\n\nSort By:\n");
	printf("[1] ID\n");
	printf("[2] Name\n");
	printf("[3] Color\n");
	printf("[4] Quantity\n");
	printf("[5] Size\n");
	printf("[0] Back\n>>  ");
}
void displayProduct(){
	
	int j = 0;
	printf("================================================================================\n");
	printf("| %-5s | %-20s | %-10s | %-10s | %-10s | %-7s|", "ID", "Product Name", "Price", "Color", "Quantity", "Size");
	printf("\n================================================================================\n");
	for(int j = 0; j < jumlahProduk; j++){
		printf("| %-5s | %-20s | %-10d | %-10s | %-10d | %-7s|\n", product[j].ID, product[j].name, product[j].price, product[j].color, product[j].quantity, product[j].size );
	}
	printf("================================================================================\n");
}
void readFile(){
	
	FILE *data = fopen("products.txt", "r");
	
	int i = 0;
	
	if(data == NULL){
		printf("Data tidak tersedia!\n");
		return;
	}
	
	while(!feof(data)){
		fscanf(data,"%[^#]#%[^#]#%d#%[^#]#%d#%[^\n]\n", product[i].ID, product[i].name, &product[i].price, product[i].color, &product[i].quantity, product[i].size);
		i++;
		jumlahProduk++;
	}
	
	fclose(data);
}
void mergeSort(struct Product data[], int left, int right, int c){
	
	if(left < right){
		int mid = (left + right) / 2;
		
		mergeSort(data, left, mid, c);
		mergeSort(data, mid + 1, right, c);
		
		if(c == 1){
			mergeID(data, left, right);
		} else if(c == 2){
			mergeN(data, left, right);
		} else if(c == 3){
			mergeC(data, left, right);
		} else if(c == 4){
			mergeQ(data, left, right);
		} else if(c == 5){
			mergeS(data, left, right);
		}
	}
}
void mergeID(struct Product data[], int left, int right){
	
	int mid = (left + right) / 2;
	int curr = 0;
	int leftIdx = left;
	int rightIdx = mid + 1;
	struct Product sortedData[right - left + 1];
	
	while(leftIdx <= mid && rightIdx <= right){
		if(strcmp(data[leftIdx].ID, data[rightIdx].ID) > 0){
			sortedData[curr] = data[rightIdx];
			rightIdx++, curr++;
		} else {
			sortedData[curr] = data[leftIdx];
			leftIdx++, curr++;
		}
	}
	
	while(leftIdx <= mid){
		sortedData[curr] = data[leftIdx];
		leftIdx++, curr++;
	}
	
	while(rightIdx <= right){
		sortedData[curr] = data[rightIdx];
		rightIdx++, curr++;
	}
	
	for(int i = 0; i < curr; i++){
		data[i + left] = sortedData[i];
	}
}
void mergeN(struct Product data[], int left, int right){
	
	int mid = (left + right) / 2;
	int curr = 0;
	int leftIdx = left;
	int rightIdx = mid + 1;
	struct Product sortedData[right - left + 1];
	
	while(leftIdx <= mid && rightIdx <= right){
		if(strcmp(data[leftIdx].name, data[rightIdx].name) > 0){
			sortedData[curr] = data[rightIdx];
			rightIdx++, curr++;
		} else {
			sortedData[curr] = data[leftIdx];
			leftIdx++, curr++;
		}
	}
	
	while(leftIdx <= mid){
		sortedData[curr] = data[leftIdx];
		leftIdx++, curr++;
	}
	
	while(rightIdx <= right){
		sortedData[curr] = data[rightIdx];
		rightIdx++, curr++;
	}
	
	for(int i = 0; i < curr; i++){
		data[i + left] = sortedData[i];
	}
}
void mergeC(struct Product data[], int left, int right){
	
	int mid = (left + right) / 2;
	int curr = 0;
	int leftIdx = left;
	int rightIdx = mid + 1;
	struct Product sortedData[right - left + 1];
	
	while(leftIdx <= mid && rightIdx <= right){
		if(strcmp(data[leftIdx].color, data[rightIdx].color) > 0){
			sortedData[curr] = data[rightIdx];
			rightIdx++, curr++;
		} else {
			sortedData[curr] = data[leftIdx];
			leftIdx++, curr++;
		}
	}
	
	while(leftIdx <= mid){
		sortedData[curr] = data[leftIdx];
		leftIdx++, curr++;
	}
	
	while(rightIdx <= right){
		sortedData[curr] = data[rightIdx];
		rightIdx++, curr++;
	}
	
	for(int i = 0; i < curr; i++){
		data[i + left] = sortedData[i];
	}
}
void mergeQ(struct Product data[], int left, int right){
	
	int mid = (left + right) / 2;
	int curr = 0;
	int leftIdx = left;
	int rightIdx = mid + 1;
	struct Product sortedData[right - left + 1];
	
	while(leftIdx <= mid && rightIdx <= right){
		if(data[leftIdx].quantity > data[rightIdx].quantity){
			sortedData[curr] = data[rightIdx];
			rightIdx++, curr++;
		} else {
			sortedData[curr] = data[leftIdx];
			leftIdx++, curr++;
		}
	}
	
	while(leftIdx <= mid){
		sortedData[curr] = data[leftIdx];
		leftIdx++, curr++;
	}
	
	while(rightIdx <= right){
		sortedData[curr] = data[rightIdx];
		rightIdx++, curr++;
	}
	
	for(int i = 0; i < curr; i++){
		data[i + left] = sortedData[i];
	}
}
void mergeS(struct Product data[], int left, int right){
	
	int mid = (left + right) / 2;
	int curr = 0;
	int leftIdx = left;
	int rightIdx = mid + 1;
	struct Product sortedData[right - left + 1];
	
	while(leftIdx <= mid && rightIdx <= right){
		if(strcmp(data[leftIdx].size, data[rightIdx].size) < 0){
			sortedData[curr] = data[rightIdx];
			rightIdx++, curr++;
		} else {
			sortedData[curr] = data[leftIdx];
			leftIdx++, curr++;
		}
	}
	
	while(leftIdx <= mid){
		sortedData[curr] = data[leftIdx];
		leftIdx++, curr++;
	}
	
	while(rightIdx <= right){
		sortedData[curr] = data[rightIdx];
		rightIdx++, curr++;
	}
	
	for(int i = 0; i < curr; i++){
		data[i + left] = sortedData[i];
	}
}
int binarySearch(struct Product data[], int left, int right, char target[]){
	
	while(left <= right){
		int mid = (left + right ) / 2;
		
		if(strcmp(data[mid].ID, target) == 0){
			return mid;
		} else if(strcmp(data[mid].ID, target) > 0 ){
			right = mid - 1;
		} else if(strcmp(data[mid].ID, target) < 0){
			left = mid + 1;
		}
	}
	
	return -1;
}
void getProduct(char *newProduct){
	
	srand(time(NULL));
    char newID[5];
    int hasil;
    int attempt = 0; 

    do {
        hasil = rand() % 999 + 1;
        sprintf(newID, "BR%03d", hasil);
        attempt++;
    } while (isDuplicateID(newID, product, jumlahProduk) && attempt < 1000); 

    if (attempt == 1000) {
        printf("Product Already full...");
        getch();
        return;
    }

    strcpy(newProduct, newID);
    strcat(newProduct, "#");
	
	char I[100];
	while(!isProductNameValid(I)){
		printf("Input product name [10 - 20 characters]: ");
		scanf("%[^\n]", I);
		getchar();
	}
					
	int P;
	char price[10];
	while(!isProductPriceValid(P)){
		printf("Input product price [50000-100000]: ");
		scanf("%d", &P);
		getchar();
		sprintf(price,"%d", P);
		
	}
	strcat(I,"#");
	strcat(I,price);
					
	char C[20];
	while(!isProductColorValid(C)){
		printf("Input product color [Brown | Baby Blue | White]: ");
		scanf("%[^\n]", C);
		getchar();
	}
	strcat(I,"#");
	strcat(I,C);
					
	int Q;
	char quantity[5];
	while(!isProductQtyValid(Q)){
		printf("Input product quantity [25-109]: ");
		scanf("%d", &Q);
		getchar();
		sprintf(quantity,"%d",Q);
	}
	strcat(I,"#");
	strcat(I,quantity);
					
	char S[5];
	while(!isProductSizeValid(S)){
		printf("Input product size [XS | S | M | L]: ");
		scanf("%[^\n]", S);
		getchar();
	}
	strcat(I,"#");
	strcat(I,S);
	strcat(newProduct, I);
	
	FILE *d = fopen("products.txt", "a");
	
	fprintf(d, "%s\n", newProduct);
	
	fclose(d);
	
	printf("Product succesfully added!\n\n");
					
	printf("Press [ENTER] to continue...");
	getch();
	
}
void resetAllProducts(struct Product *pProduct, int *size) {
    for (int i = 0; i < *size; i++) {
        pProduct[i].ID[0] = '\0'; 
        pProduct[i].name[0] = '\0'; 
        pProduct[i].color[0] = '\0'; 
        pProduct[i].size[0] = '\0'; 
        pProduct[i].quantity = 0; 
        pProduct[i].price = 0;
        *size = 0;
    }
}
bool isProductNameValid(char newProduct[]){
	
	if(strlen(newProduct) < 10 || strlen(newProduct) > 20){
		return false;
	}
	
	for(int i = 0; i < strlen(newProduct); i++){
		if(!isalpha(newProduct[i]) && newProduct[i] != ' '){
			return false;
		}
	}
	
	return true;
	
}
bool isProductPriceValid(int P){
	
	if(P < 50000 || P > 100000){
		return false;
	}
	
	return true;
	
}
bool isProductColorValid(char newProduct[]){
	
	if(strcmp(newProduct, "Brown") == 0 || strcmp(newProduct, "Baby Blue") == 0 || strcmp(newProduct, "White") == 0){
		return true;
	}
	
	return false;
}
bool isProductQtyValid(int Q){
	
	if(Q < 25 || Q > 109){
		return false;
	}
	
	return true;
	
}
bool isProductSizeValid(char newProduct[]){
	
	if(strcmp(newProduct,"XS") == 0 || strcmp(newProduct,"S") == 0 || strcmp(newProduct,"M") == 0 || strcmp(newProduct,"L") == 0){
		return true;
	}
	
	return false;
}
bool isDuplicateID(const char *newID, const struct Product data[], int jumlahProduk) {
    for (int i = 0; i < jumlahProduk; i++) {
        if (strcmp(newID, data[i].ID) == 0) {
            return true;
        }
    }
    return false;
}
void updateProduct() {
    mergeID(product, 0, jumlahProduk - 1);
    
    char targetID[10];
    system("cls");
    displayProduct();
    printf("Input product ID to update: ");
    scanf("%s", targetID);
    getchar();
    
    int indexTarget = binarySearch(product, 0, jumlahProduk, targetID);
    
    if(indexTarget != -1) {
        char productName[100];
        while(!isProductNameValid(productName)){
            printf("Enter updated product name [10 - 20 characters]: ");
            scanf(" %[^\n]", productName);
            getchar();
        }
        strcpy(product[indexTarget].name, productName);
        
        int productPrice;
        while(!isProductPriceValid(productPrice)){
            printf("Enter updated product price [50000 - 100000]: ");
            scanf("%d", &productPrice);
            getchar();
        }
        product[indexTarget].price = productPrice;
        
        char productColor[100];
        while(!isProductColorValid(productColor)){
            printf("Enter updated product color [Brown | Baby Blue | White]: ");
            scanf(" %[^\n]", productColor);
            getchar();
        }
        strcpy(product[indexTarget].color, productColor);
        
        int productQty;
        while(!isProductQtyValid(productQty)){
            printf("Enter updated product quantity [25 - 109]: ");
            scanf("%d", &productQty);
            getchar();
        }
        product[indexTarget].quantity = productQty;
        
        char productSize[5];
        while(!isProductSizeValid(productSize)){
            printf("Enter updated product size [XS | S | M | L]: ");
            scanf(" %[^\n]", productSize);
            getchar();
        }
        strcpy(product[indexTarget].size, productSize);
        
        FILE *data = fopen("products.txt", "w");
        for(int i = 0; i < jumlahProduk; i++){
            fprintf(data, "%s#%s#%d#%s#%d#%s\n", product[i].ID, product[i].name, product[i].price, product[i].color, product[i].quantity, product[i].size);
        }
        fclose(data);
        
        printf("Product with ID %s updated succesfully!\n\n", targetID);
    } else {
        printf("Product with ID %s not found.\n\n", targetID);
        printf("Press [ENTER] to continue...\n");
        getch();
        return; // Kembali ke menu utama setelah produk tidak ditemukan
    }
    
    printf("Press [ENTER] to continue...\n");
    getch();
}
void removeProduct() {
    char targetID[10];
    system("cls");
    displayProduct();
    printf("Input product ID to remove: ");
    scanf("%s", targetID);
    getchar();
    
    int indexTarget = -1;
    for (int i = 0; i < jumlahProduk; i++) {
        if (strcmp(product[i].ID, targetID) == 0) {
            indexTarget = i;
            break;
        }
    }
    
    if (indexTarget != -1) {
        for (int i = indexTarget; i < jumlahProduk - 1; i++) {
            strcpy(product[i].ID, product[i + 1].ID);
            strcpy(product[i].name, product[i + 1].name);
            strcpy(product[i].color, product[i + 1].color);
            strcpy(product[i].size, product[i + 1].size);
            product[i].quantity = product[i + 1].quantity;
            product[i].price = product[i + 1].price;
        }
        strcpy(product[jumlahProduk - 1].ID, "");
        strcpy(product[jumlahProduk - 1].name, "");
        strcpy(product[jumlahProduk - 1].color, "");
        strcpy(product[jumlahProduk - 1].size, "");
        product[jumlahProduk - 1].quantity = 0;
        product[jumlahProduk - 1].price = 0;
        
        jumlahProduk--;
        
        for (int i = 0; i < jumlahProduk - 1; i++) {
            for (int j = 0; j < jumlahProduk - i - 1; j++) {
                if (strcmp(product[j].ID, product[j + 1].ID) > 0) {
                    struct Product temp = product[j];
                    product[j] = product[j + 1];
                    product[j + 1] = temp;
                }
            }
        }
        
        FILE *data = fopen("products.txt", "w");
        for (int i = 0; i < jumlahProduk; i++) {
            fprintf(data, "%s#%s#%d#%s#%d#%s\n", product[i].ID, product[i].name, product[i].price, product[i].color, product[i].quantity, product[i].size);
        }
        fclose(data);
        
        printf("Product with ID %s successfully deleted!\n\n", targetID);
    } else {
        printf("Product not found!\n\n");
    }
    
    printf("Press [ENTER] to continue...\n");
    getch();
}
