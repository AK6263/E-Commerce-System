#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

FILE *fptr,*fp;

typedef struct product{
	char name[50];
	char description[100];
	int id;
	int np;
	float cost;
}Product;

Product s;

void initialize(){
	
	fptr=fopen("product.dat","wb");
	if(fptr==NULL){
		fprintf(stderr,"\nError opened file\n");
		exit (1);
	}
	
	Product input1 = {"Basket","store anything",45638,2,100};
	Product input2 = {"Bucket","Use for taking bath",67894,4,240};
	
	fwrite (&input1, sizeof(input1), 1, fptr);
    fwrite (&input2, sizeof(input2), 1, fptr);
     
    if(fwrite != 0){
        printf("contents to file written successfully !\n\n");
	}
    else{
        printf("error writing file !\n");
 	}
	
    fclose (fptr);
}

int read(){
	getchar();
	printf("Enter product name below:\n");
	gets(s.name);
	printf("Enter product description below:\n");
	gets(s.description);
	printf("Enter product id below:\n");
	scanf("%d",&s.id);
	getchar();
	printf("Enter number of items available below:\n");
	scanf("%d",&s.np);
	getchar();
	printf("Enter the price of above product:\n");
	scanf("%f",&s.cost);
	getchar();
	return 1;
}

void add(){
	do{
		fp=fopen("product.dat","ab+");
		if (read()==1){
			fseek(fp,0,SEEK_END);
			fwrite (&s, sizeof(s), 1, fp);
    		fclose (fp);
		}
		printf(" New product has been succesfully added \n");
		printf(" Do you want to add more ? (y / n) : \n");
	}
	while(getch()=='y');
}

int display(){
	fptr=fopen("product.dat","rb");
	if(fptr==NULL){
		fprintf(stderr, "\nError opening file\n");
        exit (1);
	}
	while(fread(&s, sizeof(s), 1, fptr)){
		printf("Product details\n");
        printf ("name : %s\ndescription : %s\nid : %d\nnp : %d\ncost : %.2f\n\n", s.name,s.description,s.id,s.np,s.cost);
	}
    fclose (fptr);
    return 0;
}

void adminmenu(){
	initialize();
	printf(" MAIN MENU \n");
	
	do{
		printf(" 1. Add Product\n");
		printf(" 2. Delete Product\n");
		printf(" 3. Update Product\n");
		printf(" 4. Search Product\n");
		printf(" 5. View Product list\n");
		printf(" 6. Close Application\n\n");
		//int choice;
		//scanf("%d",&choice);
		//printf("Enter 1 for adding new product\nEnter 2 for deleting any product\nEnter 3 for updating existing product\nEnter 4 for searching anything in the list\nEnter 5 for viewing list of all products available\n\n");
		switch(getch()){
			case '1':
				//printf("Add new product to the list\n");
				add();
				break;
			case '2':
				printf("Delete existing product from the list\n");
				//delete();
				break;
			case '3':
				printf("Update existing product in the list\n");
				//update();
				break;
			case '4':
				printf("search for product in the list\n");
				//search();
				break;
			case '5':
				printf("View list of available products\n");
				display();
				break;
			case '6':
				exit(0);
			default:
				printf(" Invalid choice\n");
				printf(" Please re-enter your choice \n");
				adminmenu();
		}
		printf("\nDo you want to continue ? (y / n) : \n\n");
	}
	while(getch()=='y');
}

char admin_usn[]="Admin";
char admin_passw[]="admin123";
char user_usn[][20]={"Mukesh","Parth","Abhay"};
char user_passw[][20]={"mukesh123","parth123","abhay123"};

void verification(void);
void verification_user(char *,char *);

void verification_user(char usn[],char passw[]){
	int j=sizeof(user_usn)/sizeof(user_usn[0]),k=0;
	while(k<j){
		if(strcmp(user_usn[k],usn)==0 && strcmp(user_passw[k],passw)==0){
			printf("\nWelcome User\n\n");
			adminmenu();
			//usermenu();
			return;
		}
		k++;
	}
	printf("\nIncorrect username or password\n\n");
	verification();
}

void verification(){
	char ch,tempusn[20],temppassw[20];
	int i=0;
	
	printf("Enter Username : ");
	scanf("%s",tempusn);
	printf("Enter Password : ");
	while(ch!=13){
		ch=getch();
		if(ch!=8 && ch!=13){
			putch('*');
			temppassw[i]=ch;
			i++;
		}
	}
	temppassw[i]='\0';
	if (strcmp(admin_usn,tempusn)==0 && strcmp(admin_passw,temppassw)==0){
		printf("\nWelcome Admin\n\n");
		adminmenu();
		//return;
	}
	else{
		//printf("\nIncorrect username or password\n\n");
		verification_user(tempusn,temppassw);
	}
}

void main(){
	verification();
}

