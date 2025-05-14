#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define SIZE 10
#define MAX_SIZE (SIZE + 1)

struct Waiting {
    int id;
    int nperson;
    char info[32];
};
typedef struct Waiting Element;
#include "CircularQueue.h"

int rand_num(int a, int b) {
    return rand() % (b - a + 1) + a;
}

double get_elapsed_sec(struct timeval start, struct timeval end) {
    return (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000.0;
}

int main(void) {
    srand((unsigned int)time(NULL));
    
    FILE* input_fp = fopen("/Users/Minho/Desktop/coding/input_csv.csv", "w+");
    FILE* output_fp = fopen("/Users/Minho/Desktop/coding/output.txt", "w+");
    
    if(input_fp == NULL || output_fp == NULL) {
        fprintf(stderr, "파일 열기에 실패했습니다.\n");
        exit(1);
    }
    
    // 1. 랜덤 데이터 생성 및 저장
    for (int i = 0; i < SIZE; i++) {
        int id = rand_num(1, 100);
        int nperson = rand_num(1, 8);
        int mid = rand_num(0, 9999);
        int back = rand_num(0, 9999);
        
        fprintf(input_fp, "%d,%d,010-%04d-%04d\n", id, nperson, mid, back);
    }
    rewind(input_fp);
    
    // 2. 파일에서 데이터를 읽어와 큐에 삽입
    Element waiting[SIZE];
    init_queue();
    for (int i = 0; i < SIZE; i++) {
        fscanf(input_fp, "%d,%d,%s", &waiting[i].id, &waiting[i].nperson, waiting[i].info);
        fprintf(output_fp, "[신청 완료] 대기번호: %d, 인원: %d명\n", waiting[i].id, waiting[i].nperson);
        enqueue(waiting[i]);
    }
    
    fprintf(output_fp, "\n=============================\n");
    fprintf(output_fp, "[입장 안내 시작]\n");
    
    // 3. 시간 측정을 위한 변수들 (gettimeofday 사용)
    struct timeval lastTime, currentTime;
    gettimeofday(&lastTime, NULL);
    double prev_elapsed = 0.0;
    double change_rate = 0.0;
    
    // 4. 큐가 빌 때까지 각 손님의 입장 시간 및 변화율 측정
    while (!is_empty()) {
        printf("엔터를 눌러 다음 손님을 입장시키세요...");
        // 입력 버퍼 클리어
        while(getchar() != '\n');
        
        gettimeofday(&currentTime, NULL);
        double elapsed_sec = get_elapsed_sec(lastTime, currentTime);
        lastTime = currentTime;
        
        Element w = dequeue();
        
        if(prev_elapsed > 0.0) {
            change_rate = (elapsed_sec - prev_elapsed) / prev_elapsed * 100.0;
        } else {
            change_rate = 0.0;
        }
        prev_elapsed = elapsed_sec;
        
        fprintf(output_fp, "[입장 안내] 대기번호: %d (%d명, %s)\n",
                w.id, w.nperson, w.info);
        fprintf(output_fp, " - 입장 소요 시간: %.2lf초\n", elapsed_sec);
        if(change_rate != 0.0) {
            fprintf(output_fp, " - 변화율: %.2lf%%\n", change_rate);
        }
        fprintf(output_fp, "\n");
    }
    
    fclose(input_fp);
    fclose(output_fp);
    
    return 0;
}
