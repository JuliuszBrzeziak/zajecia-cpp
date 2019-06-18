#include <windows.h>
#include <tchar.h>

//nazwa klasy, dzieki temu kompilator nie płacze
char nazwa[] = "Klasa Okienka";

//tworzenie struktury
LPSTR NazwaKlasy = nazwa;

//tutaj będą przechowywane komunikaty
MSG Komunikat;

//prototyp WndProc
LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );


int WINAPI WinMain(/*uchwyt*/ HINSTANCE hInstance, /*uchwyt poprzeedniego wystąpienia aplikacji*/HINSTANCE hPrevInstance,
/*linia poleceń*/ LPSTR lpCmdLine,/*stan okna*/ int nCmdShow )
{


    WNDCLASSEX wc;

    //rozmiar struktury
    wc.cbSize = sizeof(WNDCLASSEX);
    //style klasy (!= style okna)
    wc.style = 0;
    //wskaźnik procedury obs. okno
    wc.lpfnWndProc = WndProc;
    //tytuł okienkca
    //wc.lpszWindowName = "tytul";
    //dodatkowe bajty dla klasy, domyślnie 0
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    //Id apki która jest właścicielem okna, zazw. pierwszy par WinMain
    wc.hInstance = hInstance;
    //ikona okna
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    //tło zwykłe szare tło
    wc.hbrBackground =( HBRUSH )( COLOR_WINDOW + 1 );
    //kursor
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    //nazwa id menu okna zasobów
    wc.lpszMenuName = NULL;
    //nazwa klasy
    wc.lpszClassName = NazwaKlasy;
    //mała ikonka
    wc.hIconSm = LoadIcon( NULL, IDI_APPLICATION );


    //sprawdza czy się udało
    if(!RegisterClassEx(&wc)/*zwraca niezerową wartosc if udasie*/){
        MessageBox(NULL,_T("ok"),_T("nok"),MB_OK);
        return 1;
    }

    //budowanie okna
    //CreateWindowEx( dwExStyle, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam )
    //dwExStyle - parametry stylu okna WS_EX_WINDOWEDGE
    //lpClassName nazwa klasy okna
    //lpWindowName pasek tytułowy okna
    //dwStyle style okienka
    //x, y	pozycja okna, domyślna CW_USERDEFAULT
    //nWidth szerokość okna
    //nHeight wysokość
    //hWndParent uchwyt okna rodzica, może być NULL
    //hMenu uchwyt menu tego okna, jeśli nie ma NULL
    //hInstance uchwyt aplikacji może być hInstance
    //IpParam dodatkowe parametry, domyślnie NULL

    //towrzymy okno
    HWND  hwnd;

    //to będzie nasze okno
    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, NazwaKlasy, _T("Oto okienko"),
WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 240 ,120, NULL, NULL, hInstance, NULL );

    //obsulga bledu
    if(hwnd == NULL)
    {
        MessageBox(NULL,_T("okno error"),_T("okno error"),MB_YESNO);
        return 2;
    }


    //showWindow pokazuje okno
    ShowWindow(hwnd,nCmdShow); //nCmdShow to parametr z WinMain
    UpdateWindow(hwnd);

    // Pętla komunikatów
    //GetMessage pobiera wiadomości
    //TranslateMessage tłumaczy nasze wiadomości
    //DispatchMessage wysyła komunikat do właściwego okna 
    while( GetMessage( & Komunikat, NULL, 0, 0 ) )
    {
        TranslateMessage( & Komunikat );
        DispatchMessage( & Komunikat );
    }
    return Komunikat.wParam;
}

//obsluga komunikatów
LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
    //reakcja na czerwony krzyżyk
    case WM_CLOSE:
        DestroyWindow( hwnd ); //niszczy okienko
        break;

    // 
    case WM_DESTROY:
        PostQuitMessage( 0 ); //komunikat zakończenia aplikacji
        break;
        
        default:
        return DefWindowProc( hwnd, msg, wParam, lParam );
    }
    
    return 0;
}