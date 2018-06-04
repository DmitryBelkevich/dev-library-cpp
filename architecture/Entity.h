// В этом файле распологается интерфейс класса

//#pragma once    // для Visual Studio

#ifndef DEV_LIBRARY_CPP_ENTITY_H
#define DEV_LIBRARY_CPP_ENTITY_H

#include <iostream>

class Entity {
private:
    std::string str = "Hello World";
public:
    Entity(const std::string &str);

    void print();

    virtual ~Entity();
};


#endif //DEV_LIBRARY_CPP_ENTITY_H
