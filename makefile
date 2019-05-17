appname := chip8
CXX := gcc
CXXFLAGS := -Wall -g -I/usr/local/include -L/usr/local/lib -lSDL2
SDLFLAGS := `sdl-config --cflags --libs`

src := chip8.cpp main.cpp
objects := chip8.o main.o

all: $(appname)

$(appname): $(objects)
	$(CXX) $(CXXFLAGS) $(SDLFLAGS) -o $(appname) $(objects) 

$(objects): $(src)

clean:
	rm -f $(objects)