#include "screen.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

// 화면 타이틀 틀
int clearBuffer(char* screenBuf, int width, int height)
{
	int i = 0;	/* 가로 index */
	int j = 0;  /* 세로 index */
	while (j < height)
	{
		while (i < width + 1) /* 개행문자때문에 + 1*/
		{
			if (i == width)
				screenBuf[i + (j * (width + 1))] = '\n';
			else
			{
				if (i == 0 || i == (width - 1) || j == 0 || j == (height - 1))
					screenBuf[i + (j * (width + 1))] = '#';
				else
					screenBuf[i + (j * (width + 1))] = ' ';
			}
			i = i + 1;
		}
		i = 0;
		j = j + 1;
	}
	screenBuf[height * (width + 1) - 1] = '\0';
    Sleep(500); 
}

// 화면 미연시 틀
int clearSceneBuffer(char* screenBuf, int width, int height)
{
	int i = 0;	/* 가로 index */
	int j = 0;  /* 세로 index */
	while (j < height)
	{
		while (i < width + 1) /* 개행문자때문에 + 1*/
		{
			if (i == width)
				screenBuf[i + (j * (width + 1))] = '\n';
			else
			{
				if (i == 0 || i == (width - 1) || j == 0 || j == (height - 1))
					screenBuf[i + (j * (width + 1))] = '*';
                else if (i == 1 || i == (width - 2))
					screenBuf[i + (j * (width + 1))] = '|';
                else if (j == 1 || j == (height - 2))
					screenBuf[i + (j * (width + 1))] = '-';
                else if (j == 1 || j == (height - 6))
					screenBuf[i + (j * (width + 1))] = '_';
				else
					screenBuf[i + (j * (width + 1))] = ' ';
			}
			i = i + 1;
		}
		i = 0;
		j = j + 1;
	}
	screenBuf[height * (width + 1) - 1] = '\0';
    Sleep(500); 
}

// 화면 글자 출력
int writeStringToBuffer(char* screenBuf,const char* string, int x, int y, int width)
{
int i = 0;
while (string[i] !='\0')
{
    screenBuf[x + i + (y * (width + 1))] = string[i];
    i++;
}
return 0;
}

// 화면 글자 애니메이션
int writeStringAnimeToBuffer(char* screenBuf,const char* string, int x, int y, int width)
{
    int i = 0;
    while (string[i] !='\0')
    {
        screenBuf[x + i + (y * (width + 1))] = string[i];
        system("cls");
        printf("%s\n", screenBuf);  // 현재까지의 버퍼 상태 출력
        Sleep(100);  // 출력 되는 시간(1초)
        i++;
    }
    Sleep(500); //출력이 끝났으면 기다리는 초
    return 0;
}

// 로징창
void setLoadingAnimation()
{
    system("cls");
    const char animationFrames[4][13] = {
        "loading     ",
        "loading.    ",
        "loading..   ",
        "loading..."
    };

    const int numFrames = 4;
    const int delay = 100; // 애니메이션 간 지연 시간 (밀리초)

    int frameIndex = 0;
    int i;

    for (i = 0; i < 30; i++) {
        printf("%s", animationFrames[frameIndex]);

        // 현재 프레임 출력 후 출력 위치를 맨 앞으로 이동
        int j;
        for (j = 0; j < strlen(animationFrames[frameIndex]); j++) {
            printf("\b");
        }

        frameIndex = (frameIndex + 1) % numFrames;

        Sleep(delay);
    }
}

// 게임 타이틀 화면
int setTitleToScreenBuffer(char* screenBuf, int width, int height)
{
    // title 설정
    system("cls");
    clearBuffer(screenBuf,30,12);

    writeStringToBuffer(screenBuf,"Rhythm_University",7,3,width);
    writeStringToBuffer(screenBuf,"1. start",11,6,width);
    writeStringToBuffer(screenBuf,"2. menu",11,7,width);
    writeStringToBuffer(screenBuf,"3. exit",11,8,width);

    printf("%s\ninput> ", screenBuf);
    return 0;
}

