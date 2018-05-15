#include "circulo.h"
#include <iostream>
#include <math.h>

using namespace std;

Circulo::Circulo(int _x, int _y, int _raio, int _fillmode)
{
    x = _x;
    y = _y;
    raio = _raio;
    fillmode = _fillmode;
}
Circulo::Circulo(Screen &t, int _x, int _y, int _raio, int _fillmode){
    x = _x;
    y = _y;
    raio = _raio;
    fillmode = _fillmode;

    if(fillmode > 0){
        for(int i = 0; i<360; i++){
            t.setPixel(x + raio*cos(i*M_PI/180), y + raio*sin(i*M_PI/180));
        }
        while(raio != 0){
            for(int i = 0; i<360; i++){
                t.setPixel(x + raio*cos(i*M_PI/180), y + raio*sin(i*M_PI/180));
            }
            raio--;
            }
        cout<<t;

    }else{
        for(int i = 0; i<360; i++){
            t.setPixel(x + raio*cos(i*M_PI/180), y + raio*sin(i*M_PI/180));
        }
        cout<<t;
    }
}

Circulo::~Circulo()
{
    cout<<"Chamou DESTRUTOR de CIRCULO!\n";
}

void Circulo::draw(Screen &t)
{
  cout << "desenhando circulo\n";

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
  }else{
      for(int i = 0; i<360; i++){
          t.setPixel(x + raio*cos(i*M_PI/180), y + raio*sin(i*M_PI/180));
       }

           cout<<t;
    }
}
