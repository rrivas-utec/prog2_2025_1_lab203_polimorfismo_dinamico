//
// Created by rrivas on 7/11/2025.
//

#include "container_de_figuras.h"

string ContainerDeFiguras::get_tipo_de_figuras(Figura *f) {
    if (dynamic_cast<Rectangulo*>(f) != nullptr) {
        return "Rectangle";
    }
    else if (dynamic_cast<Elipse*>(f) != nullptr) {
        return "Ellipse";
    }
    else if (dynamic_cast<Triangulo*>(f) != nullptr) {
        return "Triangle";
    }
    else {
        return "No defined";
    }
}

ContainerDeFiguras::ContainerDeFiguras(const ContainerDeFiguras &other) {
    figuras.reserve(other.figuras.size());
    for (auto f : other.figuras) {
        figuras.push_back(f->clone());
    }
}

ContainerDeFiguras::~ContainerDeFiguras() {
    cout << "Objetos liberados\n";
    for (const auto& f : figuras) {
        delete f;
    }
}

void ContainerDeFiguras::add_figura(Figura *figura) {
    figuras.push_back(figura);
}

void ContainerDeFiguras::remove_figura(char tipo) {
    for (auto it = figuras.begin(); it != figuras.end(); it++) {
        if (dynamic_cast<Rectangulo*>(*it) != nullptr && tolower(tipo) == 'r' ) {
            figuras.erase(it);
            return;
        }
        else if (dynamic_cast<Elipse*>(*it) != nullptr && tolower(tipo) == 'e' ) {
            figuras.erase(it);
            return;
        }
        else if (dynamic_cast<Triangulo*>(*it) != nullptr && tolower(tipo) == 't' ) {
            figuras.erase(it);
            return;
        }
    }
}

void ContainerDeFiguras::print(ostream &os) const {

    for (int i = 1; const auto& f : figuras) {
        cout << i++ << " " << get_tipo_de_figuras(f) << " " << f->area() << endl;
    }
}
