#include "screen.h"
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

Screen::Screen(int _nlin, int _ncol){

    nlin = _nlin;
    ncol = _ncol;
    brush = ' ';
    mat = vector<vector<char>>(nlin, vector<char>(ncol, brush));

    cout<<"Chamou construtor da classe Screen\n";
};

Screen::~Screen()
{
    cout<<"Chamou destrutor da classe Screen\n";
};

void Screen::setPixel(int x, int y)
{

   if(x>nlin || x<0){
       cout<<"Posicao NAO existente!\n";
   }
   if(y>ncol || y<0){
       cout<<"Posicao NAO existente!\n";
   }
   mat[x][y] = brush;
};

void Screen::clear()
{
    for(int i=0; i<nlin;i++){
        for(int j= 0; j<ncol; j++){
            mat[i][j] = ' ';
        }
    }

};

void Screen::setBrush(char _brush)
{
    brush = _brush;
};

