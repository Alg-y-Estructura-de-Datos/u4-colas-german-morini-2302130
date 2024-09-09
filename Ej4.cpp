#include <iostream>
#include "Cola/Cola.h"

using namespace std;

// capaz deba usar otra cola para contar la cantidad, pero no tengo ganas xD
int sumar(Cola<int>& col, int n, int cantidad) {
  int suma = 0, val = col.desencolar();
  
  while (cantidad > 0 && val != n) {
    suma += val;
    col.encolar(val);
    val = col.desencolar();
    cantidad--;
  }

  return suma;
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
  int sum;

  for (int i = 2; i < argc; i++) {
    col->encolar(atoi(argv[i]));
  }

  cout << "Cola antes:" << endl;
  mostrar(*col);

  sum = sumar(*col, atoi(argv[1]), argc-2);
  cout << "La suma es: " << sum << endl;
}
