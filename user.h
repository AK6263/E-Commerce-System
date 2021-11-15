int printcatalogue(void);
int search(void);
int addtocart(int i, int q);
int printcart(void);
int displayProduct(void);
int placeorder(void);
int generate_bill(char address[100]);

void usermenu(){
    int choice;
    system(CLEAR);
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
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:{
            displayProduct();
            break;
        }
        case 2:{
            search();
            break;
        }
        case 3:
        {
    
            break;
        }
        default:
        {
            gotoxy(10,23);
            printf("\nInvalid entry!!Please re-enter a valid option. Redirecting to main menu");
            sleep(2);
            usermenu();
        }

    }
}

int search(){
    system(CLEAR);
    Product p_1;
    FILE *fp;
    char n[30],temp[2];
    int id,value, found = 0;
    fp = fopen("products.dat","r");
    gotoxy(20,3);
    printf("Enter the Product name to Search : ");
    scanf("%c",temp); // Flushing ny escapes
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
            printf("    ::::::::::::::::::::::::::::::::::: Search result :::::::::::::::::::::::::::::::::::::::::::::::::::::");

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
                system(CLEAR);
                usermenu();
                }
                default:
                {
                goto Cleanup4;
                Cleanup4:;
                gotoxy(10,32);
                printf("\aInvalin Entry!!Please re-enter a valid option. Redirecting to product catalogue... ");
                sleep(3);
                displayProduct();
                }

            }
        }
    }
    if(!found) {
        printf("\nProduct not found\n Redirecting to homepage\n");
        sleep(1);
        usermenu();
        
    }
    fclose(fp);
    
    return 0;
}
int printcart(){
    FILE *fp;
    struct product a;
    char line[200];
    int choice;

    char true;
    system(CLEAR);

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
    //gotoxy(5,25);
    printf("\n\n1. Proceed to place order");
    //gotoxy(5,27);
    printf("\n\n2. Continue Shopping");
    //gotoxy(0,29);
    printf("\n\nEnter your choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        placeorder();
        break;
    case 2:
        goto Cleanup;
        Cleanup:;
        displayProduct();
        break;
    
    default:
        {
        goto Cleanup4;
        Cleanup4:;
        gotoxy(10,36);
        printf("\aInvalid Entry!!Please re-enter a valid option. Redirecting to cart. ");
        sleep(3);
        printcart();
        }
    }

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
                        if (a.quantity<q){
                            printf("Only %d items available\nRedirecting to catalogue...",a.quantity);
                            //sleep(1);
                            displayProduct();
                        }
                        else{
                            fprintf(fptr,"%-1d,%-1s,%1d,%1f,%-1s\n", a.id, a.product_name, q, a.price, a.description);
                            //product_quantity(q);
                            //printf("\n%d",a.quantity);
                            //a.quantity=a.quantity-q;
                            //fwrite(&a,sizeof(Product), 1,fp);
                        }
                    }
                }
                printf("\nItem added to cart.");
                
    fclose(fp);
    fclose(fptr);    
    displayProduct();

    return 0;
}


int displayProduct() {
    FILE *fp;
    struct product a;
    int choice;

    char true;
    system(CLEAR);

    fp = fopen("products.dat", "r");

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

    printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");

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
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:{
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
    }
    case 2:{
    search();
    break;
    }
    case 3:{
    printcart();
    break;
    }
    case 4:
    {
    system(CLEAR);
    usermenu();
    }
    default:
    {
    gotoxy(10,32);
    printf("\aInvalid entry!!Please re-enter a valid option. Redirecting to product catalogue.");
    sleep(3);
    displayProduct();
    }

    }

    return (0);
}
void compact_string(char *pointer)
{
    //replaces white spaces with underscore
    //to deal with the __DATE__ string 
    while(1){
        if(*pointer == '\0')
            break;
        if(*pointer == ' ')
            *pointer = '_';
        pointer += 1;
    }
}

