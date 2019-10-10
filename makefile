
CC = g++ 
OBJECTS = main.o graph.o city.o
EXE = prog1 

$(EXE):		$(OBJECTS)
		$(CC) -o $(EXE) $(OBJECTS)

main.o: 	main.cpp graph.h city.h
		$(CC) -c main.cpp 

graph.o: 	graph.cpp graph.h city.h 
		$(CC) -c graph.cpp 
		
city.o:		city.cpp city.h
		$(CC) -c city.cpp 		
	
clean: 		
		rm -rf prog1 *~ $(OBJECTS) $(EXE) 
