#include "struct.h"
#include "func.h"

void ReadSplitGenerateV(vector<Student> &stud, std::ofstream &fail, std::ofstream &mldc) {
    using hrClock = std::chrono::high_resolution_clock;
    hrClock::time_point start, end;
    std::chrono::duration<double> elapsed{};
    ifstream fin;
    string line;
    string ignore_s;
    string dest;
    int random_int;
    int n;
    int y = 100;
    vector<Student> geri;
    cout << endl << endl;
    Student temp;

    for (int m = 1; m <= 5; m++) {
        n = 0;
        start = hrClock::now();
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
                for (;; n++) {
                    if (!(iss >> ignore_s)) {
                        n -= 3;
                        break;
                    }
                }
                continue;
            }
            temp.nd.reserve(n);
            if (!(iss >> temp.name >> temp.surname)) {
                break;
            }
            for (int k = 0; k < n; k++) {
                if (!(iss >> random_int)) {
                    break;
                } else {
                    temp.nd.push_back(random_int);
                }
            }
            if (!(iss >> temp.exam)) {
                break;
            }
            stud.push_back(temp);
            temp.nd.clear();
        } //irasom i studentu vektoriu

        end = hrClock::now();
        elapsed = end - start;
        cout << "Failu nuskaitymo is failo (su " << y << " irasu) laikas: " << elapsed.count() << " sec." << endl;
        CalculateV(stud); // suskaiciuojam vidurki


        // isskirstom vektoriu i du vektorius:
        // blogi studentai lieka "stud", geri pereina i "good"
        start = hrClock::now();
        std::sort(stud.begin(), stud.end(), [](Student &s1, Student &s2) { return s1.res_avg < s2.res_avg; });
        int numberOfBad = 0;
        while (stud[numberOfBad].res_avg < 5.0) {
            numberOfBad++;
        }
        geri.reserve(stud.size() - numberOfBad);
        std::copy(stud.begin() + numberOfBad, stud.end(), std::back_inserter(geri));
        stud.resize(numberOfBad);
        stud.shrink_to_fit();
        end = hrClock::now();
        elapsed = end - start;
        cout << "Failo (su " << y << " irasu) rusiavimo i dvi grupes laikas: " << elapsed.count() << " sec." << endl;


        fail << y << " studentu:" << endl << endl;
        fail << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde";
        for (int i = 0; i < stud[0].nd.size(); i++) {
            fail << left << std::setw(10) << "ND" + std::to_string(i + 1);
        }
        fail << "Egzaminas" << endl;

        mldc << y << " studentu:" << endl << endl;
        mldc << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde";
        for (int i = 0; i < geri[0].nd.size(); i++) {
            mldc << left << std::setw(10) << "ND" + std::to_string(i + 1);
        }
        mldc << "Egzaminas" << endl;

        for (int i = 0; i < geri.size(); i++) {
            mldc << left << std::setw(17) << geri[i].name << left << std::setw(19) << geri[i].surname
                 << left << std::setw(17);
            for (int j = 0; j < geri[i].nd.size(); j++) {
                mldc << left << std::setw(10) << geri[i].nd[j];
            }
            mldc << geri[i].exam << endl;
        }
        for (int i = 0; i < stud.size(); i++) {
            fail << left << std::setw(17) << stud[i].name << left << std::setw(19) << stud[i].surname
                 << left << std::setw(15);
            for (int j = 0; j < stud[i].nd.size(); j++) {
                fail << left << std::setw(10) << stud[i].nd[j];
            }
            fail << stud[i].exam << endl;
        }


        mldc << endl;
        fail << endl;
        stud.clear();
        geri.clear();
        fin.close();
    }
}

void GenerateRandomFilesV(int x, int y, vector<Student> &stud) {
    int ran;
    int size = 5;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 10);
    std::ofstream sarasas("sarasas" + std::to_string(x + 1) + ".txt");

    sarasas << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde";
    for (int i = 0; i < size; i++) {
        sarasas << left << std::setw(10) << "ND" + std::to_string(i + 1);
    }
    sarasas << left << std::setw(15) << "Egzaminas" << endl;
    for (int i = 0; i < y; i++) {
        sarasas << left << std::setw(17) << "Vardenis" + std::to_string(i + 1)
                << left << std::setw(19) << "Pavardenis" + std::to_string(i + 1);
        for (int j = 0; j < size + 1; j++) { // size + 1, nes egzaminas
            ran = dist(rng);
            sarasas << left << std::setw(10) << ran;
        } // sugeneruojam pazymius ir egzamina
        sarasas << endl;
    } // generacijos ciklas
    sarasas.close();
}

