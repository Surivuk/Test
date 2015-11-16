
// GrafikaGodHelpUsAllView.cpp : implementation of the CGrafikaGodHelpUsAllView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "GrafikaGodHelpUsAll.h"
#endif

#include "GrafikaGodHelpUsAllDoc.h"
#include "GrafikaGodHelpUsAllView.h"
#include "Math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGrafikaGodHelpUsAllView

IMPLEMENT_DYNCREATE(CGrafikaGodHelpUsAllView, CView)

BEGIN_MESSAGE_MAP(CGrafikaGodHelpUsAllView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CGrafikaGodHelpUsAllView construction/destruction

CGrafikaGodHelpUsAllView::CGrafikaGodHelpUsAllView()
{
	// TODO: add construction code here

}

CGrafikaGodHelpUsAllView::~CGrafikaGodHelpUsAllView()
{
}

BOOL CGrafikaGodHelpUsAllView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}
//sa poligonima
void CGrafikaGodHelpUsAllView::nacrtajPozadinu(CDC* painter,CRect prozor)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush backBrush = CBrush(RGB(128, 128, 128));
	
	painter->FillRect(prozor, &backBrush);
}

void CGrafikaGodHelpUsAllView::nacrtajLeviProzor(CDC* painter,CRect prozor)
{
	//Olovka i cetka
	CPen myPen = CPen(PS_SOLID, 4, BLACK_PEN);
	CPen* defPen = painter->SelectObject(&myPen);

	CBrush myBrush(RGB(124, 228, 255));
	CBrush * defBrush = painter->SelectObject(&myBrush);

	//Crtanje prozora
	
	double p = 0.05;

	//painter->MoveTo(0, p*prozor.Height());
	//painter->LineTo(p*prozor.Width(), p*prozor.Height());
	
	CPoint tacke[4] = {
		CPoint(0, p*prozor.Height()),
		CPoint(p*prozor.Width(), p*prozor.Height()),
		CPoint(2 * p*prozor.Width(), 13 * p*prozor.Height()),
		CPoint(0, 17 * p*prozor.Height()) };

	painter->Polygon(tacke, 4);

	//Vracanje konteksta
	painter->SelectObject(defPen);
	painter->SelectObject(defBrush);

	myPen.DeleteObject();
	myBrush.DeleteObject();
}

void CGrafikaGodHelpUsAllView::nacrtajCentralniProzor(CDC* painter,CRect prozor)
{
	//Olovka i cetka
	CPen myPen = CPen(PS_SOLID, 4, BLACK_PEN);
	CPen* defPen = painter->SelectObject(&myPen);

	CBrush myBrush(RGB(124, 228, 255));
	CBrush * defBrush = painter->SelectObject(&myBrush);

	//Crtanje prozora
	double p = 0.05;

	CPoint tacke[5] = {
		CPoint(1.7*p*prozor.Width(), p*prozor.Height()),
		CPoint(18.3*p*prozor.Width(), p*prozor.Height()),
		CPoint(17.3* p*prozor.Width(), 12.5 * p*prozor.Height()),
		CPoint(10* p*prozor.Width(), 11 * p*prozor.Height()),
		CPoint(2.7 * p*prozor.Width(), 12.5 * p*prozor.Height()) };

	painter->Polygon(tacke, 5);
	
	//Vracanje konteksta
	painter->SelectObject(defPen);
	painter->SelectObject(defBrush);

	myPen.DeleteObject();
	myBrush.DeleteObject();
}

void CGrafikaGodHelpUsAllView::nacrtajDesniProzor(CDC* painter,CRect prozor)
{
	//Olovka i cetka
	CPen myPen = CPen(PS_SOLID, 4, BLACK_PEN);
	CPen* defPen = painter->SelectObject(&myPen);

	CBrush myBrush(RGB(124, 228, 255));
	CBrush * defBrush = painter->SelectObject(&myBrush);

	//Crtanje prozora

	double p = 0.05;
	int offset = prozor.Width();

	CPoint tacke[4] = {
		CPoint(offset-0, p*prozor.Height()),
		CPoint(offset-p*prozor.Width(), p*prozor.Height()),
		CPoint(offset-2 * p*prozor.Width(), 13 * p*prozor.Height()),
		CPoint(offset-0, 17 * p*prozor.Height()) };

	painter->Polygon(tacke, 4);

	//Vracanje konteksta
	painter->SelectObject(defPen);
	painter->SelectObject(defBrush);

	myPen.DeleteObject();
	myBrush.DeleteObject();
}

