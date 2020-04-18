#include "func.h"

void ReadSplitGenerateV(vector<Student> &stud, std::ofstream &fail, std::ofstream &mldc, bool strat, bool enhanced, int cycle) {
    using hrClock = std::chrono::high_resolution_clock;
    hrClock::time_point start, end;
    std::chrono::duration<double> elapsed{};
    ifstream fin;
    string line;
    string ignore_s;
    string dest;
    int n;
    int y = 100;
    vector<Student> geri;
    vector<Student> blogi;
    Student temp;
    cout << endl << endl;
    bool med;
    cout << "Norite skaiciuoti pagal vidurki (iveskite 0), ar mediana (iveskite 1)?" << endl;
    cin >> med;
    while (!cin) {
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
             << std::endl;
        cin >> med;
    }

    for (int m = 1; m <= cycle; m++) {
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
            temp.readStudent(iss, n);
            stud.push_back(temp);
        } //irasom i studentu vektoriu

        end = hrClock::now();
        elapsed = end - start;
        cout << "Failu nuskaitymo is failo (su " << y << " irasu) laikas: " << elapsed.count() << " sec." << endl;

        CalculateV(stud, med); // suskaiciuojam vidurki

        // cout << "END: CalculateV" << endl;
        // isskirstom vektoriu i du vektorius:
        // blogi studentai lieka "stud", geri pereina i "good"
        if (strat) {
            if (enhanced) {
                start = hrClock::now();
                auto ptrGood = stable_partition(stud.begin(), stud.end(), [](Student &s) { return (s.getRes() < 5); });
                geri.reserve(stud.end() - ptrGood);
                std::copy(ptrGood, stud.end(), std::back_inserter(geri));
                stud.resize(ptrGood - stud.begin());

                end = hrClock::now();
                elapsed = end - start;
                cout << "Failo (su " << y
                     << " irasu) rusiavimo i dvi grupes laikas (2 strategija, geresni algoritmai): "
                     << elapsed.count() << " sec." << endl;
            } else {
                start = hrClock::now();
                std::sort(stud.begin(), stud.end(), [](Student &s1, Student &s2) { return s1.getRes() < s2.getRes(); });
                int numberOfBad = 0;
                while (stud[numberOfBad].getRes() < 5.0) {
                    numberOfBad++;
                }
                geri.reserve(stud.size() - numberOfBad);
                std::copy(stud.begin() + numberOfBad, stud.end(), std::back_inserter(geri));
                stud.resize(numberOfBad);
                stud.shrink_to_fit();
                end = hrClock::now();
                elapsed = end - start;
                cout << "Failo (su " << y
                     << " irasu) rusiavimo i dvi grupes laikas (2 strategija, be geresniu algoritmu): "
                     << elapsed.count() << " sec." << endl;
            }
        } else {
            start = hrClock::now();
            std::sort(stud.begin(), stud.end(), [](Student &s1, Student &s2) { return s1.getRes() < s2.getRes(); });
            int numberOfBad = 0;
            while (stud[numberOfBad].getRes() < 5.0) {
                numberOfBad++;
            }
            geri.reserve(stud.size() - numberOfBad);
            blogi.reserve(numberOfBad);
            std::copy(stud.begin() + numberOfBad, stud.end(), std::back_inserter(geri));
            std::copy(stud.begin(), stud.begin() + numberOfBad, std::back_inserter(blogi));
            stud.clear();

            end = hrClock::now();
            elapsed = end - start;
            cout << "Failo (su " << y << " irasu) rusiavimo i dvi grupes laikas (1 strategija): " << elapsed.count()
                 << " sec." << endl;
        }


        fail << y << " studentu:" << endl << endl;
        fail << left << setw(17) << "Vardas" << left << std::setw(19) << "Pavarde";
        for (long long int i = 0; i < stud[0].getNd().size(); i++) {
            fail << left << setw(10) << "ND" + std::to_string(i + 1);
        }
        fail << "Egzaminas" << endl;

        mldc << y << " studentu:" << endl << endl;
        mldc << left << setw(17) << "Vardas" << left << std::setw(19) << "Pavarde";
        for (long long int i = 0; i < geri[0].getNd().size(); i++) {
            mldc << left << setw(10) << "ND" + std::to_string(i + 1);
        }
        mldc << "Egzaminas" << endl;

        for (auto &i : geri) {
            mldc << left << setw(17) << i.getName() << left << std::setw(19) << i.getSurname()
                 << left << setw(17);
            for (double j : i.getNd()) {
                mldc << left << setw(10) << j;
            }
            mldc << i.getExam() << endl;
        }
        if (strat) {
            for (auto &i : stud) {
                fail << left << setw(17) << i.getName() << left << std::setw(19) << i.getSurname()
                     << left << setw(15);
                for (double j : i.getNd()) {
                    fail << left << setw(10) << j;
                }
                fail << i.getExam() << endl;
            }
        } else {
            for (auto &i : blogi) {
                fail << left << setw(17) << i.getName() << left << std::setw(19) << i.getSurname()
                     << left << setw(15);
                for (double j : i.getNd()) {
                    fail << left << setw(10) << j;
                }
                fail << i.getExam() << endl;
            }
        }
        //cout << "END: Irasymas i failus. NAUJAS CIKLAS." << endl;
        mldc << endl;
        fail << endl;
        stud.clear();
        geri.clear();
        blogi.clear();
        fin.close();
    }
}

