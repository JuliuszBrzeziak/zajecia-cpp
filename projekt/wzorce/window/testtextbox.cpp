#include <windows.h>
#include <tchar.h>
#include "hfclass.hpp"
#include "bitmap_image.hpp"

void AddMenus(HWND);



//nazwa klasy, dzieki temu kompilator nie płacze
char nazwa[] = "Klasa Okienka";

//tworzenie struktury
LPSTR NazwaKlasy = nazwa;

//tutaj będą przechowywane komunikaty
MSG Komunikat;

//prototyp WndProc
LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );

//uchwyty
HWND textfield,button,textbox;
//tablica znaków do odczytywania
char textsaved[20];

int WINAPI WinMain(/*uchwyt*/ HINSTANCE hInstance, /*uchwyt poprzeedniego wystąpienia aplikacji*/HINSTANCE hPrevInstance,
/*linia poleceń*/ LPSTR lpCmdLine,/*stan okna*/ int nCmdShow )
{


    WNDCLASSEX wc;

    //rozmiar struktury
    wc.cbSize = sizeof(WNDCLASSEX);
    //style klasy (!= style okna)
    wc.style = CS_HREDRAW | CS_VREDRAW;
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
    wc.lpszClassName =  NazwaKlasy;
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
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE, 
        NazwaKlasy, 
        _T("C++ projekt"),
        WS_OVERLAPPEDWINDOW, 
        CW_USEDEFAULT, 
        CW_USEDEFAULT, 
        550 ,550, 
        NULL, NULL, 
        hInstance, 
        NULL );

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


    case WM_CREATE:
        textbox = CreateWindow(
            "EDIT",
            "",
            WS_BORDER|WS_CHILD|WS_VISIBLE,
            20,45,
            200,20,
            hwnd,
            NULL,NULL,NULL
        );
        textfield = CreateWindow("STATIC",
        "Ile iteracji",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        20,20,//położenie
        100,20,// wielkość
        hwnd,
        NULL,NULL,NULL);


        CreateWindow("BUTTON",
        "binarny ciag naturalnych",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        20,70,//położenie
        200,20,//wielkość
        hwnd,//hak
        (HMENU) 1, //argument
        NULL,
        NULL);

        CreateWindow("BUTTON",
        "binarny ciag fibonacciego",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        20,95,
        200,20,
        hwnd,
        (HMENU) 2,
        NULL,
        NULL);


        CreateWindow("BUTTON",
        "binarny ciag jacobsthala",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        20,120,//położenie
        200,20,//wielkość
        hwnd,//hak
        (HMENU) 3, //argument
        NULL,
        NULL);

        CreateWindow("BUTTON",
        "binarny ciag Leonardo",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        20,145,//położenie
        200,20,//wielkość
        hwnd,//hak
        (HMENU) 4, //argument
        NULL,
        NULL);


        CreateWindow("BUTTON",
        "binarny c jacobsthal-lucasa",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        20,170,//położenie
        200,20,//wielkość
        hwnd,//hak
        (HMENU) 5, //argument
        NULL,
        NULL);

        CreateWindow("BUTTON",
        "binarny ciag Lucasa",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        20,195,//położenie
        200,20,//wielkość
        hwnd,//hak
        (HMENU) 6, //argument
        NULL,
        NULL);


        CreateWindow("BUTTON",
        "binarny ciag Padovana",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        20,220,//położenie
        200,20,//wielkość
        hwnd,//hak
        (HMENU) 7, //argument
        NULL,
        NULL);

        CreateWindow("BUTTON",
        "binarny ciag Perrina",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        20,245,//położenie
        200,20,//wielkość
        hwnd,//hak
        (HMENU) 8, //argument
        NULL,
        NULL);


        CreateWindow("BUTTON",
        "binarny ciag Pella",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        20,270,//położenie
        200,20,//wielkość
        hwnd,//hak
        (HMENU) 9, //argument
        NULL,
        NULL);

        CreateWindow("BUTTON",
        "binarny ciag silni",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        20,295,//położenie
        200,20,//wielkość
        hwnd,//hak
        (HMENU) 10, //argument
        NULL,
        NULL);


        CreateWindow("BUTTON",
        "parzystosc pascal",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        20,320,//położenie
        200,20,//wielkość
        hwnd,//hak
        (HMENU) 11, //argument
        NULL,
        NULL);

        CreateWindow("BUTTON",
        "parzystosc pascal(2,1)",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        20,345,//położenie
        200,20,//wielkość
        hwnd,//hak
        (HMENU) 12, //argument
        NULL,
        NULL);

        AddMenus(hwnd);


        break;
    //reakcja na czerwony krzyżyk
    case WM_CLOSE:
        DestroyWindow( hwnd ); //niszczy okienko
        break;

    case WM_COMMAND:
        switch (LOWORD(wParam)) //Tutaj wybiera się parametr przekazywany przez guziki
        {

        case 13:{
            MessageBox(hwnd,
            "generuje bitmape kolejnych wartosci ciagu w postaci binarnej",
            "binarne info",MB_OK); // wyświetla go
            break;
        }

        case 14:{
            MessageBox(hwnd,
            "generuje bitmape w ktorej kazdy piksel odpowiada parzystosci danej liczby, kropka to nieparzyste",
            "parzystosc info",MB_OK); // wyświetla go
            break;
        }

        case 15:{
            MessageBox(hwnd,
            "Juliusz Brzeziak\nC++ projekt zaliczeniowy\nCzerwiec 2019",
            "Autor",MB_OK); // wyświetla go
            break;
        }

        case 12:{
            int gwstat = 0; //tutaj będzie zapisana długość wpisanego stringa
            gwstat = GetWindowText(textbox,&textsaved[0],20);//wkłada tekst do tablicy 

            //tworzy obiekt klasy tablica
            Tablica tbl;

            int nt = std::stoi(textsaved);//zamienia tą tablicę w inta
            int k = nt; //ilość iteracji
            const int canvas_width  = nt;//ustalenie szerokości mapy
            const int canvas_height = nt;//ustalenie wysokości
            const double width = -nt/2; //współrzędna szerokości początkowego punktu
            const double height = nt/2; //współrzędna wyskokości początkowego punktu
            
            //wywołuje odpowiednia metode
            tbl.pascal21(k);
            
            //generuje wektor parzystości
            tbl.crtpstr();
            
            //tworzy kanwę
            cartesian_canvas canvas(canvas_width,canvas_height);

            //tworzy kanwę
            struct point_t { double x,y; };
            point_t pnt = {width, height };

            //pętla dla wysokości
            for(int i = 0; i <= k;i++){
                //pętla dla szerokości
                for(int j = 0; j<=i; j++ ){
                    //testuje czy w stringu jest 1, jeśli tak to rysuje bit
                    if(1==tbl.test(i,j)){
                        canvas.plot_pixel(pnt.x + j,pnt.y - i);
                    }
                }      
            }
            
            //Zapisuje bmp
            canvas.image().save_image("pascal21.bmp");

            //komunikuje zakończenie
            MessageBox(hwnd,textsaved,"OK",MB_OK); // wyświetla go
            break;
        }

        case 1:{
            int gwstat = 0; //tutaj będzie zapisana długość wpisanego stringa
            gwstat = GetWindowText(textbox,&textsaved[0],20);//wkłada tekst do tablicy 

            //tworzy obiekt klasy tablica
            Liczba tbl;

            int nt = std::stoi(textsaved);//zamienia tą tablicę w inta
            int k = nt; //ilość iteracji
            const int canvas_width  = nt;//ustalenie szerokości mapy
            const int canvas_height = nt;//ustalenie wysokości
            const double width = -nt/2; //współrzędna szerokości początkowego punktu
            const double height = nt/2; //współrzędna wyskokości początkowego punktu
            //wywołuje odpowiednia metode
            tbl.nat_str(k);

     
            //tworzy kanwę
            cartesian_canvas canvas(canvas_width,canvas_height);
            

            //tworzy kanwę
            struct point_t { double x,y; };
            point_t pnt = {width, height };

            
            //pętla dla wysokości
            for(int i = 0; i < k;i++){
                //pętla dla szerokości
                for(int j = 0; j<=i; j++ ){

                    //std::cout << "elo" << tbl.str[0][510] <<std::endl;
                    
                    //testuje czy w stringu jest 1, jeśli tak to rysuje bit
                    if(1==tbl.test(i,511-j)){
                        
                        canvas.plot_pixel(pnt.x + j,pnt.y - i);
                        //std::cout << "elo" << std::endl;
                    }
                }      
            }
            
            //Zapisuje bmp
            canvas.image().save_image("nat.bmp");

            //komunikuje zakończenie
            MessageBox(hwnd,textsaved,"OK",MB_OK); // wyświetla go
            break;
        }


        case 2:{
            int gwstat = 0; //tutaj będzie zapisana długość wpisanego stringa
            gwstat = GetWindowText(textbox,&textsaved[0],20);//wkłada tekst do tablicy 

            //tworzy obiekt klasy tablica
            Liczba tbl;

            int nt = std::stoi(textsaved);//zamienia tą tablicę w inta
            int k = nt; //ilość iteracji
            const int canvas_width  = nt;//ustalenie szerokości mapy
            const int canvas_height = nt;//ustalenie wysokości
            const double width = -nt/2; //współrzędna szerokości początkowego punktu
            const double height = nt/2; //współrzędna wyskokości początkowego punktu
            //wywołuje odpowiednia metode
            tbl.fib_str(k);
            
            
            //tworzy kanwę
            cartesian_canvas canvas(canvas_width,canvas_height);
            

            //tworzy kanwę
            struct point_t { double x,y; };
            point_t pnt = {width, height };

            
            //pętla dla wysokości
            for(int i = 0; i < k;i++){
                //pętla dla szerokości
                for(int j = 0; j<=i; j++ ){

                    //std::cout << "elo" << tbl.str[0][510] <<std::endl;
                    
                    //testuje czy w stringu jest 1, jeśli tak to rysuje bit
                    if(1==tbl.test(i,511-j)){
                        
                        canvas.plot_pixel(pnt.x + j,pnt.y - i);
                        //std::cout << "elo" << std::endl;
                    }
                }      
            }
            
            //Zapisuje bmp
            canvas.image().save_image("fib.bmp");

            //komunikuje zakończenie
            MessageBox(hwnd,textsaved,"OK",MB_OK); // wyświetla go
            break;
        }


        case 3:{
            int gwstat = 0; //tutaj będzie zapisana długość wpisanego stringa
            gwstat = GetWindowText(textbox,&textsaved[0],20);//wkłada tekst do tablicy 

            //tworzy obiekt klasy tablica
            Liczba tbl;

            int nt = std::stoi(textsaved);//zamienia tą tablicę w inta
            int k = nt; //ilość iteracji
            const int canvas_width  = nt;//ustalenie szerokości mapy
            const int canvas_height = nt;//ustalenie wysokości
            const double width = -nt/2; //współrzędna szerokości początkowego punktu
            const double height = nt/2; //współrzędna wyskokości początkowego punktu
            //wywołuje odpowiednia metode
            tbl.jac_str(k);
            
            //tworzy kanwę
            cartesian_canvas canvas(canvas_width,canvas_height);
            

            //tworzy kanwę
            struct point_t { double x,y; };
            point_t pnt = {width, height };

            
            //pętla dla wysokości
            for(int i = 0; i < k;i++){
                //pętla dla szerokości
                for(int j = 0; j<=i; j++ ){

                    //std::cout << "elo" << tbl.str[0][510] <<std::endl;
                    
                    //testuje czy w stringu jest 1, jeśli tak to rysuje bit
                    if(1==tbl.test(i,511-j)){
                        
                        canvas.plot_pixel(pnt.x + j,pnt.y - i);
                        //std::cout << "elo" << std::endl;
                    }
                }      
            }
            
            //Zapisuje bmp
            canvas.image().save_image("jac.bmp");

            //komunikuje zakończenie
            MessageBox(hwnd,textsaved,"OK",MB_OK); // wyświetla go
            break;
        }



        case 4:{
            int gwstat = 0; //tutaj będzie zapisana długość wpisanego stringa
            gwstat = GetWindowText(textbox,&textsaved[0],20);//wkłada tekst do tablicy 

            //tworzy obiekt klasy tablica
            Liczba tbl;

            int nt = std::stoi(textsaved);//zamienia tą tablicę w inta
            int k = nt; //ilość iteracji
            const int canvas_width  = nt;//ustalenie szerokości mapy
            const int canvas_height = nt;//ustalenie wysokości
            const double width = -nt/2; //współrzędna szerokości początkowego punktu
            const double height = nt/2; //współrzędna wyskokości początkowego punktu
            //wywołuje odpowiednia metode
            tbl.leo_str(k);
            
            
            //tworzy kanwę
            cartesian_canvas canvas(canvas_width,canvas_height);
            

            //tworzy kanwę
            struct point_t { double x,y; };
            point_t pnt = {width, height };

            
            //pętla dla wysokości
            for(int i = 0; i < k;i++){
                //pętla dla szerokości
                for(int j = 0; j<=i; j++ ){

                    //std::cout << "elo" << tbl.str[0][510] <<std::endl;
                    
                    //testuje czy w stringu jest 1, jeśli tak to rysuje bit
                    if(1==tbl.test(i,511-j)){
                        
                        canvas.plot_pixel(pnt.x + j,pnt.y - i);
                        //std::cout << "elo" << std::endl;
                    }
                }      
            }
            
            //Zapisuje bmp
            canvas.image().save_image("leo.bmp");

            //komunikuje zakończenie
            MessageBox(hwnd,textsaved,"OK",MB_OK); // wyświetla go
            break;
        }




        case 5:{
            int gwstat = 0; //tutaj będzie zapisana długość wpisanego stringa
            gwstat = GetWindowText(textbox,&textsaved[0],20);//wkłada tekst do tablicy 

            //tworzy obiekt klasy tablica
            Liczba tbl;

            int nt = std::stoi(textsaved);//zamienia tą tablicę w inta
            int k = nt; //ilość iteracji
            const int canvas_width  = nt;//ustalenie szerokości mapy
            const int canvas_height = nt;//ustalenie wysokości
            const double width = -nt/2; //współrzędna szerokości początkowego punktu
            const double height = nt/2; //współrzędna wyskokości początkowego punktu
            //wywołuje odpowiednia metode
            tbl.jacluc_str(k);
            
            
            //tworzy kanwę
            cartesian_canvas canvas(canvas_width,canvas_height);
            

            //tworzy kanwę
            struct point_t { double x,y; };
            point_t pnt = {width, height };

            
            //pętla dla wysokości
            for(int i = 0; i < k;i++){
                //pętla dla szerokości
                for(int j = 0; j<=i; j++ ){

                    //std::cout << "elo" << tbl.str[0][510] <<std::endl;
                    
                    //testuje czy w stringu jest 1, jeśli tak to rysuje bit
                    if(1==tbl.test(i,511-j)){
                        
                        canvas.plot_pixel(pnt.x + j,pnt.y - i);
                        //std::cout << "elo" << std::endl;
                    }
                }      
            }
            
            //Zapisuje bmp
            canvas.image().save_image("jacluc.bmp");

            //komunikuje zakończenie
            MessageBox(hwnd,textsaved,"OK",MB_OK); // wyświetla go
            break;
        }

        

        case 6:{
            int gwstat = 0; //tutaj będzie zapisana długość wpisanego stringa
            gwstat = GetWindowText(textbox,&textsaved[0],20);//wkłada tekst do tablicy 

            //tworzy obiekt klasy tablica
            Liczba tbl;

            int nt = std::stoi(textsaved);//zamienia tą tablicę w inta
            int k = nt; //ilość iteracji
            const int canvas_width  = nt;//ustalenie szerokości mapy
            const int canvas_height = nt;//ustalenie wysokości
            const double width = -nt/2; //współrzędna szerokości początkowego punktu
            const double height = nt/2; //współrzędna wyskokości początkowego punktu
            //wywołuje odpowiednia metode
            tbl.luc_str(k);
            
            
            //tworzy kanwę
            cartesian_canvas canvas(canvas_width,canvas_height);
            

            //tworzy kanwę
            struct point_t { double x,y; };
            point_t pnt = {width, height };

            
            //pętla dla wysokości
            for(int i = 0; i < k;i++){
                //pętla dla szerokości
                for(int j = 0; j<=i; j++ ){

                    //std::cout << "elo" << tbl.str[0][510] <<std::endl;
                    
                    //testuje czy w stringu jest 1, jeśli tak to rysuje bit
                    if(1==tbl.test(i,511-j)){
                        
                        canvas.plot_pixel(pnt.x + j,pnt.y - i);
                        //std::cout << "elo" << std::endl;
                    }
                }      
            }
            
            //Zapisuje bmp
            canvas.image().save_image("luc.bmp");

            //komunikuje zakończenie
            MessageBox(hwnd,textsaved,"OK",MB_OK); // wyświetla go
            break;
        }



        case 7:{
            int gwstat = 0; //tutaj będzie zapisana długość wpisanego stringa
            gwstat = GetWindowText(textbox,&textsaved[0],20);//wkłada tekst do tablicy 

            //tworzy obiekt klasy tablica
            Liczba tbl;

            int nt = std::stoi(textsaved);//zamienia tą tablicę w inta
            int k = nt; //ilość iteracji
            const int canvas_width  = nt;//ustalenie szerokości mapy
            const int canvas_height = nt;//ustalenie wysokości
            const double width = -nt/2; //współrzędna szerokości początkowego punktu
            const double height = nt/2; //współrzędna wyskokości początkowego punktu
            //wywołuje odpowiednia metode
            tbl.pad_str(k);
            
            
            //tworzy kanwę
            cartesian_canvas canvas(canvas_width,canvas_height);
            

            //tworzy kanwę
            struct point_t { double x,y; };
            point_t pnt = {width, height };

            
            //pętla dla wysokości
            for(int i = 0; i < k;i++){
                //pętla dla szerokości
                for(int j = 0; j<=i; j++ ){

                    //std::cout << "elo" << tbl.str[0][510] <<std::endl;
                    
                    //testuje czy w stringu jest 1, jeśli tak to rysuje bit
                    if(1==tbl.test(i,511-j)){
                        
                        canvas.plot_pixel(pnt.x + j,pnt.y - i);
                        //std::cout << "elo" << std::endl;
                    }
                }      
            }
            
            //Zapisuje bmp
            canvas.image().save_image("pad.bmp");

            //komunikuje zakończenie
            MessageBox(hwnd,textsaved,"OK",MB_OK); // wyświetla go
            break;
        }



        case 8:{
            int gwstat = 0; //tutaj będzie zapisana długość wpisanego stringa
            gwstat = GetWindowText(textbox,&textsaved[0],20);//wkłada tekst do tablicy 

            //tworzy obiekt klasy tablica
            Liczba tbl;

            int nt = std::stoi(textsaved);//zamienia tą tablicę w inta
            int k = nt; //ilość iteracji
            const int canvas_width  = nt;//ustalenie szerokości mapy
            const int canvas_height = nt;//ustalenie wysokości
            const double width = -nt/2; //współrzędna szerokości początkowego punktu
            const double height = nt/2; //współrzędna wyskokości początkowego punktu
            //wywołuje odpowiednia metode
            tbl.per_str(k);
            
            
            //tworzy kanwę
            cartesian_canvas canvas(canvas_width,canvas_height);
            

            //tworzy kanwę
            struct point_t { double x,y; };
            point_t pnt = {width, height };

            
            //pętla dla wysokości
            for(int i = 0; i < k;i++){
                //pętla dla szerokości
                for(int j = 0; j<=i; j++ ){

                    //std::cout << "elo" << tbl.str[0][510] <<std::endl;
                    
                    //testuje czy w stringu jest 1, jeśli tak to rysuje bit
                    if(1==tbl.test(i,511-j)){
                        
                        canvas.plot_pixel(pnt.x + j,pnt.y - i);
                        //std::cout << "elo" << std::endl;
                    }
                }      
            }
            
            //Zapisuje bmp
            canvas.image().save_image("perrin.bmp");

            //komunikuje zakończenie
            MessageBox(hwnd,textsaved,"OK",MB_OK); // wyświetla go
            break;
        }



        case 9:{
            int gwstat = 0; //tutaj będzie zapisana długość wpisanego stringa
            gwstat = GetWindowText(textbox,&textsaved[0],20);//wkłada tekst do tablicy 

            //tworzy obiekt klasy tablica
            Liczba tbl;

            int nt = std::stoi(textsaved);//zamienia tą tablicę w inta
            int k = nt; //ilość iteracji
            const int canvas_width  = nt;//ustalenie szerokości mapy
            const int canvas_height = nt;//ustalenie wysokości
            const double width = -nt/2; //współrzędna szerokości początkowego punktu
            const double height = nt/2; //współrzędna wyskokości początkowego punktu
            //wywołuje odpowiednia metode
            tbl.pell_vstr(k);
            
            
            //tworzy kanwę
            cartesian_canvas canvas(canvas_width,canvas_height);
            

            //tworzy kanwę
            struct point_t { double x,y; };
            point_t pnt = {width, height };

            
            //pętla dla wysokości
            for(int i = 0; i < k;i++){
                //pętla dla szerokości
                for(int j = 0; j<=i; j++ ){

                    //std::cout << "elo" << tbl.str[0][510] <<std::endl;
                    
                    //testuje czy w stringu jest 1, jeśli tak to rysuje bit
                    if(1==tbl.test(i,511-j)){
                        
                        canvas.plot_pixel(pnt.x + j,pnt.y - i);
                        //std::cout << "elo" << std::endl;
                    }
                }      
            }
            
            //Zapisuje bmp
            canvas.image().save_image("pell.bmp");

            //komunikuje zakończenie
            MessageBox(hwnd,textsaved,"OK",MB_OK); // wyświetla go
            break;
        }



        case 10:{
            int gwstat = 0; //tutaj będzie zapisana długość wpisanego stringa
            gwstat = GetWindowText(textbox,&textsaved[0],20);//wkłada tekst do tablicy 

            //tworzy obiekt klasy tablica
            Liczba tbl;

            int nt = std::stoi(textsaved);//zamienia tą tablicę w inta
            int k = nt; //ilość iteracji
            const int canvas_width  = nt;//ustalenie szerokości mapy
            const int canvas_height = nt;//ustalenie wysokości
            const double width = -512/2; //współrzędna szerokości początkowego punktu
            const double height = nt/2; //współrzędna wyskokości początkowego punktu
            //wywołuje odpowiednia metode
            tbl.sil_str(k);
            
            
            //tworzy kanwę
            cartesian_canvas canvas(512,canvas_height);
            

            //tworzy kanwę
            struct point_t { double x,y; };
            point_t pnt = {width, height };

            
            //pętla dla wysokości
            for(int i = 0; i < k;i++){
                //pętla dla szerokości
                for(int j = 0; j<=511; j++ ){

                    //std::cout << "elo" << tbl.str[0][510] <<std::endl;
                    
                    //testuje czy w stringu jest 1, jeśli tak to rysuje bit
                    if(1==tbl.test(i,511-j)){
                        
                        canvas.plot_pixel(pnt.x + j,pnt.y - i);
                        //std::cout << "elo" << std::endl;
                    }
                }      
            }
            
            //Zapisuje bmp
            canvas.image().save_image("sil.bmp");

            //komunikuje zakończenie
            MessageBox(hwnd,textsaved,"OK",MB_OK); // wyświetla go
            break;
        }

        case 11:{
            int gwstat = 0; //tutaj będzie zapisana długość wpisanego stringa
            gwstat = GetWindowText(textbox,&textsaved[0],20);//wkłada tekst do tablicy 

            //tworzy obiekt klasy tablica
            Tablica tbl;

            int nt = std::stoi(textsaved);//zamienia tą tablicę w inta
            int k = nt; //ilość iteracji
            const int canvas_width  = nt;//ustalenie szerokości mapy
            const int canvas_height = nt;//ustalenie wysokości
            const double width = -nt/2; //współrzędna szerokości początkowego punktu
            const double height = nt/2; //współrzędna wyskokości początkowego punktu
            
            //wywołuje odpowiednia metode
            tbl.pascaal(k);
            
            //generuje wektor parzystości
            tbl.crtpstr();
            
            //tworzy kanwę
            cartesian_canvas canvas(canvas_width,canvas_height);

            //tworzy kanwę
            struct point_t { double x,y; };
            point_t pnt = {width, height };

            //pętla dla wysokości
            for(int i = 0; i <= k;i++){
                //pętla dla szerokości
                for(int j = 0; j<=i; j++ ){
                    //testuje czy w stringu jest 1, jeśli tak to rysuje bit
                    if(1==tbl.test(i,j)){
                        canvas.plot_pixel(pnt.x + j,pnt.y - i);
                    }
                }      
            }
            
            //Zapisuje bmp
            canvas.image().save_image("pascal.bmp");

            //komunikuje zakończenie
            MessageBox(hwnd,textsaved,"OK",MB_OK); // wyświetla go
            break;
        }


        case 99:{
            int gwstat = 0;
            gwstat = GetWindowText(textbox,&textsaved[0],20);//wkłada tekst do tablicy 
            MessageBox(hwnd,textsaved,"hellooooo",MB_OK); // wyświetla go
            break;
        }
        default:
            break;
        }


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

void AddMenus(HWND hwnd) {

    HMENU hMenubar;
    HMENU hMenu;

    hMenubar = CreateMenu();
    hMenu = CreateMenu();

    AppendMenuW(hMenu, MF_STRING, 13, L"&Binarne...");
    AppendMenuW(hMenu, MF_STRING, 14, L"&Parzystosc...");
    AppendMenuW(hMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuW(hMenu, MF_STRING, 15, L"&Autor");

    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu, L"&Info");
    SetMenu(hwnd, hMenubar);
}