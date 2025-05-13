EXEC = simulation

SRC = Simulation.cpp Animal.cpp Mouton.cpp Loup.cpp Case.cpp Univers.cpp

OBJ = $(SRC:.cpp=.o)

CXX = g++
CXXFLAGS = -Wall -std=c++11

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
