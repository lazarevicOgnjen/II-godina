entity encoder_8to3_binary is 
  port (A : in  bit_vector (7 downto 0); 
        F : out bit_vector (2 downto 0)); 
end entity;
  
architecture encoder_8to3_binary_arch of encoder_8to3_binary is 
  begin 
    F(2) <= A(7) or A(6) or A(5) or A(4) 
    F(1) <= A(7) or A(6) or A(3) or A(2) 
    F(0) <= A(7) or A(5) or A(3) or A(1) 
end architecture; 
