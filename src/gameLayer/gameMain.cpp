//
// Created by vsuni on 27/07/2026.
//
#include <raylib.h>
#include "gameMain.h"
#include "asserts.h"
#include "assetManager.h"


struct GameData
{

    float PositionX = 100;
    float PositionY = 100;
}gameData;

assetManager assetManager;

bool InitGame()
{
    return true;
}

bool UpdateGame()
{

    float deltaTime = GetFrameTime();
    if (deltaTime < 1.f / 6) { deltaTime = 1 / 5.f; }



    return true;
}

void CloseGame()
{
}
