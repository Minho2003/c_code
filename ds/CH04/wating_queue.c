#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

#define MAX_SIZE (SIZE+1)    // 배열의 크기
struct Waiting {        // 대기 정보 구조체
    int id;             // 대기번호
    int nperson;        // 인원
    char info[32];      // 전화번호
};
typedef struct Waiting Element;
#include "CircularQueue.h"

//손님이 N 명일떄 걸리는 시간

int rand_num(int a, int b){
    return rand()%(b-a+1)+a;
}

int main(void)
{
    srand((unsigned int)time(NULL));
    FILE* input_fp=fopen("/Users/Minho/Desktop/coding/input_csv.csv", "r+");
    FILE* output_fp=fopen("/Users/Minho/Desktop/coding/output.txt", "w+");
    
    if(input_fp == NULL || output_fp == NULL) {
        fprintf(stderr, "파일 열기에 실패했습니다.\n");
        exit(1);
    }
    
    clock_t start = 0, end;
    
    
    
//    fprintf(input_fp,"id, nperson, phone number\n");
    for (int i=0;i<SIZE;i++){
        int id_num=rand_num(1, 100);
        int nperson_num=rand_num(1, 8);
        int mid=rand_num(0,9999);
        int back=rand_num(0,9999);
        
        fprintf(input_fp,"%d, %d, 010-%04d-%04d\n",id_num,nperson_num,mid,back);
    }
//    char line[100];

    rewind(input_fp);
//    fgets(line, sizeof(line), input_fp);

    
    Element waiting[SIZE];
    
        init_queue();
        for (int i = 0; i < SIZE; i++) {
            fscanf(input_fp, "%d,%d,%s\n",&waiting[i].id,&waiting[i].nperson,waiting[i].info);

            fprintf(output_fp,"웨이팅 신청을 완료했습니다. 대기번호: %d번 인원:%d명\n",
                waiting[i].id, waiting[i].nperson);
            fprintf(stdout,"웨이팅 신청을 완료했습니다. 대기번호: %d번 인원:%d명\n",
                waiting[i].id, waiting[i].nperson);
            enqueue(waiting[i]);
        }
    fprintf(output_fp,"\n-----------------------------------------------------\n\n");
    start=clock();
        while (!is_empty()) {
            getchar();
            end=clock();
            Element w = dequeue();
//            fprintf(output_fp,"웨이팅 번호 %d번 입장하실 차례입니다. (%d명, %s)\n",
//                w.id, w.nperson, w.info);
            fprintf(output_fp,"웨이팅 번호 %d번 입장하실 차례입니다. (%d명, %s)\n걸린 시간 : %lu시간 %lu분\n",
                w.id, w.nperson, w.info, ((end-start)*2/60),((end-start)*2%60));
            start=clock();
        }
    
    fclose(input_fp);
    fclose(output_fp);
    
    
    return 0;
}
