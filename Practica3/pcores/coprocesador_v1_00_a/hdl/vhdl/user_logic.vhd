------------------------------------------------------------------------------
-- user_logic.vhd - entity/architecture pair
------------------------------------------------------------------------------
--
-- ***************************************************************************
-- ** Copyright (c) 1995-2012 Xilinx, Inc.  All rights reserved.            **
-- **                                                                       **
-- ** Xilinx, Inc.                                                          **
-- ** XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS"         **
-- ** AS A COURTESY TO YOU, SOLELY FOR USE IN DEVELOPING PROGRAMS AND       **
-- ** SOLUTIONS FOR XILINX DEVICES.  BY PROVIDING THIS DESIGN, CODE,        **
-- ** OR INFORMATION AS ONE POSSIBLE IMPLEMENTATION OF THIS FEATURE,        **
-- ** APPLICATION OR STANDARD, XILINX IS MAKING NO REPRESENTATION           **
-- ** THAT THIS IMPLEMENTATION IS FREE FROM ANY CLAIMS OF INFRINGEMENT,     **
-- ** AND YOU ARE RESPONSIBLE FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE      **
-- ** FOR YOUR IMPLEMENTATION.  XILINX EXPRESSLY DISCLAIMS ANY              **
-- ** WARRANTY WHATSOEVER WITH RESPECT TO THE ADEQUACY OF THE               **
-- ** IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO ANY WARRANTIES OR        **
-- ** REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE FROM CLAIMS OF       **
-- ** INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS       **
-- ** FOR A PARTICULAR PURPOSE.                                             **
-- **                                                                       **
-- ***************************************************************************
--
------------------------------------------------------------------------------
-- Filename:          user_logic.vhd
-- Version:           1.00.a
-- Description:       User logic.
-- Date:              Mon Nov 30 22:50:45 2020 (by Create and Import Peripheral Wizard)
-- VHDL Standard:     VHDL'93
------------------------------------------------------------------------------
-- Naming Conventions:
--   active low signals:                    "*_n"
--   clock signals:                         "clk", "clk_div#", "clk_#x"
--   reset signals:                         "rst", "rst_n"
--   generics:                              "C_*"
--   user defined types:                    "*_TYPE"
--   state machine next state:              "*_ns"
--   state machine current state:           "*_cs"
--   combinatorial signals:                 "*_com"
--   pipelined or register delay signals:   "*_d#"
--   counter signals:                       "*cnt*"
--   clock enable signals:                  "*_ce"
--   internal version of output port:       "*_i"
--   device pins:                           "*_pin"
--   ports:                                 "- Names begin with Uppercase"
--   processes:                             "*_PROCESS"
--   component instantiations:              "<ENTITY_>I_<#|FUNC>"
------------------------------------------------------------------------------

-- DO NOT EDIT BELOW THIS LINE --------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

library proc_common_v3_00_a;
use proc_common_v3_00_a.proc_common_pkg.all;

-- DO NOT EDIT ABOVE THIS LINE --------------------

--USER libraries added here

------------------------------------------------------------------------------
-- Entity section
------------------------------------------------------------------------------
-- Definition of Generics:
--   C_SLV_DWIDTH                 -- Slave interface data bus width
--   C_NUM_REG                    -- Number of software accessible registers
--
-- Definition of Ports:
--   Bus2IP_Clk                   -- Bus to IP clock
--   Bus2IP_Reset                 -- Bus to IP reset
--   Bus2IP_Data                  -- Bus to IP data bus
--   Bus2IP_BE                    -- Bus to IP byte enables
--   Bus2IP_RdCE                  -- Bus to IP read chip enable
--   Bus2IP_WrCE                  -- Bus to IP write chip enable
--   IP2Bus_Data                  -- IP to Bus data bus
--   IP2Bus_RdAck                 -- IP to Bus read transfer acknowledgement
--   IP2Bus_WrAck                 -- IP to Bus write transfer acknowledgement
--   IP2Bus_Error                 -- IP to Bus error response
------------------------------------------------------------------------------

