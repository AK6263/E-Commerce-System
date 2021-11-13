#include <stdio.h>
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
void genBillheader(FILE *STREAM, char name[30], char date[30])
{
    printf("\n\n\t Aapki Dukaan\n---------------------------");
    printf("\nOrder placed on: %s\nInvoice To : %s\n", date, name);
    printf("----------------------\nItems\t\tQty\t\tTotal\t\t");
    printf("\n----------------------\n\n");    

    //fprintf(STREAM, "\t Aapki Dukaan\n\t ----------------------");
    fprintf(STREAM, "\nOrder placed on: %s\nInvoice To : %s\n", date, name);
    fprintf(STREAM, "----------------------\nItems\t\tQty\t\tTotal\t\t");
    fprintf(STREAM, "\n----------------------\n\n"); 
}
float genBillbody(FILE *STREAM, char item[20], int qty, float price)
{
    float TOTAL; // gets returned; total for one item
    TOTAL = qty * price;

    printf("%s\t\t%d\t\t%.2f\n", item, qty, TOTAL);
    fprintf(STREAM, "%s\t\t%d\t\t%.2f\n", item, qty, TOTAL);

    return(TOTAL);
}
void genBillFooter(FILE *STREAM, float total)
{
    float disc = 0.05*total; //discount
    float netTotal = total - disc;
    float GST=0.15*netTotal, grandTotal = netTotal + GST;
    printf("\n----------------------\nSub Total \t\t\t%.2f",total);
    printf("\nDiscount @5%s\t\t\t%.2f\n\t\t\t\t---------------","%", disc);
    printf("\nNet Total \t\t\t%.2f",netTotal);
    printf("\nGST @15 %s\t\t\t%.2f\n----------------------","%",GST);
    printf("\nGrand Total \t\t\t%.2f\n\t\t\t\t---------------",grandTotal);

    fprintf(STREAM, "\n----------------------\nSub Total \t\t\t%.2f",total);
    fprintf(STREAM, "\nDiscount @5%s\t\t\t%.2f\n\t\t\t\t---------------","%", disc);
    fprintf(STREAM, "\nNet Total \t\t\t%.2f",netTotal);
    fprintf(STREAM, "\nGST @15 %s\t\t\t%.2f\n----------------------","%",GST);
    fprintf(STREAM, "\nGrand Total \t\t\t%.2f\n\t\t\t\t---------------",grandTotal);
}

struct cart_item{
    char item_name[20];
    float price;
    int qty, id;
};
struct invoice
{
    char customer_name[30];
    char date[50];
    int numOfItems;
    float total;
    struct cart_item items[10];

};

int main()
{
    int opt, index = 0, len = strlen(__DATE__);
    float net_total = 0;
    char ext[] = ".txt", rt_name[len], temp[len];
    struct cart_item cart;
    struct invoice new_invoice;

    //accessing the cart text file
    FILE *fp_cart = fopen("cart.csv", "r");

    //dashboard
    printf("\t =================================================");    
    printf("\n\n 1. Generate Invoice");
    printf("\n 2. Show all Invoices");
    printf("\n 3. Exit");
    printf("\n\n Please select your preferred option:\t");
    scanf("%d", &opt);

    switch(opt)
    {
    case 1:
        printf("\n Enter your name \t");
        //updating invoice
        fflush(stdin);
        scanf("%[^\n]s", new_invoice.customer_name);
        strcpy(new_invoice.date, __DATE__);
        strcpy(rt_name, __DATE__);
        printf("Here is your receipt.\n");

        //this chunk replaces the white spaces
        //easy to use fscanf
        compact_string(rt_name);
        strcpy(temp, rt_name);

        strcat(rt_name, ext);
        printf("Also, please refer to %s.\n", rt_name);
        
        FILE *fp_receipt = fopen(rt_name, "w");

        //accessing the compilation of all transactions in append mode
        FILE *fp_inv = fopen("invoices.txt", "a");

        //header of the receipt 
        genBillheader(fp_receipt, new_invoice.customer_name, new_invoice.date);
        
        while(fscanf(fp_cart, "%i %s %i %f", &cart.id, cart.item_name, &cart.qty, &cart.price)!=EOF){
                if(index == 10)
                    break;
                new_invoice.items[index] = cart;
                //body of the receipt; item-wise 
                net_total += genBillbody(fp_receipt, cart.item_name, cart.qty, cart.price);
                index += 1;
        }
        fclose(fp_cart);
        //updating invoice
        new_invoice.numOfItems = index;
        new_invoice.total = net_total;

        //tail of the receipt
        genBillFooter(fp_receipt, net_total);
        fclose(fp_receipt);

        //updating invoices.txt
        /*
            NOTE:
            while saving an invoice, only the name and quantity of the item purchased are saved
            modify the following code to include more parameters
            also, customer name is omitted from the invoices; that prolly is redundant
        */
        fprintf(fp_inv, "%i %s %10.2f\n", new_invoice.numOfItems, temp, new_invoice.total);
        for(index = 0; index < new_invoice.numOfItems; index += 1){
            fprintf(fp_inv, "%s %i\n", new_invoice.items[index].item_name, new_invoice.items[index].qty);
        }
        fclose(fp_inv);

        printf("\nProcess completed successfully.\n");
        printf("Redirecting to the homepage...\n");
        sleep(100);
        return 0;
    
    case 2:
        printf("Showing all purchases made.\n");
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
                printf("%s\t\t%s\n", "Item", "Quantity");
                for(index = 3; index<items_per_purchase+3; index +=1){
                    fscanf(fp_iv, "%s", phrase);
                    printf("%s\t\t", phrase);
                    fscanf(fp_iv, "%s", phrase);
                    printf("%s\n", phrase);
                }
                printf("__________________________________\n");
                index = 0;
            }
        }

    case 3:
        printf("Redirecting to the homepage...\n");
        sleep(3);
        return 0;
   	 
    }
    printf("\n\n");
    return 0;
}
