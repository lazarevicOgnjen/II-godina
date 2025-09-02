<img src="https://r2cdn.perplexity.ai/pplx-full-logo-primary-dark%402x.png" style="height:64px;margin-right:32px"/>

# koja je razlika izmedju write i writeline , vhdl-> write(current_wline, string'("Input=ABCD, Output=F"));

    writeline(Fout, current_wline);
    The key difference between `write` and `writeline` in VHDL is that:

- `write` outputs data to a line buffer (`line` type) without adding a newline character at the end. It just appends the data to the current line.
- `writeline` outputs the entire content of the line buffer to the target file or output and then **appends a newline character** (line feed) automatically, moving the cursor to the next line for subsequent outputs.

In your example:

```vhdl
write(current_wline, string'("Input=ABCD, Output=F"));
writeline(Fout, current_wline);
```

`write` adds the string to the variable `current_wline` (a `line` type), and then `writeline` writes this line to the output file `Fout` and moves to the next line for the next write operation. Without `writeline`, you would manually have to add newline characters if you want multi-line output.

Summary:

- Use `write` to build or append data on the current line.
- Use `writeline` to finalize and output the current line with a newline.

This is consistent with how these functions help manage text output in VHDL simulation or file I/O.[^1_1][^1_2][^1_3][^1_9]
<span style="display:none">[^1_10][^1_4][^1_5][^1_6][^1_7][^1_8]</span>

<div style="text-align: center">⁂</div>

[^1_1]: https://vhdlwhiz.com/define-and-print-multiline-string-literals-in-vhdl/

[^1_2]: https://portal.cs.umbc.edu/help/VHDL/samples/samples.html

[^1_3]: https://stackoverflow.com/questions/56356064/how-can-i-move-next-line-in-vhdl-write-writeline-function

[^1_4]: https://stackoverflow.com/questions/45243179/difference-in-the-output-of-writeline-vs-write

[^1_5]: https://testbook.com/key-differences/difference-between-write-and-writeline

[^1_6]: https://www.edaboard.com/threads/vhdl-basic-input-and-output-text-file.210994/

[^1_7]: https://www.reddit.com/r/FPGA/comments/197x19x/i_need_advice_for_write_signal_in_a_file_vhdl/

[^1_8]: https://groups.google.com/g/comp.lang.vhdl/c/xMZTbf56SeE

[^1_9]: https://www.edaboard.com/threads/print-screen-statements-in-vhdl-need-code-explanation.244780/

[^1_10]: https://www.thecodingforums.com/threads/concatenate-textio-line-type.589899/


---

# ponekad stave wait; a ponekad dodaju i koliko sekundi, koja je razlika?

In VHDL, the difference between using just `wait;` and `wait for <time>;` is as follows:

- `wait;` — This causes the process to pause indefinitely, meaning the execution will stop and wait forever at that point unless interrupted by another condition (like a signal change or a simulation stop). It is often used to halt a process permanently in test benches after some initialization or events.
- `wait for <time>;` — This makes the process pause for a specific amount of simulation time. For example, `wait for 10 ns;` suspends the process for exactly 10 nanoseconds and then resumes. This is useful for introducing fixed delays in test benches or models.

So, `wait;` is an infinite wait, and `wait for` is a timed wait for a specific duration. Both are used in simulation contexts and not synthesizable in hardware designs.

Additionally, there are variants like `wait until <condition>;` which wait until a particular condition becomes true.

Example:

```vhdl
wait; -- wait forever
wait for 10 ns; -- wait for 10 nanoseconds
wait until clk = '1'; -- wait until clock signal rises
```

This distinction helps control timing and synchronization in VHDL test benches and simulation models.[^2_1][^2_2][^2_3]
<span style="display:none">[^2_4][^2_5][^2_6][^2_7][^2_8][^2_9]</span>

<div style="text-align: center">⁂</div>

[^2_1]: https://nandland.com/wait-statement-wait-until-wait-on-wait-for/

[^2_2]: https://vhdlwhiz.com/wait-on-wait-until/

[^2_3]: https://vhdlwhiz.com/wait-for/

[^2_4]: https://www.bits.digibeatrix.com/en/verilog-control-flow/verilog-wait-complete-guide/

