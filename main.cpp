//Spyro Code Utility was created using the ImGui DirectX9 example file as a starting point for the GUI. This is why you may see comments related to ImGui.



// Dear ImGui: standalone example application for DirectX 9
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs





#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_dx9.h"
#include "imgui/backends/imgui_impl_win32.h"
#include <d3d9.h>
#include <tchar.h>
#include "imgui/dirent.h"
#include "imgui/imfilebrowser.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stdio.h>



// Data
static LPDIRECT3D9              g_pD3D = NULL;
static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp = {};

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void ResetDevice();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);




//Help Marker not included in any included files

static void HelpMarker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}





// Main code
int main(int, char**)
{
    // Create application window
    //ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T("Spyro Practice Code Utility"), NULL };
    ::RegisterClassEx(&wc);
    HWND hwnd = ::CreateWindow(wc.lpszClassName, _T("Spyro Code Utility"), WS_OVERLAPPEDWINDOW, 550, 100, 765, 850, NULL, NULL, wc.hInstance, NULL);

    // Initialize Direct3D
    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);

    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;



    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);




    bool hasButtonBeenPressed = false;
    bool hasDeathButtonBeenPressed = false;
    bool fileOpened = false;
    bool hasCodeBeenCreated = false;


    ImGui::FileBrowser fileDialog;

    // (optional) set browser properties
    fileDialog.SetTitle("Open File");
    fileDialog.SetTypeFilters({ ".txt" });





















    // Main loop
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        // Poll and handle messages (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        if (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            continue;
        }






        // Start the Dear ImGui frame
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();












        // SPYRO CODE UTILITY CODE
        // SPYRO CODE UTILITY CODE
        // SPYRO CODE UTILITY CODE
        // SPYRO CODE UTILITY CODE




       // Declaring all Variables


        static int gameChoice = 0;
        static int currentButtonCombo = 0;
        std::string currentButtonComboCode;
        std::string spyroX1Address;
        std::string spyroX2Address;
        std::string spyroY1Address;
        std::string spyroY2Address;
        std::string spyroZ1Address;
        std::string spyroZ2Address;
        std::string spyroAngleAddress;
        std::string camX1Address;
        std::string camX2Address;
        std::string camY1Address;
        std::string camY2Address;
        std::string camZ1Address;
        std::string camZ2Address;
        std::string camYaw1Address;
        std::string camYaw2Address;
        std::string camYaw3Address;
        std::string camYaw4Address;
        std::string camYaw5Address;
        std::string camYaw6Address;

        std::string spyroRespawnL2;
        std::string spyroRespawnL4;
        std::string spyroRespawnL6;



        std::string lbcSpyroX1;
        std::string lbcSpyroX2;
        std::string lbcSpyroY1;
        std::string lbcSpyroY2;
        std::string lbcSpyroZ1;
        std::string lbcSpyroZ2;
        std::string lbcSpyroAngle;
        std::string lbcCamX1;
        std::string lbcCamX2;
        std::string lbcCamY1;
        std::string lbcCamY2;
        std::string lbcCamZ1;
        std::string lbcCamZ2;
        std::string lbcCamYaw1;
        std::string lbcCamYaw2;
        std::string lbcCamYaw3;
        std::string lbcCamYaw4;
        std::string lbcCamYaw5;
        std::string lbcCamYaw6;

        std::string sparxHealthAddress;
        std::string sparxHealthValue;
        std::string infiniteLivesCode;

        std::string jokerCommand;



        std::string myData;
        std::string myData2;
        std::string myData3;
        std::string myData4;
        std::string myData5;
        std::string myData6;
        std::string myData7;
        std::string myData8;
        std::string myData9;  //may need less than this, but why not :p


     //same with these




        std::string gameSharkCodeJoker;
        std::string gameSharkCodeL2;
        std::string gameSharkCodeL4;
        std::string gameSharkCodeL6;
        std::string gameSharkCodeL8;
        std::string gameSharkCodeL10;
        std::string gameSharkCodeL12;
        std::string gameSharkCodeL14;
        std::string gameSharkCodeL16;
        std::string gameSharkCodeL18;
        std::string gameSharkCodeL20;
        std::string gameSharkCodeL22;
        std::string gameSharkCodeL24;
        std::string gameSharkCodeL26;
        std::string gameSharkCodeL28;
        std::string gameSharkCodeL30;
        std::string gameSharkCodeL32;
        std::string gameSharkCodeL34;
        std::string gameSharkCodeL36;
        std::string gameSharkCodeL38;
        std::string gameSharkCodeL40;
        std::string gameSharkCodeL42;
        std::string gameSharkCodeL44;




        char gscCharJoker[15];
        char gscCharL2[15];
        char gscCharL4[15];
        char gscCharL6[15];
        char gscCharL8[15];
        char gscCharL10[15];
        char gscCharL12[15];
        char gscCharL14[15];
        char gscCharL16[15];
        char gscCharL18[15];
        char gscCharL20[15];
        char gscCharL22[15];
        char gscCharL24[15];
        char gscCharL26[15];
        char gscCharL28[15];
        char gscCharL30[15];
        char gscCharL32[15];
        char gscCharL34[15];
        char gscCharL36[15];
        char gscCharL38[15];
        char gscCharL40[15];
        char gscCharL42[15];
        char gscCharL44[15];


        std::string fullGamesharkCode;      //string that contains the full gameshark code with new lines after each code ends
        char fullGamesharkCodeChar[1000];
        bool gscCreated;


        int LINE;
        int LINE2;
        int LINE3;
        int LINE4;
        int LINE5;
        int LINE6;
        int LINE7;
        int LINE8;
        int LINE9;

        static bool publicSparxCheck = false;
        static bool publicLivesCheck = false;
        static bool publicPopstarterCheck = false;



        std::string txtFile;
        char txtFileChar[100];





        char* buttonCombosSpyro23[] = { "L2 + R2 + X", "L2 + R2 + Circle", "L2 + R2 + Triangle", "L2 + R2 + Square", "L2 + Circle + Triangle", "R2 + Circle + Triangle", "L1 + L2 + Cross", "L1 + L2 + Square", "L1 + L2 + Circle", "L1 + L2 + Triangle", "R1 + R2 + Cross", "R1 + R2 + Square", "R1 + R2 + Circle", "R1 + R2 + Triangle" };
        char* buttonCombosSpyro1[] = { "L2 + R2 + X", "L2 + R2 + Circle", "L2 + R2 + Triangle", "L2 + R2 + Square", "L2 + Circle + Triangle", "R2 + Circle + Triangle" };



        // Create the Window

        ImGui::Begin("Spyro Code Utility");


        if (hasCodeBeenCreated == false)
        {
            //ImGui::ShowDemoWindow();
            ImGui::Text("Choose Game");

            ImGui::RadioButton("Spyro 1", &gameChoice, 0); ImGui::SameLine();
            ImGui::RadioButton("Spyro 2", &gameChoice, 1); ImGui::SameLine();
            ImGui::RadioButton("Spyro 3 1.0", &gameChoice, 2); ImGui::SameLine();
            ImGui::RadioButton("Spyro 3 1.1", &gameChoice, 3); ImGui::SameLine();
            HelpMarker(
                "Spyro 3 has two versions, a 1.0 version, and a 1.1 version which is the Collector's Edition/Greatest Hits version. It's important to choose the right version as codes for one will not be compatiable with the other.");

            if (ImGui::Button("Open Bizhawk Dump"))
                fileDialog.Open();
            ImGui::SameLine();
            HelpMarker("This is where you open your Bizhawk Hex Dump. You create a dump by opening the Hex Editor in Bizhawk by clicking Tools -> Hex Editor. Then, once you are in the position you want to save in game, inside the Hex Editor you click File -> Save as Text...\nYou then open that file here.");

        }


        fileDialog.Display();

        if (fileDialog.HasSelected())
        {


            txtFile = fileDialog.GetSelected().string();
            strcpy_s(txtFileChar, 100, txtFile.c_str());
            // std::cout << "Selected filename" << txtFile << std::endl;
            fileDialog.Close();
            fileOpened = true;
        }


        if (fileOpened == true)     //made it so rest of gui appears after opening file to avoid errors
        {
            if (hasCodeBeenCreated == false)      //here to remove this text once code button has been pressed
            {
                ImGui::Text("File Opened Successfully!");
            }




            std::ifstream f1(txtFileChar);
            std::ifstream f2(txtFileChar);
            std::ifstream f3(txtFileChar);
            std::ifstream f4(txtFileChar);
            std::ifstream f5(txtFileChar);
            std::ifstream f6(txtFileChar);
            std::ifstream f7(txtFileChar);
            std::ifstream f8(txtFileChar);
            std::ifstream f9(txtFileChar);



            if (hasCodeBeenCreated == false)
            {
                ImGui::NewLine();
                ImGui::Text("Choose Button Combination");

                if (gameChoice == 0)
                {
                    ImGui::Combo("", &currentButtonCombo, buttonCombosSpyro1, IM_ARRAYSIZE(buttonCombosSpyro1));
                    ImGui::SameLine();
                    HelpMarker("This is the button combination you choose to activate your code.");
                    ImGui::NewLine();


                }

                if (gameChoice == 1 || gameChoice == 2 || gameChoice == 3)
                {
                    ImGui::Combo("", &currentButtonCombo, buttonCombosSpyro23, IM_ARRAYSIZE(buttonCombosSpyro23));
                    ImGui::SameLine();
                    HelpMarker("This is the button combonation you choose to activate your code.");
                    ImGui::NewLine();
                }

                if (ImGui::TreeNode("Extras"))
                {
                    ImGui::NewLine;
                    static bool sparxCheck = false;
                    ImGui::Checkbox("Sprax Health Trigger", &sparxCheck);
                    ImGui::SameLine();
                    HelpMarker("This will instantly change Sparx's current health points/color."
                        "You activate the code by inputting the button combination you chose above.");


                    if (sparxCheck == false)
                        publicSparxCheck = false;



                    if (sparxCheck == true)
                    {
                        const char* sparxCombo[] = { "Yellow", "Blue", "Green", "No Sparx" };
                        static int sparxComboCurrent = 0;
                        ImGui::Combo("Color/Health", &sparxComboCurrent, sparxCombo, IM_ARRAYSIZE(sparxCombo));
                        if (sparxComboCurrent == 0)
                        {
                            sparxHealthValue = "0003";
                            publicSparxCheck = true;
                        }
                        if (sparxComboCurrent == 1)
                        {
                            sparxHealthValue = "0002";
                            publicSparxCheck = true;
                        }
                        if (sparxComboCurrent == 2)
                        {
                            sparxHealthValue = "0001";
                            publicSparxCheck = true;
                        }
                        if (sparxComboCurrent == 3)
                        {
                            sparxHealthValue = "0000";
                            publicSparxCheck = true;
                        }
                    }

                    ImGui::NewLine;
                    static bool livesCheck = false;
                    ImGui::Checkbox("Infinite Lives Code", &livesCheck);
                    ImGui::SameLine();
                    HelpMarker("This will keep Spyro's lives at 99 indefinitely");



                    if (livesCheck == true)
                    {
                        publicLivesCheck = true;
                    }

                    if (livesCheck == false)
                        publicLivesCheck = false;



                    ImGui::TreePop();
                }
                ImGui::Text(" ");

























            }






            static int buttonClicked = 0;



            if (hasCodeBeenCreated == false)
            {

                for (int i = 0; i < 1; i++)
                {
                    if (i > 0)
                        ImGui::SameLine();
                    ImGui::PushID(i);
                    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(5 / 7.0f, 0.6f, 0.6f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(5 / 7.0f, 0.7f, 0.7f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(5 / 7.0f, 0.8f, 0.8f));
                    if (ImGui::Button("Generate Code to Teleport Spyro"))
                        buttonClicked++;
                }
                ImGui::PopStyleColor(3);
                ImGui::PopID();
                ImGui::SameLine();
                HelpMarker(
                    "This will generate a gameshark code to instantly teleport Spyro's position, angle, and camera to the postion you were in when you saved your Bizhawk dump. "
                    "You activate the code by inputting the button combination you chose above.");




            }



            if (buttonClicked & 1)
            {
                hasButtonBeenPressed = true;
                hasCodeBeenCreated = true;
                if (gameChoice == 0)
                {

                    
                    if (publicPopstarterCheck == true)
                    {


                        spyroX2Address = "$80078A58 ";    //BACKWARDS CUZ BYTES 
                        spyroX1Address = "$80078A5A ";
                        spyroY2Address = "$80078A5C ";
                        spyroY1Address = "$80078A5E ";
                        spyroZ2Address = "$80078A60 ";
                        spyroZ1Address = "$80078A62 ";
                        spyroAngleAddress = "$80078B74 ";
                        camX2Address = "$80076DD0 ";
                        camX1Address = "$80076DD2 ";
                        camY2Address = "$80076DD8 ";
                        camY1Address = "$80076DDA ";
                        camZ2Address = "$80076DE0 ";
                        camZ1Address = "$80076DE2 ";
                        camYaw2Address = "$80076DF8 ";
                        camYaw1Address = "$80076DFA ";
                        camYaw4Address = "$80076DFC ";
                        camYaw3Address = "$80076DFE ";
                        jokerCommand = "$D0077380 ";
                        sparxHealthAddress = "$80078BBC ";
                        infiniteLivesCode = "$8007582C 0099";

                    }

                    if (publicPopstarterCheck == false)

                    {
                        spyroX2Address = "80078A58 ";    //BACKWARDS CUZ BYTES 
                        spyroX1Address = "80078A5A ";
                        spyroY2Address = "80078A5C ";
                        spyroY1Address = "80078A5E ";
                        spyroZ2Address = "80078A60 ";
                        spyroZ1Address = "80078A62 ";
                        spyroAngleAddress = "80078B74 ";
                        camX2Address = "80076DD0 ";
                        camX1Address = "80076DD2 ";
                        camY2Address = "80076DD8 ";
                        camY1Address = "80076DDA ";
                        camZ2Address = "80076DE0 ";
                        camZ1Address = "80076DE2 ";
                        camYaw2Address = "80076DF8 ";
                        camYaw1Address = "80076DFA ";
                        camYaw4Address = "80076DFC ";
                        camYaw3Address = "80076DFE ";
                        jokerCommand = "D0077380 ";
                        sparxHealthAddress = "80078BBC ";
                        infiniteLivesCode = "8007582C 0099";
                    }





                    LINE = 30886;
                    LINE2 = 30887;
                    LINE3 = 30899;
                    LINE4 = 30430;
                    LINE5 = 30431;
                    LINE6 = 30432;




                    for (int i = 1; i <= LINE; i++)
                        std::getline(f1, myData);
                    for (int i = 1; i <= LINE2; i++)
                        std::getline(f2, myData2);
                    for (int i = 1; i <= LINE3; i++)
                        std::getline(f3, myData3);
                    for (int i = 1; i <= LINE4; i++)
                        std::getline(f4, myData4);
                    for (int i = 1; i <= LINE5; i++)
                        std::getline(f5, myData5);
                    for (int i = 1; i <= LINE6; i++)
                        std::getline(f6, myData6);




                    //taking the 1byte hex codes and making them more easily accesible in strings
                    lbcSpyroX1 += myData[33];
                    lbcSpyroX1 += myData[34];
                    lbcSpyroX1 += myData[30];
                    lbcSpyroX1 += myData[31];

                    //splitting each byte into its own string
                    lbcSpyroX2 += myData[27];
                    lbcSpyroX2 += myData[28];
                    lbcSpyroX2 += myData[24];
                    lbcSpyroX2 += myData[25];


                    lbcSpyroY1 += myData[45];
                    lbcSpyroY1 += myData[46];
                    lbcSpyroY1 += myData[42];
                    lbcSpyroY1 += myData[43];


                    lbcSpyroY2 += myData[39];
                    lbcSpyroY2 += myData[40];
                    lbcSpyroY2 += myData[36];
                    lbcSpyroY2 += myData[37];


                    lbcSpyroZ1 += myData2[9];
                    lbcSpyroZ1 += myData2[10];
                    lbcSpyroZ1 += myData2[6];
                    lbcSpyroZ1 += myData2[7];


                    lbcSpyroZ2 += myData2[3];
                    lbcSpyroZ2 += myData2[4];
                    lbcSpyroZ2 += myData2[0];
                    lbcSpyroZ2 += myData2[1];





                    lbcSpyroAngle += myData3[15];
                    lbcSpyroAngle += myData3[16];
                    lbcSpyroAngle += myData3[12];
                    lbcSpyroAngle += myData3[13];




                    lbcCamX1 += myData4[9];
                    lbcCamX1 += myData4[10];
                    lbcCamX1 += myData4[6];
                    lbcCamX1 += myData4[7];

                    lbcCamX2 += myData4[3];
                    lbcCamX2 += myData4[4];
                    lbcCamX2 += myData4[0];
                    lbcCamX2 += myData4[1];

                    lbcCamY1 += myData4[33];
                    lbcCamY1 += myData4[34];
                    lbcCamY1 += myData4[30];
                    lbcCamY1 += myData4[31];

                    lbcCamY2 += myData4[27];
                    lbcCamY2 += myData4[28];
                    lbcCamY2 += myData4[24];
                    lbcCamY2 += myData4[25];

                    lbcCamZ1 += myData5[9];
                    lbcCamZ1 += myData5[10];
                    lbcCamZ1 += myData5[6];
                    lbcCamZ1 += myData5[7];

                    lbcCamZ2 += myData5[3];
                    lbcCamZ2 += myData5[4];
                    lbcCamZ2 += myData5[0];
                    lbcCamZ2 += myData5[1];

                    lbcCamYaw1 += myData6[33];
                    lbcCamYaw1 += myData6[34];
                    lbcCamYaw1 += myData6[30];
                    lbcCamYaw1 += myData6[31];

                    lbcCamYaw2 += myData6[27];
                    lbcCamYaw2 += myData6[28];
                    lbcCamYaw2 += myData6[24];
                    lbcCamYaw2 += myData6[25];

                    lbcCamYaw3 += myData6[45];
                    lbcCamYaw3 += myData6[46];
                    lbcCamYaw3 += myData6[42];
                    lbcCamYaw3 += myData6[43];

                    lbcCamYaw4 += myData6[39];
                    lbcCamYaw4 += myData6[40];
                    lbcCamYaw4 += myData6[36];
                    lbcCamYaw4 += myData6[37];











                    if (currentButtonCombo == 0)
                    {
                        currentButtonComboCode = "0043";
                    }

                    if (currentButtonCombo == 1)
                    {
                        currentButtonComboCode = "0023";
                    }
                    if (currentButtonCombo == 2)
                    {
                        currentButtonComboCode = "0013";
                    }
                    if (currentButtonCombo == 3)
                    {
                        currentButtonComboCode = "0083";
                    }
                    if (currentButtonCombo == 4)
                    {
                        currentButtonComboCode = "0031";
                    }
                    if (currentButtonCombo == 5)
                    {
                        currentButtonComboCode = "0032";
                    }




                    gameSharkCodeJoker = jokerCommand + currentButtonComboCode;
                    gameSharkCodeL2 = spyroX2Address + lbcSpyroX2;
                    gameSharkCodeL4 = spyroX1Address + lbcSpyroX1;
                    gameSharkCodeL6 = spyroY2Address + lbcSpyroY2;
                    gameSharkCodeL8 = spyroY1Address + lbcSpyroY1;
                    gameSharkCodeL10 = spyroZ2Address + lbcSpyroZ2;
                    gameSharkCodeL12 = spyroZ1Address + lbcSpyroZ1;
                    gameSharkCodeL14 = spyroAngleAddress + lbcSpyroAngle;
                    gameSharkCodeL16 = camX2Address + lbcCamX2;
                    gameSharkCodeL18 = camX1Address + lbcCamX1;
                    gameSharkCodeL20 = camY2Address + lbcCamY2;
                    gameSharkCodeL22 = camY1Address + lbcCamY1;
                    gameSharkCodeL24 = camZ2Address + lbcCamZ2;
                    gameSharkCodeL26 = camZ1Address + lbcCamZ1;
                    gameSharkCodeL28 = camYaw2Address + lbcCamYaw2;
                    gameSharkCodeL30 = camYaw1Address + lbcCamYaw1;
                    gameSharkCodeL32 = camYaw3Address + lbcCamYaw3;
                    gameSharkCodeL34 = camYaw4Address + lbcCamYaw4;
                    if (publicSparxCheck == true)
                    {
                        gameSharkCodeL36 = sparxHealthAddress + sparxHealthValue;
                    }
                    if (publicLivesCheck == true)
                    {
                        gameSharkCodeL38 = infiniteLivesCode;
                    }




                    strcpy_s(gscCharJoker, 15, gameSharkCodeJoker.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL2, 15, gameSharkCodeL2.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL4, 15, gameSharkCodeL4.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL6, 15, gameSharkCodeL6.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL8, 15, gameSharkCodeL8.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL10, 15, gameSharkCodeL10.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL12, 15, gameSharkCodeL12.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL14, 15, gameSharkCodeL14.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL16, 15, gameSharkCodeL16.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL18, 15, gameSharkCodeL18.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL20, 15, gameSharkCodeL20.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL22, 15, gameSharkCodeL22.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL24, 15, gameSharkCodeL24.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL26, 15, gameSharkCodeL26.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL28, 15, gameSharkCodeL28.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL30, 15, gameSharkCodeL30.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL32, 15, gameSharkCodeL32.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL34, 15, gameSharkCodeL34.c_str());    // or pass &s[0]
                    if (publicSparxCheck == true)
                    {
                        strcpy_s(gscCharL36, 15, gameSharkCodeL36.c_str());    // or pass &s[0]
                    }

                    if (publicLivesCheck == true)
                    {
                        strcpy_s(gscCharL38, 15, gameSharkCodeL38.c_str());    // or pass &s[0]
                    }



                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL2;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL4;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL6;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL8;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL10;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL12;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL14;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL16;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL18;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL20;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL22;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL24;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL26;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL28;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL30;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL32;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL34;
                    fullGamesharkCode += '\n';
                    if (publicSparxCheck == true)
                    {
                        fullGamesharkCode += gscCharJoker;
                        fullGamesharkCode += '\n';
                        fullGamesharkCode += gscCharL36;
                        fullGamesharkCode += '\n';
                    }

                    if (publicLivesCheck == true)
                    {
                        fullGamesharkCode += gscCharL38;
                        fullGamesharkCode += '\n';
                    }

                    strcpy_s(fullGamesharkCodeChar, 1000, fullGamesharkCode.c_str());

                    gscCreated = true;

                    buttonClicked = 0;

                }


                if (gameChoice == 1)
                {

                    if (publicPopstarterCheck == true)
                    {


                        spyroX2Address = "$80069FF0 ";    //BACKWARDS CUZ BYTES LOLOLOL
                        spyroX1Address = "$80069FF2 ";
                        spyroY2Address = "$80069FF4 ";
                        spyroY1Address = "$80069FF6 ";
                        spyroZ2Address = "$80069FF8 ";
                        spyroZ1Address = "$80069FFA ";
                        spyroAngleAddress = "$8006A05C ";
                        camX2Address = "$80067EAC ";
                        camX1Address = "$80067EAE ";
                        camY2Address = "$80067EB0 ";
                        camY1Address = "$80067EB2 ";
                        camZ2Address = "$80067EB4 ";
                        camZ1Address = "$80067EB6 ";
                        camYaw2Address = "$80067F28 ";
                        camYaw1Address = "$80067F2A ";
                        jokerCommand = "$D00683A0 ";
                        sparxHealthAddress = "$8006A248 ";
                        infiniteLivesCode = "$8006712C 0099";

                    }

                    if (publicPopstarterCheck == false)
                    {
                        spyroX2Address = "80069FF0 ";    //BACKWARDS CUZ BYTES LOLOLOL
                        spyroX1Address = "80069FF2 ";
                        spyroY2Address = "80069FF4 ";
                        spyroY1Address = "80069FF6 ";
                        spyroZ2Address = "80069FF8 ";
                        spyroZ1Address = "80069FFA ";
                        spyroAngleAddress = "8006A05C ";
                        camX2Address = "80067EAC ";
                        camX1Address = "80067EAE ";
                        camY2Address = "80067EB0 ";
                        camY1Address = "80067EB2 ";
                        camZ2Address = "80067EB4 ";
                        camZ1Address = "80067EB6 ";
                        camYaw2Address = "80067F28 ";
                        camYaw1Address = "80067F2A ";
                        jokerCommand = "D00683A0 ";
                        sparxHealthAddress = "8006A248 ";
                        infiniteLivesCode = "8006712C 0099";
                    }


                    LINE = 27136;   //only game where all spyros positions fit on one line, so may not follow exactly like other 2 games
                    LINE2 = 27142;
                    LINE3 = 26603;
                    LINE4 = 26604;
                    LINE5 = 26611;



                    for (int i = 1; i <= LINE; i++)
                        std::getline(f1, myData);
                    for (int i = 1; i <= LINE2; i++)
                        std::getline(f2, myData2);
                    for (int i = 1; i <= LINE3; i++)
                        std::getline(f3, myData3);
                    for (int i = 1; i <= LINE4; i++)
                        std::getline(f4, myData4);
                    for (int i = 1; i <= LINE5; i++)
                        std::getline(f5, myData5);




                    //taking the 1byte hex codes and making them more easily accesible in strings
                    lbcSpyroX1 += myData[9];
                    lbcSpyroX1 += myData[10];
                    lbcSpyroX1 += myData[6];
                    lbcSpyroX1 += myData[7];

                    //splitting each byte into its own string
                    lbcSpyroX2 += myData[3];
                    lbcSpyroX2 += myData[4];
                    lbcSpyroX2 += myData[0];
                    lbcSpyroX2 += myData[1];


                    lbcSpyroY1 += myData[21];
                    lbcSpyroY1 += myData[22];
                    lbcSpyroY1 += myData[18];
                    lbcSpyroY1 += myData[19];


                    lbcSpyroY2 += myData[15];
                    lbcSpyroY2 += myData[16];
                    lbcSpyroY2 += myData[12];
                    lbcSpyroY2 += myData[13];


                    lbcSpyroZ1 += myData[33];
                    lbcSpyroZ1 += myData[34];
                    lbcSpyroZ1 += myData[30];
                    lbcSpyroZ1 += myData[31];


                    lbcSpyroZ2 += myData[27];
                    lbcSpyroZ2 += myData[28];
                    lbcSpyroZ2 += myData[24];
                    lbcSpyroZ2 += myData[25];

                    lbcSpyroAngle += myData2[39];
                    lbcSpyroAngle += myData2[40];
                    lbcSpyroAngle += myData2[36];
                    lbcSpyroAngle += myData2[37];


                    lbcCamX1 += myData3[45];
                    lbcCamX1 += myData3[46];
                    lbcCamX1 += myData3[42];
                    lbcCamX1 += myData3[43];

                    lbcCamX2 += myData3[39];
                    lbcCamX2 += myData3[40];
                    lbcCamX2 += myData3[36];
                    lbcCamX2 += myData3[37];

                    lbcCamY1 += myData3[9];
                    lbcCamY1 += myData4[10];
                    lbcCamY1 += myData4[6];
                    lbcCamY1 += myData4[7];

                    lbcCamY2 += myData3[3];
                    lbcCamY2 += myData4[4];
                    lbcCamY2 += myData4[0];
                    lbcCamY2 += myData4[1];

                    lbcCamZ1 += myData4[21];
                    lbcCamZ1 += myData4[22];
                    lbcCamZ1 += myData4[18];
                    lbcCamZ1 += myData4[19];

                    lbcCamZ2 += myData4[15];
                    lbcCamZ2 += myData4[16];
                    lbcCamZ2 += myData4[12];
                    lbcCamZ2 += myData4[13];

                    lbcCamYaw1 += myData5[33];
                    lbcCamYaw1 += myData5[34];
                    lbcCamYaw1 += myData5[30];
                    lbcCamYaw1 += myData5[31];

                    lbcCamYaw2 += myData5[27];
                    lbcCamYaw2 += myData5[28];
                    lbcCamYaw2 += myData5[24];
                    lbcCamYaw2 += myData5[25];









                    if (currentButtonCombo == 0)
                    {
                        currentButtonComboCode = "0043";
                    }

                    if (currentButtonCombo == 1)
                    {
                        currentButtonComboCode = "0023";
                    }
                    if (currentButtonCombo == 2)
                    {
                        currentButtonComboCode = "0013";
                    }
                    if (currentButtonCombo == 3)
                    {
                        currentButtonComboCode = "0083";
                    }
                    if (currentButtonCombo == 4)
                    {
                        currentButtonComboCode = "0031";
                    }
                    if (currentButtonCombo == 5)
                    {
                        currentButtonComboCode = "0032";
                    }
                    if (currentButtonCombo == 6)
                    {
                        currentButtonComboCode = "0045";
                    }
                    if (currentButtonCombo == 7)
                    {
                        currentButtonComboCode = "0085";
                    }
                    if (currentButtonCombo == 8)
                    {
                        currentButtonComboCode = "0025";
                    }
                    if (currentButtonCombo == 9)
                    {
                        currentButtonComboCode = "0015";
                    }
                    if (currentButtonCombo == 10)
                    {
                        currentButtonComboCode = "004A";
                    }
                    if (currentButtonCombo == 11)
                    {
                        currentButtonComboCode = "008A";
                    }
                    if (currentButtonCombo == 12)
                    {
                        currentButtonComboCode = "002A";
                    }
                    if (currentButtonCombo == 13)
                    {
                        currentButtonComboCode = "001A";
                    }





                    gameSharkCodeJoker = jokerCommand + currentButtonComboCode;
                    gameSharkCodeL2 = spyroX2Address + lbcSpyroX2;
                    gameSharkCodeL4 = spyroX1Address + lbcSpyroX1;
                    gameSharkCodeL6 = spyroY2Address + lbcSpyroY2;
                    gameSharkCodeL8 = spyroY1Address + lbcSpyroY1;
                    gameSharkCodeL10 = spyroZ2Address + lbcSpyroZ2;
                    gameSharkCodeL12 = spyroZ1Address + lbcSpyroZ1;
                    gameSharkCodeL14 = spyroAngleAddress + lbcSpyroAngle;
                    gameSharkCodeL16 = camX2Address + lbcCamX2;
                    gameSharkCodeL18 = camX1Address + lbcCamX1;
                    gameSharkCodeL20 = camY2Address + lbcCamY2;
                    gameSharkCodeL22 = camY1Address + lbcCamY1;
                    gameSharkCodeL24 = camZ2Address + lbcCamZ2;
                    gameSharkCodeL26 = camZ1Address + lbcCamZ1;
                    gameSharkCodeL28 = camYaw2Address + lbcCamYaw2;
                    gameSharkCodeL30 = camYaw1Address + lbcCamYaw1;
                    if (publicSparxCheck == true)
                    {
                        gameSharkCodeL32 = sparxHealthAddress + sparxHealthValue;
                    }
                    if (publicLivesCheck == true)
                    {
                        gameSharkCodeL34 = infiniteLivesCode;
                    }




                    strcpy_s(gscCharJoker, 15, gameSharkCodeJoker.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL2, 15, gameSharkCodeL2.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL4, 15, gameSharkCodeL4.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL6, 15, gameSharkCodeL6.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL8, 15, gameSharkCodeL8.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL10, 15, gameSharkCodeL10.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL12, 15, gameSharkCodeL12.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL14, 15, gameSharkCodeL14.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL16, 15, gameSharkCodeL16.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL18, 15, gameSharkCodeL18.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL20, 15, gameSharkCodeL20.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL22, 15, gameSharkCodeL22.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL24, 15, gameSharkCodeL24.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL26, 15, gameSharkCodeL26.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL28, 15, gameSharkCodeL28.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL30, 15, gameSharkCodeL30.c_str());    // or pass &s[0]
                    if (publicSparxCheck == true)
                    {
                        strcpy_s(gscCharL32, 15, gameSharkCodeL32.c_str());    // or pass &s[0]
                    }
                    if (publicLivesCheck == true)
                    {
                        strcpy_s(gscCharL34, 15, gameSharkCodeL34.c_str());    // or pass &s[0]
                    }

                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL2;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL4;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL6;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL8;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL10;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL12;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL14;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL16;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL18;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL20;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL22;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL24;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL26;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL28;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL30;
                    fullGamesharkCode += '\n';
                    if (publicSparxCheck == true)
                    {
                        fullGamesharkCode += gscCharJoker;
                        fullGamesharkCode += '\n';
                        fullGamesharkCode += gscCharL32;
                        fullGamesharkCode += '\n';
                    }

                    if (publicLivesCheck == true)
                    {
                        fullGamesharkCode += gscCharL34;
                        fullGamesharkCode += '\n';
                    }

                    strcpy_s(fullGamesharkCodeChar, 1000, fullGamesharkCode.c_str());

                    gscCreated = true;

                    buttonClicked = 0;

                }

                if (gameChoice == 2)
                {
                    
                    if (publicPopstarterCheck == true)
                    {

                        spyroX2Address = "$80070328 ";    //BACKWARDS CUZ BYTES LOLOLOL
                        spyroX1Address = "$8007032A ";
                        spyroY2Address = "$8007032C ";
                        spyroY1Address = "$8007032E ";
                        spyroZ2Address = "$80070330 ";
                        spyroZ1Address = "$80070332 ";
                        spyroAngleAddress = "$8007038C ";
                        camX2Address = "$8006E020 ";
                        camX1Address = "$8006E122 ";
                        camY2Address = "$8006E124 ";
                        camY1Address = "$8006E126 ";
                        camZ2Address = "$8006E128 ";
                        camZ1Address = "$8006E12A ";
                        camYaw2Address = "$8006E040 ";
                        camYaw1Address = "$8006E042 ";
                        camYaw4Address = "$8006E074 ";
                        camYaw3Address = "$8006E076 ";
                        camYaw6Address = "$8006E09C ";
                        camYaw5Address = "$8006E09E ";
                        jokerCommand = "$D006E538 ";
                        sparxHealthAddress = "$800705A8 ";
                        infiniteLivesCode = "$8006C784 0099";
                    }

                    if (publicPopstarterCheck == false)
                    {
                        spyroX2Address = "80070328 ";    //BACKWARDS CUZ BYTES LOLOLOL
                        spyroX1Address = "8007032A ";
                        spyroY2Address = "8007032C ";
                        spyroY1Address = "8007032E ";
                        spyroZ2Address = "80070330 ";
                        spyroZ1Address = "80070332 ";
                        spyroAngleAddress = "8007038C ";
                        camX2Address = "8006E020 ";
                        camX1Address = "8006E122 ";
                        camY2Address = "8006E124 ";
                        camY1Address = "8006E126 ";
                        camZ2Address = "8006E128 ";
                        camZ1Address = "8006E12A ";
                        camYaw2Address = "8006E040 ";
                        camYaw1Address = "8006E042 ";
                        camYaw4Address = "8006E074 ";
                        camYaw3Address = "8006E076 ";
                        camYaw6Address = "8006E09C ";
                        camYaw5Address = "8006E09E ";
                        jokerCommand = "D006E538 ";
                        sparxHealthAddress = "800705A8 ";
                        infiniteLivesCode = "8006C784 0099";
                    }

                    LINE = 102480;
                    LINE2 = 102481;
                    LINE3 = 28729;
                    LINE4 = 28163;
                    LINE5 = 28165;
                    LINE6 = 28168;
                    LINE7 = 28170;  //LEFT OF HERE //LEFT OF HERE//LEFT OF HERE//LEFT OF HERE//LEFT OF HERE//LEFT OF HERE//LEFT OF HERE//LEFT OF HERE



                    for (int i = 1; i <= LINE; i++)
                        std::getline(f1, myData);
                    for (int i = 1; i <= LINE2; i++)
                        std::getline(f2, myData2);
                    for (int i = 1; i <= LINE3; i++)
                        std::getline(f3, myData3);
                    for (int i = 1; i <= LINE4; i++)
                        std::getline(f4, myData4);
                    for (int i = 1; i <= LINE5; i++)
                        std::getline(f5, myData5);
                    for (int i = 1; i <= LINE6; i++)
                        std::getline(f6, myData6);
                    for (int i = 1; i <= LINE7; i++)
                        std::getline(f7, myData7);




                    //taking the 1byte hex codes and making them more easily accesible in strings
                    lbcSpyroX1 += myData[33];
                    lbcSpyroX1 += myData[34];
                    lbcSpyroX1 += myData[30];
                    lbcSpyroX1 += myData[31];

                    //splitting each byte into its own string
                    lbcSpyroX2 += myData[27];
                    lbcSpyroX2 += myData[28];
                    lbcSpyroX2 += myData[24];
                    lbcSpyroX2 += myData[25];


                    lbcSpyroY1 += myData[45];
                    lbcSpyroY1 += myData[46];
                    lbcSpyroY1 += myData[42];
                    lbcSpyroY1 += myData[43];


                    lbcSpyroY2 += myData[39];
                    lbcSpyroY2 += myData[40];
                    lbcSpyroY2 += myData[36];
                    lbcSpyroY2 += myData[37];


                    lbcSpyroZ1 += myData2[9];
                    lbcSpyroZ1 += myData2[10];
                    lbcSpyroZ1 += myData2[6];
                    lbcSpyroZ1 += myData2[7];


                    lbcSpyroZ2 += myData2[3];
                    lbcSpyroZ2 += myData2[4];
                    lbcSpyroZ2 += myData2[0];
                    lbcSpyroZ2 += myData2[1];

                    lbcSpyroAngle += myData3[39];
                    lbcSpyroAngle += myData3[40];
                    lbcSpyroAngle += myData3[36];
                    lbcSpyroAngle += myData3[37];



                    lbcCamX1 += myData4[9];
                    lbcCamX1 += myData4[10];
                    lbcCamX1 += myData4[6];
                    lbcCamX1 += myData4[7];

                    lbcCamX2 += myData4[3];
                    lbcCamX2 += myData4[4];
                    lbcCamX2 += myData4[0];
                    lbcCamX2 += myData4[1];

                    lbcCamY1 += myData4[21];
                    lbcCamY1 += myData4[22];
                    lbcCamY1 += myData4[18];
                    lbcCamY1 += myData4[19];

                    lbcCamY2 += myData4[15];
                    lbcCamY2 += myData4[16];
                    lbcCamY2 += myData4[12];
                    lbcCamY2 += myData4[13];

                    lbcCamZ1 += myData4[33];
                    lbcCamZ1 += myData4[34];
                    lbcCamZ1 += myData4[30];
                    lbcCamZ1 += myData4[31];

                    lbcCamZ2 += myData4[27];
                    lbcCamZ2 += myData4[28];
                    lbcCamZ2 += myData4[24];
                    lbcCamZ2 += myData4[25];

                    lbcCamYaw1 += myData5[9];
                    lbcCamYaw1 += myData5[10];
                    lbcCamYaw1 += myData5[6];
                    lbcCamYaw1 += myData5[7];

                    lbcCamYaw2 += myData5[3];
                    lbcCamYaw2 += myData5[4];
                    lbcCamYaw2 += myData5[0];
                    lbcCamYaw2 += myData5[1];

                    lbcCamYaw3 += myData6[21];
                    lbcCamYaw3 += myData6[22];
                    lbcCamYaw3 += myData6[18];
                    lbcCamYaw3 += myData6[19];

                    lbcCamYaw4 += myData6[15];
                    lbcCamYaw4 += myData6[16];
                    lbcCamYaw4 += myData6[12];
                    lbcCamYaw4 += myData6[13];

                    lbcCamYaw5 += myData7[45];
                    lbcCamYaw5 += myData7[46];
                    lbcCamYaw5 += myData7[42];
                    lbcCamYaw5 += myData7[43];

                    lbcCamYaw6 += myData7[39];
                    lbcCamYaw6 += myData7[40];
                    lbcCamYaw6 += myData7[36];
                    lbcCamYaw6 += myData7[37];




                    if (currentButtonCombo == 0)
                    {
                        currentButtonComboCode = "0043";
                    }

                    if (currentButtonCombo == 1)
                    {
                        currentButtonComboCode = "0023";
                    }
                    if (currentButtonCombo == 2)
                    {
                        currentButtonComboCode = "0013";
                    }
                    if (currentButtonCombo == 3)
                    {
                        currentButtonComboCode = "0083";
                    }
                    if (currentButtonCombo == 4)
                    {
                        currentButtonComboCode = "0031";
                    }
                    if (currentButtonCombo == 5)
                    {
                        currentButtonComboCode = "0032";
                    }
                    if (currentButtonCombo == 6)
                    {
                        currentButtonComboCode = "0045";
                    }
                    if (currentButtonCombo == 7)
                    {
                        currentButtonComboCode = "0085";
                    }
                    if (currentButtonCombo == 8)
                    {
                        currentButtonComboCode = "0025";
                    }
                    if (currentButtonCombo == 9)
                    {
                        currentButtonComboCode = "0015";
                    }
                    if (currentButtonCombo == 10)
                    {
                        currentButtonComboCode = "004A";
                    }
                    if (currentButtonCombo == 11)
                    {
                        currentButtonComboCode = "008A";
                    }
                    if (currentButtonCombo == 12)
                    {
                        currentButtonComboCode = "002A";
                    }
                    if (currentButtonCombo == 13)
                    {
                        currentButtonComboCode = "001A";
                    }





                    gameSharkCodeJoker = jokerCommand + currentButtonComboCode;
                    gameSharkCodeL2 = spyroX2Address + lbcSpyroX2;
                    gameSharkCodeL4 = spyroX1Address + lbcSpyroX1;
                    gameSharkCodeL6 = spyroY2Address + lbcSpyroY2;
                    gameSharkCodeL8 = spyroY1Address + lbcSpyroY1;
                    gameSharkCodeL10 = spyroZ2Address + lbcSpyroZ2;
                    gameSharkCodeL12 = spyroZ1Address + lbcSpyroZ1;
                    gameSharkCodeL14 = spyroAngleAddress + lbcSpyroAngle;
                    gameSharkCodeL16 = camX2Address + lbcCamX2;
                    gameSharkCodeL18 = camX1Address + lbcCamX1;
                    gameSharkCodeL20 = camY2Address + lbcCamY2;
                    gameSharkCodeL22 = camY1Address + lbcCamY1;
                    gameSharkCodeL24 = camZ2Address + lbcCamZ2;
                    gameSharkCodeL26 = camZ1Address + lbcCamZ1;
                    gameSharkCodeL28 = camYaw2Address + lbcCamYaw2;
                    gameSharkCodeL30 = camYaw1Address + lbcCamYaw1;
                    gameSharkCodeL32 = camYaw4Address + lbcCamYaw4;
                    gameSharkCodeL34 = camYaw3Address + lbcCamYaw3;
                    gameSharkCodeL36 = camYaw6Address + lbcCamYaw6;
                    gameSharkCodeL38 = camYaw5Address + lbcCamYaw5;
                    if (publicSparxCheck == true)
                    {
                        gameSharkCodeL40 = sparxHealthAddress + sparxHealthValue;
                    }

                    if (publicLivesCheck == true)
                    {
                        gameSharkCodeL42 = infiniteLivesCode;
                    }




                    strcpy_s(gscCharJoker, 15, gameSharkCodeJoker.c_str());
                    strcpy_s(gscCharL2, 15, gameSharkCodeL2.c_str());
                    strcpy_s(gscCharL4, 15, gameSharkCodeL4.c_str());
                    strcpy_s(gscCharL6, 15, gameSharkCodeL6.c_str());
                    strcpy_s(gscCharL8, 15, gameSharkCodeL8.c_str());
                    strcpy_s(gscCharL10, 15, gameSharkCodeL10.c_str());
                    strcpy_s(gscCharL12, 15, gameSharkCodeL12.c_str());
                    strcpy_s(gscCharL14, 15, gameSharkCodeL14.c_str());
                    strcpy_s(gscCharL16, 15, gameSharkCodeL16.c_str());
                    strcpy_s(gscCharL18, 15, gameSharkCodeL18.c_str());
                    strcpy_s(gscCharL20, 15, gameSharkCodeL20.c_str());
                    strcpy_s(gscCharL22, 15, gameSharkCodeL22.c_str());
                    strcpy_s(gscCharL24, 15, gameSharkCodeL24.c_str());
                    strcpy_s(gscCharL26, 15, gameSharkCodeL26.c_str());
                    strcpy_s(gscCharL28, 15, gameSharkCodeL28.c_str());
                    strcpy_s(gscCharL30, 15, gameSharkCodeL30.c_str());
                    strcpy_s(gscCharL32, 15, gameSharkCodeL32.c_str());
                    strcpy_s(gscCharL34, 15, gameSharkCodeL34.c_str());
                    strcpy_s(gscCharL36, 15, gameSharkCodeL36.c_str());
                    strcpy_s(gscCharL38, 15, gameSharkCodeL38.c_str());
                    if (publicSparxCheck == true)
                    {
                        strcpy_s(gscCharL40, 15, gameSharkCodeL40.c_str());
                    }
                    if (publicLivesCheck == true)
                    {
                        strcpy_s(gscCharL42, 15, gameSharkCodeL42.c_str());
                    }


                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL2;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL4;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL6;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL8;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL10;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL12;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL14;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL16;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL18;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL20;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL22;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL24;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL26;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL28;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL30;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL32;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL34;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL36;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL38;
                    fullGamesharkCode += '\n';
                    if (publicSparxCheck == true)
                    {
                        fullGamesharkCode += gscCharJoker;
                        fullGamesharkCode += '\n';
                        fullGamesharkCode += gscCharL40;
                        fullGamesharkCode += '\n';
                    }
                    if (publicLivesCheck == true)
                    {
                        fullGamesharkCode += gscCharL42;
                        fullGamesharkCode += '\n';
                    }


                    strcpy_s(fullGamesharkCodeChar, 1000, fullGamesharkCode.c_str());

                    //std::cout << fullGamesharkCode;


                    gscCreated = true;


                    buttonClicked = 0;

                }




                if (gameChoice == 3)
                {
                    if (publicPopstarterCheck == true)
                    {

                        spyroX2Address = "$80070408 ";    //BACKWARDS CUZ BYTES LOLOLOL
                        spyroX1Address = "$8007040A ";
                        spyroY2Address = "$8007040C ";
                        spyroY1Address = "$8007040E ";
                        spyroZ2Address = "$80070410 ";
                        spyroZ1Address = "$80070412 ";
                        spyroAngleAddress = "$8007046C ";
                        camX2Address = "$8006E100 ";
                        camX1Address = "$8006E102 ";
                        camY2Address = "$8006E104 ";
                        camY1Address = "$8006E106 ";
                        camZ2Address = "$8006E108 ";
                        camZ1Address = "$8006E10A ";
                        camYaw2Address = "$8006E120 ";
                        camYaw1Address = "$8006E122 ";
                        camYaw4Address = "$8006E154 ";
                        camYaw3Address = "$8006E156 ";
                        camYaw6Address = "$8006E17C ";
                        camYaw5Address = "$8006E17E ";
                        jokerCommand = "$D006E618 ";
                        sparxHealthAddress = "$80070688 ";
                        infiniteLivesCode = "$8006C864 0099";
                    }

                    if (publicPopstarterCheck == false)
                    {
                        spyroX2Address = "80070408 ";    //BACKWARDS CUZ BYTES LOLOLOL
                        spyroX1Address = "8007040A ";
                        spyroY2Address = "8007040C ";
                        spyroY1Address = "8007040E ";
                        spyroZ2Address = "80070410 ";
                        spyroZ1Address = "80070412 ";
                        spyroAngleAddress = "8007046C ";
                        camX2Address = "8006E100 ";
                        camX1Address = "8006E102 ";
                        camY2Address = "8006E104 ";
                        camY1Address = "8006E106 ";
                        camZ2Address = "8006E108 ";
                        camZ1Address = "8006E10A ";
                        camYaw2Address = "8006E120 ";
                        camYaw1Address = "8006E122 ";
                        camYaw4Address = "8006E154 ";
                        camYaw3Address = "8006E156 ";
                        camYaw6Address = "8006E17C ";
                        camYaw5Address = "8006E17E ";
                        jokerCommand = "D006E618 ";
                        sparxHealthAddress = "80070688 ";
                        infiniteLivesCode = "8006C864 0099";
                    }


                    LINE = 102494;
                    LINE2 = 102495;
                    LINE3 = 28743;
                    LINE4 = 28177;
                    LINE5 = 28179;
                    LINE6 = 28182;
                    LINE7 = 28184;



                    for (int i = 1; i <= LINE; i++)
                        std::getline(f1, myData);
                    for (int i = 1; i <= LINE2; i++)
                        std::getline(f2, myData2);
                    for (int i = 1; i <= LINE3; i++)
                        std::getline(f3, myData3);
                    for (int i = 1; i <= LINE4; i++)
                        std::getline(f4, myData4);
                    for (int i = 1; i <= LINE5; i++)
                        std::getline(f5, myData5);
                    for (int i = 1; i <= LINE6; i++)
                        std::getline(f6, myData6);
                    for (int i = 1; i <= LINE7; i++)
                        std::getline(f7, myData7);




                    //taking the 1byte hex codes and making them more easily accesible in strings
                    lbcSpyroX1 += myData[33];
                    lbcSpyroX1 += myData[34];
                    lbcSpyroX1 += myData[30];
                    lbcSpyroX1 += myData[31];

                    //splitting each byte into its own string
                    lbcSpyroX2 += myData[27];
                    lbcSpyroX2 += myData[28];
                    lbcSpyroX2 += myData[24];
                    lbcSpyroX2 += myData[25];


                    lbcSpyroY1 += myData[45];
                    lbcSpyroY1 += myData[46];
                    lbcSpyroY1 += myData[42];
                    lbcSpyroY1 += myData[43];


                    lbcSpyroY2 += myData[39];
                    lbcSpyroY2 += myData[40];
                    lbcSpyroY2 += myData[36];
                    lbcSpyroY2 += myData[37];


                    lbcSpyroZ1 += myData2[9];
                    lbcSpyroZ1 += myData2[10];
                    lbcSpyroZ1 += myData2[6];
                    lbcSpyroZ1 += myData2[7];


                    lbcSpyroZ2 += myData2[3];
                    lbcSpyroZ2 += myData2[4];
                    lbcSpyroZ2 += myData2[0];
                    lbcSpyroZ2 += myData2[1];

                    lbcSpyroAngle += myData3[39];
                    lbcSpyroAngle += myData3[40];
                    lbcSpyroAngle += myData3[36];
                    lbcSpyroAngle += myData3[37];



                    lbcCamX1 += myData4[9];
                    lbcCamX1 += myData4[10];
                    lbcCamX1 += myData4[6];
                    lbcCamX1 += myData4[7];

                    lbcCamX2 += myData4[3];
                    lbcCamX2 += myData4[4];
                    lbcCamX2 += myData4[0];
                    lbcCamX2 += myData4[1];

                    lbcCamY1 += myData4[21];
                    lbcCamY1 += myData4[22];
                    lbcCamY1 += myData4[18];
                    lbcCamY1 += myData4[19];

                    lbcCamY2 += myData4[15];
                    lbcCamY2 += myData4[16];
                    lbcCamY2 += myData4[12];
                    lbcCamY2 += myData4[13];

                    lbcCamZ1 += myData4[33];
                    lbcCamZ1 += myData4[34];
                    lbcCamZ1 += myData4[30];
                    lbcCamZ1 += myData4[31];

                    lbcCamZ2 += myData4[27];
                    lbcCamZ2 += myData4[28];
                    lbcCamZ2 += myData4[24];
                    lbcCamZ2 += myData4[25];

                    lbcCamYaw1 += myData5[9];
                    lbcCamYaw1 += myData5[10];
                    lbcCamYaw1 += myData5[6];
                    lbcCamYaw1 += myData5[7];

                    lbcCamYaw2 += myData5[3];
                    lbcCamYaw2 += myData5[4];
                    lbcCamYaw2 += myData5[0];
                    lbcCamYaw2 += myData5[1];

                    lbcCamYaw3 += myData6[21];
                    lbcCamYaw3 += myData6[22];
                    lbcCamYaw3 += myData6[18];
                    lbcCamYaw3 += myData6[19];

                    lbcCamYaw4 += myData6[15];
                    lbcCamYaw4 += myData6[16];
                    lbcCamYaw4 += myData6[12];
                    lbcCamYaw4 += myData6[13];

                    lbcCamYaw5 += myData7[45];
                    lbcCamYaw5 += myData7[46];
                    lbcCamYaw5 += myData7[42];
                    lbcCamYaw5 += myData7[43];

                    lbcCamYaw6 += myData7[39];
                    lbcCamYaw6 += myData7[40];
                    lbcCamYaw6 += myData7[36];
                    lbcCamYaw6 += myData7[37];




                    if (currentButtonCombo == 0)
                    {
                        currentButtonComboCode = "0043";
                    }

                    if (currentButtonCombo == 1)
                    {
                        currentButtonComboCode = "0023";
                    }
                    if (currentButtonCombo == 2)
                    {
                        currentButtonComboCode = "0013";
                    }
                    if (currentButtonCombo == 3)
                    {
                        currentButtonComboCode = "0083";
                    }
                    if (currentButtonCombo == 4)
                    {
                        currentButtonComboCode = "0031";
                    }
                    if (currentButtonCombo == 5)
                    {
                        currentButtonComboCode = "0032";
                    }
                    if (currentButtonCombo == 6)
                    {
                        currentButtonComboCode = "0045";
                    }
                    if (currentButtonCombo == 7)
                    {
                        currentButtonComboCode = "0085";
                    }
                    if (currentButtonCombo == 8)
                    {
                        currentButtonComboCode = "0025";
                    }
                    if (currentButtonCombo == 9)
                    {
                        currentButtonComboCode = "0015";
                    }
                    if (currentButtonCombo == 10)
                    {
                        currentButtonComboCode = "004A";
                    }
                    if (currentButtonCombo == 11)
                    {
                        currentButtonComboCode = "008A";
                    }
                    if (currentButtonCombo == 12)
                    {
                        currentButtonComboCode = "002A";
                    }
                    if (currentButtonCombo == 13)
                    {
                        currentButtonComboCode = "001A";
                    }





                    gameSharkCodeJoker = jokerCommand + currentButtonComboCode;
                    gameSharkCodeL2 = spyroX2Address + lbcSpyroX2;
                    gameSharkCodeL4 = spyroX1Address + lbcSpyroX1;
                    gameSharkCodeL6 = spyroY2Address + lbcSpyroY2;
                    gameSharkCodeL8 = spyroY1Address + lbcSpyroY1;
                    gameSharkCodeL10 = spyroZ2Address + lbcSpyroZ2;
                    gameSharkCodeL12 = spyroZ1Address + lbcSpyroZ1;
                    gameSharkCodeL14 = spyroAngleAddress + lbcSpyroAngle;
                    gameSharkCodeL16 = camX2Address + lbcCamX2;
                    gameSharkCodeL18 = camX1Address + lbcCamX1;
                    gameSharkCodeL20 = camY2Address + lbcCamY2;
                    gameSharkCodeL22 = camY1Address + lbcCamY1;
                    gameSharkCodeL24 = camZ2Address + lbcCamZ2;
                    gameSharkCodeL26 = camZ1Address + lbcCamZ1;
                    gameSharkCodeL28 = camYaw2Address + lbcCamYaw2;
                    gameSharkCodeL30 = camYaw1Address + lbcCamYaw1;
                    gameSharkCodeL32 = camYaw4Address + lbcCamYaw4;
                    gameSharkCodeL34 = camYaw3Address + lbcCamYaw3;
                    gameSharkCodeL36 = camYaw6Address + lbcCamYaw6;
                    gameSharkCodeL38 = camYaw5Address + lbcCamYaw5;
                    if (publicSparxCheck == true)
                        gameSharkCodeL40 = sparxHealthAddress + sparxHealthValue;

                    if (publicLivesCheck == true)
                        gameSharkCodeL42 = infiniteLivesCode;


                    strcpy_s(gscCharJoker, gameSharkCodeJoker.c_str());
                    strcpy_s(gscCharL2, 15, gameSharkCodeL2.c_str());
                    strcpy_s(gscCharL4, 15, gameSharkCodeL4.c_str());
                    strcpy_s(gscCharL6, 15, gameSharkCodeL6.c_str());
                    strcpy_s(gscCharL8, 15, gameSharkCodeL8.c_str());
                    strcpy_s(gscCharL10, 15, gameSharkCodeL10.c_str());
                    strcpy_s(gscCharL12, 15, gameSharkCodeL12.c_str());
                    strcpy_s(gscCharL14, 15, gameSharkCodeL14.c_str());
                    strcpy_s(gscCharL16, 15, gameSharkCodeL16.c_str());
                    strcpy_s(gscCharL18, 15, gameSharkCodeL18.c_str());
                    strcpy_s(gscCharL20, 15, gameSharkCodeL20.c_str());
                    strcpy_s(gscCharL22, 15, gameSharkCodeL22.c_str());
                    strcpy_s(gscCharL24, 15, gameSharkCodeL24.c_str());
                    strcpy_s(gscCharL26, 15, gameSharkCodeL26.c_str());
                    strcpy_s(gscCharL28, 15, gameSharkCodeL28.c_str());
                    strcpy_s(gscCharL30, 15, gameSharkCodeL30.c_str());
                    strcpy_s(gscCharL32, 15, gameSharkCodeL32.c_str());
                    strcpy_s(gscCharL34, 15, gameSharkCodeL34.c_str());
                    strcpy_s(gscCharL36, 15, gameSharkCodeL36.c_str());
                    strcpy_s(gscCharL38, 15, gameSharkCodeL38.c_str());
                    if (publicSparxCheck == true)
                    {
                        strcpy_s(gscCharL40, 15, gameSharkCodeL40.c_str());
                    }

                    if (publicLivesCheck == true)
                        strcpy_s(gscCharL42, 15, gameSharkCodeL42.c_str());


                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL2;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL4;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL6;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL8;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL10;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL12;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL14;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL16;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL18;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL20;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL22;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL24;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL26;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL28;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL30;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL32;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL34;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL36;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL38;
                    fullGamesharkCode += '\n';
                    if (publicSparxCheck == true)
                    {
                        fullGamesharkCode += gscCharJoker;
                        fullGamesharkCode += '\n';
                        fullGamesharkCode += gscCharL40;
                        fullGamesharkCode += '\n';
                    }

                    if (publicLivesCheck == true)
                    {
                        fullGamesharkCode += gscCharL42;
                        fullGamesharkCode += '\n';
                    }

                    strcpy_s(fullGamesharkCodeChar, fullGamesharkCode.c_str());

                    //std::cout << fullGamesharkCode;


                    gscCreated = true;


                    buttonClicked = 0;

                }

            }






            // BUTTON FOR DIE AND RESPAWN AT POSITION YOU WERE AT
            // BUTTON FOR DIE AND RESPAWN AT POSITION YOU WERE AT
            // BUTTON FOR DIE AND RESPAWN AT POSITION YOU WERE AT
            // BUTTON FOR DIE AND RESPAWN AT POSITION YOU WERE AT
            // BUTTON FOR DIE AND RESPAWN AT POSITION YOU WERE AT
            // BUTTON FOR DIE AND RESPAWN AT POSITION YOU WERE AT
            // BUTTON FOR DIE AND RESPAWN AT POSITION YOU WERE AT






            static int deathButtonClicked = 0;



            if (hasCodeBeenCreated == false)
            {

                for (int i = 0; i < 1; i++)
                {
                    if (i > 0)
                        ImGui::SameLine();
                    ImGui::PushID(i);
                    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(7 / 7.0f, 0.6f, 0.6f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(7 / 7.0f, 0.7f, 0.7f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(7 / 7.0f, 0.8f, 0.8f));
                    if (ImGui::Button("Generate Code to Respawn Spyro"))
                        deathButtonClicked++;
                }
                ImGui::PopStyleColor(3);
                ImGui::PopID();
                ImGui::SameLine();
                HelpMarker(
                    "This will generate a gameshark code that will instantly kill, then respawn Spyro at the postion you were in when you saved your bizhawk dump."
                    "You activate the code by inputting the button combination you chose above.");
                ImGui::NewLine;







                ImGui::Text(" ");

                static bool popstarterCheck = false;
                ImGui::Checkbox("Popstarter Code Format ($)", &popstarterCheck);
                ImGui::SameLine();
                HelpMarker("This will put $ before every line of code to support Popstarters code format.");



                if (popstarterCheck == true)
                {
                    publicPopstarterCheck = true;
                }

                if (popstarterCheck == false)
                    publicPopstarterCheck = false;


                ImGui::Text(" ");










            }


            if (deathButtonClicked & 1)
            {
                hasDeathButtonBeenPressed = true;
                hasCodeBeenCreated = true;
                if (gameChoice == 0)
                {
                    if (publicPopstarterCheck == true)
                    {

                        spyroX2Address = "$800778D8 ";    //BACKWARDS CUZ BYTES LOLOLOL
                        spyroX1Address = "$800778DA ";
                        spyroY2Address = "$800778DC ";
                        spyroY1Address = "$800778DE ";
                        spyroZ2Address = "$800778E0 ";
                        spyroZ1Address = "$800778E2 ";
                        spyroRespawnL2 = "$8007593C 0000";
                        spyroRespawnL4 = "$80077888 0001";
                        spyroRespawnL6 = "$800757D8 0004";
                        jokerCommand = "$D0077380 ";
                        infiniteLivesCode = "$8007582C 0099";
                    }

                    if (publicPopstarterCheck == false)
                    {

                        spyroX2Address = "800778D8 ";    //BACKWARDS CUZ BYTES LOLOLOL
                        spyroX1Address = "800778DA ";
                        spyroY2Address = "800778DC ";
                        spyroY1Address = "800778DE ";
                        spyroZ2Address = "800778E0 ";
                        spyroZ1Address = "800778E2 ";
                        spyroRespawnL2 = "8007593C 0000";
                        spyroRespawnL4 = "80077888 0001";
                        spyroRespawnL6 = "800757D8 0004";
                        jokerCommand = "D0077380 ";
                        infiniteLivesCode = "8007582C 0099";
                    }

                    LINE = 30886;
                    LINE2 = 30887;





                    for (int i = 1; i <= LINE; i++)
                        std::getline(f1, myData);
                    for (int i = 1; i <= LINE2; i++)
                        std::getline(f2, myData2);





                    //taking the 1byte hex codes and making them more easily accesible in strings
                    lbcSpyroX1 += myData[33];
                    lbcSpyroX1 += myData[34];
                    lbcSpyroX1 += myData[30];
                    lbcSpyroX1 += myData[31];

                    //splitting each byte into its own string
                    lbcSpyroX2 += myData[27];
                    lbcSpyroX2 += myData[28];
                    lbcSpyroX2 += myData[24];
                    lbcSpyroX2 += myData[25];


                    lbcSpyroY1 += myData[45];
                    lbcSpyroY1 += myData[46];
                    lbcSpyroY1 += myData[42];
                    lbcSpyroY1 += myData[43];


                    lbcSpyroY2 += myData[39];
                    lbcSpyroY2 += myData[40];
                    lbcSpyroY2 += myData[36];
                    lbcSpyroY2 += myData[37];


                    lbcSpyroZ1 += myData2[9];
                    lbcSpyroZ1 += myData2[10];
                    lbcSpyroZ1 += myData2[6];
                    lbcSpyroZ1 += myData2[7];


                    lbcSpyroZ2 += myData2[3];
                    lbcSpyroZ2 += myData2[4];
                    lbcSpyroZ2 += myData2[0];
                    lbcSpyroZ2 += myData2[1];








                    if (currentButtonCombo == 0)
                    {
                        currentButtonComboCode = "0043";
                    }

                    if (currentButtonCombo == 1)
                    {
                        currentButtonComboCode = "0023";
                    }
                    if (currentButtonCombo == 2)
                    {
                        currentButtonComboCode = "0013";
                    }
                    if (currentButtonCombo == 3)
                    {
                        currentButtonComboCode = "0083";
                    }
                    if (currentButtonCombo == 4)
                    {
                        currentButtonComboCode = "0031";
                    }
                    if (currentButtonCombo == 5)
                    {
                        currentButtonComboCode = "0032";
                    }




                    gameSharkCodeJoker = jokerCommand + currentButtonComboCode;
                    gameSharkCodeL2 = spyroX2Address + lbcSpyroX2;
                    gameSharkCodeL4 = spyroX1Address + lbcSpyroX1;
                    gameSharkCodeL6 = spyroY2Address + lbcSpyroY2;
                    gameSharkCodeL8 = spyroY1Address + lbcSpyroY1;
                    gameSharkCodeL10 = spyroZ2Address + lbcSpyroZ2;
                    gameSharkCodeL12 = spyroZ1Address + lbcSpyroZ1;
                    gameSharkCodeL14 = spyroRespawnL2;
                    gameSharkCodeL16 = spyroRespawnL4;
                    gameSharkCodeL18 = spyroRespawnL6;
                    if (publicLivesCheck == true)
                    {
                        gameSharkCodeL20 = infiniteLivesCode;
                    }





                    strcpy_s(gscCharJoker, gameSharkCodeJoker.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL2, 15, gameSharkCodeL2.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL4, 15, gameSharkCodeL4.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL6, 15, gameSharkCodeL6.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL8, 15, gameSharkCodeL8.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL10, 15, gameSharkCodeL10.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL12, 15, gameSharkCodeL12.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL14, 15, gameSharkCodeL14.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL16, 15, gameSharkCodeL16.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL18, 15, gameSharkCodeL18.c_str());    // or pass &s[0]
                    if (publicLivesCheck == true)
                        strcpy_s(gscCharL20, 15, gameSharkCodeL20.c_str());    // or pass &s[0]





                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL2;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL4;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL6;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL8;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL10;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL12;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL14;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL16;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL18;
                    fullGamesharkCode += '\n';
                    if (publicLivesCheck == true)
                    {
                        fullGamesharkCode += gscCharL20;
                        fullGamesharkCode += '\n';
                    }





                    strcpy_s(fullGamesharkCodeChar, 1000, fullGamesharkCode.c_str());







                    //std::cout << fullGamesharkCode;


                    gscCreated = true;

                    deathButtonClicked = 0;

                }


                if (gameChoice == 1)
                {
                    if (publicPopstarterCheck == true)
                    {

                        spyroX2Address = "$80067438 ";    //BACKWARDS CUZ BYTES LOLOLOL
                        spyroX1Address = "$8006743A ";
                        spyroY2Address = "$8006743C ";
                        spyroY1Address = "$8006743E ";
                        spyroZ2Address = "$80067440 ";
                        spyroZ1Address = "$80067442 ";
                        spyroRespawnL2 = "$800698EC 0000";
                        spyroRespawnL4 = "$800698F0 0000";
                        spyroRespawnL6 = "$800681C8 0003";
                        jokerCommand = "$D00683A0 ";
                        infiniteLivesCode = "$8006712C 0099";
                    }

                    if (publicPopstarterCheck == false)
                    {
                        spyroX2Address = "80067438 ";    //BACKWARDS CUZ BYTES LOLOLOL
                        spyroX1Address = "8006743A ";
                        spyroY2Address = "8006743C ";
                        spyroY1Address = "8006743E ";
                        spyroZ2Address = "80067440 ";
                        spyroZ1Address = "80067442 ";
                        spyroRespawnL2 = "800698EC 0000";
                        spyroRespawnL4 = "800698F0 0000";
                        spyroRespawnL6 = "800681C8 0003";
                        jokerCommand = "D00683A0 ";
                        infiniteLivesCode = "8006712C 0099";
                    }

                    LINE = 27136;   // RESPAWN LOCATION LINES, NOT SPYRO POSITION





                    for (int i = 1; i <= LINE; i++)
                        std::getline(f1, myData);





                    //taking the 1byte hex codes and making them more easily accesible in strings
                    lbcSpyroX1 += myData[9];
                    lbcSpyroX1 += myData[10];
                    lbcSpyroX1 += myData[6];
                    lbcSpyroX1 += myData[7];

                    //splitting each byte into its own string
                    lbcSpyroX2 += myData[3];
                    lbcSpyroX2 += myData[4];
                    lbcSpyroX2 += myData[0];
                    lbcSpyroX2 += myData[1];


                    lbcSpyroY1 += myData[21];
                    lbcSpyroY1 += myData[22];
                    lbcSpyroY1 += myData[18];
                    lbcSpyroY1 += myData[19];


                    lbcSpyroY2 += myData[15];
                    lbcSpyroY2 += myData[16];
                    lbcSpyroY2 += myData[12];
                    lbcSpyroY2 += myData[13];


                    lbcSpyroZ1 += myData[33];
                    lbcSpyroZ1 += myData[34];
                    lbcSpyroZ1 += myData[30];
                    lbcSpyroZ1 += myData[31];


                    lbcSpyroZ2 += myData[27];
                    lbcSpyroZ2 += myData[28];
                    lbcSpyroZ2 += myData[24];
                    lbcSpyroZ2 += myData[25];







                    if (currentButtonCombo == 0)
                    {
                        currentButtonComboCode = "0043";
                    }

                    if (currentButtonCombo == 1)
                    {
                        currentButtonComboCode = "0023";
                    }
                    if (currentButtonCombo == 2)
                    {
                        currentButtonComboCode = "0013";
                    }
                    if (currentButtonCombo == 3)
                    {
                        currentButtonComboCode = "0083";
                    }
                    if (currentButtonCombo == 4)
                    {
                        currentButtonComboCode = "0031";
                    }
                    if (currentButtonCombo == 5)
                    {
                        currentButtonComboCode = "0032";
                    }
                    if (currentButtonCombo == 6)
                    {
                        currentButtonComboCode = "0045";
                    }
                    if (currentButtonCombo == 7)
                    {
                        currentButtonComboCode = "0085";
                    }
                    if (currentButtonCombo == 8)
                    {
                        currentButtonComboCode = "0025";
                    }
                    if (currentButtonCombo == 9)
                    {
                        currentButtonComboCode = "0015";
                    }
                    if (currentButtonCombo == 10)
                    {
                        currentButtonComboCode = "004A";
                    }
                    if (currentButtonCombo == 11)
                    {
                        currentButtonComboCode = "008A";
                    }
                    if (currentButtonCombo == 12)
                    {
                        currentButtonComboCode = "002A";
                    }
                    if (currentButtonCombo == 13)
                    {
                        currentButtonComboCode = "001A";
                    }





                    gameSharkCodeJoker = jokerCommand + currentButtonComboCode;
                    gameSharkCodeL2 = spyroX2Address + lbcSpyroX2;
                    gameSharkCodeL4 = spyroX1Address + lbcSpyroX1;
                    gameSharkCodeL6 = spyroY2Address + lbcSpyroY2;
                    gameSharkCodeL8 = spyroY1Address + lbcSpyroY1;
                    gameSharkCodeL10 = spyroZ2Address + lbcSpyroZ2;
                    gameSharkCodeL12 = spyroZ1Address + lbcSpyroZ1;
                    gameSharkCodeL14 = spyroRespawnL2;
                    gameSharkCodeL16 = spyroRespawnL4;
                    gameSharkCodeL18 = spyroRespawnL6;
                    if (publicLivesCheck == true)
                        gameSharkCodeL20 = infiniteLivesCode;





                    strcpy_s(gscCharJoker, gameSharkCodeJoker.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL2, 15, gameSharkCodeL2.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL4, 15, gameSharkCodeL4.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL6, 15, gameSharkCodeL6.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL8, 15, gameSharkCodeL8.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL10, 15, gameSharkCodeL10.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL12, 15, gameSharkCodeL12.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL14, 15, gameSharkCodeL14.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL16, 15, gameSharkCodeL16.c_str());    // or pass &s[0]
                    strcpy_s(gscCharL18, 15, gameSharkCodeL18.c_str());    // or pass &s[0]
                    if (publicLivesCheck == true)
                        strcpy_s(gscCharL20, 15, gameSharkCodeL20.c_str());    // or pass &s[0]




                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL2;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL4;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL6;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL8;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL10;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL12;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL14;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL16;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL18;
                    fullGamesharkCode += '\n';
                    if (publicLivesCheck == true)
                    {
                        fullGamesharkCode += gscCharL20;
                        fullGamesharkCode += '\n';
                    }



                    strcpy_s(fullGamesharkCodeChar, 1000, fullGamesharkCode.c_str());

                    gscCreated = true;

                    deathButtonClicked = 0;

                }

                if (gameChoice == 2)
                {
                    if (publicPopstarterCheck == true)
                    {

                        spyroX2Address = "$8006D0AC ";    //BACKWARDS CUZ BYTES LOLOLOL
                        spyroX1Address = "$8006D0AE ";
                        spyroY2Address = "$8006D0B0 ";
                        spyroY1Address = "$8006D0B2 ";
                        spyroZ2Address = "$8006D0B4 ";
                        spyroZ1Address = "$8006D0B6 ";
                        spyroRespawnL2 = "$8006C598 0000";
                        spyroRespawnL4 = "$8006FBC8 0000";
                        spyroRespawnL6 = "$8006E344 0003";
                        jokerCommand = "$D006E538 ";
                        infiniteLivesCode = "$8006C784 0099";
                    }

                    if (publicPopstarterCheck == false)
                    {
                        spyroX2Address = "8006D0AC ";    //BACKWARDS CUZ BYTES LOLOLOL
                        spyroX1Address = "8006D0AE ";
                        spyroY2Address = "8006D0B0 ";
                        spyroY1Address = "8006D0B2 ";
                        spyroZ2Address = "8006D0B4 ";
                        spyroZ1Address = "8006D0B6 ";
                        spyroRespawnL2 = "8006C598 0000";
                        spyroRespawnL4 = "8006FBC8 0000";
                        spyroRespawnL6 = "8006E344 0003";
                        jokerCommand = "D006E538 ";
                        infiniteLivesCode = "8006C784 0099";
                    }


                    LINE = 102480;
                    LINE2 = 102481;




                    for (int i = 1; i <= LINE; i++)
                        std::getline(f1, myData);
                    for (int i = 1; i <= LINE2; i++)
                        std::getline(f2, myData2);




                    //taking the 1byte hex codes and making them more easily accesible in strings
                    lbcSpyroX1 += myData[33];
                    lbcSpyroX1 += myData[34];
                    lbcSpyroX1 += myData[30];
                    lbcSpyroX1 += myData[31];

                    //splitting each byte into its own string
                    lbcSpyroX2 += myData[27];
                    lbcSpyroX2 += myData[28];
                    lbcSpyroX2 += myData[24];
                    lbcSpyroX2 += myData[25];


                    lbcSpyroY1 += myData[45];
                    lbcSpyroY1 += myData[46];
                    lbcSpyroY1 += myData[42];
                    lbcSpyroY1 += myData[43];


                    lbcSpyroY2 += myData[39];
                    lbcSpyroY2 += myData[40];
                    lbcSpyroY2 += myData[36];
                    lbcSpyroY2 += myData[37];


                    lbcSpyroZ1 += myData2[9];
                    lbcSpyroZ1 += myData2[10];
                    lbcSpyroZ1 += myData2[6];
                    lbcSpyroZ1 += myData2[7];


                    lbcSpyroZ2 += myData2[3];
                    lbcSpyroZ2 += myData2[4];
                    lbcSpyroZ2 += myData2[0];
                    lbcSpyroZ2 += myData2[1];



                    if (currentButtonCombo == 0)
                    {
                        currentButtonComboCode = "0043";
                    }

                    if (currentButtonCombo == 1)
                    {
                        currentButtonComboCode = "0023";
                    }
                    if (currentButtonCombo == 2)
                    {
                        currentButtonComboCode = "0013";
                    }
                    if (currentButtonCombo == 3)
                    {
                        currentButtonComboCode = "0083";
                    }
                    if (currentButtonCombo == 4)
                    {
                        currentButtonComboCode = "0031";
                    }
                    if (currentButtonCombo == 5)
                    {
                        currentButtonComboCode = "0032";
                    }
                    if (currentButtonCombo == 6)
                    {
                        currentButtonComboCode = "0045";
                    }
                    if (currentButtonCombo == 7)
                    {
                        currentButtonComboCode = "0085";
                    }
                    if (currentButtonCombo == 8)
                    {
                        currentButtonComboCode = "0025";
                    }
                    if (currentButtonCombo == 9)
                    {
                        currentButtonComboCode = "0015";
                    }
                    if (currentButtonCombo == 10)
                    {
                        currentButtonComboCode = "004A";
                    }
                    if (currentButtonCombo == 11)
                    {
                        currentButtonComboCode = "008A";
                    }
                    if (currentButtonCombo == 12)
                    {
                        currentButtonComboCode = "002A";
                    }
                    if (currentButtonCombo == 13)
                    {
                        currentButtonComboCode = "001A";
                    }





                    gameSharkCodeJoker = jokerCommand + currentButtonComboCode;
                    gameSharkCodeL2 = spyroX2Address + lbcSpyroX2;
                    gameSharkCodeL4 = spyroX1Address + lbcSpyroX1;
                    gameSharkCodeL6 = spyroY2Address + lbcSpyroY2;
                    gameSharkCodeL8 = spyroY1Address + lbcSpyroY1;
                    gameSharkCodeL10 = spyroZ2Address + lbcSpyroZ2;
                    gameSharkCodeL12 = spyroZ1Address + lbcSpyroZ1;
                    gameSharkCodeL14 = spyroRespawnL2;
                    gameSharkCodeL16 = spyroRespawnL4;
                    gameSharkCodeL18 = spyroRespawnL6;
                    if (publicLivesCheck == true)
                        gameSharkCodeL20 = infiniteLivesCode;





                    strcpy_s(gscCharJoker, gameSharkCodeJoker.c_str());
                    strcpy_s(gscCharL2, 15, gameSharkCodeL2.c_str());
                    strcpy_s(gscCharL4, 15, gameSharkCodeL4.c_str());
                    strcpy_s(gscCharL6, 15, gameSharkCodeL6.c_str());
                    strcpy_s(gscCharL8, 15, gameSharkCodeL8.c_str());
                    strcpy_s(gscCharL10, 15, gameSharkCodeL10.c_str());
                    strcpy_s(gscCharL12, 15, gameSharkCodeL12.c_str());
                    strcpy_s(gscCharL14, 15, gameSharkCodeL14.c_str());
                    strcpy_s(gscCharL16, 15, gameSharkCodeL16.c_str());
                    strcpy_s(gscCharL18, 15, gameSharkCodeL18.c_str());
                    if (publicLivesCheck == true)
                    {
                        strcpy_s(gscCharL18, 15, gameSharkCodeL18.c_str());
                    }



                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL2;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL4;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL6;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL8;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL10;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL12;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL14;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL16;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL18;
                    fullGamesharkCode += '\n';
                    if (publicLivesCheck == true)
                    {
                        fullGamesharkCode += gscCharL18;
                        fullGamesharkCode += '\n';
                    }



                    strcpy_s(fullGamesharkCodeChar, 1000, fullGamesharkCode.c_str());

                    //std::cout << fullGamesharkCode;


                    gscCreated = true;


                    deathButtonClicked = 0;

                }












                if (gameChoice == 3)
                {
                    if (publicPopstarterCheck == true)
                    {

                        spyroX2Address = "$8006D18C ";    //BACKWARDS CUZ BYTES LOLOLOL
                        spyroX1Address = "$8006D18E ";
                        spyroY2Address = "$8006D190 ";
                        spyroY1Address = "$8006D192 ";
                        spyroZ2Address = "$8006D194 ";
                        spyroZ1Address = "$8006D196 ";
                        spyroRespawnL2 = "$8006FCA4 0000";
                        spyroRespawnL4 = "$8006FCA8 0000";
                        spyroRespawnL6 = "$8006E424 0003";
                        jokerCommand = "$D006E618 ";
                        infiniteLivesCode = "$8006C864 0099";
                    }

                    if (publicPopstarterCheck == false)
                    {
                        spyroX2Address = "8006D18C ";    //BACKWARDS CUZ BYTES LOLOLOL
                        spyroX1Address = "8006D18E ";
                        spyroY2Address = "8006D190 ";
                        spyroY1Address = "8006D192 ";
                        spyroZ2Address = "8006D194 ";
                        spyroZ1Address = "8006D196 ";
                        spyroRespawnL2 = "8006FCA4 0000";
                        spyroRespawnL4 = "8006FCA8 0000";
                        spyroRespawnL6 = "8006E424 0003";
                        jokerCommand = "D006E618 ";
                        infiniteLivesCode = "8006C864 0099";
                    }



                    LINE = 102494;
                    LINE2 = 102495;




                    for (int i = 1; i <= LINE; i++)
                        std::getline(f1, myData);
                    for (int i = 1; i <= LINE2; i++)
                        std::getline(f2, myData2);




                    //taking the 1byte hex codes and making them more easily accesible in strings
                    lbcSpyroX1 += myData[33];
                    lbcSpyroX1 += myData[34];
                    lbcSpyroX1 += myData[30];
                    lbcSpyroX1 += myData[31];

                    //splitting each byte into its own string
                    lbcSpyroX2 += myData[27];
                    lbcSpyroX2 += myData[28];
                    lbcSpyroX2 += myData[24];
                    lbcSpyroX2 += myData[25];


                    lbcSpyroY1 += myData[45];
                    lbcSpyroY1 += myData[46];
                    lbcSpyroY1 += myData[42];
                    lbcSpyroY1 += myData[43];


                    lbcSpyroY2 += myData[39];
                    lbcSpyroY2 += myData[40];
                    lbcSpyroY2 += myData[36];
                    lbcSpyroY2 += myData[37];


                    lbcSpyroZ1 += myData2[9];
                    lbcSpyroZ1 += myData2[10];
                    lbcSpyroZ1 += myData2[6];
                    lbcSpyroZ1 += myData2[7];


                    lbcSpyroZ2 += myData2[3];
                    lbcSpyroZ2 += myData2[4];
                    lbcSpyroZ2 += myData2[0];
                    lbcSpyroZ2 += myData2[1];



                    if (currentButtonCombo == 0)
                    {
                        currentButtonComboCode = "0043";
                    }

                    if (currentButtonCombo == 1)
                    {
                        currentButtonComboCode = "0023";
                    }
                    if (currentButtonCombo == 2)
                    {
                        currentButtonComboCode = "0013";
                    }
                    if (currentButtonCombo == 3)
                    {
                        currentButtonComboCode = "0083";
                    }
                    if (currentButtonCombo == 4)
                    {
                        currentButtonComboCode = "0031";
                    }
                    if (currentButtonCombo == 5)
                    {
                        currentButtonComboCode = "0032";
                    }
                    if (currentButtonCombo == 6)
                    {
                        currentButtonComboCode = "0045";
                    }
                    if (currentButtonCombo == 7)
                    {
                        currentButtonComboCode = "0085";
                    }
                    if (currentButtonCombo == 8)
                    {
                        currentButtonComboCode = "0025";
                    }
                    if (currentButtonCombo == 9)
                    {
                        currentButtonComboCode = "0015";
                    }
                    if (currentButtonCombo == 10)
                    {
                        currentButtonComboCode = "004A";
                    }
                    if (currentButtonCombo == 11)
                    {
                        currentButtonComboCode = "008A";
                    }
                    if (currentButtonCombo == 12)
                    {
                        currentButtonComboCode = "002A";
                    }
                    if (currentButtonCombo == 13)
                    {
                        currentButtonComboCode = "001A";
                    }





                    gameSharkCodeJoker = jokerCommand + currentButtonComboCode;
                    gameSharkCodeL2 = spyroX2Address + lbcSpyroX2;
                    gameSharkCodeL4 = spyroX1Address + lbcSpyroX1;
                    gameSharkCodeL6 = spyroY2Address + lbcSpyroY2;
                    gameSharkCodeL8 = spyroY1Address + lbcSpyroY1;
                    gameSharkCodeL10 = spyroZ2Address + lbcSpyroZ2;
                    gameSharkCodeL12 = spyroZ1Address + lbcSpyroZ1;
                    gameSharkCodeL14 = spyroRespawnL2;
                    gameSharkCodeL16 = spyroRespawnL4;
                    gameSharkCodeL18 = spyroRespawnL6;
                    if (publicLivesCheck == true)
                        gameSharkCodeL20 = infiniteLivesCode;





                    strcpy_s(gscCharJoker, gameSharkCodeJoker.c_str());
                    strcpy_s(gscCharL2, 15, gameSharkCodeL2.c_str());
                    strcpy_s(gscCharL4, 15, gameSharkCodeL4.c_str());
                    strcpy_s(gscCharL6, 15, gameSharkCodeL6.c_str());
                    strcpy_s(gscCharL8, 15, gameSharkCodeL8.c_str());
                    strcpy_s(gscCharL10, 15, gameSharkCodeL10.c_str());
                    strcpy_s(gscCharL12, 15, gameSharkCodeL12.c_str());
                    strcpy_s(gscCharL14, 15, gameSharkCodeL14.c_str());
                    strcpy_s(gscCharL16, 15, gameSharkCodeL16.c_str());
                    strcpy_s(gscCharL18, 15, gameSharkCodeL18.c_str());
                    if (publicLivesCheck == true)
                        strcpy_s(gscCharL20, 15, gameSharkCodeL20.c_str());



                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL2;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL4;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL6;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL8;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL10;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL12;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL14;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL16;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharJoker;
                    fullGamesharkCode += '\n';
                    fullGamesharkCode += gscCharL18;
                    fullGamesharkCode += '\n';
                    if (publicLivesCheck == true)
                    {
                        fullGamesharkCode += gscCharL20;
                        fullGamesharkCode += '\n';
                    }



                    strcpy_s(fullGamesharkCodeChar, 1000, fullGamesharkCode.c_str());

                    gscCreated = true;

                    deathButtonClicked = 0;

                }

            }




            //Teleport Spyro Text Code Outputs
            //Teleport Spyro Text Code Outputs
            //Teleport Spyro Text Code Outputs
            //Teleport Spyro Text Code Outputs




            if (hasButtonBeenPressed == true && gameChoice == 0)    //spliting up output bcuz spyro 1 has 2 more lines for extra camera values
            {



                ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "Code Generated!");
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL2);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL4);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL6);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL8);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL10);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL12);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL14);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL16);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL18);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL20);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL22);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL24);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL26);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL28);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL30);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL32);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL34);
                if (publicSparxCheck == true)
                {
                    ImGui::Text(gscCharJoker);
                    ImGui::Text(gscCharL36);
                }

                if (publicLivesCheck == true)
                {
                    ImGui::Text(gscCharL38);
                }


                static int copyClicked = 0;


                for (int i = 0; i < 1; i++)
                {
                    if (i > 0)
                        ImGui::SameLine();
                    ImGui::PushID(i);
                    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(6 / 7.0f, 0.6f, 0.6f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(6 / 7.0f, 0.7f, 0.7f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(6 / 7.0f, 0.8f, 0.8f));
                    if (ImGui::Button("Copy to Clipboard"))
                        copyClicked++;
                    if (copyClicked & 1)
                    {
                        ImGui::SetClipboardText(fullGamesharkCodeChar);
                        copyClicked = 0;
                    }
                    ImGui::PopStyleColor(3);
                    ImGui::PopID();
                }



                static int resetClicked = 0;

                for (int i = 0; i < 1; i++)
                {
                    if (i > 0)
                        ImGui::SameLine();
                    ImGui::PushID(i);
                    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(7 / 7.0f, 0.6f, 0.6f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(7 / 7.0f, 0.7f, 0.7f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(7 / 7.0f, 0.8f, 0.8f));
                    ImGui::SameLine();
                    if (ImGui::Button("Reset"))
                        resetClicked++;
                    if (resetClicked & 1)
                    {
                        resetClicked = 0;
                        fileOpened = false;
                        hasButtonBeenPressed = false;
                        hasCodeBeenCreated = false;
                    }
                    ImGui::PopStyleColor(3);
                    ImGui::PopID();
                }



            }

            if (hasButtonBeenPressed == true && gameChoice == 1)    //spliting up output bcuz spyro games have more or less lines of code that are needed
            {



                ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "Code Generated!");
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL2);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL4);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL6);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL8);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL10);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL12);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL14);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL16);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL18);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL20);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL22);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL24);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL26);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL28);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL30);


                if (publicSparxCheck == true)
                {
                    ImGui::Text(gscCharJoker);
                    ImGui::Text(gscCharL32);
                }
                if (publicLivesCheck == true)
                {
                    ImGui::Text(gscCharL34);
                }

                std::cout << sparxHealthValue;
                static int copyClicked = 0;


                for (int i = 0; i < 1; i++)
                {
                    if (i > 0)
                        ImGui::SameLine();
                    ImGui::PushID(i);
                    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(6 / 7.0f, 0.6f, 0.6f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(6 / 7.0f, 0.7f, 0.7f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(6 / 7.0f, 0.8f, 0.8f));
                    if (ImGui::Button("Copy to Clipboard"))
                        copyClicked++;
                    if (copyClicked & 1)
                    {
                        ImGui::SetClipboardText(fullGamesharkCodeChar);
                        copyClicked = 0;
                    }
                    ImGui::PopStyleColor(3);
                    ImGui::PopID();
                }





                static int resetClicked = 0;

                for (int i = 0; i < 1; i++)
                {
                    if (i > 0)
                        ImGui::SameLine();
                    ImGui::PushID(i);
                    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(7 / 7.0f, 0.6f, 0.6f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(7 / 7.0f, 0.7f, 0.7f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(7 / 7.0f, 0.8f, 0.8f));
                    ImGui::SameLine();
                    if (ImGui::Button("Reset"))
                        resetClicked++;
                    if (resetClicked & 1)
                    {
                        resetClicked = 0;
                        fileOpened = false;
                        hasButtonBeenPressed = false;
                        hasCodeBeenCreated = false;
                    }
                    ImGui::PopStyleColor(3);
                    ImGui::PopID();
                }






            }


            if (hasButtonBeenPressed == true && gameChoice == 2)    //spliting up output bcuz spyro 1 has 2 more lines for extra camera values
            {



                ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "Code Generated!");
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL2);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL4);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL6);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL8);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL10);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL12);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL14);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL16);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL18);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL20);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL22);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL24);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL26);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL28);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL30);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL32);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL34);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL36);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL38);
                if (publicSparxCheck == true)
                {
                    ImGui::Text(gscCharJoker);
                    ImGui::Text(gscCharL40);
                }
                if (publicLivesCheck == true)
                {
                    ImGui::Text(gscCharL42);
                }

                static int copyClicked = 0;

                for (int i = 0; i < 1; i++)
                {
                    if (i > 0)
                        ImGui::SameLine();
                    ImGui::PushID(i);
                    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(6 / 7.0f, 0.6f, 0.6f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(6 / 7.0f, 0.7f, 0.7f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(6 / 7.0f, 0.8f, 0.8f));
                    if (ImGui::Button("Copy to Clipboard"))
                        copyClicked++;
                    if (copyClicked & 1)
                    {
                        ImGui::SetClipboardText(fullGamesharkCodeChar);
                        copyClicked = 0;
                    }
                    ImGui::PopStyleColor(3);
                    ImGui::PopID();
                }







                static int resetClicked = 0;

                for (int i = 0; i < 1; i++)
                {
                    if (i > 0)
                        ImGui::SameLine();
                    ImGui::PushID(i);
                    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(7 / 7.0f, 0.6f, 0.6f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(7 / 7.0f, 0.7f, 0.7f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(7 / 7.0f, 0.8f, 0.8f));
                    ImGui::SameLine();
                    if (ImGui::Button("Reset"))
                        resetClicked++;
                    if (resetClicked & 1)
                    {
                        resetClicked = 0;
                        fileOpened = false;
                        hasButtonBeenPressed = false;
                        hasCodeBeenCreated = false;
                    }
                    ImGui::PopStyleColor(3);
                    ImGui::PopID();
                }


            }






            if (hasButtonBeenPressed == true && gameChoice == 3)    //spliting up output bcuz spyro 1 has 2 more lines for extra camera values
            {



                ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "Code Generated!");
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL2);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL4);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL6);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL8);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL10);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL12);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL14);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL16);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL18);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL20);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL22);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL24);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL26);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL28);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL30);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL32);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL34);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL36);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL38);
                if (publicSparxCheck == true)
                {
                    ImGui::Text(gscCharJoker);
                    ImGui::Text(gscCharL40);
                }

                if (publicLivesCheck == true)
                {
                    ImGui::Text(gscCharL42);
                }

                static int copyClicked = 0;

                for (int i = 0; i < 1; i++)
                {
                    if (i > 0)
                        ImGui::SameLine();
                    ImGui::PushID(i);
                    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(6 / 7.0f, 0.6f, 0.6f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(6 / 7.0f, 0.7f, 0.7f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(6 / 7.0f, 0.8f, 0.8f));
                    if (ImGui::Button("Copy to Clipboard"))
                        copyClicked++;
                    if (copyClicked & 1)
                    {
                        ImGui::SetClipboardText(fullGamesharkCodeChar);
                        copyClicked = 0;
                    }
                    ImGui::PopStyleColor(3);
                    ImGui::PopID();
                }







                static int resetClicked = 0;

                for (int i = 0; i < 1; i++)
                {
                    if (i > 0)
                        ImGui::SameLine();
                    ImGui::PushID(i);
                    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(7 / 7.0f, 0.6f, 0.6f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(7 / 7.0f, 0.7f, 0.7f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(7 / 7.0f, 0.8f, 0.8f));
                    ImGui::SameLine();
                    if (ImGui::Button("Reset"))
                        resetClicked++;
                    if (resetClicked & 1)
                    {
                        resetClicked = 0;
                        fileOpened = false;
                        hasButtonBeenPressed = false;
                        hasCodeBeenCreated = false;
                    }
                    ImGui::PopStyleColor(3);
                    ImGui::PopID();
                }


            }




            //Respawn/Die Outputs
            //Respawn/Die Outputs           
            //Respawn/Die Outputs
            //Respawn/Die Outputs
            //Respawn/Die Outputs
            //Respawn/Die Outputs
            //Respawn/Die Outputs









            if (hasDeathButtonBeenPressed == true && gameChoice == 1 || hasDeathButtonBeenPressed == true && gameChoice == 2 || hasDeathButtonBeenPressed == true && gameChoice == 3)    //spliting up output bcuz spyro 1 has 2 more lines for extra camera values
            {



                ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "Code Generated!");
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL2);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL4);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL6);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL8);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL10);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL12);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL14);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL16);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL18);
                if (publicLivesCheck == true)
                {
                    ImGui::Text(gscCharL20);
                }

                static int copyClicked = 0;


                for (int i = 0; i < 1; i++)
                {
                    if (i > 0)
                        ImGui::SameLine();
                    ImGui::PushID(i);
                    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(6 / 7.0f, 0.6f, 0.6f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(6 / 7.0f, 0.7f, 0.7f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(6 / 7.0f, 0.8f, 0.8f));
                    if (ImGui::Button("Copy to Clipboard"))
                        copyClicked++;
                    if (copyClicked & 1)
                    {
                        ImGui::SetClipboardText(fullGamesharkCodeChar);
                        copyClicked = 0;
                    }
                    ImGui::PopStyleColor(3);
                    ImGui::PopID();
                }





                static int resetClicked = 0;

                for (int i = 0; i < 1; i++)
                {
                    if (i > 0)
                        ImGui::SameLine();
                    ImGui::PushID(i);
                    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(7 / 7.0f, 0.6f, 0.6f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(7 / 7.0f, 0.7f, 0.7f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(7 / 7.0f, 0.8f, 0.8f));
                    ImGui::SameLine();
                    if (ImGui::Button("Reset"))
                        resetClicked++;
                    if (resetClicked & 1)
                    {
                        resetClicked = 0;
                        fileOpened = false;
                        hasDeathButtonBeenPressed = false;
                        hasCodeBeenCreated = false;
                    }
                    ImGui::PopStyleColor(3);
                    ImGui::PopID();
                }



            }


            if (hasDeathButtonBeenPressed == true && gameChoice == 0)    //spliting up output bcuz spyro 1 has 2 more lines for extra camera values
            {



                ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "Code Generated!");
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL2);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL4);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL6);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL8);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL10);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL12);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL14);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL16);
                ImGui::Text(gscCharJoker);
                ImGui::Text(gscCharL18);
                if (publicLivesCheck == true)
                {
                    ImGui::Text(gscCharL20);
                }



                static int copyClicked = 0;

                for (int i = 0; i < 1; i++)
                {
                    if (i > 0)
                        ImGui::SameLine();
                    ImGui::PushID(i);
                    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(6 / 7.0f, 0.6f, 0.6f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(6 / 7.0f, 0.7f, 0.7f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(6 / 7.0f, 0.8f, 0.8f));
                    if (ImGui::Button("Copy to Clipboard"))
                        copyClicked++;
                    if (copyClicked & 1)
                    {
                        ImGui::SetClipboardText(fullGamesharkCodeChar);
                        copyClicked = 0;
                    }
                    ImGui::PopStyleColor(3);
                    ImGui::PopID();
                }





                static int resetClicked = 0;

                for (int i = 0; i < 1; i++)
                {
                    if (i > 0)
                        ImGui::SameLine();
                    ImGui::PushID(i);
                    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(8 / 7.0f, 0.6f, 0.6f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(8 / 7.0f, 0.7f, 0.7f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(8 / 7.0f, 0.8f, 0.8f));
                    ImGui::SameLine();
                    if (ImGui::Button("Reset"))
                        resetClicked++;
                    if (resetClicked & 1)
                    {
                        resetClicked = 0;
                        fileOpened = false;
                        hasDeathButtonBeenPressed = false;
                        hasCodeBeenCreated = false;
                    }
                    ImGui::PopStyleColor(3);
                    ImGui::PopID();
                }




            }












        }

        ImGui::End();





        // Rendering
        ImGui::EndFrame();
        g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
        g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
        g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
        D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x * clear_color.w * 255.0f), (int)(clear_color.y * clear_color.w * 255.0f), (int)(clear_color.z * clear_color.w * 255.0f), (int)(clear_color.w * 255.0f));
        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }
        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

        // Handle loss of D3D9 device
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
            ResetDevice();
    }

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;
}

// Helper functions

bool CreateDeviceD3D(HWND hWnd)
{
    if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
        return false;

    // Create the D3DDevice
    ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
    g_d3dpp.Windowed = TRUE;
    g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN; // Need to use an explicit format with alpha if needing per-pixel alpha composition.
    g_d3dpp.EnableAutoDepthStencil = TRUE;
    g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;           // Present with vsync
    //g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync, maximum unthrottled framerate
    if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
        return false;

    return true;
}

void CleanupDeviceD3D()
{
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
    if (g_pD3D) { g_pD3D->Release(); g_pD3D = NULL; }
}

void ResetDevice()
{
    ImGui_ImplDX9_InvalidateDeviceObjects();
    HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
    if (hr == D3DERR_INVALIDCALL)
        IM_ASSERT(0);
    ImGui_ImplDX9_CreateDeviceObjects();
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}

