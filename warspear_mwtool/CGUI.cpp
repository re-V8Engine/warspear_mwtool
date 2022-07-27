#include "stdafx.h"

namespace ImGui
{
	static auto vector_getter = [](void* vec, int idx, const char** out_text)
	{
		auto& vector = *static_cast<std::vector<std::string>*>(vec);
		if (idx < 0 || idx >= static_cast<int>(vector.size())) { return false; }

		//string str(vector.at(idx).begin(), vector.at(idx).end());
		*out_text = vector.at(idx).c_str();
		return true;
	};

	bool Combo(const char* label, int* currIndex, std::vector<std::string>& values)
	{
		if (values.empty()) { return false; }
		return Combo(label, currIndex, vector_getter,
			static_cast<void*>(&values), values.size());
	}

	bool ListBox(const char* label, int* currIndex, std::vector<std::string>& values)
	{
		if (values.empty()) { return false; }
		return ListBox(label, currIndex, vector_getter,
			static_cast<void*>(&values), values.size());
	}

}

void CGUI::SetStyle(float alpha_)
{
	ImGuiStyle& style = ImGui::GetStyle();

	ImVec4* colors = ImGui::GetStyle().Colors;
	style.Alpha = 1.0f;
	style.FrameRounding = 0.0f;
	style.WindowRounding = 0;

	colors[ImGuiCol_Text] = ImVec4(1.04f, 1.04f, 1.04f, 1.09f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.17f, 0.17f, 0.17f, 1.00f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.15f, 0.15f, 0.15f, 1.03f);
	colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.11f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.32f, 0.32f, 0.32f, 0.42f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.98f, 0.98f, 0.98f, 0.44f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.94f, 0.94f, 0.94f, 0.74f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.16f, 0.16f, 0.16f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.10f, 1.10f, 1.10f, 0.56f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.24f, 0.24f, 0.24f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.11f, 0.11f, 0.11f, 0.58f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.69f, 0.69f, 0.69f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.59f, 0.59f, 0.59f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.49f, 0.49f, 0.49f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.33f, 0.33f, 0.33f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.42f, 0.42f, 0.42f, 0.44f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.17f, 0.17f, 0.17f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.40f, 0.40f, 0.40f, 0.34f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.33f, 0.33f, 0.33f, 0.88f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.85f, 0.85f, 0.85f, 1.00f);
	colors[ImGuiCol_Separator] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(1.10f, 1.10f, 1.10f, 0.86f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(1.10f, 1.10f, 1.10f, 0.55f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.87f, 0.88f, 0.88f, 0.81f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.97f, 0.97f, 0.97f, 1.04f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 0.25f, 0.25f, 0.42f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.10f, 1.10f, 0.00f, 0.99f);
	colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.10f, 1.10f, 1.10f, 0.77f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.88f, 0.88f, 0.88f, 0.22f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.22f, 0.22f, 0.22f, 0.38f);
	colors[ImGuiCol_Tab] = ImVec4(0.46f, 0.46f, 0.46f, 0.95f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.22f, 0.22f, 0.22f, 0.88f);
	colors[ImGuiCol_TabActive] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);

	for (int i = 0; i <= ImGuiCol_COUNT; i++)
	{
		ImVec4& col = style.Colors[i];
		if (col.w < 1.00f)
		{
			col.x *= alpha_;
			col.y *= alpha_;
			col.z *= alpha_;
			col.w *= alpha_;
		}
	}
}

void CGUI::ShowLog(bool* p_open)
{
	static ExampleAppLog log;

	// For the demo: add a debug button _BEFORE_ the normal log window contents
	// We take advantage of a rarely used feature: multiple calls to Begin()/End() are appending to the _same_ window.
	// Most of the contents of the window will be added by the log.Draw() call.
	ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_FirstUseEver);
	ImGui::Begin("Example: Log", p_open);
	if (ImGui::SmallButton("[Debug] Add 5 entries"))
	{
		static int counter = 0;
		for (int n = 0; n < 5; n++)
		{
			const char* categories[3] = { "info", "warn", "error" };
			const char* words[] = { "Bumfuzzled", "Cattywampus", "Snickersnee", "Abibliophobia", "Absquatulate", "Nincompoop", "Pauciloquent" };
			log.AddLog("[%05d] [%s] Hello, current time is %.1f, here's a word: '%s'\n",
				ImGui::GetFrameCount(), categories[counter % IM_ARRAYSIZE(categories)], ImGui::GetTime(), words[counter % IM_ARRAYSIZE(words)]);
			counter++;
		}
	}
	ImGui::End();

	// Actually call in the regular Log helper (which will Begin() into the same window as we just did)
	log.Draw("Example: Log", p_open);
}


