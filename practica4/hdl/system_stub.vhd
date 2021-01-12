-------------------------------------------------------------------------------
-- system_stub.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

entity system_stub is
  port (
    Clk_pin : in std_logic;
    Rst_pin : in std_logic;
    RX_pin : in std_logic;
    TX_pin : out std_logic;
    leds_pin : inout std_logic_vector(0 to 7);
    switches_pin : inout std_logic_vector(0 to 7);
    pantalla_0_hsyncb_pin : out std_logic;
    pantalla_0_vsyncb_pin : out std_logic;
    pantalla_0_rgb_pin : out std_logic_vector(0 to 8)
  );
end system_stub;

architecture STRUCTURE of system_stub is

  component system is
    port (
      Clk_pin : in std_logic;
      Rst_pin : in std_logic;
      RX_pin : in std_logic;
      TX_pin : out std_logic;
      leds_pin : inout std_logic_vector(0 to 7);
      switches_pin : inout std_logic_vector(0 to 7);
      pantalla_0_hsyncb_pin : out std_logic;
      pantalla_0_vsyncb_pin : out std_logic;
      pantalla_0_rgb_pin : out std_logic_vector(0 to 8)
    );
  end component;

  attribute BOX_TYPE : STRING;
  attribute BOX_TYPE of system : component is "user_black_box";

begin

  system_i : system
    port map (
      Clk_pin => Clk_pin,
      Rst_pin => Rst_pin,
      RX_pin => RX_pin,
      TX_pin => TX_pin,
      leds_pin => leds_pin,
      switches_pin => switches_pin,
      pantalla_0_hsyncb_pin => pantalla_0_hsyncb_pin,
      pantalla_0_vsyncb_pin => pantalla_0_vsyncb_pin,
      pantalla_0_rgb_pin => pantalla_0_rgb_pin
    );

end architecture STRUCTURE;