void GenerateRandomFiles(int x, int y) {
    int ran;
    int size = 5;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 10);
    std::ofstream sarasas("sarasas" + std::to_string(x + 1) + ".txt");

    sarasas << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde";
    sarasas << left << std::setw(10) << "Egzaminas";
    for (int i = 0; i < size; i++) {
        sarasas << left << std::setw(10) << "ND" + std::to_string(i + 1);
    }
    sarasas << endl;

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
        if (!cin) {
            cin.clear(); // reset failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                for (;; n++) {
                    if (!(iss >> ignore_s)) {
                        n -= 3;
                        break;
                    }
                }
                continue;
            }
            temp.readStudent(iss, n);
            stud.push_back(temp);
        }
        fin.close();
    } else {
        vector<double> nd;
        int exam;
        string random_s;
        for (int i = 0; cont; i++) {
            nd.clear();
            cout << "Iveskite varda: " << std::endl;
            cin >> random_s;
            temp.setName(random_s);
            cout << "Iveskite pavarde: " << std::endl;
            cin >> random_s;
            temp.setSurname(random_s);

            cout << "Ar norite atsitiktinai generuojamu pazymiu? 0 - ne, 1 - taip." << endl;
            cin >> random;
            while (!cin) {
                cin.clear(); // reset failbit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                while (!cin) {
                    cin.clear(); // reset failbit
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
                         << std::endl;
                    cin >> n;
                }
                for (int j = 0; j < n; j++) {
                    nd.push_back(dist(rng));
                }
                nd.shrink_to_fit();
                exam = dist(rng);
                temp.setNd(nd);
                temp.setExam(exam);
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
                        if (nd.empty()) {
                            cout << "Neivedete jokiu pazymiu!" << endl;
                            continue;
                        } else {
                            break;
                        }
                    } else {
                        nd.push_back(x);
                    }
                }
                nd.shrink_to_fit(); // optimizuoja vektoriaus dydi atmintyje


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
                    break;
                }
                temp.setNd(nd);
                temp.setExam(x);
                stud.push_back(temp);
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

void CalculateV(vector<Student> &stud, bool isMed) {
    if (isMed) {            // mediana:
        double med;
        vector<Student>::iterator it;
        for (it = stud.begin(); it != stud.end(); it++) {
            // mediana:
            //sort((*it)->getNd().begin(), (*it)->getNd().end());
            it->sortNd();
            if ((*it).getNd().size() % 2 != 0) {
                med = (*it).getNd()[(*it).getNd().size() / 2];
            } else {
                med = ((*it).getNd()[((*it).getNd().size() / 2) - 1] +
                        (*it).getNd()[(*it).getNd().size() / 2]) / 2.0;
            }
            (*it).setRes(0.4 * med + 0.6 * (*it).getExam());
        }
    } else {                 // vidurkis:
        double avg;
        vector<Student>::iterator it;
        for (it = stud.begin(); it != stud.end(); it++) {
            avg = 0;
            // vidurkis:
            for (double j : (*it).getNd()) {
                avg += j;
            }
            avg /= (*it).getNd().size();
            (*it).setRes(0.4 * avg + 0.6 * (*it).getExam());
        }
    }
}

