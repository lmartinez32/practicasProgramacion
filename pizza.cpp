#include <iostream>
using namespace std;

struct ordenCliente
{
  string nombreCliente;
  string platoPrincipal;
  string bebida;
  string entrance;
  int metodoPago;
  int idOrden;
};
struct Nodo
{
  ordenCliente cliente;
  Nodo *siguiente;
};

void login();
void insertarOrden(string, string, string, string, int);
void mostrarOrden();
void menuOrden();

// Inicializar la lista
Nodo *lista = nullptr;

int main()
{
  login();
  menuOrden();

  return 0;
}

void login()
{
  const string username = "lmartinez33";
  const string password = "l2456789";

  string inputUsername;
  string inputPassword;

  do
  {
    cout << "Enter your username" << endl;
    cin >> inputUsername;
    cout << "Enter your password" << endl;
    cin >> inputPassword;

  } while ((inputUsername != username) && (inputPassword != password));
}

void menuOrden()
{
  int opcion;
  string nombre;
  string platoPrincipal;
  string entrada;
  string bebida;
  int id;
  int metodoPago;

  do
  {
    cout << "\t.:MENU:.\n";
    cout << "1. Insertar elementos de la orden" << endl;
    cout << "2. Mostrar elementos de la orden" << endl;
    cout << "3. Salir" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:

      cout << "Ingrese a nombre de quien sera la pizza:" << endl;
      cin >> nombre;

      cout << "Ingrese el ingrediente de la pizza: jamon, pepperonni" << endl;
      cin >> platoPrincipal;

      cout << "Ingrese su entrada: pan con ajo, cheesticks" << endl;
      cin >> entrada;

      cout << "Ingrese el sabor de su bebida" << endl;
      cin >> bebida;

      cout << "Ingrese el numero de orden" << endl;
      cin >> id;

      insertarOrden(nombre, platoPrincipal, entrada, bebida, id);

      cout << "\n";
      system("pause");
      break;

    case 2:
      mostrarOrden();
      cout << "\n";
      system("pause");
      break;
    case 3:
      break;
    }
    system("cls");
  } while (opcion != 3);
}

void insertarOrden(string name, string platoPrincipal, string bebida, string entrada, int id)
{
  Nodo *nuevoNodo = new Nodo();
  nuevoNodo->cliente.nombreCliente = name;
  nuevoNodo->cliente.platoPrincipal = platoPrincipal;
  nuevoNodo->cliente.bebida = bebida;
  nuevoNodo->cliente.entrance = entrada;
  nuevoNodo->cliente.idOrden = id;

  Nodo *auxiliar1 = lista;
  Nodo *auxiliar2;

  if (lista == nullptr)
  {
    lista = nuevoNodo;
  }
  else
  {
    nuevoNodo->siguiente = lista;
    lista = nuevoNodo;
  }

  cout << "Nombre: " << name << "agregado a lista correctamente" << endl;
  cout << "Plato Principal: " << platoPrincipal << "agregado a lista correctamente" << endl;
  cout << "Bebida: " << bebida << "agregado a lista correctamente" << endl;
  cout << "Entrada: " << entrada << "agregado a lista correctamente" << endl;
  cout << "Numero de orden: " << id << "agregado a lista correctamente" << endl;
}

void mostrarOrden()
{
  Nodo *auxiliar = new Nodo();
  auxiliar = lista;

  while (auxiliar != nullptr)
  {
    cout << auxiliar->cliente.nombreCliente << endl;
    cout << auxiliar->cliente.platoPrincipal << endl;
    cout << auxiliar->cliente.bebida << endl;
    cout << auxiliar->cliente.entrance << endl;
    cout << auxiliar->cliente.idOrden << endl;
    auxiliar = auxiliar->siguiente;
  }
}
