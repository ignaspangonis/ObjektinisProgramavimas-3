#include "container.h"

void Vec(bool strat, bool enhanced, int cycle) {
    std::vector<Student> stud;
    std::ofstream fail("neislaike.txt");
    std::ofstream mldc("islaike.txt");
    if (fail.is_open() && mldc.is_open()) {
        stud.clear();
        ReadSplitGenerateV(stud, fail, mldc, strat, enhanced, cycle);
        fail.close();
        mldc.close();
    } else {
        cout << "Failo atidarymas nepavyko!" << endl;
    }
}

void Lis(bool strat, int cycle) {
    list<Student> stud;
    std::ofstream fail("neislaike.txt");
    std::ofstream mldc("islaike.txt");
    if (fail.is_open() && mldc.is_open()) {
        stud.clear();
        ReadSplitGenerateL(stud, fail, mldc, strat, cycle);
        fail.close();
        mldc.close();
    } else {
        cout << "Failo atidarymas nepavyko!" << endl;
    }
}

void Deq(bool strat, int cycle) {
    deque<Student> stud;
    std::ofstream fail("neislaike.txt");
    std::ofstream mldc("islaike.txt");
    if (fail.is_open() && mldc.is_open()) {
        stud.clear();
        ReadSplitGenerateD(stud, fail, mldc, strat, cycle);
        fail.close();
        mldc.close();
    } else {
        cout << "Failo atidarymas nepavyko!" << endl;
    }
}