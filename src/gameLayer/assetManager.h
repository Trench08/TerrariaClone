//
// Created by vsuni on 29/07/2026.
//
#pragma once
#include "raylib.h"


struct AssetManager
{
    Texture2D dirt = {};
    Texture2D textures = {};
    Texture2D frame = {};

    void loadAll();
};

