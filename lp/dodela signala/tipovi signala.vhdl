-- uslovna
F <= '1' when (A='0' and B='0' and C='1') else
         when (A='0' and B='1' and C='1') else
         when (A='1' and B='0' and C='0') else
         when (A='1' and B='1' and C='0') else
         '0';

       
-- selekciona
with (ABC) select
  F <= '1' when '001',
       '1' when '011',
       '1' when '100',
       '1' when '110',
       '0' when others;

       
-- konkurentna
F(0) <= not A(3) and not A(2) and not A(1) and not A(0);
F(1) <= not A93) and not A(2) and not A(1) and A(0);
F(2) <= not A(3) and not A(2) and A(1) and not A(0);
