//
// Created by rrivas on 7/11/2025.
//

#ifndef CONTAINER_DE_FIGURAS_H
#define CONTAINER_DE_FIGURAS_H

#include <ostream>

#include "figura.h"
#include <iostream>
#include <vector>
using namespace std;



class ContainerDeFiguras {
    vector<Figura*> figuras;
    static string get_tipo_de_figuras(Figura* f);
public:
    ContainerDeFiguras() = default;
    ContainerDeFiguras(
        const ContainerDeFiguras &other);
    ~ContainerDeFiguras();

    void add_figura(Figura *figura);
    void remove_figura(char tipo);
    void print(ostream &os = cout) const;
};



#endif //CONTAINER_DE_FIGURAS_H
