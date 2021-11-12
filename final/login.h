typedef struct log_details
{
    char *uname;
    int uname_size;
    char *pass;
    int pass_size;
}LOG;

LOG log_1;
void admin_login();
void user_login();
void register_admin();
void register_user();
void signin(int n);
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
        switch (option)
        {
        case 1:
            admin_login();
            break;
        
        case 2:
            user_login();
            break;
        }
    } while (option != 0);
    create_logins();
    system(CLEAR);
}

void admin_login() {
    // system(CLEAR);
    int option;
    printf("[1] Sign In\n");
    printf("[2] Sign Up\n");
    scanf("%d",&option);
    if(option == 1){
        signin(0);
    } else if(option == 2){
        printf("Signed Up");
    } else {
        admin_login();
    }
}

void register_admin() {
    // char *uname, *pass;
    fptr = fopen("login_details.dat", "w");
    printf("USERNAME : ");
    while
    printf("PASSWORD : ");
    fclose(fptr);
}

void signin(int n){

}