void PrintV(vector<Student> &stud) {
    cout << "\nPavarde             Vardas              Galutinis (Vid.)  Galutinis (Med.)\n" <<
         "----------------------------------------------------------------------------" << std::endl;

    for (auto &i : stud) {
        printf("%.18s", i.getSurname().c_str());
        if ((int) i.getSurname().length() > 18) {
            cout << "- ";
        } else {
            for (int j = 20; (int) (j - ((int) i.getSurname().length())) > 0; j--) {
                cout << " ";
            }
        }
        printf("%.18s", i.getName().c_str());
        if ((int) i.getName().length() > 18) {
            cout << "- ";
        } else {
            for (int j = 20; (int) (j - ((int) i.getName().length())) > 0; j--) {
                cout << " ";
            }
        }
        cout << std::fixed << setprecision(2) << i.getRes();
        cout << "              ";
        cout << std::fixed << setprecision(2) << i.getRes() << endl;
    }
}


void ReadSplitGenerateL(list<Student> &stud, std::ofstream &fail, std::ofstream &mldc, bool strat, int cycle) {
    using hrClock = std::chrono::high_resolution_clock;
    hrClock::time_point start, end;
    std::chrono::duration<double> elapsed{};
    ifstream fin;
    string line;
    string ignore_s;
    string dest;
    int n;
    int y = 100;
    list<Student> geri;
    list<Student> blogi;
    cout << endl << endl;
    Student temp = Student();
    bool med;
    cout << "Norite skaiciuoti pagal vidurki (iveskite 0), ar mediana (iveskite 1)?" << endl;
    cin >> med;
    while (!cin) {
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
             << std::endl;
        cin >> med;
    }

    for (int m = 1; m <= cycle; m++) {
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
            temp.readStudent(iss, n);
            stud.push_back(temp);
        } //irasom i studentu vektoriu

        end = hrClock::now();
        elapsed = end - start;
        cout << "Failu nuskaitymo is failo (su " << y << " irasu) laikas: " << elapsed.count() << " sec." << endl;


        CalculateL(stud, med); // suskaiciuojam vidurki


        // isskirstom vektoriu i du vektorius:
        // blogi studentai lieka "stud", geri pereina i "good"
        list<Student>::iterator itt;
        if (strat) {
            start = hrClock::now();
            stud.sort([](Student &s1, Student &s2) { return s1.getRes() < s2.getRes(); });
            itt = stud.begin();
            int count = 0;
            while (itt->getRes() < 5.0) {
                itt++;
                count++;
            }
            std::copy(itt, stud.end(), std::back_inserter(geri));
            stud.resize(count);
            end = hrClock::now();
            elapsed = end - start;
            cout << "Failo (su " << y << " irasu) rusiavimo i dvi grupes laikas (2 strategija): " << elapsed.count() << " sec." << endl;

        } else {
            start = hrClock::now();
            stud.sort([](Student &s1, Student &s2) { return s1.getRes() < s2.getRes(); });
            itt = stud.begin();
            while (itt->getRes() < 5.0) {
                itt++;
            }
            std::copy(itt, stud.end(), std::back_inserter(geri));
            std::copy(stud.begin(), itt, std::back_inserter(blogi));
            stud.clear();
            end = hrClock::now();
            elapsed = end - start;
            cout << "Failo (su " << y << " irasu) rusiavimo i dvi grupes laikas (1 strategija): " << elapsed.count() << " sec." << endl;
        }


        fail << y << " studentu:" << endl << endl;
        fail << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde";


        itt = stud.begin();
        for (long long int i = 0; i < itt->getNd().size(); i++) {
            fail << left << std::setw(10) << "ND" + std::to_string(i + 1);
        }
        fail << "Egzaminas" << endl;

        mldc << y << " studentu:" << endl << endl;
        mldc << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde";
        for (long long int i = 0; i < itt->getNd().size(); i++) {
            mldc << left << std::setw(10) << "ND" + std::to_string(i + 1);
        }
        mldc << "Egzaminas" << endl;


        for (itt = geri.begin(); itt != geri.end(); itt++) {
            mldc << left << std::setw(17) << itt->getName() << left << std::setw(19) << itt->getSurname()
                 << left << std::setw(17);
            for (double j : itt->getNd()) {
                mldc << left << std::setw(10) << j;
            }
            mldc << itt->getExam() << endl;
        }
        if (strat) {
            for (itt = stud.begin(); itt != stud.end(); itt++) {
                fail << left << std::setw(17) << itt->getName() << left << std::setw(19) << itt->getSurname()
                     << left << std::setw(15);
                for (double j : itt->getNd()) {
                    fail << left << std::setw(10) << j;
                }
                fail << itt->getExam() << endl;
            }
        } else {
            for (itt = blogi.begin(); itt != blogi.end(); itt++) {
                fail << left << std::setw(17) << itt->getName() << left << std::setw(19) << itt->getSurname()
                     << left << std::setw(15);
                for (double j : itt->getNd()) {
                    fail << left << std::setw(10) << j;
                }
                fail << itt->getExam() << endl;
            }
        }



        mldc << endl;
        fail << endl;
        stud.clear();
        geri.clear();
        fin.close();
    }
}

