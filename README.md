# Objektinio programavimo užduotis nr. 2
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
- Nuo šiol į ekraną išvedamas galutinis pažymys ir pagal medianą, ir pagal vidurkį.
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

### [v0.5](https://github.com/ignaspangonis/ObjektinisProgramavimas-2/releases/tag/v0.5)
- Išmatuojama patobulintos v0.4 realizacijos veikimo sparta priklausomai nuo naudojamo vieno iš trijų konteinerių: std::vector, std::list, std::deque.
Spartos analizės rezultatai:
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

## Programos diegimas ir naudojimas:
1. Parsisiųsti programą.
2. Parsisiųsti ir įdiegti GCC kompiliatorių.
3. Atsidaryti terminalo langą ir jame įvesti programos vietą diske.
4. Sukompiliuoti programą:
a) Jei naudojate GCC su GNU Make, įrašykite: `make`
b) Jei naudojate GCC be GNU Make, įrašykite:
- `g++ -c main.cpp func.cpp struct.cpp`
- `g++ -o main main.o func.o struct.o`
- Paleiskite programą įrašydami `./main` arba `main`
