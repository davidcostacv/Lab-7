#include <iostream>

using namespace std;

struct Nodo {
    Nodo* padre;
    Nodo* izquierdo;
    Nodo* derecho;
    int elemento;

    Nodo() {
        padre = nullptr;
        izquierdo = nullptr;
        derecho = nullptr;
        elemento = 0;
    }

    Nodo(Nodo* izq, Nodo* der, int elem) {
        padre = nullptr;
        izquierdo = izq;
        derecho = der;
        elemento = elem;
    }

    Nodo(int elem) {
        padre = nullptr;
        izquierdo = nullptr;
        derecho = nullptr;
        elemento = elem;
    }

    bool esRaíz() {
        return padre == nullptr;
    }

    bool esHoja() {
        return izquierdo == nullptr && derecho == nullptr;
    }

    int altura() {
        if (esHoja()) {
            return 0;
        } else {
            int alturaIzq = izquierdo != nullptr ? izquierdo->altura() : 0;
            int alturaDer = derecho != nullptr ? derecho->altura() : 0;
            return max(alturaIzq, alturaDer) + 1;
        }
    }

    int profundidad() {
        if (esRaíz()) {
            return 0;
        } else {
            return padre->profundidad() + 1;
        }
    }

    void imprimirPreorden() {
        cout << elemento << " ";
        if (izquierdo != nullptr) {
            izquierdo->imprimirPreorden();
        }
        if (derecho != nullptr) {
            derecho->imprimirPreorden();
        }
    }

    void imprimirPosorden() {
        if (izquierdo != nullptr) {
            izquierdo->imprimirPosorden();
        }
        if (derecho != nullptr) {
            derecho->imprimirPosorden();
        }
        cout << elemento << " ";
    }

    void imprimirInorden() {
        if (izquierdo != nullptr) {
            izquierdo->imprimirInorden();
        }
        cout << elemento << " ";
        if (derecho != nullptr) {
            derecho->imprimirInorden();
        }
    }
};

int main() {

    Nodo* nodo1 = new Nodo(1);
    Nodo* nodo2 = new Nodo(2);
    Nodo* nodo3 = new Nodo(3);
    Nodo* nodo4 = new Nodo(nodo1, nodo2, 4);
    Nodo* nodo5 = new Nodo(nodo3, nullptr, 5);
    Nodo* raiz = new Nodo(nodo4, nodo5, 6);


    cout << "Altura del árbol: " << raiz->altura() << endl;
    cout << "Profundidad del árbol: " << raiz->profundidad() << endl;


    cout << "Recorrido en preorden: ";
    raiz->imprimirPreorden();
    cout << endl;

    cout << "Recorrido en posorden: ";
    raiz->imprimirPosorden();
    cout << endl;

    cout << "Recorrido en inorden: ";
    raiz->imprimirInorden();
    cout << endl;


    delete raiz;
    delete nodo1;
    delete nodo2;
    delete nodo3;
    delete nodo4;
    delete nodo5;

    return 0;
}
