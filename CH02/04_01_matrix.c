#include "CMH.h"

#define ROWS 3
#define COLS 3

void print_mat(int(* p)[COLS], char* str, FILE* fp);
void transpose_mat(int(* p)[COLS]);

int main(void){
    FILE* fp1=fopen("/Users/Minho/Desktop/coding/input.txt", "r");
    FILE* fp2=fopen("/Users/Minho/Desktop/coding/output.txt","a+");
    
    int mat[ROWS][COLS] = { 4, 0, 1, 1, 6, 5, 7, 3, 6 };
    
    print_mat(mat, "원래 행렬", fp2);
    transpose_mat(mat);
    print_mat(mat, "전치 행렬", fp2);
    
    fclose(fp1);
    fclose(fp2);
    system("open /Users/Minho/Desktop/coding/output.txt");
    return 0;
}

void print_mat(int(* p)[COLS], char* str, FILE* fp){
    fprintf(stdout, "%s\n", str);
    fprintf(fp, "%s\n", str);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fprintf(stdout, " %3d", p[i][j]);
            fprintf(fp, " %3d", p[i][j]);
        }
        fprintf(stdout, "\n");
        fprintf(fp, "\n");
    }
}

void transpose_mat(int(* p)[COLS]){
    for (int i = 0; i < sizeof(p); i++) {
        for (int j = i+1; j < COLS; j++) {
            int tmp = p[i][j];
            p[i][j] = p[j][i];
            p[j][i] = tmp;
        }
    }
}
