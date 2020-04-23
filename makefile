main: func.o container.o Student.o
	g++ -o main main.cpp func.o container.o Student.o
func:
	g++ -c func.cpp
container:
	g++ -c container.cpp
Student:
	g++ -c Student.cpp
clean-win:
	del *.o main
clean-unix:
	rm *.o main
