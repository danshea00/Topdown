#include "Entity.h"

Entity::Entity() {}

Entity::~Entity() {}

void Entity::setId(int newId)
{
    id = newId;
}

int Entity::getId()
{
    return id;
}