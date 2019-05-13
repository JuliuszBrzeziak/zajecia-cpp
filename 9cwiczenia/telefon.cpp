#include<iostream>
#include<string>
using namespace std;

class Telefon{
    int numer;
    string nazwa;

    public:
    Telefon (int nr=0, string nz="") : numer(nr), nazwa(nz){}

};

ostream & operator<< (ostream &wyjscie, const Telefon &s){

}

class student{
    string name;
    int age;

    public:
    student(){
        cout << "wolany konstruktor\n";
    }

    student(string name, int age){
        this->name = name;
        this->age = age;
    }

    void display(){
        cout<<"Name:"<<name<<endl;
        cout<<"Age:"<<age<<endl;
    }

    void * operator new(size_t size){
        cout << "przeladowanie New rozmiar"<<size <<endl;
        void * p = ::new student();

        //void * p = malloc(size); podobno też działa, czy tak samo?

        return p;
    }

    void operator delete(void *p){
        cout << "przeladowanie delete" << endl;
        free(p);
    }
};

int main(){
    cout << "elo" << endl;

    student * p = new student("Jan",24);

    p->display();
    delete p;

    return 0;
}