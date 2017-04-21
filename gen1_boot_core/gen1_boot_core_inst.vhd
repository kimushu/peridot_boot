	component gen1_boot_core is
		port (
			clk_100m_clk           : in    std_logic                     := 'X';             -- clk
			clk_25m_clk            : in    std_logic                     := 'X';             -- clk
			nios2_cpu_resetrequest : in    std_logic                     := 'X';             -- cpu_resetrequest
			nios2_cpu_resettaken   : out   std_logic;                                        -- cpu_resettaken
			reset_reset_n          : in    std_logic                     := 'X';             -- reset_n
			sci_sclk               : in    std_logic                     := 'X';             -- sclk
			sci_txd                : in    std_logic                     := 'X';             -- txd
			sci_txr_n              : out   std_logic;                                        -- txr_n
			sci_rxd                : out   std_logic;                                        -- rxd
			sci_rxr_n              : in    std_logic                     := 'X';             -- rxr_n
			sdr_addr               : out   std_logic_vector(11 downto 0);                    -- addr
			sdr_ba                 : out   std_logic_vector(1 downto 0);                     -- ba
			sdr_cas_n              : out   std_logic;                                        -- cas_n
			sdr_cke                : out   std_logic;                                        -- cke
			sdr_cs_n               : out   std_logic;                                        -- cs_n
			sdr_dq                 : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
			sdr_dqm                : out   std_logic_vector(1 downto 0);                     -- dqm
			sdr_ras_n              : out   std_logic;                                        -- ras_n
			sdr_we_n               : out   std_logic;                                        -- we_n
			swi_cpureset           : out   std_logic;                                        -- cpureset
			swi_led                : out   std_logic;                                        -- led
			swi_cso_n              : out   std_logic;                                        -- cso_n
			swi_dclk               : out   std_logic;                                        -- dclk
			swi_asdo               : out   std_logic;                                        -- asdo
			swi_data0              : in    std_logic                     := 'X'              -- data0
		);
	end component gen1_boot_core;

	u0 : component gen1_boot_core
		port map (
			clk_100m_clk           => CONNECTED_TO_clk_100m_clk,           -- clk_100m.clk
			clk_25m_clk            => CONNECTED_TO_clk_25m_clk,            --  clk_25m.clk
			nios2_cpu_resetrequest => CONNECTED_TO_nios2_cpu_resetrequest, --    nios2.cpu_resetrequest
			nios2_cpu_resettaken   => CONNECTED_TO_nios2_cpu_resettaken,   --         .cpu_resettaken
			reset_reset_n          => CONNECTED_TO_reset_reset_n,          --    reset.reset_n
			sci_sclk               => CONNECTED_TO_sci_sclk,               --      sci.sclk
			sci_txd                => CONNECTED_TO_sci_txd,                --         .txd
			sci_txr_n              => CONNECTED_TO_sci_txr_n,              --         .txr_n
			sci_rxd                => CONNECTED_TO_sci_rxd,                --         .rxd
			sci_rxr_n              => CONNECTED_TO_sci_rxr_n,              --         .rxr_n
			sdr_addr               => CONNECTED_TO_sdr_addr,               --      sdr.addr
			sdr_ba                 => CONNECTED_TO_sdr_ba,                 --         .ba
			sdr_cas_n              => CONNECTED_TO_sdr_cas_n,              --         .cas_n
			sdr_cke                => CONNECTED_TO_sdr_cke,                --         .cke
			sdr_cs_n               => CONNECTED_TO_sdr_cs_n,               --         .cs_n
			sdr_dq                 => CONNECTED_TO_sdr_dq,                 --         .dq
			sdr_dqm                => CONNECTED_TO_sdr_dqm,                --         .dqm
			sdr_ras_n              => CONNECTED_TO_sdr_ras_n,              --         .ras_n
			sdr_we_n               => CONNECTED_TO_sdr_we_n,               --         .we_n
			swi_cpureset           => CONNECTED_TO_swi_cpureset,           --      swi.cpureset
			swi_led                => CONNECTED_TO_swi_led,                --         .led
			swi_cso_n              => CONNECTED_TO_swi_cso_n,              --         .cso_n
			swi_dclk               => CONNECTED_TO_swi_dclk,               --         .dclk
			swi_asdo               => CONNECTED_TO_swi_asdo,               --         .asdo
			swi_data0              => CONNECTED_TO_swi_data0               --         .data0
		);