[^2_5]: https://stackoverflow.com/questions/32717040/what-is-the-difference-between-wait-until-rising-edgeclk-vs-if-rising-edge

[^2_6]: https://www.elektronika.ftn.uns.ac.rs/jezici-za-modelovanje-hardvera/wp-content/uploads/sites/201/2018/03/Vezba-6-Opis-standardnih-sekvencijalnih-mreza-3.pdf

[^2_7]: https://odseknis.akademijanis.edu.rs/wp-content/plugins/vts-predmeti/uploads/04 Predavanje 16.03.2020.pdf

[^2_8]: http://leda.elfak.ni.ac.rs/education/PEK_stari/Kurs%20VHDL/VHDLPrimeri%20Poglavlje4.pdf

[^2_9]: https://www.youtube.com/watch?v=CABjy5rafU4


---

# daj kraci odgovor

Kratko:

- `wait;` znači čekaj **beskonačno** (dok se nešto ručno ne prekine).
- `wait for <vreme>;` znači čekaj tačno određeno vreme (npr. 10 ns), pa nastavi dalje.

`wait` bez vremena zaustavlja proces zauvek, a sa `for` uvodi vremensko kašnjenje u simulaciji [^3_1][^3_2][^3_3].
<span style="display:none">[^3_4][^3_5][^3_6][^3_7][^3_8][^3_9]</span>

<div style="text-align: center">⁂</div>

[^3_1]: https://nandland.com/wait-statement-wait-until-wait-on-wait-for/

[^3_2]: https://vhdlwhiz.com/wait-on-wait-until/

[^3_3]: https://vhdlwhiz.com/wait-for/

[^3_4]: https://www.bits.digibeatrix.com/en/verilog-control-flow/verilog-wait-complete-guide/

[^3_5]: https://stackoverflow.com/questions/32717040/what-is-the-difference-between-wait-until-rising-edgeclk-vs-if-rising-edge

[^3_6]: https://www.elektronika.ftn.uns.ac.rs/jezici-za-modelovanje-hardvera/wp-content/uploads/sites/201/2018/03/Vezba-6-Opis-standardnih-sekvencijalnih-mreza-3.pdf

[^3_7]: https://odseknis.akademijanis.edu.rs/wp-content/plugins/vts-predmeti/uploads/04 Predavanje 16.03.2020.pdf

[^3_8]: http://leda.elfak.ni.ac.rs/education/PEK_stari/Kurs%20VHDL/VHDLPrimeri%20Poglavlje4.pdf

[^3_9]: https://www.youtube.com/watch?v=CABjy5rafU4


---

# koja je razlika izmedju ova 2 -> readline(Fin, current_rline);

    read(current_rline, current_aux);
    Kratko:

- `readline(Fin, current_rline);` čita **čitavu liniju teksta** iz fajla i smešta je u promenljivu tipa `line`.
- `read(current_rline, current_aux);` čita jedan podatak (element) iz te linije sa pozicije na kojoj se trenutno nalazi ponašajući se kao parser.

Dakle, prvo se preko `readline` unese cela linija, a zatim `read` uzima pojedinačne elemente iz te linije po redu.[^4_2][^4_3]
<span style="display:none">[^4_1][^4_4][^4_5][^4_6][^4_7]</span>

<div style="text-align: center">⁂</div>

[^4_1]: https://www.reddit.com/r/FPGA/comments/d4v7bb/vhdl_how_to_read_long_lines_of_data_from_text/

[^4_2]: https://stackoverflow.com/questions/41839901/how-to-read-elements-from-a-line-in-vhdl

[^4_3]: https://vhdlwhiz.com/stimulus-file/

[^4_4]: https://www.edaboard.com/threads/reading-input-in-vhdl.233034/

[^4_5]: https://soceame.wordpress.com/2025/03/04/how-to-use-textio-library-functions-in-vhdl/

[^4_6]: https://nandland.com/file-input-output/

[^4_7]: https://adaptivesupport.amd.com/s/question/0D52E00006hpgKJSAY/reading-a-text-file-in-vhdl?language=en_US


---

