#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
//#include<graphic.h>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
FILE *fptr,*fp,*ft;

typedef struct product
{
    char product_name[20];
    int id;
    int quantity;
    float price;
    char description[100];
}Product;


Product *p;
Product p_1;

void gotoxy(int x, int y) {
    printf("%c[%d;%df", 0x1B, y, x);
}

int check_id(int id) {
    int flag = 0;
    fp = fopen("products.dat", "r");
    while(fread(&p_1, sizeof(Product), 1, fp)) {
        if (p_1.id == id) {
            flag = 1;
        }
    }
    fclose(fp);
    return flag;
}

#include "admin_functions.h"

int no_of_product() {
    /*
        Get the id of the last product so you can 
        put the id automatically instead of asking
    */
    return 0;
}

void search() {
    system(CLEAR);
}
int addtocart(int i, int q) {
    FILE *fp, *fptr;
    struct product b;
    char buf[1000];
    char true;
    fp = fopen("products.txt","r");
    fptr = fopen("cart.txt","a");
    fclose(fptr);
    fclose(fp);
}

// ADMIN_MENU
void admin_menu () {
	int choice, i;
	int left = 1, top = 1, right = 200, bottom = 100;
	
    do
    {
    	char options[9][50] = {
			"Welcome to the E-Commerce Application",
			"[1] CREATE\n",
			"[2] DISPLAY\n",
			"[3] APPEND\n",
			"[4] NO OF PRODUCT\n",
			"[5] SEARCH PRODUCT\n",
       		"[6] UPDATE PRODUCT\n",
			"[7] DELETE PRODUCT\n",
			"[0] EXIT\n"
		};
        system(CLEAR);
        
		for(i = 0; i < 9; i++){
			if(i == 0)
				gotoxy(20,i+4);
			else
				gotoxy(10,i+5);
			printf("%s",options[i]);
		}
		gotoxy(20,10 + 5);
        printf("Enter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                new_append();
                break;
            case 4:
                no_of_product();
                break;
            case 5:
                search_product();
                break;
            case 6:
                update_product();
                break;
            case 7:
                delete_product();
                break;
        }
    } while (choice != 0 );
}

void usermenu() {
    int choice;
    char options[4][30] = {
        "MAIN MENU",
        "[1] View Catalogue",
        "[2] Search Products",
        "[3] Close Application"
    };
    system(CLEAR);
    do
    {
        for (int i = 0; i < 3; i++) {
            gotoxy(20,i + 3);
            printf("%s",options[i]);
        }
        gotoxy(20,13);
        printf("Enter your choice : ");

        switch (getche())
        {
            case '1':
                display();
                break;
            case '2':
                search();
                break;
            default:
                choice = 0;
                break;
        }
    } while (choice != 0);
}

int main()
{   
    admin_menu();
    // usermenu();
    return 0;
}
