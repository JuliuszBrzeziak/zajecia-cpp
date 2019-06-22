
//###############################################################################
//
//                   RYSOWANIE BIT PO BICIE
//
//##############################################################################




#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include "bitmap_image.hpp"
#include "myclass.hpp"

using namespace std;

int main()
{

    struct point_t { double x,y; };

    Liczba li;
    int arr[4]={0,1,882,1};

    int *ar;
    ar = arr;
    vector <int> arv(3,883);

    //li.test(885,arr,arv);

    const int canvas_width  = 100;//ustalenie szerokości mapy
    const int canvas_height = 1000;//ustalenie wysokości

    Liczba lic;
    lic.nat_tab(10000);
    lic.itrs();
    //lic.prtstr();
    cartesian_canvas canvas(canvas_width,canvas_height);

    point_t pnt = {-canvas_width/2,canvas_height/2};
        for(int i = 0; i <= 10000;i++){
            for(int j = 0; j< 100; j++ ){

                if('1'==lic.str[i][j]){
                    canvas.plot_pixel(pnt.x + j,pnt.y - i);
                }
                //    cout << "tak" ;
                //} else{
                //    cout << "nie" ;
                //}

            }
            //cout << endl;
        }

    canvas.image().save_image("plot2.bmp");


    
    cout << "zamykam sie" << endl;
    return 0;
}