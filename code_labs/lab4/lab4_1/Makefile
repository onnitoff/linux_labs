#MakeFile

main: main.o lib/lib_business_logic.a
	g++ -o main main.o -L. lib/lib_business_logic.a
	
main.o:
	g++ -c main.cpp

clean:
	rm -f *.o
	rm -f main
