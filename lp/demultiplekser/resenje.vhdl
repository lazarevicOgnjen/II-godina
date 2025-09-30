entity demux_1to8 is 
  port (A : in  bit; 
        Sel : in  bit_vector (2 downto 0); 
        F : out bit_vector (7 downto 0)); 
end entity; 
  
architecture demux_1to8_arch of demux_1to8 is 
  begin 
    with (Sel) select 
    F(0) <= A when “000”,
    F(1) <= A when “001”,
    F(2) <= A when “010”, 
    F(3) <= A when “011”,  
    F(4) <= A when “100”, 
    F(5) <= A when “101”, 
    F(6) <= A when “110”, 
    F(7) <= A when “111”;  
end architecture; 
