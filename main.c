#include "imports.h"
#include "splashscreen.h"
#include "admin_functions.h"
// #include "user_functions.h"
#include "user.h"
#include "login.h"
#include "register.h"

int main()
{   
    int choice;
    
    do
    {
        splash_screen();
        gotoxy(9,2);
        printf("!! Welcome To C-Kart !!");
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
            // system("COLOR 40");
            printf("Invalid Option !!");
            break;
        }
        
    } while (choice != 1);
    system(CLEAR);
    
    login();


    // delete_product();
    // display(0);
    // search_product();
    // update_product();
    // append();
    // placeorder();
    // printf("LOGIN");
    // usermenu();
    // admin_menu();
    return 0;
}
