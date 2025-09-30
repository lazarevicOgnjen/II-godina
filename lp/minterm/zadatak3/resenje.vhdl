entity SystemE is
  port (A,B,C : in bit;
        F: out bit);
end entity;

architecture SystemE_arch of SystemE is
  
  signal ABC <= bit_vector(2 downto 0);

  begin

    ABC <= A & B & C;
    with (ABC) select
    F <= '1' when '001',
         '1' when '011',
         '1' when '100',
         '1' when '110',
         '0' when others;
  
end architecture;
