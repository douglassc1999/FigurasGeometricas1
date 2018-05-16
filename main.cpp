#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "figurageometrica.h"
#include "circulo.h"
#include "reta.h"
#include "retangulo.h"
#include "ponto.h"
#include <vector>

using namespace std;

int main(){
/*
    //  FiguraGeometrica f;
  FiguraGeometrica *pf;
  Circulo c, *pc;
  Reta rt;
  Retangulo ro;

  //vector<FiguraGeometrica*> figuras;
  //string s, s2;

  //ifstream fin, fin2;
  //ofstream fout;


  fin.open("C:/Users/carva/Desktop/dca1202-master/retangulo.txt");
  if(!fin.is_open()){
      cout<<"ERRO!";
      exit(0);
  }

  fin2.open("C:/Users/carva/Desktop/Projeto_PA_2/Figuras_Padrao/reta.txt");
  if(!fin2.is_open()){
      cout<<"ERRO!";
      exit(0);
  }

  while(fin2.good()){
    getline(fin2, s2);
     cout << s2 << endl;
    }



  while(fin.good()){
    getline(fin, s);
     cout << s << endl;
    }
  cout<<"O tamanho da string eh: "<<s.size()<<endl;

  vector<char>::iterator vi;

  fout.open("C:/Users/carva/Desktop/dca1202-master/retangulo.txt");
  if(!fout.is_open()){
    exit(0);
  }


  for(int i = 0; i < s.size();i++){
      if(s[i] == '@'){
          //s[i] = '.';
          fout << ".";
      }
  }

    cout << s << endl;


  int selecao=0;

  cout<<"Qual figura mane?\n";
  cin>>selecao;
  switch(selecao){

  case 1: figuras.push_back(new Reta);         break;
  case 2: figuras.push_back(new Retangulo);    break;
  case 3: figuras.push_back(new Circulo);      break;
  case 4: figuras.push_back(new Ponto);        break;
  default: cout<<"Um valido\n";  break;
  }


   for(int i=0; i<figuras.size(); i++){
     figuras[i]->draw();
   }

   for(int i=0; i<figuras.size(); i++){
     delete figuras[i];
   }

  // ponteiros de uma classe herdeira
  // nao podem apontar para objetos de uma
  // classe derivada
  // pc = &f;

  f.draw();
  c.draw();
  pf = &c;
  pf->draw();
  pf = &rt;
  pf->draw();
  pf = &ro;
  pf->draw();
  */

    vector<FiguraGeometrica*> figuras;
    char sel;

    cout<<"Modo de Desenho ou Padrao? (d/p)\n";
    cin>>sel;

    // MODO DE DESENHO ARBITRARIO

    if(sel == 'd'){
    system("cls");  

    int nl, nc;
    int x0, y0, xn, yn, largura, altura, raio, fillmode;
    char brush;


    cout<<"Informe o tamanho da matriz (numero de linhas e colunas, respectivamente)\n";
    cin>>nl>>nc;
    Screen t(nl,nc);

    system("cls");

    cout<<"Informe o tipo de figura que voce quer desenhar: reta(r), retangulo(e) ou circulo(c)\n";
    cin>>sel;
    system("cls");

    if (sel=='r' ||sel== 'R'){
        cout<<"Informe as coordenadas iniciais e finais da reta (x0, y0), (xn,yn):\n";
        cin>>x0>>y0>>xn>>yn;

        cout<<"Informe o caracter para preenchimento: \n";
        cin>>brush;

        t.setBrush(brush);
        figuras.push_back(new Reta(x0, y0, xn, yn));

    }
    if (sel=='e' ||sel== 'E'){
        cout<<"Informe as coordenadas do canto superior esquerdo do retangulo (x0, y0), a largura e a altura:\n";
        cin>>x0>>y0>>largura>>altura;

        cout<<"Informe o caracter para preenchimento: \n";
        cin>>brush;

        cout<<"Seu retangulo deve ser preenchido? (se sim, digite um numero maior que zero): \n";
        cin>>fillmode;

         t.setBrush(brush);
        figuras.push_back(new Retangulo(x0, y0, largura, altura, fillmode));
    }
    if (sel=='c' ||sel== 'C'){
        cout<<"Informe as coordenadas  do centro do circulo ou circunferencia (x0, y0), e o raio:\n";
        cin>>x0>>y0>>raio;

        cout<<"Seu circulo deve ser preenchido? (se sim, digite um numero maior que zero): \n";
        cin>>fillmode;

        cout<<"Informe o caracter para preenchimento: \n";
        cin>>brush;

        t.setBrush(brush);
        figuras.push_back(new Circulo(x0, y0, raio, fillmode));

    }
    system("cls");
      for(vector<FiguraGeometrica*>::iterator it = figuras.begin(); it != figuras.end(); it++){

          (*it)->draw(t);
          t.clear();

    }

    for(int i=0; i<figuras.size(); i++){

      delete figuras[i];

    }

    }else{

    //MODO DE DESENHO PADRAO

    system("cls");

    ifstream fin;
    ofstream fout;
    vector<string*> s2;
    string s, cmd;
    int nc, nl, x0, y0, xn, yn, largura, altura, raio, fillmode;
    char caracter;

    fin.open("C:/Users/carva/Desktop/ProjetoPA/Arquivo/bola.txt"); //Diretório do arquivo de referência

    if(!fin.is_open()){

        cout<<"ERRO!";
        exit(0);

    }

    while(fin.good()){

        getline(fin, s);

        stringstream sstream(s);
        sstream >> cmd;
        if(cmd.compare("dim")==0){
            sstream >> nl >> nc;
            cout << "nl = " << nl << endl;
            cout << "nc = " << nc << endl;
        }
        if(cmd.compare("brush")==0){
            sstream >> caracter;
            cout << "caracter = " << caracter << endl;
        }
        // RETA
        if(cmd.compare("line")==0){
            sstream >> x0 >> y0 >> xn >> yn;
            cout << "x0 = " << x0 << endl;
            cout << "y0 = " << y0 << endl;
            cout << "x1 = " << xn << endl;
            cout << "y1 = " << yn << endl;
            figuras.push_back(new Reta(x0,y0,xn,yn));
            cout<<"A figura no diretorio escolhido eh uma RETA!\n";
        }

        //RETANGULO
        if(cmd.compare("rectangle")==0){
            sstream >> x0 >> y0 >> largura >> altura >> fillmode;
            cout << "x0 = " << x0 << endl;
            cout << "y0 = " << y0 << endl;
            cout << "largura = " << largura << endl;
            cout << "altura = " << altura << endl;
            cout << "fillmode = " << fillmode << endl;
            figuras.push_back(new Retangulo(x0,y0, largura, altura, fillmode));
            cout<<"A figura no diretorio escolhido eh um RETANGULO!\n";
        }

        // CIRCULO
        if(cmd.compare("circle")==0){
            sstream >> x0 >> y0 >> raio >> fillmode;
            cout << "x0 = " << x0 << endl;
            cout << "y0 = " << y0 << endl;
            cout << "raio = " << raio << endl;
            cout << "fillmode = " << fillmode << endl;
            figuras.push_back(new Circulo(x0,y0,raio, fillmode));
            cout<<"A figura no diretorio escolhido eh um CIRCULO!\n";
        }

    }

    Screen t(nl, nc);
    t.setBrush(caracter);

    for(vector<FiguraGeometrica*>::iterator it = figuras.begin(); it != figuras.end(); it++){

        t.clear();
        (*it)->draw(t);

    }
    t.setBrush('.');

    //PARA GRAVAR EM UM ARQUIVO EXTERNO


    fout.open("C:/Users/carva/Desktop/ProjetoPA/Arquivo/2.txt"); // Onde sera gravado a figura

    if(!fout.is_open()){

        cout<<"ERRO!";
        exit(0);
    }


    fout<<t;
    fout.close();

    for(int i=0; i<figuras.size(); i++){
        delete figuras[i];
    }

    }

    return 0;
}
