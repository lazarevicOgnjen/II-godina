Library IEEE
use IEEE.std_logic_1164.all

entity reg is
port(
  Clock,Reset,EN : in std_logic;
  Data_in: in std_logic_vector(31 downto 0);
  Data_out: out std_logic_vector(31 downto 0);
);
end entity;

architecture reg_arch of reg is
  begin
  
  Reg_proc : process (Clock,Reset)
    begin
    
      if(Reset = '0') then
        Data_out <= x"00";
      elsif (Clock'event and Clock = '1') then
        if(EN = '1') then
          Data_out <= Data_in;
        end if;
      end if;
      
  end process;
      
end architecture;
