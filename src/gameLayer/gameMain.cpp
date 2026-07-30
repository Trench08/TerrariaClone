//
// Created by vsuni on 27/07/2026.
//
#include <raylib.h>
#include "gameMain.h"
#include "asserts.h"
#include "assetManager.h"
#include "gameMap.h"


struct GameData
{
    GameMap gameMap;

}gameData;

AssetManager assetManager;

bool InitGame()
{
    assetManager.loadAll();

    gameData.gameMap.create(30, 10);

    gameData.gameMap.getBlocUnsafe(0,0).type = Block::dirt;
    gameData.gameMap.getBlocUnsafe(1,1).type = Block::dirt;
    gameData.gameMap.getBlocUnsafe(2,2).type = Block::dirt;
    gameData.gameMap.getBlocUnsafe(3,3).type = Block::dirt;
    gameData.gameMap.getBlocUnsafe(4,4).type = Block::dirt;

    return true;
}

bool UpdateGame()
{

    float deltaTime = GetFrameTime();
    if (deltaTime < 1.f / 6) { deltaTime = 1 / 5.f; }

    ClearBackground({75, 75, 150, 255});

    for (int y = 0; y < gameData.gameMap.h; y++)
        for (int x = 0; x < gameData.gameMap.w; x++)
        {
            auto &b = gameData.gameMap.getBlocUnsafe(x,y);

            if (b.type != Block::air)
            {
                float size = 32;
                float posX = x * size;
                float posY = y * size;

                DrawTexturePro(
                    assetManager.dirt,
                    Rectangle{0.f, 0.f, 32.f, 32.f},
                    {posX, posY, size, size},
                    {0, 0},
                    0.0f,
                    WHITE
                    );
            }
        }



    return true;
}

void CloseGame()
{
}
