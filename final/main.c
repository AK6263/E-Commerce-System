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
    // admin_menu();
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
        default:
            choice = 1;
            break;
        }
    } while (choice != 1);
    system(CLEAR);
    // printf("LOGIN");
    login();
    // usermenu();
    return 0;
}
