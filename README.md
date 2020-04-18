# Objektinio programavimo užduotis nr. 3 (nr.2 tęsinys)
## Versijos
### [v0.1](https://github.com/ignaspangonis/ObjektinisProgramavimas-2/releases/tag/v0.1)

Programa:
- nuskaito vartotojo įvestus duomenis apie studentus *(vardą, pavardę, namų darbų ir egzamino rezultatus)*;
- suskaičiuoja studento galutinį pažymį pagal formulę: `Galutinis = 0.6 × Egzaminas + 0,4 × Vidurkis arba Mediana`;
- suteikia galimybę pasirinkti, kad namų darbų ir egzamino rezultatai būtų parinkti atsitiktinai;
- rezultatus pateikia lentelėje ekrane. Jei vardas arba pavardė netelpa laukelyje, jie pateikiami sutrumpinti.

### [v0.2](https://github.com/ignaspangonis/ObjektinisProgramavimas-2/releases/tag/v0.2)

- Pridėta galimybė skaityti duomenis iš failo;
- Pridėtas studentų rūšiavimas pagal pavardes abecėlės tvarka;
- Nuo šiol į ekraną išvedamas galutinis pažymys ir pagal medianą, ir pagal vidurkį;
- Pažymių formatas pakeistas iš int į float, siekiant išvengti parse'ingo komplikacijų.

### [v0.3](https://github.com/ignaspangonis/ObjektinisProgramavimas-2/releases/tag/v0.3)
- Padarytas kodo refactor'ingas su antraštėmis;
- Failo atidarymui panaudotas exception handling.

### [v0.4](https://github.com/ignaspangonis/ObjektinisProgramavimas-2/releases/tag/v0.4)
- Pridėta galimybė matuoti programos veikimo spartą:
1. Sugeneruojami penki atsitiktiniai studentų sąrašų failai, sudaryti iš: 1000, 10000, 100000, 1000000, 10000000 įrašų;
2. Sūrušiuojami studentai į dvi kategorijas (su balais >= 5.0 ir < 5.0).
3. Surūšiuoti studentai išvedami į du naujus failus.
4. Atliekama programos veikimo greičio (spartos) analizė, jos rezultatai: [PNG](https://github.com/ignaspangonis/ObjektinisProgramavimas-2/blob/v0.4/rezultatai.png)

### [v0.4.1](https://github.com/ignaspangonis/ObjektinisProgramavimas-2/releases/tag/v0.4.1)
- Pakeitimai programoje:
1. Efektyvesnis laiko matavimas - naudojama biblioteka std::chrono.
2. Efektyvesnis failų generavimas - nebenaudojamas studentų vektorius saugoti informacijai.
3. Nuo šiol studentai į vektorių įrašomi naudojant "temp" kaip laikiną kiekvieno studento objektą.
4. Efektyvesnis atsitiktinių skaičių generavimas.
5. Sumažintas Student struktūros dydis pakeitus kodą ir pašalinus nebūtinus kintamuosius.
6. Pridėtas makefile

Analizės rezultatai: 


| Įrašų kiekis | Failų generavimas | Failų skaitymas | Studentų skaidymas | Išlaikiusių ir neišlaikiusių išvedimas į failus|
| ------------ |-------------------|-----------------|--------------------|------------------------------------------------|
| 1000         | 0.015949 s        | 0.009973 s      | 0.005021 s         | 0.023961 s                                     |
| 10000        | 0.140623 s        | 0.088793 s      | 0.054859 s         | 0.231388 s                                     |
| 100000       | 1.44513 s         | 0.850717 s      | 0.718081 s         | 2.25497 s                                      |
| 1000000      | 14.1721 s         | 8.20905 s       | 8.52424 s          | 21.6391 s                                      |
| 10000000     | 135.937 s         | 80.9885 s       | 83.3212 s          | 203.6815 s                                     |


### [v0.5](https://github.com/ignaspangonis/ObjektinisProgramavimas-2/releases/tag/v0.5)
- Išmatuojama patobulintos v0.4 realizacijos veikimo sparta priklausomai nuo naudojamo vieno iš trijų konteinerių: std::vector, std::list, std::deque.
#### Spartos analizės rezultatai:

Failų nuskaitymas:


| Įrašų kiekis | std::vector | std::list  | std::deque |
|--------------|-------------|------------|------------|
| 1000         | 0.009016    | 0.009959 s | 0.008975 s |
| 10000        | 0.082769 s  | 0.092754 s | 0.081781 s |
| 100000       | 0.876657 s  | 0.876655 s | 0.840751 s |
| 1000000      | 9.33106 s   | 9.51154 s  | 8.66088 s  |
| 10000000     | 94.9372 s   | 96.0245 s  | 87.4924 s  |

Skaidymas į dvi grupes:

| Įrašų kiekis | std::vector | std::list  | std::deque |
|--------------|-------------|------------|------------|
| 1000         | 0.00399 s   | 0.000998 s | 0.004023 s |
| 10000        | 0.052858 s  | 0.015984 s | 0.054852 s |
| 100000       | 0.739025 s  | 0.203453 s | 0.743014 s |
| 1000000      | 8.92113 s   | 2.6419 s   | 9.44578 s  |
| 10000000     | 90.2545 s   | 27.4452 s  | 95.4631 s  |

- Testavimo sistemos parametrai:
1. Procesorius Intel Core i5-7300HQ CPU @ 2.50 GHz
2. RAM 8.00 GB
3. HDD 1 TB
4. SSD 256 GB

### [v1.0](https://github.com/ignaspangonis/ObjektinisProgramavimas-2/releases/tag/v1.0)
#### Patobulinimai:
- Dalis for ciklų pakeista į foreach ciklus;
- Pridėta galimybė vartotojui testuojant spartą pasirinkti skaičiuoti ne vidurkį, o medianą.
- Vartotojui suteikta galimybė pasirinkti analizei skirtų generuojamų failų kiekį;
- Pridėta galimybė rūšiuoti studentus kuriant du naujus konteinerius, šios galimybės įtaka išmatuota;
- Studentų rūšiavimo paspartinimui panaudotas std::stable_partition algoritmas, kurio įtaka išmatuota palyginant su senu;
- Struktūros dydis sumažintas vienu.

#### Spartos analizės rezultatai (skaidymas į dvi grupes):
1 strategija: kuriami 2 nauji konteineriai, po to senojo turinys ištrinamas.
2 strategija: kuriamas 1 naujas konteineris, nukopijuota dalis iš senojo konteinerio ištrinama.
Konteineris | strategija




| Įrašų kiekis | std::vector  1 | std::vector  2 (paprastai) | std::vector  2 (optimizuotai) | std::list  1 | std::list  2 | std::deque  1 | std::deque  2 |
|--------------|-----------------|-----------------------------|--------------------------------|---------------|---------------|----------------|----------------|
| 10000 | 0.046863 s | 0.046837 s | 0.015623 s | 0.015621 s | 0.015595 s | 0.06352 s | 0.046867 s |
| 100000 | 0.719008 s | 0.703366 s | 0.124996 s | 0.218726 s | 0.171806 s | 0.718584 s | 0.703303 s |
| 1000000 | 8.36857 s | 8.01802 s | 1.37508 s | 3.09155 s | 2.29689 s | 9.0822 s | 8.35948 s |
| 10000000 | 84.0689 s | 80.8637 s | 13.5134 s | 29.9869 s | 23.6324 s | 89.2664 s | 80.3982 s |

### [v1.0.1](https://github.com/ignaspangonis/ObjektinisProgramavimas-2/releases/tag/v1.0.1)
#### Patobulinimai:
- v1.0 versijoje buvo atsisakyta nebūtino struct.cpp failo, bet jis per klaidą paliktas makefile ir README.md programos diegimo instrukcijoje. Šios klaidos ištaisytos 1.0.1 versijoje.

## Programos diegimas:
1. Parsisiųsti programą.
2. Parsisiųsti ir įdiegti [GCC](https://gcc.gnu.org/) kompiliatorių.
3. Atsidaryti terminalo langą ir jame įvesti programos vietą diske.
4. Sukompiliuoti programą:
a) Jei naudojate GCC su GNU Make, įrašykite: `make`
b) Jei naudojate GCC be GNU Make, įrašykite:
- `g++ -c main.cpp container.cpp func.cpp`
- `g++ -o main main.o container.o func.o`
- Paleiskite programą įrašydami `./main` arba `main`