void Input(vector<Student> &stud) {
    bool cont = true;
    int x;
    bool random;
    int n = 0;
    bool file;
    Student temp;

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
            if (!(iss >> temp.name >> temp.surname)) { break; }
            for (int k = 0; k < n; k++) {
                if (!(iss >> random_int)) { break; }
                else {
                    temp.nd.push_back(random_int);
                }
            }
            temp.nd.shrink_to_fit();
            if (!(iss >> temp.exam)) { break; }
            stud.push_back(temp);
            temp.nd.clear();
        }
        fin.close();
    } else {
        for (int i = 0; cont; i++) {
            // stud.push_back(Student());
            cout << "Iveskite varda: " << std::endl;
            cin >> temp.name;
            cout << "Iveskite pavarde: " << std::endl;
            cin >> temp.surname;

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
                std::random_device dev;
                std::mt19937 rng(dev());
                std::uniform_int_distribution<std::mt19937::result_type> dist(1, 10);
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
                    temp.nd.push_back(dist(rng));
                }
                temp.nd.shrink_to_fit();
                temp.exam = dist(rng);
                stud.push_back(temp);
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
                        if (temp.nd.empty()) {
                            cout << "Neivedete jokiu pazymiu!" << endl;
                            continue;
                        } else {
                            break;
                        }
                    } else {
                        temp.nd.push_back(x);
                    }
                }
                temp.nd.shrink_to_fit(); // optimizuoja vektoriaus dydi atmintyje


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
                    temp.exam = x;
                    stud.push_back(temp);
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

void CalculateV(vector<Student> &stud) {
    double avg;
    double med;
    for (int i = 0; i < stud.size(); i++) {
        avg = 0;
        // mediana:
        sort(stud[i].nd.begin(), stud[i].nd.end());
        if (stud[i].nd.size() % 2 != 0) {
            med = stud[i].nd[stud[i].nd.size() / 2];
        } else {
            med = (stud[i].nd[(stud[i].nd.size() / 2) - 1] +
                   stud[i].nd[stud[i].nd.size() / 2]) / 2.0;
        }
        stud[i].res_med = 0.4 * med + 0.6 * stud[i].exam;
        // vidurkis:
        for (int j = 0; j < stud[i].nd.size(); j++) {
            avg += stud[i].nd[j];
        }
        avg /= stud[i].nd.size();
        stud[i].res_avg = 0.4 * avg + 0.6 * stud[i].exam;
    }
}

