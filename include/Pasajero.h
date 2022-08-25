#ifndef PASAJERO_H
#define PASAJERO_H
#include <iostream>
#include <string>

using namespace std;


class Pasajero
{
    public:
        Pasajero();
        virtual ~Pasajero();

        void setApellido(const string &valor);
        string getApellido() const;

        void setNombre(const string &valor);
        string getNombre() const;

        void setEdad(int valor);
        int getEdad() const;

        void setOrigen(const string &valor);
        string getOrigen() const;

        void setDestino(const string &valor);
        string getDestino() const;

        void setAsiento(int valor);
        int getAsiento() const;

        bool operator <(const Pasajero &other) const;
        friend ostream &operator <<(ostream &os, const Pasajero &obj);
        friend istream &operator >>(istream &is, Pasajero &obj);

    private:

        string apellido;
        string nombre;
        int edad;
        string origen;
        string destino;
        int asiento;
};

#endif // PASAJERO_H
