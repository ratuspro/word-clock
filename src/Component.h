#include <memory>

#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
   protected:
    class Core* _owner;
   public:
    Component(class Core* core);
};

#endif