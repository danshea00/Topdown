set(C_SOURCES main.cpp Bullet.cpp Game.cpp input.cpp Player.cpp Entity.cpp EntityManager.cpp PlayingEntity.cpp)
set(C_HEADERS Bullet.h Game.h input.h Player.h Entity.h EntityManager.h PlayingEntity.h)

add_executable(topdown ${C_SOURCES} ${C_HEADERS})