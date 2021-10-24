#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

COORD coord = {0,0};

void gotoxy(int x,int y){
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(){
	int i,j,k;
	for(i=0;i<14;i++){
		for(j=0;j<31;j++){
			if(i==0){
				if(j%2==0){
					printf("*");
				}
				else{
					printf(" ");
				}
			}
			else{
				if(j==0 || j==30){
					printf("*");
				}
				else{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	gotoxy(10,2);
	printf(" MAIN MENU \n");
	gotoxy(4,4);
	printf(" 1. Add Product\n");
	gotoxy(4,5);
	printf(" 2. Delete Product\n");
	gotoxy(4,6);
	printf(" 3. Update Product\n");
	gotoxy(4,7);
	printf(" 4. Search Product\n");
	gotoxy(4,8);
	printf(" 5. View Product list\n");
	gotoxy(4,9);
	printf(" 6. Close Application\n\n");
	for(j=0;j<31;j++){
		if(j%2==0){
			printf("*");
		}
		else{
			printf(" ");
		}
	}
	return 0;	
}
