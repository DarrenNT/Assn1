Dictionary: Dictionary.o
	g++ Dictionary.o -o Dictionary
Dictionary.o: Dictionary.cpp
	g++ -c Dictionary.cpp
clean:
	rm *.o Dictionary
