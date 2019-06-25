

//             TO JEST MOJA KLASA <3


#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include "bitmap_image.hpp"



using namespace std;


//nadrzędna klasa
class Liczba{




    
    public:
    


    vector<string> str;

    //zwraca wektor stringów ciągu silni
    vector <string> sil_str(int n){

        //tworzy wektor który zwróci
        vector <string> vec;

        //ustala wartości początkowe
        int a = 1;

        //tworzy stringi wartosci początkowych
        string s1 = bitset< 512>(a).to_string();
        string s2 = bitset< 512 >(a).to_string(); 

        //tworzy string buforowy
        string ss= bitset< 512 >(a).to_string();;

        //wpycha wartość początkową w wektor w wektor 
        vec.push_back(s1);

        //pętla kręci się dla ustalonego n
        for(int i = 1; i<n; i++){

            //zwiększa indeks
            s2 =  addBinary(s2,s1);

            //wpisuje w wektor buforowy
            ss = bbmultiply(ss,s2);

            //wpycha bufor w wektor
            vec.push_back( ss );

        }

            //zwraca wektor
            return vec;
    }


    //zwraca wektor stringów ciągu fibonacciego
    vector <string> fib_str(int n){

        //tworzy wektor który zwróci
        vector <string> vec;

        //ustala wartości początkowe
        int a = 1;

        //tworzy stringi wartosci początkowych
        string s1 = bitset< 512 >(a).to_string();
          
        //wpycha je w wektor
        vec.push_back(s1);
        vec.push_back(s1);
        
        //tworzy string buforowy
        string ss;

        //pętla kręci się dla ustalonego n
        for(int i = 2; i<n; i++){

            //wpisuje w bufor wynik przepisu
            ss =  addBinary(vec[i-1], vec[i - 2]);

            //wpycha bufor w wektor
            vec.push_back( ss );
        } 

        //zwraca wektor
        return vec;
    }

   
    //zwraca wektor stringów ciągu jacobsthala
    vector <string> jac_str(int n){

        //tworzy wektor który zwróci
        vector <string> vec;

        //ustala wartości początkowe
        int a = 1;

        //tworzy stringi wartosci początkowych
        string s1 = bitset< 512 >(a).to_string();
          
        //wpycha je w wektor
        vec.push_back(s1);
        vec.push_back(s1);
        
        //tworzy string buforowy
        string ss; 

        //pętla kręci się dla ustalonego n
        for(int i = 2; i<n; i++){

            //wpisuje w bufor wynik przepisu
            ss =  addBinary(vec[i-1], bdmultiply(vec[i - 2],2));

            //wpycha bufor w wektor
            vec.push_back( ss );
        } 

        //zwraca wektor
        return vec;
    }


    //zwraca wektor stringów ciągu Leonardo
    vector <string> leo_str(int n){

        //tworzy wektor który zwróci
        vector <string> vec;

        //ustala wartości początkowe
        int a = 1;


        //tworzy stringi wartosci początkowych
        string s1 = bitset< 512 >(a).to_string();
  
        //wpycha je w wektor
        vec.push_back(s1);
        vec.push_back(s1);
        
        //tworzy string buforowy
        string ss;

        //pętla kręci się dla ustalonego n
        for(int i = 2; i<n; i++){

            //wpisuje w bufor wynik przepisu
            ss =  addBinary(vec[i-1], addBinary(vec[i - 2],s1));

            //wpycha bufor w wektor
            vec.push_back( ss );
        } 

        //zwraca wektor
        return vec;
    }


    //zwraca wektor stringów ciągu jacobsthal-lucas
    vector <string> jacluc_str(int n){

        //tworzy wektor który zwróci
        vector <string> vec;

        //ustala wartości początkowe
        int a = 1;
        int b = 2;

        //tworzy stringi wartosci początkowych
        string s1 = bitset< 512 >(b).to_string();
        string s2 = bitset< 512 >(a).to_string();
          
        //wpycha je w wektor
        vec.push_back(s1);
        vec.push_back(s2);
                 
        //tworzy string buforowy
        string ss;

        //pętla kręci się dla ustalonego n
        for(int i = 2; i<n; i++){

            //wpisuje w bufor wynik przepisu
            ss =  addBinary(vec[i-1], bdmultiply(vec[i - 2],2));

            //wpycha bufor w wektor
            vec.push_back( ss );
        } 

        //zwraca wektor
        return vec;
    }


