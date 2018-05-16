#include "reta.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
Reta::Reta(int _x0, int _y0, int _xn, int _yn)
{
  // Atribuição das variáveis
  x0 = _x0;
  y0 = _y0;
  xn = _xn;
  yn = _yn;

}
void Reta::draw(Screen &t)
{
  cout << "desenhando reta\n";

  //Eq da reta eh y = m*x + b
  //  m = (yn - y0)/(xn - x0)
  // b = y - m*x

  // m é o coeficiente angular da reta

  int m=0, b=0;
  m = (yn - y0)/(xn - x0);
  b = yn - m*xn;

      for(int i=0; i<(xn-x0); i++){

          t.setPixel(x0+i, m*(x0+i)+b);

      }

  cout<<t;
}