entity user_logic is
  generic
  (
    -- ADD USER GENERICS BELOW THIS LINE ---------------
    --USER generics added here
    -- ADD USER GENERICS ABOVE THIS LINE ---------------

    -- DO NOT EDIT BELOW THIS LINE ---------------------
    -- Bus protocol parameters, do not add to or delete
    C_SLV_DWIDTH                   : integer              := 32;
    C_NUM_REG                      : integer              := 4
    -- DO NOT EDIT ABOVE THIS LINE ---------------------
  );
  port
  (
    -- ADD USER PORTS BELOW THIS LINE ------------------
    --USER ports added here
	 leds : out std_logic_vector(0 to 7);
	 switches : in std_logic_vector(0 to 3);
    -- ADD USER PORTS ABOVE THIS LINE ------------------

    -- DO NOT EDIT BELOW THIS LINE ---------------------
    -- Bus protocol ports, do not add to or delete
    Bus2IP_Clk                     : in  std_logic;
    Bus2IP_Reset                   : in  std_logic;
    Bus2IP_Data                    : in  std_logic_vector(0 to C_SLV_DWIDTH-1);
    Bus2IP_BE                      : in  std_logic_vector(0 to C_SLV_DWIDTH/8-1);
    Bus2IP_RdCE                    : in  std_logic_vector(0 to C_NUM_REG-1);
    Bus2IP_WrCE                    : in  std_logic_vector(0 to C_NUM_REG-1);
    IP2Bus_Data                    : out std_logic_vector(0 to C_SLV_DWIDTH-1);
    IP2Bus_RdAck                   : out std_logic;
    IP2Bus_WrAck                   : out std_logic;
    IP2Bus_Error                   : out std_logic
    -- DO NOT EDIT ABOVE THIS LINE ---------------------
  );

  attribute MAX_FANOUT : string;
  attribute SIGIS : string;

  attribute SIGIS of Bus2IP_Clk    : signal is "CLK";
  attribute SIGIS of Bus2IP_Reset  : signal is "RST";

end entity user_logic;

------------------------------------------------------------------------------
-- Architecture section
------------------------------------------------------------------------------

architecture IMP of user_logic is

  --USER signal declarations added here, as needed for user logic
  
--	component contador is 
--	  Port ( clk : in  STD_LOGIC;
--				  reset : in  STD_LOGIC;
--				  cout : out  STD_LOGIC_VECTOR (7 downto 0));
--	end component;
	signal resul_contador : std_logic_vector(7 downto 0);
	
	
--	component divisor1 is 
--		port (
--			  rst: in STD_LOGIC;
--			  clk_in: in STD_LOGIC;
--			  clk_out: out STD_LOGIC
--		 );
--	end component;
	signal div_out : std_logic;
	
	signal resultado: std_logic_vector(0 to C_SLV_DWIDTH-1);
	signal cnt_aux : std_logic_vector(7 downto 0);
	SIGNAL cuenta: std_logic_vector(26 downto 0);
   --SIGNAL clk, clk_aux: std_logic;
  ------------------------------------------
  -- Signals for user logic slave model s/w accessible register example
  ------------------------------------------
  signal slv_reg0                       : std_logic_vector(0 to C_SLV_DWIDTH-1);
  signal slv_reg1                       : std_logic_vector(0 to C_SLV_DWIDTH-1);
  signal slv_reg2                       : std_logic_vector(0 to C_SLV_DWIDTH-1);
  signal slv_reg3                       : std_logic_vector(0 to C_SLV_DWIDTH-1);
  signal slv_reg_write_sel              : std_logic_vector(0 to 3);
  signal slv_reg_read_sel               : std_logic_vector(0 to 3);
  signal slv_ip2bus_data                : std_logic_vector(0 to C_SLV_DWIDTH-1);
  signal slv_read_ack                   : std_logic;
  signal slv_write_ack                  : std_logic;

