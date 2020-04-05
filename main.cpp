#include "struct.h"
#include "func.h"
#include "container.h"

int main() {
    bool x;
    cout << "Norite matuoti programos veikimo sparta su skirtingais konteineriais (iveskite 0), ar paleisti programa (iveskite 1)?" << endl;
    cin >> x;
    while (!std::cin) {
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
        cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
             << std::endl;
        cin >> x;
    }

    if (x == 0) { // jei pasirinko matuoti
        char cont;
        bool strat;
        int cycle;

        cout << "Programos matavimo strategija - pirma (iveskite 0), antra (iveskite 1)?" << endl;
        cin >> strat;
        while (!cin) {
            cin.clear(); // reset failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
                 << std::endl;
            cin >> strat;
        }



        cout << "Konteineris - vector (v), list (l), deque (d)?: " << endl;
        cin >> cont;
        while (!(cont == 'v' || cont == 'l' || cont == 'd')) {
            cin.clear(); // reset failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
                 << std::endl;
            cin >> cont;
        }
        cout << "Kiek failu generuoti (1-5)?: " << endl;
        cin >> cycle;
        while (cycle < 1 || cycle > 5) {
            cin.clear(); // reset failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
                 << std::endl;
            cin >> cycle;
        }


        if (cont == 'v') {
            bool enhanced = false;
            if (strat) {
                cout << "Norite naudoti studentu skirstyma spartinancius algoritmus (1), ar ne (0)?"
                     << endl;
                cin >> enhanced;
                while (!cin) {
                    cin.clear(); // reset failbit
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                    cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
                         << std::endl;
                    cin >> enhanced;
                }
            }
            Vec(strat, enhanced, cycle);
        } else if (cont == 'l') {
            Lis(strat, cycle);
        } else if (cont == 'd') {
            Deq(strat, cycle);
        }

    } else { // jei pasirinko paleisti programa
        vector<Student> stud;
        bool med;
        stud.reserve(150);
        Input(stud);
        stud.shrink_to_fit();
        sort(begin(stud), end(stud), [](const Student &a1, const Student &a2) {
            return a1.surname.compare(a2.surname) < 0;
        });
        cout << "Norite skaiciuoti pagal vidurki (iveskite 0), ar mediana (iveskite 1)?" << endl;
        cin >> med;
        while (!cin) {
            cin.clear(); // reset failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
                 << std::endl;
            cin >> med;
        }
        CalculateV(stud, med);
        PrintV(stud);
        return 0;
    }
}