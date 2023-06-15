#include <stdio.h>
#include "screen.h"
#include <windows.h>

int main()
{
    char screenBuf[1365];
    int input = 0;

    setTitleToScreenBuffer(screenBuf,30,15);
    scanf("%d", &input);

    while (input <= 4)
    if(input == 1)
    {
        setLoadingAnimation();
        setFirstSceneScreenBuffer(screenBuf, 45, 20);
        scanf("%d", &input);
        if(input == 1)
        {
            setFirstScene1ScreenBuffer(screenBuf, 45, 20);
            setLoadingAnimation();
            setSecondSceneScreenBuffer(screenBuf, 45, 20);
            scanf("%d", &input);
                if(input == 1)
                {
                    setSceneAnswer1ScreenBuffer(screenBuf, 45, 20);
                    setSecondScene1ScreenBuffer(screenBuf, 45, 20);
                    setThird1SceneScreenBuffer(screenBuf, 45, 20);
                    setThird3SceneScreenBuffer(screenBuf,45, 20);
                    setLoadingAnimation();
                    RhythmGame();
                    printf("\nTo [Continue] Press 4");
                    printf("input> ");
                    scanf("%d", &input);
                }
                if(input == 2)
                {
                    setSceneAnswer2ScreenBuffer(screenBuf, 45, 20);
                    setSecondScene2ScreenBuffer(screenBuf, 45, 20);
                    setThird2SceneScreenBuffer(screenBuf, 45, 20);
                    setThird3SceneScreenBuffer(screenBuf,45, 20);
                    setLoadingAnimation();
                    RhythmGame();
                    printf("\nTo [Continue] Press 4");
                    printf("\ninput> ");
                    scanf("%d", &input);
                }
        }
        if(input == 2)
        {
            setFirstScene2ScreenBuffer(screenBuf, 45, 20);
            Sleep(300);
            setLoadingAnimation();
            setSecondSceneScreenBuffer(screenBuf, 45, 20);
            scanf("%d", &input);
                if(input == 1)
                {
                    setSceneAnswer1ScreenBuffer(screenBuf, 45, 20);
                    setSecondScene1ScreenBuffer(screenBuf, 45, 20);
                    setThird1SceneScreenBuffer(screenBuf, 45, 20);
                    setThird3SceneScreenBuffer(screenBuf,45, 20);
                    setLoadingAnimation();
                    RhythmGame();
                    printf("\nTo [Continue] Press 4\n");
                    printf("input> ");
                    scanf("%d", &input);
                }
                if(input == 2)
                {
                    setSceneAnswer2ScreenBuffer(screenBuf, 45, 20);
                    setSecondScene2ScreenBuffer(screenBuf, 45, 20);
                    setThird2SceneScreenBuffer(screenBuf, 45, 20);
                    setThird3SceneScreenBuffer(screenBuf,45, 20);
                    setLoadingAnimation();
                    RhythmGame();
                    printf("\nTo [Continue] Press 4");
                    printf("\ninput> ");
                    scanf("%d", &input);
                }
        }
    }
    else if(input == 2)
    {
        setLoadingAnimation();
        setGameMenuToScreenBuffer(screenBuf,30,15);
        scanf("%d", &input);
    if (input == 1)
    {
        setLoadingAnimation();
        setTitleToScreenBuffer(screenBuf,30,15);
        scanf("%d", &input);
    }
    else
    {
        setLoadingAnimation();
        setGameMenuToScreenBuffer(screenBuf,30,15);
        scanf("%d", &input);
    }
    }

    else if (input == 3)
    {
        setLoadingAnimation();
        setGameExitToScreenBuffer(screenBuf,30,15);
        scanf("%d", &input);

        if(input == 1)
        {
            break;
        }
        else
        {
            setLoadingAnimation();
            setTitleToScreenBuffer(screenBuf,30,15);
            scanf("%d", &input);
        }
    }
    else if(input == 4)
    {
        setLoadingAnimation();
        setFourthSceneScreenBuffer(screenBuf, 45, 20); 
        setFourth1SceneScreenBuffer(screenBuf, 45, 20);
        setEndSceneScreenBuffer(screenBuf, 45, 20);
        break;
    }

    else
    {
        break;
    }

    return 0;
}