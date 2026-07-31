//
// Created by vsuni on 27/07/2026.
//
#include <raylib.h>
#include "gameMain.h"

#include <iostream>
#include <random>

#include "asserts.h"
#include "assetManager.h"
#include "gameMap.h"
#include "helpers.h"
#include "imgui.h"
#include "randomStuff.h"
#include "raymath.h"
#include "worldGenerator.h"


struct GameData
{
    GameMap gameMap;
    Camera2D camera;

}gameData;

AssetManager assetManager;

bool InitGame()
{
    assetManager.loadAll();

    generateWorld(gameData.gameMap, 144);

    gameData.camera.target = {0,0};
    gameData.camera.rotation = 0.0f;
    gameData.camera.zoom = 100.0f;

    return true;
}

bool UpdateGame()
{

    float deltaTime = GetFrameTime();
    if (deltaTime > 1.f / 6) { deltaTime = 1 / 5.f; }

    gameData.camera.offset = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};

    ClearBackground({75, 75, 150, 255});

    static float CAMERA_SPEED = 2.0f;
    if (IsKeyDown(KEY_A)) gameData.camera.target.x -= CAMERA_SPEED * deltaTime;
    if (IsKeyDown(KEY_D)) gameData.camera.target.x += CAMERA_SPEED * deltaTime;
    if (IsKeyDown(KEY_W)) gameData.camera.target.y -= CAMERA_SPEED * deltaTime;
    if (IsKeyDown(KEY_S)) gameData.camera.target.y += CAMERA_SPEED * deltaTime;

    ImGui::Begin("Block Selector");

    static int blockType = 0;
    ImGui::InputInt("Block Type", &blockType);

    ImGui::End();

    Vector2 worldPos = GetScreenToWorld2D(GetMousePosition(), gameData.camera);
    int blockX = (int)floor(worldPos.x);
    int blockY = (int)floor(worldPos.y);

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        if (blockType != 0)
            if (auto b = gameData.gameMap.getBlocSafe(blockX, blockY))
            {
                b->type = blockType;
            }

    if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
        if (auto b = gameData.gameMap.getBlocSafe(blockX, blockY))
        {
            *b = {};
        }

    BeginMode2D(gameData.camera);

    Vector2 topLeftView = GetScreenToWorld2D({0, 0}, gameData.camera);
    Vector2 bottomRightView = GetScreenToWorld2D({(float)GetScreenWidth(), (float)GetScreenHeight()}, gameData.camera);

    int startXView = (int)floorf(topLeftView.x - 1);
    int endXView = (int)ceilf(bottomRightView.x + 1);
    int startYView = (int)floorf(topLeftView.y - 1);
    int endYView = (int)ceilf(bottomRightView.y + 1);

    startXView = Clamp(startXView, 0, gameData.gameMap.w - 1);
    endXView = Clamp(endXView, 0, gameData.gameMap.w - 1);

    startYView = Clamp(startYView, 0, gameData.gameMap.h - 1);
    endYView = Clamp(endYView, 0, gameData.gameMap.h - 1);


    for (int y = startYView; y <= endYView; y++)
        for (int x = startXView; x <= endXView; x++)
        {
            auto &b = gameData.gameMap.getBlocUnsafe(x,y);

            if (b.type != Block::air)
            {
                DrawTexturePro(
                    assetManager.textures,
                    getTextureAtlas(b.type, 0, 32, 32),
                    {(float)x, (float)y, 1, 1},
                    {0, 0},
                    0.0f,
                    WHITE
                    );
            }
        }

    DrawTexturePro(
        assetManager.frame,
        getTextureAtlas(0, 0, 32, 32),
        {(float)blockX, (float)blockY, 1, 1},
        {0, 0},
        0.0f,
        WHITE
        );




    EndMode2D();

    ImGui::Begin("Game Controlls");

    ImGui::SliderFloat("Camera Zoom", &gameData.camera.zoom, 10, 150);
    ImGui::SliderFloat("Camera Speed", &CAMERA_SPEED, 1, 30);

    ImGui::End();

    DrawFPS(10, 10);
    return true;
}

void CloseGame()
{
}
