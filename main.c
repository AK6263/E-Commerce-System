#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void addProduct(char*[]);
void removeProduct(void);
void search(void);
void readFile(void);
FILE *fptr;

typedef struct product
{
    char product_name[20];
    int id;
    int quantity;
    float price;
    char description[100];
}Product;


void create() {
    FILE *fptr;
    Product *p;
    char temp[2];
    int n, i, j;

    printf("\nEnter the number of products you be added : \n");
    scanf("%d",&n);

    p = (Product*)calloc(n, sizeof(Product));
    fptr = fopen("products.dat","w");
    for (int i = 0; i < n; i++)
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

void display() {
    system("clear");
    Product p_1;
    FILE *fptr;
    fptr = fopen("products.dat","r");
    
    // printf("ID |Name  |  Des ")
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
        scanf("%d",&flag);
    }
    // system("clear");
    
}


void append() {
    Product *p;
    FILE *fptr;
    char temp[2];
    int n;
    printf("\nHow many products you want to append : ");
    scanf("%d",&n);

    p = (Product*)calloc(n, sizeof(Product));
    fptr = fopen("products.dat","a");

    for (int i = 0; i < n; i++) {
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

int no_of_product() {
    /*
        Get the id of the last product so you can 
        put the id automatically instead of asking
    */
    return 0;
}

void search_product() {
    Product p_1;
    FILE *fp;
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
    scanf("%d",&flag);
    while (!flag)
    {
        scanf("%d",&flag);
    }
}


void update_product() {
    Product p_1;
    FILE *fp, *ft;
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
void delete_product() {
    Product p_1;
    FILE *fp, *ft;
    // ft is the temporary file for updating
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

    }}



int main()
{   
    int choice;
    do
    {
        system("clear");
        printf("\nWelcome to the Student Database\n");
        printf("\n1.CREATE\n");
        printf("2.DISPLAY\n");
        printf("3.APPEND\n");
        printf("4.NO OF PRODUCT\n");
        printf("5.SEARCH PRODUCT\n");
        printf("6.UPDATE PRODUCT\n");
        printf("7.DELETE PRODUCT\n");
        printf("0.EXIT\n");

        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                append();
                break;
            case 4:
                no_of_product();
                break;
            case 5:
                search_product();
                break;
            case 6:
                update_product();
                break;
            case 7:
                delete_product();
                break;
        }

    } while (choice !=0 );
    

    return 0;
}