void CGrafikaGodHelpUsAllView::nacrtajKontrolnuTablu(CDC* painter, CRect prozor)
{
	//Olovka i cetka
	CPen myPen = CPen(PS_SOLID, 4, BLACK_PEN);
	CPen* defPen = painter->SelectObject(&myPen);

	CBrush myBrush(RGB(64, 64, 64));
	CBrush * defBrush = painter->SelectObject(&myBrush);

	//Crtanje prozora

	double p = 0.05;

	//Path
	painter->BeginPath();

	//A-B Linija
	painter->MoveTo(3 * p*prozor.Width(), 20 * p*prozor.Height());
	painter->LineTo(3 * p*prozor.Width(), 17 * p*prozor.Height());
	
	//B-C Bezier
	CPoint tacke[3]={
		CPoint(3 * p*prozor.Width(), 17 * p*prozor.Height()),
		CPoint(3 * p*prozor.Width(), 15.5 * p*prozor.Height()),
		CPoint(4 * p*prozor.Width(), 15 * p*prozor.Height())
	};

	painter->PolyBezierTo(tacke, 3);

	//C-D Linija
	painter->LineTo(8 * p*prozor.Width(), 13 * p*prozor.Height());

	//D-E Bezier
	CPoint tacke1[3]={
		CPoint(8 * p*prozor.Width(), 13 * p*prozor.Height()),
		CPoint(10 * p*prozor.Width(), 12 * p*prozor.Height()),
		CPoint(12 * p*prozor.Width(), 13 * p*prozor.Height())
	};

	painter->PolyBezierTo(tacke1, 3);

	//E-F Linija
	painter->LineTo(16 * p*prozor.Width(), 15 * p*prozor.Height());

	//G-H Bezier
	CPoint tacke2[3]={
		CPoint(16 * p*prozor.Width(), 15 * p*prozor.Height()),
		CPoint(17 * p*prozor.Width(), 15.5 * p*prozor.Height()),
		CPoint(17 * p*prozor.Width(), 17 * p*prozor.Height())
	};

	painter->PolyBezierTo(tacke2, 3);

	//H-I Linija
	painter->LineTo(17 * p*prozor.Width(), 20 * p*prozor.Height());

	//I-J Linija
	painter->LineTo(3 * p*prozor.Width(), 20 * p*prozor.Height());

	//Kraj putanje
	painter->EndPath();
	painter->StrokeAndFillPath();

	//Vracanje konteksta
	painter->SelectObject(defPen);
	painter->SelectObject(defBrush);

	myPen.DeleteObject();
	myBrush.DeleteObject();
}

void CGrafikaGodHelpUsAllView::nacrtajEkrane(CDC* painter, CRect tabla)
{
	//Olovka i cetka
	CPen myPen = CPen(PS_SOLID, 1, RGB(200,200,200));
	CPen* defPen = painter->SelectObject(&myPen);

	CBrush myBrush(RGB(32, 32, 32));
	CBrush * defBrush = painter->SelectObject(&myBrush);

	double p = 0.05;

	//Levi ekran
	CRect leviEkran = new CRect(8 * p*tabla.Width(), 15.5* p*tabla.Height(), 10 * p*tabla.Width(), 19 * p*tabla.Height());
	painter->RoundRect(leviEkran, CPoint(2, 2));

	//Desni ekran
	CRect desniEkran = new CRect(10.2 * p*tabla.Width(), 15.5* p*tabla.Height(), 12.2* p*tabla.Width(), 19 * p*tabla.Height());
	painter->RoundRect(desniEkran, CPoint(3, 3));

	//Tekst na levom ekranu

	//1) Font
	CFont myFont;
	CString naziv("Arial");
	double fSize = 0.026*leviEkran.left;
	myFont.CreateFont(fSize, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, naziv);
	
	CFont* defFont = painter->SelectObject(&myFont);

	//2) Konfiguracija
	COLORREF clrOld = painter->SetTextColor(RGB(0,200,0));
	int defaultBkMode = painter->SetBkMode(TRANSPARENT);

	//3) Tekst
	CString leviTekst("358mph\n\nH: 23°\n\nA: 284°\n\n1217fpm");
	CString desniTekst("1285m\n\n43°19'29""\n\n21°54'11""\n\n08:54:29");

	//4) Iscrtavanje 

	CRect display = CRect(8.1 * p*tabla.Width(), 15.8* p*tabla.Height(), 9.9 * p*tabla.Width(), 19 * p*tabla.Height());

	painter->DrawText(leviTekst, display, DT_LEFT);
	//painter->DrawText(desniTekst, display, DT_RIGHT);
	
	//5)Povratak
	painter->SetBkMode(defaultBkMode);
	painter->SelectObject(defFont);
	myFont.DeleteObject();
	
	//Komentarisani ekrani
}

