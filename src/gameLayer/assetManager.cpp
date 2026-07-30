//
// Created by vsuni on 29/07/2026.
//

#include "assetManager.h"

void AssetManager::loadAll()
{
    dirt = LoadTexture(RESOURCES_PATH "/dirt.png");
    Atlas = LoadTexture(RESOURCES_PATH "/textures.png");
}