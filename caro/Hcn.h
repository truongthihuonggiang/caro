#pragma once
class Hcn
{
public:
	int x1, y1, x2, y2;
	Hcn();
	Hcn(int mx1, int my1, int mx2, int my2);
	void setHcn(int mx1, int my1, int mx2, int my2);
	void vehinh(CClientDC* pdc);
	int kiemtratronghinh(CPoint p);

};

