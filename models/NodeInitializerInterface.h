#ifndef CASO_7_NODEINITIALIZERINTERFACE_H
#define CASO_7_NODEINITIALIZERINTERFACE_H

#include "Node.h"
#include "vector"

//interface
class NodeInitializerInterface {

    virtual std::vector<Node*> createNodes() = 0;
    virtual void linkNodes(std::vector<Node*> &pNodes) = 0;

};

#endif //CASO_7_NODEINITIALIZERINTERFACE_H
