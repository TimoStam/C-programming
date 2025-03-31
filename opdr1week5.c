#include <stdio.h>

void fillSudoku(FILE *file, int sudoku[9][9]){
    for (int row =0; row<9; row++){
        for (int col = 0; col<9; col++){
            fscanf(file, "%d", &sudoku[row][col]);
        }
    }
}

void printSudoku(int sudoku[9][9]){
    for (int row =0; row<9; row++){
        for (int col = 0; col<9; col++){
            printf("%d ", sudoku[row][col]);
        }
        printf("\n");
    }
}

void checkSumRow(int sudoku[9][9]){
    for (int row =0; row<9; row++){
        int sum = 0;
        for (int col = 0; col<9; col++){
            sum += sudoku[row][col];
        }
        if (sum != 45){
            printf("row %d does not add up to 45. it adds up to %d\n", row+1, sum);
        }
    }
}

void checkSumCol(int sudoku[9][9]){
    for (int col =0; col<9; col++){
        int sum = 0;
        for (int row = 0; row<9; row++){
            sum += sudoku[row][col];
        }
        if (sum != 45){
            printf("col %d does not add up to 45. it adds up to %d\n", col+1, sum);
        }
    }    
}

int main (){
    FILE *file = fopen("C:\\Users\\timos\\Documents\\CP\\C-programming\\sudoku.txt", "r");
    int sudoku[9][9];
    if(file == NULL) {
        printf("Not able to open the file.");
        return 1;
    }

    fillSudoku(file, sudoku);
    printSudoku(sudoku);
    checkSumRow(sudoku);
    checkSumCol(sudoku);


fclose(file);
}