#include<stdio.h>
void addProduct(char*[]);
void removeProduct(void);
void search(void);
void readFile(void);
FILE *fptr;

typedef struct product
{
    char product_name[100];
    int id;
    int quantity;
    float price;

}Product;

int main(){
    char product_name[100];
    float price;
    int id, quantity;
    Product product;

    fptr = fopen("../database/products.txt","+r");

    if (fptr == NULL)
    {
        printf("Bhai lund");
    }
    while(fread(&product, sizeof(Product), 1, fptr)) 
    {
        printf("Name : %s, Quantity : %d, Price : %f, id : %d",product_name, quantity, price, id);
        printf("Current position: %ld  \n", ftell(fptr));

    }
    fscanf(fptr, "%[^,],%d,%f,%d", product_name, &quantity, &price, &id);
    printf("Name : %s, Quantity : %d, Price : %f, id : %d",product_name, quantity, price, id);


    fclose(fptr);
    return 0;
}


// Add new products
void addProduct(char *a[]) {
    printf("%s\n", a);
}

// Remove Products from Database
void removeProduct() {

}

void readFile() {

}

// Search Function
void search() {

}