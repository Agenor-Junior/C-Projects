#pragma once
#define LENGTH_MIN 10
#define LENGTH_MAX 70
#define LIVES_MIN  1
#define LIVES_MAX  10
#define DIVISOR    5

//-----------------------------------------------------------PLAYER INFO
struct PlayerInfo
{
    char namePlayer;
    int  nLives;
    int  treasures;
    char positHist[LENGTH_MAX];
};

//-------------------------------------------------------------GAME INFO
struct GameInfo
{
    int moves;
    int pathLenght;
    int setBomb[LENGTH_MAX];
    int setTreas[LENGTH_MAX];
    int tenMap[LENGTH_MAX];
    int unitMap[LENGTH_MAX];
};
