appname := chip8
CXX := gcc
CXXFLAGS := -Wall -g
# -I/usr/local/include -L/usr/local/lib -lSDL2
# For macOS
# SDLFLAGS := `sdl-config --cflags --libs`
# For Ubuntu
SDLFLAGS := `pkg-config --cflags --libs sdl2`

src := chip8.cpp main.cpp
objects := chip8.o main.o

all: $(appname)

$(appname): $(objects)
	$(CXX) $(SDLFLAGS) $(CXXFLAGS) -o $(appname) $(objects) -lSDL2

$(objects): $(src)

clean:
	rm -f $(objects)