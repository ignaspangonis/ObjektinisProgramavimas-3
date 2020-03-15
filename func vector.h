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

void DuomenuKurimas(int y, vector<Student> &stud);
void FailuKurimas (int x, int y, vector<Student> &stud);
void FailuKurimas2 (vector<Student> &stud, std::ofstream &fail, std::ofstream &mldc);
void Input(vector<Student> &stud);
void Calculate(vector<Student> &stud);
void Print(vector<Student> &stud);

#endif
