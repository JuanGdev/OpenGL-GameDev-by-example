// RoboRacer2D.cpp : Define el punto de entrada de la aplicación.
//

#include "framework.h"
#include "RoboRacer2D.h"
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "SOIL.h"
#include "Sprite.h"


#define MAX_LOADSTRING 100

// Variables globales:
HINSTANCE hInst;                                // instancia actual
WCHAR szTitle[MAX_LOADSTRING];                  // Texto de la barra de título
WCHAR szWindowClass[MAX_LOADSTRING];            // nombre de clase de la ventana principal

Sprite* robot_left;
Sprite* robot_right;
Sprite* robot_right_strip;
Sprite* robot_left_strip;
Sprite* background;
Sprite* player;

// Declaraciones de funciones adelantadas incluidas en este módulo de código:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void GameLoop() {};
void EndGame() {};
const bool LoadTextures()
{
    background = new Sprite(1);
    background->SetFrameSize(1877.0f, 600.0f);
    background->SetNumberOfFrames(1);
    //background->AddTexture("background.png", false);

    //robot_right = new Sprite(4);
    //robot_right->SetFrameSize(100.0f, 125.0f);
    //robot_right->SetNumberOfFrames(4);
    //robot_right->SetPosition(0, 250.0f);
    //robot_right->AddTexture(""); // 1
    //robot_right->AddTexture(""); // 2
    //robot_right->AddTexture(""); // 3
    //robot_right->AddTexture(""); // 4

    //robot_left = new Sprite(4);
    //robot_left->SetFrameSize(100.0f, 125.0f);
    //robot_left->SetNumberOfFrames(4);
    //robot_left->SetPosition(0, 250.0f);
    //robot_left->AddTexture(""); // 1
    //robot_left->AddTexture(""); // 2
    //robot_left->AddTexture(""); // 3
    //robot_left->AddTexture(""); // 4

    //robot_right_strip = new Sprite(1);
    //robot_right_strip->SetFrameSize(125.0f, 100.0f);
    //robot_right_strip->SetNumberOfFrames(4);
    //robot_right_strip->SetPosition(0, 250.0f);
    //robot_right_strip->AddTexture(""); // 1
    //robot_right_strip->AddTexture(""); // 2
    //robot_right_strip->AddTexture(""); // 3
    //robot_right_strip->AddTexture(""); // 4

    //robot_left_strip = new Sprite(1);
    //robot_left_strip->SetFrameSize(125.0f, 100.0f);
    //robot_left_strip->SetNumberOfFrames(4);
    //robot_left_strip->SetPosition(0, 250.0f);
    //robot_left_strip->AddTexture(""); // 1
    //robot_left_strip->AddTexture(""); // 2
    //robot_left_strip->AddTexture(""); // 3
    //robot_left_strip->AddTexture(""); // 4

    background->IsVisible(true);
    background->IsActive(true);
    background->SetVelocity(-50.0f);

    //robot_right->IsActive(true);
    //robot_right->IsVisible(true);
    //robot_right->SetVelocity(50.0f);

    //player = robot_right;
    //player->IsActive(true);
    //player->IsVisible(true);
    //player->SetVelocity(50.0f);

    return true;
}

void StartGame() {
    //LoadTextures();
};
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Colocar código aquí.
    
    // Inicializar cadenas globales
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_ROBORACER2D, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Realizar la inicialización de la aplicación:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ROBORACER2D));

    MSG msg;

    // Bucle principal de mensajes:
    StartGame();
    // Game loop
    bool done = false;
    while (!done)
    {
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                done = true;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            GameLoop();
        }
    }
    EndGame();

    return (int) msg.wParam;
}



//
//  FUNCIÓN: MyRegisterClass()
//
//  PROPÓSITO: Registra la clase de ventana.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ROBORACER2D));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_ROBORACER2D);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCIÓN: InitInstance(HINSTANCE, int)
//
//   PROPÓSITO: Guarda el identificador de instancia y crea la ventana principal
//
//   COMENTARIOS:
//
//        En esta función, se guarda el identificador de instancia en una variable común y
//        se crea y muestra la ventana principal del programa.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Almacenar identificador de instancia en una variable global

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCIÓN: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PROPÓSITO: Procesa mensajes de la ventana principal.
//
//  WM_COMMAND  - procesar el menú de aplicaciones
//  WM_PAINT    - Pintar la ventana principal
//  WM_DESTROY  - publicar un mensaje de salida y volver
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Analizar las selecciones de menú:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Agregar cualquier código de dibujo que use hDC aquí...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Controlador de mensajes del cuadro Acerca de.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