void CGUI::ShowEntityList()
{
	//ImGui::Begin("Entity List", pOpen, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse);
	if (ImGui::BeginTabBar("Entity List"))
	{
		if (ImGui::BeginTabItem("Alive"))
		{
			ImGui::Text("Total: %i", coun);
			coun = 0;
			for (auto entity : *pAlive)
			{
				char name[20];
				wcstombs(name, entity.name, 20);
				ImGui::Text("%s Health: %i", &name, entity.health);
				coun++;
			}
			
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Dead"))
		{
			for (auto entity : *pCorpse)
			{
				char name[20];
				wcstombs(name, entity.name, 20);
				ImGui::Text("%s", &name);
			}
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Collectable"))
		{
			for (auto entity : *pCollectable)
			{
				char name[20];
				wcstombs(name, entity.name, 20);
				ImGui::Text("%s", &name);
			}
			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}
	
	//ImGui::End();
}

void CGUI::ShowBot()
{
	vector<string> names;
	for (auto entity : *pAlive)
	{
		char name[20];
		wcstombs(name, entity.name, 20);
		if (find(names.begin(), names.end(), name) == names.end())
		{
			names.push_back(name);
		}
	}
	//ImGui::Begin("Bot", pOpen);
	
	ImGui::Text("Area");
	ImGui::SliderInt("X", &areaX, 0, 10);
	ImGui::SliderInt("Y", &areaY, 0, 10);
	ImGui::GetWindowDrawList()->AddRect(ImVec2(0, 0), ImVec2(100, 100), IM_COL32(255,255,255,0));
	static int current = 0;
	ImGui::Combo("Choose target", &current, names);
	ImGui::Checkbox("Loot", &bLoot);

	
	//ImGui::End();
}

void CGUI::ShowLocalPlayer()
{
	char name[20];
	wcstombs(name, player->name, 20);
	string info = "Name: " + string(name) + "\n"
		+ "Health: " + to_string(player->health) + "\n"
		+ "State: " + to_string(player->anim) + "\n"
		+ "Position" + "\n"
		+ "X = " + to_string(player->posX) + " Y = " + to_string(player->posY) + "\n"
		+ "Destination" + "\n"
		+ "X = " + to_string(player->destinatonX) + " Y = " + to_string(player->destinatonY) + "\n";
	ImGui::Begin("LocalPlayer");
	ImGui::Text(info.c_str());
	ImGui::End();
}

void CGUI::ShowPetMode()
{
	static char target[20];
	ImGui::InputText("Choose target", target, IM_ARRAYSIZE(target));

}

void CGUI::ShowMainMenu()
{
	ImGui::Begin("Warspear MWTool :: Author: V8Engine");
	if (ImGui::BeginTabBar("Main Menu"))
	{
		if (ImGui::BeginTabItem("Entities"))
		{
			ShowEntityList();
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("FarmBot"))
		{
			ShowBot();
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Pet Mode"))
		{
			ShowPetMode();
			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}
	ImGui::End();
}

void CGUI::Build()
{
	
	// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
	if (show_demo_window)
		ImGui::ShowDemoWindow(&show_demo_window);
	//ShowLog(&show_demo_window);
	

	// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
	{
		static float f = 0.0f;
		static int counter = 0;

		ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

		ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
		ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
		ImGui::Checkbox("Another Window", &show_another_window);

		ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
		ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

		if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
			counter++;
		ImGui::SameLine();
		ImGui::Text("counter = %d", counter);

		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();
	}



	// 3. Show another simple window.
	if (show_another_window)
	{
		ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
		ImGui::Text("Hello from another window!");
		if (ImGui::Button("Close Me"))
			show_another_window = false;
		ImGui::End();
	}
	ShowMainMenu();
	ShowLocalPlayer();

}
void CGUI::Setup(Entity* player, vector<Entity>* pAlive, vector<Entity>*pCorpse, vector<Entity>* pCollectable)
{
	this->player = player;
	this->pAlive = pAlive;
	this->pCorpse = pCorpse;
	this->pCollectable = pCollectable;
	//Init frame
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	CGUI::Build(); //build menu
	// Render here
	//end frame
	ImGui::EndFrame();
}



void CGUI::Render()
{
	

	//CWindow::update(); //window update

	//D3D
	//CDirectX::BeginRender();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
	//CDirectX::EndRender();
}
CGUI::CGUI(HWND hwnd, IDirect3DDevice9Ex* device)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsClassic();

	// Setup Platform/Renderer bindings
	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX9_Init(device);



	//Setup style
	SetStyle(1.1f);

	// Load Fonts
	// - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
	// - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
	// - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
	// - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
	// - Read 'misc/fonts/README.txt' for more instructions and details.
	// - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
	//io.Fonts->AddFontDefault();
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
	//ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
	//IM_ASSERT(font != NULL);
	io.Fonts->AddFontFromFileTTF("imgui/fonts/SF.ttf", 18.0f);
	io.Fonts->AddFontDefault();
	ImFont* font = io.Fonts->AddFontFromFileTTF("imgui/fonts/SF.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());

	// Our state
	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
}
CGUI::~CGUI()
{
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}
