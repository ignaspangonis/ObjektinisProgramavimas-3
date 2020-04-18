# Objektinio programavimo užduotis nr. 3 (nr.2 tęsinys)

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
## Versijos
### Ankstesnes versijas rasite [šioje repozitorijoje](https://github.com/ignaspangonis/ObjektinisProgramavimas-2/)

### [v1.1](https://github.com/ignaspangonis/ObjektinisProgramavimas-3/releases/tag/v1.1)
#### Patobulinimai:
- Atsisakyta nereikalingų atskirų metodų failų generavimui su std::list ir std::deque
- Nuo struktūrų pereita prie klasių. Sukurti get'eriai bei set'eriai darbui su klasių objektais. Atitinkamai sutvarkytos ir perdarytos funkcijos.
- Vietose, kur galimas int ribų viršijimas, pereita prie long long int.
- Atlikta analizė su flag'ais: O1, O2, O3.

#### Spartos analizės rezultatai (skaidymas į dvi grupes):





