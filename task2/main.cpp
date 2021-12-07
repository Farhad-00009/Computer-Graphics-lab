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








                                        drawLineDDA(894,80,1106,80);
                                        drawLineDDA(894,80,895,245);
                                        drawLineDDA(894,246,1107,245);
                                        drawLineDDA(1107,245,1106,80);

                                          drawLineDDA(841,170,1002,43);


                                            drawLineDDA(841,170,1003,298);

                                            drawLineDDA(1003,298,1161,171);

                                            drawLineDDA(1161,171,1002,44);






                                            drawLineDDA(146,140,190,262);
                                        drawLineDDA(190,262,334,262);
                                        drawLineDDA(334,262,378,140);
                                        drawLineDDA(378,140,262,63);
                                          drawLineDDA(146,140,262,63);





                                          drawLineDDA(204,145,243,145);
                                          drawLineDDA(204,145,223,169);
                                          drawLineDDA(223,169,206,194);
                                          drawLineDDA(206,194,243,195);
                                          drawLineDDA(243,195,264,219);
                                          drawLineDDA(264,219,284,194);
                                          drawLineDDA(284,194,320,195);
                                          drawLineDDA(320,195,302,170);
                                          drawLineDDA(302,170,319,146);
                                          drawLineDDA(319,146,283,146);
                                          drawLineDDA(283,146,262,121);
                                          drawLineDDA(262,121,243,144);



                                          drawLineDDA(234,174,257,170);
                                          drawLineDDA(257,170,260,150);
                                          drawLineDDA(260,150,265,170);
                                          drawLineDDA(265,170,284,173);
                                          drawLineDDA(284,173,266,178);
                                          drawLineDDA(266,178,262,193);
                                          drawLineDDA(262,193,256,178);
                                          drawLineDDA(256,178,234,174);




                                           drawLineDDA(492,80,758,81);
                                          drawLineDDA(492,80,492,260);
                                          drawLineDDA(492,260,759,260);
                                          drawLineDDA(759,260,758,81);


                                          drawLineDDA(509,103,743,103);
                                          drawLineDDA(509,103,509,238);
                                          drawLineDDA(509,238,743,238);
                                          drawLineDDA(743,238,743,103);



                                          drawLineDDA(618,106,574,146);
                                          drawLineDDA(618,106,653,145);
                                          drawLineDDA(574,146,572,202);
                                          drawLineDDA(653,143,653,200);


                                          drawLineDDA(653,200,621,239);
                                          drawLineDDA(621,239,575,205);


















































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
