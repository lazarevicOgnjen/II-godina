

<img width="1018" height="600" alt="Screenshot 2025-09-02 223700" src="https://github.com/user-attachments/assets/73d2ace5-cc9c-4d1b-b9a8-ca689f789cbe" />



```vhdl
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_textio.all;
library std;
use std.textio.all;

-- Entitet enkodera
entity encoder_8to3_binary is
  port(
    A : in bit_vector(7 downto 0);
    F : out bit_vector(2 downto 0)
  );
end entity;

-- Arhitektura enkodera - logika prema tabeli one-hot enkodera
architecture Behavioral of encoder_8to3_binary is
begin
  process(A)
  begin
    F(0) <= A(1) or A(3) or A(5) or A(7);
    F(1) <= A(2) or A(3) or A(6) or A(7);
    F(2) <= A(4) or A(5) or A(6) or A(7);
  end process;
end Behavioral;

-- Testbenč za enkoder
entity encoder_8to3_binary_tb is
end entity;

architecture Behavioral_tb of encoder_8to3_binary_tb is
  component encoder_8to3_binary is
    port(
      A : in bit_vector(7 downto 0);
      F : out bit_vector(2 downto 0)
    );
  end component;

  signal A: bit_vector(7 downto 0);
  signal F: bit_vector(2 downto 0);

  file fin: text open read_mode is "ulaz.txt";
  file fout: text open write_mode is "izlaz.txt";
begin

  -- Instanca enkodera
  UUT: encoder_8to3_binary port map (
    A => A,
    F => F
  );

  -- Proces koji čita ulaz i piše izlaz
  stim_proc: process
    variable input_line: line;
    variable output_line: line;
    variable input_vec: bit_vector(7 downto 0);
  begin
    write(output_line, string'("A(7 downto 0), F(2 downto 0)"));
    writeline(fout, output_line);

    while not endfile(fin) loop
      readline(fin, input_line);
      read(input_line, input_vec);
      A <= input_vec;
      wait for 10 ns;  -- čekanje da se baš signal postavi

      write(output_line, input_vec);
      write(output_line, string'(" -> "));
      write(output_line, F);
      writeline(fout, output_line);
    end loop;

    wait; -- kraj testa
  end process;

end Behavioral_tb;


```



