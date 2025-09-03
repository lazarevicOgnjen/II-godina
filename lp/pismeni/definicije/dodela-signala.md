> **konkurentna**

```vhdl
process(A)
    begin
        if A = "00000001" then
            Y <= "000";
        elsif A = "00000010" then
            Y <= "001";
        elsif A = "00000100" then
            Y <= "010";
        elsif A = "00001000" then
            Y <= "011";
        elsif A = "00010000" then
            Y <= "100";
        elsif A = "00100000" then
            Y <= "101";
        elsif A = "01000000" then
            Y <= "110";
        elsif A = "10000000" then
            Y <= "111";
        else
            Y <= "XXX"; -- neodređeno za ostale slučajeve
        end if;
```

> **selekciona**

```vhdl
with A select
        Y <= "000" when "00000001",
             "001" when "00000010",
             "010" when "00000100",
             "011" when "00001000",
             "100" when "00010000",
             "101" when "00100000",
             "110" when "01000000",
             "111" when "10000000",
             "XXX" when others;
```

> **uslovna**

```vhdl
Y <= "000" when A = "00000001" else
         "001" when A = "00000010" else
         "010" when A = "00000100" else
         "011" when A = "00001000" else
         "100" when A = "00010000" else
         "101" when A = "00100000" else
         "110" when A = "01000000" else
         "111" when A = "10000000" else
         "XXX";
```






