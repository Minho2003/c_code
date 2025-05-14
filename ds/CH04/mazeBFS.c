#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#define MAX_SIZE 100
struct Pos2D { int r; int c; };
typedef struct Pos2D Element;
#include "CircularDeque.h"

#define MAZE_DIM 6
char map[MAZE_DIM][MAZE_DIM];

void push_loc(int r, int c);
Element pop_loc(void);
void print_maze(FILE* fp);
void clear(void);
void nsleep(int n);


int main(void)
{
    FILE* fp_map=fopen("map.txt", "r");
    FILE* fp_output=fopen("output.txt", "w");

    if (fp_map == NULL) {
        printf("map.txt 파일을 열 수 없습니다.\n");
        return 1;
    }
    if (fp_output == NULL) {
        printf("output.txt 파일을 열 수 없습니다.\n");
        return 1;
    }
    
    
    for (int i=0; i<MAZE_DIM;i++){
        for ( int k=0; k<MAZE_DIM;k++){
            fscanf(fp_map, " %c", &map[i][k]);
        }
    }
    
    
    
    init_deque();       // 덱: 초기화
    push_loc(1, 0);     // 미로의 시작 위치를 저장
    int n=500;
    
    fclose(fp_map);
    
    while (is_empty() == 0) {
        clear();
        print_maze(fp_output);
        nsleep(n);

        Element here = pop_loc();
        int c = here.c;
        int r = here.r;
        if (map[r][c] == 'x') {
            printf("\n미로 탈출 성공\n");
            
            fprintf(fp_output,"\n미로 탈출 성공\n");
            return 0;
        }
        else {
            map[r][c] = '.';    // 방문함
            push_loc(r - 1, c); // 상
            push_loc(r + 1, c); // 하
            push_loc(r, c - 1); // 좌
            push_loc(r, c + 1); // 우
        }
    }
    printf("\n미로 탈출 실패\n");
    
    fclose(fp_output);

    return 0;
}

void push_loc(int r, int c)
{
    if (r < 0 || c < 0 || r >= MAZE_DIM || c >= MAZE_DIM)
        return; // 미로 범위 밖의 위치
    if (map[r][c] != '0' && map[r][c] != 'x')
        return; // 갈 수 있는 칸이 아님
    Element pos = { r, c };
    add_rear(pos);
}
Element pop_loc(void)
{
//    return delete_rear();       // 후단 삭제(스택의 pop)
     return delete_front();       // 후단 삭제(스택의 pop)
}

void print_maze(FILE* fp)
{
    Element here = get_rear();
    for (int r = 0; r < MAZE_DIM; r++) {
        for (int c = 0; c < MAZE_DIM; c++)
            if (here.r == r && here.c == c) {
                fprintf(fp,"@");
                printf("@");
            }
            else {
                fprintf(fp,"%c", map[r][c]);
                printf("%c", map[r][c]);
            }
        fprintf(fp, "\n");
        printf("\n");
    }
}

void clear(void){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void nsleep(int n){
#ifdef _WIN32
    Sleep(n);
#else
    usleep(n*1000);
#endif
}