    //zwraca wektor stringów ciągu Lucasa
    vector <string> luc_str(int n){

        //tworzy wektor który zwróci
        vector <string> vec;

        //ustala wartości początkowe
        int a = 1;
        int b = 2;

        //tworzy stringi wartosci początkowych
        string s1 = bitset< 512 >(b).to_string();
        string s2 = bitset< 512 >(a).to_string();
        
        //wpycha je w wektor
        vec.push_back(s1);
        vec.push_back(s2);
            
        //tworzy string buforowy
        string ss;

        //pętla kręci się dla ustalonego n
        for(int i = 2; i<n; i++){

            //wpisuje w bufor wynik przepisu
            ss =  addBinary(vec[i-1], vec[i - 2]);

            //wpycha bufor w wektor
            vec.push_back( ss );
        } 

        //zwraca wektor
        return vec;
    }


    //zwraca wektor stringów ciągu Padovana
    vector <string> pad_str(int n){

        //tworzy wektor który zwróci
        vector <string> vec;

        //ustala wartości początkowe
        int a = 1;

        //tworzy stringi wartosci początkowych
        string s1 = bitset< 512 >(a).to_string();
          
        //wpycha je w wektor
        vec.push_back(s1);
        vec.push_back(s1);
        vec.push_back(s1);
        
        //tworzy string buforowy
        string ss;

        //pętla kręci się dla ustalonego n
        for(int i = 3; i<n; i++){

            //wpisuje w bufor wynik przepisu
            ss =  addBinary(vec[i-2], vec[i - 3]);

            //wpycha bufor w wektor
            vec.push_back( ss );
        } 

        //zwraca wektor
        return vec;
    }


    //zwraca wektor stringów ciągu Perrina
    vector <string> per_str(int n){

        //tworzy wektor który zwróci
        vector <string> vec;

        //ustala wartości początkowe
        int a = 3;
        int b = 0;
        int c = 2;

        //tworzy stringi wartosci początkowych
        string s1 = bitset< 512 >(a).to_string();
        string s2 = bitset< 512 >(b).to_string();
        string s3 = bitset< 512 >(c).to_string();
          
        //wpycha je w wektor
        vec.push_back(s1);
        vec.push_back(s2);
        vec.push_back(s3);

        //tworzy string buforowy
        string ss;
        
        //pętla kręci się dla ustalonego n
        for(int i = 3; i<n; i++){

            //wpisuje w bufor wynik przepisu
            ss =  addBinary(vec[i-2], vec[i - 3]);

            //wpycha bufor w wekto
            vec.push_back( ss );
        }

        //zwraca wektor
        return vec;
    }


    //zwraca wektor stringów ciągu Pella
    vector <string> pell_vstr(int n){

        //tworzy wektor który zwróci
        vector <string> vec;
        
        //ustala wartości początkowe
        int a = 0;
        int b = 1;

        //tworzy stringi wartosci początkowych
        string s1 = bitset< 512 >(a).to_string();
        string s2 = bitset< 512 >(b).to_string();

        //wpycha je w wektor
        vec.push_back(s1);
        vec.push_back(s2);
        
        //tworzy string buforowy
        string ss;

        //pętla kręci się dla ustalonego n
        for(int i = 2; i<=n; i++){

            //wpisuje w bufor wynik przepisu
            ss =  addBinary(vec[i-2], bdmultiply(vec[i - 1],2));

            //wpycha bufor w wektor
            vec.push_back( ss );
        }

        //zwraca wektor
        return vec; 
    }


    //zwraca wektor stringów ciągu liczb naturalnych
    vector <string> nat_str(int n){

        //tworzy wektor który zwróci
        vector <string> vec;

        //ustala wartości początkowe
        int a = 1;

        //tworzy stringi wartosci początkowych
        string s1 = bitset< 512 >(a).to_string();
          
        //wpycha je w wektor
        vec.push_back(s1);
        
        //tworzy string buforowy
        string ss;

        //pętla kręci się dla ustalonego n
        for(int i = 1; i<n; i++){

            //wpisuje w bufor wynik dodawania
            ss =  addBinary(vec[i-1], s1);

            //wpycha bufor w wektor
            vec.push_back( ss );
        }

        //zwraca wektor
        return vec;    
    }