begin

  --USER logic implementation added here
--	DVSOR: divisor1 port map(Bus2IP_Reset,Bus2IP_Clk,div_out);
--	CNT: contador port map (div_out,Bus2IP_Reset,resul_contador);
	

	
  ------------------------------------------
  -- Example code to read/write user logic slave model s/w accessible registers
  -- 
  -- Note:
  -- The example code presented here is to show you one way of reading/writing
  -- software accessible registers implemented in the user logic slave model.
  -- Each bit of the Bus2IP_WrCE/Bus2IP_RdCE signals is configured to correspond
  -- to one software accessible register by the top level template. For example,
  -- if you have four 32 bit software accessible registers in the user logic,
  -- you are basically operating on the following memory mapped registers:
  -- 
  --    Bus2IP_WrCE/Bus2IP_RdCE   Memory Mapped Register
  --                     "1000"   C_BASEADDR + 0x0
  --                     "0100"   C_BASEADDR + 0x4
  --                     "0010"   C_BASEADDR + 0x8
  --                     "0001"   C_BASEADDR + 0xC
  -- 
  ------------------------------------------
--  slv_reg_write_sel <= Bus2IP_WrCE(0 to 3);
--  slv_reg_read_sel  <= Bus2IP_RdCE(0 to 3);
--  slv_write_ack     <= Bus2IP_WrCE(0) or Bus2IP_WrCE(1) or Bus2IP_WrCE(2) or Bus2IP_WrCE(3);
--  slv_read_ack      <= Bus2IP_RdCE(0) or Bus2IP_RdCE(1) or Bus2IP_RdCE(2) or Bus2IP_RdCE(3);


  -- implement slave model software accessible register(s)
