#include <iostream>

using namespace std;

class Smchdy
{
    public:
    int l_kl;
    int vmax;

    void ddj_smchd(){
        cout << "dodaj l_kl" << endl;
        cin >> l_kl;
        cout << "dodaj vmax" << endl;
        cin >> vmax;
    }

    void prt_smchd(){
        cout << l_kl << vmax;
    }

};



int main(){
    Smchdy s1;

    s1.ddj_smchd();
    s1.prt_smchd();

    return 0;
}