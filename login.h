typedef struct logins
{
    char uname[20];
    int admin;
    char pass[20];

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
    
    do
    {   
        splash_screen();
        gotoxy(10,2);
        printf("LOGIN MENU");
        char UI[4][20] = {
            "Give Option\n",
            "[1] Admin\n",
            "[2] User\n",
            "[0] Exit\n"
        };
        for (int i = 0; i < 4; i++)
        {
            gotoxy(5,4 + i);
            printf("%s",UI[i]);
        }
        gotoxy(5,9);
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
        system(CLEAR);
        splash_screen();
        gotoxy(7,2);
        printf("WELCOME TO ADMIN LOGIN\n");
        char UI[4][20] = {
            "Give Option\n",
            "[1] Sign In\n",
            "[2] Register\n",
            "[0] Exit\n"
        };
        for (int i = 0; i < 4; i++) {
            gotoxy(5,4 + i);
            printf("%s",UI[i]);
        }
        gotoxy(5,9);
        printf("Option : ");
        scanf("%d",&option);
        scanf("%c",temp);
        switch (option) {
        case 1:
            signin(1);
            break;
        case 2:
            register_admin();
            break;
        case 0:
            break;
        default:
            gotoxy(5,10);
            printf("Invalid Option !!");
            break;
        }
    } while (option != 0);
    // create_logins();
    system(CLEAR);

}

void user_login() {
    int option = 0;
    do
    {
        system(CLEAR);
        splash_screen();
        gotoxy(10,2);
        printf("WELCOME TO USER LOGIN\n");
        char UI[4][20] = {
            "Give Option\n",
            "[1] Sign In\n",
            "[2] Register\n",
            "[0] Exit\n"
        };
        for (int i = 0; i < 4; i++) {
            gotoxy(5,4 + i);
            printf("%s",UI[i]);
        }
        gotoxy(5,9);
        printf("Option : ");
        scanf("%d",&option);
        scanf("%c",temp);
        switch (option) {
        case 1:
            signin(0);
            break;
        case 2:
            register_user();
            break;
        case 0:
            break;
        default:
            gotoxy(5,10);
            printf("Invalid Option !!");
            break;
        }
    } while (option != 0);
    // create_logins();
    // system(CLEAR);

}

void signin(int n) {
    system(CLEAR);
    splash_screen();
    gotoxy(15,2);
    printf("Sign In Page\n");
    LOGIN l_1;
    char username[20], password[20];
    int flag = 0;
    int admin_val=0;
    if (n == 1) {
        fptr = fopen("login_a.dat", "r");
    } else {
        fptr = fopen("login_u.dat", "r");
    }
    
    // fptr = fopen("logins.dat", "r");
    
    gotoxy(3,4);
    printf("Enter USERNAME : ");
    scanf("%[^\n]s", username);
    scanf("%c",temp);
    gotoxy(3,5);
    printf("Enter PASSWORD : ");
    scanf("%[^\n]s", password);
    scanf("%c",temp);
    
    while(fread(&l_1, sizeof(LOGIN), 1, fptr)) {
        if ((strcmp(l_1.uname, username) == 0) && (strcmp(l_1.pass, password) == 0)) {
            // printf("\nUSERNAME is VALID\n");
            // flag++;
            // if (strcmp(l_1.pass, password) == 0) {
            //     // printf("\nPASSSWORD is VALID\n");
            //     flag++;
            // } else {
            //     flag = 0;
            // }
            flag = 2;
        } else {
            flag=0;
        }
        if (flag==2) {
            admin_val = l_1.admin;
            break;
        }
        
    }
    gotoxy(3,8);
    if (flag == 0)
    {
        printf("USERNAME AND PASSWORD IS INCORRECT\n");
        printf("Press Enter to go back.");
        scanf("%c",temp);
    } else if (flag == 1)
    {
        printf("USERNAME OR PASSWORD IS INCORRECT. Press Enter to go back\n");
        scanf("%c",temp);
    } else if (flag == 2) {
        printf("LOGIN Successful Press enter\n");
        if (admin_val == 1) {
            // Go To ADMIN MENU
            scanf("%c",temp);
            admin_menu();
        } else {
            // GO To User Menu
            scanf("%c",temp);
            usermenu();
        } 
    }
    
    fclose(fptr);
}