#include "pch.h"
#include "Oco.h"

Oco::Oco()
{
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	giatri = 0;
	
}

Oco::Oco(int mx1, int my1)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx1 + DAI;
	y2 = my1 + DAI;
	giatri = 0;
}

void Oco::vehinh(CClientDC* pdc)
{
	Hcn::vehinh(pdc);
	CString strx, stro;
	strx.Format(_T("X"));
	stro.Format(_T("O"));
	int xmoi = (x2 + x1) / 2 - 8;
	int ymoi = (y2 + y1) / 2 - 10;
	if (giatri == 1)
		pdc->TextOutW(xmoi, ymoi, stro);
	if (giatri == -1)
		pdc->TextOutW(xmoi, ymoi, strx);
}

int Oco::bamoco(CClientDC* pdc, CPoint p, int mgiatri)
{
	if (kiemtratronghinh(p) == 1)
	{
		giatri = mgiatri;
		vehinh(pdc);
		return 1;
	}
	else
		return 0;
}
