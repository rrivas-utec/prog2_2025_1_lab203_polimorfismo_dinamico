#include <iostream>
#include <vector>

#include "container_de_figuras.h"
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

void ejemplo_objeto_polimorfico () {
    Figura* f;
    f = new Rectangulo(5, 5);
    cout << f->area() << endl;
    delete f;
    f = new Elipse(10, 20);
    cout << f->area() << endl;
    delete f;
    f = new Triangulo(5, 20);
    cout << f->area() << endl;
    delete f;
}

void ejemplo_container_de_figuras () {
    ContainerDeFiguras c1;
    c1.add_figura(new Elipse(10, 20));
    c1.add_figura(new Rectangulo(5, 5));
    c1.add_figura(new Triangulo(5, 20));
    c1.print();
    cout << "----------------------" << endl;
    {
        // ContainerDeFiguras c2 = c1; // Constructor Copia
        ContainerDeFiguras c2(c1); // Constructor Copia
        c2.remove_figura('r');
        c2.print();
        cout << "----------------------" << endl;
    }
    c1.print();
    cout << "----------------------" << endl;
    {
        ContainerDeFiguras c3;
        c3 = c1;
        c3.remove_figura('r');
        c3.print();
        cout << "----------------------" << endl;
    }
    c1.print();
}

int main() {
    // ejemplo_contenedor_polimorfico();
    ejemplo_container_de_figuras();
    return 0;
}
