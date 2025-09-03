> **komponentna**

```vhdl
component INV1 is
port (A : in bit;
 F : out bit);
end component;

component AND3 is
port (A,B,C : in bit;
 F : out bit);
end component;

component OR4 is
port (A,B,C,D : in bit;
 F : out bit);
end component;

begin

U1 : INV1 port map (A=>A, F=>An);
U2 : INV1 port map (A=>B, F=>Bn);
U3 : INV1 port map (A=>C, F=>Cn);

U4 : AND3 port map (A=>An, B=>Bn, C=>C, F=>m1);
U5 : AND3 port map (A=>An, B=>B, C=>C, F=>m3);
U6 : AND3 port map (A=>A, B=>Bn, C=>Cn, F=>m4);
U7 : AND3 port map (A=>A, B=>B, C=>Cn, F=>m6);

U8 : OR4 port map (A=>m1, B=>m3, C=>m4, D=>m6, F=>F);
```

<br>

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

<br>

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

<br>

> **konkurentna**

```vhdl
An <= not A;
Bn <= not B;
Cn <= not C;
Dn <= not D;

s1 <= An and Bn and Cn and D;
s2 <= An and Bn and C and D;
s3 <= A and Bn and Cn and D;
s4 <= A and Bn and C and D;

F <= s1 or s2 or s3 or s4;

```




