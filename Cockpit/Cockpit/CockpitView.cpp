
// CockpitView.cpp : implementation of the CCockpitView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Cockpit.h"
#endif

#include "CockpitDoc.h"
#include "CockpitView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCockpitView

IMPLEMENT_DYNCREATE(CCockpitView, CView)

BEGIN_MESSAGE_MAP(CCockpitView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCockpitView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CCockpitView construction/destruction

CCockpitView::CCockpitView()
{
	// TODO: add construction code here

}

CCockpitView::~CCockpitView()
{
}

BOOL CCockpitView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCockpitView drawing

void CCockpitView::DrawBezier(CDC* pDC, CRect rect, CPoint* points, int length, COLORREF color)
{
	float a = 0.07;
	float b = 2 * a;

	CPoint LeftWnd[16] = {
		CPoint(0, a * rect.Height()),
		CPoint(0, 2 * a * rect.Height()),
		CPoint(0, 2 * a * rect.Height()),
		CPoint(0, 11 * a * rect.Height()),

		CPoint(a * rect.Width(), 10.5 * a * rect.Height()),
		CPoint(a * rect.Width(), 10.5 * a * rect.Height()),
		CPoint(2 * a * rect.Width(), 10 * a * rect.Height()),

		CPoint(2.5 * a * rect.Width(), 9.4 * a * rect.Height()),
		CPoint(2.6 * a * rect.Width(), 8.7 * a * rect.Height()),
		CPoint(2.5 * a * rect.Width(), 8 * a * rect.Height()),

		CPoint(2.167 * a * rect.Width(), 6 * a * rect.Height()),
		CPoint(1.83 * a * rect.Width(), 4 * a * rect.Height()),
		CPoint(1.5 * a * rect.Width(), 2 * a * rect.Height()),

		CPoint(a * rect.Width(), 1.1 * a * rect.Height()),
		CPoint(a * rect.Width(), 1.1 * a * rect.Height()),
		CPoint(0, a * rect.Height()),
	};

	CPoint RightWnd[16];

	float topX2 = 2.25 * a * rect.Width(), topY2 = 2 * a * rect.Height();
	float topX1 = a * rect.Width() + topX2, topY1 = 1.2 * a * rect.Height();
	float middleBottomX1 = 3.25 * a * rect.Width();
	float middleBottomX2 = 4.5 * a * rect.Width();
	float temp = 4 * a * rect.Width();

	CPoint MiddleWnd[25] = {

		CPoint(topX1, topY1),
		CPoint((topX1 + topX2) / 2, topY1 * 0.9),
		CPoint(0.9 * (topX1 + topX2) / 2, topY1 * 0.9),
		CPoint(topX2, topY2),

		CPoint(3.25 * a * rect.Width(), 8 * a * rect.Height()),
		CPoint(3.25 * a * rect.Width(), 8 * a * rect.Height()),
		CPoint(3.25 * a * rect.Width(), 8 * a * rect.Height()),

		CPoint(middleBottomX1, 8.55 * a * rect.Height()),
		CPoint(4 * a * rect.Width(), 9.3 * a * rect.Height()),
		CPoint(middleBottomX2, 9 * a * rect.Height()),

		CPoint(0.5 * rect.Width() + a, 8 * a * rect.Height()),
		CPoint(0.5 * rect.Width() - a, 8 * a * rect.Height()),
		CPoint(rect.Width() - middleBottomX2, 9 * a * rect.Height()),

		CPoint(rect.Width() - temp , 9.3 * a * rect.Height()),
		CPoint(rect.Width() - middleBottomX1, 8.55 * a * rect.Height()),
		CPoint(rect.Width() - middleBottomX1, 8 * a * rect.Height()),

		CPoint(rect.Width() - middleBottomX1, 8 * a * rect.Height()),
		CPoint(rect.Width() - middleBottomX1, 8 * a * rect.Height()),
		CPoint(rect.Width() - topX2, topY2),

		CPoint(rect.Width() - 0.9*(topX1 + topX2) / 2, topY1 * 0.9),
		CPoint(rect.Width() - (topX1 + topX2) / 2, topY1 * 0.9),
		CPoint(rect.Width() - topX1, topY1),

		CPoint(0.5 * rect.Width(), topY1 * 1.2),
		CPoint(0.5 * rect.Width(), topY1 * 1.2),
		CPoint(topX1, topY1),
	};

	for (int i = 0; i < 16; i++)
	{
		RightWnd[i].x = rect.Width() - LeftWnd[i].x;
		RightWnd[i].y = LeftWnd[i].y;
	}



	pDC->BeginPath();

	pDC->PolyBezier(LeftWnd, 16);
	pDC->PolyBezier(RightWnd, 16);

	pDC->PolyBezier(MiddleWnd, 25);

	pDC->EndPath();

	CBrush newBrush;
	newBrush.CreateSolidBrush(RGB(128, 224, 255));
	pDC->SelectObject(newBrush);
	CPen newPen(PS_SOLID, 5, RGB(0, 0, 0));
	pDC->SelectObject(newPen);

	pDC->StrokeAndFillPath();


}

void CCockpitView::DrawInstrumenTable(CDC* pDC, CRect rect, COLORREF color)
{
	float leftX = 0.22 * rect.Width(), topLeftX = leftX * 1.17;
	float firstRoundY = 0.79 * rect.Height();
	float a = 1.12, b = 1.02;
	float coefY = 0.91;
	CPoint InstrumentTable[19] = {

		CPoint(leftX, rect.Height()),
		CPoint(leftX, firstRoundY),
		CPoint(leftX, firstRoundY),
		CPoint(leftX, firstRoundY),

		CPoint(leftX * b, firstRoundY * coefY),
		CPoint(leftX * a,  firstRoundY * coefY),
		CPoint(topLeftX,  firstRoundY * 0.9),

		CPoint(0.5 * rect.Width(), firstRoundY * 0.77),
		CPoint(0.5 * rect.Width(), firstRoundY * 0.77),
		CPoint(rect.Width() - topLeftX, firstRoundY * 0.9),

		CPoint(rect.Width() - topLeftX, firstRoundY * 0.9),
		CPoint(rect.Width() - topLeftX, firstRoundY * 0.9),
		CPoint(rect.Width() - topLeftX, firstRoundY * 0.9),

		CPoint(rect.Width() - leftX * a, firstRoundY * coefY),
		CPoint(rect.Width() - leftX * b, firstRoundY * coefY),
		CPoint(rect.Width() - leftX, firstRoundY),

		CPoint(rect.Width() - leftX, rect.Height() * 0.9),
		CPoint(rect.Width() - leftX, rect.Height() * 0.9),
		CPoint(rect.Width() - leftX, rect.Height()),
	};

	pDC->BeginPath();
	pDC->PolyBezier(InstrumentTable, 19);
	pDC->EndPath();

	CBrush newBrush;
	newBrush.CreateSolidBrush(RGB(64, 64, 64));
	pDC->SelectObject(newBrush);
	CPen newPen(PS_SOLID, 3, RGB(0, 0, 0));
	pDC->SelectObject(newPen);

	pDC->StrokeAndFillPath();
}

void CCockpitView::DrawRectangle(CDC* pDC, CRect rect, COLORREF color)
{
	CBrush newBrush;
	newBrush.CreateSolidBrush(color);

	CBrush* oldBrush = pDC->SelectObject(&newBrush);

	pDC->Rectangle(rect);

	pDC->SelectObject(oldBrush);

	newBrush.DeleteObject();
}

void CCockpitView::DrawRoundRect(CDC* pDC, CRect wall, COLORREF color)
{
	CBrush newBrush;
	newBrush.CreateSolidBrush(color);
	CPen newPen(PS_SOLID, 1, RGB(255, 255, 255));
	pDC->SelectObject(newPen);
	pDC->SelectObject(newBrush);

	float coef = 0.01;
	float rectWidth = 0.1 * wall.Width();
	float roundCoef = 0.3;
	
	CRect rightRect((0.5 + coef) * wall.Width(), 0.98 * wall.Height(), (coef + 0.5) * wall.Width() + rectWidth, 0.98 * wall.Height() + rectWidth);
	CRect leftRect;
	leftRect.SetRect((0.5 - coef) * wall.Width() - rectWidth, 0.98 * wall.Height() + rectWidth, (0.5 - coef) * wall.Width(), 0.98 * wall.Height());

	pDC->RoundRect(&leftRect, CPoint(roundCoef * rectWidth, roundCoef * rectWidth));
	pDC->RoundRect(&rightRect, CPoint(roundCoef * rectWidth, roundCoef * rectWidth));
	//Write string
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(0, 255, 0));
	float topOffset = leftRect.Height() * 0.2;
	float leftOffset = leftRect.Width() * 0.05;

	CFont font;
	CFont* pOldFont = pDC->SelectObject(&font);

	leftRect.MoveToY(leftRect.top * 1.03);
	pDC->DrawText(CString("358mph"), leftRect, DT_LEFT);
	leftRect.MoveToY(leftRect.top * 1.03);
	pDC->DrawText(CString("H: 23"), leftRect, DT_LEFT);
	pDC->SelectObject(pOldFont);
	font.DeleteObject();
	
	//pDC->MoveTo(leftRect.BottomRight().x, leftRect.BottomRight().y);
	//pDC->LineTo(wall.Width() / 2, wall.Height() / 2);

	//pDC->MoveTo(wall.Width()/2, wall.Height()/2);
	//pDC->LineTo(wall.Width() / 2, wall.Height());
}

