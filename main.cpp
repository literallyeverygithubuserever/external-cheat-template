#include <Windows.h>
#include <iostream>
#include "window.hpp"
#include "Memory.h"
#include <thread>

int main()
{
	CDispatcher* mem = CDispatcher::Get();
	mem->Attach("FortniteClient-Win64-Shipping.exe"); // Change the executable to the game you're attaching this to.
	uint64_t base = mem->GetModuleBase("FortniteClient-Win64-Shipping.exe"); // Change the executable to the game you're attaching this to.

	overlay.shouldRun = true;
	overlay.RenderMenu = false;

	overlay.CreateOverlay();
	overlay.CreateDevice();
	overlay.CreateImGui();

	printf("[>>] Press ~ to show the menu!/n");

	overlay.SetForeground(GetConsoleWindow());

	while (overlay.shouldRun)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));

		overlay.StartRender();

		if (overlay.RenderMenu) {
			overlay.Render();
		}
		else
			ImGui::GetBackgroundDrawList()->AddText({ 0, 0 }, ImColor(245.0f, 0.0f, 31.0f), "External Cheat Template by @literallyeverygithubuserever on Github - Press ~ to use");

		if (drawCrosshair)
		{
			ImVec2 screenSize = ImGui::GetIO().DisplaySize;
			ImVec2 center(screenSize.x * 0.5f, screenSize.y * 0.5f);
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(center.x - 20, center.y - 10), ImVec2(center.x + 20, center.y - 32), IM_COL32(57, 255, 20, 220), 0.3f);
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(center.x, center.y - 32), ImVec2(center.x, center.y + 10), IM_COL32(57, 255, 20, 220), 0.3f);
		}
		if (showEsp)
		{
			// swagger
		}
		if (showBulletESP)
		{
			// swagger
		}
		overlay.EndRender();
	}

	overlay.DestroyImGui();
	overlay.DestroyDevice();
	overlay.DestroyOverlay();
}