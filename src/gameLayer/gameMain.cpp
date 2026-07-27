//
// Created by vsuni on 27/07/2026.
//
#include <raylib.h>
#include "gameMain.h"

#include <iostream>

struct GameData
{

    float PositionX = 100;
    float PositionY = 100;
}gameData;


bool InitGame()
{
    return true;
}

bool UpdateGame()
{

    float deltaTime = GetFrameTime();
    if (deltaTime < 1.f / 6) { deltaTime = 1 / 5.f; }

    Color c;
    c.r = 255;
    c.g = 0;
    c.b = 200;
    c.a = 255;



    if (IsKeyDown(KEY_A)){ gameData.PositionX -= 20 * deltaTime; };
    if (IsKeyDown(KEY_D)){ gameData.PositionX += 20 * deltaTime; }
    if (IsKeyDown(KEY_W)){ gameData.PositionY -= 20 * deltaTime; }
    if (IsKeyDown(KEY_S)){ gameData.PositionY += 20 * deltaTime; }

    DrawRectangle(gameData.PositionX, gameData.PositionY, 50, 50, c);

    return true;
}

void CloseGame()
{
    std::cout << "\n\nCLOSED!!!!!!!!!\n\n";
}
