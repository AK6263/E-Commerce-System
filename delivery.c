#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void gotoxy(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);
}

int main()
{  
	//pin, timing, address as user inputs
    //if pin \in available pins, pin_found = 1
    //similar for time_found
	int pin, time_slot, pin_found = 0, time_found = 0;
    char address[50];

    //accessing the available list of pins
    //make sure that the first row in "pin.txt" denotes the total #
    FILE *fp_pin = fopen("pin.txt", "r");
    int len;
    fscanf(fp_pin, "%i", &len);

    // pins[] contain the available pins
    int pins[len], index;

    for(index = 0; index < len; index += 1){
        fscanf(fp_pin, "%i", &pins[index]);
    }
    fclose(fp_pin);

    //accessing time.txt; checking availability of a delivery van
    FILE *fp_time = fopen("time.txt", "r");
    int availability_of_vans[5];

    for(index = 0; index < 5; index += 1){
        fscanf(fp_time, "%i", &availability_of_vans[index]);
    }
    fclose(fp_time);

    // first UI
    int opt1;
    printf("\n\n 1. Avail Home delivery");
    gotoxy(20,7);
    printf("\n 2. Collect your order directly from our outlet");
    gotoxy(20,9);
    printf("\n 3. Exit");
    gotoxy(20,13);
    printf("\n\n Please select your preferred option:\t");
    scanf("%d", &opt1);

    switch(opt1)
    {
        case 1:
        printf("Enter the PINCODE of the delivery locality (pattern: ******)\n");
        scanf("%i", &pin);
        for(index = 0; index < len; index += 1){
            if(pins[index] == pin){
                pin_found = 1;
                break;}
        }
        if(pin_found == 1)
        {
            printf("Which of the time-slots is ideal to deliver to you\n");
            printf("1. 5-7\n2. 7-9\n3. 9-13\n4. 13-17\n5. 17-22\n");
            scanf("%i", &time_slot);

            if(availability_of_vans[time_slot-1] == 1){
                printf("Van available.\n");
            }
            else{
                printf("No van available. Delivery might be delayed.\n");
            }
        }
        else
        {
        printf("Oops!\n");
        printf("Looks like we don't deliver to your locality.");
        sleep(3);
        return 1;
        //usermenu();
        }
    
        case 2:
            printf("\nYour order is curated");
            printf("\nFeel free to drop by and receive your order!");
            printf("\nThe Outlet is open from 8am to 8pm");
        
        case 3:
        printf("Redirecting to main menu...");
        sleep(3);
        return 0;
        //usermenu();

    }
    printf("\n\n\nProceeding to the billing section.");
    sleep(3);
    return 0;
    // cross link to billing

}
