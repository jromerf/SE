----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    02:58:20 10/21/2020 
-- Design Name: 
-- Module Name:    contador - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

entity contador is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           cout : out  STD_LOGIC_VECTOR (7 downto 0));
end contador;

architecture Behavioral of contador is
signal cnt_out: std_logic_vector(7 downto 0);
begin

	contador : process(clk,reset)
	begin
		
		if reset = '0' then
			cnt_out <= (others=>'0');
		elsif clk'event and clk='1' then
			if cnt_out = "11111111" then
				cnt_out<="00000000";
			else
				cnt_out<= std_logic_vector(unsigned(cnt_out)+1);
			end if;
		end if;
		
	end process contador;

	cout<= cnt_out;
	
end Behavioral;

