#include <iostream>
#include "grafo.h"
#include "Persona.h"
#include "WebApp.h"
#include "NodoGrafo.h"
#include "INodo.h"
#include <vector>

using namespace std;

int main() {

    // Ejercicio #1: 
    Grafo grafo1(true);

    Persona ana;
    ana.setNombre("Ana");

    Persona juan;
    juan.setNombre("Juan");

    grafo1.addNode(&ana);
    grafo1.addNode(&juan);

    grafo1.addArc(&ana, &juan);

    cout << "Ejercio de recorrido en anchura testeando creacion de arcos" << endl;

    WebApp Like = WebApp(1, "Likes");
    WebApp Comentario = WebApp(2, "Comentarios");
    WebApp Compartir = WebApp(3, "Compartidas");
    WebApp Guardados = WebApp(4, "Guardados");
    WebApp Post1 = WebApp(20, "Selfie");
    WebApp Post2 = WebApp(10, "Paisaje");
    WebApp Post3 = WebApp(60, "Salida familiar");
    WebApp Post4 = WebApp(24, "Almuerzo");
    WebApp Post5 = WebApp(40, "Graduacion");
    WebApp Post6 = WebApp(19, "Cita");
    WebApp Post7 = WebApp(14, "Pelicula");
    WebApp Post8 = WebApp(32, "Musica");
    WebApp Post9 = WebApp(55, "Mascotas");
    WebApp Post10 = WebApp(64, "VideoJuegos");
    WebApp Post11 = WebApp(27, "Concierto");
    WebApp Post12 = WebApp(90, "Dibujo");
    WebApp Post13 = WebApp(84, "Salud");
    
    WebApp allapps[] = {Like,Comentario,Compartir,Guardados,Post1,Post2,Post3,Post4,Post5,Post6,Post7,Post8,Post9,Post10,Post11,Post12,Post13};

    Grafo grafoApps(true);

    for(int i=0; i<17; i++) {
        grafoApps.addNode(&allapps[i]);
    }

    NodoGrafo* origen = grafoApps.getNodo(1);
    NodoGrafo* destino = grafoApps.getNodo(84);
    //origen, destino , peso
    grafoApps.addArc(origen, destino, 3);
    grafoApps.addArc(1, 20, 700);
    grafoApps.addArc(2, 20, 150);
    grafoApps.addArc(3, 20, 200);
    grafoApps.addArc(4, 20, 100);
    grafoApps.addArc(1, 10, 20);
    grafoApps.addArc(2, 10, 5);
    grafoApps.addArc(1, 60, 10);
    grafoApps.addArc(1, 90, 10500);
    grafoApps.addArc(2, 90, 5000);
    grafoApps.addArc(3, 90, 1000);
    grafoApps.addArc(4, 84, 300);
    grafoApps.addArc(1, 64, 1000);
    grafoApps.addArc(2, 64, 45);




    vector<INodo*> result = grafoApps.broadPath(&Like);

    for(int i=0; i<result.size(); i++) {
        WebApp dato = *((WebApp*)(void*)result[i]);
        cout << dato.getId() << " " << dato.getNombre() << endl;
    }



}