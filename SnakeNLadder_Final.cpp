#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

char map[17][20];
int xp1 = 15;
int yp1 = 1;
int xp2 = 15;
int yp2 = 1;
int m = 0;
void generateMapP1(char map[][20], int R, int C);
void generateMapP2(char map[][20], int R, int C);
void displayMap(char map[][20]);
void welcome();
void movePlayers1(int m, int *xp1, int *yp1);
void movePlayers2(int m, int *xp1, int *yp1);
void player1Win();
void player2Win();
void fullscreen();

int main(){
	
	fullscreen();
	srand(time(NULL));
	
	generateMapP1(map,17,20);
	welcome();
	printf("\n\nPress Enter to continue...");
	getch();
	system("cls");
	
	int runApp = 1;
	
	while(runApp == 1) {
		int runMenu = 1;
		int menu;
		
		while(runMenu == 1) {
			printf("   Menu\n");
			for(int i = 0; i < 12; i++){
				printf("%c", 205);
			}
			puts("");
			printf("1. Play game\n");
			printf("2. Exit\n");
			printf("Choose menu [1]/[2]: ");
//			scanf("%d", &menu);
			menu = getch() - '0';
			
			getchar();
			
			system("cls"); // clear screen terminal
			
			if(menu == 1){
				runMenu = 0;
				
				break;
			} else if(menu == 2){
				system("cls");
				printf("\n\033[1m Goodbye!\033[0m\n");
				getch();
				return 0;
			} else {
				printf("\n Wrong Input!\n");
			}
		}
		
			int p;
			generateMapP1(map,17,20);
			displayMap(map);
			printf("\033[7m\n RULES & INFORMATION:\033[0m\n");
			printf("- \033[4mEvery single row has 18 blocks\033[0m\n");
			printf("\033[2mA = go down to row 8, block 4\n");
			printf("B = climb up to row 1, block 6\n");
			printf("C = go down to row 4, block 2\n");
			printf("D = climb up to row 2, block 9\n");
			printf("E = go down to row 7, block 7\n");
			printf("F = climb up to row 3, block 2\n");
			printf("G = go down to row 8, block 6\033[0m\n");
			printf("\n\n\nWhose turn? \033[31;5m[1]\033[0m\033[5m /\033[0m \033[34;5m[2]\033[0m \n");
			printf(">> ");
//			scanf("%d", &p);
			p = getch() - '0';
			m = rand() % 10 + 1;
		
		switch(menu) {
			case 1: { 
			
				
				int runGame = 1;
				while(runGame){
					if(p == 1){
						if(xp1 == 1 & yp1 == 1){
							system("cls");
							player1Win();
							getch();
							return 0;
						}else if(xp2 == 1 && yp2 == 1){
							system("cls");
							player2Win();
							getch();
							return 0;
						} else {
							system("cls");
							movePlayers1(m, &xp1, &yp1);
							generateMapP1(map,17,20);
							displayMap(map);
							printf("\033[7m\n RULES & INFORMATION:\033[0m\n");
							printf("- \033[4mEvery single row has 18 blocks\033[0m\n");
							printf("\033[2mA = go down to row 8, block 4\n");
							printf("B = climb up to row 1, block 6\n");
							printf("C = go down to row 4, block 2\n");
							printf("D = climb up to row 2, block 9\n");
							printf("E = go down to row 7, block 7\n");
							printf("F = climb up to row 3, block 2\n");
							printf("G = go down to row 8, block 6\033[0m\n");
							printf("\n\033[31m1st player\033[0m move >> ");
	                        printf("%d box\n", m);
							printf("\nWhose turn? \033[31;5m[1]\033[0m\033[5m /\033[0m \033[34;5m[2]\033[0m \n");
							printf(">> ");
							m = rand() % 10 + 1;
//							scanf("%d", &p);
							p = getch() - '0';
						}
					} else if(p == 2){
						
						if(xp1 == 1 & yp1 == 1){
							system("cls");
							player1Win();
							getch();
							return 0;
						}else if(xp2 == 1 && yp2 == 1){
							system("cls");
							player2Win();
							getch();
							return 0;
						} else {
							system("cls");
							movePlayers2(m, &xp2, &yp2);
							generateMapP2(map,17,20);
							displayMap(map);
							printf("\033[7m\n RULES & INFORMATION:\033[0m\n");
							printf("- \033[4mEvery single row has 18 blocks\033[0m\n");
							printf("\033[2mA = go down to row 8, block 4\n");
							printf("B = climb up to row 1, block 6\n");
							printf("C = go down to row 4, block 2\n");
							printf("D = climb up to row 2, block 9\n");
							printf("E = go down to row 7, block 7\n");
							printf("F = climb up to row 3, block 2\n");
							printf("G = go down to row 8, block 6\033[0m\n");
							printf("\n\033[34m2nd player\033[0m move >> ");
	                        printf("%d box\n", m);
							printf("\nWhose turn? \033[31;5m[1]\033[0m\033[5m /\033[0m \033[34;5m[2]\033[0m \n");
							printf(">> ");
							m = rand() % 10 + 1;
//							scanf("%d", &p);
							p = getch() - '0';
						}
						
					} else {
						if(xp1 == 1 & yp1 == 1){
							system("cls");
							player1Win();
							getch();
							return 0;
						}else if(xp2 == 1 && yp2 == 1){
							system("cls");
							player2Win();
							getch();
							return 0;
						} else {
							system("cls");
							generateMapP1(map,17,20);
							displayMap(map);
							printf("\033[7m\n RULES & INFORMATION:\033[0m\n");
							printf("- \033[4mEvery single row has 18 blocks\033[0m\n");
							printf("\033[2mA = go down to row 8, block 4\n");
							printf("B = climb up to row 1, block 6\n");
							printf("C = go down to row 4, block 2\n");
							printf("D = climb up to row 2, block 9\n");
							printf("E = go down to row 7, block 7\n");
							printf("F = climb up to row 3, block 2\n");
							printf("G = go down to row 8, block 6\033[0m\n");
							printf("\nInvalid input!\n");
							printf("\nWhose turn? \033[31;5m[1]\033[0m\033[5m /\033[0m \033[34;5m[2]\033[0m \n");
							printf(">> ");
							m = rand() % 10 + 1;
//							scanf("%d", &p);
							p = getch() - '0';
						}
					}
				}
				break;
			}
			
			case 2: { // 2. Exit
				runApp = 0;
				
				break;
			}
		}
		
	}
	return 0;
}
void generateMapP1(char map[][20], int R, int C){
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(i == 0 && j < 20){
				map[i][j] = 205;
			} else if(i == 16 && j < 20){
				map[i][j] = 205;
			} else if(j == 0 && i < 16){
				map[i][j] = 186;
			} else if(j == 19 && i < 16){
				map[i][j] = 186;
			}
			else {
				map[i][j] = 178;
			}
		}
		
		// corner
		map[0][0] = 201;
		map[0][19] = 187;
		map[16][0] = 200;
		map[16][19] = 188;
		
		//baris 1
		map[2][0] = 204;
		for(int k = 1; k < 17; k++){
			map[2][k] = 205;
		}
		
		//baris 2
		map[4][19] = 185;
		for(int k = 3; k < 19; k++){
			map[4][k] = 205;
		}
		
		//baris 3
		map[6][0] = 204;
		for(int k = 1; k < 17; k++){
			map[6][k] = 205;
		}
		
		//baris 4
		map[8][19] = 185;
		for(int k = 3; k < 19; k++){
			map[8][k] = 205;
		}
		
		//baris 5
		map[10][0] = 204;
		for(int k = 1; k < 17; k++){
			map[10][k] = 205;
		}
		
		//baris 6
		map[12][19] = 185;
		for(int k = 3; k < 19; k++){
			map[12][k] = 205;
		}
		
		//baris 7
		map[14][0] = 204;
		for(int k = 1; k < 17; k++){
			map[14][k] = 205;
		}
		map[1][3] = 'A'; //SNAKE
		map[3][10] = 'B'; //LADDER
		map[5][5] = 'C'; //SNAKE
		map[7][13] = 'D'; //LADDER
		map[9][8] = 'E'; //SNAKE
		map[11][4] = 'F'; //LADDER
		map[13][7] = 'G'; //SNAKE
		map[xp1][yp1] = '1';
		
	}
}
void generateMapP2(char map[][20], int R, int C){
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(i == 0 && j < 20){
				map[i][j] = 205;
			} else if(i == 16 && j < 20){
				map[i][j] = 205;
			} else if(j == 0 && i < 16){
				map[i][j] = 186;
			} else if(j == 19 && i < 16){
				map[i][j] = 186;
			}
			else {
				map[i][j] = 178;
			}
		}
		
		// corner
		map[0][0] = 201;
		map[0][19] = 187;
		map[16][0] = 200;
		map[16][19] = 188;
		
		//baris 1
		map[2][0] = 204;
		for(int k = 1; k < 17; k++){
			map[2][k] = 205;
		}
		
		//baris 2
		map[4][19] = 185;
		for(int k = 3; k < 19; k++){
			map[4][k] = 205;
		}
		
		//baris 3
		map[6][0] = 204;
		for(int k = 1; k < 17; k++){
			map[6][k] = 205;
		}
		
		//baris 4
		map[8][19] = 185;
		for(int k = 3; k < 19; k++){
			map[8][k] = 205;
		}
		
		//baris 5
		map[10][0] = 204;
		for(int k = 1; k < 17; k++){
			map[10][k] = 205;
		}
		
		//baris 6
		map[12][19] = 185;
		for(int k = 3; k < 19; k++){
			map[12][k] = 205;
		}
		
		//baris 7
		map[14][0] = 204;
		for(int k = 1; k < 17; k++){
			map[14][k] = 205;
		}
		