int placeorder(){

    system(CLEAR);
	int pin, time_slot, pin_found = 0, time_found = 0;
    char address[100];

    //accessing the available list of pins
    //make sure that the first row in "pin.txt" denotes the total #
    FILE *fp_pin = fopen("pin.txt", "r");
    int len;
    fscanf(fp_pin, "%i", &len);

    // pins[] contain the available pins
    int pins[len], index;
    for(index = 0; index < len; index += 1){
        fscanf(fp_pin, "%i", &pins[index]);
    }
    fclose(fp_pin);

    //accessing time.txt; checking availability of a delivery van
    FILE *fp_time = fopen("time.txt", "r");
    int availability_of_vans[5];

    for(index = 0; index < 5; index += 1){
        fscanf(fp_time, "%i", &availability_of_vans[index]);
    }
    fclose(fp_time);

    // first UI
    int opt1;
    gotoxy(0,4);
    printf("1. Avail Home delivery");
    gotoxy(0,6);
    printf("2. Collect your order directly from our outlet");
    gotoxy(0,8);
    printf("3. Back to main menu");
    gotoxy(5,11);
    printf("Please select your preferred option: ");
    scanf("%d", &opt1);

    switch(opt1)
    {
        case 1:
        gotoxy(5,13);
        printf("Enter the PINCODE of the delivery locality (pattern: ******): ");
        scanf("%i", &pin);
        for(index = 0; index < len; index += 1){
            if(pins[index] == pin){
                pin_found = 1;
                break;}
        }
        if(pin_found)
        {
            //gotoxy(0,15);
            //printf("Kindly enter the preferred delivery address (press ENTER to confirm)\n");
            fflush(stdin);
            scanf("%100[^\n]s", address);
            gotoxy(0,15);
            printf("Which of the time-slots is ideal to deliver to you?\n");
            printf("1. 5-7\n2. 7-9\n3. 9-13\n4. 13-17\n5. 17-22\n\n");
            printf("Enter your choice: ");
            scanf("%i", &time_slot);

            if(availability_of_vans[time_slot-1] == 1){
                printf("Van available.\n");
            }
            else{
                printf("No van available. Delivery might be delayed.\n");
            }
            printf("\nProceeding to the billing section.\n\n");
            sleep(3);
            generate_bill(address);
            break;
        }
        else
        {
        printf("Oops!\n");
        printf("Looks like we don't deliver to your locality.\n");
        sleep(3);
        placeorder();
        return 1;
        }
    
        case 2:
            printf("\nYour order is curated");
            printf("\nFeel free to drop by and receive your order!");
            printf("\nThe Outlet is open from 8am to 8pm\n");
            generate_bill(address);
        
        case 3:
            usermenu();
            break;

    }
    //printf("Redirecting to main menu...");
    //printf("Press any key to go back to main menu\n");
    //if (getch())
    //usermenu();
    return 0;
}

void genBillheader(FILE *STREAM, char name[30], char date[30], char address[100])
{
    printf("\n\n\t\t   %s\n\t ---------------------------", "Aapki Dukaan");
    printf("\n\tOrder placed on: %s\n\tInvoice To: %s\n  Address: %s\n", date, name, address);
    printf("\n==============================================\n%-20s%-10s%-10s%-10s", 
        "Item", "ID", "Quantity", "Total");
    printf("\n----------------------------------------------\n\n");    

    fprintf(STREAM, "\t\t   %s\n\t ---------------------------", "Aapki Dukaan");
    fprintf(STREAM, "\n\tOrder placed on: %s\n\tInvoice To: %s\n  Address: %s", date, name, address);
    fprintf(STREAM, "\n==============================================\n%-20s%-10s%-10s%-10s", 
        "Item", "ID", "Quantity", "Total");
    fprintf(STREAM, "\n----------------------------------------------\n\n"); 
}

float genBillbody(FILE *STREAM, char item[20], int id, int qty, float price)
{
    float TOTAL; // gets returned; total for one item
    TOTAL = qty * price;

    printf("%-20s%-10d%-10d%-8.2f\n", item, id, qty, TOTAL);
    fprintf(STREAM, "%-20s%-10d%-10d%-8.2f\n", item, id, qty, TOTAL);

    return(TOTAL);
}

void genBillfooter(FILE *STREAM, float total)
{
    float disc = 0.05*total; //discount
    float netTotal = total - disc;
    float GST=0.15*netTotal, grandTotal = netTotal + GST;
    printf("\n----------------------------------------------\n");
    printf("%-40s%-18.2f\n", "Sub total", total);
    printf("%-40s%-18.2f\n", "Discount @5\%", disc);
    printf("-------------------------\n");
    printf("%-40s%-18.2f\n", "Net total", netTotal);
    printf("%-40s%-18.2f\n", "GST @15\%", GST);
    printf("-------------------------\n");
    printf("%-40s%-18.2f\n", "Grand total", grandTotal);
    printf("----------------------------------------------\n");
    printf("Thank you!! ----------------------------------\n");

    fprintf(STREAM, "\n----------------------------------------------\n");
    fprintf(STREAM, "%-40s%-18.2f\n", "Sub total", total);
    fprintf(STREAM, "%-40s%-18.2f\n", "Discount @5\%", disc);
    fprintf(STREAM, "-------------------------\n");
    fprintf(STREAM, "%-40s%-18.2f\n", "Net total", netTotal);
    fprintf(STREAM, "%-40s%-18.2f\n", "GST @15\%", GST);
    fprintf(STREAM, "-------------------------\n");
    fprintf(STREAM, "%-40s%-18.2f\n", "Grand total", grandTotal);
    fprintf(STREAM, "----------------------------------------------\n");
    fprintf(STREAM, "Thank you!! ----------------------------------\n");
}

