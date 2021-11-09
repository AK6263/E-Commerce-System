// ADD TO CART
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

//  USER MENU
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