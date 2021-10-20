#include<stdio.h>
void addProduct();
void removeProduct(void);
void search(void);


int main(){
    int option;
    char a[10] = "bruh";
    printf("Enter the option\n [1] add product\n [2] remove product\n [3] search for product");
    // scanf("%d", &option);
    addProduct(*a);

    return 0;
}


// Add new products
void addProduct(char *a[]) {
    puts(*a);
}

// Remove Products from Database
void removeProduct() {

}

// Search Function
void search() {

}