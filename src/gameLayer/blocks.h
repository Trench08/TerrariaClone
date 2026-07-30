//
// Created by vsuni on 30/07/2026.
//
#pragma once
#include <cstdint>


struct Block
{
    enum
    {
        air = 0,
        dirt,
        grasBlock,
        stone,
        grass,
        sand,
        sandRuby,
        sandStone,
        woodPlanks,
        stoneBricks,
        clay,
        woodLog,
        leaves,
        copper,
        iron,
        gold,
        copperBlock,
        ironBlock,
        goldBlock,
        brickBlock,
        snow,
        ice,
        rubyBlock,
        platform,
        workBench,
        glass,
        furnace,
        painting,
        sappling,
        snowBlueRuby,
        blueRubyBlock,
        door,
        iar,
        table,
        wordrobe,
        bookShelf,
        snowBricks,
        iceTable,
        iceWordrobe,
        iceBookShelf,
        icePlatform,
        sandTable,
        sandWordrobe,
        sandBookShelf,
        sandPlatform,
        woodenChest,
        iceChest,
        sandChest,
        boneChest,
        boneBricks,
        boneBench,
        boneWordrobe,
        boneBookShelf,
        bonePlatform,

        BLOCKS_COUNT,
    };

    std::uint8_t var = 0;
    std::uint16_t type = 0;
};

