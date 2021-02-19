-------------------------------------------------------------------------------
-- system_stub.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

entity system_stub is
  port (
    Rst_pin : in std_logic;
    RX_pin : in std_logic;
    TX_pin : out std_logic;
    lcd_pantalla_0_rs_pin : out std_logic;
    lcd_pantalla_0_rw_pin : out std_logic;
    lcd_pantalla_0_e_pin : out std_logic;
    lcd_pantalla_0_lcd_data_pin : out std_logic_vector(7 downto 0);
    Clk_pin : in std_logic
  );
end system_stub;

architecture STRUCTURE of system_stub is

  component system is
    port (
      Rst_pin : in std_logic;
      RX_pin : in std_logic;
      TX_pin : out std_logic;
      lcd_pantalla_0_rs_pin : out std_logic;
      lcd_pantalla_0_rw_pin : out std_logic;
      lcd_pantalla_0_e_pin : out std_logic;
      lcd_pantalla_0_lcd_data_pin : out std_logic_vector(7 downto 0);
      Clk_pin : in std_logic
    );
  end component;

  attribute BOX_TYPE : STRING;
  attribute BOX_TYPE of system : component is "user_black_box";

begin

  system_i : system
    port map (
      Rst_pin => Rst_pin,
      RX_pin => RX_pin,
      TX_pin => TX_pin,
      lcd_pantalla_0_rs_pin => lcd_pantalla_0_rs_pin,
      lcd_pantalla_0_rw_pin => lcd_pantalla_0_rw_pin,
      lcd_pantalla_0_e_pin => lcd_pantalla_0_e_pin,
      lcd_pantalla_0_lcd_data_pin => lcd_pantalla_0_lcd_data_pin,
      Clk_pin => Clk_pin
    );

end architecture STRUCTURE;

