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
#include <chrono>
#include <list>
#include <deque>
#include "struct.h"

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
using std::deque;

void GenerateRandomFilesV(int x, int y, vector<Student> &stud);
void ReadSplitGenerateV(vector<Student> &stud, std::ofstream &fail, std::ofstream &mldc);
void Input(vector<Student> &stud);
void CalculateV(vector<Student> &stud);
void PrintV(vector<Student> &stud);


void GenerateRandomFilesL(int x, int y, list<Student> &stud);
void ReadSplitGenerateL(list<Student> &stud, std::ofstream &fail, std::ofstream &mldc);
void CalculateL(list<Student> &stud);


void GenerateRandomFilesD(int x, int y, deque<Student> &stud);
void ReadSplitGenerateD(deque<Student> &stud, std::ofstream &fail, std::ofstream &mldc);
void CalculateD(deque<Student> &stud);

#endif
