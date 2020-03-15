#ifndef OP_2_0_3_FUNC_H
#define OP_2_0_3_FUNC_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <random>
#include <list>
#include <iterator>
#include <deque>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::sort;
using std::setprecision;
using std::setw;
using std::left;
using std::ifstream;
using std::list;

void DuomenuKurimas(int y, list<Student> &stud);
void FailuKurimas (int x, int y, list<Student> &stud);
void FailuKurimas2 (list<Student> &stud, std::ofstream &fail, std::ofstream &mldc);
void Input(list<Student> &stud);
void Calculate(list<Student> &stud);
void Print(list<Student> &stud);

#endif
