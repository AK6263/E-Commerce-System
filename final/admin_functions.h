void admin_menu();
// CREATE FUNCTION
void create() {
    char temp[2];
    int n, i, j;

    printf("\nEnter the number of products you be added : \n");
    scanf("%d",&n);

    p = (Product*)calloc(n, sizeof(Product));
    fptr = fopen("products.dat","w");
    for (i = 0; i < n; i++)
    {
        printf("Enter ID : ");
        scanf("%d",&p[i].id);
        scanf("%c",temp);
        printf("Enter Name : ");
        scanf("%[^\n]s", p[i].product_name);
        scanf("%c",temp);
        printf("Enter the Product Description : ");
        scanf("%[^\n]s", p[i].description);
        printf("Enter the Product Price (float) : ");
        scanf("%f", &p[i].price);
        printf("Enter the Product Quantity (int) : ");
        scanf("%d", &p[i].quantity);

        fwrite(&p[i], sizeof(Product), 1, fptr);
    }
    
    fclose(fptr);
}

void new_create() {
    char temp[2];
    int n = 5, i, j;
    char prod_names[5][20] = {
        "Corn Flakes",
        "Lays",
        "Monster Energy",
        "Heinz Can of Beans",
        "Pepsi"
    };
    char prod_description[5][100] = {
        "Nourishing and Tasty ready-2-eat breakfast",
        "Tasty Snack",
        "A can of the meanest energy drink on the planet",
        "Its Everywhere",
        "Soft Drink Better than Cola"
    };
    int prod_quantity[] = {
        40,
        55,
        60,
        12,
        10
    };
    float prod_prices[] = {
        20.00,
        12.00,
        60.45,
        45.23,
        22.20
    };
    p = (Product*)calloc(n, sizeof(Product));
    fptr = fopen("products.dat","w");
    for (i = 0; i < n; i++)
    {
        p[i].id = i + 1;
        strcpy(p[i].product_name, prod_names[i]);
        strcpy(p[i].description, prod_description[i]);
        p[i].price = prod_prices[i];
        p[i].quantity = prod_quantity[i];
        fwrite(&p[i], sizeof(Product), 1, fptr);
    }
    fclose(fptr);
}

// DISPLAY FUNCTION
void display() {
	system(CLEAR);

    fptr = fopen("products.dat","r");
    
    printf("ID |Name  |  Des ");
    while (fread(&p_1,sizeof(Product), 1,fptr))
    {
        printf("\n%-5d|%-20s|%-50s|%8.2f|%4d", p_1.id, p_1.product_name, p_1.description, p_1.price, p_1.quantity);
    }
    fclose(fptr);
    printf("\n");
    int flag = 0;
    printf("Go Back (1 = Yes, 0 = No) : ");
    scanf("%d",&flag);
    while (!flag)
    {
    	printf("Go Back (1 = Yes, 0 = No) : ");
        scanf("%d",&flag);
    }
}

// NEW APPEND FUNCTION
void append() {
    system(CLEAR);
    char temp[2];
    int n,i, flag = 0, idflag = 1, app = 0;
    n = 0;
    //fptr = fopen("products.dat","a");
    Product p;
    do{
        gotoxy(20, 2);
        printf("Do you want to append a new product \n(Yes = 1, No = 0 [GO BACK])): ");
        scanf("%d",&app);
        if (app == 1) {
            fptr = fopen("products.dat","a");
            
            do {
                gotoxy(20,4);
                printf("Enter ID : ");
                scanf("%d", &p.id);
                if (check_id(p.id)) {
                    printf("This id is already present use other id\n");
                    idflag = 1;
                } else {
                    idflag = 0;
                }
            } while(idflag != 0);

            scanf("%c", temp);
            gotoxy(20,5);
            printf("Enter Name : ");
            scanf("%[^\n]s", p.product_name);
            scanf("%c", temp);
            gotoxy(20,6);
            printf("Enter the Product Description : ");
            scanf("%[^\n]s", p.description);
            gotoxy(20,7);
            printf("Enter the Product Price (float) : ");
            scanf("%f", &p.price);
            gotoxy(20,8);
            printf("Enter the Product Quantity (int) : ");
            scanf("%d", &p.quantity);
            
            fwrite(&p,sizeof(Product), 1, fptr);
            fclose(fptr);
            n++;
            gotoxy(10,10);
            printf("Appended %d value/s to the database\n", n);
            system(CLEAR);
        } else {
            flag = 1;
        }
    }while(flag != 1);
    //fclose(fptr);
}

