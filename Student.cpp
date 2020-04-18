#include "Student.h"

class Student;

Student::Student() {}
Student::~Student() {}

// get'eriai:
const string &Student::getName() const {
    return name;
}
const string &Student::getSurname() const {
    return surname;
}
const vector<double> &Student::getNd() const {
    return nd;
}
int Student::getExam() const {
    return exam;
}
double Student::getRes() const {
    return res;
}

// set'eriai:
std::istream &Student::readStudent(std::istream &in, int n) {
    in >> name >> surname;
    nd.clear();
    nd.reserve(n);
    in >> exam;
    for (int random_int = 0; in >> random_int;) {
        nd.push_back(random_int);
    }
    nd.shrink_to_fit();
}
void Student::setName(const string &name) {
    Student::name = name;
}
void Student::setSurname(const string &surname) {
    Student::surname = surname;
}
void Student::setNd(const vector<double> &nd) {
    Student::nd = nd;
}
void Student::setExam(int exam) {
    Student::exam = exam;
}
void Student::setRes(double res) {
    Student::res = res;
}