// 게임 나가기 화면
int setGameExitToScreenBuffer(char* screenBuf, int width, int height)
{
   // game exit 설정
    system("cls");
    clearBuffer(screenBuf,30,12);

    writeStringToBuffer(screenBuf,"game exit",10,4,width);
    writeStringToBuffer(screenBuf,"1. [yes]",4,7,width);
    writeStringToBuffer(screenBuf,"2. [no]",19,7,width);
    
    printf("%s\ninput> ", screenBuf);
    return 0;
}

// 게임 메뉴 화면
int setGameMenuToScreenBuffer(char* screenBuf, int width, int height)
{
    // game exit 설정
    system("cls");
    clearBuffer(screenBuf,30,12);

    writeStringToBuffer(screenBuf,"{ *game menu* }",8,0,width);
    writeStringToBuffer(screenBuf,"clear the rhythm game",4,2,width);
    writeStringToBuffer(screenBuf,"to clear the rhythm game",3,3,width);
    writeStringToBuffer(screenBuf,"choose one answer",6,4,width);
    writeStringToBuffer(screenBuf,"At last you will play",4,5,width);
    writeStringToBuffer(screenBuf,"rhythm game key",7,6,width);
    writeStringToBuffer(screenBuf,"[ S D J K ]",9,7,width);
    writeStringToBuffer(screenBuf,"1. [back]",3,9,width);
    writeStringToBuffer(screenBuf,"2. [stay]",17,9,width);

    printf("%s\ninput> ", screenBuf);
    return 0;
}

