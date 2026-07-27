#include <iostream>
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

#include "gameMain.h"

int main()
{

#if PRODUCTION_BUILD == 1
    SetTraceLogLevel(LOG_NONE);
#endif

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 450, "TerrariaClone");
    SetExitKey(KEY_NULL);
    SetTargetFPS(240);

#pragma region ImGui

    rlImGuiSetup(true);

    ImGuiIO  &io = ImGui::GetIO();
    io.FontGlobalScale = 2;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

#pragma endregion ImGui

    if (!InitGame())
    {
        return 0;
    }

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        rlImGuiBegin();

        ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
        ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
        ImGui::PopStyleColor(2);

        if (!UpdateGame())
        {
            return 0;
        }

        ImGui::Begin("Test");

        ImGui::Text("Hello");
        ImGui::Button("Test 2");

        ImGui::End();

        rlImGuiEnd();

        EndDrawing();
    }

    CloseWindow();

    CloseGame();

    rlImGuiShutdown();
    return 0;
}
