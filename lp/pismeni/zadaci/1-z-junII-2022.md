<img width="784" height="276" alt="Screenshot 2025-09-03 163623" src="https://github.com/user-attachments/assets/ec46b54c-d862-4929-a37d-0299f908263b" />

---

<img width="792" height="591" alt="sl" src="https://github.com/user-attachments/assets/dda82863-dd3b-4983-b5d8-d7d094719b7b" />

---

<mark>NIJE ZAVRSEN</mark>

```vhdl
entity Zad2 is
	port(A, B, C, D : in bit;
	     F : out bit);
end entity;
architecture Zad2_arch of Zad2 is
begin
	F <= '1' when (A='0' and B='0' and C='1' ) else
			 when (A='0' and B='1' and C='1') else
			 when (A='1' and B='0' and C='0') else
			 when (A='1' and B='1' and C='0') else
			 '0';
end architecture;

entity Zad2_TB is
end entity;
architecture Zad2_TB_arch of Zad2_TB is
	component Zad2
		port(A, B, C, D : in bit;
			 F : out bit);
	end component;
	
	signal A_TB, B_TB, C_TB, D : bit;
	signal F_TB : bit;
	begin
			DUT1: Zad2 port map (A=>A_TB, B=>B_TB, C=>C_TB,D  F=>F_TB);
			STIMULUS: process
			begin
				A_TB <= '1'; B_TB <= '0'; C_TB <= '1'; D wait for 100ps;
				A_TB <= '1'; B_TB <= '1'; C_TB <= '0'; wait for 100ps;
			end process;
end architecture;
```
