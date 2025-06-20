#include "../include/Menu.h"
#include "../include/Menu.h"
#include "../include/ManejadorClientes.h"
#include "../include/ManejadorInmobiliarias.h"
#include "../include/ManejadorInmuebles.h"
#include "../include/ManejadorPropietarios.h"
#include "../include/ManejadorPublicaciones.h"
#include "../include/Factory.h"
#include "../include/ControladorSistema.h"
#include "../include/CargaDatos.h"
#include "../include/ControladorFechaActual.h"
#include <iostream>
void limpiarSistema();
int main() {
    atexit(limpiarSistema);
    while (true) {
        mostrarMenu();
        int opcion = obtenerOpcion();
        ejecutarOpcion(opcion);
        std::cout << std::endl;
    }
    return 0;
}

void limpiarSistema() {

    ManejadorPropietarios::getInstance()->clear();
    ManejadorInmobiliarias::getInstance()->clear();
    ManejadorPublicaciones::getInstance()->clear();
    ManejadorInmuebles::getInstance()->clear();
    ManejadorClientes::getInstance()->clear();
    ControladorSistema::getInstance()->liberarInstanciaSistema();
    Factory::getInstance()->liberarInstancia();
    CargaDatos::getInstance()->liberar();
    ControladorFechaActual::getInstance()->liberar();



}