    //wpisuje zany wektor stringów w wektor stringów w klasie
    void tkvec(vector <string> vec){
        str = vec;
    }


    //zwraca długość str
    int str_Size(){
        return str.size();
    }    

    //dodaje do siebie 2 stringi bitowe
    //autorem jest aganjali10
    string addBinary(string a, string b) { 
        string result = ""; // Initialize result 
        int s = 0;          // Initialize digit sum 
        int i = a.size() - 1, j = b.size() - 1; 
        while (i >= 0 || j >= 0 || s == 1) 
        { 
        // Comput sum of last digits and carry 
        s += ((i >= 0)? a[i] - '0': 0); 
        s += ((j >= 0)? b[j] - '0': 0); 
  
        // If current digit sum is 1 or 3, add 1 to result 
        result = char(s % 2 + '0') + result; 
  
        // Compute carry 
        s /= 2; 
  
        // Move to next digits 
        i--; j--; 
        } 
        return result; 
    }

    //mnożenie binarnej przez binarną
    string bbmultiply(string num1, string num2) {

        //tworzy bitowy iterator
        int a = 1;
        
        //zamienia ja w string bitów
        string j = bitset< 512 >(a).to_string();

        //granica iterowania już jest stringiem bitów jest też pierwszą sumą
        string ss = num1;

        //pętla kręci się tak długo aż osiągnie num2 raz
        //za każdym razem dodaje bitowo 1 do iteratora
        for(string i = bitset< 512 >(a).to_string();i!=num2;i = addBinary(i,j)){

            //wpisuje dodawanie w bufor
            ss = addBinary(ss,num1);

        }

        //zwraca stringa
        return ss;
    }

    //mnożenie binarnej przez dec
    string bdmultiply(string num1,int n){

        //tworzy buforowy string
        string ss;

        //pętla kręci się dla ustalonego n
        for(int i=0;i<n;i++){

            //dodaje mnożoną n razy
            ss = addBinary(ss,num1);
        }

        //zwraca stringa
        return ss;
    }




    //testuje czy w danym bicie jest jedynka
    int test(int i,int j){
        if('1'==str[i][j]){
            return 1;
        } else {
            return 0;
        }
    }

};

class Tablica : public Liczba {

    public:
    vector<vector<string> >vstr;//tutaj będą stringi z wartościami trójąta
    vector<string> pstr;//tutaj będą parzystości danych wartości trójkąta

    //tworzy trójkąt paskala w vstr
    //z jakiegoś powodu nie chce przyjąć nazwy pascal
    void pascaal( int f ) {

        //wartości początkowe
        int a = 1;

        //zamienia je w stringi
        string i1 = bitset< 512 >(a).to_string();
        
        //tworzy wektor w którym będzie string jednostkowy
        vector <string> vecp;

        //wpisuje jedynkę stringową do wektora jednostkowego
        vecp.push_back(i1);

        //wpisuje wektor jednostkowy do wektora stringów
        vstr.push_back(vecp);

        //dopisuje do wektora jednostkowego jeszcze jedną jedynkę
        vecp.push_back(i1);

        //pcha go do wektora stringów
        vstr.push_back(vecp);


        //tworzy wektor buforowy
        vector <string> vec;
        
        //pętla kręci się dla ustalonego f
        for(int i = 2; i <=f; i++){

            //wpisuje 1 w pierwsze miejsce
            vec.push_back(i1);

            //trójkąty maja szerokość proporcjonalną do wysokości
            //więc od niej uzależniamy szerokość
            for(int j = 1; j <i; j++){

                //wpisuje wynik do wektora buforowego
                vec.push_back(addBinary(vstr[i-1][j-1],vstr[i-1][j]));

            }

            //wpisuje końcową jedynkę do wektora buforowego
            vec.push_back(i1);

            //wpisuje wektor buforowy do wektora stringów
            vstr.push_back(vec);

            //wymazuje wektor buforowy
            vec.clear();
	        vec.shrink_to_fit();

        }

    }

