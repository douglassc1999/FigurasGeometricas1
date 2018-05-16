#include "circulo.h"
#include <iostream>
#include <math.h>

using namespace std;

Circulo::Circulo(int _x, int _y, int _raio, int _fillmode)
{
    //Atribuição as variáveis privadas
    x = _x;
    y = _y;
    raio = _raio;
    fillmode = _fillmode;
}

Circulo::~Circulo()
{
    cout<<"Chamou DESTRUTOR de CIRCULO!\n";
}

void Circulo::draw(Screen &t)
{
  cout << "desenhando circulo\n";

  //O desenho da circunferência consiste em trigonometria básica
  // soma ao ponto central a multiplicação do raio com o cos de um angulo
  // que varia de 0 à 360, para percorrer toda sua extensão
  if(fillmode > 0){
      for(int i = 0; i<360; i++){
          t.setPixel(x + raio*cos(i*M_PI/180), y + raio*sin(i*M_PI/180));
  }while(raio != 0){
          for(int i = 0; i<360; i++){
            t.setPixel(x + raio*cos(i*M_PI/180), y + raio*sin(i*M_PI/180));
          }
          raio--;
          }

         cout<<t;

  //O desenho do circulo consiste no mesmo princípio, adicionando o preechimento
  // de circunferências de raios cada vez menores até que esteja completamente
  // preenchida
  }else{
      for(int i = 0; i<360; i++){
          t.setPixel(x + raio*cos(i*M_PI/180), y + raio*sin(i*M_PI/180));
       }

           cout<<t;
    }
}
