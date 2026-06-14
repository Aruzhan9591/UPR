
# CSV Processor

*CSV Processor* je program pro práci s tabulkami ve formátu CSV. Umožňuje přidávat řádky a sloupce, vypočítávat statistiky (minimum, maximum, součet, průměr) a ukládat změny zpět do souboru. Program podporuje také ukončení příkazem `exit`.


# Popis funkcí programu

# Příkazy programu
1. `addrow` — Přidání řádku
Přidává nový řádek do tabulky s uvedenými hodnotami.

2. `addcol` — Přidání sloupce
Přidává nový sloupec do tabulky s názvem a hodnotami.

3. `average` — Průměrná hodnota
Vypočítá průměrnou hodnotu zadaného číselného sloupce.

4. `min` — Minimum
Najde minimální hodnotu ve zvoleném číselném sloupci.

5. `max` — Maximum
Najde maximální hodnotu ve zvoleném číselném sloupci.

6. `sum` — Součet
Vypočítá součet všech číselných hodnot ve zvoleném sloupci.

7. `exit` — Ukončení
Ukončí běh programu a uloží změny do výstupního souboru.


# Soubory projektu

1. `main.c`
Popis:  
  Hlavní soubor programu, který zpracovává argumenty příkazového řádku, inicializuje data, volá funkce pro zpracování příkazů a řídí běh programu.

2. `commands.c`
Popis: 
  Obsahuje implementaci příkazů uživatele, jako je přidání řádku (`addrow`), přidání sloupce (`addcol`), výpočet minimální, maximální hodnoty, součtu a průměru (`min`, `max`, `sum`, `average`).

3. `commands.h`
Popis:  
  Obsahuje deklarace funkcí, které jsou implementovány v souboru `commands.c`.

4. `csv.c`
Popis: 
  Obsahuje funkce pro práci se soubory CSV, jako je načítání dat, ukládání změn a uvolňování paměti.

5. `csv.h`
Popis: 
  Obsahuje popis datové struktury `Database` a deklarace funkcí pro práci s CSV.

# Datová struktura `Database`:
```c
typedef struct {
    char *data[MAX_ROWS][MAX_COLS]; // Tabulka dat
    int rows; // Počet řádků
    int cols; // Počet sloupců
} Database;
```
6.  `utils.h` / `utils.c`
Popis:
  Obsahuje pomocnou funkci `my_strdup`, která kopíruje řetězce, a další pomocné funkce.


7. `Makefile`
Popis:
  Automatizuje proces sestavení projektu.

---

# Příklad vstupního souboru (`input.csv`)
```
name,surname,points
jakub,cocka,51
adam,lezak,60
jarmila,konikova,30
lenka,laskoradova,95
```

---

# Příklad použití programu
1. Přidání řádku:
   ```
   addrow petr,kolar,40
   ```
  output: name,surname,points
          jakub,cocka,51
          adam,lezak,60
          jarmila,konikova,30
          lenka,laskoradova,95
          petr,kolar,40

2. Přidání sloupce:
   ```
   addcol age 25,30,45,35,50
   ```
  output: name,surname,points,age
          jakub,cocka,51,25
          adam,lezak,60,30
          jarmila,konikova,30,45
          lenka,laskoradova,95,35
          petr,kolar,40,50

3. Výpočet součtu hodnot:
   ```
   sum points
   ```
  output: sum points: 276

4. Nalezení minimální hodnoty:
   ```
   min points
   ```
  output: min points: 30

---

# Instalace a spuštění

# Požadavky
- GCC (verze 9.3.0 nebo novější)
- Makefile pro sestavení

# Sestavení
1. Sestavte projekt pomocí Makefile:
   ```
   make
   ```

2. Spusťte program:
   ```
   ./csv_program --input input.csv --output output.csv
   ```

3. Valgrind:
   ```
   valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./csv_program

4. exit:

5. make clean
---

# Autor
Projekt vytvořila **Aruzhan Abilmazhinova**, osobní číslo: **ABI0008**.