//kraj

//sa Bezierovim krivama
void CGrafikaGodHelpUsAllView::Prozori(CDC* pDC, CRect rect, CPoint* points, int length, COLORREF color)
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

void CGrafikaGodHelpUsAllView::Kruzni(CDC* pDC,int x1,int y1,int x2,int y2,COLORREF color)
{

}

void CGrafikaGodHelpUsAllView::InstrumentTabla(CDC* pDC, CRect rect, COLORREF color)
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

void CGrafikaGodHelpUsAllView::Pravougaonik(CDC* pDC, CRect rect, COLORREF color)
{
	CBrush newBrush;
	newBrush.CreateSolidBrush(color);

	CBrush* oldBrush = pDC->SelectObject(&newBrush);

	pDC->Rectangle(rect);

	pDC->SelectObject(oldBrush);

	newBrush.DeleteObject();
}

void CGrafikaGodHelpUsAllView::ZaobljeniPravougaonik(CDC* pDC, CRect wall, COLORREF color)
{
	CBrush newBrush;
	newBrush.CreateSolidBrush(color);
	CPen newPen(PS_SOLID, 1, RGB(255, 255, 255));
	pDC->SelectObject(newPen);
	pDC->SelectObject(newBrush);

	float coef = 0.02;
	float rectWidth = 0.1 * wall.Width();
	float roundCoef = 0.3;
	
	CRect rightRect((0.5 + coef) * wall.Width(), 0.98 * wall.Height(), (0.5+coef) * wall.Width() + rectWidth, 0.98 * wall.Height() + rectWidth);
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
	int fontSize = abs(leftRect.left * 0.03);
	font.CreateFontW(fontSize,0,0,0,0,0,0,0,0,0,0,0,0,CString("Arial"));
	
	CFont* pOldFont = pDC->SelectObject(&font);
	//crtanje u levom pravougaoniku
	leftRect.MoveToY(leftRect.top + topOffset);
	leftRect.MoveToX(leftRect.left + leftOffset);
	pDC->DrawText(CString("358mph"), leftRect, DT_LEFT);
	leftRect.MoveToY(leftRect.top);
	leftRect.MoveToX(leftRect.left-5);
	pDC->DrawText(CString("1285m"),leftRect,DT_RIGHT);
	leftRect.MoveToY(leftRect.top+ topOffset);
	leftRect.MoveToX(leftRect.left+5);
	pDC->DrawText(CString("H: 23°"), leftRect, DT_LEFT);
	leftRect.MoveToX(leftRect.left-5);
	pDC->DrawText(CString("43°19'29''"),leftRect,DT_RIGHT);
	leftRect.MoveToX(leftRect.left+5);
	leftRect.MoveToY(leftRect.top + topOffset);
	pDC->DrawText(CString("A: 284°"), leftRect, DT_LEFT);
	leftRect.MoveToX(leftRect.left-5);
	pDC->DrawText(CString("21°54'11''"),leftRect,DT_RIGHT);
	leftRect.MoveToX(leftRect.left+5);
	leftRect.MoveToY(leftRect.top + topOffset);
	pDC->DrawText(CString("A: 1217fpm"), leftRect, DT_LEFT);
	leftRect.MoveToX(leftRect.left-5);
	pDC->DrawText(CString("08:54:29"),leftRect,DT_RIGHT);
	
	
	

	pDC->SelectObject(pOldFont);
	font.DeleteObject();
}
//kraj

void CGrafikaGodHelpUsAllView::IzotropniMapping(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);

	pDC->SetMapMode(MM_ISOTROPIC);
	pDC->SetWindowExt(100, -200);
	pDC->SetViewportExt(rect.right, rect.bottom);
	pDC->SetWindowOrg(0, 0);

	CRect zid;
	zid.SetRect(0, 0, 0, -200);
	if (rect.Height()!=0)
		zid.SetRect(0, 0, 200 * rect.Width() / rect.Height(), -200);
	

	if (rect.Height() != 0)
		Pravougaonik(pDC, zid, RGB(128, 128, 128));

	//testing
	CPoint points[7] = {
		CPoint(100, -100),
		CPoint(100, 0),
		CPoint(0, 0),
		CPoint(0, -100),

		CPoint(0, -200),
		CPoint(100, -200),
		CPoint(100, -100)

	};

	InstrumentTabla(pDC, zid, RGB(255, 0, 0));
	//nije neophodno da seposalju tacke testiranje radjeno
	Prozori(pDC, zid, points, 7, RGB(255, 0, 0));
	ZaobljeniPravougaonik(pDC, zid, RGB(32, 32, 32));
}

