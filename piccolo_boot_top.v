// ===================================================================
// TITLE : PERIDOT Piccolo - Serial boot loader
//
//   DEGISN : S.OSAFUNE (J-7SYSTEM WORKS LIMITED)
//   DATE   : 2017/03/01 -> 2017/03/03
//   UPDATE : 
//
// ===================================================================
// *******************************************************************
//       (C)2017, J-7SYSTEM WORKS LIMITED.  All rights Reserved.
//
// * This module is a free sourcecode and there is NO WARRANTY.
// * No restriction on use. You can use, modify and redistribute it
//   for personal, non-profit or commercial products UNDER YOUR
//   RESPONSIBILITY.
// * Redistributions of source code must retain the above copyright
//   notice.
// *******************************************************************


module piccolo_boot_top(
	// clk and system reset
	input wire			CLOCK_50,
	input wire			RESET_N,	// PIO19

	// Interface: Host communication
	input wire			RXD,		// PIO0
	output wire			TXD,		// PIO1

	// Interface: SDRAM
	output wire			SDRCLK_OUT,
	output wire			SDR_CKE,
	output wire			SDR_CS_N,
	output wire			SDR_RAS_N,
	output wire			SDR_CAS_N,
	output wire			SDR_WE_N,
	output wire [11:0]	SDR_A,
	output wire [1:0]	SDR_BA,
	inout wire  [15:0]	SDR_DQ,
	output wire [1:0]	SDR_DQM,

	// Interface: On board SPI-Flash
	output wire			SPI_SS_N,
	output wire			SPI_SCK,
	output wire			SPI_MOSI,
	input wire			SPI_MISO,

	// GPIO
	inout wire  [29:0]	D,			// PIO2-17,PIO20-33

	// LED
	output wire			LED			// LED:On board
);


/* ===== 外部変更可能パラメータ ========== */



/* ----- 内部パラメータ ------------------ */


/* ※以降のパラメータ宣言は禁止※ */

/* ===== ノード宣言 ====================== */
				/* 内部は全て正論理リセットとする。ここで定義していないノードの使用は禁止 */
	wire			reset_sig = ~RESET_N;			// モジュール内部駆動非同期リセット 

				/* 内部は全て正エッジ駆動とする。ここで定義していないクロックノードの使用は禁止 */
	wire			clock_sig = CLOCK_50;			// モジュール内部駆動クロック 

	wire			qsys_reset_n_sig;
	wire			clock_core_sig;
	wire			clock_peri_sig;
	wire			cpureset_sig;
	reg  [1:0]		resetreq_reg;
	wire [3:0]		led_sig;


/* ※以降のwire、reg宣言は禁止※ */

/* ===== テスト記述 ============== */



/* ===== モジュール構造記述 ============== */

	///// PLLとQsysコアのインスタンス /////

	syspll
	u0 (
		.areset		(reset_sig),
		.inclk0		(clock_sig),
		.c0			(SDRCLK_OUT),
		.c1			(clock_core_sig),
		.c2			(clock_peri_sig),
		.locked		(qsys_reset_n_sig)
	);


	ngs_boot_core
	u1 (
        .reset_reset_n   (qsys_reset_n_sig),		//    reset.reset_n
        .clk_100m_clk    (clock_core_sig),			// clk_100m.clk
        .clk_25m_clk     (clock_peri_sig),			//  clk_25m.clk

        .mreset_mreset_n (qsys_reset_n_sig),		//   mreset.mreset_n
        .hostuart_rxd    (RXD),						// hostuart.rxd
        .hostuart_txd    (TXD),						//         .txd

        .nios2_cpu_resetrequest (resetreq_reg[1]),	//    nios2.cpu_resetrequest <-- NiosIIのバストランザクションを完了させるリセット要求 
        .nios2_cpu_resettaken   (),					//         .cpu_resettaken

        .sdr_addr        (SDR_A),					//      sdr.addr
        .sdr_ba          (SDR_BA),					//         .ba
        .sdr_cs_n        (SDR_CS_N),				//         .cs_n
        .sdr_ras_n       (SDR_RAS_N),				//         .ras_n
        .sdr_cas_n       (SDR_CAS_N),				//         .cas_n
        .sdr_we_n        (SDR_WE_N),				//         .we_n
        .sdr_dq          (SDR_DQ),					//         .dq
        .sdr_dqm         (SDR_DQM),					//         .dqm
        .sdr_cke         (SDR_CKE),					//         .cke

        .swi_cpu_resetrequest   (cpureset_sig),		//      swi.cpu_resetrequest
        .swi_led         (led_sig),					//         .led
        .epcs_cso_n      (SPI_SS_N),				//     epcs.cso_n
        .epcs_dclk       (SPI_SCK),					//         .dclk
        .epcs_asdo       (SPI_MOSI),				//         .asdo
        .epcs_data0      (SPI_MISO),				//         .data0

        .gpio_export     (D)						//     gpio.export
    );

	assign LED = led_sig[0];


	// cpu_resetrequest信号の同期化 

	always @(posedge clock_core_sig or negedge qsys_reset_n_sig) begin
		if (!qsys_reset_n_sig) begin
			resetreq_reg <= 2'b00;
		end
		else begin
			resetreq_reg <= {resetreq_reg[0], cpureset_sig};
		end
	end




endmodule
