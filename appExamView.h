
// appExamView.h : interface of the CappExamView class
//

#pragma once
#include "grille.h"

class CappExamView : public CView
{
private :
	grille magrille;
protected: // create from serialization only
	CappExamView();
	DECLARE_DYNCREATE(CappExamView)

// Attributes
public:
	CappExamDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CappExamView();
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
};

#ifndef _DEBUG  // debug version in appExamView.cpp
inline CappExamDoc* CappExamView::GetDocument() const
   { return reinterpret_cast<CappExamDoc*>(m_pDocument); }
#endif

