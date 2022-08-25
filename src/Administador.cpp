#include "Administador.h"

Administador::Administador()
{
    //ctor
}

Administador::~Administador()
{
    //dtor
}

void Administador::menu()
{
    int opc;
    do
    {
        cout <<"                Administador Vuelos 'Despegar'"
            <<endl <<endl
           <<OPC_AGREGAR <<") Agregar vuelo" <<endl
          <<OPC_CONSULTAR <<") Consultar lista de vuelos" <<endl
        <<OPC_MODIFICAR <<") Modificar vuelo" <<endl
        <<OPC_ELIMINAR <<") Cancelar vuelo" <<endl
        <<OPC_SALIR <<") Salir" <<endl
        <<"Selecciona una opción: ";
        cin >>opc;
        cin.ignore();
        system("cls");

        switch(opc)
        {
        case OPC_AGREGAR:
            agregarVuelo();
            break;
        case OPC_CONSULTAR:
            consultarVuelo();
            break;
        case OPC_MODIFICAR:
            modificarVuelo();
            break;
        case OPC_ELIMINAR:
            eliminarVuelo();
            break;
        case OPC_SALIR:
            cout <<" Adios..." <<endl <<endl;
            break;
        default:
            cout <<"Opción no válida" <<endl <<endl;
            system("cls");
            break;
        }
    }
    while(opc != OPC_SALIR);
}

void Administador::agregarVuelo()
{
    Vuelo nuevo;
    string aux;
    int auxInt;


    cout <<endl <<"                 Agregar Vuelo" <<endl <<endl;
    cout <<"Vuelos agregados: "<<listaVuelos.size()<<endl
    <<"Ingresa los siguientes datos:" <<endl
    <<"Ciudad de origen: ";
    getline(cin, aux);
    nuevo.setOrigen(aux);

    cout <<"Ciudad destino: ";
    getline(cin, aux);
    nuevo.setDestino(aux);

    cout <<"Fecha de salida: ";
    cin >>aux;
    nuevo.setSalida(aux);

    cout <<"Fecha de llegada: ";
    cin >>aux;
    nuevo.setLlegada(aux);

    cout <<"Distancia: ";
    cin >>auxInt;
    nuevo.setDistancia(auxInt);

    cout <<"Carga: ";
    cin >>auxInt;
    nuevo.setCarga(auxInt);

    cout <<"Asientos: ";
    cin >>auxInt;
    nuevo.setAsientos(auxInt);

    listaVuelos.push_back(nuevo);

}

void Administador::consultarVuelo()
{
    cout<<endl<<"                 Vuelos     "<<endl;
    if (!listaVuelos.empty())
    {
        for (size_t i(0); i <listaVuelos.size(); ++i)
        {
            cout<<listaVuelos[i]<<endl;
        }
    }
    else
    {
        cout<<"No hay vuelos registrados"<<endl<<endl;
    }
}


void Administador::modificarVuelo(){
     cout<<endl<<"                Modificar vuelo     "<<endl;
    if (!listaVuelos.empty())
    {
        for (size_t i(0); i <listaVuelos.size(); ++i)
        {
            cout<<i<<".-"<<endl<<listaVuelos[i] <<endl<<endl;
        }
        int auxInt;
        cout <<"Numero del vuelo: ";
        cin >>auxInt;
        listaVuelos[auxInt].menuVuelo();
    }
    else
    {
        cout<<"No hay vuelos registrados"<<endl<<endl;
    }

}

void Administador::eliminarVuelo(){
     cout<<endl<<"                 Cancelar vuelo     "<<endl;
    if (!listaVuelos.empty())
    {
        for (size_t i(0); i <listaVuelos.size(); ++i)
        {
            cout<<i<<".-"<<endl<<listaVuelos[i] <<endl<<endl;
        }
        int auxInt;
        cout <<"Numero del vuelo: ";
        cin >>auxInt;
        listaVuelos.erase(auxInt);
        cout <<endl<<" Vuelo cancelado" <<endl <<endl;
    }
    else
    {
        cout<<"No hay vuelos registados"<<endl<<endl;
    }

}


