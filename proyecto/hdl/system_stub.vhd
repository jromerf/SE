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
    keypad_0_S_pin : out std_logic_vector(3 downto 0);
    keypad_0_R_pin : in std_logic_vector(3 downto 0);
    Clk_pin : in std_logic;
    banner_0_reset2_out_pin : out std_logic;
    banner_0_reset_out_pin : out std_logic;
    banner_0_col_clk_pin : out std_logic;
    banner_0_row_clk_pin : out std_logic;
    banner_0_col_serial_out_pin : out std_logic;
    banner_0_row_serial_out_pin : out std_logic;
    banner_0_switch_pin : in std_logic;
    banner_0_led_pin : out std_logic
  );
end system_stub;

architecture STRUCTURE of system_stub is

  component system is
    port (
      Rst_pin : in std_logic;
      RX_pin : in std_logic;
      TX_pin : out std_logic;
      keypad_0_S_pin : out std_logic_vector(3 downto 0);
      keypad_0_R_pin : in std_logic_vector(3 downto 0);
      Clk_pin : in std_logic;
      banner_0_reset2_out_pin : out std_logic;
      banner_0_reset_out_pin : out std_logic;
      banner_0_col_clk_pin : out std_logic;
      banner_0_row_clk_pin : out std_logic;
      banner_0_col_serial_out_pin : out std_logic;
      banner_0_row_serial_out_pin : out std_logic;
      banner_0_switch_pin : in std_logic;
      banner_0_led_pin : out std_logic
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
      keypad_0_S_pin => keypad_0_S_pin,
      keypad_0_R_pin => keypad_0_R_pin,
      Clk_pin => Clk_pin,
      banner_0_reset2_out_pin => banner_0_reset2_out_pin,
      banner_0_reset_out_pin => banner_0_reset_out_pin,
      banner_0_col_clk_pin => banner_0_col_clk_pin,
      banner_0_row_clk_pin => banner_0_row_clk_pin,
      banner_0_col_serial_out_pin => banner_0_col_serial_out_pin,
      banner_0_row_serial_out_pin => banner_0_row_serial_out_pin,
      banner_0_switch_pin => banner_0_switch_pin,
      banner_0_led_pin => banner_0_led_pin
    );

end architecture STRUCTURE;

