#include <iostream>
using namespace std;

class myclass{
    private:
        int a,b;
    public:
        void setdata(int i,int j){
            a=i;
            b=j;
        }
};

int main() {
    myclass p;
    //p = new myclass;
    p.setdata(5,6);

    cout << "elo" << endl;
    return 0;
}