# kako ovo funkcionise readline(Fin, current_rline);

    read(current_rline, current_aux); 
        ABCD_TB<=current_aux;
    Evo kako funkcioniše tvoj kod:

1. `readline(Fin, current_rline);` – iz fajla `Fin` se pročita cela jedna linija i ta linija se smešta u promenljivu `current_rline` tipa `line`.
2. `read(current_rline, current_aux);` – iz te linije se pročita jedan element (na primer broj, string ili neki drugi tip podataka) i smešta u promenljivu `current_aux`.
3. `ABCD_TB <= current_aux;` – vrednost iz `current_aux` se dodeljuje signalu `ABCD_TB`.

Dakle, prvo se uzme cela linija teksta iz fajla, pa se iz nje pročita određeni podatak koji se potom prosleđuje signalu.[^5_1][^5_3]
<span style="display:none">[^5_2][^5_4][^5_5][^5_6][^5_7]</span>

<div style="text-align: center">⁂</div>

[^5_1]: https://stackoverflow.com/questions/41839901/how-to-read-elements-from-a-line-in-vhdl

[^5_2]: https://www.ucg.ac.me/skladiste/blog_10555/objava_44831/fajlovi/VHDL_skripta%202019.pdf

[^5_3]: https://community.intel.com/t5/Intel-Quartus-Prime-Software/Reading-and-Writing-Text-File-in-VHDL/td-p/180931

[^5_4]: https://www.edaboard.com/threads/text-file-reading-and-writing-in-vhdl.169813/

[^5_5]: https://soceame.wordpress.com/2025/03/04/how-to-use-textio-library-functions-in-vhdl/

[^5_6]: https://nandland.com/file-input-output/

[^5_7]: https://www.edaboard.com/threads/help-me-with-working-with-vhdl-text-i-o-to-read-data.18293/


---

# sta ovo omogucava (cemu to sluzi) -> Library IEEE;

use IEEE.std_logic_1164.all;
use IEEE.std_logic_textio.all;

Evo čemu služe te tri linije:

- `library IEEE;` — učitava biblioteku IEEE koja sadrži standardne pakete i definicije za VHDL.
- `use IEEE.std_logic_1164.all;` — koristi paket `std_logic_1164` koji definiše tipove kao što su `std_logic` i `std_logic_vector`, koji su osnovni za modelovanje digitalnih signala sa viševalentnom logikom (npr. 0, 1, neodređeno, visoki otpor...).
- `use IEEE.std_logic_textio.all;` — omogućava rad sa tekstualnim fajlovima za tipove `std_logic` i `std_logic_vector`, kao što su funkcije za čitanje i pisanje tekstualnih podataka koji predstavljaju digitalne vrednosti.

Znači, ove linije omogućavaju korišćenje osnovnih logičkih tipova i funkcija za rad sa digitalnim signalima i tekstualnim fajlovima u VHDL-u.[^6_1][^6_2][^6_3]
<span style="display:none">[^6_10][^6_4][^6_5][^6_6][^6_7][^6_8][^6_9]</span>

<div style="text-align: center">⁂</div>

[^6_1]: https://hdlfactory.com/post/2025/06/29/vhdl-ieee-libraries-and-numeric-type-conversion-a-definitive-reference/

[^6_2]: https://www.hdlworks.com/hdl_corner/vhdl_ref/VHDLContents/StdLogic1164.htm

[^6_3]: https://sites.google.com/site/learnvhdl/home/hour-07-libraries-and-data-types

[^6_4]: https://portal.cs.umbc.edu/help/VHDL/packages/std_logic_1164.vhd

[^6_5]: https://en.wikipedia.org/wiki/IEEE_1164

[^6_6]: https://www2.cs.sfu.ca/~ggbaker/reference/std_logic/

[^6_7]: https://www.arl.wustl.edu/projects/fpx/class/resources/Libraries and Packages in VHDL.htm

[^6_8]: https://opensource.ieee.org/vasg/Packages/blob/c12aae473a809f092415f9ccc9c20986a29c8eb6/ieee/std_logic_1164.vhdl

[^6_9]: https://www.sciencedirect.com/topics/engineering/library-ieee

