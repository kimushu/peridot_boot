	gen1_boot_core u0 (
		.clk_100m_clk           (<connected-to-clk_100m_clk>),           // clk_100m.clk
		.clk_25m_clk            (<connected-to-clk_25m_clk>),            //  clk_25m.clk
		.nios2_cpu_resetrequest (<connected-to-nios2_cpu_resetrequest>), //    nios2.cpu_resetrequest
		.nios2_cpu_resettaken   (<connected-to-nios2_cpu_resettaken>),   //         .cpu_resettaken
		.reset_reset_n          (<connected-to-reset_reset_n>),          //    reset.reset_n
		.sci_sclk               (<connected-to-sci_sclk>),               //      sci.sclk
		.sci_txd                (<connected-to-sci_txd>),                //         .txd
		.sci_txr_n              (<connected-to-sci_txr_n>),              //         .txr_n
		.sci_rxd                (<connected-to-sci_rxd>),                //         .rxd
		.sci_rxr_n              (<connected-to-sci_rxr_n>),              //         .rxr_n
		.sdr_addr               (<connected-to-sdr_addr>),               //      sdr.addr
		.sdr_ba                 (<connected-to-sdr_ba>),                 //         .ba
		.sdr_cas_n              (<connected-to-sdr_cas_n>),              //         .cas_n
		.sdr_cke                (<connected-to-sdr_cke>),                //         .cke
		.sdr_cs_n               (<connected-to-sdr_cs_n>),               //         .cs_n
		.sdr_dq                 (<connected-to-sdr_dq>),                 //         .dq
		.sdr_dqm                (<connected-to-sdr_dqm>),                //         .dqm
		.sdr_ras_n              (<connected-to-sdr_ras_n>),              //         .ras_n
		.sdr_we_n               (<connected-to-sdr_we_n>),               //         .we_n
		.swi_cpureset           (<connected-to-swi_cpureset>),           //      swi.cpureset
		.swi_led                (<connected-to-swi_led>),                //         .led
		.swi_cso_n              (<connected-to-swi_cso_n>),              //         .cso_n
		.swi_dclk               (<connected-to-swi_dclk>),               //         .dclk
		.swi_asdo               (<connected-to-swi_asdo>),               //         .asdo
		.swi_data0              (<connected-to-swi_data0>)               //         .data0
	);

