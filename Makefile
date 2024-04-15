proj3 : Project3.o Account.o
	g++ -o proj3 Project3.o Account.o

Account.o : Account.cpp Account.h
	g++ -c -Wall Account.cpp

Project3.o : Project3.cpp Account.h
	g++ -c -Wall Project3.cpp

clean :
	rm *.o proj3