#include <stdio.h>
#include <unistd.h>  // For usleep function

#define DELAY 90000  // Delay in microseconds (0.07 seconds)

void print_2d_array_col_by_col(int arr[20][20], int rows, int cols) {
    int i, j;
    
    // Loop over columns
    for (j = 0; j < cols; j++) {
        // Loop over rows in the current column
        for (i = 0; i < rows; i++) {
            if (arr[i][j] == 1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");

        // Delay after printing each column
        usleep(DELAY);
    }
}

int main(void) {
    int arr[20][20] = {
        {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
        {1,1,1,0,1,1,0,0,0,1,1,1,0,0,1,1,0,0,0,0},
        {1,1,1,0,1,1,0,0,0,1,1,1,0,0,1,1,0,0,0,0},
        {1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
        {1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1},
        {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1},
        {0,0,0,0,0,1,1,0,0,1,1,1,0,0,1,1,0,1,1,1},
        {0,0,0,0,0,1,1,0,0,1,1,1,0,0,1,1,0,1,1,1},
        {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    };

    int rows = 20;
    int cols = 20;

    print_2d_array_col_by_col(arr, rows, cols);

    return 0;
}