## Programos naudojimas:
### Pavyzdžiai:
```
Norite matuoti programos veikimo sparta su skirtingais konteineriais (iveskite 0), ar paleisti programa (iveskite 1)?
0
Programos matavimo strategija - pirma (iveskite 0), antra (iveskite 1)?
0
Konteineris - vector (v), list (l), deque (d)?:
v
Kiek failu generuoti (1-5)?:
3

Kuriamas sarasas is 1000 studentu.

Kuriamas sarasas is 10000 studentu.

Kuriamas sarasas is 100000 studentu.


Norite skaiciuoti pagal vidurki (iveskite 0), ar mediana (iveskite 1)?
1
Failu nuskaitymo is failo (su 1000 irasu) laikas: 0 sec.
Failo (su 1000 irasu) rusiavimo i dvi grupes laikas (1 strategija): 0.015658 sec.
Failu nuskaitymo is failo (su 10000 irasu) laikas: 0.078135 sec.
Failo (su 10000 irasu) rusiavimo i dvi grupes laikas (1 strategija): 0.046887 sec.
Failu nuskaitymo is failo (su 100000 irasu) laikas: 0.749824 sec.
Failo (su 100000 irasu) rusiavimo i dvi grupes laikas (1 strategija): 0.718942 sec.
```
```
Norite matuoti programos veikimo sparta su skirtingais konteineriais (iveskite 0), ar paleisti programa (iveskite 1)?
1
Ar norite skaityti duomenis is failo? 0 - ne, 1 - taip.
1
Iveskite teksto failo varda (pvz kursiokai.txt):
kursiokai.txt
Norite skaiciuoti pagal vidurki (iveskite 0), ar mediana (iveskite 1)?
0

Pavarde             Vardas              Galutinis (Vid.)  Galutinis (Med.)
----------------------------------------------------------------------------
Andrionis           Andrius             4.80              4.80
Audrius             Lapas               6.32              6.32
Pangonis            Ignas               4.80              4.80
Gasiunas            Augustas            8.16              8.16
```
