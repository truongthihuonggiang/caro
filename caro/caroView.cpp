
// caroView.cpp : implementation of the CcaroView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "caro.h"
#endif

#include "caroDoc.h"
#include "caroView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcaroView

IMPLEMENT_DYNCREATE(CcaroView, CView)

BEGIN_MESSAGE_MAP(CcaroView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CcaroView construction/destruction

CcaroView::CcaroView() noexcept
{
	// TODO: add construction code here
	//hcn1 = Hcn(10, 10, 200, 100);
	//oco1 = Oco(200, 200);
	banco = Banco();
}

CcaroView::~CcaroView()
{
}

BOOL CcaroView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CcaroView drawing

void CcaroView::OnDraw(CDC* /*pDC*/)
{
	CcaroDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CClientDC pdc(this);
	//hcn1.vehinh(&pdc);

	/*Hcnmau hcn2 = Hcnmau(200, 200, 300, 250);
	hcn2.setMau(0, 0, 200);
	hcn2.vehinh(&pdc);*/
	
	//oco1.giatri = 0;
	//oco1.vehinh(&pdc);
	banco.vehinh(&pdc);
}

void CcaroView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CcaroView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CcaroView diagnostics

#ifdef _DEBUG
void CcaroView::AssertValid() const
{
	CView::AssertValid();
}

void CcaroView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CcaroDoc* CcaroView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CcaroDoc)));
	return (CcaroDoc*)m_pDocument;
}
#endif //_DEBUG


// CcaroView message handlers


void CcaroView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC pdc(this);
	//oco1.bamoco(&pdc, point, -1);
	banco.bambanco(&pdc, point);
	CView::OnLButtonUp(nFlags, point);
}