[^6_10]: https://www.intel.com/content/www/us/en/docs/programmable/683283/18-1/vhdl-standard-libraries-and-packages.html


---

# a ovo -> library STD;

use STD.textio.all;

Kratko:

- `library STD;` učitava standardnu biblioteku VHDL-a.
- `use STD.textio.all;` omogućava korišćenje paketa `textio` koji sadrži funkcije i tipove za čitanje i pisanje ASCII tekstualnih fajlova u VHDL-u.

Ovaj paket se koristi za ulazno-izlazne operacije nad tekstualnim fajlovima, npr. da se čitaju linije iz fajla, i dalje obrađuju unutar testbenča ili simulacije.[^7_2][^7_4]
<span style="display:none">[^7_1][^7_3][^7_5][^7_6]</span>

<div style="text-align: center">⁂</div>

[^7_1]: https://www.zemris.fer.hr/~ssegvic/pubs/vhdl-cm.pdf

[^7_2]: https://www.hdlworks.com/hdl_corner/vhdl_ref/VHDLContents/TEXTIOPackage.htm

[^7_3]: https://petsoftware.files.wordpress.com/2015/01/8_txtio.pdf

[^7_4]: https://www.vhdl-online.de/vhdl_reference_93/package_textio

[^7_5]: http://leda.elfak.ni.ac.rs/education/PEK_Elektronika/literatura/predavanja%20EKS/2019-20/05/VHDL%20primena%20u%20sintezi.pdf

[^7_6]: https://portal.cs.umbc.edu/help/VHDL/stdpkg.html


---

# objasni ovo -> for i in 0 to 15 loop

    readline(Fin, current_rline);
    read(current_rline, current_aux); 
        ABCD_TB<=current_aux;
    wait for 10 ns;
    write(current_wline, string'("ABCD="));
    write(current_wline, ABCD_TB);
    write(current_wline, string'("F="));
    write(current_wline, F_TB);
    writeline(Fout, current_wline);
    end loop;

Ovo radi sledeće:

- Petlja `for i in 0 to 15 loop` ponavlja kod unutar  nje 16 puta (za i=0 do i=15).
- Svaki put:

1. `readline(Fin, current_rline);` čita jednu liniju iz ulaznog fajla `Fin` u promenljivu `current_rline`.
2. `read(current_rline, current_aux);` iz te linije čita jedan podatak i smešta u `current_aux`.
3. `ABCD_TB <= current_aux;` dodeljuje taj podatak signalu `ABCD_TB`.
4. `wait for 10 ns;` pauzira izvršavanje petlje na 10 nanosekundi (simulaciono vreme).
5. Zatim sa `write` funkcijama sklapa liniju teksta: prvo piše `"ABCD="`, pa vrednost `ABCD_TB`, zatim `"F="`, pa vrednost `F_TB`.
6. `writeline(Fout, current_wline);` upisuje tu liniju u izlazni fajl `Fout`.

Dakle, petlja čita podatke iz fajla, dodeljuje signalima, pravi tekstualni zapis i upisuje ga u drugi fajl, sa pauzom između svake iteracije.[^8_1][^8_2][^8_4]
<span style="display:none">[^8_3][^8_5][^8_6][^8_7][^8_8][^8_9]</span>

<div style="text-align: center">⁂</div>

[^8_1]: https://www.youtube.com/watch?v=OjIHfYkQUYA

[^8_2]: https://www.vhdl-online.de/courses/system_design/vhdl_language_and_syntax/sequential_statements/for_loops

[^8_3]: https://fpgatutorial.com/vhdl-for-while-loop-if-case-statement/

[^8_4]: https://vhdlwhiz.com/for-loop/

[^8_5]: https://ics.uci.edu/~jmoorkan/vhdlref/for_loop.html

[^8_6]: https://nandland.com/for-loop-2/

[^8_7]: https://docs.amd.com/r/en-US/ug901-vivado-synthesis/Example-of-for-loop-Statement-VHDL

[^8_8]: https://peterfab.com/ref/vhdl/vhdl_renerta/mobile/source/vhd00042.htm

[^8_9]: https://stackoverflow.com/questions/10672256/short-vhdl-for-loop-code-i-dont-understand

