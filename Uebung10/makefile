CXX        = g++  
CXXFLAGS   = -ansi -pedantic -Wall -Wextra -Wfatal-errors -std=c++11 -g -pthread
 
SRCS = Aufgabe10_1.cpp
OBJS = $(SRCS:.cpp=.o)
 
Aufgabe10_1.exe: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
 
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
 
%.exe:%.cpp
	$(CXX) $(CXXFLAGS) -o $@  $<
 
clean:
	rm -f $(BINS)