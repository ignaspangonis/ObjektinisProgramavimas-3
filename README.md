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
- Kiekvienam konteineriui matuoti yra atskiri main.cpp, func.h ir func.cpp failai, o struct.h ir struct.cpp išlieka tie patys.
1. std::deque spartos analizės rezultatai: [PNG](https://github.com/ignaspangonis/ObjektinisProgramavimas-2/blob/v0.5/Deque.png)
2. std::list spartos analizės rezultatai: [PNG](https://github.com/ignaspangonis/ObjektinisProgramavimas-2/blob/v0.5/Lists.png)
3. std::vector spartos analizės rezultatai: [PNG](https://github.com/ignaspangonis/ObjektinisProgramavimas-2/blob/v0.5/Vector.png)
- Testavimo sistemos parametrai:
1. Procesorius Intel Core i5-7300HQ CPU @ 2.50 GHz
2. RAM 8.00 GB
3. HDD 1 TB
4. SSD 256 GB