void CCockpitView::OnDraw(CDC* pDC)
{
	CCockpitDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect;
	GetClientRect(&rect);

	pDC->SetMapMode(MM_ISOTROPIC);
	pDC->SetWindowExt(100, -200);
	pDC->SetViewportExt(rect.right, rect.bottom);
	pDC->SetWindowOrg(0, 0);

	CRect wall;
	wall.SetRect(0, 0, 0, -200);
	if (rect.Height()!=0)
		wall.SetRect(0, 0, 200 * rect.Width() / rect.Height(), -200);
	

	if (rect.Height() != 0)
		DrawRectangle(pDC, wall, RGB(128, 128, 128));

	CPoint points[7] = {
		CPoint(100, -100),
		CPoint(100, 0),
		CPoint(0, 0),
		CPoint(0, -100),

		CPoint(0, -200),
		CPoint(100, -200),
		CPoint(100, -100)

	};

	DrawInstrumenTable(pDC, wall, RGB(255, 0, 0));
	DrawBezier(pDC, wall, points, 7, RGB(255, 0, 0));
	DrawRoundRect(pDC, wall, RGB(32, 32, 32));
}


// CCockpitView printing


void CCockpitView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCockpitView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCockpitView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCockpitView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CCockpitView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCockpitView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCockpitView diagnostics

#ifdef _DEBUG
void CCockpitView::AssertValid() const
{
	CView::AssertValid();
}

void CCockpitView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCockpitDoc* CCockpitView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCockpitDoc)));
	return (CCockpitDoc*)m_pDocument;
}
#endif //_DEBUG


// CCockpitView message handlers