// SEARCH FUNCTION
void search_product() {

    int id, found = 0;
    fp = fopen("products.dat","r");
    printf("Enter the Product ID to Search : ");
    scanf("%d", &id);

    while (fread(&p_1,sizeof(Product), 1,fp))
    {
        if (p_1.id == id) {
            found = 1;
            printf("%-5d|%-20s|%-50s|%8.2f|%4d\n", p_1.id, p_1.product_name, p_1.description, p_1.price, p_1.quantity);
        }
    }
    if(!found) {
        printf("\nRecord not found\n");
    }
    fclose(fp);

    int flag = 0;
    printf("Go Back (1 = Yes, 0 = No) : ");
    scanf("%d",&flag); while (!flag)
    {
        scanf("%d",&flag);
    }
}

// UPDATE PRODUCT FUNCTION
void update_product() {

    // ft is the temporary file for updating
    int id, found = 0;
    char temp[2];
    fp = fopen("products.dat","r");
    ft = fopen("temp.dat","w");
    printf("Enter the Product ID to Update : ");
    scanf("%d", &id);

    while (fread(&p_1,sizeof(Product), 1,fp))
    {
        if (p_1.id == id) {
            found = 1;
            scanf("%c",temp);
            printf("Enter Name : ");
            scanf("%[^\n]s", p_1.product_name);
            scanf("%c",temp);
            printf("Enter the Product Description : ");
            scanf("%[^\n]s", p_1.description);
            printf("Enter the Product Price (float) : ");
            scanf("%f", &p_1.price);
            printf("Enter the Product Quantity (int) : ");
            scanf("%d", &p_1.quantity);
        }
        fwrite(&p_1, sizeof(Product), 1, ft);
    }
    fclose(ft);
    fclose(fp);


    if(!found) {
        printf("\nRecord not found\n");
    } else {
        ft = fopen("temp.dat","r");
        fp = fopen("products.dat", "w");
        while (fread(&p_1, sizeof(Product), 1,ft)) {
            fwrite(&p_1, sizeof(Product), 1, fp);
        }
        
        fclose(fp);
        fclose(ft);

    }
}

// DELETE PRODUCT FUNCTION
void delete_product() {

    int id, found = 0;
    char temp[2];
    fp = fopen("products.dat","r");
    ft = fopen("temp.dat","w");
    printf("Enter the Product ID to Update : ");
    scanf("%d", &id);

    while (fread(&p_1,sizeof(Product), 1,fp))
    {
        if (p_1.id == id) // ignore that id 
            found = 1;
        else
            fwrite(&p_1, sizeof(Product), 1, ft);
    }
    fclose(ft);
    fclose(fp);


    if(!found) {
        printf("\nRecord not found\n");
    } else {
        ft = fopen("temp.dat","r");
        fp = fopen("products.dat", "w");
        while (fread(&p_1, sizeof(Product), 1,ft)) {
            fwrite(&p_1, sizeof(Product), 1, fp);
        }
        
        fclose(fp);
        fclose(ft);

    }
}

void exit_admin() {
    int exit = 0;
    printf("You have exited the program. Press 1 to Exit.\n");
    scanf("%d", &exit);
    if(!exit) {
        admin_menu();
    }
}
// ADMIN_MENU
void admin_menu () {
	int choice, i;
	
    do
    {
    	char options[9][50] = {
			"Welcome to the E-Commerce Application",
			"[1] CREATE INITIAL DATA FILE\n",
			"[2] DISPLAY\n",
			"[3] APPEND\n",
			"[4] SEARCH PRODUCT\n",
       		"[5] UPDATE PRODUCT\n",
			"[6] DELETE PRODUCT\n",
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
                // create();
                new_create();
                break;
            case 2:
                display();
                break;
            case 3:
                append();
                break;
            case 4:
                search_product();
                break;
            case 5:
                update_product();
                break;
            case 6:
                delete_product();
                break;
            default:
                choice = 0;
                break;

        }
    } while (choice != 0 );

}