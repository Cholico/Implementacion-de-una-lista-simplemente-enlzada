#include "Vuelo.h"

Vuelo::Vuelo()
{
    pasajeros = 0;
}

Vuelo::~Vuelo()
{
    //dtor
}


string Vuelo::getOrigen()const
{
    return origen;
}

void Vuelo::setOrigen(const string &value)
{
    origen = value;
}

string Vuelo::getDestino()const
{
    return destino;
}

void Vuelo::setDestino(const string &value)
{
    destino = value;
}

string Vuelo::getSalida()const
{
    return salida;
}

void Vuelo::setSalida(const string &value)
{
    salida = value;
}

string Vuelo::getLlegada() const
{
    return llegada;
}

void Vuelo::setLlegada(const string &value)
{
    llegada = value;
}

int Vuelo::getDistancia()const
{
    return distancia;
}

void Vuelo::setDistancia(int value)
{
    distancia = value;
}

int Vuelo::getPasajeros()const
{
    return pasajeros;
}

void Vuelo::setPasajeros(int value)
{
    pasajeros = value;
}


int Vuelo::getCarga()const
{
    return carga;
}

void Vuelo::setCarga(int value)
{
    carga = value;
}

int Vuelo::getAsientos()const
{
    return asientos;
}

void Vuelo::setAsientos(int value)
{
    asientos = value;
}

ostream &operator <<(ostream &os, const Vuelo &obj)
{
    os <<"Ciudad de origen: " <<obj.getOrigen()<<endl
        <<"Ciudad destino: " <<obj.getDestino() <<endl
       <<"Salida: " <<obj.getSalida() <<endl
       <<"Llegada: " <<obj.getLlegada() <<endl
       <<"Distancia: " <<obj.getDistancia()<<"Km"<<endl
       <<"Pasajeros: "<<obj.getPasajeros()<<endl
       <<"Carga: "<<obj.getCarga()<<" Toneladas"<<endl
       <<"Asientos: "<<obj.getAsientos()<<endl;


    return  os;
}

istream &operator >>(istream &is, Vuelo &obj)
{
    string origen;
    string destino;
    string salida;
    string llegada;
    int distancia;
    int carga;
    int asientos;

    getline(is, origen);
    getline(is, destino);
    getline(is, salida);
    getline(is, llegada);
    is >>distancia;
    is >>carga;
    is >>asientos;

    obj.setOrigen(origen);
    obj.setDestino(destino);
    obj.setSalida(salida);
    obj.setLlegada(llegada);
    obj.setDistancia(distancia);
    obj.setCarga(carga);
    obj.setAsientos(asientos);
    return is;
}

bool Vuelo::operator<(const Vuelo &other) const
{
    return this->getDestino() < other.getDestino();
}

void Vuelo::menuVuelo()
{
    int opc;
    do
    {
        cout <<"                Vuelo " <<origen <<"-" <<destino
            <<endl <<endl
           <<OPC_AGREGAR <<") Agregar pasajero" <<endl
          <<OPC_CONSULTAR <<") Consultar lista" <<endl
         <<OPC_BUSCAR <<") Buscar pasajero" <<endl
        <<OPC_MODIFICAR <<") Modificar pasajero" <<endl
        <<OPC_ELIMINAR <<") Eliminar pasajero" <<endl
        <<OPC_SALIR <<") Salir" <<endl
        <<"Selecciona una opción: ";
        cin >>opc;
        cin.ignore();
        system("cls");

        switch(opc)
        {
        case OPC_AGREGAR:
            agregarPasajero();
            break;
        case OPC_CONSULTAR:
            consultarPasajero();
            break;
        case OPC_BUSCAR:
            buscarPasajero();
            break;
        case OPC_MODIFICAR:
            modificarPasajero();
            break;
        case OPC_ELIMINAR:
            eliminarPasajero();
            break;
        case OPC_SALIR:
            cout <<"Dejando el vuelo " <<origen <<"-"
                <<destino <<" Adios..." <<endl <<endl;
            break;
        default:
            cout <<"Opción no válida" <<endl <<endl;
            system("cls");
            break;
        }
    }
    while(opc != OPC_SALIR);
}

