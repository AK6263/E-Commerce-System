typedef struct logins
{
    char uname[20];
    int admin;
    // int uname_size;
    char pass[20];
    // int pass_size;
}LOGIN;

char temp[2];
void admin_login();
void user_login();
void register_admin();
void register_user();
void admin_menu();
void user_menu();
void signin(int n);

// #include "regid"
void login() {
    int option = 0;
    
    printf("Give Option\n");
    printf("[1] Admin\n");
    printf("[2] User\n");
    printf("[0] Exit\n");
    
    do
    {
        printf("Option : ");
        scanf("%d",&option);
        scanf("%c", temp);
        switch (option)
        {
        case 1:
            admin_login();
            // register_admin();
            break;
        
        case 2:
            user_login();
            break;
        }
    } while (option != 0);
    // create_logins();
    system(CLEAR);
}

void admin_login() {
    int option = 0;

    do
    {
        printf("Give Option\n");
        printf("[1] Sign In\n");
        printf("[2] Register\n");
        printf("[0] Exit\n");
        printf("Option : ");
        scanf("%d",&option);
        scanf("%c",temp);
        switch (option) {
        case 1:
            signin(0);
            break;
        case 2:
            register_admin();
            break;
        }
    } while (option != 0);
    // create_logins();
    system(CLEAR);

}

void user_login() {
    int option = 0;
    printf("\n\nUSER LOGIN SCREEN\n");
    do
    {
        printf("Give Option \n");
        printf("[1] Sign In\n");
        printf("[2] Register\n");
        printf("[0] Exit\n");
        printf("Option : ");
        scanf("%d",&option);
        scanf("%c",temp);
        switch (option) {
        case 1:
            signin(1);
            break;
        case 2:
            register_user();
            break;
        }
    } while (option != 0);
    // create_logins();
    // system(CLEAR);

}

void signin(int n) {
    printf("\nSign In Page\n");
    LOGIN l_1;
    char username[20], password[20];
    int flag = 0;
    int admin_val=0;
    fptr = fopen("logins.dat", "r");
    printf("\nEnter USERNAME : ");
    scanf("%[^\n]s", username);
    scanf("%c",temp);
    printf("\nEnter PASSWORD : ");
    scanf("%[^\n]s", password);
    scanf("%c",temp);
    while(fread(&l_1, sizeof(LOGIN), 1, fptr)) {
        if (strcmp(l_1.uname, username) == 0) {
            // printf("\nUSERNAME is VALID\n");
            flag++;
        }
        if (strcmp(l_1.pass, password) == 0) {
            // printf("\nPASSSWORD is VALID\n");
            flag++;
        }
        if (flag==2) {
            admin_val = l_1.admin;
            break;
        }
        
    }
    if (flag == 0)
    {
        printf("\nUSERNAME AND PASSWORD IS INCORRECT\n");
    } else if (flag == 1)
    {
        printf("\nUSERNAME OR PASSWORD IS INCORRECT\n");
    } else {
        printf("\nLOGIN Successful\n");
        if (admin_val == 1) {
            // Go To ADMIN MENU
            // scanf("%c",temp);
            admin_menu();
        } else {
            // GO To User Menu
            scanf("%c",temp);
            user_menu();
        } 
    }
    
    fclose(fptr);
}