void printcatalogue(void);
void search(void);
void addtocart(int i, int q);
void printcart(void);
void displayProduct(void);

// ADD TO CART
void addtocart(int i, int q) {
    FILE *fp, *fptr;
    struct product b;
    char buf[1000];
    char true;
    fp = fopen("products.txt","r");
    fptr = fopen("cart.txt","a");
    while(fscanf(fp, "%d %s %d %f", &p_1.id, p_1.product_name, &p_1.quantity, &p_1.price)==4) {
        if (p_1.id == i)
        {
            fprintf(fptr,"%-1d %-1s %1d %1f\n", p_1.id, p_1.product_name, q, p_1.price);
            gotoxy(10,36);
            printf("Item added to the cart\n\n");
        }
    }
    fclose(fptr);
    fclose(fp);
}

//  USER MENU
void user_menu() {
    int choice;
    char options[4][30] = {
        "MAIN MENU",
        "[1] View Catalogue",
        "[2] Search Products",
        "[3] Close Application"
    };
    
    do
    {
        system(CLEAR);
        for (int i = 0; i < 3; i++) {
            gotoxy(20,i + 3);
            printf("%s",options[i]);
        }
        gotoxy(20,13);
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                display();
                break;
            case 2:
                search();
                break;
            default:
                choice = 0;
                break;
        }
    } while (choice != 0);
}

// DISPLAY PRODUCT : Using display() from admin function
void displayProduct() {
    display();
}

void printcart() {
    return;
}