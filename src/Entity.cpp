#include "Entity.h"
#include <stduuid/uuid.h>

Entity::Entity() : entityId(uuids::uuid_system_generator{}()) {}

Entity::~Entity() {}