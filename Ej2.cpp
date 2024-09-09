#include <iostream>
#include <cstring>
#include "Cola/Cola.h"

using namespace std;

void filtrar(Cola<int>& col, int lim) {
  Cola<int>* aux = new Cola<int>;

  while (!col.esVacia()) {
    aux->encolar(col.desencolar());
  }

  while (!aux->esVacia()) {
    int val = aux->desencolar();
    
    if (val <= lim) {
      col.encolar(val);
    }
  }

  delete aux;
}

void mostrar(Cola<int>& col) {
  Cola<int>* aux = new Cola<int>;

  while (!col.esVacia()) {
    aux->encolar(col.desencolar());
  }

  while (!aux->esVacia()) {
    int val = aux->desencolar();
    cout << val << "->";
    col.encolar(val);
  }
  cout << "NULL" << endl;

  delete aux;
}

int main(int argc, char** argv) {
  if (argc <= 2) {
    cout << "Uso: " << argv[0] << " LIMITE NUMEROS..." << endl;
    return 1;
  }
  Cola<int>* col = new Cola<int>;

  for (int i = 2; i < argc; i++) {
    col->encolar(atoi(argv[i]));
  }

  filtrar(*col, atoi(argv[1]));
  mostrar(*col);
}
