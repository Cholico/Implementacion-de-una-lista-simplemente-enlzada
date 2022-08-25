#ifndef ADMINISTADOR_H
#define ADMINISTADOR_H
#include <iostream>
#include "Vuelo.h"
#include "LSL.h"
#include <string>
#include <stdlib.h>

using namespace std;

class Administador
{
    public:
        Administador();
        virtual ~Administador();

        void menu();

    protected:

    private:

        LSL<Vuelo>listaVuelos;

        void agregarVuelo();
        void consultarVuelo();
        void modificarVuelo();
        void eliminarVuelo();


        enum Opciones
        {
            OPC_SALIR,
            OPC_AGREGAR,
            OPC_CONSULTAR,
            OPC_MODIFICAR,
            OPC_ELIMINAR
        };
};

#endif // ADMINISTADOR_H
