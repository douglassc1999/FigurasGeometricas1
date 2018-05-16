#ifndef CIRCULO_H
#define CIRCULO_H
#include "figurageometrica.h"

class Circulo : public FiguraGeometrica{

    // Declaração da variáveis usadas para a construção do circulo/circunferência
    int x, y, raio, fillmode;

public:

  //Construtor da classe
  Circulo(int _x, int _y, int _raio, int _fillmode);

  //Destrutor da classe
  ~Circulo();

  // Método de desenho da subclasse circulo
  void draw(Screen &t);
};

#endif // CIRCULO_H
