#MakeFile

main: main.o lib/lib_business_logic.so
	g++ -o main main.o -Ilib -Llib lib/lib_business_logic.so -Wl,-rpath=/home/onnitoff/lab4/lab4_2/lib
	
main.o:
	g++ -c main.cpp

clean:
	rm -f *.o
	rm -f main
