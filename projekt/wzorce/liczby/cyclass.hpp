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

    
    //klasa zawiera prywatną liczbę oraz tabele int
    private:
    //#############################################################
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //Ukradziono tab
    //Ukradziono i
    ////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //#############################################################
    
    private:
    
    


    //i publiczne metody
    public:

    vector<string> str;

    

    //#############################################################
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //chwilowo umieszczono tutaj tab i l też
    vector<unsigned long long  int> tab;
    int l;

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //#############################################################




    //dodaje do siebie dwie binarne i wypluwa stringa binarnego
    //OK
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


    //bierze inta i wpisuje go w l Liczby
    //OK
    void Wczytaj_l(int a){
        l = a;
    }

    //wypisuje i`ty element tablicy
    //OK
    void Wypisz_tabi(int i){
        cout << "element " <<i<<" to "<< tab[i] <<  endl;
    }
    
    //zwraca ilość elementów taba
    //OK
    int tab_Size(){
        return tab.size();
    }

    //zwraca długość str
    //OK
    int str_Size(){
        return str.size();
    }    

    //wypisuje tab
    //OK
    void Wypisz_tab(){
        for(int k=0;k<tab_Size();k++){
            cout << tab[k] << ",";
        }
    }

    //sprawdza czy tab jest pusty, jeśli tak to wpisuje do niego fib
    //OK
    void fib_tab(int n){
        if(0 != tab_Size()){
            cout << "fib_tab error: niezerowa wielkośc tablicy" << endl;
            exit(1);
        } else{
            string ss;
            tab = {1,1,1};
            its();
            for(int i = 3; i<=n; i++){
                //ss =  addBitStrings(str[i-1], str[i - 2]);
                //tab.push_back(tab[i-1] + tab[i - 2]);
                //str.push_back( ss );
            }
        }
    }



    //sprawdza czy tab jest pusty i wpisuje do niego silnie
    //OK
    void sil_tab(int n){
        
        int k;
        
        if(0 != tab_Size()){
            cout << "sil_tab error: niezerowa wielkośc tablicy" << endl;
            exit(2);
        } else{
            tab={1};
            for(int i =1;i<n;i++){
              
                tab.push_back( *(tab.end()-1) * i);
            }
        }
    }

    //naturalna tablica
    //OK
    void nat_tab(int n){
        if(0 != tab_Size()){
            cout << "nat_tab error: niezerowa wielkośc tablicy" << endl;
            exit(3);
        } else {
            tab={0};
            for (int i = 1; i<n;i++){
                tab.push_back(i);
            }
        }
    }

    //naturalny bin string
    //OK
    vector <string> nat_str(int n){

        vector <string> vec;
        cout << "elo1" <<endl;
        string ss;
        int a = 1;

        string s1 = bitset< 200 >(a).to_string();
          
        vec.push_back(s1);
            
        // str[4]= s2;
        cout << "elo2" << endl;
        //its();
        for(int i = 1; i<n; i++){
            ss =  addBinary(vec[i-1], s1);
            //reverse(ss.begin(),ss.end());
            //cout << ss <<endl <<endl;
            //reverse(ss.begin(),ss.end());
            //tab.push_back(tab[i-1] + tab[i - 2]);
            vec.push_back( ss );
        }

        return vec;
        
    }

    //spr czy tab i str jest pusty i wkleja odwrócony bit
    //OK
    void itrs(){

        if(0 == tab_Size()){
            cout << "itrs error: zerowa wielkośc tablicy liczb" << endl;
            exit(3); 
        }

        if(0 != str_Size()){
            cout << "itrs error: niezerowa wielkośc tablicy" << endl;
            exit(4);
        } else{
            string s;
            for(int i = 0; i <= tab_Size(); i++){
                s = bitset< 128 >(tab[i]).to_string();
                reverse(s.begin(),s.end());
                str.push_back(s);
            }
            
        }
    }

    //zamienia int tab w str bin
    //OK
    void its(){

        if(0 == tab_Size()){
            cout << "itrs error: zerowa wielkośc tablicy liczb" << endl;
            exit(3); 
        }

        if(0 != str_Size()){
            cout << "itrs error: niezerowa wielkośc tablicy" << endl;
            exit(4);
        } else{
            string s;
            for(int i = 0; i <= tab_Size(); i++){
                s = bitset< 128 >(tab[i]).to_string();
                //reverse(s.begin(),s.end());
                str.push_back(s);
            }
            
        }
    }


    //printuje mojego stringa bitów
    //OK
    void prtstr(){
        for(int i =0; i<str_Size();i++){
            cout << str[i] << endl;
        }
    }

    //printuje długość stringa
    //OK
    void nl(){
        cout << str[0].length() << endl;
        cout << str[0][2] << endl;
    }


    //Funkcja testowa
    void test(int i,int talbica[],vector<int> vec){

        int tablica2[5]={0,1,2,3,4};
        int i2=884;
        vector<unsigned long long int> vec2(5,3);

        //vec2[0]=88;
        //vec2[1]=881;
        vec2[2]=882;
        //vec2[3]=883;
        

        //sprawdza fib_tab
        cout <<"fib_tab ";
        sil_tab(4);
        Wypisz_tab();
        cout<<"  jesli jest \"0,1,1,2,3,5\" to dobrze"<<endl;


        //sprawdza działanie wczytaj_tab wewnętrznego wektora
        //Wczytaj_tab(vec2);
        cout <<"wczytaj_tab wewnątrz:" <<tab[2] << "  jeżeli 882 to dobrze"<< endl;
        cout << "tab_size " << tab_Size() << " powinno być 5" << endl;

        //sprawdza wczytaj_tab wektorów zewnętrznych
        //Wczytaj_tab(vec);
        cout <<"wczytaj_tab zewnątrz:" <<tab[2] << "  jeżeli 883 to dobrze"<< endl;

        //sprawdza działanie wewnętrznego wczytaj_l
        Wczytaj_l(i2);
        cout <<"wczytaj_l wewnątrz:" <<i2 << "  jeżeli 884 to dobrze"<< endl;

        //sprawdza działanie zewnętrznego wczytaj_l
        Wczytaj_l(i);
        cout <<"wczytaj_tab wewnątrz:" <<l << "  jeżeli 885 to dobrze"<< endl;

        //sprawdza wypisz_tabi
        Wypisz_tabi(2);

        //sprawdza tab_size
        cout << "tab_size " << tab_Size() << " powinno być 4" << endl;

        //sprawdza wypisz_tab
        cout << "wypisz tab";
        Wypisz_tab();
        cout << "powinno być \"883,883,883,\" "<<endl;

        //sprawdza prtspr
        cout << "prtspr" <<endl;
        itrs();
        prtstr();

        nl();

        //nat_tab(20);

        //rysuj();
        cout << "koniec testu"<<endl;
    }

    void tkvec(vector <string> vec){
        str = vec;
    }


    //mnożenie binarnej przez binarną
    //OK
    string bbmultiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a = 1;
        //int b = 0;
        string j = bitset< 200 >(a).to_string();
        string ss = num1;
        for(string i = bitset< 200 >(a).to_string();i!=num2;i = addBinary(i,j)){
            ss = addBinary(ss,num1);
            //cout << i<<endl<<j<<endl<<endl;
        }

        return ss;
    }

    //mnożenie binarnej przez dec
    //OK
    string bdmultiply(string num1,int n){
        string ss;
        for(int i=0;i<n;i++){
            ss = addBinary(ss,num1);
        }
        return ss;
    }

    //ustawia str w silnie
    //OK
    vector <string> sil_str(int n){

        vector <string> vec;

        cout << "elo1" <<endl;

            int a = 1;
            int b = str_Size();
            string ss= bitset< 200 >(a).to_string();;
            string s1 = bitset< 200>(a).to_string();
            string s2 = bitset< 200 >(a).to_string();          
            vec.push_back(s1);

            //its();
            for(int i = 1; i<n; i++){
                s2 =  addBinary(s2,s1);
                ss = bbmultiply(ss,s2);

                vec.push_back( ss );
            }

            return vec;
        
    }

    //fibonacci bin string
    //OK
    vector <string> fib_str(int n){

        vector <string> vec;

        string ss;
        int a = 1;

        string s1 = bitset< 200 >(a).to_string();
          
        vec.push_back(s1);
        vec.push_back(s1);
        
            
        for(int i = 2; i<n; i++){
            ss =  addBinary(vec[i-1], vec[i - 2]);

            vec.push_back( ss );
        } 

        return vec;
    }

    //jacobsthal
    //OK
    vector <string> jac_str(int n){

        vector <string> vec;
        cout << "elo1" <<endl;
        string ss;
        int a = 1;

        string s1 = bitset< 200 >(a).to_string();
          
        vec.push_back(s1);
        vec.push_back(s1);
        
        cout << "elo2" << endl;
            
        for(int i = 2; i<n; i++){
            ss =  addBinary(vec[i-1], bdmultiply(vec[i - 2],2));

            vec.push_back( ss );
        } 

        return vec;
    }

    //leonardo
    //OK
    vector <string> leo_str(int n){

        vector <string> vec;

        string ss;
        int a = 1;

        string s1 = bitset< 200 >(a).to_string();
          
        vec.push_back(s1);
        vec.push_back(s1);
        
            
        for(int i = 2; i<n; i++){
            ss =  addBinary(vec[i-1], addBinary(vec[i - 2],s1));

            vec.push_back( ss );
        } 

        return vec;
    }

    //jacobsthal-lucas
    //OK
    vector <string> jacluc_str(int n){

        vector <string> vec;

        cout << "elo1" <<endl;
        string ss;
        int a = 1;
        int b = 2;

        string s1 = bitset< 200 >(b).to_string();
        string s2 = bitset< 200 >(a).to_string();
          
        vec.push_back(s1);
        vec.push_back(s2);
        
        cout << "elo2" << endl;
            
        for(int i = 2; i<n; i++){
            ss =  addBinary(vec[i-1], bdmultiply(vec[i - 2],2));

            vec.push_back( ss );
        } 

        return vec;
    }

    //lucas
    //OK
    vector <string> luc_str(int n){

        vector <string> vec;

        string ss;
        int a = 1;
        int b = 2;

        string s1 = bitset< 200 >(b).to_string();
        string s2 = bitset< 200 >(a).to_string();
          
        vec.push_back(s1);
        vec.push_back(s2);
            
        for(int i = 2; i<n; i++){
            ss =  addBinary(vec[i-1], vec[i - 2]);

            vec.push_back( ss );
        } 

        return vec;
    }

    //padovan
    //OK
    vector <string> pad_str(int n){

        vector <string> vec;

        string ss;
        int a = 1;

        string s1 = bitset< 200 >(a).to_string();
          
        vec.push_back(s1);
        vec.push_back(s1);
        vec.push_back(s1);
        
            
        for(int i = 3; i<n; i++){
            ss =  addBinary(vec[i-2], vec[i - 3]);

            vec.push_back( ss );
        } 

        return vec;
    }

    //perrin
    //OK
    vector <string> per_str(int n){

        vector <string> vec;

        string ss;
        int a = 3;
        int b = 0;
        int c = 2;


        string s1 = bitset< 200 >(a).to_string();
        string s2 = bitset< 200 >(b).to_string();
        string s3 = bitset< 200 >(c).to_string();
          
        vec.push_back(s1);
        vec.push_back(s2);
        vec.push_back(s3);
        
            
        for(int i = 3; i<n; i++){
            ss =  addBinary(vec[i-2], vec[i - 3]);

            vec.push_back( ss );
        }

        return vec;
    }

    //pell
    //OK
    vector <string> pell_vstr(int n){
        vector <string> vec;
        cout << "elo1" <<endl;
        string ss;
        int a = 0;
        int b = 1;

        string s1 = bitset< 200 >(a).to_string();
        string s2 = bitset< 200 >(b).to_string();

        vec.push_back(s1);
        vec.push_back(s2);
        
        cout << "elo2" << endl;
            
        for(int i = 2; i<=n; i++){
            ss =  addBinary(vec[i-2], bdmultiply(vec[i - 1],2));

            vec.push_back( ss );
        }

        cout << "vec" << endl;

        return vec; 
    }


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
    vector<vector<string> >vstr;
    vector<string> pstr;

    //trójkąt paskala w vstr
    //OK
    void pascal(int n){

        //vector <int> vec,vec1;

        int a = 1;

        string i1 = bitset< 512 >(a).to_string();
        

        vector <string> vecp;
        vecp.push_back(i1);

        vstr.push_back(vecp);

        vecp.push_back(i1);

        vstr.push_back(vecp);

        
        for(int i = 2; i <=n; i++){

            //cout <<"elo";

            vector <string> vec;
            vec.push_back(i1);

            for(int j = 1; j <i; j++){

                vec.push_back(addBinary(vstr[i-1][j-1],vstr[i-1][j]));

            }

            vec.push_back(i1);

            vstr.push_back(vec);

            vec.clear();
	        vec.shrink_to_fit();

        }


    }

    void pascal21(int n){

        int a = 1;
        int b = 2;

        string i1 = bitset< 512 >(a).to_string();
        string i2 = bitset< 512 >(b).to_string();

        vector <string> vecp;
        vecp.push_back(i1);

        vstr.push_back(vecp);

        vecp.clear();
	    vecp.shrink_to_fit();

        vecp.push_back(i2);
        vecp.push_back(i1);

        vstr.push_back(vecp);

        for(int i = 2; i <=n; i++){

            cout <<"elo";

            vector <string> vec;
            vec.push_back(i2);

            for(int j = 1; j <i; j++){

                vec.push_back(addBinary(vstr[i-1][j-1],vstr[i-1][j]));

            }

            vec.push_back(i1);

            vstr.push_back(vec);

            vec.clear();
	        vec.shrink_to_fit();

        }

    }

    int vstr_size(){
        int i = vstr.size();
        i--;
        return i;
    }

    char par(int i, int j){
        //cout << vstr[i][j].at(199) << endl;
        return vstr[i][j].at(511);
    }

    void crtpstr(){
        for(int i = 0; i <= vstr_size(); i++){
            string pr;
            for(int j = 0; j<=i;j++){
                pr += par(i,j);
                }
            cout<<pr<<endl;
            pstr.push_back(pr);
            }

        cout << "poszlo";
        
    }

    //przeciążona funkcja test z klasy liczba
    int test(int i,int j){
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