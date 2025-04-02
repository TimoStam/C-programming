#include <stdio.h>
#define SIZE 9

void fillSudoku(FILE *file, int sudoku[9][9]){
    for (int row =0; row<SIZE; row++){
        for (int col = 0; col<SIZE; col++){
            fscanf(file, "%d", &sudoku[row][col]);
        }
    }
}

void printSudoku(int sudoku[SIZE][SIZE]){
    for (int row =0; row<SIZE; row++){
        for (int col = 0; col<SIZE; col++){
            printf("%d ", sudoku[row][col]);
        }
        printf("\n");
    }
}

void checkSumRow(int sudoku[SIZE][SIZE]){
    for (int row =0; row<SIZE; row++){
        int sum = 0;
        for (int col = 0; col<SIZE; col++){
            sum += sudoku[row][col];
        }
        if (sum != 45){
            printf("row %d does not add up to 45. it adds up to %d\n", row+1, sum);
        }
    }
}

void checkSumCol(int sudoku[SIZE][SIZE]){
    for (int col =0; col<SIZE; col++){
        int sum = 0;
        for (int row = 0; row<SIZE; row++){
            sum += sudoku[row][col];
        }
        if (sum != 45){
            printf("col %d does not add up to 45. it adds up to %d\n", col+1, sum);
        }
    }    
}

void checkSumSquares(int sudoku[SIZE][SIZE]){
    for (int blockRow =0; blockRow<SIZE; blockRow +=3){
        for (int blockCol =0; blockCol<SIZE; blockCol +=3){
            int sum = 0;
            for (int row =blockRow; row<blockRow+3; row++){
                for (int col =blockCol; col<blockCol+3; col++){
                    sum += sudoku[row][col];
                }
            }
            if (sum != 45){
                printf("block at position %d %d does not equal 45 it equals %d\n", (blockRow/3)+1, (blockCol/3)+1, sum);
            }
        }
    }
}

int main (){
    FILE *file = fopen("C:\\Users\\timos\\Documents\\CP\\C-programming\\sudoku.txt", "r");
    int sudoku[SIZE][SIZE];
    if(file == NULL) {
        printf("Not able to open the file.");
        return 1;
    }

    fillSudoku(file, sudoku);
    printSudoku(sudoku);
    checkSumRow(sudoku);
    checkSumCol(sudoku);
    checkSumSquares(sudoku);
fclose(file);
}