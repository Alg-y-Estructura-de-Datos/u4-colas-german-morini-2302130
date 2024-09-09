#include <iostream>
#include "Cola/Cola.h"
#include "Pila/Pila.h"

using namespace std;

void filtrar(Cola<int>& col, Pila<int>& pil) {
  Cola<int>* aux = new Cola<int>;

  while (!col.esVacia()) {
    int val = col.desencolar();

    val%2 == 0 ? aux->encolar(val) : pil.push(val);
  }
  
  while (!aux->esVacia()) {
    col.encolar(aux->desencolar());
  }

  delete aux;
}

void mostrarPila(Pila<int>& pila) {
    Pila<int> pilaAux;

    // Desapilar elementos para mostrar sin perderlos
    while (!pila.esVacia()) {
        int valor = pila.pop();
        cout << "|" << valor << "|" << endl;
        pilaAux.push(valor);
    }

    // Restaurar la pila original
    while (!pilaAux.esVacia()) {
        pila.push(pilaAux.pop());
    }
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
  if (argc == 1) {
    cout << "Uso: " << argv[0] << " NUMEROS..." << endl;
    return 1;
  }
  Cola<int>* col = new Cola<int>;
  Pila<int>* pil = new Pila<int>;

  for (int i = 1; i < argc; i++) {
    col->encolar(atoi(argv[i]));
  }

  cout << "Cola antes:" << endl;
  mostrar(*col);

  filtrar(*col, *pil);
  cout << "Resultados:" << endl;
  mostrar(*col);
  mostrarPila(*pil);
}
