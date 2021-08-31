#include "pch.h"
#include "Banco.h"

Banco::Banco()
{
	int i = 0, j = 0;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			ds[i][j] = Oco(XDAU + DAI * j, YDAU + DAI * i);
		}
	}
	nguoichoi = 1;
	dieukhien = 1; //duoc choi
}

void Banco::vehinh(CClientDC* pdc)
{
	int i = 0, j = 0;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			ds[i][j].vehinh(pdc);
		}
	}
}

void Banco::bambanco(CClientDC* pdc,CPoint p)
{
	int i = 0, j = 0;
	if (dieukhien == 1)
	{
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 20; j++)
				if (ds[i][j].giatri == 0)
				{
					if (ds[i][j].bamoco(pdc, p, nguoichoi) == 1)
						if (ktthang(i, j) == 1)//neu thang
						{
							dieukhien = 0;
							/////thong bao nguoi choi thang
							xuatthongbaothang(pdc);
						}
						else
						{
							nguoichoi = nguoichoi * -1;//doinguoichoi
							///goi phuong thuc buoc di tiep theo
							buocditieptheo(i, j, pdc);
						}
						
				}

		}
	}
	
}

int Banco::ktthang_ngang(int mi, int mj)
{
	int i = mi;
	int j = mj;
	int dem = 0;
	//dem qua ben trai
	for (j = mj - 1; j >= 0; j--)
		if (ds[i][j].giatri == nguoichoi)
			dem++;
		else
			break;
	//dem qua ben phai
	for (j = mj + 1; j < 20; j++)
	{
		if (ds[i][j].giatri == nguoichoi)
			dem++;
		else
			break;
	}
	if (dem >= 4)
		return 1;
	else
		return 0;
	
}

int Banco::ktthang_doc(int mi, int mj)
{
	int i = mi, j = mj;
	int dem = 0;
	//kiem tra len tren;
	for (i = mi - 1; i >= 0; i--)
	{
		if (ds[i][j].giatri == nguoichoi)
			dem++;
		else
			break;
	}
	//kiem tra xuong duoi
	for (i = mi + 1; i < 20; i++)
	{
		if (ds[i][j].giatri == nguoichoi)
			dem++;
		else
			break;
	}
	if (dem >= 4)
		return 1;
	else
		return 0;
	
}

int Banco::ktthang_cheophai(int mi, int mj)
{
	int i = mi;
	int j = mj;
	int dem = 0;
	//kiem tra cheo phai tren, i giam va j tang
	i = mi - 1;
	j = mj + 1;
	while (i >= 0 && j < 20)
	{
		if (ds[i][j].giatri == nguoichoi)
			dem++;
		else
			break;
		i--;
		j++;
	}
	//kiem tra cheo phai duoi, i tang va j giam
	i = mi + 1;
	j = mj - 1;
	while (i < 20 && j >= 0)
	{
		if (ds[i][j].giatri == nguoichoi)
			dem++;
		else
			break;
		i++;
		j--;
	}
	if (dem >= 4)
		return 1;
	else
		return 0;
}

int Banco::ktthang_cheotrai(int mi, int mj)
{
	int i = mi;
	int j = mj;
	int dem = 0;
	//kiem tra cheo len tren, ca i va j cung giam
	i = mi - 1;
	j = mj - 1;
	while (i >= 0 && j >= 0)
	{
		if (ds[i][j].giatri == nguoichoi)
			dem++;
		else
			break;
		i--;
		j--;
	}
	// kiem tra cheo xuong duoi, cai va j cung tang
	i = mi + 1;
	j = mj + 1;
	while (i < 20 && j < 20)
	{
		if (ds[i][j].giatri == nguoichoi)
			dem++;
		else
			break;
		i++;
		j++;
	}
	if (dem >= 4)
		return 1;
	else
		return 0;
}

int Banco::ktthang(int mi, int mj)
{
	int kq = 0;
	if (ktthang_ngang(mi, mj) == 1)
		kq = 1;
	else
		if (ktthang_doc(mi, mj) == 1)
			kq = 1;
		else
			if (ktthang_cheotrai(mi, mj) == 1)
				kq = 1;
			else
				if (ktthang_cheophai(mi, mj) == 1)
					kq = 1;
	return kq;
}