--  SLAVE_REG_WRITE_PROC : process( Bus2IP_Clk ) is
--  begin
--
--    if Bus2IP_Clk'event and Bus2IP_Clk = '1' then
--      if Bus2IP_Reset = '1' then
--        slv_reg0 <= (others => '0');
--        slv_reg1 <= (others => '0');
--        slv_reg2 <= (others => '0');
--        slv_reg3 <= (others => '0');
--      else
--        case slv_reg_write_sel is
--          when "1000" =>
--            for byte_index in 0 to (C_SLV_DWIDTH/8)-1 loop
--              if ( Bus2IP_BE(byte_index) = '1' ) then
--                slv_reg0(byte_index*8 to byte_index*8+7) <= Bus2IP_Data(byte_index*8 to byte_index*8+7);
--              end if;
--            end loop;
--          when "0100" =>
--            for byte_index in 0 to (C_SLV_DWIDTH/8)-1 loop
--              if ( Bus2IP_BE(byte_index) = '1' ) then
--                slv_reg1(byte_index*8 to byte_index*8+7) <= Bus2IP_Data(byte_index*8 to byte_index*8+7);
--              end if;
--            end loop;
--          when "0010" =>
--            for byte_index in 0 to (C_SLV_DWIDTH/8)-1 loop
--              if ( Bus2IP_BE(byte_index) = '1' ) then
--                slv_reg2(byte_index*8 to byte_index*8+7) <= Bus2IP_Data(byte_index*8 to byte_index*8+7);
--              end if;
--            end loop;
--          when "0001" =>
--            for byte_index in 0 to (C_SLV_DWIDTH/8)-1 loop
--              if ( Bus2IP_BE(byte_index) = '1' ) then
--                slv_reg3(byte_index*8 to byte_index*8+7) <= Bus2IP_Data(byte_index*8 to byte_index*8+7);
--              end if;
--            end loop;
--          when others => null;
--        end case;
--      end if;
--    end if;
--
--  end process SLAVE_REG_WRITE_PROC;
--
--  -- implement slave model software accessible register(s) read mux
--  SLAVE_REG_READ_PROC : process( slv_reg_read_sel, slv_reg0, slv_reg1, slv_reg2, slv_reg3 ) is
--  begin
--
--    case slv_reg_read_sel is
--      when "1000" => slv_ip2bus_data <= slv_reg0;
--      when "0100" => slv_ip2bus_data <= slv_reg1;
--      when "0010" => slv_ip2bus_data <= slv_reg2;
--      when "0001" => slv_ip2bus_data <= slv_reg3;
--      when others => slv_ip2bus_data <= (others => '0');
--    end case;
--
--  end process SLAVE_REG_READ_PROC;
  
  ------------------------------------------
  -- Apartado a
  ------------------------------------------
  APA: process(slv_reg1,slv_reg2,slv_reg3,Bus2IP_Clk,Bus2IP_Reset) is
  begin
		if Bus2IP_Reset = '1' then
			slv_reg3 <= (others=>'0');
		else
			if Bus2IP_Clk'event and Bus2IP_Clk = '1' then
				if slv_reg0(31) = '0' then
					slv_reg3 <= unsigned(slv_reg1) + unsigned(slv_reg2);
				else
					slv_reg3 <= unsigned(slv_reg1) - unsigned(slv_reg2);
				end if;
			end if;
		end if; 
  end process APA;
  
  
  ------------------------------------------
  -- Apartado b
  --
	--  0 0 x 0
	--  0 1 x 0
	--  1 0 x 0
	--  1 1 x 0
  ------------------------------------------
  
  APB: process (switches, slv_reg0,slv_reg1,slv_reg2,slv_reg3,resul_contador) is 
  begin
  if switches(3) = '0' then 
		if switches(0 to 1) = "00"  then 
			leds <= slv_reg0(0 to 7);
		elsif switches(0 to 1) = "01" then
			leds <= slv_reg1(0 to 7);
		elsif switches(0 to 1) = "10" then
			leds <= slv_reg2(0 to 7);
		elsif switches(0 to 1) = "11" then --lo que hay en el contador o reg3 �?
			leds <= slv_reg3(0 to 7);
		end if;
	elsif switches(3) = '1' then	 
		cnt_aux <= resul_contador; 
		leds <= cnt_aux;
  end if;
  end process APB;
  
 divisor: process(Bus2IP_Clk,Bus2IP_Reset) is
	begin
		IF (Bus2IP_Reset='1') THEN
			cuenta<= (OTHERS=>'0');
		ELSIF(Bus2IP_Clk'EVENT AND Bus2IP_Clk='1') THEN
		IF (cuenta="101111101011110000100000000") THEN
			div_out <= not div_out;
		  cuenta<= (OTHERS=>'0');
		ELSE
		  cuenta <= cuenta+'1';
		END IF;
		END IF;
		 
	end process divisor;
 
	 contador : process(div_out,Bus2IP_Reset)
		begin
			
			if Bus2IP_Reset = '1' then
				resul_contador <= (others=>'0');
			elsif div_out'event and div_out='1' then --clk divisor
				if resul_contador = "11111111" then
					resul_contador<="00000000";
				else
					resul_contador<= unsigned(resul_contador)+1;
				end if;
			end if;
			
		end process contador;


  
  
--  leds<= slv_reg3(0 to 7) when switches = "1000" else
--			slv_reg2(0 to 7) when switches = "0100" else
--			slv_reg1(0 to 7) when switches = "0010" else
--			slv_reg0(0 to 7);
--  
  

--  ------------------------------------------
--  -- Example code to drive IP to Bus signals
--  ------------------------------------------
--  IP2Bus_Data  <= slv_ip2bus_data when slv_read_ack = '1' else
--                  (others => '0');
--
--  IP2Bus_WrAck <= slv_write_ack;
--  IP2Bus_RdAck <= slv_read_ack;
--  IP2Bus_Error <= '0';

end IMP;