int printcatalogue(void);
int search(void);
int addtocart(int i, int q);
int printcart(void);
int displayProduct(void);

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
    printf("\nWrong Entry!!Please re-entered correct option");
    if(getch())
    usermenu();
    }

    }
}

int search(){
    system("clear");
    Product p_1;
    FILE *fp;
    char n[30];
    int id,value, found = 0;
    fp = fopen("products.dat","r");
    gotoxy(20,3);
    printf("Enter the Product name to Search : ");
    scanf("%[^\n]s",n);
    int choice;
    //scanf("%d", &id);

    while (fread(&p_1,sizeof(Product), 1,fp))
    {
        value=strcmp(n,p_1.product_name);
        if (value==0) {
            found = 1;
            //printf("%-5d|%-20s|%-50s|%8.2f|%4d\n", p_1.id, p_1.product_name, p_1.description, p_1.price, p_1.quantity);
            gotoxy(0, 5);
            printf("    ::::::::::::::::::::::::::::::::::: Product catalogue :::::::::::::::::::::::::::::::::::::::::::::::::::::");

            gotoxy(5, 6);
            printf("===========================================================================================================");

            gotoxy(5, 7);
            printf("Product ID\t\tProduct Name\t\tQuantity\t  Price\t        Description"); //TABLE TITLES !

            gotoxy(5, 8);
            printf("===========================================================================================================");
            gotoxy(5,9);
            printf("\n\t%-2d\t\t%-20s\t%4d\t\t%8.2f\t%-50s", p_1.id, p_1.product_name,p_1.quantity, p_1.price, p_1.description);

            gotoxy(5,13);
            printf("1. Add product to the cart");
            gotoxy(5,15);
            printf("2. View product catalogue");
            gotoxy(5,17);
            printf("3. Go back to main menu");
            gotoxy(5,19);
            printf("Enter your choice: ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:{
                goto Cleanup;
                Cleanup:;
                int quantity;
                //printf("Product id: ");
                //scanf("%d",&id);
                gotoxy(10,21);
                printf("Quantity: ");
                scanf("%d",&quantity);
                addtocart(p_1.id,quantity);
                break;
                }
                case 2:{
                goto Cleanup1;
                Cleanup1:;
                displayProduct();
                break;
                }
                case 3:{
                goto Cleanup2;
                Cleanup2:;
                usermenu();
                break;
                }
                case 4:
                {
                goto Cleanup3;
                Cleanup3:;
                system("clear");
                usermenu();
                }
                default:
                {
                goto Cleanup4;
                Cleanup4:;
                gotoxy(10,32);
                printf("\aWrong Entry!!Please re-entered correct option ");
                if(getch())
                displayProduct();
                }

            }
        }
    }
    if(!found) {
        printf("\nProduct not found\n");
        //sleep(2);
        //goto Cleanup5;
        //Cleanup5:;
        //search();
    }
    fclose(fp);
    /*
    int flag = 0;
    printf("Go Back (1 = Yes, 0 = No) : ");
    scanf("%d",&flag); while (!flag)
    {
        scanf("%d",&flag);
    }
    */
    return 0;
}
int printcart(){
    FILE *fp;
    struct product a;
    char line[200];

    char true;
    system("clear");

    fp = fopen("cart.csv", "r");

    gotoxy(0, 5);
    printf("::::::::::::::::::::::::::::::::::: Cart :::::::::::::::::::::::::::::::::::::::::::::::::::::");

    gotoxy(0, 7);
    printf("==============================================================================================");

    gotoxy(0, 8);
    printf("Product ID\t  Product Name\t       Quantity\t           Price\t\t Description"); //TABLE TITLES !

    gotoxy(0, 9);
    printf("==============================================================================================");

    gotoxy(5,10);
                while (fgets(line,sizeof(line),fp))
                {
                    char *token;
                    token = strtok(line, ",");
                    while (token!= NULL) 
                    {
                        printf ("%-20s", token);
                        token = strtok(NULL, ",");
                    }
                    printf("\n");
                }            

                fclose(fp);
}

int addtocart(int i, int q){
    FILE *fp, *fptr;
    int n,j;
    struct product a;
    Product *p;
    p = (Product*)calloc(n, sizeof(Product));
    fp = fopen("products.dat","r");
    fptr = fopen("cart.csv","a");
    

            while (fread(&a,sizeof(Product), 1,fp))
                {
                    
                    if (a.id==i){
                    fprintf(fptr,"%-1d,%-1s,%1d,%1f,%-1s\n", a.id, a.product_name, q, a.price, a.description);
                    
                    }
                    
                    //gotoxy(5,36);
                    
                    /*
                    else{
                        printf("\nEnter valid id");
                        displayProduct();
                    }*/
                }
                printf("\n\nItem added to cart\n\n");
    fclose(fp);
    fclose(fptr);
        
        
        switch(getche())
        {
        default:
        {
        //gotoxy(10,38);
        printf("\n\nPress any key to go back");
        if(getch())
        displayProduct();
        }

        }
                //if(getch())
                //displayProduct();

    

    return 0;
}

int displayProduct() {
    FILE *fp;
    struct product a;

    char true;
    system("clear");

    fp = fopen("products.dat", "rb");

    gotoxy(0, 5);
    printf("::::::::::::::::::::::::::::::::::: Product catalogue :::::::::::::::::::::::::::::::::::::::::::::::::::::");

    gotoxy(5, 6);
    printf("==============================================================================================");

    gotoxy(5, 7);
    printf("Product ID\t\tProduct Name\t\tQuantity\t  Price\t        Description"); //TABLE TITLES !

    gotoxy(5, 8);
    printf("==============================================================================================");

    gotoxy(5,9);
                while (fread(&a,sizeof(Product), 1,fp))
                {
                printf("\n\t%-2d\t\t%-20s\t%4d\t\t%8.2f\t%-50s", a.id, a.product_name,a.quantity, a.price, a.description);
                }
                

                fclose(fp);

    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");

    gotoxy(5,22);
    printf("1. Enter product id to add to cart");
    gotoxy(5,24);
    printf("2. Search");
    gotoxy(5,26);
    printf("3. View cart");
    gotoxy(5,28);
    printf("4. Go back to main menu");
    gotoxy(5,31);
    printf("Enter your choice: ");

    switch(getche())
    {
    case '1':
    goto Cleanup;
    Cleanup:;
    int id, quantity;
    gotoxy(10,33);
    printf("Product id: ");
    scanf("%d",&id);
    gotoxy(10,34);
    printf("Quantity: ");
    scanf("%d",&quantity);
    addtocart(id,quantity);
    break;
    case '2':
    search();
    break;
    case '3':
    printcart();
    break;
    case '4':
    {
    system(CLEAR);
    usermenu();
    }
    default:
    {
    gotoxy(10,32);
    printf("\aWrong Entry!!Please re-entered correct option ");
    if(getch())
    displayProduct();
    }

    }

    return (0);
}