//		map[1][5] = 178;
		map[1][3] = 'A'; //SNAKE
		map[3][10] = 'B'; //LADDER
		map[5][5] = 'C'; //SNAKE
		map[7][13] = 'D'; //LADDER
		map[9][8] = 'E'; //SNAKE
		map[11][4] = 'F'; //LADDER
		map[13][7] = 'G'; //SNAKE
		map[xp2][yp2] = '2';
		
	}
}
void displayMap(char map[][20]){
	for(int i = 0; i < 17; i++){
		for(int j = 0; j < 20; j++){
			if (i == xp1 && j == yp1) {
                printf("\033[31;5;7m%c\033[0m", map[i][j]);
            } else if (i == xp2 && j == yp2) {
                printf("\033[34;5;7m%c\033[0m", map[i][j]);
            } else if(i == 1 && j == 3){
            	printf("\033[33m%c\033[0m", map[i][j]);
			} else if(i == 3 && j == 10){
				printf("\033[32m%c\033[0m", map[i][j]);
			} else if(i == 5 && j == 5){
				printf("\033[33m%c\033[0m", map[i][j]);
			} else if(i == 7 && j == 13){
				printf("\033[32m%c\033[0m", map[i][j]);
			} else if(i == 9 && j == 8){
				printf("\033[33m%c\033[0m", map[i][j]);
			} else if(i == 11 && j == 4){
				printf("\033[32m%c\033[0m", map[i][j]);
			} else if(i == 13 && j == 7){
				printf("\033[33m%c\033[0m", map[i][j]);
			} else {
                printf("%c", map[i][j]);
            }
		}
		printf("\n");
	}
}
void welcome(){
	printf("                                      \n");
	printf("\033[31m __      __   ___    ____     _____    \n");
    printf(" \\ \\    / /  / _ \\  |  _ \\   |  __ \\  \n");
    printf(" \033[32m \\ \\  / /  / | | \\ | |_| \\  | |  ) ) \n");
    printf("   \\ \\/ /   \\ |_| / |  _  /  | |_/ /  \n");
    printf(" \033[34m   \\__/     \\___/  |_| |_|  |____/\033[0m   \n");

    printf("\033[37;5m\nWelcome to the Snake and Ladder Game!\033[0m\n");
}
void movePlayers1(int m, int *xp1, int *yp1){
	
    for (int i = 0; i < m; i++) {
    	if(*xp1 == 1 && (*yp1 - m) < 1){
    		continue;
		} else {
	    	//baris 8
	        if (*xp1 == 15 && *yp1 < 18) {
	            (*yp1)++;
	        } 
			else if (*xp1 == 15 && *yp1 == 18) {
	            (*xp1)--;
	        } 
			else if (*xp1 == 14 && *yp1 == 18) {
	            (*xp1)--;
	        } 
	        //baris 7
			else if(*xp1 == 13 && *yp1 <= 18 && *yp1 > 1) {
	        	(*yp1)--;
			} 
			else if(*xp1 == 13 && *yp1 < 1){
				(*yp1) = 1;
			} 
			else if(*xp1 == 13 && *yp1 == 1){
				(*xp1)--;
			}
			//baris 6
			else if(*xp1 == 12 && *yp1 == 1){
				(*xp1)--;
			}
			else if(*xp1 == 11 && *yp1 == 1){
				(*yp1)++;
			}
			else if(*xp1 == 11 && *yp1 > 1 && *yp1 < 18){
				(*yp1)++;
			}
			else if(*xp1 == 11 && *yp1 > 18){
				(*yp1) = 18;
			}
			else if(*xp1 == 11 && *yp1 == 18){
				(*xp1)--;
			}
			else if(*xp1 == 10 && *yp1 == 18){
				(*xp1)--;
			}
			//baris 5
			else if(*xp1 == 9 && *yp1 <= 18 && *yp1 > 1) {
	        	(*yp1)--;
			} 
			else if(*xp1 == 9 && *yp1 < 1){
				(*yp1) = 1;
			} 
			else if(*xp1 == 9 && *yp1 == 1){
				(*xp1)--;
			}
			else if(*xp1 == 8 && *yp1 == 1){
				(*xp1)--;
			}
			//baris 4
			else if(*xp1 == 7 && *yp1 == 1){
				(*yp1)++;
			}
			else if(*xp1 == 7 && *yp1 > 1 && *yp1 < 18){
				(*yp1)++;
			}
			else if(*xp1 == 7 && *yp1 > 18){
				(*yp1) = 18;
			}
			else if(*xp1 == 7 && *yp1 == 18){
				(*xp1)--;
			}
			else if(*xp1 == 6 && *yp1 == 18){
				(*xp1)--;
			}
			//baris 3
			else if(*xp1 == 5 && *yp1 <= 18 && *yp1 > 1) {
	        	(*yp1)--;
			} 
			else if(*xp1 == 5 && *yp1 < 1){
				(*yp1) = 2;
			} 
			else if(*xp1 == 5 && *yp1 == 1){
				(*xp1)--;
			}
			else if(*xp1 == 4 && *yp1 == 1){
				(*xp1)--;
			}
			//baris 2
			else if(*xp1 == 3 && *yp1 == 1){
				(*yp1)++;
			}
			else if(*xp1 == 3 && *yp1 > 1 && *yp1 < 18){
				(*yp1)++;
			}
			else if(*xp1 == 3 && *yp1 > 18){
				(*yp1) = 18;
			}
			else if(*xp1 == 3 && *yp1 == 18){
				(*xp1)--;
			}
			else if(*xp1 == 2 && *yp1 == 18){
				(*xp1)--;
			}
			//baris 1
			else if(*xp1 == 1 && *yp1 <= 18 && *yp1 > 1) {
	        	(*yp1)--;
			} 
		}
    }
    
    if(*xp1 == 1 && *yp1 == 3){
    	*xp1 = 15;
    	*yp1 = 5;
	}else if(*xp1 == 3 && *yp1 == 10){
		*xp1 = 1;
		*yp1 = 7;
	}else if(*xp1 == 5 && *yp1 == 5){
		*xp1 = 7;
		*yp1 = 3;
	}else if(*xp1 == 7 && *yp1 == 13){
		*xp1 = 3;
		*yp1 = 10;
	}else if(*xp1 == 9 && *yp1 == 8){
		*xp1 = 13;
		*yp1 = 8;
	}else if(*xp1 == 11 && *yp1 == 4){
		*xp1 = 5;
		*yp1 = 2;
	}else if(*xp1 == 13 && *yp1 == 7){
		*xp1 = 15;
		*yp1 = 10;
	}
    
}
void movePlayers2(int m, int *xp2, int *yp2){
	
    for (int i = 0; i < m; i++) {
    	//baris 8
    	if(*xp2 == 1 && (*yp2 - m) < 1){
			continue;
		} else {
			if (*xp2 == 15 && *yp2 < 18) {
	            (*yp2)++;
	        } 
			else if (*xp2 == 15 && *yp2 == 18) {
	            (*xp2)--;
	        } 
			else if (*xp2 == 14 && *yp2 == 18) {
	            (*xp2)--;
	        } 
	        //baris 7
			else if(*xp2 == 13 && *yp2 <= 18 && *yp2 > 1) {
	        	(*yp2)--;
			} 
			else if(*xp2 == 13 && *yp2 < 1){
				(*yp2) = 2;
			} 
			else if(*xp2 == 13 && *yp2 == 1){
				(*xp2)--;
			}
			//baris 6
			else if(*xp2 == 12 && *yp2 == 1){
				(*xp2)--;
			}
			else if(*xp2 == 11 && *yp2 == 1){
				(*yp2)++;
			}
			else if(*xp2 == 11 && *yp2 > 1 && *yp2 < 18){
				(*yp2)++;
			}
			else if(*xp2 == 11 && *yp2 > 18){
				(*yp2) = 18;
			}
			else if(*xp2 == 11 && *yp2 == 18){
				(*xp2)--;
			}
			else if(*xp2 == 10 && *yp2 == 18){
				(*xp2)--;
			}
			//baris 5
			else if(*xp2 == 9 && *yp2 <= 18 && *yp2 > 1) {
	        	(*yp2)--;
			} 
			else if(*xp2 == 9 && *yp2 < 1){
				(*yp2) = 2;
			} 
			else if(*xp2 == 9 && *yp2 == 1){
				(*xp2)--;
			}
			else if(*xp2 == 8 && *yp2 == 1){
				(*xp2)--;
			}
			//baris 4
			else if(*xp2 == 7 && *yp2 == 1){
				(*yp2)++;
			}
			else if(*xp2 == 7 && *yp2 > 1 && *yp2 < 18){
				(*yp2)++;
			}
			else if(*xp2 == 7 && *yp2 > 18){
				(*yp2) = 18;
			}
			else if(*xp2 == 7 && *yp2 == 18){
				(*xp2)--;
			}
			else if(*xp2 == 6 && *yp2 == 18){
				(*xp2)--;
			}
			//baris 3
			else if(*xp2 == 5 && *yp2 <= 18 && *yp2 > 1) {
	        	(*yp2)--;
			} 
			else if(*xp2 == 5 && *yp2 < 1){
				(*yp2) = 1;
			} 
			else if(*xp2 == 5 && *yp2 == 1){
				(*xp2)--;
			}
			else if(*xp2 == 4 && *yp2 == 1){
				(*xp2)--;
			}
			//baris 2
			else if(*xp2 == 3 && *yp2 == 1){
				(*yp2)++;
			}
			else if(*xp2 == 3 && *yp2 > 1 && *yp2 < 18){
				(*yp2)++;
			}
			else if(*xp2 == 3 && *yp2 > 18){
				(*yp2) = 18;
			}
			else if(*xp2 == 3 && *yp2 == 18){
				(*xp2)--;
			}
			else if(*xp2 == 2 && *yp2 == 18){
				(*xp2)--;
			}
			//baris 1
			else if(*xp2 == 1 && *yp2 <= 18 && *yp2 > 1) {
				(*yp2)--;
			}
		}
    }
    
    if(*xp2 == 1 && *yp2 == 3){
    	*xp2 = 15;
    	*yp2 = 5;
	}else if(*xp2 == 3 && *yp2 == 10){
		*xp2 = 1;
		*yp2 = 7;
	}else if(*xp2 == 5 && *yp2 == 5){
		*xp2 = 7;
		*yp2 = 3;
	}else if(*xp2 == 7 && *yp2 == 13){
		*xp2 = 3;
		*yp2 = 10;
	}else if(*xp2 == 9 && *yp2 == 8){
		*xp2 = 13;
		*yp2 = 8;
	}else if(*xp2 == 11 && *yp2 == 4){
		*xp2 = 5;
		*yp2 = 2;
	}else if(*xp2 == 13 && *yp2 == 7){
		*xp2 = 15;
		*yp2 = 10;
	}
	
}
void player1Win(){
	printf(" \033[31m                                                          _       _\033[0m\n");
	printf(" \033[31m _____                                    ______         | |  _  | |\033[0m\n");
	printf(" \033[31m|  _  |_                                 /_/ | |         | | | | | |       _\033[0m\n");
	printf(" \033[31m| |_| | |  ____ __   __ _____________        | |         | | | | | |______| /____\033[0m\n");
	printf(" \033[31m|  ___| | |  _ |  | |  |  _____| ____\\       | |         | |_| |_| |  _   |  __  |\033[0m\n");
	printf(" \033[31m| |   | |_|    |  |_|  |  _____| |           | |         |         |  |   | |  | |\033[0m\n");
	printf(" \033[31m|_|   |___|__|_|____   |_______|_|           |_|         |_________|______|_|  |_|\033[0m\n");
	printf(" \033[31m                    |  |\033[0m\n");
	printf(" \033[31m                  __|  |\033[0m\n");
	printf(" \033[31m                 |_____|\033[0m\n\n");
	printf("\t\t\t\t    Thankyou\n\n");
	printf("\t\t\tPress any key to exit the game...");
}
void player2Win(){
	printf(" \033[34m                                           _______      _       _\033[0m\n");
	printf(" \033[34m _____                                    / ___   |    | |  _  | |\033[0m\n");
	printf(" \033[34m|  _  |_                                 /_/   / /     | | | | | |       _\033[0m\n");
	printf(" \033[34m| |_| | |  ____ __   __ _____________         / /      | | | | | |______| /____\033[0m\n");
	printf(" \033[34m|  ___| | |  _ |  | |  |  _____| ____\\       / /       | |_| |_| |  _   |  __  |\033[0m\n");
	printf(" \033[34m| |   | |_|    |  |_|  |  _____| |          / /____    |         |  |   | |  | |\033[0m\n");
	printf(" \033[34m|_|   |___|__|_|____   |_______|_|         /_______|   |_________|______|_|  |_|\033[0m\n");
	printf(" \033[34m                    |  |\033[0m\n");
	printf(" \033[34m                  __|  |\033[0m\n");
	printf(" \033[34m                 |_____|\033[0m\n\n");
	printf("\t\t\t\t    Thankyou\n\n");
	printf("\t\t\tPress any key to exit the game...");
}
void fullscreen(){
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
