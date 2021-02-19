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
    banner_pantalla_0_reset_out_pin : out std_logic;
    banner_pantalla_0_row_clk_pin : out std_logic;
    banner_pantalla_0_reset2_out_pin : out std_logic;
    banner_pantalla_0_row_serial_out_pin : out std_logic;
    banner_pantalla_0_col_clk_pin : out std_logic;
    banner_pantalla_0_col_serial_out_pin : out std_logic;
    Clk_pin : in std_logic
  );
end system_stub;

architecture STRUCTURE of system_stub is

  component system is
    port (
      Rst_pin : in std_logic;
      RX_pin : in std_logic;
      TX_pin : out std_logic;
      banner_pantalla_0_reset_out_pin : out std_logic;
      banner_pantalla_0_row_clk_pin : out std_logic;
      banner_pantalla_0_reset2_out_pin : out std_logic;
      banner_pantalla_0_row_serial_out_pin : out std_logic;
      banner_pantalla_0_col_clk_pin : out std_logic;
      banner_pantalla_0_col_serial_out_pin : out std_logic;
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
      banner_pantalla_0_reset_out_pin => banner_pantalla_0_reset_out_pin,
      banner_pantalla_0_row_clk_pin => banner_pantalla_0_row_clk_pin,
      banner_pantalla_0_reset2_out_pin => banner_pantalla_0_reset2_out_pin,
      banner_pantalla_0_row_serial_out_pin => banner_pantalla_0_row_serial_out_pin,
      banner_pantalla_0_col_clk_pin => banner_pantalla_0_col_clk_pin,
      banner_pantalla_0_col_serial_out_pin => banner_pantalla_0_col_serial_out_pin,
      Clk_pin => Clk_pin
    );

end architecture STRUCTURE;

