void splash_screen() {
    system(CLEAR);
    gotoxy(0,0);
    int vert = 10, hori = 40;
    for(int i = 0; i <= vert; i++) {
        for(int j = 0; j <= hori; j ++) {
            if(i == 0 || i == vert)
                printf("*");
            else {
                if(j == 0 ||j == hori) {
                    gotoxy(0, i+1);
                    printf("|");
                    gotoxy(hori+1, i+1);
                    printf("|");
                }
            }
        }
        printf("\n");
    }
    
}