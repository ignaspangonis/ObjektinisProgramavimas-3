#include "Student.h"

class Student;

Student::Student(string name_, string surname_, vector<double> nd_, int exam_, double res_) : name(std::move(name_)), surname(std::move(surname_)), nd(std::move(nd_)), exam(exam_), res(res_) {}
Student::Student(string name_, string surname_, double res_) : name(std::move(name_)), surname(std::move(surname_)), res(res_) {}
Student::Student() = default;
Student::Student(string name_, string surname_) : name(std::move(name_)), surname(std::move(surname_)) {}
Student::Student(string name_, string surname_, vector<double> nd_, int exam_) : name(std::move(name_)), surname(std::move(surname_)), nd(std::move(nd_)), exam(exam_), res(0) {}

Student& Student::operator=(const Student& origin) {
    name = origin.name;
    surname = origin.surname;
    nd = origin.nd;
    exam = origin.exam;
    res = origin.res;
    return *this;
}

Student::Student(const Student &origin) {
    name = origin.name;
    surname = origin.surname;
    nd = origin.nd;
    exam = origin.exam;
    res = origin.res;
}

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
