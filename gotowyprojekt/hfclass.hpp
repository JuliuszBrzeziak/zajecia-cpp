

//             TO JEST MóJ PLIK Z KLASAMI 


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

    private:

    vector<string> str;

    
    public:
    


    

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

        //wpisuje vec do stringa w klasie
        str = vec;

  
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

        //wpisuje vec do stringa w klasie
        str = vec;

  
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

        //wpisuje vec do stringa w klasie
        str = vec;

  
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

        //wpisuje vec do stringa w klasie
        str = vec;

  
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

        //wpisuje vec do stringa w klasie
        str = vec;

  
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

        //wpisuje vec do stringa w klasie
        str = vec;

  
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

        //wpisuje vec do stringa w klasie
        str = vec;

  
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

        //wpisuje vec do stringa w klasie
        str = vec;

  
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

        //wpisuje vec do stringa w klasie
        str = vec;

  
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

        //wpisuje vec do stringa w klasie
        str = vec;

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
    string addBinary(string a, string b) { 

        string wyn = ""; 
        int s = 0;          
        int i = a.size() - 1, j = b.size() - 1; 

        while (i >= 0 || j >= 0 || s == 1) 
        { 
        
        if(i>=0){
            s += a[i] - '0';//dodaje do s 1
        } else 
            {s+=0;}


        if(j>=0){
            s += b[j] - '0';//dodaje do s 1
        }else
            {s+=0;}

   
        wyn = char(s % 2 + '0') + wyn; 
  
        s /= 2; 
  
        i--; j--; 
        } 
        return wyn; 
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

    
    vector<vector<string> >vstr;//tutaj będą stringi z wartościami trójąta
    vector<string> pstr;//tutaj będą parzystości danych wartości trójkąta

    public:
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

    //tworzy trójkąt hasoya
    void has(int n){

        //wartości początkowe
        int a = 1;
        int b = 2;
        int c = 3;

        //zamienia je w stringi
        string i1 = bitset< 512 >(a).to_string();
        string i2 = bitset< 512 >(b).to_string();
        string i3 = bitset< 512 >(c).to_string();

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
        vecp.push_back(i1);
        vecp.push_back(i1);

        //pcha go do wektora stringów
        vstr.push_back(vecp);

        //czyści wektor jednostkowy
        vecp.clear();
	    vecp.shrink_to_fit();


        vecp.push_back(i2);
        vecp.push_back(i1);
        vecp.push_back(i2);

        //pcha go do wektora stringów
        vstr.push_back(vecp);

        //czyści wektor jednostkowy
        vecp.clear();
	    vecp.shrink_to_fit();

        vecp.push_back(i3);
        vecp.push_back(i2);
        vecp.push_back(i2);
        vecp.push_back(i3);

        //pcha go do wektora stringów
        vstr.push_back(vecp);

        //czyści wektor jednostkowy
        vecp.clear();
	    vecp.shrink_to_fit();

        //tworzy wektor buforowy
        vector <string> vec;

        //pętla kręci się dla ustalonego n
        for(int i = 4; i <=n; i++){

            //generuje początkowy wektor
            i2 = addBinary(vstr[i-1][0],vstr[i-2][0]);

            //wpisuje początkowy w pierwsze miejsce
            vec.push_back(i2);

            //wpisuje drugi
            i2 = vstr[i-1][0];
            
            vec.push_back(i2);

            //trójkąty maja szerokość proporcjonalną do wysokości
            //więc od niej uzależniamy szerokość
            int k = i;
            k--;
            for(int j = 2; j <=i; j++){

                //wpisuje wynik do wektora buforowego
                vec.push_back(addBinary(vstr[i-1][j-1],vstr[i-2][j-2]));
            }

            //vec.push_back(vstr[i-1][0]);

            //wpisuje końcową początkowy do wektora buforowego
            //vec.push_back(i2);

            //wpisuje wektor buforowy do wektora stringów
            vstr.push_back(vec);
            

            //wymazuje wektor buforowy
            vec.clear();
	        vec.shrink_to_fit();

        }
    }

    //tworzy trójkąt Bernoulli(2,1)
    void ber(int n){

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

        //wymazuje wektor buforowy
        vecp.clear();
	    vecp.shrink_to_fit();

        //wpisuje 2 w pierwsze miejsce
        vecp.push_back(i1);
        vecp.push_back(i2);

        //wpisuje wektor jednostkowy do wektora stringów
        vstr.push_back(vecp);


        //tworzy wektor buforowy
        vector <string> vec;

        //pętla kręci się dla ustalonego n
        for(int i = 2; i <=n; i++){

            //wpisuje 2 w pierwsze miejsce
            vec.push_back(i1);

            //trójkąty maja szerokość proporcjonalną do wysokości
            //więc od niej uzależniamy szerokość
            for(int j = 1; j <i; j++){

                //wpisuje wynik do wektora buforowego
                vec.push_back(addBinary(vstr[i-1][j-1],vstr[i-1][j]));
            }

            //wpisuje wynik do wektora buforowego
            vec.push_back(bdmultiply(vstr[i-1][i-1],2));

            //wpisuje wektor buforowy do wektora stringów
            vstr.push_back(vec);


            //wymazuje wektor buforowy
            vec.clear();
	        vec.shrink_to_fit();

        }

        cout <<vstr[3][3];

    }

    void bell( int f ) {

        //wartości początkowe
        int a = 1;

        //zamienia je w stringi
        string i1 = bitset< 512 >(a).to_string();
        string i2 = bitset< 512 >(a).to_string();
        
        //tworzy wektor w którym będzie string jednostkowy
        vector <string> vecp;

        //wpisuje jedynkę stringową do wektora jednostkowego
        vecp.push_back(i1);

        //wpisuje wektor jednostkowy do wektora stringów
        vstr.push_back(vecp);

        //tworzy wektor buforowy
        vector <string> vec;

        vec.push_back(i1);
        
        //pętla kręci się dla ustalonego f
        for(int i = 1; i <=f; i++){


            //trójkąty maja szerokość proporcjonalną do wysokości
            //więc od niej uzależniamy szerokość
            for(int j = 1; j <=i; j++){

                //wpisuje wynik do wektora buforowego
                i2 = addBinary(vstr[i-1][j-1],vec[j-1]);
                vec.push_back(i2);

            }

            //wpisuje wektor buforowy do wektora stringów
            vstr.push_back(vec);

            //wymazuje wektor buforowy
            vec.clear();
	        vec.shrink_to_fit();

            //wpisuję ostatni wyraz w pierwsze miejsce
            vec.push_back(i2);

            

        }

    }

};

