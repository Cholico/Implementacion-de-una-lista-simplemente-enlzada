#ifndef VUELO_H
#define VUELO_H
#include <iostream>
#include <string>
#include <istream>
#include "LSL.h"
#include "Pasajero.h"
#include <stdlib.h>

using namespace std;

class Vuelo
{
    public:
        Vuelo();
        virtual ~Vuelo();

        void setOrigen(const string &valor);
        string getOrigen()const;

        void setDestino(const string &valor);
        string getDestino()const;

        void setSalida(const string &valor);
        string getSalida()const;

        void setLlegada(const string &valor);
        string getLlegada()const;

        void setDistancia(int valor);
        int getDistancia()const;

        void setPasajeros(int valor);
        int getPasajeros()const;

        void setCarga(int valor);
        int getCarga()const;

        void setAsientos(int valor);
        int getAsientos()const;

        void menuVuelo();

        bool operator <(const Vuelo &other) const;
        friend ostream &operator <<(ostream &os, const Vuelo &obj);
        friend istream &operator >>(istream &is, Vuelo &obj);

    private:

        LSL<Pasajero> listaPasajeros;
        string origen;
        string destino;
        string salida;
        string llegada;
        int distancia;
        int pasajeros;
        int carga;
        int asientos;


        void agregarPasajero();
        void consultarPasajero(const Pasajero &p);
        void consultarPasajero();
        void consultarLista();
        void buscarPasajero();
        void modificarPasajero();
        void eliminarPasajero();

        enum Opciones
        {
            OPC_SALIR,
            OPC_AGREGAR,
            OPC_CONSULTAR,
            OPC_BUSCAR,
            OPC_MODIFICAR,
            OPC_ELIMINAR
        };
};

#endif // VUELO_H
