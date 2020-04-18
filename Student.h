#ifndef OP_2_1_1_STUDENTAS_H
#define OP_2_1_1_STUDENTAS_H

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <random>
#include <chrono>
#include <list>
#include <deque>
#include <functional>

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
using std::istream;

//https://stackoverflow.com/questions/11415469/setup-stdvector-in-class-constructor
class Student {
private:
    string name;
    string surname;
    vector<double> nd;
    int exam;
    double res;
public:
    Student();
    virtual ~Student();

    const string &getName() const;
    const string &getSurname() const;
    const vector<double> &getNd() const;
    int getExam() const;
    double getRes() const; // get'eriai

    std::istream& readStudent(std::istream& in, int n);

    void setName(const string &name);
    void setSurname(const string &surname);
    void setNd(const vector<double> &nd);
    void setExam(int exam);
    void setRes(double res); // set'eriai

    /*
    friend std::istream& operator >>(std::istream& in, Student& s) {
        in >> s.name >> s.surname;
        in >> s.exam;
        for (int random_int; in >> random_int;) {
            s.nd.push_back(random_int);
        }
        return in;
    }
    bool operator<(const Student& other) const {
        return res < other.res;
    }
     */
    void sortNd() {
        sort(nd.begin(), nd.end());
    }
};

#endif