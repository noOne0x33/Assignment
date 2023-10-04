#include <stdio.h>

int main(){
    int size;

    // Input the size of the square
    printf("Enter the size of the square: ");
    scanf("%d", &size);

    // Loop through rows
    for (int i = 1; i <= size; i++){
        // Loop through columns
        for (int j = 1; j <= size; j++){
            // Print '*' for the outermost rows and columns or for the inner square
            if (i == 1 || i == size || j == 1 || j == size){
                printf("*");
            }else{
                printf(" "); // Print a space for the inner area
            }
        }
        // Move to the next line after each row
        printf("\n");
    }

    return 0;
}