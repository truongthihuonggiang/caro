#pragma once
#include "Hcn.h"
class Hcnmau :
    public Hcn
{
public:
    int r;
    int g;
    int b;
    Hcnmau()
    {
        x1 = 0;
        x2 = 0;
        y1 = 0;
        y2 = 0;
        r = 0;
        g = 0;
        b = 0;
    }
    Hcnmau( int mx1, int my1, int mx2, int my2)
    {
        x1 = mx1;
        x2 = mx2;
        y1 = my1;
        y2 = my2;
    }
    void setMau(int mr, int mg, int mb)
    {
        r = mr;
        g = mg;
        b = mb;
    }
    void vehinh(CClientDC* pdc)
    {
        CPen* pen;
        pen = new CPen(PS_SOLID, 2, RGB(r, g, b));
        CPen* oldpen;
        oldpen = pdc->SelectObject(pen);
        pdc->Rectangle(x1, y1, x2, y2);
        pdc->SelectObject(oldpen);
    }
};

