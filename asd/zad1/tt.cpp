#include <iostream>
//#include <conio.h>

using namespace std;

class EksperymentCL
{
private:
    int TwojaPrywatnaFunkcja( int a, int b );
public:
    int TwojaPublicznaFunkcja( int a, int b );
};

int EksperymentCL::TwojaPrywatnaFunkcja( int a, int b )
{
    return( a - b + 2 );
}

int EksperymentCL::TwojaPublicznaFunkcja( int a, int b )
{
    return(( a + b ) * 2 );
}

int main()
{
    EksperymentCL zmienna;
    cout << "Wynik: " << zmienna.TwojaPrywatnaFunkcja( 3, 4 ) << endl;
    //getch();
    return( 0 );
}