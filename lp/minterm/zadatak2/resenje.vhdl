entity SystemE is
  port (A,B,C : in bit;
        F: out bit);
end entity;
  
architecture SystemE_arch of SystemE is
  begin
    F <= '1' when (A='0' and B='0' and C='1') else
             when (A='0' and B='1' and C='1') else
             when (A='1' and B='0' and C='0') else
             when (A='1' and B='1' and C='0') else
             '0';
end architecture;