void PrintV(vector<Student> &stud) {
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















void ReadSplitGenerateL(list<Student> &stud, std::ofstream &fail, std::ofstream &mldc) {
    using hrClock = std::chrono::high_resolution_clock;
    hrClock::time_point start, end;
    std::chrono::duration<double> elapsed{};
    ifstream fin;
    string line;
    string ignore_s;
    string dest;
    int random_int;
    int n;
    int y = 100;
    list<Student> geri;
    cout << endl << endl;
    Student temp;

    for (int m = 1; m <= 5; m++) {
        n = 0;
        start = hrClock::now();
        fin.open("sarasas" + std::to_string(m) + ".txt");
        if (!fin.is_open()) {
            cout << "Nepavyko failo atidarymas" << endl;
            break;
        }
        y *= 10;
        for (int l = -1; std::getline(fin, line); l++) {
            std::istringstream iss(line);
            if (l == -1) {
                for (;; n++) {
                    if (!(iss >> ignore_s)) {
                        n -= 3;
                        break;
                    }
                }
                continue;
            }
            temp.nd.reserve(n);
            if (!(iss >> temp.name >> temp.surname)) {
                break;
            }
            for (int k = 0; k < n; k++) {
                if (!(iss >> random_int)) {
                    break;
                } else {
                    temp.nd.push_back(random_int);
                }
            }
            if (!(iss >> temp.exam)) {
                break;
            }
            stud.push_back(temp);
            temp.nd.clear();
        } //irasom i studentu vektoriu

        end = hrClock::now();
        elapsed = end - start;
        cout << "Failu nuskaitymo is failo (su " << y << " irasu) laikas: " << elapsed.count() << " sec." << endl;
        CalculateL(stud); // suskaiciuojam vidurki


        // isskirstom vektoriu i du vektorius:
        // blogi studentai lieka "stud", geri pereina i "good"
        start = hrClock::now();
        stud.sort([](Student &s1, Student &s2) { return s1.res_avg < s2.res_avg; });
        list<Student>::iterator itt;
        itt = stud.begin();
        int count = 0;
        while (itt->res_avg < 5.0) {
            itt++;
            count++;
        }
        std::copy(itt, stud.end(), std::back_inserter(geri));
        stud.resize(count);
        end = hrClock::now();
        elapsed = end - start;
        cout << "Failo (su " << y << " irasu) rusiavimo i dvi grupes laikas: " << elapsed.count() << " sec." << endl;


        fail << y << " studentu:" << endl << endl;
        fail << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde";


        itt = stud.begin();
        for (int i = 0; i < itt->nd.size(); i++) {
            fail << left << std::setw(10) << "ND" + std::to_string(i + 1);
        }
        fail << "Egzaminas" << endl;

        mldc << y << " studentu:" << endl << endl;
        mldc << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde";
        for (int i = 0; i < itt->nd.size(); i++) {
            mldc << left << std::setw(10) << "ND" + std::to_string(i + 1);
        }
        mldc << "Egzaminas" << endl;



        for (itt = geri.begin(); itt != geri.end(); itt++) {
            mldc << left << std::setw(17) << itt->name << left << std::setw(19) << itt->surname
                 << left << std::setw(17);
            for (int j = 0; j < itt->nd.size(); j++) {
                mldc << left << std::setw(10) << itt->nd[j];
            }
            mldc << itt->exam << endl;
        }
        for (itt = stud.begin(); itt != stud.end(); itt++) {
            fail << left << std::setw(17) << itt->name << left << std::setw(19) << itt->surname
                 << left << std::setw(15);
            for (int j = 0; j < itt->nd.size(); j++) {
                fail << left << std::setw(10) << itt->nd[j];
            }
            fail << itt->exam << endl;
        }


        mldc << endl;
        fail << endl;
        stud.clear();
        geri.clear();
        fin.close();
    }
}

void GenerateRandomFilesL(int x, int y, list<Student> &stud) {
    int ran;
    int size = 5;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 10);
    std::ofstream sarasas("sarasas" + std::to_string(x + 1) + ".txt");

    sarasas << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde";
    for (int i = 0; i < size; i++) {
        sarasas << left << std::setw(10) << "ND" + std::to_string(i + 1);
    }
    sarasas << left << std::setw(15) << "Egzaminas" << endl;
    for (int i = 0; i < y; i++) {
        sarasas << left << std::setw(17) << "Vardenis" + std::to_string(i + 1)
                << left << std::setw(19) << "Pavardenis" + std::to_string(i + 1);
        for (int j = 0; j < size + 1; j++) { // size + 1, nes egzaminas
            ran = dist(rng);
            sarasas << left << std::setw(10) << ran;
        } // sugeneruojam pazymius ir egzamina
        sarasas << endl;
    } // generacijos ciklas
    sarasas.close();
}



void CalculateL(list<Student> &stud) {
    double avg;
    double med;
    list<Student>::iterator it;
    it = stud.begin();
    for (it = stud.begin(); it != stud.end(); it++) {
        avg = 0;
        // mediana:
        sort(it->nd.begin(), it->nd.end());
        if (it->nd.size() % 2 != 0) {
            med = it->nd[it->nd.size() / 2];
        } else {
            med = (it->nd[(it->nd.size() / 2) - 1] +
                   it->nd[it->nd.size() / 2]) / 2.0;
        }
        it->res_med = 0.4 * med + 0.6 * it->exam;
        // vidurkis:
        for (int j = 0; j < it->nd.size(); j++) {
            avg += it->nd[j];
        }
        avg /= it->nd.size();
        it->res_avg = 0.4 * avg + 0.6 * it->exam;
    }
}










