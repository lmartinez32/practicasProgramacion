#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo
{
  int dato;
  Nodo *der;
  Nodo *izq;
};

Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *, int);
void menu();

Nodo *arbol = nullptr;

int main()
{
  menu();

  return 0;
}

void menu()
{
  int dato, opcion, contador = 0;

  do
  {
    cout << "\t.:MENU:.\n"
         << endl;
    cout << "1. Insertar un nuevo nodo" << endl;
    cout << "2. Mostrar el arbol completo" << endl;
    cout << "3. Salir" << endl;
    cout << "opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
      cout << "\nDigite un numero: ";
      cin >> dato;
      insertarNodo(arbol, dato);
      cout << "\n";
      system("pause");
      break;
    case 2:
      cout << "\nMostrando el arbol completo:\n\n";
      mostrarArbol(arbol, contador);
      cout << "\n";
      system("pause");
      break;

    default:
      break;
    }
    system("cls");
  } while (opcion != 2);
}

Nodo *crearNodo(int n)
{
  Nodo *nuevoNodo = new Nodo;

  nuevoNodo->dato = n;
  nuevoNodo->der = nullptr;
  nuevoNodo->izq = nullptr;

  return nuevoNodo;
}

void insertarNodo(Nodo *&arbol, int n)
{
  if (arbol == nullptr)
  {
    Nodo *nuevoNodo = crearNodo(n);
    arbol = nuevoNodo;
  }
  else
  {
    int valorRaiz = arbol->dato;
    if (n < valorRaiz)
    {
      insertarNodo(arbol->izq, n);
    }
    else
    {
      insertarNodo(arbol->der, n);
    }
  }
}

void mostrarArbol(Nodo *arbol, int cont)
{
  if (arbol == nullptr)
  {
    return;
  }
  else
  {
    mostrarArbol(arbol->der, cont + 1);
    for (int i = 0; i < cont; i++)
    {
      cout << "   ";
    }
    cout << arbol->dato << endl;
    mostrarArbol(arbol->izq, cont + 1);
  }
}
