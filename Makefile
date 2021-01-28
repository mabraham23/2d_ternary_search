CXXFLAGS := -std=c++11

all: ternary_search

bash_tests: ternary.bash ternary_search
	./ternary.bash

ternary_search: ternary_search.cpp
	g++ $(CXXFLAGS) -o $@ $^

clean:
	-rm -f ternary_search
