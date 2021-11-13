#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
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