//inline bez mapiranja
void CGrafikaGodHelpUsAllView::BezMappiranja(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush * background = new CBrush(COLORREF(RGB(128,128,128)));
	int min;
	if(rect.Width() <= rect.Height())
	{
		min = rect.Width();
	}
	else
	{
		min = rect.Height();
	}
	int penWidth = min/100;

	pDC->SelectObject(background);
	pDC->Rectangle(0,0,rect.Width(),rect.Height());
	CPen * black = new CPen(PS_SOLID | PS_GEOMETRIC,penWidth,RGB(0,0,0));
	CBrush * sky = new CBrush(RGB(128,224,255));
	pDC->SelectObject(black);
	pDC->SelectObject(sky);
	
	int offsetSides = rect.Width()/4;
	int offsetTop = rect.Height()*0.1;
	int widthTenth = rect.Width()*0.1;
	int heightTenth = rect.Height()*0.1;
	CPoint MainWindow[25]=
	{
		//gornja linija s leva na desno
		CPoint(offsetSides, offsetTop),
		CPoint(rect.Width()/4 + offsetSides, offsetTop*1.2),
		CPoint(rect.Width()/2+offsetSides, offsetTop),
		CPoint(rect.Width()/2+offsetSides, offsetTop),
		//gornji desni ugao odozgo na dole
		CPoint(rect.Width()/2+offsetSides+offsetTop/4+offsetTop/4, offsetTop+offsetTop/4),
		CPoint(rect.Width()/2+offsetSides+offsetTop/2,offsetTop*2),
		CPoint(rect.Width()/2+offsetSides+offsetTop/2,offsetTop*2),
		//desni sloop(na dole)
		CPoint(rect.Width()/2+offsetSides+offsetTop/2-rect.Width()/16,offsetTop*2+rect.Height()/3),
		CPoint(rect.Width()/2+offsetSides+offsetTop/2-rect.Width()/16,offsetTop*2+rect.Height()/3),
		CPoint(rect.Width()/2+offsetSides+offsetTop/2-rect.Width()/16,offsetTop*2+rect.Height()/3),
		//donji desni ugao
		CPoint(offsetSides+rect.Width()/2-widthTenth/2,rect.Height()/2 + 2*offsetTop),
		CPoint(offsetSides+rect.Width()/2-widthTenth,rect.Height()/2 + 2*offsetTop),
		CPoint(offsetSides+rect.Width()/2-widthTenth,rect.Height()/2 + 2*offsetTop),
		//donja linija
		CPoint(offsetSides+rect.Width()/2-widthTenth,rect.Height()/2 + 2*offsetTop),
		CPoint(offsetSides+rect.Width()/4,(rect.Height()/2 + 2*offsetTop)*0.85),
		CPoint(offsetSides+widthTenth,rect.Height()/2 + 2*offsetTop),
		//donji levi ugao
		CPoint(offsetSides+widthTenth,rect.Height()/2 + 2*offsetTop),
		CPoint(offsetSides+widthTenth/2,rect.Height()/2 + 2*offsetTop),
		CPoint(offsetSides-offsetTop/2+rect.Width()/16,2*offsetTop+rect.Height()/3),
		//levi sloop (na gore)
		CPoint(offsetSides-offsetTop/2+rect.Width()/16,2*offsetTop+rect.Height()/3),
		CPoint(offsetSides-offsetTop/2+rect.Width()/16,2*offsetTop+rect.Height()/3),
		CPoint(offsetSides-offsetTop/2, 2*offsetTop),
		//gornji levi ugao
		CPoint(offsetSides-offsetTop/2, offsetTop+offsetTop/4),
		CPoint(offsetSides, offsetTop),
		CPoint(offsetSides, offsetTop),
	};
	CPoint LeftWindow[13]=
	{
		CPoint(0,offsetTop),
		CPoint(rect.Width()/6,2*offsetTop),
		CPoint(rect.Width()/6,2*offsetTop),
		CPoint(rect.Width()/6,2*offsetTop),

		CPoint(rect.Width()/6+rect.Width()/16,2*offsetTop+rect.Height()/3),
		CPoint(rect.Width()/6+rect.Width()/16,2*offsetTop+rect.Height()/3),
		CPoint(rect.Width()/6+rect.Width()/16,2*offsetTop+rect.Height()/3),

		CPoint(rect.Width()/6,2*offsetTop+rect.Height()/3+rect.Width()/16),
		CPoint(rect.Width()/6,2*offsetTop+rect.Height()/3+rect.Width()/16),
		CPoint(rect.Width()/6,2*offsetTop+rect.Height()/3+rect.Width()/16),

		CPoint(0,3*offsetTop+rect.Height()/3+rect.Width()/16),
		CPoint(0,3*offsetTop+rect.Height()/3+rect.Width()/16),
		CPoint(0,3*offsetTop+rect.Height()/3+rect.Width()/16),
	};
	CPoint RightWindow[13];
	for(int i=0 ; i < 13 ; i++)
	{
		RightWindow[i].y = LeftWindow[i].y;
		RightWindow[i].x = rect.Width() - LeftWindow[i].x;
	}

	pDC->BeginPath();

	pDC->PolyBezier(MainWindow,25);
	pDC->PolyBezier(LeftWindow,13);
	pDC->PolyBezier(RightWindow,13);

	pDC->EndPath();


	/*XFORM Xform,XformOld;
	int a = GM_ADVANCED;
	int prevMode = pDC->SetGraphicsMode(GM_ADVANCED);
	DWORD dw = GetLastError();
	BOOL b = pDC->GetWorldTransform(&XformOld);
	Xform.eM11 = cos(65.0);
	Xform.eM12 = sin(65.0);
	Xform.eM21 = -sin(65.0);
	Xform.eM22 = cos(65.0);
	Xform.eDx = 150;
	Xform.eDy = 500;
	b = pDC->SetWorldTransform(&Xform);
	dw = GetLastError();
	pDC->RoundRect(0,0,rect.Width()/5,rect.Height()/2,50,50);
	b = pDC->SetWorldTransform(&XformOld);
	pDC->SetGraphicsMode(prevMode);*/
	
	pDC->StrokeAndFillPath();
	sky->DeleteObject();
	black->DeleteObject();
	background->DeleteObject();
}

