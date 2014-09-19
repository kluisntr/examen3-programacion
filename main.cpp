#include "Evaluador.h"
#include <iostream>
#include <list>
#include "NodoBinario.h"
#include "NodoTrinario.h"
#include "NodoNario.h"
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mixer.h>



using namespace std;

//Devuelve true si encuentra num dentro del arbol raiz
//2.5pts
bool existe(NodoTrinario* raiz, int num)
{
if(raiz==NULL)
return false;
if(raiz->num==num)
{
return true;
}else
{
bool x=existe(raiz->der,num);
bool y=existe(raiz->izq,num);
bool z=existe(raiz->medio,num);
if(x==true||y==true||z==true)
return true;
}
return false;
}









//Devuelve true si encuentra num dentro del arbol raiz
//2.5pts


//    NodoNario* ra;
//      list<ra->hijos*>::iterator i =ra->hijos.begin();
bool existe(NodoNario* raiz, int num)
{
    if(raiz==NULL)
    {
    return false;
    }
    if(raiz->num==num)
    {
    return true;
    }
//    else
//    {
//    existe(raiz->hijos,num);
//    }
//    return false;



}

//Devuelve la cantidad de veces que encuentre el numero "num" dentro del arbol "raiz"
//5pts

int contar(NodoBinario* raiz, int num)
{
int contador;
if(raiz==NULL)
{
return 0;
}

if(raiz->num==num)
{

contador=1;

return (contador+contar(raiz->izq,num)+contar(raiz->der,num));
}else{
contador=0;
return (contador+contar(raiz->izq,num)+contar(raiz->der,num));
}


    return 0;
}



//Dado un tablero bidiensional donde:
//0 representa los pasillos donde puedo caminar
//1 representa las paredes donde no puedo caminar
//2 representa el terreno dificil (quita un paso)
//la cantidad de casillas donde me puedo desplazar "pasos"
//Devuelve true si puedo llegar desde las coordenadas [y_inicial][x_inicial] hasta [y_destino][x_destino], de lo contrario devuelve false
//Solo se puede desplazar hacia arriba, abajo, izquierda y derecha
//5pts







SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;

int tile_width = 64;

bool puedoLLegar(int tablero[5][5],
            int x_inicial, int y_inicial,
            int x_destino, int y_destino,
            int pasos)
{
    if(tablero[y_inicial][x_inicial]==2)
        pasos--;

    if(pasos<=0)
        return false;



    if(x_inicial>=5 || x_inicial<0 || y_inicial>=5 || y_inicial<0)
        return false;

    if(tablero[y_inicial][x_inicial]==1)
        return false;

    if(tablero[y_destino][x_destino]==1)
        return false;

    if(x_destino>=5 || x_destino<0 || y_destino>=5 || y_destino<0)
        return false;


    if(x_inicial==x_destino && y_inicial==y_destino)
        return true;


        //--------------------------------------





        //--------------------------------------


    bool puedo_der = puedoLLegar(tablero,  x_inicial+1,y_inicial,   x_destino,y_destino, pasos-1);

    bool puedo_izq = puedoLLegar(tablero,x_inicial-1,y_inicial,  x_destino,y_destino,pasos-1);

    bool puedo_arriba = puedoLLegar(tablero,x_inicial,y_inicial-1, x_destino,y_destino, pasos-1);

    bool puedo_abajo = puedoLLegar(tablero,x_inicial,y_inicial+1,x_destino,y_destino,pasos-1);


    return puedo_der || puedo_izq || puedo_arriba || puedo_abajo;

}

int main()
{
evaluar();

return 1;
}