void Vuelo::agregarPasajero()
{
    Pasajero nuevo;
    string aux;
    int auxInt;

    if (asientos > 0)
    {
        cout <<endl <<"                 Agregar Pasajero" <<endl <<endl;
        cout <<"Pasajeros: "<<pasajeros<<" | "<<"Asientos: "<<asientos<<endl
        <<"Ingresa los siguientes datos:" <<endl
        <<"Nombre: ";
        getline(cin, aux);
        nuevo.setNombre(aux);

        cout <<"Apellido: ";
        getline(cin, aux);
        nuevo.setApellido(aux);

        cout <<"Edad: ";
        cin >>auxInt;
        nuevo.setEdad(auxInt);

        cout <<"Origen: ";
        cin >>aux;
        nuevo.setOrigen(aux);

        cout <<"Destino: ";
        cin >>aux;
        nuevo.setDestino(aux);


        cout <<"Asiento: ";
        cin >>auxInt;
        nuevo.setAsiento(auxInt);

        listaPasajeros.push_back(nuevo);
        ++pasajeros;
        --asientos;

    }
    else
    {
        cout <<"No hay asientos suficientes" <<endl <<endl;
    }
}

void Vuelo::consultarPasajero()
{
    cout<<endl<<"                 Pasajeros     "<<endl;
    if (!listaPasajeros.empty())
    {
        for (size_t i(0); i <listaPasajeros.size(); ++i)
        {
            cout<< listaPasajeros[i] <<endl;
        }
    }
    else
    {
        cout<<"No hay pasajeros registrados"<<endl<<endl;
    }
}


void Vuelo::buscarPasajero()
{
    string nombre;
    string apellido;
    size_t i;
    cout <<"                    Búsqueda de pasajero" <<endl <<endl
        <<"Nombre: ";
    getline(cin, nombre);

    cout <<"Apellido: ";
    getline(cin, apellido);

    for (i = 0; i < listaPasajeros.size(); ++i)
    {
        if (nombre == listaPasajeros[i].getNombre() && apellido == listaPasajeros[i].getApellido())
        {
            cout <<endl<<endl<<listaPasajeros[i]<<endl<<endl;
            break;
        }
    }
    if (i == listaPasajeros.size())
    {
        cout <<endl<<endl<<"No esta registado este pasajero" <<endl <<endl;
    }
}

void Vuelo::modificarPasajero(){
    string nombre;
    string apellido;
    size_t i;
    cout <<"                    Modificar de pasajero" <<endl <<endl
        <<"Nombre: ";
    getline(cin, nombre);

    cout <<"Apellido: ";
    getline(cin, apellido);

    for (i = 0; i < listaPasajeros.size(); ++i)
    {
        if (nombre == listaPasajeros[i].getNombre() && apellido == listaPasajeros[i].getApellido())
        {
            string aux;
            int auxInt;
            cout <<"Ingresa los siguientes datos:" <<endl
            <<"Nombre: ";
            getline(cin, aux);
            listaPasajeros[i].setNombre(aux);

            cout <<"Apellido: ";
            getline(cin, aux);
            listaPasajeros[i].setApellido(aux);

            cout <<"Edad: ";
            cin >>auxInt;
            listaPasajeros[i].setEdad(auxInt);

            cout <<"Origen: ";
            cin >>aux;
            listaPasajeros[i].setOrigen(aux);

            cout <<"Destino: ";
            cin >>aux;
            listaPasajeros[i].setDestino(aux);

            cout <<"Asiento: ";
            cin >>auxInt;
            listaPasajeros[i].setAsiento(auxInt);

            cout <<endl<<endl<<"Modificacio hecha con exito" <<endl <<endl;
            break;
        }
    }
    if (i == listaPasajeros.size())
    {
        cout <<endl<<endl<<"No esta registado este pasajero" <<endl <<endl;
    }

}


void Vuelo::eliminarPasajero(){
     cout<<endl<<"                 Eliminar pasajeros     "<<endl;
    if (!listaPasajeros.empty())
    {
        for (size_t i(0); i <listaPasajeros.size(); ++i)
        {
            cout<<i<<".-"<<endl<<listaPasajeros[i] <<endl<<endl;
        }
        int auxInt;
        cout <<"Numero del pasajero: ";
        cin >>auxInt;
        listaPasajeros.erase(auxInt);
        cout <<endl<<" Pasajero borrado exitosamente" <<endl <<endl;
        --pasajeros;
        ++asientos;
    }
    else
    {
        cout<<"No hay pasajeros registrados"<<endl<<endl;
    }

}
