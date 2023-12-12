# MakeFile

main: main.o model.o controller.o view.o
	g++ -o main main.o model.o controller.o view.o

main.o: main.cpp controller.h
	g++ -c main.cpp
	
model.o: model.cpp model.h
	g++ -c model.cpp

view.o: view.cpp view.h
	g++ -c view.cpp

controller.o: controller.cpp controller.h
	g++ -c controller.cpp
	

clean:
	rm -f *.o
	rm -f main


