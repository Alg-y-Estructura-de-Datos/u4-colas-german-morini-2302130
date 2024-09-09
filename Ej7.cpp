#include <iostream>
#include <unistd.h>
#include "Cola/Cola.h"

using namespace std;

struct Impresion {};

int agregar(Cola<Impresion>& col) {
  int nro;

  cout << "Nro de hojas a agregar: ";
  cin >> nro;

  for (int i = 0; i < nro; i++) {
    col.encolar(Impresion{});
  }

  return nro;
}

void imprimir(Cola<Impresion>& col, int& nro) {
  if (nro == 0) throw 404;
  
  cout << "Imprimiendo..." << endl << endl;
  while (nro > 0) {
    cout << "📨";
    nro--;
    col.desencolar();
    sleep(2);
  }
  cout << endl << "Listo!" << endl;
}

void mostrar(Cola<Impresion>& col) {
  Cola<Impresion>* aux = new Cola<Impresion>;
  int i = 0;

  while (!col.esVacia()) {
    aux->encolar(col.desencolar());
  }

  while (!aux->esVacia()) {
    col.encolar(aux->desencolar());
    i++;
  }
  cout << "Documentos en espera: " << i << endl;
  delete aux;
}

int main() {
  Cola<Impresion>* cola = new Cola<Impresion>;
  int opt, hojas = 0;
  
  cout << "\033[H\033[2J";
  while (!(1==2)) {
    cout << endl;
    cout << "--- MENU ---" << endl;
    cout << "1. Estado" << endl;
    cout << "2. Agregar documentos" << endl;
    cout << "3. Imprimir documentos" << endl;
    cout << "4. Salir" << endl;
    cout << "> "; cin >> opt;

    cout << "\033[H\033[2J";
    switch (opt) {
      case 1:
        mostrar(*cola);
        break;
      case 2:
        hojas += agregar(*cola);
        break;
      case 3:
        try {
          imprimir(*cola, hojas);
          hojas = 0;
        } catch(int) {
          cout << "No hay documentos para imprimir!" << endl;
        }
        break;
      case 4:
        delete cola;
        return 0;
        break;
      default:
        cout << "Ingrese un valor entre 1-4!" << endl;
    }
  }
}

