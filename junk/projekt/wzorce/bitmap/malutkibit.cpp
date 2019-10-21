
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

struct point_t { double x,y; };

        const int canvas_width  = 10;//ustalenie szerokości mapy
        const int canvas_height = 200;//ustalenie wysokości

        cartesian_canvas canvas(canvas_width,canvas_height);

        point_t pnt = {0,0};
        for(int i = 0; i <= str_Size();i++){
            for(int j = 0; j< str[0].length(); j++ ){

                if('1'==str[i][j]){
                    canvas.plot_pixel(i,j);
                }

            }
        }

        canvas.image().save_image("plot.bmp");
    }

    return 0;
}