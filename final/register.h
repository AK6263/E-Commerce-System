void register_admin() {
    char secret[] = "Hentai";
    char input_secret[20];

    printf("\nEnter Scret Code\n");
    scanf("%[^\n]s", input_secret);
    
    if(strcmp(secret, input_secret) == 0) {
        printf("\nEntered Code is Valid %d\n",strcmp(secret, input_secret));
        LOGIN l_1;
        scanf("%c", temp);
        fptr = fopen("logins.dat", "a");
        printf("\nEnter a USERNAME :");
        scanf("%[^\n]s", l_1.uname);
        scanf("%c",temp);
        printf("\nEnter a PASSWORD :");
        scanf("%[^\n]s", l_1.pass);
        l_1.admin = 1;
        fwrite(&l_1, sizeof(LOGIN), 1, fptr);
        fclose(fptr);
    } else {
        printf("\nEntered Code is In-valid\n");
    }
}

void register_user() {
    printf("\n\nUSER REGISTRATION\n");
    LOGIN l_1;
    // scanf("%c", temp);

    fptr = fopen("logins.dat", "a");
    printf("\nEnter a USERNAME :");
    scanf("%[^\n]s", l_1.uname);
    scanf("%c",temp);
    printf("\nEnter a PASSWORD :");
    scanf("%[^\n]s", l_1.pass);
    l_1.admin = 0;
    fwrite(&l_1, sizeof(LOGIN), 1, fptr);
    fclose(fptr);
}