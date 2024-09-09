#include <iostream>
#include <unistd.h>
#include "Cola/Cola.h"

using namespace std;

class Paciente {
  private:
    string nombre;
    int numero;
  public:
    Paciente() {}
    Paciente(string nom, int num) : nombre(nom), numero(num) {}

    string getNombre() {return nombre;}
    int getNumero() {return numero;}

    void setNombre(string nom) {nombre = nom;}
    void setNumero(int num) {numero = num;}

    friend ostream& operator<<(ostream& os, const Paciente& p) {
        os << p.nombre << " - " << p.numero;
        return os;
    }
};

void mostrar(Cola<Paciente>& col) {
  Cola<Paciente>* aux = new Cola<Paciente>;
  int i = 1;

  while (!col.esVacia()) {
    aux->encolar(col.desencolar());
  }

  cout << "Pacientes en espera:" << endl;
  while (!aux->esVacia()) {
    Paciente val = aux->desencolar();
    cout << i << ". " << val << endl;
    col.encolar(val);
    i++;
  }

  delete aux;
}

void registrar(Cola<Paciente>& col) {
  string nom;
  int num;
    
  cout << "Ingrese los datos del paciente:" << endl;
  cout << "    Nombre:";
  cin.ignore();
  getline(cin, nom, '\n');

  cout << "    Numero:";
  cin >> num;

  col.encolar(Paciente(nom, num));
  cout << "Paciente registrado con exito!" << endl;
}

void atender(Cola<Paciente>& col) {
  Paciente p = col.desencolar();
  
  cout << "Atendiendo a " << p.getNombre() << "..." << endl;
  sleep(5);
  cout << "Paciente atendido" << endl;
}

int main() {
  Cola<Paciente>* cola = new Cola<Paciente>;
  int opt;
  
  cout << "\033[H\033[2J";
  while (!(1==2)) {
    cout << endl;
    cout << "--- MENU ---" << endl;
    cout << "1. Mostrar pacientes" << endl;
    cout << "2. Registrar pacientes" << endl;
    cout << "3. Atender pacientes" << endl;
    cout << "4. Salir" << endl;
    cout << "\033[31m> \033[0m"; cin >> opt;

    cout << "\033[H\033[2J";
    switch (opt) {
      case 1:
        mostrar(*cola);
        break;
      case 2:
        registrar(*cola);
        break;
      case 3:
        try {
          atender(*cola);
        } catch(int) {
          cout << "No hay pacientes en espera!" << endl;
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

