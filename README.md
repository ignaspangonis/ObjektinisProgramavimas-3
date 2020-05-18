# Objektinio programavimo užduoties nr. 2 tęsinys

## Programos diegimas:
1. Parsisiųsti programą.
2. Parsisiųsti ir įdiegti [GCC](https://gcc.gnu.org/) kompiliatorių.
3. Atsidaryti terminalo langą ir jame įvesti programos vietą diske.
4. Sukompiliuoti programą:
a) Jei naudojate GCC su GNU Make, įrašykite: `make`
b) Jei naudojate GCC be GNU Make, įrašykite:
- `g++ -c main.cpp container.cpp func.cpp Student.cpp`
- `g++ -o main main.o container.o func.o Student.o`
- Paleiskite programą įrašydami `./main` arba `main`

## Programos (v2.0) naudojimas:
### Pavyzdžiai:
```
Norite matuoti programos veikimo sparta su skirtingais konteineriais (iveskite 0), ar paleisti programa (iveskite 1)?
0
Programos matavimo strategija - pirma (iveskite 0), antra (iveskite 1)?
1
Konteineris - vector (v), list (l), deque (d)?:
v
Ar norite generuoti naujus failus, jei dar negeneravote (1), ar ne (0)?
0
Failu dydis - nuo 1000 studentu, su kiekvienu failu didinant si skaiciu 10 kartu.
Kiek failu skaityti ir/ar generuoti (1-5)?:
4
Ar norite naudoti studentu skirstyma spartinancius algoritmus vektoriui (1), ar ne (0)?
1


Norite skaiciuoti pagal vidurki (iveskite 0), ar mediana (iveskite 1)?
0
Failu nuskaitymo is failo (su 1000 irasu) laikas: 0 sec.
Failo (su 1000 irasu) rusiavimo i dvi grupes laikas (2 strategija, geresni algoritmai): 0 sec.
Failu nuskaitymo is failo (su 10000 irasu) laikas: 0.078097 sec.
Failo (su 10000 irasu) rusiavimo i dvi grupes laikas (2 strategija, geresni algoritmai): 0.015596 sec.
Failu nuskaitymo is failo (su 100000 irasu) laikas: 0.781453 sec.
Failo (su 100000 irasu) rusiavimo i dvi grupes laikas (2 strategija, geresni algoritmai): 0.12497 sec.
Failu nuskaitymo is failo (su 1000000 irasu) laikas: 7.80297 sec.
Failo (su 1000000 irasu) rusiavimo i dvi grupes laikas (2 strategija, geresni algoritmai): 1.51734 sec.
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
## Testavimo sistemos parametrai:
1. Procesorius Intel Core i5-7300HQ CPU @ 2.50 GHz
2. RAM 8.00 GB
3. HDD 2 TB
4. Windows OS

## Versijos
### Ankstesnes versijas rasite [šioje repozitorijoje](https://github.com/ignaspangonis/ObjektinisProgramavimas-2/)

### [v1.1](https://github.com/ignaspangonis/ObjektinisProgramavimas-3/releases/tag/v1.1)
#### Patobulinimai:
- Atsisakyta nereikalingų atskirų metodų failų generavimui su std::list ir std::deque;
- Nuo struktūrų pereita prie klasių. Sukurti get'eriai bei set'eriai darbui su klasių objektais. Atitinkamai sutvarkytos ir perdarytos funkcijos;
- Vietose, kur galimas int ribų viršijimas, pereita prie long long int;
- Atlikta analizė su flag'ais: O1, O2, O3.

#### Spartos analizės rezultatai:
- O1, O2, O3 - naudojami flag'ai;
- Naudojamas vektorius su greičiausiais algortimais (2 strategija, optimizuoti algoritmai);
- A - nuskaitymas iš failo į objektų konteinerį;
- B - skirstymas į dvi grupes;
- Laikas nurodytas sekundėmis.

| Įrašų kiekis | Struktūros A | Struktūros B | Klasės A | Klasės B | Klasės A O1 | Klasės B O1 | Klasės A O2 | Klasės B O2 | Klasės A O3 | Klasės B O3 |
|--------------|--------------|--------------|----------|----------|-------------|-------------|-------------|-------------|-------------|-------------|
| 100000       | 0.75188      | 0.124996     | 0.781066 | 0.124971 | 0.792878    | 0.131649    | 0.765471    | 0.125275    | 0.785948    | 0.12497     |
| 1000000      | 7.92602      | 1.3045       | 8.0166   | 1.35085  | 8.33828     | 1.51817     | 7.68328     | 1.43428     | 7.85201     | 1.45358     |
| 10000000     | 78.6323      | 13.1134      | 79.9157  | 13.2285  | 81.4987     | 14.9894     | 75.0212     | 14.2151     | 77.6569     | 14.0493     |

#### Spartos analizės išvados:
- Veiksmai su struktūra buvo nežymiai spartesni už veiksmus su klase.
- O2 buvo efektyviausias optimizavimo flag'as nuskaitymui (A), o skaidymas efektyviausiai veikė be flag'ų.

### [v1.2](https://github.com/ignaspangonis/ObjektinisProgramavimas-3/releases/tag/v1.2)
#### Patobulinimai:
- Realizuoti operatoriai: įvesties >>, išvesties <<, lyginimo ==, !=, >, <, >=, <=;
- Pašalintas Student klasės metodas readStudent(), kurį pakeitė operatorius >>.
- Taisyklingiau apibrėžtas exception, kai įvesto failo vardo nėra.
#### Pastabos:
- Lyginimo operatoriai yra skirti palyginti dviems objektams (studentų rezultatams) arba objektui (studento rezultatui) ir realiajam skaičiui.
- Įvesties operatorius nuskaito iš stream'o studento duomenis tokiu eiliškumu: vardas, pavardė, egzaminas, namų darbai;
- Išvesties operatorius įrašo į stream'ą studento duomenis tokiu eiliškumu: vardas, pavardė, namų darbai, egzaminas;

### [v1.5](https://github.com/ignaspangonis/ObjektinisProgramavimas-3/releases/tag/v1.5)
#### Patobulinimai:
- Klasė Student buvo išskaidyta į dvi klases - Person (bazinė klasė) ir Student (išvestinė klasė).
- Person klasė paversta sąsąjos (interface) klase, t.y. jos funkcijos yra abstrakčios.

### [v2.0](https://github.com/ignaspangonis/ObjektinisProgramavimas-3/releases/tag/v2.0)
#### Patobulinimai:
- Sukurtas kopijavimo operatorius;
- Sugeneruota Doxygen dokumentacija (aplanke /doc);
- Su Catch framework'u sukurti ir įvykdyti unit testai.
#### Unit testing:
Testais įsitikinta, kad veikia:

- Studentų pavardžių lyginimas naudojant get'erius;
- Galutinio balo skaičiavimas:
  - Pagal vidurkį;
  - Pagal medianą;
- Student klasės palyginimo operatoriai, lyginantys galutinius balus;
- Student klasės kopijavimo operatorius.
