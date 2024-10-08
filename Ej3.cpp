#include <iostream>
#include "Cola/Cola.h"

using namespace std;

void filtrar(Cola<int>& col, int n) {
  Cola<int>* aux = new Cola<int>;
  bool flag = 0;

  while (!col.esVacia()) {
    int val = col.desencolar();
    
    flag += val == n; // si se encontró el numero
    
    aux->encolar(val);
  }
  if (!flag) throw 404;
  flag = 0;

  while (!aux->esVacia()) {
    int val = aux->desencolar();
    
    if (val != n || !flag) {
      col.encolar(val);
    }
    flag += val == n;
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
    cout << "Uso: " << argv[0] << " VALOR NUMEROS..." << endl;
    return 1;
  }
  Cola<int>* col = new Cola<int>;

  for (int i = 2; i < argc; i++) {
    col->encolar(atoi(argv[i]));
  }

  try {
    filtrar(*col, atoi(argv[1]));
  } catch (int) {
    cout << "No se encontró el número!" << endl;
    return 0;
  }
  mostrar(*col);
}
