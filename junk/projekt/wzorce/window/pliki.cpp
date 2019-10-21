#include <windows.h>

int main(int argc, char const *argv[])
{


    /* 
    CreateFile(
        lpFileName  "Nazwapliku.roz" \\ jeśli ma mieć ścieżkę,
        dwDesiredAccess tryb odczytu GENERIC_READ to odczyt,
        dwShareMode jakie operacje mogą być wykonane (tryb współdzielenia) 0 pozwala wszystkim FILE_SHARE_READ | FILE_SHARE_WRITE,
        lpSecurityAttributesatrybut bezpieczeństwa (mało ważne) NULL,
        dwCreationDistribution  jak utworzyć plik,
        dwFlagsAndAttributes    flagi i atrybuty,
        hTemplateFile   uchwyt pliku którego atrybut chcemy skopiować na właśnie otwierany plik !!!NULL!!!

    );
    
    Opcje dwCreationDistribuion
    CREATE_NEW - tworzy plik, jeśli już taki plik istnieje wyrzuca błąd
    CREATE_ALWAYS - tworzy plik, jeśli już istnieje to nadpisuje
    OPEN_EXISTING - otwiera istniejący plik, jesli nie istnieje to błąd
    OPEN_ALWAYS - otwiera ist. plik, jeśli nie istnieje to go tworzy
    TRUNCATE_EXISTING - Otwiera istniejący plik zerując go, jeśli nie istnieje to bład, musi być GENERIC_WRITE

    CreateFile powinno zwrócić uchwyt typu HANDLE
    jeżeli bład to INVALID_HANDLE_VALUE


    */
   hPlik = CreateFile( "test.txt",
    GENERIC_READ,
    0,
    NULL, 
    OPEN_EXISTING, 
    0, 
    NULL );

    if( hPlik == INVALID_HANDLE_VALUE ) {
    MessageBox( NULL, "Nie można otworzyć pliku.", "A to pech!", MB_ICONEXCLAMATION );
    PostQuitMessage( 0 ); // Zakończ program
}


   /* zwraca wartość w DWORD
   GetFileSize(
       pierwszy argument to HANDLE który zwraca CreateFile,
       drugi powinien być NULL
   );
   
*/
    DWORD dwSize = GetFileSize( hPlik, NULL );
        if( dwSize == 0xFFFFFFFF ) // błąd!
     MessageBox( NULL, "Zły rozmiar pliku!", "Błąd", MB_ICONEXCLAMATION );
    else
/* 
   Następnie alokujemy pamięć:

   GlobalAlloc alokuje nowy obszar
   GlobalAlloc(
       GPTR, sprawia że cały obszar wypełnia się zerami
       dwSize czyli ilość bajtów do zalokowania
   );
   
   W przypadku błędu funkcja zwraca NULL

    */
    LPSTR Bufor;
    Bufor =( LPSTR ) GlobalAlloc( GPTR, dwSize );

    if( Bufor == NULL )
        MessageBox( NULL, "Błąd alokacji", "Ups...", MB_ICONSTOP );
   
   /*

   ReadFile(
       hFile, - uchwyt pliku do odczytu
       lpBuffer, - wskaźnik na bufor do którego wczytamy
       nBytesToRead, - liczba bajtów do odczytania
       lpBytesRead, - adres zmiennej otrzymującej liczbę bajtów które odczytał
       lpOberlapped - adres struktury otrzymującej dane
   );
   
    */



    return 0;
}
