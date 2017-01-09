#include <windows.h>

#include "GUI_SIM_Win32.h"
#include "LCD_SIM.h"
#include "GUI.h"

void MainTask(void);
static DWORD __stdcall _Thread(void* Parameter) {
  MainTask();
  return 0;
}

static LRESULT CALLBACK _WndProcMain(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
  SIM_GUI_HandleKeyEvents(message, wParam);
  switch (message) {
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  }
  return DefWindowProc(hWnd, message, wParam, lParam);
}

static void _RegisterClass(HINSTANCE hInstance) {
  WNDCLASSEX wcex;
  memset (&wcex, 0,  sizeof(wcex));
  wcex.cbSize        = sizeof(WNDCLASSEX);
  wcex.hInstance     = hInstance;
  wcex.style         = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc   = (WNDPROC)_WndProcMain;
  wcex.hIcon         = 0;
  wcex.hCursor       = LoadCursor(NULL, IDC_ARROW);
  wcex.hbrBackground = (HBRUSH)(COLOR_APPWORKSPACE + 1);
  wcex.lpszMenuName  = 0;
  wcex.lpszClassName = "GUIApplication";
  RegisterClassEx(&wcex);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  DWORD ThreadID;
  MSG   Msg;
 HACCEL hAccelTable;
  HWND  hWndMain;
  /* Register window class */
  _RegisterClass(hInstance);
  /* Make sure the driver configuration is done */
  SIM_GUI_Enable();
  /* Create main window */
  hWndMain = CreateWindow("GUIApplication", "Application window",
                          WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_VISIBLE,
                          100, 100, 490, 310, NULL, NULL, hInstance, NULL);
  /* Initialize the GUI simulation and create a LCD window */
  SIM_GUI_Init(hInstance, hWndMain, lpCmdLine, "GUI Simulation");
  SIM_GUI_CreateLCDWindow(hWndMain, 0, 0, 480, 272, 0);
  /* Create a thread which executes the code to be simulated */
  ShowWindow(hWndMain, nCmdShow);
  CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)_Thread, NULL, 0, &ThreadID);
  /* Main message loop */
  while (GetMessage(&Msg, NULL, 0, 0)) {
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
  }
  SIM_GUI_Exit();
}

/*************************** End of file ****************************/