int Banco::uocluongdiemdi_thang(int mi, int mj)
{
	//dem chieu doc di len
	int i = mi, j = mj;
	int dem = 0;
	int k = 20;
	int m = 2;
	int count = 0;
	//kiem tra len tren;
	for (i = mi - 1; i >= 0; i--)
	{
		if (ds[i][j].giatri == nguoichoi)
		{
			dem = dem +(k - mi + i) * m;
			count++;
		}
		if (ds[i][j].giatri ==0)
			m = 1;
		if (ds[i][j].giatri == nguoichoi * -1)
			break;
	}
	//kiem tra doc di xuong
	i = mi;
	j = mj;
	for (i = mi + 1; i < 20; i++)
	{
		if (ds[i][j].giatri == nguoichoi)
		{
			dem = dem + (k - i + mi) * m;
			count++;
		}
		if (ds[i][j].giatri == 0)
			m = 1;
		if (ds[i][j].giatri == nguoichoi * -1)
			break;
	}
	if (count >= 3)
		dem = dem * count*100;
	count = 0;
	i = mi;
	j = mj;
	//kiem tra chieu ngang trai
	for (j = mj - 1; j >= 0; j--)
	{
		if (ds[i][j].giatri == nguoichoi)
		{
			dem = dem + (k -( mj - j)) * m;
			count++;
		}
		if (ds[i][j].giatri == 0)
			m = 1;
		if (ds[i][j].giatri == nguoichoi * -1)
			break;
	}
	i = mi;
	j = mj;
	//kiem tra chieu ngang phai
	for (j = mj + 1; j < 20; j++)
	{
		if (ds[i][j].giatri == nguoichoi)
		{
			dem = dem + (k - (j - mj)) * m;
			count++;
		}
		if (ds[i][j].giatri == 0)
			m = 1;
		if (ds[i][j].giatri == nguoichoi * -1)
			break;
	}
	if (count >= 3)
		dem = dem * count*100;
	count = 0;
	//kiem tra cheo len tren, ca i va j cung giam
	i = mi - 1;
	j = mj - 1;
	while (i >= 0 && j >= 0)
	{
		if (ds[i][j].giatri == nguoichoi)
		{
			dem = dem + (k - (mi - i)) * m;
			count++;
		}
		if (ds[i][j].giatri == 0)
			m = 1;
		if (ds[i][j].giatri == nguoichoi * -1)
			break;
		i--;
		j--;
	}
	// kiem tra cheo xuong duoi, cai va j cung tang
	i = mi + 1;
	j = mj + 1;
	while (i < 20 && j < 20)
	{
		if (ds[i][j].giatri == nguoichoi)
		{
			dem = dem + (k - (i - mi)) * m;
			count++;
		}
		if (ds[i][j].giatri == 0)
			m = 1;
		if (ds[i][j].giatri == nguoichoi * -1)
			break;
		i++;
		j++;
	}
	if (count >= 3)
		dem = dem * count*100;
	count = 0;
	//kiem tra cheo phai tren, i giam va j tang
	i = mi - 1;
	j = mj + 1;
	while (i >= 0 && j < 20)
	{
		if (ds[i][j].giatri == nguoichoi)
		{
			dem = dem + (k - (mi - i)) * m;
			count++;
		}
		if (ds[i][j].giatri == 0)
			m = 1;
		if (ds[i][j].giatri == nguoichoi * -1)
			break;
		i--;
		j++;
	}
	//kiem tra cheo phai duoi, i tang va j giam
	i = mi + 1;
	j = mj - 1;
	while (i < 20 && j >= 0)
	{
		if (ds[i][j].giatri == nguoichoi)
		{
			dem = dem + (k - (i - mi)) * m;
			count++;
		}
		if (ds[i][j].giatri == 0)
			m = 1;
		if (ds[i][j].giatri == nguoichoi * -1)
			break;
		i++;
		j--;
	}
	if (count >= 3)
		dem = dem * count*100;
	count = 0;
	return dem;
}

int Banco::uocluongdiemdi_hanche(int mi, int mj)
{
	nguoichoi = nguoichoi * -1;
	int dem = 0;
	dem = uocluongdiemdi_thang(mi, mj);
	nguoichoi = nguoichoi * -1;
	return dem;
	
}

void Banco::buocditieptheo(int mi, int mj, CClientDC* pdc)
{
	int minho = mi - 5;
	int mjnho = mj - 5;
	int milon = mi + 5;
	int mjlon = mj + 5;
	if (minho < 0)
		minho = 0;
	if (mjnho < 0)
		mjnho = 0;
	if (milon > 20)
		milon = 20;
	if (mjlon > 20)
		mjlon = 20;

	int i = 0, j = 0;
	int h = 0;
	int max = 0;
	int imax = -1;
	int jmax = -1;
	for(i = minho; i < milon; i++)
		for (j = mjnho; j < mjlon; j++)
		{
			if (ds[i][j].giatri == 0)
			{
				h = uocluongdiemdi_thang(i, j) + uocluongdiemdi_hanche(i, j);
				if (max < h)
				{
					max = h;
					imax = i;
					jmax = j;
				}
			}
		
		}
	if (imax == -1)
	{
		for (i = 0; i < 20; i++)
			for (j = 0; j < 20; j++)
			{
				if (ds[i][j].giatri == 0)
				{
					h = uocluongdiemdi_thang(i, j) + uocluongdiemdi_hanche(i, j);
					if (max < h)
					{
						max = h;
						imax = i;
						jmax = j;
					}
				}

			}
	}
	if (imax == -1)//khong the tim buoc di tiep theo tuc khong co o trong
	{
		dieukhien = 0;
		//xuat thong bao hoa
		xuatthongbaohoa(pdc);
	}
	else
	{
		i = imax;
		j = jmax;
		ds[i][j].giatri = nguoichoi;
		ds[i][j].vehinh(pdc);
		///kiem tra thang cho may
		if (ktthang(i, j) == 1)//neu thang
		{
			dieukhien = 0;
			/////thong bao nguoi choi thang
			xuatthongbaothang(pdc);
		}
		else
			nguoichoi = nguoichoi * -1;	///doinguoichoi

	}
}

void Banco::xuatthongbaothang(CClientDC* pdc)
{
	CString strx, stro;
	strx.Format(_T("Nguoi choi x thang"));
	stro.Format(_T("Nguoi choi o thang"));
	int xmoi = 20;
	int ymoi = 20;
	if (nguoichoi == 1)
		pdc->TextOutW(xmoi, ymoi, stro);
	if (nguoichoi== -1)
		pdc->TextOutW(xmoi, ymoi, strx);
}

void Banco::xuatthongbaohoa(CClientDC* pdc)
{
	CString strx;
	strx.Format(_T("Hai nguoi choi hoa nhau"));
	
	int xmoi = 20;
	int ymoi = 20;
	pdc->TextOutW(xmoi, ymoi, strx);
	
}
