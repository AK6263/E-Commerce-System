#include "imports.h"
#include "splashscreen.h"
#include "admin_functions.h"
#include "user_functions.h"
#include "login.h"
#include "register.h"

void search() {
    system(CLEAR);
}

int main()
{   
    int choice;
    
    do
    {
        splash_screen();
        gotoxy(5, 6);
        printf("Press 1 to Enter 0 to Exit : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            system(CLEAR);
            exit(0);
            break;
        case 1:
            choice = 1;
            break;
        default:
            gotoxy(5,8);
            printf("Invalid Option !!");
            break;
        }
        
    } while (choice != 1);
    system(CLEAR);
    
    login();
    // printf("LOGIN");
    // usermenu();
    // admin_menu();
    return 0;
}
