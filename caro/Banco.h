#pragma once
#include "Oco.h"
#define		XDAU  50
#define		YDAU  50

class Banco
{
public:
	Oco ds[20][20];
	int nguoichoi;
	int dieukhien; //dieukhien = 1 thi duoc choi, = 0 thi khong duoc choi
	Banco();
	void vehinh(CClientDC* pdc);
	void bambanco(CClientDC* pdc, CPoint p);
	int ktthang_ngang(int mi, int mj);
	int ktthang_doc(int mi, int mj);
	int ktthang_cheophai(int mi, int mj);
	int ktthang_cheotrai(int mi, int mj);
	int ktthang(int mi, int mj);
	int uocluongdiemdi_thang(int mi, int mj);
	int uocluongdiemdi_hanche(int mi, int mj);
	void buocditieptheo(int mi, int mj, CClientDC * pdc);
	void xuatthongbaothang(CClientDC* pdc);
	void xuatthongbaohoa(CClientDC* pdc);

};