    //tworzy trójkąt pascala(2,1)
    void pascal21(int n){

        //wartości początkowe
        int a = 1;
        int b = 2;

        //zamienia je w stringi
        string i1 = bitset< 512 >(a).to_string();
        string i2 = bitset< 512 >(b).to_string();

        //tworzy wektor w którym będzie string jednostkowy
        vector <string> vecp;

        //wpisuje jedynkę stringową do wektora jednostkowego
        vecp.push_back(i1);

        //wpisuje wektor jednostkowy do wektora stringów
        vstr.push_back(vecp);

        //czyści wektor jednostkowy
        vecp.clear();
	    vecp.shrink_to_fit();

        //recykling wektora jednostkowego
        //wpisuje drugi wiersz trójkąta
        vecp.push_back(i2);
        vecp.push_back(i1);

        //pcha go do wektora stringów
        vstr.push_back(vecp);

        //tworzy wektor buforowy
        vector <string> vec;

        //pętla kręci się dla ustalonego n
        for(int i = 2; i <=n; i++){

            //wpisuje 2 w pierwsze miejsce
            vec.push_back(i2);

            //trójkąty maja szerokość proporcjonalną do wysokości
            //więc od niej uzależniamy szerokość
            for(int j = 1; j <i; j++){

                //wpisuje wynik do wektora buforowego
                vec.push_back(addBinary(vstr[i-1][j-1],vstr[i-1][j]));
            }

            //wpisuje końcową jedynkę do wektora buforowego
            vec.push_back(i1);

            //wpisuje wektor buforowy do wektora stringów
            vstr.push_back(vec);


            //wymazuje wektor buforowy
            vec.clear();
	        vec.shrink_to_fit();

        }

    }

    //sprawdza długość wektora stringów
    int vstr_size(){
        
        //wpisuje jego długość do i
        int i = vstr.size();

        //zmniejsza ja o 1 aby zwrócić indeks ostatniego wyrazu
        i--;
        return i;
    }

    //sprawdza czy dany string jest parzysty
    char par(int i, int j){

        //sprawdza ostatni bit odpowiedzialny za parzystośc
        return vstr[i][j].at(511);
    }

    //wpisuje parzystości w wektor parzystości
    void crtpstr(){
        
        //pętla kręci się dla długości wektora stringów
        for(int i = 0; i <= vstr_size(); i++){

            string pr;//za każdym razem tworzy się string od nowa

            //trójkąty maja szerokość proporcjonalną do wysokości
            //więc od niej uzależniamy szerokość
            for(int j = 0; j<=i;j++){
                
                //sprawdzamy parzystość i wpisujemy ją w bufor
                pr += par(i,j);
                }
            //pchamy bufor w string parzystości
            pstr.push_back(pr);
            }     
    }

    //przeciążona funkcja test z klasy liczba
    int test(int i,int j){

        //jeżeli wektor parzystości jest nieparzysty
        if('1'==pstr[i][j]){
            return 1;
        } else {
            return 0;
        }
    }

};

/* 

int main()
{

    struct point_t { double x,y; };
    */
/* 
    Liczba li;
    int arr[4]={0,1,882,1};

    int *ar;
    ar = arr;
    vector <int> arv(3,883);

    Tablica tbl;
    cout << "hii" << endl;

    //tbl.vstr[0][0] = "elo";
    

    Tablica tbl;

    const int k = 300; // ilość iteracji

    tbl.pascal21(k);

    cout << "hii" << endl;


   tbl.crtpstr();

    cout << tbl.vstr.size() << tbl.vstr_size() << endl;

    cout << tbl.pstr[0] << tbl.pstr[1] << tbl.pstr[2] << endl;

    double p;


 
    const int n = 250; //szerkość kanwy
    const int m = 1000; //wysokość

    const int l = 200; //ilość bitów
    const int canvas_width  = n;//ustalenie szerokości mapy
    const int canvas_height = m;//ustalenie wysokości



    cartesian_canvas canvas(canvas_width,canvas_height);

    
 
    point_t pnt = {-canvas_width/2,canvas_height/2};
     
        for(int i = 0; i <= k;i++){
            cout <<"e" <<endl;
            for(int j = 0; j<=i; j++ ){


                
                if(1==tbl.test(i,j)){
                    canvas.plot_pixel(pnt.x + j,pnt.y - i);
                }


            }   
        }
    cout<< "fibtab przeszedł" << endl;
    canvas.image().save_image("plot2.bmp");
     
    cout << tbl.test(1,1) << "zamykam sie" << endl;
    return 0;
}*/

