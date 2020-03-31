#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>

using namespace std;


class Jugador
{
public:
    Jugador();
    Jugador(string n):nombre(n),puntos(134){};
    string nombre;
    int puntos;

    template<typename charT, typename traits>
    friend std::basic_ostream<charT, traits> &
    operator<< (std::basic_ostream<charT, traits> &lhs, Jugador const &rhs) {
        return lhs << rhs.nombre << ','<< ' ' << rhs.puntos;
    }
};

#endif // JUGADOR_H
