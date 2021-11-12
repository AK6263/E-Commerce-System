void splash_screen() {
    system(CLEAR);
    int vert = 10, hori = 40;
    for(int i = 0; i <= vert; i++) {
        for(int j = 0; j <= hori; j ++) {
            if(i == 0 || i == vert)
                printf("*");
            else {
                if (j == 0 || j == hori) {
                    printf("|");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}