void CalculateL(list<Student> &stud, bool isMed) {
    if (isMed) {            // mediana:
        double med;
        list<Student>::iterator it;
        for (it = stud.begin(); it != stud.end(); it++) {
            // mediana:
            it->sortNd();
            if (it->getNd().size() % 2 != 0) {
                med = it->getNd()[it->getNd().size() / 2];
            } else {
                med = (it->getNd()[(it->getNd().size() / 2) - 1] +
                       it->getNd()[it->getNd().size() / 2]) / 2.0;
            }
            it->setRes(0.4 * med + 0.6 * it->getExam());
        }
    } else {                 // vidurkis:
        double avg;
        list<Student>::iterator it;
        for (it = stud.begin(); it != stud.end(); it++) {
            avg = 0;
            // vidurkis:
            for (double j : it->getNd()) {
                avg += j;
            }
            avg /= it->getNd().size();
            it->setRes(0.4 * avg + 0.6 * it->getExam());
        }
    }
}



void ReadSplitGenerateD(deque<Student> &stud, std::ofstream &fail, std::ofstream &mldc, bool strat, int cycle) {
    using hrClock = std::chrono::high_resolution_clock;
    hrClock::time_point start, end;
    std::chrono::duration<double> elapsed{};
    ifstream fin;
    string line;
    string ignore_s;
    string dest;
    int n;
    int y = 100;
    deque<Student> geri;
    deque<Student> blogi;
    cout << endl << endl;
    Student temp = Student();
    bool med;
    cout << "Norite skaiciuoti pagal vidurki (iveskite 0), ar mediana (iveskite 1)?" << endl;
    cin >> med;
    while (!cin) {
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Neteisingai ivestas skaicius, iveskite dar karta!"
             << std::endl;
        cin >> med;
    }

    for (int m = 1; m <= cycle; m++) {
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
            temp.readStudent(iss, n);
            stud.push_back(temp);
        } //irasom i studentu vektoriu

        end = hrClock::now();
        elapsed = end - start;
        cout << "Failu nuskaitymo is failo (su " << y << " irasu) laikas: " << elapsed.count() << " sec." << endl;

        CalculateD(stud, med); // suskaiciuojam vidurki

        // isskirstom vektoriu i du vektorius:
        // blogi studentai lieka "stud", geri pereina i "good"
        deque<Student>::iterator itt;
        if (strat) {
            start = hrClock::now();
            std::sort(stud.begin(), stud.end(), [](Student &s1, Student &s2) { return s1.getRes() < s2.getRes(); });
            itt = stud.begin();
            int count = 0;
            while (itt->getRes() < 5.0) {
                itt++;
                count++;
            }
            std::copy(itt, stud.end(), std::back_inserter(geri));
            stud.resize(count);
            end = hrClock::now();
            elapsed = end - start;
            cout << "Failo (su " << y << " irasu) rusiavimo i dvi grupes laikas (2 strategija): " << elapsed.count() << " sec." << endl;

        } else {
            start = hrClock::now();
            std::sort(stud.begin(), stud.end(), [](Student &s1, Student &s2) { return s1.getRes() < s2.getRes(); });
            itt = stud.begin();
            while (itt->getRes() < 5.0) {
                itt++;
            }
            std::copy(itt, stud.end(), std::back_inserter(geri));
            std::copy(stud.begin(), itt, std::back_inserter(blogi));
            stud.clear();
            end = hrClock::now();
            elapsed = end - start;
            cout << "Failo (su " << y << " irasu) rusiavimo i dvi grupes laikas (1 strategija): " << elapsed.count() << " sec." << endl;
        }

        fail << y << " studentu:" << endl << endl;
        fail << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde";


        itt = stud.begin();
        for (long long int i = 0; i < itt->getNd().size(); i++) {
            fail << left << std::setw(10) << "ND" + std::to_string(i + 1);
        }
        fail << "Egzaminas" << endl;

        mldc << y << " studentu:" << endl << endl;
        mldc << left << std::setw(17) << "Vardas" << left << std::setw(19) << "Pavarde";
        for (long long int i = 0; i < itt->getNd().size(); i++) {
            mldc << left << std::setw(10) << "ND" + std::to_string(i + 1);
        }
        mldc << "Egzaminas" << endl;


        for (itt = geri.begin(); itt != geri.end(); itt++) {
            mldc << left << std::setw(17) << itt->getName() << left << std::setw(19) << itt->getSurname()
                 << left << std::setw(17);
            for (double j : itt->getNd()) {
                mldc << left << std::setw(10) << j;
            }
            mldc << itt->getExam() << endl;
        }
        if (strat) {
            for (itt = stud.begin(); itt != stud.end(); itt++) {
                fail << left << std::setw(17) << itt->getName() << left << std::setw(19) << itt->getSurname()
                     << left << std::setw(15);
                for (double j : itt->getNd()) {
                    fail << left << std::setw(10) << j;
                }
                fail << itt->getExam() << endl;
            }
        } else {
            for (itt = blogi.begin(); itt != blogi.end(); itt++) {
                fail << left << std::setw(17) << itt->getName() << left << std::setw(19) << itt->getSurname()
                     << left << std::setw(15);
                for (double j : itt->getNd()) {
                    fail << left << std::setw(10) << j;
                }
                fail << itt->getExam() << endl;
            }
        }


        mldc << endl;
        fail << endl;
        stud.clear();
        geri.clear();
        fin.close();
    }
}

void CalculateD(deque<Student> &stud, bool isMed) {
    if (isMed) {            // mediana:
        double med;
        deque<Student>::iterator it;
        for (it = stud.begin(); it != stud.end(); it++) {
            // mediana:
            it->sortNd();
            if (it->getNd().size() % 2 != 0) {
                med = it->getNd()[it->getNd().size() / 2];
            } else {
                med = (it->getNd()[(it->getNd().size() / 2) - 1] +
                       it->getNd()[it->getNd().size() / 2]) / 2.0;
            }
            it->setRes(0.4 * med + 0.6 * it->getExam());
        }
    } else {                 // vidurkis:
        double avg;
        deque<Student>::iterator it;
        for (it = stud.begin(); it != stud.end(); it++) {
            avg = 0;
            // vidurkis:
            for (double j : it->getNd()) {
                avg += j;
            }
            avg /= it->getNd().size();
            it->setRes(0.4 * avg + 0.6 * it->getExam());
        }
    }
}
