#ifndef RETA_H
#define RETA_H
#include "figurageometrica.h"

class Reta : public FiguraGeometrica{
    //Variáveis usadas para construir a linha
    int x0, xn, y0, yn;

public:

  // Construtor
  Reta(int _x0, int _y0, int _xn, int _yn);

  //Destrutor
  ~Reta();

  //Método para desenho
  void draw(Screen &t);

};

#endif // RETA_H
