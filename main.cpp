#include <iostream>
#include <vector>
#include "figura.h"
using namespace std;

void mostrar_areas(vector<Figura*> figuras) {
    for (const Figura* figura : figuras) {
        cout << figura->area() << endl;
    }
}


void ejemplo_contenedor_polimorfico () {
    vector<Figura*> figuras = {
        new Rectangulo(10, 5.5),
        new Elipse(10, 20),
        new Triangulo(10, 20)
    };
    mostrar_areas(figuras);

    for (Figura* fig : figuras) {
        delete fig;
    }
}

int main() {
    ejemplo_contenedor_polimorfico();
    return 0;
}
