main: func.o container.o struct.o
	g++ -o main main.cpp func.o container.o struct.o
func:
	g++ -c func.cpp
container:
	g++ -c container.cpp
struct:
	g++ -c struct.cpp
clean-win:
	del *.o main
clean-unix:
	rm *.o main
