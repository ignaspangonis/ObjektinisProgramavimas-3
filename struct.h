#ifndef OP_2_0_3_STRUCT_H
#define OP_2_0_3_STRUCT_H

#include <string>
#include <vector>

using std::string;
using std::vector;

struct Student {
    string name;
    string surname;
    vector<double> nd;
    int exam;
    double res;
};

#endif

