void register_admin() {
    system(CLEAR);
    splash_screen();
    gotoxy(7,2);
    printf("WELCOME TO ADMIN REGISTRATION\n");
    char secret[] = "Secret";
    char input_secret[20];
    gotoxy(3, 4);
    printf("Enter Scret Code : ");
    scanf("%[^\n]s", input_secret);
    
    if(strcmp(secret, input_secret) == 0) {
        // printf("Entered Code is Valid %d",strcmp(secret, input_secret));
        gotoxy(3,5);
        printf("Secret Code is Valid");
        LOGIN l_1;
        scanf("%c", temp);
        fptr = fopen("login_admin.dat", "a");
        gotoxy(3,7);
        printf("Enter a USERNAME :");
        scanf("%[^\n]s", l_1.uname);
        scanf("%c",temp);
        gotoxy(3,8);
        printf("Enter a PASSWORD :");
        scanf("%[^\n]s", l_1.pass);
        l_1.admin = 1;
        fwrite(&l_1, sizeof(LOGIN), 1, fptr);
        fclose(fptr);
    } else {
        gotoxy(3,5);
        printf("Secret Code is Invalid. Press Enter\n");
        scanf("%c",temp);
    }
}

void register_user() {
    system(CLEAR);
    splash_screen();
    gotoxy(7,2);
    printf("WELCOME TO USER REGISTRATION\n");
    LOGIN l_1;
    // scanf("%c", temp);

    fptr = fopen("login_user.dat", "a");
    gotoxy(3,5);
    printf("Enter a USERNAME : ");
    scanf("%[^\n]s", l_1.uname);
    scanf("%c",temp);
    gotoxy(3,7);
    printf("Enter a PASSWORD : ");
    scanf("%[^\n]s", l_1.pass);
    l_1.admin = 0;
    fwrite(&l_1, sizeof(LOGIN), 1, fptr);
    fclose(fptr);
}