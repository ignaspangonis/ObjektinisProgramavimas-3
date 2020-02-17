#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::sort;
using std::setprecision;
using std::setw;
using std::left;

struct Student {
    string name;
    string surname;
    vector<int> nd;
    int exam;
    double avg = 0;
    double med;
    double res;
};

void Input(vector<Student> &stud) {
    bool cont = true;
    int x;
    bool random;
    int n;

    for (int i = 0; cont; i++) {
        stud.push_back(Student());
        std::cout << "Iveskite varda: " << std::endl;
        std::cin >> stud[i].name;
        std::cout << "Iveskite pavarde: " << std::endl;
        std::cin >> stud[i].surname;

        cout << "Ar norite atsitiktinai generuojamu pazymiu? 0 - ne, 1 - taip." << endl;
        while (true) {
            cin >> random;
            if (!std::cin) {
                std::cin.clear(); // reset failbit
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                std::cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
                          << std::endl;
                continue;
            }
            break;
        }


        if (random) {
            srand(time(0));
            cout << "Iveskite studento namu darbu pazymiu skaiciu:" << endl;
            cin >> n;
            for (int j = 0; j < n; j++) {
                stud[i].nd.push_back((1 + rand() % 10));
            }
            cout << "Sekmingai sugeneruota!" << endl;
        } else {

            std::cout << "Iveskite studento pazymius 10-baleje sistemoje (jei norite baigti - iveskite 0): "
                      << std::endl;
            while (true) {
                std::cin >> x;
                if (!std::cin || x > 10 || x < 0) {
                    std::cin.clear(); // reset failbit
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                    std::cout << "Neteisingai ivestas skaicius, iveskite dar karta (jei norite baigti - iveskite 0)!"
                              << std::endl;
                    continue;
                }
                if (x == 0) {
                    if (stud[i].nd.empty()) {
                        std::cout << "Neivedete jokiu pazymiu!" << std::endl;
                        continue;
                    } else {
                        break;
                    }
                } else {
                    stud[i].nd.push_back(x);
                }
            }
            stud[i].nd.shrink_to_fit(); // optimizuoja vektoriaus dydi atmintyje


            std::cout << "Iveskite studento egzamino vertinima 10-baleje sistemoje: " << std::endl;
            while (true) {
                std::cin >> x;
                if (!std::cin || x > 10 || x < 1) {
                    std::cin.clear(); // reset failbit
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                    std::cout << "Neteisingai ivestas skaicius, iveskite dar karta (jei norite baigti - iveskite 0)!"
                              << std::endl;
                    continue;
                }
                stud[i].exam = x;
                break;
            }
        }

        std::cout << "Ar bus dar vienas studentas? Iveskite 1 jei taip, 0 jei ne." << std::endl;
        while (true) {
            std::cin >> cont;
            if (!std::cin) {
                std::cin.clear(); // reset failbit
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                std::cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
                          << std::endl;
                continue;
            }
            break;
        }
    }

}

void Calculate(vector<Student> &stud, bool m) {
    if (m) {
        for (int i = 0; i < stud.size(); i++) {
            sort(stud[i].nd.begin(), stud[i].nd.end());

            if (stud[i].nd.size() % 2 != 0) {
                stud[i].med = (double) stud[i].nd[stud[i].nd.size() / 2];
            } else {
                stud[i].med = ((double) stud[i].nd[ (stud[i].nd.size() / 2) - 1] +
                        (double) stud[i].nd[stud[i].nd.size() / 2]) / 2.0;
            }
            stud[i].res = 0.4 * stud[i].med + 0.6 * stud[i].exam;
        }
    } else {
        for (int i = 0; i < stud.size(); i++) {
            for (int j = 0; j < stud[i].nd.size(); j++) {
                stud[i].avg += (double) stud[i].nd[j];
            }
            stud[i].avg /= (double) stud[i].nd.size();
            stud[i].res = 0.4 * stud[i].avg + 0.6 * stud[i].exam;
        }
    }
}

void Print(vector<Student> &stud, bool m) {
    if (m) {
        cout << "\nPavarde             Vardas              Galutinis (Med.)\n" <<
             "------------------------------------------------------------" << std::endl;
    } else {
        cout << "\nPavarde             Vardas              Galutinis (Vid.)\n" <<
             "------------------------------------------------------------" << std::endl;
    }
    for (int i = 0; i < stud.size(); i++) {
        printf("%.18s", stud[i].surname.c_str());
        if ((int) stud[i].surname.length() > 18) {
            cout << "- ";
        } else {
            for (int j = 20; (int) (j - ((int) stud[i].surname.length())) > 0; j--) {
                cout << " ";
            }
        }
        printf("%.18s", stud[i].name.c_str());
        if ((int) stud[i].name.length() > 18) {
            cout << "- ";
        } else {
            for (int j = 20; (int) (j - ((int) stud[i].name.length())) > 0; j--) {
                cout << " ";
            }
        }
        cout << std::fixed << setprecision(2) << stud[i].res << endl;
    }
}


//double average (const int *paz, size_t n) {
//    int avg = 0;
//    for (int i = 0; i < n; i++) {
//        avg += paz[i];
//    }
//    return (double) avg / (double) n;
//}

int main() {
    //int x;
    //double avg;
    //std::vector<double> res;
    //bool end;
    vector<Student> stud;
    bool med;
    stud.reserve(150);
    //bool cont = true;


    Input(stud);
    cout << "Ar norite galutini pazymi skaiciuoti pagal pazymiu vidurki (iveskite 0) ar mediana (iveskite 1): ";
    while (true) {
        std::cin >> med;
        if (!std::cin) {
            std::cin.clear(); // reset failbit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            std::cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
                      << std::endl;
            continue;
        }
        break;
    }
    stud.shrink_to_fit();
    Calculate(stud, med);
    Print(stud, med);

    return 0;
}