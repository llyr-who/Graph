all: source

#For debugging
OPT=-g -Wall
OBJECTS=AdjListGraph.h AdjMatrixGraph.h AdjMatrixMultiGraph.h Edge.h search.h

#For optimistaion
#OPT=-O

#All objects (except main) come from cpp and hpp 
%.o:	%.cpp %.hpp
	g++ ${OPT} -c -o $@ $<
#use_vectors relies on objects which rely on headers
source:		source.cpp ${OBJECTS}
		g++ ${OPT} ${OBJECTS} -o source source.cpp 
clean:
	rm -f *.o *~ source
