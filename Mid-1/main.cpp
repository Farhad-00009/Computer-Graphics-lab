#include <windows.h>

#include <cmath>

#define ROUND(a) ((int) (a + 0.5))

/* set window handle */

static HWND sHwnd;

static COLORREF redColor=RGB(255,0,0);

static COLORREF blueColor=RGB(0,0,255);

static COLORREF greenColor=RGB(0,255,0);


void SetWindowHandle(HWND hwnd) {

    sHwnd=hwnd;

}

/* SetPixel */

void setPixel(int x,int y,COLORREF& color=redColor) {

    if(sHwnd==NULL) {

        MessageBox(NULL,"sHwnd was not initialized !","Error",MB_OK|MB_ICONERROR);

        exit(0);

    }

    HDC hdc=GetDC(sHwnd);

    SetPixel(hdc,x,y,color);

    ReleaseDC(sHwnd,hdc);

    return;

// NEVERREACH //

}


void drawLineDDA(int xa, int ya, int xb, int yb) {

    int dx = xb - xa, dy = yb - ya, steps, k;

    float xIncrement, yIncrement, x = xa, y = ya;

    if(abs(dx) > abs(dy)) steps = abs(dx);

    else steps = abs(dy);

    xIncrement = dx / (float) steps;

    yIncrement = dy / (float) steps;

    setPixel(ROUND(x), ROUND(y));

    for(int k = 0; k < steps; k++) {

        x += xIncrement;

        y += yIncrement;

        setPixel(x, y);

    }

}

/* Window Procedure WndProc */

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam) {

    switch(message) {

    case WM_PAINT:

        SetWindowHandle(hwnd);
        /* /__ */











                                          drawLineDDA(339,93,640,93);

                                          drawLineDDA(339,93,274,145);

                                          drawLineDDA(640,93,739,139);

                                          drawLineDDA(274,145,739,139);





                                          drawLineDDA(311,147,311,460);

                                          drawLineDDA(324,147,326,460);

                                          drawLineDDA(310,155,673,155);
                                          drawLineDDA(659,143,659,476);

                                          drawLineDDA(674,143,674,471);


                                          drawLineDDA(310,460,674,474);

                                          drawLineDDA(310,238,674,238);

                                          drawLineDDA(311,255,674,255);


                                          drawLineDDA(310,360,673,366);

                                          drawLineDDA(311,374,675,379);



                                          drawLineDDA(340,177,414,177);
                                          drawLineDDA(417,177,414,209);
                                          drawLineDDA(414,209,340,209);
                                          drawLineDDA(340,209,340,177);


                                          drawLineDDA(339,191,414,191);
                                          drawLineDDA(378,177,379,207);


                                          drawLineDDA(450,177,508,177);
                                          drawLineDDA(508,177,507,208);
                                          drawLineDDA(507,208,448,208);
                                          drawLineDDA(448,208,450,177);
                                          drawLineDDA(450,191,507,191);
                                          drawLineDDA(476,177,477,207);



                                          drawLineDDA(551,178,619,178);
                                          drawLineDDA(619,178,618,204);

                                          drawLineDDA(618,204,551,204);
                                          drawLineDDA(551,204,551,178);
                                          drawLineDDA(582,204,582,179);
                                          drawLineDDA(551,194,618,194);












                                          drawLineDDA(345,282,399,281);

                                          drawLineDDA(399,281,401,316);
                                          drawLineDDA(401,316,346,316);

                                          drawLineDDA(346,316,346,281);
                                          drawLineDDA(373,281,372,317);

                                          drawLineDDA(346,296,401,296);





                                          drawLineDDA(438,281,499,281);
                                          drawLineDDA(499,281,498,314);
                                          drawLineDDA(440,314,440,314);

                                          drawLineDDA(440,314,440,281);

                                          drawLineDDA(440,300,500,301);
                                          drawLineDDA(464,282,464,314);






                                          drawLineDDA(548,286,608,286);
                                          drawLineDDA(608,286,608,312);


                                          drawLineDDA(608,312,548,314);

                                          drawLineDDA(548,319,548,268);

                                          drawLineDDA(548,301,607,301);
                                          drawLineDDA(576,285,576,314);




                                          drawLineDDA(349,409,423,409);
































////////////////////////////////////////////


























































        break;

    case WM_CLOSE: // FAIL THROUGH to call DefWindowProc

        break;

    case WM_DESTROY:

        PostQuitMessage(0);

        return 0;

    default:

        break; // FAIL to call DefWindowProc //

    }

    return DefWindowProc(hwnd,message,wParam,lParam);

}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int iCmdShow) {

    static TCHAR szAppName[] = TEXT("Straight Line");

    WNDCLASS wndclass;

    wndclass.style         = CS_HREDRAW|CS_VREDRAW ;

    wndclass.lpfnWndProc   = WndProc ;

    wndclass.cbClsExtra    = 0 ;

    wndclass.cbWndExtra    = 0 ;

    wndclass.hInstance     = hInstance ;

    wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;

    wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;

    wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;

    wndclass.lpszMenuName  = NULL ;

    wndclass.lpszClassName = szAppName ;

// Register the window //

    if(!RegisterClass(&wndclass)) {

        MessageBox(NULL,"Registering the class failled","Error",MB_OK|MB_ICONERROR);

        exit(0);

    }

// CreateWindow //

    HWND hwnd=CreateWindow(szAppName,"DDA - Programming Techniques",

                           WS_OVERLAPPEDWINDOW,

                           CW_USEDEFAULT,

                           CW_USEDEFAULT,

                           CW_USEDEFAULT,

                           CW_USEDEFAULT,

                           NULL,

                           NULL,

                           hInstance,

                           NULL);

    if(!hwnd) {

        MessageBox(NULL,"Window Creation Failed!","Error",MB_OK);

        exit(0);

    }

// ShowWindow and UpdateWindow //

    ShowWindow(hwnd,iCmdShow);

    UpdateWindow(hwnd);

// Message Loop //

    MSG msg;

    while(GetMessage(&msg,NULL,0,0)) {

        TranslateMessage(&msg);

        DispatchMessage(&msg);

    }

    /* return no error to the operating system */

    return 0;

}
