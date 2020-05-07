#include "Student.h"

class Person;
class Student;

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
void Student::setName(const string &name_) {
    Student::name = name_;
}
void Student::setSurname(const string &surname_) {
    Student::surname = surname_;
}
void Student::setNd(const vector<double> &nd_) {
    Student::nd = nd_;
}
void Student::setExam(int exam_) {
    Student::exam = exam_;
}
void Student::setRes(double res_) {
    Student::res = res_;
}