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
    leds_rgb_0_green_pin : out std_logic;
    leds_rgb_0_blue_pin : out std_logic;
    leds_rgb_0_red_pin : out std_logic;
    Clk_pin : in std_logic;
    leds_rgb_1_blue_pin : out std_logic;
    leds_rgb_1_green_pin : out std_logic;
    leds_rgb_1_red_pin : out std_logic;
    leds_rgb_2_green_pin : out std_logic;
    leds_rgb_2_red_pin : out std_logic;
    leds_rgb_2_blue_pin : out std_logic
  );
end system_stub;

architecture STRUCTURE of system_stub is

  component system is
    port (
      Rst_pin : in std_logic;
      RX_pin : in std_logic;
      TX_pin : out std_logic;
      leds_rgb_0_green_pin : out std_logic;
      leds_rgb_0_blue_pin : out std_logic;
      leds_rgb_0_red_pin : out std_logic;
      Clk_pin : in std_logic;
      leds_rgb_1_blue_pin : out std_logic;
      leds_rgb_1_green_pin : out std_logic;
      leds_rgb_1_red_pin : out std_logic;
      leds_rgb_2_green_pin : out std_logic;
      leds_rgb_2_red_pin : out std_logic;
      leds_rgb_2_blue_pin : out std_logic
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
      leds_rgb_0_green_pin => leds_rgb_0_green_pin,
      leds_rgb_0_blue_pin => leds_rgb_0_blue_pin,
      leds_rgb_0_red_pin => leds_rgb_0_red_pin,
      Clk_pin => Clk_pin,
      leds_rgb_1_blue_pin => leds_rgb_1_blue_pin,
      leds_rgb_1_green_pin => leds_rgb_1_green_pin,
      leds_rgb_1_red_pin => leds_rgb_1_red_pin,
      leds_rgb_2_green_pin => leds_rgb_2_green_pin,
      leds_rgb_2_red_pin => leds_rgb_2_red_pin,
      leds_rgb_2_blue_pin => leds_rgb_2_blue_pin
    );

end architecture STRUCTURE;

