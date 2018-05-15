#include "reta.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
Reta::Reta(int _x0, int _y0, int _xn, int _yn)
{
  x0 = _x0;
  y0 = _y0;
  xn = _xn;
  yn = _yn;

}
void Reta::draw(Screen &t)
{
  cout << "desenhando reta\n";
/**
  //Ponto inicial
  tela.setPixel(x0,y0);
  //Ponto final
  tela.setPixel(x1,y1);

  //Algoritmo de Bresenham

  int slope;
          int dx, dy, incE, incNE, d, x, y;
          // Onde inverte a linha x1 > x2
          if (x1 > x2){
              bresenham1(x2, y2, x1, y1);
               return;
          }
          dx = x2 - x1;
          dy = y2 - y1;

          if (dy < 0){
              slope = -1;
              dy = -dy;
          }
          else{
             slope = 1;
          }
          // Constante de Bresenham
          incE = 2 * dy;
          incNE = 2 * dy - 2 * dx;
          d = 2 * dy - dx;
          y = y1;
          for (x = x1; x <= x2; x++){
              putpixel(x, y);
              if (d <= 0){
                d += incE;
              }
              else{
                d += incNE;
                y += slope;
              }
          }
    }
    */


  //Eq da reta eh y = m*x + b
  //  m = (yn - y0)/(xn - x0)
  // b = y - m*x

  // m é o coeficiente angular da reta
  int m=0, b=0;
  m = (yn - y0)/(xn - x0);
  b = yn - m*xn;

  // Funciona para retas de coordenas iguais

      for(int i=0; i<(xn-x0); i++){

          t.setPixel(x0+i, m*(x0+i)+b);

      }

  cout<<t;
}

