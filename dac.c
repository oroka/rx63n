#include "iodefine.h"

void initDAC(void);

void initDAC(void){
	SYSTEM.PRCR.WORD = 0xA502;
	SYSTEM.MSTPCRA.BIT.MSTPA19 = 0;
	SYSTEM.PRCR.WORD = 0xA500;
	
	//DA0
	PORT0.PDR.BIT.B3 = 0;
	PORT0.PMR.BIT.B3 = 0;
	//DA1
	PORT0.PDR.BIT.B5 = 0;
	PORT0.PMR.BIT.B5 = 0;
	
	MPC.PWPR.BIT.B0WI = 0;
	MPC.PWPR.BIT.PFSWE = 1;
	
	MPC.P03PFS.BIT.ASEL = 1;
	MPC.P05PFS.BIT.ASEL = 1;
	
	MPC.PWPR.BIT.PFSWE = 0;
	MPC.PWPR.BIT.B0WI = 1;
	
	DA.DADPR.BIT.DPSEL = 0;
	DA.DAADSCR.BIT.DAADST = 0;
	
	//0で個別許可,1で一括許可
	DA.DACR.BIT.DAE = 0;
	DA.DACR.BIT.DAOE0 = 0;
	DA.DACR.BIT.DAOE1 = 0;
}

