#ifndef OP_2_0_3_FUNC_H
#define OP_2_0_3_FUNC_H
#include "Student.h"

void Input(vector<Student> &stud);
void Print(vector<Student> &stud);
void GenerateRandomFiles(int x, int y);

void CalculateV(vector<Student> &stud, bool isMed);
void CalculateL(list<Student> &stud, bool isMed);
void CalculateD(deque<Student> &stud, bool isMed);

void ReadSplitGenerateV(vector<Student> &stud, std::ofstream &fail, std::ofstream &mldc, bool strat, bool enhanced, int cycle);
void ReadSplitGenerateL(list<Student> &stud, std::ofstream &fail, std::ofstream &mldc, bool strat, int cycle);
void ReadSplitGenerateD(deque<Student> &stud, std::ofstream &fail, std::ofstream &mldc, bool strat, int cycle);

#endif