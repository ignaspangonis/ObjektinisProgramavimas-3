#include "struct.h"
#include "func.h"

void DuomenuKurimas(int y, deque<Student> &stud) {
    int ran, sum;
    int size = 5;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 10);
    for (int i = 0; i < y; i++) {
        sum = 0;
        stud.push_back(Student());
        stud.back().nd.reserve(size);
        stud.back().name = "Vardenis" + std::to_string(i + 1);
        stud.back().surname = "Pavardenis" + std::to_string(i + 1);
        for (int j = 0; j < size; j++) {
            ran = dist(rng);
            stud.back().nd.push_back(ran);
            sum += ran;
        }
        ran = dist(rng);
        stud.back().exam = ran;
        // stud[i].res_avg = ( (double) sum / size) * 0.4 + stud[i].exam * 0.6;
    }
}

void FailuKurimas2(deque<Student> &stud, std::ofstream &fail, std::ofstream &mldc) {
    clock_t start, end;
    ifstream fin;
    string line;
    string ignore_s;
    string dest;
    int random_int;
    int n;
    int y = 100;
    deque<SimpleStudent> geri;
    deque<SimpleStudent> blogi;
    cout << endl;
    for (int m = 1; m <= 5; m++) {
        n = 0;
        start = clock();
        fin.open("sarasas" + std::to_string(m) + ".txt");
        if (!fin.is_open()) {
            cout << "Nepavyko failo atidarymas" << endl;
            break;
        }
        y *= 10;
        for (int l = -1; std::getline(fin, line); l++) {
            std::istringstream iss(line);
            if (l == -1) {
                if (!(iss >> ignore_s >> ignore_s)) {
                    break;
                }
                for (;; n++) {
                    if (!(iss >> ignore_s)) {
                        n -= 1;
                        break;
                    }
                }
                continue;
            }
            stud.push_back(Student());
            if (!(iss >> stud.back().name >> stud.back().surname)) {
                break;
            }
            for (int k = 0; k < n; k++) {
                if (!(iss >> random_int)) {
                    break;
                } else {
                    stud.back().nd.push_back(random_int);
                }
            }
            if (!(iss >> stud.back().exam)) {
                break;
            }
        } //irasom i studentu vektoriu

        end = clock();
        cout << "Failu nuskaitymo is failo (su " << y << " irasu) laikas: "
             << std::setprecision(4) << 1.0 * (end - start) / CLOCKS_PER_SEC << " sec." << endl;

        Calculate(stud); // suskaiciuojam vidurki

        start = clock();
        deque<Student>::iterator itt;
        for (itt = stud.begin(); itt != stud.end(); itt++) {
            if (itt->res_avg < 5) {
                blogi.push_back(SimpleStudent());
                blogi.back().name = itt->name;
                blogi.back().surname = itt->surname;
                blogi.back().res_avg = itt->res_avg;
            } else {
                geri.push_back(SimpleStudent());
                geri.back().name = itt->name;
                geri.back().surname = itt->surname;
                geri.back().res_avg = itt->res_avg;
            }
        } // isskirstom vektoriu i du vektorius

        end = clock();
        cout << "Failo (su " << y << " irasu) rusiavimo i dvi grupes laikas: "
             << std::setprecision(4) << 1.0 * (end - start) / CLOCKS_PER_SEC << " sec." << endl << endl;

        start = clock();
        fail << y << " studentu:" << endl << endl;
        fail << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde" << left << std::setw(15)
             << "Galutinis (vid.)" << endl;
        mldc << y << " studentu:" << endl << endl;
        mldc << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde" << "Galutinis (vid.)" << endl;

        deque<SimpleStudent>::iterator it;
        for (it = geri.begin(); it != geri.end(); it++) {
            mldc << left << std::setw(17) << it->name << left << std::setw(19) << it->surname
                 << left << std::setw(17) << it->res_avg << endl;
        }
        for (it = blogi.begin(); it != blogi.end(); it++) {
            fail << left << std::setw(17) << it->name << left << std::setw(19) << it->surname
                 << left << std::setw(15) << it->res_avg << endl;
        }

        end = clock();
//        cout << "Studentu isvedimas i 2 failus is dvieju grupiu (su " << y << " irasu) laikas: "
//             << std::setprecision(4) << 1.0 * (end - start) / CLOCKS_PER_SEC << " sec." << endl << endl;

        mldc << endl;
        fail << endl;
        stud.clear();
        geri.clear();
        blogi.clear();
        fin.close();
    }
}

