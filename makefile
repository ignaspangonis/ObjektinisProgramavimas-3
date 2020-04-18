main: func.o container.o 
	g++ -o main main.cpp func.o container.o
func:
	g++ -c func.cpp
container:
	g++ -c container.cpp
clean-win:
	del *.o main
clean-unix:
	rm *.o main