void CGrafikaGodHelpUsAllView::IzotropSaPoligonima(CDC* painter)
{
	//Ekran
	CRect rect; GetClientRect(&rect);

	painter->SetMapMode(MM_ISOTROPIC);
	painter->SetWindowExt(100,200);
	painter->SetViewportExt(rect.right,rect.bottom);
	painter->SetWindowOrg(0, 0);

	//Cockpit
	double p = 0.05;

	if (rect.Height() > 0 && rect.Width() > 0)
	{
		CRect prozor = CRect(0, 0, 200 * rect.Width() / rect.Height(), 200);

		nacrtajPozadinu(painter, prozor);
		nacrtajLeviProzor(painter, prozor);
		nacrtajCentralniProzor(painter, prozor);
		nacrtajDesniProzor(painter, prozor);
		nacrtajKontrolnuTablu(painter, prozor);
		nacrtajEkrane(painter, prozor);
	}
}

// CGrafikaGodHelpUsAllView drawing

void CGrafikaGodHelpUsAllView::OnDraw(CDC* pDC)
{
	CGrafikaGodHelpUsAllDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//IzotropniMapping(pDC);
	//BezMappiranja(pDC);
	IzotropSaPoligonima(pDC);
}



	
	
	// TODO: add draw code for native data here
//}


// CGrafikaGodHelpUsAllView printing

BOOL CGrafikaGodHelpUsAllView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGrafikaGodHelpUsAllView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGrafikaGodHelpUsAllView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CGrafikaGodHelpUsAllView diagnostics

#ifdef _DEBUG
void CGrafikaGodHelpUsAllView::AssertValid() const
{
	CView::AssertValid();
}

void CGrafikaGodHelpUsAllView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGrafikaGodHelpUsAllDoc* CGrafikaGodHelpUsAllView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGrafikaGodHelpUsAllDoc)));
	return (CGrafikaGodHelpUsAllDoc*)m_pDocument;
}
#endif //_DEBUG


// CGrafikaGodHelpUsAllView message handlers
