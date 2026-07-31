//
// Created by vsuni on 30/07/2026.
//

#include "worldGenerator.h"

#include "randomStuff.h"
#include <raymath.h>

void generateWorld(GameMap &gameMap, int seed)
{
    const int w = 900;
    const int h = 500;

    gameMap.create(w, h);

    std::ranlux24_base rng(seed);

    int keepDirDirtTime = getRandomInt(rng, 5, 40);
    int dirtDirection = getRandomInt(rng, -2, 2);

    int keepDirStoneTime = getRandomInt(rng, 5, 40);
    int stoneDirection = getRandomInt(rng, -2, 2);

    int stoneHeight = 350;
    int dirtHeight = 50;

    for (int x = 0; x < w; x++)
    {
        keepDirDirtTime--;
        if (keepDirDirtTime <= 0)
        {
            keepDirDirtTime = getRandomInt(rng, 5, 40);
            dirtDirection = getRandomInt(rng, -2, 2);
        }

        if (dirtDirection == -2)
        {
            if (getRandomChance(rng, 0.25))
                dirtHeight--;
            if (getRandomChance(rng, 0.25))
                dirtHeight--;
        }
        else if (dirtDirection == -1)
        {
            if (getRandomChance(rng, 0.25))
                dirtHeight--;
        }
        else if (dirtDirection == 1)
        {
            if (getRandomChance(rng, 0.25))
                dirtHeight++;
        }
        else if (dirtDirection == 2)
        {
            if (getRandomChance(rng, 0.25))
                dirtHeight++;
            if (getRandomChance(rng, 0.25))
                dirtHeight++;
        }

        if (dirtHeight < 50)
            dirtHeight = 50;


        if (dirtHeight > 90)
            dirtHeight = 90;

        //stone
        keepDirStoneTime--;
        if (keepDirStoneTime <= 0)
        {
            keepDirStoneTime = getRandomInt(rng, 5, 40);
            stoneDirection = getRandomInt(rng, -2, 2);
        }

        if (stoneDirection == -2)
        {
            if (getRandomChance(rng, 0.25))
                stoneHeight--;
            if (getRandomChance(rng, 0.25))
                stoneHeight--;
        }
        else if (stoneDirection == -1)
        {
            if (getRandomChance(rng, 0.25))
                stoneHeight--;
        }
        else if (stoneDirection == 1)
        {
            if (getRandomChance(rng, 0.25))
                stoneHeight++;
        }
        else if (stoneDirection == 2)
        {
            if (getRandomChance(rng, 0.25))
                stoneHeight++;
            if (getRandomChance(rng, 0.25))
                stoneHeight++;
        }

        if (stoneHeight < 320)
            stoneHeight = 320;


        if (stoneHeight > 400)
            stoneHeight = 400;




        for (int y = 0; y < h; y++)
        {
            Block b;

            if (y < h - (stoneHeight + dirtHeight))
            {
                b.type = Block::air;
            }
            else if (y == h - (stoneHeight + dirtHeight))
            {
                b.type = Block::grassBlock;
            }
            else if (y < h - stoneHeight)
            {
                b.type = Block::dirt;
            }
            else
            {
                b.type = Block::stone;
            }

            gameMap.getBlocUnsafe(x, y) = b;
        }
    }

}
