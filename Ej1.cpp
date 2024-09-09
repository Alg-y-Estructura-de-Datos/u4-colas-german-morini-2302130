#include <iostream>
#include <cstring>
#include "Cola/Cola.h"

using namespace std;

int main(int argc, char** argv) {
  if (argc != 3) {
    cout << "Uso: " << argv[0] << " PALABRA1 PALABRA2" << endl;
    return 1;
  }

  if (strlen(argv[1]) != strlen(argv[2])) {
    cout << "Las colas difieren!" << endl;
    return 0;
  }

  Cola<char>* c1 = new Cola<char>;
  Cola<char>* c2 = new Cola<char>;

  for (int i = 1; i < strlen(argv[1]); i++) {
    c1->encolar(argv[1][i]);
    c2->encolar(argv[2][i]);
  }
  
  for (int i = 1; i < strlen(argv[1]); i++) {
    char val1 = c1->desencolar();
    char val2 = c2->desencolar();

    if (val1 != val2) {
      cout << "Las colas difieren!" << endl;
      return 0;
    }
  }

  cout << "Las colas son iguales!" << endl;
}
