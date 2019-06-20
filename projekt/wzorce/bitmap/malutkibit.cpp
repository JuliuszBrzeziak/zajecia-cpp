
//###############################################################################
//
//                   RYSOWANIE BIT PO BICIE
//
//##############################################################################




#include <cmath>
#include <cstdlib>
#include "bitmap_image.hpp"

struct point_t { double x,y; };

int main()
{
    const int canvas_width  = 10;//ustalenie szerokości mapy
    const int canvas_height = 10;//ustalenie wysokości

    cartesian_canvas canvas(canvas_width,canvas_height); //ustalenie że obraz będzie kartezjański

    //canvas.setup_canvas(255, 150, 50);

    point_t pnt = {200,200};
    point_t vers ={1,1};/* 
    for(int i = 0; i<3000;i++){
        pnt.x -= vers.x;
        pnt.y -= vers.y;

        canvas.plot_pen_pixel(pnt.x,pnt.y);//rusyje kropkę w danym miejscu
    }

*/
    pnt = {-5,-5}; //ustawiam się w lewym dolnym rogu
    for (int j = 0; j < 200; j++)
    {
        pnt.x += 1;

        canvas.plot_pixel(pnt.x, pnt.y);
    }
    
   
   
    canvas.image().save_image("mybmp.bmp");//zapisuje
   



    return 0;
}