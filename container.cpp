#include "container.h"

void Vec(bool strat, bool enhanced, int cycle) {
    int y = 100;
    vector<Student> stud;

    for (int i = 0; i < cycle; i++) {
        y = y * 10;
        cout << endl << "Kuriamas sarasas is " << y << " studentu." << endl;
        GenerateRandomFilesV(i, y, stud);
    }
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
    int y = 100;
    list<Student> stud;

    for (int i = 0; i < cycle; i++) {
        y = y * 10;
        cout << endl << "Kuriamas sarasas is " << y << " studentu." << endl;
        GenerateRandomFilesL(i, y, stud);
    }
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
    int y = 100;
    deque<Student> stud;

    for (int i = 0; i < cycle; i++) {
        y = y * 10;
        cout << endl << "Kuriamas sarasas is " << y << " studentu." << endl;
        GenerateRandomFilesD(i, y, stud);
    }
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