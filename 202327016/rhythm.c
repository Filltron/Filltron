#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <mmsystem.h>

#define SCREEN_WIDTH 31
#define SCREEN_HEIGHT 32

typedef struct {
    int x;
    int y;
    bool isVisible;
} Note;

int noteSpeed = 1;

void updateNotes(Note *notes, int *noteCount, int *score, int *combo) {
    static int frameCount = 0;

    if (frameCount % 5 == 0) {
        int x = 0;
        int option = rand() % 4;

        switch (option) {
            case 0:
                x = 2;
                break;
            case 1:
                x = 9;
                break;
            case 2:
                x = 16;
                break;
            case 3:
                x = 23;
                break;
        }

        notes[*noteCount].x = x;
        notes[*noteCount].y = 0;
        notes[*noteCount].isVisible = true;
        (*noteCount)++;
    }

    int comboReset = 0; // 콤보 초기화 여부를 나타내는 변수

    for (int i = 0; i < *noteCount; i++) {
        notes[i].y += noteSpeed;

        if (notes[i].y >= SCREEN_HEIGHT - 2) {
            if (notes[i].isVisible) {
                notes[i].isVisible = false;
                comboReset = 1; // 노트를 놓칠 경우 콤보 초기화
            }
        } 
        else if (notes[i].y == 28 && notes[i].isVisible) {
            // 사용자 입력에 따라 노트를 맞췄을 때 점수와 콤보 증가
            if (notes[i].x == 2 && _kbhit() && _getch() == 's') {
                notes[i].isVisible = false;
                (*score) += 300; // 노트를 맞춘 경우 점수 증가
                (*combo)++; // 콤보 증가
            }
            else if (notes[i].x == 9 && _kbhit() && _getch() == 'd') {
                notes[i].isVisible = false;
                (*score) += 300; // 노트를 맞춘 경우 점수 증가
                (*combo)++; // 콤보 증가
            }
            else if (notes[i].x == 16 && _kbhit() && _getch() == 'j') {
                notes[i].isVisible = false;
                (*score) += 300; // 노트를 맞춘 경우 점수 증가
                (*combo)++; // 콤보 증가
            }
            else if (notes[i].x == 23 && _kbhit() && _getch() == 'k') {
                notes[i].isVisible = false;
                (*score) += 300; // 노트를 맞춘 경우 점수 증가
                (*combo)++; // 콤보 증가
            }
        }
        else if (notes[i].y == 27 && notes[i].isVisible) {
            if (notes[i].x == 2 && _kbhit() && _getch() == 's') {
                notes[i].isVisible = false;
                (*score) += 100; 
                (*combo)++; 
            }
            else if (notes[i].x == 9 && _kbhit() && _getch() == 'd') {
                notes[i].isVisible = false;
                (*score) += 100; 
                (*combo)++; 
            }
            else if (notes[i].x == 16 && _kbhit() && _getch() == 'j') {
                notes[i].isVisible = false;
                (*score) += 100; 
                (*combo)++; 
            }
            else if (notes[i].x == 23 && _kbhit() && _getch() == 'k') {
                notes[i].isVisible = false;
                (*score) += 100; 
                (*combo)++; 
            }
        }
        else if (notes[i].y == 29 && notes[i].isVisible) {
            if (notes[i].x == 2 && _kbhit() && _getch() == 's') {
                notes[i].isVisible = false;
                (*score) += 50;
                (*combo)++; 
            }
            else if (notes[i].x == 9 && _kbhit() && _getch() == 'd') {
                notes[i].isVisible = false;
                (*score) += 50;
                (*combo)++;
            }
            else if (notes[i].x == 16 && _kbhit() && _getch() == 'j') {
                notes[i].isVisible = false;
                (*score) += 50; 
                (*combo)++; 
            }
            else if (notes[i].x == 23 && _kbhit() && _getch() == 'k') {
                notes[i].isVisible = false;
                (*score) += 50; 
                (*combo)++; 
            }
        }
    }

    // 콤보 초기화 여부를 확인하여 콤보를 초기화
    if (comboReset) {
        (*combo) = 0;
    }

    frameCount++;
}

// 음악 재생
DWORD WINAPI playMusic(LPVOID lpParam) {
    PlaySound(TEXT("testing 70.wav"), NULL, SND_ASYNC);
    Sleep(78000); // 5초간 대기
    return 0;
}

//게임 화면
void clearGameBuffer(char* screenBuf, int width, int height) {

    int i = 0;
    int j = 0;
    while (j < height) {
        while (i < width + 1) {
            if (i == width)
                screenBuf[i + (j * (width + 1))] = '\n';
            else {
                if (j == 31)
                    screenBuf[i + (j* (width + 1))] = ' ';
                else if (i == 0 || i == (width - 1) || j == 0 || j == (height - 1) || j == (height - 2))
                    screenBuf[i + (j * (width + 1))] = '#';
                else if (i == 1 || i == (width - 2) || i == 8 || i == (width - 9) || i == 15)
                    screenBuf[i + (j * (width + 1))] = '|';
                else if (j == (height - 5))
                    screenBuf[i + (j * (width + 1))] = '_';
                else if (j == (height - 3) && i > 1 && i < (width - 2))
                    screenBuf[i + (j * (width + 1))] = 'T';
                else if (j == 1)
                    screenBuf[i + (j * (width + 1))] = '=';
                else if (j == height)
                    screenBuf[i + (j* (width + 1))] = ' ';
                else
                    screenBuf[i + (j * (width + 1))] = ' ';
            }
            i = i + 1;
        }
        i = 0;
        j = j + 1;
    }
    screenBuf[height * (width + 1) - 1] = '\0';
}

