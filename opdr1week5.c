#include <stdio.h>
void printFile(char content[100], FILE *file, int size){
    while (fgets(content, size, file)){
        printf("%s", content);
    }
    printf("\n");
}

void checkSumRow(FILE *file){
    rewind(file);
    int numbers[81];
    char content[100];
    int count = 0;

    while (fgets(content, sizeof(content), file)){
        for (int i=0; content[i] != '\0'; i++){
            if (content[i] >= '0' && content[i] <= '9'){
                numbers[count++] = content[i] - '0';
            }
        }
    }
    int sum = 0;
    int index = 0;
    for (int row = 0; row<9; row++){
        for (int col = 0; col<9; col++){
            sum += numbers[index++];
        }
        if (sum != 45){
            printf("row %d does not equal 45, it equals %d\n", row, sum);
        }
        sum = 0;
    }


}
int main (){
    FILE *file = fopen("C:\\Users\\timos\\Downloads\\sudoku.txt", "r");
    char filecontent[100];
    if(file == NULL) {
        printf("Not able to open the file.");
        return 1;
    }
    printFile(filecontent, file, sizeof(filecontent));
    checkSumRow(file);
fclose(file);
}