void ReadSplitGenerateD(deque<Student> &stud, std::ofstream &fail, std::ofstream &mldc) {
    using hrClock = std::chrono::high_resolution_clock;
    hrClock::time_point start, end;
    std::chrono::duration<double> elapsed{};
    ifstream fin;
    string line;
    string ignore_s;
    string dest;
    int random_int;
    int n;
    int y = 100;
    deque<Student> geri;
    cout << endl << endl;
    Student temp;

    for (int m = 1; m <= 5; m++) {
        n = 0;
        start = hrClock::now();
        fin.open("sarasas" + std::to_string(m) + ".txt");
        if (!fin.is_open()) {
            cout << "Nepavyko failo atidarymas" << endl;
            break;
        }
        y *= 10;
        for (int l = -1; std::getline(fin, line); l++) {
            std::istringstream iss(line);
            if (l == -1) {
                for (;; n++) {
                    if (!(iss >> ignore_s)) {
                        n -= 3;
                        break;
                    }
                }
                continue;
            }
            temp.nd.reserve(n);
            if (!(iss >> temp.name >> temp.surname)) {
                break;
            }
            for (int k = 0; k < n; k++) {
                if (!(iss >> random_int)) {
                    break;
                } else {
                    temp.nd.push_back(random_int);
                }
            }
            if (!(iss >> temp.exam)) {
                break;
            }
            stud.push_back(temp);
            temp.nd.clear();
        } //irasom i studentu vektoriu

        end = hrClock::now();
        elapsed = end - start;
        cout << "Failu nuskaitymo is failo (su " << y << " irasu) laikas: " << elapsed.count() << " sec." << endl;
        CalculateD(stud); // suskaiciuojam vidurki


        // isskirstom vektoriu i du vektorius:
        // blogi studentai lieka "stud", geri pereina i "good"
        start = hrClock::now();
        std::sort(stud.begin(), stud.end(), [](Student &s1, Student &s2) { return s1.res_avg < s2.res_avg; });
        deque<Student>::iterator itt;
        itt = stud.begin();
        int count = 0;
        while (itt->res_avg < 5.0) {
            itt++;
            count++;
        }
        std::copy(itt, stud.end(), std::back_inserter(geri));
        stud.resize(count);
        end = hrClock::now();
        elapsed = end - start;
        cout << "Failo (su " << y << " irasu) rusiavimo i dvi grupes laikas: " << elapsed.count() << " sec." << endl;

        fail << y << " studentu:" << endl << endl;
        fail << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde";


        itt = stud.begin();
        for (int i = 0; i < itt->nd.size(); i++) {
            fail << left << std::setw(10) << "ND" + std::to_string(i + 1);
        }
        fail << "Egzaminas" << endl;

        mldc << y << " studentu:" << endl << endl;
        mldc << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde";
        for (int i = 0; i < itt->nd.size(); i++) {
            mldc << left << std::setw(10) << "ND" + std::to_string(i + 1);
        }
        mldc << "Egzaminas" << endl;



        for (itt = geri.begin(); itt != geri.end(); itt++) {
            mldc << left << std::setw(17) << itt->name << left << std::setw(19) << itt->surname
                 << left << std::setw(17);
            for (int j = 0; j < itt->nd.size(); j++) {
                mldc << left << std::setw(10) << itt->nd[j];
            }
            mldc << itt->exam << endl;
        }
        for (itt = stud.begin(); itt != stud.end(); itt++) {
            fail << left << std::setw(17) << itt->name << left << std::setw(19) << itt->surname
                 << left << std::setw(15);
            for (int j = 0; j < itt->nd.size(); j++) {
                fail << left << std::setw(10) << itt->nd[j];
            }
            fail << itt->exam << endl;
        }



        mldc << endl;
        fail << endl;
        stud.clear();
        geri.clear();
        fin.close();
    }
}

void GenerateRandomFilesD(int x, int y, deque<Student> &stud) {
    int ran;
    int size = 5;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 10);
    std::ofstream sarasas("sarasas" + std::to_string(x + 1) + ".txt");

    sarasas << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde";
    for (int i = 0; i < size; i++) {
        sarasas << left << std::setw(10) << "ND" + std::to_string(i + 1);
    }
    sarasas << left << std::setw(15) << "Egzaminas" << endl;
    for (int i = 0; i < y; i++) {
        sarasas << left << std::setw(17) << "Vardenis" + std::to_string(i + 1)
                << left << std::setw(19) << "Pavardenis" + std::to_string(i + 1);
        for (int j = 0; j < size + 1; j++) { // size + 1, nes egzaminas
            ran = dist(rng);
            sarasas << left << std::setw(10) << ran;
        } // sugeneruojam pazymius ir egzamina
        sarasas << endl;
    } // generacijos ciklas
    sarasas.close();
}



void CalculateD(deque<Student> &stud) {
    double avg;
    double med;
    deque<Student>::iterator it;
    it = stud.begin();
    for (it = stud.begin(); it != stud.end(); it++) {
        avg = 0;
        // mediana:
        sort(it->nd.begin(), it->nd.end());
        if (it->nd.size() % 2 != 0) {
            med = it->nd[it->nd.size() / 2];
        } else {
            med = (it->nd[(it->nd.size() / 2) - 1] +
                   it->nd[it->nd.size() / 2]) / 2.0;
        }
        it->res_med = 0.4 * med + 0.6 * it->exam;
        // vidurkis:
        for (int j = 0; j < it->nd.size(); j++) {
            avg += it->nd[j];
        }
        avg /= it->nd.size();
        it->res_avg = 0.4 * avg + 0.6 * it->exam;
    }
}