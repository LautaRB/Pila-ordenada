#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define p printf
#define s scanf

typedef struct nodo
{
	int nro;
	struct nodo *sig;
}nodo;

int menu(void);
nodo* ingresarDato(void);
void insertar(nodo**,int);
nodo* nuevonodo(int);
void apilar(nodo**,nodo*);
nodo desapilar(nodo**);
void listar(nodo*);
int pilaVacia(nodo*);

int main()
{
	system("color 6f");
	
	int opc;
	nodo *pila = NULL;
	
	do
	{
		opc = menu();
		switch(opc)
		{
			case 1:
				system("cls");
				int i, j;
				
				p("-Cuantos nros desea ingresar?\n");
				s("%d",&j);
				
				for(i=0;i<j;i++)
				{
					apilar(&pila,ingresarDato());
				}
				
				p("\n\t\t-Los nros se ingresaron correctamente en la pila!-\n\n");
				
				system("Pause");
				opc = 10;
				break;
			case 2:
				system("cls");
				
				if(pilaVacia(pila)==0)
					p("\n\t\t-La pila esta vacia-\n\n");
				else
					listar(pila);
				
				system("Pause");
				opc = 10;
				break;
			case 3:
				system("cls");
				
				int max=-1000000;
				nodo secuaz;//Aux para el ordenamiento
				nodo *aux = NULL;//Aux para el ordenamiento (pila 2)
				nodo *pilaOrdenada = NULL;//pila 3
				
				int k;
				for(k=0;k<j;k++)//j es el contador de los nros que se ingresan, se uso en la op 1.
				{
					while(pila != NULL)//Busca el valor mas grande.
					{
						secuaz = desapilar(&pila);
						insertar(&aux,secuaz.nro);
						if(secuaz.nro>max)
							max = secuaz.nro;
					}
					
					while(aux != NULL)//Ordena segun el valor mas grande
					{
						secuaz = desapilar(&aux);
						if(secuaz.nro == max)
							insertar(&pilaOrdenada,secuaz.nro);
						else
							insertar(&pila,secuaz.nro);
					}
					max=-1000000;	
				}
				
				p("\t\t-Pila Ordenada!-\n");	
				listar(pilaOrdenada);
				
				free(aux);
				free(pilaOrdenada);
				system("Pause");
				opc = 10;
				break;
			case 4:
				system("cls");
				
				p("\n\t\tCerrando el programa...\n\n");
				getch();
				break;
		}
	}while(opc<1 || opc>4);
	
	free(pila);
	
	return 0;
}

int menu()
{
	system("cls");

	int opc;
	
	p("\t\t\t-MENU PILA-\n");
	p("\t\t-[1]-Ingresar Nros\n");
	p("\t\t-[2]-Listar\n");
	p("\t\t-[3]-Ordenar\n");
	p("\t\t-[4]-Salir\n");
	s("%d",&opc);
	return opc;
}

nodo* ingresarDato()
{
	int nro;
	nodo *q;
	q=(nodo*)malloc(sizeof(nodo));
	p("\nIngrese un numero:  ");
	s("%d",&nro);
	q->nro=nro;
	q->sig=NULL;
	return q;
}

void insertar(nodo **x, int y)
{
    nodo *nuevo;
    nuevo = nuevonodo(y);
    if (*x == NULL)
        *x = nuevo;
    else
    {
        insertar(&(*x)->sig, y);
    }
}

nodo *nuevonodo(int x)
{
    nodo *a;
    a = (nodo *)malloc(sizeof(nodo));
    a->nro = x;
    a->sig = NULL;
    return a;
}

void apilar(nodo**p,nodo*q)
{
   q->sig=*p;
   *p=q;
}

nodo desapilar(nodo**p)
{
	nodo dato,*aux;
	aux=*p;
	dato=**p;
	*p=(*p)->sig;
	free(aux);
	return dato;
}

void listar(nodo *x)
{
    if (x)
    {
        p("| %d |\n", x->nro);
        listar(x->sig);
    }
}

int pilaVacia(nodo*x)
{
	return((x==NULL)?0:1);
}
