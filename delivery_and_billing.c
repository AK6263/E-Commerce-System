#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/*
    NOTE:
    the bill generator functions generate a txt receipt
    as well as print on the console
*/
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
 
//BILLING
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

int generate_bill(char address[100])
{
    int opt, index = 0, len = strlen(__DATE__);
    float net_total = 0;
    char ext[] = ".txt", rt_name[len], temp[len];
    struct cart_item cart;
    struct invoice new_invoice;

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

            printf("\nProcess completed successfully.\n");
            sleep(3);

            //cross-link to the main UI
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
            printf("Redirecting to the homepage...\n");
            sleep(3);
            break;
        }
    }
    //cross-link to the main UI
    return 0;
}

void gotoxy(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);
}

int main()
{  
	//pin, timing, address as user inputs
    //if pin \in available pins, pin_found = 1
    //similar for time_found
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
    printf("\n\n 1. Avail Home delivery");
    gotoxy(20,7);
    printf("\n 2. Collect your order directly from our outlet");
    gotoxy(20,9);
    printf("\n 3. Back to main menu");
    gotoxy(20,13);
    printf("\n\n Please select your preferred option:\t");
    scanf("%d", &opt1);

    switch(opt1)
    {
        case 1:
        printf("Enter the PINCODE of the delivery locality (pattern: ******)\n");
        scanf("%i", &pin);
        for(index = 0; index < len; index += 1){
            if(pins[index] == pin){
                pin_found = 1;
                break;}
        }
        if(pin_found)
        {
            printf("Kindly enter the preferred delivery address (press ENTER to confirm)\n");
            fflush(stdin);
            scanf("%100[^\n]s", address);
            printf("Which of the time-slots is ideal to deliver to you\n");
            printf("1. 5-7\n2. 7-9\n3. 9-13\n4. 13-17\n5. 17-22\n");
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
        return 1;
        //usermenu();
        }
    
        case 2:
            printf("\nYour order is curated");
            printf("\nFeel free to drop by and receive your order!");
            printf("\nThe Outlet is open from 8am to 8pm\n");
        
        case 3:
            break;

    }
    printf("Redirecting to main menu...");
    sleep(3);
    return 0;
    //usermenu();
}
