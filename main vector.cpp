#include "struct.h"
#include "func.h"

int main() {
    bool x;
    cout << "Norite matuoti programos veikimo sparta (iveskite 0), ar paleisti programa (iveskite 1)?" << endl;
    cin >> x;
    while (!std::cin) {
        std::cin.clear(); // reset failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
        cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
             << std::endl;
        cin >> x;
    }
    if (x == 0) {
        int y = 100;
        vector<Student> stud;
        clock_t start, end;
        for (int i = 0; i < 5; i++) {

            y = y * 10;
            cout << endl << "Kuriamas sarasas is " << y << " studentu." << endl;
            stud.clear();
            stud.reserve(y);
            start = clock();
            DuomenuKurimas(y, stud);
            FailuKurimas(i, y, stud);
            end = clock();
            cout << "Duomenu kurimo ir failo is " << y << " irasu kurimo laikas: " << std::setprecision(4) << 1.0*(end - start)/ CLOCKS_PER_SEC << " sec." << endl;
        }
        std::ofstream fail("neislaike.txt");
        std::ofstream mldc("islaike.txt");
        if (fail.is_open() && mldc.is_open()) {
            stud.clear();
            FailuKurimas2(stud, fail, mldc);
            fail.close();
            mldc.close();
        } else {
            cout << "Failo atidarymas nepavyko!" << endl;
        }
    } else {
        vector<Student> stud;
        stud.reserve(150);
        Input(stud);
        stud.shrink_to_fit();
        sort(begin(stud), end(stud), [](const Student &a1, const Student &a2) {
            return a1.surname.compare(a2.surname) < 0;
        });
        Calculate(stud);
        Print(stud);

        return 0;
    }
}