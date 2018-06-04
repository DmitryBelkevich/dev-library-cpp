// В этом файле распологается реализация класса

#include "Entity.h"

Entity::Entity(const std::string &str) : str(str) {}

void Entity::print() {
    std::cout << str << std::endl;
}

Entity::~Entity() {

}
