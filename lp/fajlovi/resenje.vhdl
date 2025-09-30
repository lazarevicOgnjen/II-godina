library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_textio.all;

library STD;
use STD.textio.all;

-- Entitet enkodera
entity encoder_8to3_binary is
  port(
    A : in bit_vector(7 downto 0);
    F : out bit_vector(2 downto 0)
  );
end entity;

-- Arhitektura enkodera - logika prema tabeli one-hot enkodera
architecture encoder_8to3_binary_arch of encoder_8to3_binary is
begin
  with (A) select
		F <= "000" when "00000001",
             "001" when "00000010",
            "010" when "00000100",
            "011" when "00001000",
            "100" when "00010000",
            "101" when "00100000",
            "110" when "01000000",
            "111" when "10000000;
end architecture;

-- Testbenč za enkoder
entity encoder_8to3_binary_tb is
end entity;

architecture encoder_8to3_binary_tb_arch of encoder_8to3_binary_tb is
  component encoder_8to3_binary is
    port(
      A : in bit_vector(7 downto 0);
      F : out bit_vector(2 downto 0)
    );
  end component;

  signal A_TB: bit_vector(7 downto 0);
  signal F_TB: bit_vector(2 downto 0);

  file fin: text open read_mode is "ulaz.txt";
  file fout: text open write_mode is "izlaz.txt";
begin

-- Instanca enkodera
  DUT1: encoder_8to3_binary port map (
    A => A_TB,
    F => F_TB
  );

-- Proces koji čita ulaz i piše izlaz
  STIMULUS: process
    variable input_line: line;
    variable output_line: line;
    variable input_vec: bit_vector(7 downto 0);
  begin
    write(output_line, string'("A(7 downto 0), F(2 downto 0)")');
    writeline(fout, output_line);

    for i in 0 to 7 loop
      readline(fin, input_line);
      read(input_line, input_vec);
      A_TB <= input_vec;
      wait for 10 ns;  -- čekanje da se baš signal postavi

      write(output_line, A_TB);
      write(output_line, string'(" -> "));
      write(output_line, F_TB);
      writeline(fout, output_line);
    end loop;

    wait; -- kraj testa
  end process;

end architecture;

