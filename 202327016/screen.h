// 화면 타이틀 틀, 미연시 틀
int clearBuffer(char* screenBuf, int width, int height);
int clearSceneBuffer(char* screenBuf, int width, int height);

// 게임 글자, 글자 애니메이션
int writeStringToBuffer(char* screenBuf,const char* string, int x, int y, int width);
int writeStringAnimeToBuffer(char* screenBuf,const char* string, int x, int y, int width);

// 로징창
void setLoadingAnimation();

// 게임 타이틀,나가기,메뉴
int setTitleToScreenBuffer(char* screenBuf, int width, int height);
int setGameExitToScreenBuffer(char* screenBuf, int width, int height);
int setGameMenuToScreenBuffer(char* screenBuf, int width, int height);

// 게임 시나리오
// 첫번째 씬
int setFirstSceneScreenBuffer(char* screenBuf, int width, int height);
int setFirstScene1ScreenBuffer(char* screenBuf, int width, int height);
int setFirstScene2ScreenBuffer(char* screenBuf, int width, int height);
//두번째 씬
int setSecondSceneScreenBuffer(char* screenBuf, int width, int height);
int setSecondScene1ScreenBuffer(char* screenBuf, int width, int height);
int setSecondScene2ScreenBuffer(char* screenBuf, int width, int height);
// 세번째 씬
int setThird1SceneScreenBuffer(char* screenBuf, int width, int height);
int setThird2SceneScreenBuffer(char* screenBuf, int width, int height);
int setThird3SceneScreenBuffer(char* screenBuf, int width, int height);
int setSceneAnswer1ScreenBuffer(char* screenBuf, int width, int height);
int setSceneAnswer2ScreenBuffer(char* screenBuf, int width, int height);
//네번째 씬
int setFourthSceneScreenBuffer(char* screenBuf, int width, int height);
int setFourth1SceneScreenBuffer(char* screenBuf, int width, int height);
int setFourth1SceneScreenBuffer(char* screenBuf, int width, int height);
//엔딩 씬
int setEndSceneScreenBuffer(char* screenBuf, int width, int height);

// 게임
int RhythmGame();