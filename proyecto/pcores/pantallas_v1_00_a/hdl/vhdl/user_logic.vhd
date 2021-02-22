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
-- Date:              Wed Oct 16 18:25:11 2013 (by Create and Import Peripheral Wizard)
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
--   IP2WFIFO_RdReq               -- IP to WFIFO : IP read request
--   WFIFO2IP_Data                -- WFIFO to IP : WFIFO read data
--   WFIFO2IP_RdAck               -- WFIFO to IP : WFIFO read acknowledge
--   WFIFO2IP_AlmostEmpty         -- WFIFO to IP : WFIFO almost empty
--   WFIFO2IP_Empty               -- WFIFO to IP : WFIFO empty
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
    C_NUM_REG                      : integer              := 1
    -- DO NOT EDIT ABOVE THIS LINE ---------------------
  );
  port
  (
    -- ADD USER PORTS BELOW THIS LINE ------------------
    --USER ports added here
    -- ADD USER PORTS ABOVE THIS LINE ------------------
		col_serial_out: out std_logic;	-- rs en lcd
		col_clk: out std_logic;         
		row_serial_out: out std_logic;  --lcd_data<0> en lcd
		row_clk: out std_logic;         --lcd_data<1> en lcd
		reset_out: out std_logic;       -- e en lcd
		reset2_out: out std_logic;      -- lcd_data<2> en lcd
    lcd_data_ext : OUT   STD_LOGIC_VECTOR(7 DOWNTO 0);
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
    IP2Bus_Error                   : out std_logic;
    IP2WFIFO_RdReq                 : out std_logic;
    WFIFO2IP_Data                  : in  std_logic_vector(0 to C_SLV_DWIDTH-1);
    WFIFO2IP_RdAck                 : in  std_logic;
    WFIFO2IP_AlmostEmpty           : in  std_logic;
    WFIFO2IP_Empty                 : in  std_logic
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
component  bannerDesp is
	port
	(
		reset_in: in std_logic;	-- reset
		clock: in std_logic; -- 
		col_serial_out: out std_logic;	
		col_clk: out std_logic;
		row_serial_out: out std_logic; 
		row_clk: out std_logic; 
		reset_out: out std_logic;
		reset2_out: out std_logic;
		fila: in std_logic_vector (2 downto 0);
		columna: in std_logic_vector ( 2 downto 0);
		dato: in std_logic_vector (4 downto 0);
		load: in std_logic
	);
end component;
	type statesLectura is (estadoEsperaLectura, estadoEnviarDato);
	signal currentStateLectura, nextStateLectura : statesLectura;

	signal fifo_rdreq_cmb_banner : std_logic;
	signal fila: std_logic_vector (2 downto 0);
	signal 	columna: std_logic_vector ( 2 downto 0);
	signal 	dato:  std_logic_vector (4 downto 0);
	signal 	load_banner:  std_logic;

  --señales auxiliares de banner
  signal col_serial_out_aux : std_logic;
  signal col_clk_aux :std_logic;
  signal reset_out_aux : std_logic; 
  signal row_clk_aux : std_logic; 
  signal row_serial_out_aux: std_logic;
  signal reset2_out_aux : std_logic;

  component lcd_controller
	  PORT(
		 clk        : IN    STD_LOGIC;  --system clock
		 reset    	: IN    STD_LOGIC;  --active high reinitializes lcd
		 lcd_enable : IN    STD_LOGIC;  --latches data into lcd controller
		 lcd_bus    : IN    STD_LOGIC_VECTOR(9 DOWNTO 0);  --data and control signals
		 busy       : OUT   STD_LOGIC := '1';  --lcd controller busy/idle feedback
		 rw, rs, e  : OUT   STD_LOGIC;  --read/write, setup/data, and enable for lcd
		 lcd_data   : OUT   STD_LOGIC_VECTOR(7 DOWNTO 0)); --data signals for lcd
	END component;

  signal lcd_bus : STD_LOGIC_VECTOR(9 DOWNTO 0);
	signal busy : std_logic;
  signal lcd_data: std_logic_vector(7 downto 0);
------------------------------------
--señales auxiliares de lcd
signal fifo_rdreq_cmb_lcd : std_logic;
signal rw :std_logic ; 
signal rs : std_logic;
signal e : std_logic;
signal load_lcd : std_logic;

-- controlador de componente (lcd/banner) "1" banner , "0" lcd
signal dispositivo : std_logic;

begin

  --Determinamos que en la fifo el bit 0 al 1 determinara el componente a enviar el dato 
  dispositivo <= WFIFO2IP_Data(0);

  --Pasamos las señales para el lcd 
  lcd_bus(0) <= WFIFO2IP_Data(31);
	lcd_bus(1) <= WFIFO2IP_Data(30);
	lcd_bus(2) <= WFIFO2IP_Data(29);
	lcd_bus(3) <= WFIFO2IP_Data(28);
	lcd_bus(4) <= WFIFO2IP_Data(27);
	lcd_bus(5) <= WFIFO2IP_Data(26);
	lcd_bus(6) <= WFIFO2IP_Data(25);
	lcd_bus(7) <= WFIFO2IP_Data(24);
	lcd_bus(8) <= WFIFO2IP_Data(23);  
	lcd_bus(9) <= WFIFO2IP_Data(22); 

  
  fila(2 downto 0) <= WFIFO2IP_Data(5 to 7);
  columna(2 downto 0) <= WFIFO2IP_Data(13 to 15);
  dato(4 downto 0)<=WFIFO2IP_Data(19 to 23);
  
------------------------   Mapeo   --------------------
  lcd_controller_i : lcd_controller
  PORT MAP(
		 clk        => Bus2IP_Clk,
		 reset	   => Bus2IP_Reset,
		 lcd_enable => load_lcd,
		 lcd_bus    => lcd_bus,
		 busy       => busy,
		 rw			=> rw, 
		 rs			=> rs, 
		 e  			=> e,
		 lcd_data   => lcd_data
		);

  
  mybanner: bannerDesp 
  port map (
        reset_in            =>  Bus2IP_Reset ,
        clock               =>  Bus2IP_Clk ,  
        col_serial_out      =>  col_serial_out_aux,
        col_clk             =>  col_clk_aux,
        row_serial_out      =>  row_serial_out_aux,
        row_clk             =>  row_clk_aux,
        reset_out           =>  reset_out_aux, 
        reset2_out          =>  reset2_out_aux, 
        fila                =>  fila,
        columna             =>  columna,
        dato                =>  dato,
        load                =>  load_banner
    );
	------------------------ Fin Mapeo --------------------

	-- Maquinas de estados		
		unidadDeControl: process(currentStateLectura, WFIFO2IP_empty)
		begin
		
			nextStateLectura <= currentStateLectura;
			load_lcd <= '0';
      load_banner <= '0';
			fifo_rdreq_cmb_banner <= '0';
      fifo_rdreq_cmb_lcd <= '0';
		
			case currentStateLectura is
			
				when estadoEsperaLectura =>
					if (WFIFO2IP_empty = '0' and busy = '0')  then
            if dispositivo = '0' then 
              fifo_rdreq_cmb_lcd <='1';
            else
              fifo_rdreq_cmb_banner <= '1';
            end if;
						nextStateLectura   <= estadoEnviarDato ;
					end if;
					--WFIFO2IP_RdAck: Active high signal indicating that the PFIFO is outputting data from the requested read operation. 
          --The data is valid at the next low to high transition of the Bus_clk.
				when estadoEnviarDato =>
          if (WFIFO2IP_RdAck = '1') then 
            if dispositivo = '0' then 
              load_lcd <='1';
            else
              load_banner <= '1';
            end if;
            nextStateLectura   <= estadoEsperaLectura;
          end if;
				end case;
		end process unidadDeControl;

    --IP2WFIFO_RdReq: Active high input used to signal the Write PFIFO that the IP 
    --is requesting a data transfer (read) from the Write PFIFO.
		state: process (Bus2IP_Clk)
		begin		
    
        if dispositivo = '0' then
            row_serial_out <= rs;
            row_clk <= rw;
            reset_out <= e;
            col_serial_out <= lcd_data(0);
            col_clk <= lcd_data(1);
            reset2_out <= lcd_data(2);
            lcd_data_ext <= lcd_data;
        else
            row_serial_out <= col_serial_out_aux;
            row_clk <= col_clk_aux;
            reset_out <= reset_out_aux;
            col_serial_out <= row_serial_out_aux;
            col_clk <= row_clk_aux;
            reset2_out <= reset2_out_aux;
        end if;

			  if Bus2IP_Clk'EVENT and Bus2IP_Clk='1' then
				 if Bus2IP_Reset = '1' then
            currentStateLectura <= estadoEsperaLectura;
            IP2WFIFO_RdReq <= '0';
				 else
            currentStateLectura <= nextStateLectura;
            if dispositivo = '0' then
              IP2WFIFO_RdReq <= fifo_rdreq_cmb_lcd;
            else
              IP2WFIFO_RdReq <= fifo_rdreq_cmb_banner;
            end if;
            --IP2WFIFO_RdReq <= fifo_rdreq_cmb;
				 end if;
			  end if;
		end process state;



  ------------------------------------------
  -- Example code to drive IP to Bus signals
  ------------------------------------------
  IP2Bus_Data  <= (others => '0');

  IP2Bus_WrAck <= '0';
  IP2Bus_RdAck <= '0';
  IP2Bus_Error <= '0';

end IMP;
