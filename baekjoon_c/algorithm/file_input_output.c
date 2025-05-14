#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#define DIRECTORY "/Users/Minho/Desktop/coding"


int main(void) {
    FILE *inputFile, *outputFile;
    int number;
    DIR *dir;
    struct dirent *entry;
    char filepath[256];
    int found = 0;

    // 디렉터리 열기
    dir = opendir(DIRECTORY);
    if (dir == NULL) {
        perror("디렉터리 열기 실패");
        return 1;
    }
    
    // 파일 경로 설정
        snprintf(filepath, sizeof(filepath), "%s/%s", DIRECTORY, "output.txt");
    
    // 입력 파일 열기 (읽기 모드)
    inputFile = fopen("/Users/Minho/Desktop/coding/baekjoon_test_c.c/text_file/input.txt", "r");
    if (inputFile == NULL) {
        perror("입력 파일 열기 실패");
        return 1;
    }

    // 출력 파일 열기 (쓰기 모드, 기존 파일 덮어쓰기)
    outputFile = fopen(filepath,"a");
    if (outputFile == NULL) {
        perror("출력 파일 생성 실패");
        fclose(inputFile);
        return 1;
    }

    // input.txt에서 숫자 읽고, output.txt에 제곱값 저장
    while (fscanf(inputFile, "%d", &number) == 1) {
        fprintf(outputFile, "%d의 제곱: %d\n", number, number * number);
    }

    // 파일 닫기
    fclose(inputFile);
    fclose(outputFile);

    printf("출력 파일 저장 완료: output.txt\n");
    printf("출력값 저장 완료: %s\n", filepath);

    return 0;
}
