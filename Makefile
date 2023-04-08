# Set the name of your executable file
TARGET = game

# Set the path to your SFML directory
SFML_PATH = /opt/homebrew/Cellar/sfml/2.5.1_2/

# Set your compiler and flags
CC = g++
CFLAGS = -std=c++11 -Wall -I$(SFML_PATH)/include -lsfml-graphics -lsfml-window -lsfml-system
LFLAGS = -L$(SFML_PATH)/lib -lsfml-graphics -lsfml-window -lsfml-system

# List your source files
SOURCES = main.cpp input.cpp Player.cpp Game.cpp Bullet.cpp

# Set the name of the object files
OBJECTS = $(SOURCES:.cpp=.o)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LFLAGS)

# Build the object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the object files and executable
clean:
	rm -f $(OBJECTS) $(TARGET)
