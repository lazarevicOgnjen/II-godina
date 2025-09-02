<br><br>

<img width="1018" height="600" alt="Screenshot 2025-09-02 223700" src="https://github.com/user-attachments/assets/73d2ace5-cc9c-4d1b-b9a8-ca689f789cbe" />

<br><br>

```vhdl
library IEEE;
use IEEE.std_logic_1164.all;

entity encoder_8to3_binary is
  port (
    A: in bit_vector(7 downto 0);
    F: out bit_vector(2 downto 0)
  );
end entity;

architecture encoder_arch of encoder_8to3_binary is
begin
  process(A)
  begin
    case A is
      when "00000001" => F <= "000"; -- A(0)
      when "00000010" => F <= "001"; -- A(1)
      when "00000100" => F <= "010"; -- A(2)
      when "00001000" => F <= "011"; -- A(3)
      when "00010000" => F <= "100"; -- A(4)
      when "00100000" => F <= "101"; -- A(5)
      when "01000000" => F <= "110"; -- A(6)
      when "10000000" => F <= "111"; -- A(7)
      when others => F <= "000"; -- podrazumevano
    end case;
  end process;
end architecture;

```
