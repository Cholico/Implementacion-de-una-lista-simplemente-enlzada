#include "Pasajero.h"

Pasajero::Pasajero()
{
    //ctor
}

Pasajero::~Pasajero()
{
    //dtor
}


string Pasajero::getApellido() const
{
    return apellido;
}

void Pasajero::setApellido(const string &value)
{
    apellido = value;
}

string Pasajero::getNombre() const
{
    return nombre;
}

void Pasajero::setNombre(const string &value)
{
    nombre = value;
}


int Pasajero::getEdad() const
{
    return edad;
}

void Pasajero::setEdad(int value)
{
    edad = value;
}

string Pasajero::getOrigen() const
{
    return origen;
}

void Pasajero::setOrigen(const string &value)
{
    origen = value;
}

string Pasajero::getDestino() const
{
    return destino;
}

void Pasajero::setDestino(const string &value)
{
    destino = value;
}

int Pasajero::getAsiento() const
{
    return asiento;
}

void Pasajero::setAsiento(int value)
{
     asiento = value;
}

ostream &operator <<(ostream &os, const Pasajero &obj)
{
    os <<"Nombre: " <<obj.getNombre()<<" "<<obj.getApellido() <<endl
        <<"Edad: " <<obj.getEdad() <<endl
       <<"Ciudad origen: " <<obj.getOrigen() <<endl
       <<"Ciudad destino: " <<obj.getDestino() <<endl
       <<"Asiento: " <<obj.getAsiento() <<endl;

    return  os;
}

istream &operator >>(istream &is, Pasajero &obj)
{
    string apellido;
    string nombre;
    int edad;
    string origen;
    string destino;
    int asiento;

    getline(is, apellido);
    getline(is, nombre);
    is >>edad;
    getline(is, origen);
    getline(is, destino);
    is >>asiento;

    obj.setApellido(apellido);
    obj.setNombre(nombre);
    obj.setEdad(edad);
    obj.setOrigen(origen);
    obj.setDestino(destino);
    obj.setAsiento(asiento);

    return is;
}

bool Pasajero::operator<(const Pasajero &other) const
{
    return this->getNombre() < other.getNombre();
}



