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
        deque<Student> stud;
        for (int i = 0; i < 5; i++) {
            y = y * 10;
            cout << endl << "Kuriamas sarasas is " << y << " studentu." << endl;
            stud.clear();
            DuomenuKurimas(y, stud);
            FailuKurimas(i, y, stud);
//            cout << "Duomenu kurimo ir failo is " << y << " irasu kurimo laikas: " << std::setprecision(4)
//                 << 1.0 * (end - start) / CLOCKS_PER_SEC << " sec." << endl;
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
        deque<Student> stud;
        Input(stud);
        Calculate(stud);
        Print(stud);

        return 0;
    }
}