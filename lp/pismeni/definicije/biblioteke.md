```vhdl
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_textio.all;

library STD;
use STD.textio.all;
```

<br>

- `library IEEE;` — učitava biblioteku IEEE koja sadrži standardne pakete i definicije za VHDL.
- `use IEEE.std_logic_1164.all;` — koristi paket `std_logic_1164` koji definiše tipove kao što su `std_logic` i `std_logic_vector`, koji su osnovni za modelovanje digitalnih signala sa viševalentnom logikom (npr. 0, 1, neodređeno, visoki otpor...).
- `use IEEE.std_logic_textio.all;` — omogućava rad sa tekstualnim fajlovima za tipove `std_logic` i `std_logic_vector`, kao što su funkcije za čitanje i pisanje tekstualnih podataka koji predstavljaju digitalne vrednosti.

Znači, ove linije omogućavaju korišćenje osnovnih logičkih tipova i funkcija za rad sa digitalnim signalima i tekstualnim fajlovima u VHDL-u.

---

- `library STD;` učitava standardnu biblioteku VHDL-a.
- `use STD.textio.all;` omogućava korišćenje paketa `textio` koji sadrži funkcije i tipove za čitanje i pisanje ASCII tekstualnih fajlova u VHDL-u.

Ovaj paket se koristi za ulazno-izlazne operacije nad tekstualnim fajlovima, npr. da se čitaju linije iz fajla, i dalje obrađuju unutar testbenča ili simulacije.
