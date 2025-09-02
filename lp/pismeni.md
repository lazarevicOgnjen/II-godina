[<img src="https://r2cdn.perplexity.ai/pplx-full-logo-primary-dark%402x.png" style="height:64px;margin-right:32px"/>

# sta ovo omogucava (cemu to sluzi) -> Library IEEE;

use IEEE.std_logic_1164.all;
use IEEE.std_logic_textio.all;

Evo čemu služe te tri linije:

- `library IEEE;` — učitava biblioteku IEEE koja sadrži standardne pakete i definicije za VHDL.
- `use IEEE.std_logic_1164.all;` — koristi paket `std_logic_1164` koji definiše tipove kao što su `std_logic` i `std_logic_vector`, koji su osnovni za modelovanje digitalnih signala sa viševalentnom logikom (npr. 0, 1, neodređeno, visoki otpor...).
- `use IEEE.std_logic_textio.all;` — omogućava rad sa tekstualnim fajlovima za tipove `std_logic` i `std_logic_vector`, kao što su funkcije za čitanje i pisanje tekstualnih podataka koji predstavljaju digitalne vrednosti.

Znači, ove linije omogućavaju korišćenje osnovnih logičkih tipova i funkcija za rad sa digitalnim signalima i tekstualnim fajlovima u VHDL-u.

# a ovo -> library STD;

use STD.textio.all;

Kratko:

- `library STD;` učitava standardnu biblioteku VHDL-a.
- `use STD.textio.all;` omogućava korišćenje paketa `textio` koji sadrži funkcije i tipove za čitanje i pisanje ASCII tekstualnih fajlova u VHDL-u.

Ovaj paket se koristi za ulazno-izlazne operacije nad tekstualnim fajlovima, npr. da se čitaju linije iz fajla, i dalje obrađuju unutar testbenča ili simulacije.

# razlika izmedju wait i wait for 10 ns

- `wait;` znači čekaj **beskonačno** (dok se nešto ručno ne prekine).
- `wait for <vreme>;` znači čekaj tačno određeno vreme (npr. 10 ns), pa nastavi dalje.

`wait` bez vremena zaustavlja proces zauvek, a sa `for` uvodi vremensko kašnjenje u simulaciji 

# kako ovo funkcionise readline(Fin, current_rline);

    read(current_rline, current_aux); 
        ABCD_TB<=current_aux;
    Evo kako funkcioniše tvoj kod:

1. `readline(Fin, current_rline);` – iz fajla `Fin` se pročita cela jedna linija i ta linija se smešta u promenljivu `current_rline` tipa `line`.
2. `read(current_rline, current_aux);` – iz te linije se pročita jedan element (na primer broj, string ili neki drugi tip podataka) i smešta u promenljivu `current_aux`.
3. `ABCD_TB <= current_aux;` – vrednost iz `current_aux` se dodeljuje signalu `ABCD_TB`.

Dakle, prvo se uzme cela linija teksta iz fajla, pa se iz nje pročita određeni podatak koji se potom prosleđuje signalu.](https://www.perplexity.ai/search/koja-je-razlika-izmedju-write-SnSwuJb8TJq.B.pIgkqG.Q)
