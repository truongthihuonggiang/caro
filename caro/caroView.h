
// caroView.h : interface of the CcaroView class
//

#pragma once
#include "Hcn.h"
#include "Hcnmau.h"
#include "Oco.h"
#include "Banco.h"
class CcaroView : public CView
{
protected: // create from serialization only
	CcaroView() noexcept;
	DECLARE_DYNCREATE(CcaroView)

// Attributes
public:
	CcaroDoc* GetDocument() const;

// Operations
public:
//	Hcn hcn1;
//	Oco oco1;
	Banco banco;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CcaroView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in caroView.cpp
inline CcaroDoc* CcaroView::GetDocument() const
   { return reinterpret_cast<CcaroDoc*>(m_pDocument); }
#endif

