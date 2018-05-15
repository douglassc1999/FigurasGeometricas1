#ifndef RETA_H
#define RETA_H
#include "figurageometrica.h"

class Reta : public FiguraGeometrica{
    int x0, xn, y0, yn;

public:

  Reta(int _x0, int _y0, int _xn, int _yn);
  ~Reta();

  void draw(Screen &t);

};

#endif // RETA_H