// 게임 글자 출력
void drawScreen(Note *notes, int noteCount, int score, int combo) {
    char screenBuf[SCREEN_WIDTH * (SCREEN_HEIGHT + 1)];

    clearGameBuffer(screenBuf, SCREEN_WIDTH, SCREEN_HEIGHT);

    // 점수 출력
    char scoreText[19];
    sprintf(scoreText, "[ Score: %d ]", score);
    int scoreX = (SCREEN_WIDTH - strlen(scoreText)) / 2;
    int scoreY = SCREEN_HEIGHT - 1;
    for (int i = 0; i < strlen(scoreText); i++) {
        screenBuf[scoreX + i + 1 + (scoreY * (SCREEN_WIDTH + 1))] = scoreText[i];
    }

    // 콤보 출력
    char comboString[] = "Combo";
    int comboStringLength = sizeof(comboString) - 1;
    int comboValue = combo; // 콤보 숫자
    int comboValueLength = snprintf(NULL, 0, "%d", comboValue); // 콤보 숫자의 길이 계산
    int comboX = (SCREEN_WIDTH - comboValueLength - comboStringLength + 1 ) / 2; // 콤보 문자의 X 좌표
    int comboY = (SCREEN_HEIGHT - 14) / 2; // 콤보 문자의 Y 좌표
    int comboValueY = comboY - 1; // 콤보 숫자의 Y 좌표 (콤보 문자 위로 이동)

    // 콤보 문자 출력
    for (int i = 0; i < comboStringLength; i++) {
        screenBuf[comboX + i + (comboY * (SCREEN_WIDTH + 1))] = comboString[i];
    }

    // 콤보 숫자 출력
    char comboValueString[10];
    snprintf(comboValueString, sizeof(comboValueString), "%d", comboValue);
    int comboValueStringLength = strlen(comboValueString);

    int comboValueX = (SCREEN_WIDTH - comboValueStringLength) / 2; // 콤보 숫자의 X 좌표

    for (int i = 0; i < comboValueStringLength; i++) {
        screenBuf[comboValueX + i + (comboValueY * (SCREEN_WIDTH + 1))] = comboValueString[i];
    }
    
    // 노트 출력
    for (int i = 0; i < noteCount; i++) {
        int x = notes[i].x;
        int y = notes[i].y;

        if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT && notes[i].isVisible) {
            // 다중 문자열 복사
            char noteString[] = "@@@@";
            int noteStringLength = sizeof(noteString) - 1; // null 종료 문자 제외

            // screenBuf에 문자열 복사
            for (int j = 0; j < noteStringLength; j++) {
                screenBuf[x + 1 + ((y + 1) * (SCREEN_WIDTH + 1)) + j] = noteString[j];
            }
        }
    }

    system("cls");
    printf("%s", screenBuf);
}

int RhythmGame() {

    Note notes[100];
    int noteCount = 0;
    int score = 0;
    int combo = 0;
    
    HANDLE musicThread = CreateThread(NULL, 0, playMusic, NULL, 0, NULL);

    srand((unsigned int)time(NULL));

    bool isNoteDestroyed = false;

    while (true) {
        updateNotes(notes, &noteCount, &score, &combo);
        drawScreen(notes, noteCount, score, combo);

        if (_kbhit()) {
            char key = _getch();
            if (key == 'S' || key == 's') {
                for (int i = 0; i < noteCount; i++) {
                    if (notes[i].x == 2 && notes[i].y == 28 && notes[i].isVisible) {
                        notes[i].isVisible = false;
                        isNoteDestroyed = true;
                        break;
                    }
                }
            }
            else if (key == 'D' || key == 'd') {
                for (int i = 0; i < noteCount; i++) {
                    if (notes[i].x == 9 && notes[i].y == 28 && notes[i].isVisible) {
                        notes[i].isVisible = false;
                        isNoteDestroyed = true;
                        break;
                    }
                }
            }
            else if (key == 'J' || key == 'j') {
                for (int i = 0; i < noteCount; i++) {
                    if (notes[i].x == 16 && notes[i].y == 28 && notes[i].isVisible) {
                        notes[i].isVisible = false;
                        isNoteDestroyed = true;
                        break;
                    }
                }
            }
            else if (key == 'K' || key == 'k') {
                for (int i = 0; i < noteCount; i++) {
                    if (notes[i].x == 23 && notes[i].y == 28 && notes[i].isVisible) {
                        notes[i].isVisible = false;
                        isNoteDestroyed = true;
                        break;
                    }
                }
            }
        }

        if (isNoteDestroyed) {
            isNoteDestroyed = false;
        }
        int remainingNotes = 0;
            for (int i = 0; i < noteCount; i++) {
                if (notes[i].isVisible) {
                    remainingNotes++;
                }
            }

            if (remainingNotes == 0 || WaitForSingleObject(musicThread, 0) == WAIT_OBJECT_0) {
                system("cls");
                printf("Your[ Score: %d ]", score);
                break;
            }

            Sleep(150);
            continue; // 노트가 사라졌으므로 게임 루프를 다시 시작
    }
    
    // 스레드가 종료될 때까지 대기
    WaitForSingleObject(musicThread, INFINITE);

    CloseHandle(musicThread);

    return 0;
}
