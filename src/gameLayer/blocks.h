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

        BLOCKS_COUNT,
    };

    std::uint8_t var = 0;
    std::uint16_t type = 0;
};

