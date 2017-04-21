
module gen1_boot_core (
	clk_100m_clk,
	clk_25m_clk,
	nios2_cpu_resetrequest,
	nios2_cpu_resettaken,
	reset_reset_n,
	sci_sclk,
	sci_txd,
	sci_txr_n,
	sci_rxd,
	sci_rxr_n,
	sdr_addr,
	sdr_ba,
	sdr_cas_n,
	sdr_cke,
	sdr_cs_n,
	sdr_dq,
	sdr_dqm,
	sdr_ras_n,
	sdr_we_n,
	swi_cpureset,
	swi_led,
	swi_cso_n,
	swi_dclk,
	swi_asdo,
	swi_data0);	

	input		clk_100m_clk;
	input		clk_25m_clk;
	input		nios2_cpu_resetrequest;
	output		nios2_cpu_resettaken;
	input		reset_reset_n;
	input		sci_sclk;
	input		sci_txd;
	output		sci_txr_n;
	output		sci_rxd;
	input		sci_rxr_n;
	output	[11:0]	sdr_addr;
	output	[1:0]	sdr_ba;
	output		sdr_cas_n;
	output		sdr_cke;
	output		sdr_cs_n;
	inout	[15:0]	sdr_dq;
	output	[1:0]	sdr_dqm;
	output		sdr_ras_n;
	output		sdr_we_n;
	output		swi_cpureset;
	output		swi_led;
	output		swi_cso_n;
	output		swi_dclk;
	output		swi_asdo;
	input		swi_data0;
endmodule
