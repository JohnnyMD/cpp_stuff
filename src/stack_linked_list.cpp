#include <iostream>

using namespace std;


struct Node
{
    int   data;
    Node *next;
};

struct Node  *testa_pila = NULL;
struct Node  *p;

int leggi_dato_utente()
{
    int data;
    cout << "\nInserisci un numero intero: ";
    cin  >> data;

    return data;
}


Node *new_node()
{
    int data = leggi_dato_utente();

    // L'operatore <new> crea un nuovo oggetto e ritorna SEMPRE un puntatore a quel oggetto in memoria  (rimane li fino alla rimozione - operatore <delete> o ...):
    p = new Node;
    p -> data = data;
    p -> next = NULL;
    return p;
}


void push(Node *n)
{
    if (testa_pila == NULL)         // pila vuota
        testa_pila = n;
    else
    {
        n -> next = testa_pila;     // almeno un nodo in pila
        testa_pila = n;             // testa pila punta al nodo appena creato
    }
}


void pop()
{
    if (testa_pila == NULL)
        cout << "Pila vuota !!!" << endl;
    else
    {
        cout    << "Valore dato del nodo eliminato (pop()): " 
                << testa_pila -> data 
                << endl;

        // Testa deve puntare al prossimo nodo:
        p = testa_pila;
        testa_pila = testa_pila -> next;
        
        // Elimionare il nodo precedentemente creato con <new>:
        delete p;
    }
}


void stampa_pila()
{
    Node *n;
    n = testa_pila;

    if (testa_pila == NULL)
    {
        cout << "Pila vuota !!!" << endl;
    }
    else
    {
        cout << "Pila: \n\t";
        while (n != NULL)
        {
            cout <<  n -> data  << " --> ";
            n = n -> next;
        }
        cout << "NULL" << endl;
    }
}


Node *cerca_prima_occorenza(int val)
{
    /** 
     * Cerca e ritorna il primo nodo con valore <val> (se esiste),
     * altrimenti ritorna NULL.  
    **/

    Node *n;
    n = testa_pila;

    if (testa_pila == NULL)
    {
        cout << "Pila vuota !!!" << endl;
        return NULL;
    }
    else
    {
        while (n != NULL)
        {
            if (n -> data  ==  val){
                // trovato !
                return n;
            }
            n = n->next;
        }
        cout << "Nessun nodo col valore  val = " << val << " nella pila..." << endl;
    }
}



int main()
{
    int   opzione,  x;
    Node *n;

    while (1)
    {
        cout << "\n\n  1.Push \n  2.Pop \n  3.Stampa Pila \n  4.Exit \n\n";
        cout << "Inserisce opzione da eseguire (1 | 2 | 3 | 4): ";
        cin >> opzione;
        cout << "\n> ";

        switch (opzione)
        {
        case 1:
            n = new_node();
            push(n);
            break;

        case 2:
            pop();
            break;

        case 3:
            stampa_pila();
            break;

        case 4:
            exit(0);

        default:
            cout << "\nOpzione inesistente !" << endl;
        }
    }

    return 0;
}
