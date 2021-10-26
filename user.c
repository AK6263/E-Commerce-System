#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

int printcatalogue(void);
int search(void);
int printcatalogue(void);

struct product {
    int quantity, reorder, i, id;
    char name[20];
    float price;
};


// gotoxy() function definition
void gotoxy(int x, int y){
    printf("%c[%d;%df", 0x1B, y, x);
}


int getch(void){
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}


int getche(void){
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}


void usermenu(){
    system("clear");
    gotoxy(27,3);
    printf("MAIN MENU ");
    gotoxy(20,5);
    printf(" 1. View catalogue  ");
    gotoxy(20,7);
    printf(" 2. Search Products ");
    gotoxy(20,9);
    printf(" 3. Close Application");
    gotoxy(20,13);
    printf("Enter your choice:");
    switch(getche())
    {
    case '1':
    displayProduct();
    break;
    case '2':
    search();
    break;
    case '3':
    {
    system("clear");
    exit(0);
    }
    default:
    {
    gotoxy(10,23);
    printf("\aWrong Entry!!Please re-entered correct option");
    if(getch())
    usermenu();
    }

    }
}


int search(){
    system("clear");
    return 0;
}


int displayProduct() {
    FILE *fp;
    struct product a;

    char true;
    system("clear");

    fp = fopen("products.txt", "r");

    gotoxy(17, 5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Product catalogue \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(5, 6);
    printf("======================================================================");

    gotoxy(5, 7);
    printf("Product ID\t\t Product Name\t\t Quantity\t Unit Price\n"); //TABLE TITLES !

    gotoxy(5, 8);
    printf("======================================================================");

    gotoxy(0,10);
                while(fscanf(fp, "%d %s %d %f", &a.id, a.name, &a.quantity, &a.price)==4)
                {
                printf("\t%-10d\t %-12s\t\t %8d\t %8.2f\n\n", a.id, a.name, a.quantity, a.price);
                }

                fclose(fp);

    printf("\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\nPress any key to return to Main Menu.");

    getch();

    usermenu();

    return (0);
}



int main(){   
    //char product_name[100];
    //float price;
    //int id, quantity;
    //Product product;
    usermenu();
    return 0;
}
