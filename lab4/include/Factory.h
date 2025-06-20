#ifndef FACTORY_H
#define FACTORY_H
#include "IControladorSistema.h"
#include "IControladorFechaActual.h"

class Factory {
    private:
        static Factory* instance;
        Factory();
    public:
        static Factory* getInstance();
        IControladorFechaActual* getControladorFechaActual();
        IControladorSistema* getControladorSistema();
        static void liberarInstancia();
        ~Factory();
};

#endif
