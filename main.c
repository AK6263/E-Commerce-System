#include<stdio.h>
void addProduct(char*[]);
void removeProduct(void);
void search(void);


int main(){
    int option = 1;
    char a[10] = "bruh";
    printf("Enter the option\n[1] add product\n[2] remove product\n[3] Search for product\n");
    switch (option) {
        case 1:
            addProduct(a);
            break;
        case 2:
            removeProduct();
            break;
        case 3:
            search();
            break;
        default:
            break;
    }
    addProduct(a);

    return 0;
}


// Add new products
void addProduct(char *a[]) {
    printf("%s\n", a);
}

// Remove Products from Database
void removeProduct() {

}

// Search Function
void search() {

}