void FailuKurimas(int x, int y, deque<Student> &stud) {
    std::ofstream sarasas("sarasas" + std::to_string(x + 1) + ".txt");
    sarasas << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde";
    deque<Student>::iterator it;
    for (int i = 0; i < stud.back().nd.size(); i++) {
        sarasas << left << std::setw(10) << "ND" + std::to_string(i);
    }
    sarasas << left << std::setw(15) << "Egzaminas" << endl;
    for (it = stud.begin(); it != stud.end(); it++) {
        sarasas << left << std::setw(17) << it->name << left << std::setw(19) << it->surname;
        for (int j = 0; j < it->nd.size(); j++) {
            sarasas << left << std::setw(10) << it->nd[j];
        }
        sarasas << it->exam << endl;
    }
    sarasas.close();
}

void Input(deque<Student> &stud) {
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
        try {
            cin >> dest;
            fin.open(dest);
            if (!fin) {
                throw "Failo atidarymas nepavyko!\n";
            }
        } catch (const char *msg) {
            std::cerr << msg;
            exit(1);
        }

        for (int l = -1; std::getline(fin, line); l++) {
            std::istringstream iss(line);
            if (l == -1) {
                iss >> ignore_s >> ignore_s;
                for (;; n++) {
                    if (!(iss >> ignore_s)) {
                        n -= 1;
                        break;
                    }
                }
                continue;
            }
            stud.push_back(Student());
            if (!(iss >> stud.back().name >> stud.back().surname)) { break; }
            for (int k = 0; k < n; k++) {
                if (!(iss >> random_int)) { break; }
                else {
                    stud.back().nd.push_back(random_int);
                }
            }
            if (!(iss >> stud.back().exam)) { break; }
        }
        fin.close();
    } else {
        for (int i = 0; cont; i++) {
            stud.push_back(Student());
            cout << "Iveskite varda: " << std::endl;
            cin >> stud.back().name;
            cout << "Iveskite pavarde: " << std::endl;
            cin >> stud.back().surname;

            cout << "Ar norite atsitiktinai generuojamu pazymiu? 0 - ne, 1 - taip." << endl;
            cin >> random;
            while (!std::cin) {
                std::cin.clear(); // reset failbit
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
                     << std::endl;
                cin >> random;
            }

            if (random) {
                srand(time(0));
                cout << "Iveskite studento namu darbu pazymiu skaiciu:" << endl;
                cin >> n;
                while (!std::cin) {
                    std::cin.clear(); // reset failbit
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                    cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
                         << std::endl;
                    cin >> n;
                }
                for (int j = 0; j < n; j++) {
                    stud.back().nd.push_back((1 + rand() % 10));
                }
                stud.back().exam = (1 + rand() % 10);
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
                        if (stud.back().nd.empty()) {
                            cout << "Neivedete jokiu pazymiu!" << endl;
                            continue;
                        } else {
                            break;
                        }
                    } else {
                        stud.back().nd.push_back(x);
                    }
                }

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
                    stud.back().exam = x;
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

void Calculate(deque<Student> &stud) {
    deque<Student>::iterator it;
    for (it = stud.begin(); it != stud.end(); it++) {
        // mediana:
        sort(it->nd.begin(), it->nd.end());
        if (it->nd.size() % 2 != 0) {
            it->med = it->nd[it->nd.size() / 2];
        } else {
            it->med = (it->nd[(it->nd.size() / 2) - 1] +
                       it->nd[it->nd.size() / 2]) / 2.0;
        }
        it->res_med = 0.4 * it->med + 0.6 * it->exam;
        // vidurkis:
        for (int j = 0; j < it->nd.size(); j++) {
            it->avg += it->nd[j];
        }
        it->avg /= it->nd.size();
        it->res_avg = 0.4 * it->avg + 0.6 * it->exam;
    }
}

void Print(deque<Student> &stud) {
    cout << "\nPavarde             Vardas              Galutinis (Vid.)  Galutinis (Med.)\n" <<
         "----------------------------------------------------------------------------" << std::endl;
    deque<Student>::iterator it;
    for (it = stud.begin(); it != stud.end(); it++) {
        printf("%.18s", it->surname.c_str());
        if ((int) it->surname.length() > 18) {
            cout << "- ";
        } else {
            for (int j = 20; (int) (j - ((int) it->surname.length())) > 0; j--) {
                cout << " ";
            }
        }
        printf("%.18s", it->name.c_str());
        if ((int) it->name.length() > 18) {
            cout << "- ";
        } else {
            for (int j = 20; (int) (j - ((int) it->name.length())) > 0; j--) {
                cout << " ";
            }
        }
        cout << std::fixed << setprecision(2) << it->res_avg;
        cout << "              ";
        cout << std::fixed << setprecision(2) << it->res_med << endl;
    }
}

