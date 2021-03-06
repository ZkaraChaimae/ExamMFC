
// appExamView.cpp : implementation of the CappExamView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "appExam.h"
#endif

#include "appExamDoc.h"
#include "appExamView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CappExamView

IMPLEMENT_DYNCREATE(CappExamView, CView)

BEGIN_MESSAGE_MAP(CappExamView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CappExamView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CappExamView construction/destruction

CappExamView::CappExamView()
{
	// TODO: add construction code here

}

CappExamView::~CappExamView()
{
}

BOOL CappExamView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CappExamView drawing

void CappExamView::OnDraw(CDC* dc)
{
	CappExamDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	magrille.dessiner(dc);

	// TODO: add draw code for native data here
}


// CappExamView printing


void CappExamView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CappExamView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CappExamView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CappExamView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CappExamView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CappExamView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CappExamView diagnostics

#ifdef _DEBUG
void CappExamView::AssertValid() const
{
	CView::AssertValid();
}

void CappExamView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CappExamDoc* CappExamView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CappExamDoc)));
	return (CappExamDoc*)m_pDocument;
}
#endif //_DEBUG


// CappExamView message handlers
