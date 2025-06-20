
#include "ManejadorPublicaciones.h"
#include "Publicacion.h"

ManejadorPublicaciones* ManejadorPublicaciones::instancia = 0;

ManejadorPublicaciones::ManejadorPublicaciones() {}

ManejadorPublicaciones::~ManejadorPublicaciones() {
    std::map<int, Publicacion*>::iterator it;
    for (it = pubs.begin(); it != pubs.end(); ++it) {
        delete it->second;
    }
    pubs.clear();
}

ManejadorPublicaciones* ManejadorPublicaciones::getInstance() {
    if (instancia == 0) {
        instancia = new ManejadorPublicaciones();
    }
    return instancia;
}

void ManejadorPublicaciones::agregar(Publicacion* p) {
    int key = p->getCodigo();  
    // insert devuelve un par<iterador, bool>
    auto [it, inserted] = pubs.insert({ key, p });
    if (!inserted) {
        // Ya existía esa clave; si querés reemplazar el puntero:
        it->second = p;
    }
}

Publicacion* ManejadorPublicaciones::find(int codigo) {
    return pubs[codigo];
}

std::set<Publicacion*> ManejadorPublicaciones::getAll() {
    std::set<Publicacion*> salida;
    std::map<int, Publicacion*>::iterator it;
    for (it = pubs.begin(); it != pubs.end(); ++it) {
        if (it->second != nullptr){
            salida.insert(it->second);
        }
    }
    return salida;
}
void ManejadorPublicaciones::clear() {
    delete instancia;
    instancia = NULL;
}

void ManejadorPublicaciones::borrar(int codigo) {
    auto it = pubs.find(codigo);
    if (it != pubs.end()) {
        delete it->second;
        pubs.erase(it);
    }
}
