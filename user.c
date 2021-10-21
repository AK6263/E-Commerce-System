#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

int printcatalogue(void);
int search(void);

// gotoxy() function definition
void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

int getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

void usermenu(){
    system("clear");
    gotoxy(27,3);
    printf("MAIN MENU ");
    gotoxy(20,5);
    printf(" 1. View catalogue  ");
    gotoxy(20,7);
    printf(" 2. Search Products ");
    gotoxy(20,9);
    printf(" 3. Close Application");
    gotoxy(20,13);
    printf("Enter your choice:");
    switch(getche())
    {
    case '1':
    printcatalogue();
    break;
    case '2':
    search();
    break;
    case '3':
    {
    system("clear");
    exit(0);
    }
    default:
    {
    gotoxy(10,23);
    printf("\aWrong Entry!!Please re-entered correct option");
    if(getch())
    usermenu();
    }

    }
}


int search(){
    system("clear");
    return 0;
}

int printcatalogue(){
    system("clear");
    return 0;
}


int main()
{   
    usermenu();
    return 0;
}
