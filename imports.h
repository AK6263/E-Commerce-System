#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>

#include <unistd.h>

#ifdef _WIN32
    #define CLEAR "cls"
    #include "conio.h"
#else
#include <termios.h>
    #define CLEAR "clear"
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

struct cart_item{
    char item_name[20];
    char description[100];
    float price;
    int qty, id;
};

struct invoice
{
    char customer_name[30];
    char date[50];
    char description[100];
    int numOfItems;
    float total;
    struct cart_item items[10];
};