int generate_bill(char address[100])
{
    int opt, index = 0, len = strlen(__DATE__), flag;
    float net_total = 0;
    char ext[] = ".txt", rt_name[len], temp[len];
    struct cart_item cart;
    struct invoice new_invoice;
    int choice;

    //accessing the cart text file
    FILE *fp_cart = fopen("cart.csv", "r");

    while(1){
        //dashboard
        printf("====================== Aapki Dukaan ========================");    
        printf("\n\n1. Generate Invoice");
        printf("\n2. Show all Invoices");
        printf("\n3. Back to main menu");
        printf("\n\n Please select your preferred option:\t");
        scanf("%d", &opt);

        switch(opt)
        {
        case 1:
            printf("\n Enter your name \t");
            //updating invoice
            fflush(stdin);
            scanf("%30[^\n]s", new_invoice.customer_name);
            strcpy(new_invoice.date, __DATE__);
            strcpy(rt_name, __DATE__);
            printf("Here is your receipt.\n");

            //this chunk replaces the white spaces
            compact_string(rt_name);
            strcpy(temp, rt_name);

            strcat(rt_name, ext);
            printf("Also, please refer to %s.\n", rt_name);
            
            FILE *fp_receipt = fopen(rt_name, "w");

            //accessing the compilation of all transactions in append mode
            FILE *fp_inv = fopen("invoices.txt", "a");

            //header of the receipt 
            genBillheader(fp_receipt, new_invoice.customer_name, new_invoice.date, address);
            
            while(fscanf(fp_cart, "%d,%20[^,],%d,%f,%[^\n]s", &cart.id, cart.item_name, &cart.qty, 
                &cart.price, cart.description)!=EOF){
                    if(index == 10)
                        break;
                    new_invoice.items[index] = cart;
                    //body of the receipt; item-wise 
                    net_total += genBillbody(fp_receipt, cart.item_name, cart.id, cart.qty, cart.price);
                    index += 1;
            }
            fclose(fp_cart);
            //updating invoice
            new_invoice.numOfItems = index;
            new_invoice.total = net_total;

            //tail of the receipt
            genBillfooter(fp_receipt, net_total);
            fclose(fp_receipt);

            //updating invoices.txt
            /*
                NOTE:
                while saving an invoice, only the name and quantity of the item purchased are saved
                modify the following code to include more parameters
                also, customer name is omitted from the invoices; that prolly is redundant
            */
            fprintf(fp_inv, "%d %s %10.2f\n", new_invoice.numOfItems, temp, new_invoice.total);
            for(index = 0; index < new_invoice.numOfItems; index += 1){
                fprintf(fp_inv, "%s,%d,%d\n", new_invoice.items[index].item_name, new_invoice.items[index].id,
                new_invoice.items[index].qty);
            }
            fclose(fp_inv);

            printf("\nProcess completed successfully.\n Press [1] to continue shopping [0] to exit: ");
            scanf("%d",&choice);
            if(choice==1)
            usermenu();
            else if (choice==0);
            {
                break;
            }
            
            return 0;
        
        case 2:
            printf("Showing all purchases made...\n\n\n");
            char phrase[20];
            int items_per_purchase;
            index = 0;

            //accessing invoices.txt in read mode
            FILE *fp_iv = fopen("invoices.txt", "r");

            while(fscanf(fp_iv, "%s", phrase)!=EOF){
                //printing date and total amount spent
                if(index == 0){
                    items_per_purchase = atoi(phrase);
                    index += 1;
                }
                else if(index == 1){
                    printf("Date of purchase: ");
                    char *p; p = phrase;
                    while(*p != '\0'){
                        if(*p == '_')
                            printf(" ");
                        else
                            printf("%c", *p);
                        p+=1;
                    }
                    printf("\t\t");
                    index += 1;
                }
                else{
                    printf("Total: %s\n", phrase);
                    index += 1;

                    //printing purchased items
                    printf("%-20s%-20s%-20s", "Item", "Product ID", "Quantity");
                    for(index = 3; index<items_per_purchase+3; index +=1){
                        char t1[20], t2[10], t3[10];
                        fscanf(fp_iv, "%[^,],%[^,],%[^\n]", t1, t2, t3);
                        printf("%-20s%-20s%-20s", t1, t2, t3);
                    }
                    printf("\n________________________________________");
                    printf("__________________________\n");
                    index = 0;
                }
            }
            continue;

        case 3:
            printf("Press any key to go back\n");
            flag = 1;
            break;
        }
        if (flag == 1)
        {
            break;
        }
        
    }
    //cross-link to the main UI
    return 0;
}
