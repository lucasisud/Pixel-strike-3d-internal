#pragma once
#include "includes.h"
static bool playMusic = false;
#pragma comment(lib, "Winmm.lib")

void DrawUI()
{
    ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_Once);
    auto window_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoResize;
    if (ImGui::Begin("Pixel Strike - Base By 0SD47", nullptr, window_flags))
    {
        ImGui::Text("Pixel Strike - Base By 0SD47");
        if (ImGui::BeginTabBar("MainTabBar", ImGuiTabBarFlags_None))
        {
            if (ImGui::BeginTabItem("Aim"))
            {
                ImGui::Text("Aimbot Features");
                ImGui::Separator();
                ImGui::Spacing();
                ImGui::Checkbox("Aimbot", &aimbot);
                ImGui::Spacing();
                ImGui::Checkbox("Draw FOV", &showFov);
                ImGui::Spacing();
                ImGui::SliderFloat("FOV", &fov, 1.0f, 180.0f);
                ImGui::Spacing();
                ImGui::SliderFloat("Smoothness", &Smoothness, 1.0f, 70.0f);
                ImGui::Spacing();
                ImGui::Spacing();
                if (ImGui::Combo("Aim Key", &currentHotkey, HotKeys, IM_ARRAYSIZE(HotKeys))) {
                    aimKey = HotKeyCodes[currentHotkey];
                }
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("GamePlay"))
            {
                ImGui::Text("GamePlay Features");
                ImGui::Separator();
                ImGui::Spacing();
                ImGui::Checkbox("No Recoil", &norecoil);
                ImGui::Spacing();
                ImGui::Checkbox("Mass Loop Reload", &MassLoopReload);
                ImGui::Spacing();
                ImGui::Checkbox("Rapid Fire", &RapidFire);
                ImGui::Spacing();
                ImGui::Checkbox("Set Weapon", &SetWeapon);
                ImGui::Spacing();
                ImGui::Checkbox("Grenade Bullet", &GrenadeBullet);
                ImGui::SameLine();
                ImGui::TextColored(ImVec4(1.0f, 0.3f, 0.3f, 1.0f), "[Bannable]");
                ImGui::Spacing();
                ImGui::Checkbox("No Equipment Cooldown", &NoEquipmentCooldown);
                ImGui::Spacing();
                ImGui::Checkbox("ESP 2D", &esp2d);
                if (ImGui::Checkbox("Play music", &playMusic))
                {
                    if (playMusic)
                    {
                        PlaySound(TEXT("C:\\Users\\lucas\\Downloads\\Trevor Daniel - Falling (Official Music Video).wav"), NULL, SND_FILENAME | SND_ASYNC);
                    }
                    else
                    {
                        PlaySound(NULL, 0, 0); // Stop sound
                    }
                }

                ImGui::Spacing();
                ImGui::Spacing();
                if (ImGui::Button("Get Reward", ImVec2(140, 30)))
                {
                    GetReward = true;
                }
                else
                {
                    GetReward = false;
                }
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Movement"))
            {
                ImGui::Text("Movement Features");
                ImGui::Separator();
                ImGui::Spacing();
                ImGui::Checkbox("Speed Test", &SpeedTest);
                ImGui::SameLine();
                ImGui::TextColored(ImVec4(1.0f, 0.3f, 0.3f, 1.0f), "[Bannable]");
                ImGui::Spacing();
                if (SpeedTest)
                {
                    ImGui::SliderFloat("Speed Multiplier", &SpeedTestSlider, 0.0f, 120.0f, "%.1f");
                }
                ImGui::Spacing();
                ImGui::Checkbox("Jump Boost", &JumpBoost);
                ImGui::Spacing();
                ImGui::Checkbox("Fly", &Fly);
                ImGui::Spacing();
                ImGui::Checkbox("Infinite Jump", &InfiniteJump);
                ImGui::EndTabItem();
            }

            ImGui::EndTabBar();
        }
    }
    ImGui::End();
}
