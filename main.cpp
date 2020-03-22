#include "struct.h"
#include "func.h"
#include "container.h"

int main() {
    bool x;
    cout << "Norite matuoti programos veikimo sparta su skirtingais konteineriais (iveskite 0), ar paleisti programa (iveskite 1)?" << endl;
    cin >> x;
    while (!std::cin) {
        std::cin.clear(); // reset failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
        cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
             << std::endl;
        cin >> x;
    }

    if (x == 0) { // jei pasirinko matuoti
        char cont;
        cout << "Konteineris - vector (v), list (l), deque (d)?: " << endl;
        cin >> cont;
        while (!(cont == 'v' || cont == 'l' || cont == 'd')) {
            std::cin.clear(); // reset failbit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
                 << std::endl;
            cin >> cont;
        }
        if (cont == 'v') {
            Vec();
        } else if (cont == 'l') {
            Lis();
        } else if (cont == 'd') {
            Deq();
        }

    } else { // jei pasirinko paleisti programa
        vector<Student> stud;
        stud.reserve(150);
        Input(stud);
        stud.shrink_to_fit();
        sort(begin(stud), end(stud), [](const Student &a1, const Student &a2) {
            return a1.surname.compare(a2.surname) < 0;
        });
        CalculateV(stud);
        PrintV(stud);
        return 0;
    }
}