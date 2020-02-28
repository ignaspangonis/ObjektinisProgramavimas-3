#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::sort;
using std::setprecision;
using std::setw;
using std::left;
using std::ifstream;

struct Student {
    string name;
    string surname;
    vector<double> nd;
    int exam;
    double avg = 0;
    double med;
    double res_avg;
    double res_med;
};

void Input(vector<Student> &stud) {
    bool cont = true;
    int x;
    bool random;
    int n = 0;
    bool file;

    cout << "Ar norite skaityti duomenis is failo? 0 - ne, 1 - taip." << endl;
    while (true) {
        cin >> file;
        if (!std::cin) {
            std::cin.clear(); // reset failbit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
                 << std::endl;
            continue;
        }
        break;
    }

    if (file) {
        ifstream fin;
        string line;
        string ignore_s;
        string dest;
        int random_int;

        cout << "Iveskite teksto failo varda (pvz kursiokai.txt):" << endl;
        cin >> dest;
        fin.open(dest);

        if (!fin) {
            cout << "Failo atidarymas nepavyko!";
            exit(1);   // call system to stop
        }

        for (int l = -1; std::getline(fin, line); l++) {
            std::istringstream iss(line);
            if (l == -1) {
                iss >> ignore_s >> ignore_s;
                for (; ; n++) {
                    if (!(iss >> ignore_s)) {
                        n -= 1;
                        break;
                    }
                }
                continue;
            }
            stud.push_back(Student());
            if (!(iss >> stud[l].name >> stud[l].surname)) { break; }
            for (int k = 0; k < n; k++) {
                if (!(iss >> random_int)) { break; } else {
                    stud[l].nd.push_back(random_int);
                }
            }
            if (!(iss >> stud[l].exam)) { break; }
        }
        fin.close();
    } else {
        for (int i = 0; cont; i++) {
            stud.push_back(Student());
            cout << "Iveskite varda: " << std::endl;
            cin >> stud[i].name;
            cout << "Iveskite pavarde: " << std::endl;
            cin >> stud[i].surname;

            cout << "Ar norite atsitiktinai generuojamu pazymiu? 0 - ne, 1 - taip." << endl;
            while (true) {
                cin >> random;
                if (!std::cin) {
                    std::cin.clear(); // reset failbit
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                    cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
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
                stud[i].nd.shrink_to_fit();
                stud[i].exam = (1 + rand() % 10);
                cout << "Sekmingai sugeneruota!" << endl;
            } else {

                cout << "Iveskite studento pazymius 10-baleje sistemoje (jei norite baigti - iveskite 0): "
                     << endl;
                while (true) {
                    cin >> x;
                    if (!cin || x > 10 || x < 0) {
                        cin.clear(); // reset failbit
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                        cout << "Neteisingai ivestas skaicius, iveskite dar karta (jei norite baigti - iveskite 0)!"
                             << std::endl;
                        continue;
                    }
                    if (x == 0) {
                        if (stud[i].nd.empty()) {
                            cout << "Neivedete jokiu pazymiu!" << endl;
                            continue;
                        } else {
                            break;
                        }
                    } else {
                        stud[i].nd.push_back(x);
                    }
                }
                stud[i].nd.shrink_to_fit(); // optimizuoja vektoriaus dydi atmintyje


                cout << "Iveskite studento egzamino vertinima 10-baleje sistemoje: " << endl;
                while (true) {
                    cin >> x;
                    if (!cin || x > 10 || x < 1) {
                        cin.clear(); // reset failbit
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                        cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
                             << std::endl;
                        continue;
                    }
                    stud[i].exam = x;
                    break;
                }
            }

            cout << "Ar bus dar vienas studentas? Iveskite 1 jei taip, 0 jei ne." << std::endl;
            while (true) {
                cin >> cont;
                if (!cin) {
                    cin.clear(); // reset failbit
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                    cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
                         << std::endl;
                    continue;
                }
                break;
            }
        }
    }
}

void Calculate(vector<Student> &stud) {
    for (int i = 0; i < stud.size(); i++) {
        // mediana:
        sort(stud[i].nd.begin(), stud[i].nd.end());
        if (stud[i].nd.size() % 2 != 0) {
            stud[i].med = stud[i].nd[stud[i].nd.size() / 2];
        } else {
            stud[i].med = (stud[i].nd[(stud[i].nd.size() / 2) - 1] +
                    stud[i].nd[stud[i].nd.size() / 2]) / 2.0;
        }
        stud[i].res_med = 0.4 * stud[i].med + 0.6 * stud[i].exam;
        // vidurkis:
        for (int j = 0; j < stud[i].nd.size(); j++) {
            stud[i].avg += stud[i].nd[j];
        }
        stud[i].avg /= stud[i].nd.size();
        stud[i].res_avg = 0.4 * stud[i].avg + 0.6 * stud[i].exam;
    }
}

void Print(vector<Student> &stud) {
    cout << "\nPavarde             Vardas              Galutinis (Vid.)  Galutinis (Med.)\n" <<
             "----------------------------------------------------------------------------" << std::endl;

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
        cout << std::fixed << setprecision(2) << stud[i].res_avg;
        cout << "              ";
        cout << std::fixed << setprecision(2) << stud[i].res_med << endl;
    }
}

int main() {
    vector<Student> stud;
    bool med;
    stud.reserve(150);
    Input(stud);
    stud.shrink_to_fit();
    sort(begin(stud), end(stud), [](const Student &a1, const Student &a2 ) {
        return a1.surname.compare(a2.surname) < 0;
    });
    Calculate(stud);
    Print(stud);
    return 0;
}