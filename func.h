#ifndef OP_2_0_3_FUNC_H
#define OP_2_0_3_FUNC_H
#include "Student.h"

void GenerateRandomFiles(int x, int y);
void ReadSplitGenerateV(vector<Student> &stud, std::ofstream &fail, std::ofstream &mldc, bool strat, bool enhanced, int cycle);
void Input(vector<Student> &stud);
void CalculateV(vector<Student> &stud, bool isMed);
void PrintV(vector<Student> &stud);

void ReadSplitGenerateL(list<Student> &stud, std::ofstream &fail, std::ofstream &mldc, bool strat, int cycle);
void CalculateL(list<Student> &stud, bool isMed);

void ReadSplitGenerateD(deque<Student> &stud, std::ofstream &fail, std::ofstream &mldc, bool strat, int cycle);
void CalculateD(deque<Student> &stud, bool isMed);

#endif