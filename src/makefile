#SRC=Cercle.cpp Liste.cpp Rectangle.cpp Forme.cpp Point.cpp main.cpp
SRC=Cercle.cpp Forme.cpp Point.cpp Rectangle.cpp tests_catch.cpp main_catch.cpp
#SRC=$(wildcard *.cpp) 
#SRC=Forme.cpp Point.cpp tests_catch.cpp main_catch.cpp
EXE=appli

CXXFLAGS+=-Wall -Wextra -MMD -g -O2 -fdiagnostics-color=auto --std=c++14
LDFLAGS= #-lSDL

OBJ=$(addprefix build/,$(SRC:.cpp=.o))
DEP=$(addprefix build/,$(SRC:.cpp=.d))

all: $(OBJ)
	$(CXX) -o $(EXE) $^ $(LDFLAGS)

build/%.o: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch

-include $(DEP)
