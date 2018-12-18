
CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

Projet: main.o 
	$(CXX) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o *~ core 


