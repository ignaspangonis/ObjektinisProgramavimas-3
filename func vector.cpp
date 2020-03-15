#include "struct.h"
#include "func.h"

void DuomenuKurimas(int y, vector<Student> &stud) {
    int ran, sum;
    int size = 5;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1,10);
    for (int i = 0; i < y; i++) {
        sum = 0;
        stud.push_back(Student());
        stud[i].nd.reserve(size);
        stud[i].name = "Vardenis" + std::to_string(i + 1);
        stud[i].surname = "Pavardenis" + std::to_string(i + 1);
        for (int j = 0; j < size; j++) {
            ran = dist(rng);
            stud[i].nd.push_back(ran);
            sum += ran;
        }
        ran = dist(rng);
        stud[i].exam = ran;
        // stud[i].res_avg = ( (double) sum / size) * 0.4 + stud[i].exam * 0.6;
    }
}

void FailuKurimas2 (vector<Student> &stud, std::ofstream &fail, std::ofstream &mldc) {
    clock_t start, end;
    ifstream fin;
    string line;
    string ignore_s;
    string dest;
    int random_int;
    int n;
    int y = 100;
    int g;
    int b;
    vector<SimpleStudent> geri;
    vector<SimpleStudent> blogi;
    cout << endl << endl;
    for (int m = 1; m <= 5; m++) {
        g = 0;
        b = 0;
        n = 0;
        start = clock();
        fin.open("sarasas" + std::to_string(m) + ".txt");
        if (!fin.is_open()) {
            cout << "Nepavyko failo atidarymas" << endl;
            break;
        }
        y *= 10;
        stud.reserve(y);
        for (int l = -1; std::getline(fin, line); l++) {
            std::istringstream iss(line);
            if (l == -1) {
                if (!(iss >> ignore_s >> ignore_s)) {
                    break;
                }
                for (; ; n++) {
                    if (!(iss >> ignore_s)) {
                        n -= 1;
                        break;
                    }
                }
                continue;
            }
            stud.push_back(Student());
            if (!(iss >> stud[l].name >> stud[l].surname)) {
                break;
            }
            for (int k = 0; k < n; k++) {
                if (!(iss >> random_int)) {
                    break;
                } else {
                    stud[l].nd.push_back(random_int);
                }
            }
            stud[l].nd.shrink_to_fit();
            if (!(iss >> stud[l].exam)) {
                break;
            }
        } //irasom i studentu vektoriu

        end = clock();
        cout << "Failu nuskaitymo is failo (su " << y << " irasu) laikas: "
             << std::setprecision(4) << 1.0 * (end - start)/ CLOCKS_PER_SEC << " sec." << endl;

        Calculate(stud); // suskaiciuojam vidurki

        blogi.reserve(y);
        geri.reserve(y);

        start = clock();
        for (int i = 0; i < y; i++) {
            if (stud[i].res_avg < 5) {
                blogi.push_back(SimpleStudent());
                blogi[b].name = stud[i].name;
                blogi[b].surname = stud[i].surname;
                blogi[b].res_avg = stud[i].res_avg;
                b++;
            } else {
                geri.push_back(SimpleStudent());
                geri[g].name = stud[i].name;
                geri[g].surname = stud[i].surname;
                geri[g].res_avg = stud[i].res_avg;
                g++;
            }
        } // isskirstom vektoriu i du vektorius

        end = clock();
        cout << "Failo (su " << y << " irasu) rusiavimo i dvi grupes laikas: "
             << std::setprecision(4) << 1.0 * (end - start)/ CLOCKS_PER_SEC << " sec." << endl;


        start = clock();
        fail  << y << " studentu:" << endl << endl;
        fail << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde" << left << std::setw(15) << "Galutinis (vid.)" << endl;
        mldc << y << " studentu:" << endl << endl;
        mldc << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde" << "Galutinis (vid.)" << endl;
        for (int i = 0; i < g; i++) {
            mldc << left << std::setw(17) << geri[i].name << left << std::setw(19) << geri[i].surname
                 << left << std::setw(17) << geri[i].res_avg << endl;
        }
        for (int i = 0; i < b; i++) {
            fail << left << std::setw(17) << blogi[i].name << left << std::setw(19) << blogi[i].surname
                 << left << std::setw(15) << blogi[i].res_avg << endl;
        }

        end = clock();
        cout << "Studentu isvedimas i 2 failus is dvieju grupiu (su " << y << " irasu) laikas: "
             << std::setprecision(4) << 1.0 * (end - start)/ CLOCKS_PER_SEC << " sec." << endl << endl;

        mldc << endl;
        fail << endl;
        stud.clear();
        geri.clear();
        blogi.clear();
        fin.close();
    }
}

void FailuKurimas (int x, int y, vector<Student> &stud) {
    std::ofstream sarasas("sarasas" + std::to_string(x + 1) + ".txt");
    sarasas << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde";
    for (int i = 0; i < stud[0].nd.size(); i++){
        sarasas << left << std::setw(10) << "ND" + std::to_string(i);
    }
    sarasas << left << std::setw(15) << "Egzaminas" << endl;
    for (int i = 0; i < y; i++) {
        sarasas << left << std::setw(17) << stud[i].name << left << std::setw(19) << stud[i].surname;
        for (int j = 0; j < stud[0].nd.size(); j++) {
            sarasas << left << std::setw(10) << stud[i].nd[j];
        }
        sarasas << stud[i].exam << endl;
    }
    sarasas.close();
}

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

//        if (!fin) {
//            cout << "Failo atidarymas nepavyko!";
//            exit(1);   // call system to stop
//        }

        try {
            cin >> dest;
            fin.open(dest);
            if (!fin) {
                throw "Failo atidarymas nepavyko!\n";
            }
        } catch (const char* msg) {
            std::cerr << msg;
            exit(1);
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
            stud[l].nd.shrink_to_fit();
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