// 첫번째 시나리오
// 첫 번째 씬
int setFirstSceneScreenBuffer(char* screenBuf, int width, int height)
{
    clearSceneBuffer(screenBuf,45,20);

    writeStringToBuffer(screenBuf,"<Rhythm_University>",12,1,width);
    writeStringToBuffer(screenBuf,"202327016_Choi_Se_Chang",11,19,width);
    writeStringAnimeToBuffer(screenBuf,"You gotta go to college",11,15,width);
    writeStringAnimeToBuffer(screenBuf,"Do you wanna go now?",11,16,width);
    writeStringToBuffer(screenBuf,"1. [yes]",9,17,width);
    writeStringToBuffer(screenBuf,"2. [no]",29,17,width);
    
    Sleep(300);
    system("cls");
    printf("%s\ninput> ", screenBuf);

    return 0;
}
int setFirstScene1ScreenBuffer(char* screenBuf, int width, int height)
{
    clearSceneBuffer(screenBuf,45,20);

    writeStringToBuffer(screenBuf,"<Rhythm_University>",12,1,width);
    writeStringToBuffer(screenBuf,"202327016_Choi_Se_Chang",11,19,width);
    writeStringAnimeToBuffer(screenBuf,"Great, let's go!",15,16,width);
    
    Sleep(300);
    system("cls");
    printf("%s\ninput> ", screenBuf);

    return 0;
}
int setFirstScene2ScreenBuffer(char* screenBuf, int width, int height)
{
    clearSceneBuffer(screenBuf,45,20);

    writeStringToBuffer(screenBuf,"<Rhythm_University>",12,1,width);
    writeStringToBuffer(screenBuf,"202327016_Choi_Se_Chang",11,19,width);
    writeStringAnimeToBuffer(screenBuf,"Wrong answer, just leave now!",9,16,width);
    
    Sleep(300);
    system("cls");
    printf("%s\ninput> ", screenBuf);

    return 0;
}
// 두번째 씬
int setSecondSceneScreenBuffer(char* screenBuf, int width, int height)
{
    clearSceneBuffer(screenBuf,45,20);

    writeStringToBuffer(screenBuf,"<Rhythm_University>",12,1,width);
    writeStringToBuffer(screenBuf,"202327016_Choi_Se_Chang",11,19,width);
    
    //학교 화면
    writeStringToBuffer(screenBuf,"_________________________________",6,2,width);
    writeStringToBuffer(screenBuf,"|  _________         _________  |",6,3,width);
    writeStringToBuffer(screenBuf,"|  |___|___|         |___|___|  |",6,4,width);
    writeStringToBuffer(screenBuf,"|  |___|___|         |___|___|  |",6,5,width);
    writeStringToBuffer(screenBuf,"|                               |",6,6,width);
    writeStringToBuffer(screenBuf,"|          ___________          |",6,7,width);
    writeStringToBuffer(screenBuf,"|          |    |    |          |",6,8,width);
    writeStringToBuffer(screenBuf,"|          |  * | *  |          |",6,9,width);
    writeStringToBuffer(screenBuf,"|          |    |    |          |",6,10,width);
    writeStringToBuffer(screenBuf,"---------------------------------",6,11,width);

    writeStringAnimeToBuffer(screenBuf,"You arrived at college",12,15,width);
    writeStringAnimeToBuffer(screenBuf,"You just saw the professor",10,16,width);
    writeStringAnimeToBuffer(screenBuf,"What would you say?",14,17,width); 
    writeStringToBuffer(screenBuf,"1. [Hey professor, what's up?]",8,12,width);
    writeStringToBuffer(screenBuf,"2. [What's today's class?]",8,13,width);
    
    Sleep(300);
    system("cls");
    printf("%s\ninput> ", screenBuf);

    return 0;
}
int setSecondScene1ScreenBuffer(char* screenBuf, int width, int height)
{
    clearSceneBuffer(screenBuf,45,20);

    writeStringToBuffer(screenBuf,"<Rhythm_University>",12,1,width);
    writeStringToBuffer(screenBuf,"202327016_Choi_Se_Chang",11,19,width);
    writeStringAnimeToBuffer(screenBuf,"Not well",19,16,width);

    
    Sleep(300);
    system("cls");
    printf("%s\ninput> ", screenBuf);

    return 0;
}
int setSecondScene2ScreenBuffer(char* screenBuf, int width, int height)
{
    clearSceneBuffer(screenBuf,45,20);

    writeStringToBuffer(screenBuf,"<Rhythm_University>",12,1,width);
    writeStringToBuffer(screenBuf,"202327016_Choi_Se_Chang",11,19,width);
    writeStringAnimeToBuffer(screenBuf,"No class today only assignment",8,16,width);

    Sleep(300);
    system("cls");
    printf("%s\ninput> ", screenBuf);

    return 0;
}
// 세번째 씬
int setThird1SceneScreenBuffer(char* screenBuf, int width, int height)
{
    clearSceneBuffer(screenBuf,45,20);

    writeStringToBuffer(screenBuf,"<Rhythm_University>",12,1,width);
    writeStringToBuffer(screenBuf,"202327016_Choi_Se_Chang",11,19,width);
    writeStringAnimeToBuffer(screenBuf,"I'm in a bad mood because",10,15,width);
    writeStringAnimeToBuffer(screenBuf,"everyone didn't do their homework",6,16,width);
    
    Sleep(300);
    system("cls");
    printf("%s\ninput> ", screenBuf);

    return 0;
}
int setThird2SceneScreenBuffer(char* screenBuf, int width, int height)
{
    clearSceneBuffer(screenBuf,45,20);

    writeStringToBuffer(screenBuf,"<Rhythm_University>",12,1,width);
    writeStringToBuffer(screenBuf,"202327016_Choi_Se_Chang",11,19,width);
    writeStringAnimeToBuffer(screenBuf,"because",19,15,width);
    writeStringAnimeToBuffer(screenBuf,"everyone didn't do their homework",6,16,width);
    
    Sleep(300);
    system("cls");
    printf("%s\ninput> ", screenBuf);

    return 0;
}
int setThird3SceneScreenBuffer(char* screenBuf, int width, int height)
{
    clearSceneBuffer(screenBuf,45,20);

    writeStringToBuffer(screenBuf,"<Rhythm_University>",12,1,width);
    writeStringToBuffer(screenBuf,"202327016_Choi_Se_Chang",11,19,width);
    writeStringAnimeToBuffer(screenBuf,"So in that sense, do this",10,16,width);
    
    Sleep(300);
    system("cls");
    printf("%s\ninput> ", screenBuf);

    return 0;
}
int setSceneAnswer1ScreenBuffer(char* screenBuf, int width, int height)
{
    clearSceneBuffer(screenBuf,45,20);

    writeStringToBuffer(screenBuf,"<Rhythm_University>",12,1,width);
    writeStringToBuffer(screenBuf,"202327016_Choi_Se_Chang",11,19,width);
    writeStringAnimeToBuffer(screenBuf,"[Hey professor, what's up?]",9,16,width);
    
    Sleep(300);
    system("cls");
    printf("%s\ninput> ", screenBuf);

    return 0;
}
int setSceneAnswer2ScreenBuffer(char* screenBuf, int width, int height)
{
    clearSceneBuffer(screenBuf,45,20);

    writeStringToBuffer(screenBuf,"<Rhythm_University>",12,1,width);
    writeStringToBuffer(screenBuf,"202327016_Choi_Se_Chang",11,19,width);
    writeStringAnimeToBuffer(screenBuf,"[What's today's class?]",11,16,width);
    
    Sleep(300);
    system("cls");
    printf("%s\ninput> ", screenBuf);

    return 0;
}
// 네번째 씬
int setFourthSceneScreenBuffer(char* screenBuf, int width, int height)
{
    clearSceneBuffer(screenBuf,45,20);

    writeStringToBuffer(screenBuf,"<Rhythm_University>",12,1,width);
    writeStringToBuffer(screenBuf,"202327016_Choi_Se_Chang",11,19,width);
    writeStringAnimeToBuffer(screenBuf,"Hmm... That's bad",14,16,width);
    
    Sleep(300);
    system("cls");
    printf("%s\ninput> ", screenBuf);

    return 0;
}
int setFourth1SceneScreenBuffer(char* screenBuf, int width, int height)
{
    clearSceneBuffer(screenBuf,45,20);

    writeStringToBuffer(screenBuf,"<Rhythm_University>",12,1,width);
    writeStringToBuffer(screenBuf,"202327016_Choi_Se_Chang",11,19,width);
    writeStringAnimeToBuffer(screenBuf,"take a break time",13,16,width);
    
    Sleep(300);
    system("cls");
    printf("%s\ninput> ", screenBuf);

    return 0;
}
// 엔딩
int setEndSceneScreenBuffer(char* screenBuf, int width, int height)
{
    clearSceneBuffer(screenBuf,45,20);

    writeStringToBuffer(screenBuf,"<Rhythm_University>",12,1,width);
    writeStringToBuffer(screenBuf,"202327016_Choi_Se_Chang",11,19,width);

    //학교 화면
    writeStringToBuffer(screenBuf,"_________________________________",6,3,width);
    writeStringToBuffer(screenBuf,"|  _________         _________  |",6,4,width);
    writeStringToBuffer(screenBuf,"|  |___|___|         |___|___|  |",6,5,width);
    writeStringToBuffer(screenBuf,"|  |___|___|         |___|___|  |",6,6,width);
    writeStringToBuffer(screenBuf,"|                               |",6,7,width);
    writeStringToBuffer(screenBuf,"|                               |",6,8,width);
    writeStringToBuffer(screenBuf,"|          ___________          |",6,9,width);
    writeStringToBuffer(screenBuf,"|          |    |    |          |",6,10,width);
    writeStringToBuffer(screenBuf,"|          |  * | *  |          |",6,11,width);
    writeStringToBuffer(screenBuf,"|          |    |    |          |",6,12,width);
    writeStringToBuffer(screenBuf,"---------------------------------",6,13,width);

    writeStringAnimeToBuffer(screenBuf,"Game End",18,15,width);
    writeStringAnimeToBuffer(screenBuf,"If you want to continue",11,16,width);
    writeStringAnimeToBuffer(screenBuf,"Go to This Link",15,17,width);
    
    Sleep(300); //3초 대기
    system("cls");
    printf("%s", screenBuf);

    return 0;
}