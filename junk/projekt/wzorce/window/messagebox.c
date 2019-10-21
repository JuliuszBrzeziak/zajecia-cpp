#include <windows.h>

int WINAPI WinMain(/*uchwyt*/ HINSTANCE hInstance, /*uchwyt poprzeedniego wystąpienia aplikacji*/HINSTANCE hPrevInstance,
/*linia poleceń*/ LPSTR lpCmdLine,/*stan okna*/ int nCmdShow )
{
    //rzuca komunikat
    //MessageBox( hWnd, lpText, lpCaption, uType )
    //hWnd to uchwyt okna z którego wyrzuca komunikat, NULL to bezpański kominukat
    //lpText to tekst który wyświetlimy lp i p to zazwyczaj wskaźniki
    //lpCaption to tytuł okna, dając NULL dostaniemy domyślny error
    //uType style oknienka


    //uType
    //Aby dodać kilka styli dodajemy między nimi |
    //MB_ABORTRETRYIGNORE	przyciski Abort, Retry i Ignore (w polskiej wersji systemu będą oczywiście miały inne nazwy)
    //MB_OK	tylko przycisk OK
    //MB_OKCANCEL	przyciski OK i Anuluj
    //MB_RETRYCANCEL	przyciski Ponów i Anuluj
    //MB_YESNO	przyciski Tak i Nie
    //MB_YESNOCANCEL	przyciski Tak, Nie i Anuluj
    //ikony
    //MB_ICONEXCLAMATION lub MB_ICONWARNING	wykrzyknik
    //MB_ICONINFORMATION, MB_ICONASTERISK	literka 'i' w kółeczku (informacja)
    //MB_ICONQUESTION	znak zapytania
    //MB_ICONSTOP lub MB_ICONERROR lub MB_ICONHAND	błąd krytyczny (znak stopu)
    //modalność
    //MB_APPLMODAL można kontynuować dopiero po reakci na komunikat
    //MB_SYSTEMMODAL to samo co wyżej + na wierzch    
    //sugerowane odpowiedzi
    //MB_DEFBUTTON1 MB_DEFBUTTON2 MB_DEFBUTTON3 MB_DEFBUTTON4


    //Zwracane wartości
    //0 w przypadku błędu
    //IDABORT IDCANCEL IDRETRY IDIGNORE IDNO IDYES IDOK odpowiednio



    //przykład
    MessageBox( NULL, "czesc", NULL, MB_YESNO | MB_DEFBUTTON2);
    
    return 0;
}