#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>

struct Mahasiswa{
	
	char nama[100];
	char nim[20];
	int usia;
	double ipk;
	
};
  
//using namespace std;
//This Initiates the fullscreen function
void fullscreen(){
keybd_event(VK_MENU,0x38,0,0);
keybd_event(VK_RETURN,0x1c,0,0);
keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

int main(){
	
//	Mahasiswa mahasiswa1;
//	strcpy(mahasiswa1.nama,"Iqbal");
//	printf("%s", mahasiswa1.nama);
//	
//	int angka[10] = {0,1,2,3,4,5,6,7,8,9};
//	
//	int *numbers = (int*)malloc(sizeof(int) * 10); // sama aja dengan -> numbers[10];
//	
//	*(numbers + 0) = 0;
//	*(numbers + 1) = 1;
//	*(numbers + 2) = 2;
//	*(numbers + 3) = 3;
//	*(numbers + 4) = 4;
//	*(numbers + 5) = 10;
//	*(numbers + 6) = 6;
//	*(numbers + 7) = 7;
//	*(numbers + 8) = 8;
//	*(numbers + 9) = 9;
//	
//	numbers[5] = 2;
//	
//	printf("%d", *(numbers + 5));

//	Mahasiswa dataMahasiswa[1000];
	Mahasiswa *dataMahasiswa = (Mahasiswa*)malloc(sizeof(Mahasiswa) * 1000);
	
	// khusus untuk struct yang menggunakan Malloc bisa pake ->
	
	strcpy((dataMahasiswa + 0)->nama, "Iqbal");
	strcpy((dataMahasiswa + 0)->nim, "2702390236");
	dataMahasiswa[0].usia = 23;
	dataMahasiswa[0].ipk = 3.2;
	
	strcpy((dataMahasiswa + 1)->nama, "Rehan");
	strcpy((dataMahasiswa + 1)->nim, "2702390254");
	dataMahasiswa[1].usia = 18;
	dataMahasiswa[1].ipk = 2.9;
	
	strcpy((dataMahasiswa + 2)->nama, "Naufal");
	strcpy((dataMahasiswa + 2)->nim, "2723405239");
	dataMahasiswa[2].usia = 19;
	dataMahasiswa[2].ipk = 2.6;
	
//	strcpy((dataMahasiswa + 0)->nama, "Jonathan");
//	fullscreen(); //This puts the window in fullscreen
	
	for(int i = 0; i < 3; i++){
		printf("%d. \n", i + 1);
		printf("Nama: %s\n", (dataMahasiswa + i) -> nama);
		printf("NIM: %s\n", (dataMahasiswa + i)->nim);
		printf("Usia: %d\n", (dataMahasiswa + i)->usia);
		printf("IPK: %.2lf\n", (dataMahasiswa + i)->ipk);
		for(int j = 0; j < 15; j++){
			printf("%c", 205);
		}
		printf("\n");
	}
	 
		
	
	return 0;
}
