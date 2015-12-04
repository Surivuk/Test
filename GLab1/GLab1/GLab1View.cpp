
// GLab1View.cpp : implementation of the CGLab1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "GLab1.h"
#endif
#include "math.h"
#include "GLab1Doc.h"
#include "GLab1View.h"
#include "DImage.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define PI 3.14159265

// CGLab1View

IMPLEMENT_DYNCREATE(CGLab1View, CView)

BEGIN_MESSAGE_MAP(CGLab1View, CView)
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

CPoint startPoint;
int longest;
// CGLab1View construction/destruction

CGLab1View::CGLab1View()
{
	// TODO: add construction code here
	longest = 0;
}

CGLab1View::~CGLab1View()
{
}

BOOL CGLab1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CGLab1View drawing

void CGLab1View::OnDraw(CDC* painter)
{
	CGLab1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

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
		//nacrtajLeviProzor(painter, prozor);
		//nacrtajCentralniProzor(painter, prozor);
		//nacrtajDesniProzor(painter, prozor);
		//nacrtajKontrolnuTablu(painter, prozor);
		//nacrtajEkrane(painter, prozor);

		////Desni donji sat za visinu



		//float width = 3 * p*min(15.2*p*prozor.Width(), prozor.Height());
		//int desniSatX = prozor.Width() / 2 + 2.9*width;
		//int desniSatY = 16.5*p*prozor.Height() - 2;  

		//CRect desniSat = CRect(desniSatX, desniSatY,desniSatX+width,desniSatY+width);
		////painter->Rectangle(desniSat);
		//
		//CString vrednosti[7] = { CString("-3"), CString("-2"), CString("-1"), CString("0"), CString("1"), CString("2"), CString("3") };
		//nacrtajSat(painter, prozor, desniSat, 13, vrednosti, 7, 120, 420, 2, 45);

		////Levi donji sat za brzinu
		//int leviSatX = prozor.Width() / 2 - 3.7*width;
		//int leviSatY = 16.5*p*prozor.Height() - 2;
		//CRect leviSat = CRect(leviSatX, leviSatY, leviSatX + width, leviSatY + width);
		//
		//CString vrednosti1[8] = { CString("4"), CString("8"), CString("12"), CString("16"), CString("20"), CString("24"), CString("28") , CString("32")};
		//nacrtajSat(painter, prozor, leviSat, 30, vrednosti1, 8, 40, 340, 2, 180);
		////painter->Rectangle(leviSat);

		////Levi gornji sat za kompas
		//int leviGornjiSatX = prozor.Width() / 2 - 2.6*width;
		//int leviGornjiSatY = 15*p*prozor.Height() - 2;
		//CRect leviGornjiSat = CRect(leviGornjiSatX, leviGornjiSatY, leviGornjiSatX + width, leviGornjiSatY + width);

		//CString vrednosti2[8] = { CString("N"), CString("NE"), CString("E"), CString("SE"), CString("S"), CString("SW"), CString("W"), CString("NW") };
		//nacrtajSat(painter, prozor, leviGornjiSat, 16, vrednosti2, 8, 0, 320, 3, 90);

		////Desni gornji sat ziroskop 
		//int desniGornjiSatX = prozor.Width() / 2 + 1.7*width;
		//int desniGornjiSatY = 15*p*prozor.Height() - 2;
		//CRect desniGornjiSat = CRect(desniGornjiSatX, desniGornjiSatY, desniGornjiSatX + width, desniGornjiSatY + width);
		//nacrtajZiroskop(painter, prozor, desniGornjiSat,325);
		//
		//
		////PRVI FUEL
		//COLORREF green(RGB(0, 255, 0));
		//COLORREF red(RGB(255, 0, 0));
		//COLORREF yellow(RGB(255, 255, 0));
		//COLORREF fuelColor[] = { red, green, yellow };
		//CPoint p1, p2;
		//p1.SetPoint(prozor.Width() * 0.395, prozor.Height() *  0.66);
		//p2.SetPoint(prozor.Width() * 0.463, prozor.Height() *  0.745);
		//CRect watch(p1, p2);
		//nacrtajFuelWatch(painter, prozor, watch, fuelColor);

		////DRUGI FUEL
		//fuelColor[0] = yellow;
		//fuelColor[1] = green;
		//fuelColor[2] = red;
		//p1.SetPoint(prozor.Width() * 0.531, prozor.Height() * 0.66);
		//p2.SetPoint(prozor.Width() * 0.6, prozor.Height() * 0.745);
		//watch.SetRect(p1, p2);
		//nacrtajFuelWatch(painter, prozor, watch, fuelColor);
		////DrawPoint(pDC, zid);

		//testing(painter,prozor);
	}

}

// --- METODE ZA ISCRTAVANJE KOKPITA ---
// LAB1

void CGLab1View::nacrtajPozadinu(CDC* painter,CRect prozor)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush backBrush = CBrush(RGB(128, 128, 128));
	
	painter->FillRect(prozor, &backBrush);
}

void CGLab1View::nacrtajLeviProzor(CDC* painter,CRect prozor)
{
	//Olovka i cetka
	CPen myPen = CPen(PS_SOLID, 4, BLACK_PEN);
	CPen* defPen = painter->SelectObject(&myPen);

	DImage slika;
	slika.Load(CString("F:\Sky.jpg"));
	
	CBitmap * mapa = slika.GetBitMap();
	CBrush neboCetka(mapa);

	//CBrush myBrush(RGB(124, 228, 255));
	CBrush * defBrush = painter->SelectObject(&neboCetka);

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
	//myBrush.DeleteObject();
}

void CGLab1View::nacrtajCentralniProzor(CDC* painter,CRect prozor)
{
	//Olovka i cetka
	CPen myPen = CPen(PS_SOLID, 4, BLACK_PEN);
	CPen* defPen = painter->SelectObject(&myPen);

	DImage slika;
	slika.Load(CString("F:\Sky.jpg"));
	
	CBitmap * mapa = slika.GetBitMap();
	CBrush neboCetka(mapa);
	painter->SelectObject(neboCetka);

	//CBrush myBrush(RGB(124, 228, 255));
	//CBrush * defBrush = painter->SelectObject(&myBrush);

	//Crtanje prozora
	double p = 0.05;

	CPoint tacke[5] = {
		CPoint(1.7*p*prozor.Width(), p*prozor.Height()),
		CPoint(18.3*p*prozor.Width(), p*prozor.Height()),
		CPoint(17.3* p*prozor.Width(), 12.5 * p*prozor.Height()),
		CPoint(10* p*prozor.Width(), 11 * p*prozor.Height()),
		CPoint(2.7 * p*prozor.Width(), 12.5 * p*prozor.Height()) };

	painter->Polygon(tacke, 5);
	
	nacrtajAvion(painter,prozor,CString("Suhoj.bmp"));
	//Vracanje konteksta
	painter->SelectObject(defPen);
	//painter->SelectObject(defBrush);

	myPen.DeleteObject();
	//myBrush.DeleteObject();
}

void CGLab1View::nacrtajDesniProzor(CDC* painter,CRect prozor)
{
	//Olovka i cetka
	CPen myPen = CPen(PS_SOLID, 4, BLACK_PEN);
	CPen* defPen = painter->SelectObject(&myPen);

	DImage slika;
	slika.Load(CString("F:\Sky.jpg"));
	
	CBitmap * mapa = slika.GetBitMap();
	CBrush neboCetka(mapa);

	//CBrush myBrush(RGB(124, 228, 255));
	CBrush * defBrush = painter->SelectObject(&neboCetka);

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
	//myBrush.DeleteObject();
}

void CGLab1View::nacrtajKontrolnuTablu(CDC* painter, CRect prozor)
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

void CGLab1View::nacrtajEkrane(CDC* painter, CRect tabla)
{
	
	//Olovka i cetka
	CPen myPen = CPen(PS_SOLID, 1, RGB(200,200,200));
	CPen* defPen = painter->SelectObject(&myPen);

	CBrush myBrush(RGB(32, 32, 32));
	CBrush * defBrush = painter->SelectObject(&myBrush);

	double p = 0.05;

	//Skaliranje sirine 
	float width = 3.9*p*min(tabla.Width(), tabla.Height());
	int x1, y1, x2, y2;

	//Levi ekran
	//CRect leviEkran = new CRect(8 * p*tabla.Width(), 15.5* p*tabla.Height(), 10 * p*tabla.Width(), 19 * p*tabla.Height());
	//x1 = 8 * p*tabla.Width();

	x1 = tabla.left + tabla.Width() / 2-1.1*width+5;
	y1 = 15.5* p*tabla.Height();

	x2 = x1 + width;
	y2 = y1 + width;
	
	CRect leviEkran = new CRect(x1,y1,x2,y2);
	painter->RoundRect(leviEkran, CPoint(3, 3));

	//Desni ekran
	x1 = leviEkran.right + 0.2*p*tabla.Width();
	y1 = 15.5* p*tabla.Height();

	x2 = x1 + width;
	y2 = y1 + width;

	CRect desniEkran = new CRect(x1,y1,x2,y2);
	
	painter->RoundRect(desniEkran, CPoint(3, 3));

	//mapa  u desnom ekranu
	DImage x;
	x.Load(CString("F:\Map.png"));
	CRect pictureSize = new CRect(0, 0, x.Width(), x.Height());
	x.Draw(painter, pictureSize, desniEkran);
	//Tekst na levom ekranu

	//1) Font
	CFont myFont;
	CString naziv("Arial");
	float fSize = 3*p*width;
	myFont.CreateFont(fSize, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, naziv);
	
	CFont* defFont = painter->SelectObject(&myFont);

	//2) Konfiguracija
	COLORREF clrOld = painter->SetTextColor(RGB(0,200,0));
	int defaultBkMode = painter->SetBkMode(TRANSPARENT);

	//3) Tekst
	CString leviTekst("358mph\n\nH: 23°\n\nA: 284°\n\n1217fpm");
	CString desniTekst("1285m\n\n43°19'29""\n\n21°54'11""\n\n08:54:29");

	//4) Iscrtavanje 

	CRect display = CRect(leviEkran.left+2,leviEkran.top+2.8,leviEkran.right-2,leviEkran.bottom-1.7);

	painter->DrawText(leviTekst, display, DT_LEFT);
	painter->DrawText(desniTekst, display, DT_RIGHT);
		
	//5)Povratak
	painter->SetBkMode(defaultBkMode);
	painter->SelectObject(defFont);
	painter->SelectObject(defPen);
	painter->SelectObject(defBrush);

	myFont.DeleteObject();
	myPen.DeleteObject();
	myBrush.DeleteObject();
	
	////Komentarisani ekrani
	//CRect desniDonjiKrug = CRect(14.2* p*tabla.Width(), 16* p*tabla.Height(), 15.7* p*tabla.Width(), 19 * p*tabla.Height());
	//painter->Ellipse(desniDonjiKrug);

	//CRect desniGornjiKrug = CRect(12.5 * p*tabla.Width(), 15 * p*tabla.Height(), 14 * p*tabla.Width(), 18 * p*tabla.Height());
	//painter->Ellipse(desniGornjiKrug);

	//CRect  leviDonjiKrug = CRect(4.5* p*tabla.Width(), 16 * p*tabla.Height(), 6 * p*tabla.Width(), 19 * p*tabla.Height());
	//painter->Ellipse(leviDonjiKrug);

	//CRect leviGornjiKrug = CRect(6.2* p*tabla.Width(), 15 * p*tabla.Height(), 7.7 * p*tabla.Width(), 18 * p*tabla.Height());
	//painter->Ellipse(leviGornjiKrug);
}

// LAB2

void CGLab1View::nacrtajSat(CDC* painter, CRect prozor, CRect sat, int brPodeoka, CString vrednosti[], int brVrednosti, double pocetniUgao, double krajnjiUgao, int tipKazaljke, double ugaoKazaljke)
{
	//Olovka i cetka
	CPen myPen = CPen(PS_SOLID, 1, RGB(255, 255, 255));
	CPen* defPen = painter->SelectObject(&myPen);

	CBrush myBrush(RGB(0, 0, 0));
	CBrush * defBrush = painter->SelectObject(&myBrush);

	//Crtanje spoljnog kruga
	painter->Ellipse(sat);

	//Crtanje podeoka
	nacrtajPodeoke(painter, sat, 12, 1, pocetniUgao, krajnjiUgao);

	//Crtanje teksta
	nacrtajVrednosti(painter, sat, 12, vrednosti, brVrednosti, 1, pocetniUgao, krajnjiUgao);

	//Crtanje strelice
	//Pozicija
	
	int centarX = (sat.left + sat.right) / 2;
	int centarY = (sat.top + sat.bottom) / 2;

	CPoint pTL = CPoint(centarX-2,sat.top+5);
	CPoint pBR = CPoint(centarX+2,sat.bottom-5);

	CRect strelicaPravougaonik = CRect(pTL, pBR);
	
	//painter->Rectangle(strelicaPravougaonik);

	// ROTACIJA STRELICE 

		//Graficki mod
		int prevMod = SetGraphicsMode(painter->m_hDC, GM_ADVANCED);

		XFORM xForm, xFormOld;
		GetWorldTransform(painter->m_hDC, &xFormOld);

		//Translacija na koordinatni pocetak
		xForm.eM11 = (FLOAT) 1.0;
		xForm.eM12 = (FLOAT) 0.0;
		xForm.eM21 = (FLOAT) 0.0;
		xForm.eM22 = (FLOAT) 1.0;
		xForm.eDx = (FLOAT)-centarX;
		xForm.eDy = (FLOAT)-centarY;

		double ugaoRad = stepen_u_radian(ugaoKazaljke);

		//Rotacija
		SetWorldTransform(painter->m_hDC, &xForm);

		xForm.eM11 = (FLOAT)cos(ugaoRad);
		xForm.eM12 = (FLOAT)sin(ugaoRad);
		xForm.eM21 = (FLOAT)-sin(ugaoRad);
		xForm.eM22 = (FLOAT)cos(ugaoRad);
		xForm.eDx = (FLOAT)centarX;
		xForm.eDy = (FLOAT)centarY;

		//Translacija * Rotacija
		ModifyWorldTransform(painter->m_hDC, &xForm, MWT_RIGHTMULTIPLY);

		//Crtanje

		if (tipKazaljke != 3)
		{
			nacrtajStrelicu(painter, prozor, strelicaPravougaonik, ugaoKazaljke, tipKazaljke);
		}
		else if (tipKazaljke == 3)
		{
			pTL = CPoint(centarX - 7, sat.top + 5);
			pBR = CPoint(centarX + 7, sat.bottom - 5);
			strelicaPravougaonik = CRect(pTL, pBR);
			nacrtajStrelicu(painter, prozor, strelicaPravougaonik, ugaoKazaljke, tipKazaljke);
		}

		//Povratak grafickog moda
		SetWorldTransform(painter->m_hDC, &xFormOld);
		SetGraphicsMode(painter->m_hDC, prevMod);



	//Povratak olovke i cetke
	painter->SelectObject(defPen);
	painter->SelectObject(defBrush);

	myPen.DeleteObject();
	myBrush.DeleteObject();
}

void CGLab1View::nacrtajZiroskop(CDC* painter, CRect prozor, CRect sat, double ugao)
{
	//Tacke od znacaja
	CPoint leviCentar, desniCentar, Centar;

	leviCentar = CPoint(sat.left, (sat.top+sat.bottom)/2);
	desniCentar = CPoint(sat.right, (sat.top + sat.bottom) / 2);
	Centar = CPoint((sat.left+sat.right)/2, (sat.top + sat.bottom) / 2);
	
	//Olovka i cetka
	CPen myPen = CPen(PS_SOLID, 1, RGB(255, 255, 255));
	CPen* defPen = painter->SelectObject(&myPen);

	CBrush myBlueBrush(RGB(48, 176, 224));
	CBrush mySandBrush(RGB(208, 176, 128));
	CBrush * defBrush = painter->SelectObject(&myBlueBrush);

	// ---- ROTACIJA ---- 
	int prevMod;
	XFORM xForm, xFormOld;

	if (ugao != 0)
	{
		//Graficki mod
		prevMod = SetGraphicsMode(painter->m_hDC, GM_ADVANCED);
		GetWorldTransform(painter->m_hDC, &xFormOld);

		//Transliranje na pocetak 
		int translateX = (Centar.x);
		int translateY = (Centar.y);

		//Translacija na koordinatni pocetak
		xForm.eM11 = (FLOAT) 1.0;
		xForm.eM12 = (FLOAT) 0.0;
		xForm.eM21 = (FLOAT) 0.0;
		xForm.eM22 = (FLOAT) 1.0;
		xForm.eDx = (FLOAT)-translateX;
		xForm.eDy = (FLOAT)-translateY;

		//Ugao rotacije
		double ugaoRad = stepen_u_radian(ugao);

		///Rotacija
		SetWorldTransform(painter->m_hDC, &xForm);

		xForm.eM11 = (FLOAT)cos(ugaoRad);
		xForm.eM12 = (FLOAT)sin(ugaoRad);
		xForm.eM21 = (FLOAT)-sin(ugaoRad);
		xForm.eM22 = (FLOAT)cos(ugaoRad);
		xForm.eDx = (FLOAT)translateX;
		xForm.eDy = (FLOAT)translateY;

		// Translacija * Rotacija
		ModifyWorldTransform(painter->m_hDC, &xForm, MWT_RIGHTMULTIPLY);
	}

	//--- Crtanje

	//Gornji luk
    painter->BeginPath();
	painter->SetArcDirection(AD_CLOCKWISE);
	
	painter->Arc(sat, leviCentar, desniCentar);
	
	painter->EndPath();
	painter->StrokeAndFillPath();

	//Donji luk
	painter->SelectObject(&mySandBrush);
	painter->BeginPath();
    painter->SetArcDirection(AD_COUNTERCLOCKWISE);
	
	painter->Arc(sat, leviCentar, desniCentar);

	painter->EndPath();
	painter->StrokeAndFillPath();

	//Gornji podeoci
	nacrtajPodeoke(painter, sat, 12, 2, 300+ugao, 420+ugao);

	//Donji podeoci
	CPoint krajPrvog, krajDrugog, krajTreceg, krajCetvrtog, krajPetog;

	krajPrvog = CPoint(Centar.x, Centar.y + 9);
	krajDrugog = CPoint(Centar.x - 5, Centar.y + 7);
	krajTreceg = CPoint(Centar.x + 5, Centar.y + 7);
	krajCetvrtog = CPoint(Centar.x - 10, Centar.y + 5);
	krajPetog = CPoint(Centar.x + 10, Centar.y + 5);

	painter->MoveTo(Centar);
	painter->LineTo(krajPrvog);

	painter->MoveTo(Centar);
	painter->LineTo(krajDrugog);

	painter->MoveTo(Centar);
	painter->LineTo(krajTreceg);

	painter->MoveTo(Centar);
	painter->LineTo(krajCetvrtog);
	
	painter->MoveTo(Centar);
	painter->LineTo(krajPetog);

	//--- Vracanje grafickog moda i transformacije
	if (ugao != 0)
	{
		SetWorldTransform(painter->m_hDC, &xFormOld);
		SetGraphicsMode(painter->m_hDC, prevMod);
	}
	
	//--- Vracanje cetkica

	painter->SelectObject(defPen);
	myPen.DeleteObject();
	painter->SelectObject(defBrush);
	myBlueBrush.DeleteObject();
	mySandBrush.DeleteObject();
}

void CGLab1View::nacrtajElZaGorivo(CDC* painter, CRect prozor, CRect sat, int brPodeoka, double startUgao, double krajUgao, double proporcija[], int deloviSkale, COLORREF bojeSkale[], double ugaoKazaljke)
{
	startUgao = startUgao + 180;
	krajUgao = 360 - krajUgao;

	//--- GLAVNI PROZOR ---

	//Olovka i cetka
	CPen myPen = CPen(PS_SOLID, 1, RGB(255, 255, 255));
	CPen* defPen = painter->SelectObject(&myPen);

	CBrush myBrush(RGB(0, 0, 0));
	CBrush * defBrush = painter->SelectObject(&myBrush);

	//painter->Rectangle(sat);

	//Gornji arc

	float radStart = stepen_u_radian(startUgao);
	float radStop = stepen_u_radian(krajUgao);

	int cX = sat.left + (sat.left + sat.right) / 2;
	int cY = sat.bottom;
	int r = sat.Height() / 0.05;

	CPoint startPoint = CPoint(cX + r*cos(radStart), cY + r*sin(radStart));
	CPoint stopPoint = CPoint(cX + r*cos(radStop), cY + r*sin(radStop));

	//Donji arc
	CRect maliRect = CRect((sat.left + sat.right) / 2 - 6, sat.bottom - 8, (sat.left + sat.right) / 2 + 7, sat.bottom);
	CPoint doleStart = CPoint(maliRect.left, (maliRect.top + maliRect.bottom) / 2);
	CPoint doleKraj = CPoint(maliRect.right, (maliRect.top + maliRect.bottom) / 2);

	//painter->Rectangle(maliRect);

	painter->SetArcDirection(AD_CLOCKWISE);
	painter->Arc(sat, startPoint, stopPoint);
	painter->Arc(maliRect, doleStart, doleKraj);

	//Linije

	painter->MoveTo(startPoint);
	painter->LineTo(doleStart);

}
HENHMETAFILE onePath(CDC* painter,CRect wall)
{
	CMetaFileDC MetaDC;
	bool doesntExist = MetaDC.CreateEnhanced(painter,CString("Test.emf"),CRect(0,0,2650,5300),CString("OMK"));
	if(doesntExist)
	{
		CPen * green = new CPen(PS_SOLID,0,RGB(255,0,0));
		CPen * old = MetaDC.SelectObject(green);
	
		CBrush brush(RGB(0,255,0));
		MetaDC.SelectObject(&brush);
		
		MetaDC.Rectangle(0,0,30,80);

		MetaDC.SelectObject(old);
		HENHMETAFILE MF;
		MF = MetaDC.CloseEnhanced();
		MetaDC.DeleteDC();
		DeleteEnhMetaFile(MF);
		old->DeleteObject();
		green->DeleteObject();
	}
	
	return GetEnhMetaFile(CString("Test.emf"));
}
void CGLab1View::testing(CDC* pDC, CRect wall)
{
	CRect imgRect(wall);
	imgRect.bottom = imgRect.bottom / 2;
	imgRect.top = imgRect.top / 2 + imgRect.Height()/4;
	imgRect.left = imgRect.left / 2 + imgRect.Width()/4;
	imgRect.right = imgRect.right / 2;

	pDC->BeginPath();
	pDC->Ellipse(imgRect);
	pDC->EndPath();


	CRgn region;
	region.CreateFromPath(pDC);
	
	CRgn region2;
	region2.CreateRectRgn(0,0,50,50);

	region.CombineRgn(&region,&region2,RGN_XOR);

	//pDC->SelectClipRgn(&region);

	HENHMETAFILE MF = onePath(pDC,wall);

	PlayEnhMetaFile(pDC->m_hDC, MF, wall);

	DImage test;
	bool omk = test.Load(CString("Map.png"));
	CRect pictureSize = new CRect(0, 0, test.Width(), test.Height());
	//if(omk)
		//test.Draw(pDC,pictureSize,wall);
	
}
//lab3

void CGLab1View::nacrtajAvion(CDC* painter,CRect prozor,CString putanja)
{
	int width = prozor.Width();
	int height = prozor.Height();

	CBitmap bmpImage;
	//BOOL suc = bmpImage.LoadBitmap(IDB_BITMAP6);
	bmpImage.LoadBitmapW(IDB_BITMAP6);
	CBitmap bmpMask;
	BITMAP bm;
	
	bmpImage.GetBitmap(&bm);
	
	bmpMask.CreateBitmap(bm.bmWidth,bm.bmHeight,1,1,NULL);
	CDC * SrcDC = new CDC();
	SrcDC->CreateCompatibleDC(NULL);
	CDC * DstDC = new CDC();
	DstDC->CreateCompatibleDC(NULL);

	CBitmap * pOldSrcBmp = SrcDC->SelectObject(&bmpImage);
	CBitmap * pOldDstBmp = DstDC->SelectObject(&bmpMask);

	COLORREF clrTopLeft = SrcDC->GetPixel(0,0);
	COLORREF clrSaveBk = SrcDC->SetBkColor(clrTopLeft);

	DstDC->BitBlt(0,0,bm.bmWidth,bm.bmHeight,SrcDC,0,0,SRCCOPY);

	COLORREF clrSaveDstText = SrcDC->SetTextColor(RGB(255,255,255));
	SrcDC->SetBkColor(RGB(0,0,0));
	SrcDC->BitBlt(0,0,bm.bmWidth,bm.bmHeight,DstDC,0,0,SRCAND);

	DstDC->SetTextColor(clrSaveDstText);
	SrcDC->SetBkColor(clrSaveBk);
	SrcDC->SelectObject(pOldSrcBmp);
	DstDC->SelectObject(pOldDstBmp);
	SrcDC->DeleteDC();
	delete SrcDC;
	DstDC->DeleteDC();
	delete DstDC;

	CDC* MemDC = new CDC();
	MemDC->CreateCompatibleDC(NULL);
	CBitmap * bmpOldT = MemDC->SelectObject(&bmpMask);
	//painter->BitBlt(0,0,bm.bmWidth,bm.bmHeight,MemDC,0,0,SRCAND);
	painter->StretchBlt(width/3,height/3,bm.bmWidth/8,bm.bmHeight/8,MemDC,0,0,bm.bmWidth,bm.bmHeight,SRCAND);


	MemDC->SelectObject(&bmpImage);

	//painter->BitBlt(0,0,bm.bmWidth,bm.bmHeight,MemDC,0,0,SRCPAINT);
	painter->StretchBlt(width/3,height/3,bm.bmWidth/8,bm.bmHeight/8,MemDC,0,0,bm.bmWidth,bm.bmHeight,SRCPAINT);
	
	MemDC->SelectObject(bmpOldT);
	MemDC->DeleteDC();
	delete MemDC;

}
void CGLab1View::nacrtajNebo(CDC* painter,int n,CPoint niz[])
{
	/*DImage x;
	x.Load(CString("F:\Map.png"));
	CRect pictureSize = new CRect(0, 0, x.Width(), x.Height());
	x.Draw(painter, pictureSize, desniEkran);*/

	

}
void CGLab1View::nacrtajFuelWatch(CDC * pDC, CRect wall, CRect watch, COLORREF fuelColor[])
{
	CPen pen(PS_SOLID, 1, RGB(255, 255, 255));
	pDC->SelectObject(pen);
	CBrush newBrush;
	newBrush.CreateSolidBrush(RGB(32, 32, 32));
	pDC->SelectObject(newBrush);

	int width = wall.Width();
	int height = wall.Height();

	CPoint p1;
	CPoint p2;
	//CRect krug;

	/////////ARC
	//pDC->BeginPath();

	p1.SetPoint(width * 0.395, height *  0.66);
	p2.SetPoint(width * 0.463, height *  0.745);
	//krug.SetRect(p1, p2);
	
	p1.SetPoint(width * 0.395, height *  0.69);
	p2.SetPoint(width * 0.463, height *  0.69);
	//pDC->MoveTo(width * 0.44, height *  0.72);
	//pDC->ArcTo(krug, p2, p1);

	///////////FUEL1////////////////////////
	int startEndHeightArc = (watch.bottom + watch.top) / 2.03;

	pDC->BeginPath();
	CPoint p3, p4;
	p3.SetPoint(watch.left, startEndHeightArc);
	p4.SetPoint(watch.right, startEndHeightArc);
	
	p1.SetPoint(watch.left + watch.Width() * 0.25, watch.bottom + watch.Height() * 0.25);
	p2.SetPoint(watch.left + watch.Width() * 0.75, watch.bottom - watch.Height() * 0.25);
	CRect partWatch;
	partWatch.SetRect(p1, p2);
	startEndHeightArc = (partWatch.bottom + partWatch.top) / 2.03;
	p1.SetPoint(partWatch.left, startEndHeightArc);
	p2.SetPoint(partWatch.right, startEndHeightArc);

	pDC->MoveTo(watch.left + watch.Width() * 0.75, startEndHeightArc);
	pDC->ArcTo(watch, p4, p3);
	pDC->SetArcDirection(AD_CLOCKWISE);
	pDC->ArcTo(partWatch, p1, p2);

	pDC->EndPath();
	pDC->StrokeAndFillPath();


	//pDC->Rectangle(watch);
	//pDC->Rectangle(partWatch);
	CRect rectStrelica = partWatch;

	//zeleni deo (srednji)
	CPen greenPen(PS_SOLID, 2, fuelColor[1]);
	pDC->SelectObject(greenPen);
	p1.SetPoint(watch.left + watch.Width() * 0.12, watch.top + watch.Height() * 0.25);
	p2.SetPoint(watch.right - watch.Width() * 0.1, watch.bottom - watch.Height() * 0.1);
	partWatch.SetRect(p1, p2);
	startEndHeightArc = (partWatch.bottom + partWatch.top) / 2.04;
	p1.SetPoint(partWatch.left, startEndHeightArc);
	p2.SetPoint(partWatch.right, startEndHeightArc);
	pDC->Arc(partWatch, p1, p2);

	//Crveni deo (levi deo)
	CPen redPen(PS_SOLID, 2, fuelColor[0]);
	pDC->SelectObject(redPen);
	p1.SetPoint(partWatch.left, startEndHeightArc);
	p2.SetPoint(partWatch.left + watch.Width() * 0.3, startEndHeightArc);
	pDC->Arc(partWatch, p1, p2);
	
	//Zuti deo (desni deo)
	CPen yellowPen(PS_SOLID, 2, fuelColor[2]);
	pDC->SelectObject(yellowPen);
	p1.SetPoint(partWatch.right - watch.Width() * 0.3, startEndHeightArc);
	p2.SetPoint(partWatch.right, startEndHeightArc);
	pDC->SetArcDirection(AD_COUNTERCLOCKWISE);
	pDC->Arc(partWatch, p2, p1);

	//Strelice
	//createClassicNeedle(pDC, watch);
	//pDC->Rectangle(rectStrelica);
	CPoint nizStrelica[3] = {
	CPoint(rectStrelica.left + rectStrelica.Width() / 2  - 1, rectStrelica.bottom ),
	CPoint(rectStrelica.left + rectStrelica.Width() / 2 + 1, rectStrelica.bottom),
	CPoint(partWatch.left + partWatch.Width() / 2, partWatch.top - 2),
	};

	pDC->BeginPath();
	CPen pen3(PS_SOLID, 1, RGB(255, 255, 255));
	pDC->SelectObject(pen3);
	CBrush newBrush3;
	newBrush3.CreateSolidBrush(RGB(255, 255, 255));
	pDC->SelectObject(newBrush3);

	pDC->Polygon(nizStrelica, 3);

	pDC->EndPath();
	pDC->StrokeAndFillPath();

	redPen.DeleteObject();
	yellowPen.DeleteObject();
	greenPen.DeleteObject();
	pen.DeleteObject();
	newBrush.DeleteObject();
}
// Pomocne f-je

void CGLab1View::nacrtajStrelicu(CDC* painter, const CRect prozor, const CRect sat, double ugao, int tipStrelice)
{
	HENHMETAFILE MF;
	CString MetaFileName;

	switch (tipStrelice)
	{
	case 1:
		//MetaFileName = CString("SimplyNeedle.emf");
		MF = createClassicNeedle(painter, sat);
		break;

	case 2:
		//MetaFileName = CString("ComplexNeedle.emf");
		MF = createCircularNeedle(painter, sat);
		break;

	case 3:
		//MetaFileName = CString("PlaneNeedle.emf");
		MF = createPlaneNeedle(painter, sat);
		break;

	default:
		return;
	}

	MF = GetEnhMetaFile(MetaFileName);

	painter->PlayMetaFile(MF, sat);

	DeleteEnhMetaFile(MF);
}

void CGLab1View::nacrtajVrednosti(CDC* painter, CRect prozor, int brPodeoka, CString vrednosti[], int brVrednosti, int brMedjuPodeoka, double pocetniUgao, double krajnjiUgao)
{
	//Font
	CFont Font, *oldFont;
	int charHeight = prozor.Height() * 0.18;
	int charWidth = prozor.Height() * 0.08;
	int lineLength = prozor.Height() * 0.08;

	Font.CreateFontW(charHeight,charWidth,0,0,FW_BLACK,0,0,0,0,0,0,0,0,CString("Arial"));

	oldFont = painter->SelectObject(&Font);
	painter->SetBkColor(RGB(0, 0, 0));
	painter->SetTextColor(RGB(255, 255, 255));

	//Translacija i rotacija teksta pozicije
	int translateTextX = (prozor.left + prozor.Width() / 2);
	int translateTextY = (prozor.top + prozor.Height() / 2);

	int razlikaUglova = abs(pocetniUgao - krajnjiUgao);

	//Graficki mod
	int prevMod = SetGraphicsMode(painter->m_hDC, GM_ADVANCED);

	XFORM xForm, xFormOld;
	GetWorldTransform(painter->m_hDC, &xFormOld);

	for (int i = 0; i < brVrednosti && brVrednosti != 0; i++)
	{
			CString stringVrednost = vrednosti[i];

			int stringDuzina = charWidth * stringVrednost.GetLength();

			int stringStartX = prozor.left + prozor.Width() / 2 - stringDuzina / 2;
			int stringStartY = prozor.top + lineLength + 0.03*prozor.Height();

			//Transliranje do koordinatnog pocetka, simulirajuci da je koordinatni pocetak centar kruga, tj sata
			xForm.eM11 = (FLOAT) 1.0;
			xForm.eM12 = (FLOAT) 0.0;
			xForm.eM21 = (FLOAT) 0.0;
			xForm.eM22 = (FLOAT) 1.0;
			xForm.eDx = (FLOAT)-translateTextX;
			xForm.eDy = (FLOAT)-translateTextY;

			//Odredjivanje ugla rotiranje
			double ugao = (razlikaUglova / (brVrednosti - 1)) * i + pocetniUgao;
			double ugaoRad = stepen_u_radian(ugao);

			//Rotacija linije sa translacijom do odredisne pozicije
			SetWorldTransform(painter->m_hDC, &xForm);

			xForm.eM11 = (FLOAT)cos(ugaoRad);
			xForm.eM12 = (FLOAT)sin(ugaoRad);
			xForm.eM21 = (FLOAT)-sin(ugaoRad);
			xForm.eM22 = (FLOAT)cos(ugaoRad);
			xForm.eDx = (FLOAT)translateTextX;
			xForm.eDy = (FLOAT)translateTextY;
	
			ModifyWorldTransform(painter->m_hDC, &xForm, MWT_RIGHTMULTIPLY);

			painter->TextOutW(stringStartX, stringStartY, stringVrednost);
	}

	//Vracanje grafickog moda
	SetWorldTransform(painter->m_hDC, &xFormOld);
	SetGraphicsMode(painter->m_hDC, prevMod);
}

void CGLab1View::nacrtajPodeoke(CDC* painter, CRect prozor, int brPodeoka, int brMedjuPodeoka, double pocetniUgao, double krajnjiUgao)
{
	//Olovka
	CPen pen, *oldPen = NULL;
	
	CPoint pocetnaTacka = CPoint(prozor.left + prozor.Width() / 2, prozor.top);
	CPoint krajnjaTacka  = CPoint(prozor.left + prozor.Width() / 2, prozor.top + 0.2*prozor.Width() / 2);

	//Graficki mod
	int prevMod = SetGraphicsMode(painter->m_hDC, GM_ADVANCED);

	XFORM xForm, xFormOld;
	GetWorldTransform(painter->m_hDC, &xFormOld);

	//Transliranje na pocetak 
	int translateX = (prozor.left + prozor.Width() / 2);
	int translateY = (prozor.top + prozor.Height() / 2);

	int razlikaUglova = abs(pocetniUgao - krajnjiUgao);

	for (int i = 0; i <= brPodeoka && brPodeoka != 0; i++)
	{
		//Translacija na koordinatni pocetak
		xForm.eM11 = (FLOAT) 1.0;
		xForm.eM12 = (FLOAT) 0.0;
		xForm.eM21 = (FLOAT) 0.0;
		xForm.eM22 = (FLOAT) 1.0;
		xForm.eDx = (FLOAT)-translateX;
		xForm.eDy = (FLOAT)-translateY;

		//Ugao rotacije
		double ugao = (razlikaUglova / brPodeoka) * i + pocetniUgao;
		double ugaoRad = stepen_u_radian(ugao);
		
		///Rotacija
		SetWorldTransform(painter->m_hDC, &xForm);

		xForm.eM11 = (FLOAT)cos(ugaoRad);
		xForm.eM12 = (FLOAT)sin(ugaoRad);
		xForm.eM21 = (FLOAT)-sin(ugaoRad);
		xForm.eM22 = (FLOAT)cos(ugaoRad);
		xForm.eDx = (FLOAT)translateX;
		xForm.eDy = (FLOAT)translateY;

		// Translacija * Rotacija
		ModifyWorldTransform(painter->m_hDC, &xForm, MWT_RIGHTMULTIPLY);

		int debljinaLinije, duzinaLinije;

		if (i % (brMedjuPodeoka+1) == 0)
		{
			duzinaLinije = prozor.Height() * 0.15;
			debljinaLinije = 1;
		}
		else
		{
			duzinaLinije = prozor.Height() * 0.09;
			debljinaLinije = 0;
		}

		pen.CreatePen(PS_SOLID, debljinaLinije, RGB(255, 255, 255));
		oldPen = painter->SelectObject(&pen);

		krajnjaTacka.y = prozor.top + duzinaLinije;
	
		painter->MoveTo(pocetnaTacka);
		painter->LineTo(krajnjaTacka);

		//Vracanje olovke
		painter->SelectObject(oldPen);
		pen.DeleteObject();
	}

	//Vracanje grafickog moda
	SetWorldTransform(painter->m_hDC, &xFormOld);
	SetGraphicsMode(painter->m_hDC, prevMod);

	painter->SelectObject(oldPen);
	pen.DeleteObject();
}

double CGLab1View::radian_u_stepen(double radian)
{
	return (180/PI)*radian;
}

double CGLab1View::stepen_u_radian(double stepen)
{
	return (PI / 180)*stepen;
}

double CGLab1View::scaleValue(double value, double oldMin, double oldMax, double newMin, double newMax)
{
	return (value - oldMin)*(newMax - newMin) / (oldMax - oldMin) + newMin;
}

//Metode za ucitavanje kazaljki

HENHMETAFILE CGLab1View::createClassicNeedle(CDC* painter, CRect prozor)
{
	CMetaFileDC MetaDC;
	MetaDC.CreateEnhanced(painter, CString("SimplyNeedle.emf"), prozor, CString("ClassicNeedle"));

	HENHMETAFILE MF;

	CBrush brush, *oldBrush = NULL;
	brush.CreateSolidBrush(RGB(255, 0, 0));

	CPoint p1 = CPoint(2500, 0);
	CPoint p2 = CPoint(5000, 20000);
	CPoint p3 = CPoint(5000, 60000);
	CPoint p4 = CPoint(0, 60000);
	CPoint p5 = CPoint(0, 20000);
	CPoint p6 = p1;

	CPoint line[] = { p1, p2, p3, p4, p5, p6 };


	painter->SelectObject(&brush);
	MetaDC.Polygon(line, 6);
	painter->SelectObject(oldBrush);
	brush.DeleteObject();

	MF = MetaDC.CloseEnhanced();
	MetaDC.DeleteDC();

	return MF;

	/*ENHMETAHEADER emfHeader;
	GetEnhMetaFileHeader(MF, sizeof(ENHMETAHEADER), &emfHeader);
	int nWidth = emfHeader.rclBounds.right - emfHeader.rclBounds.left;
	int nHeight = emfHeader.rclBounds.bottom - emfHeader.rclBounds.top;
	int factor = 2;
	PlayEnhMetaFile(pDC->m_hDC, MF, CRect(100, 100, 100 + nWidth/factor, 100 + nHeight/factor));
	DeleteEnhMetaFile(MF);*/
}

HENHMETAFILE CGLab1View::createCircularNeedle(CDC* painter, CRect prozor)
{
	CMetaFileDC MetaDC;
	MetaDC.CreateEnhanced(painter, CString("ComplexNeedle.emf"), prozor, CString("CircularNeedle"));

	HENHMETAFILE MF;

	double width = prozor.Width();
	double height = prozor.Height();
	double dveTrecine = 0.66;

	CPen pen, *oldPen;
	pen.CreatePen(PS_SOLID, width / 100, RGB(255, 255, 255));

	CBrush brush, *oldBrush;
	brush.CreateSolidBrush(RGB(255, 255, 255));

	//Gornja Polovina kazaljke
	CPoint p1 = CPoint(prozor.left + width / 2, prozor.top);
	CPoint p2 = CPoint(prozor.left + 0.75 * width, prozor.top + height / 12);
	CPoint p3 = CPoint(p2.x, prozor.top + height / 2);
	CPoint p4 = CPoint(prozor.left + 0.25 * width, p3.y);
	CPoint p5 = CPoint(p4.x, p2.y);
	CPoint p6 = p1;

	CPoint lineTopHalf[] = { p1, p2, p3, p4, p5, p6 };

	oldPen = painter->SelectObject(&pen);

	oldBrush = painter->SelectObject(&brush);
	painter->Polygon(lineTopHalf, 6);
	painter->SelectObject(oldBrush);
	brush.DeleteObject();

	//Donja polovina kruga
	int radius = width / 2;

	double alfa = acos(0.5);

	//---prva linija
	CPoint line1[2];
	line1[0] = CPoint(prozor.left + width / 4, prozor.top + height / 2);
	line1[1] = CPoint(line1[0].x, prozor.top + (dveTrecine * height) - sin(alfa) * radius);

	//---prvi luk
	CPoint arc1P1 = CPoint(prozor.left, prozor.top + (dveTrecine * height) - width / 2);
	CPoint arc1P2 = CPoint(prozor.right, arc1P1.y + width);
	CPoint arc1P3 = CPoint(prozor.left + width / 4, prozor.top + (dveTrecine * height) - radius * sin(alfa));
	CPoint arc1P4 = CPoint(arc1P3.x+0.1, prozor.top + (dveTrecine * height) + radius * sin(alfa));

	//---druga linija
	CPoint line2[2];
	line2[0] = CPoint(line1[0].x, prozor.top + (dveTrecine * height) + radius * sin(alfa));
	line2[1] = CPoint(line2[0].x, prozor.bottom - radius - radius * sin(alfa));

	//---donji luk
	CPoint arc2P1 = CPoint(arc1P1.x, prozor.bottom - width);
	CPoint arc2P2 = prozor.BottomRight();
	CPoint arc2P3 = CPoint(prozor.left + radius / 2+0.1, prozor.bottom - radius - radius * sin(alfa)+0.1);
	CPoint arc2P4 = CPoint(prozor.right - radius / 2, arc2P3.y);

	//---treca linija
	CPoint line3[2];
	line3[0] = arc2P4;
	line3[1] = CPoint(line3[0].x, line2[0].y);

	//---treci luk
	CPoint arc3P1 = arc1P1;
	CPoint arc3P2 = arc1P2;
	CPoint arc3P3 = line3[1];
	CPoint arc3P4 = CPoint(line3[1].x, line1[1].y);

	//---cetvrta linija
	CPoint line4[2];
	line4[0] = CPoint(line3[1].x, line1[1].y);
	line4[1] = CPoint(line4[0].x, line1[0].y);

	//---peta (gornja) linija
	CPoint line5[2];
	line5[0] = line4[1];
	line5[1] = line1[0];

	painter->BeginPath();

	//painter->Polygon(lineTopHalf, 6);

	//prva linija
	painter->MoveTo(line1[0]);
	painter->LineTo(line1[1]);

	//prvi luk
	painter->Arc(arc1P1.x, arc1P1.y, arc1P2.x, arc1P2.y, arc1P3.x, arc1P3.y, arc1P4.x, arc1P4.y);

	//druga linija
	painter->MoveTo(line2[0]);
	painter->LineTo(line2[1]);

	//donji luk
	painter->Arc(arc2P1.x, arc2P1.y, arc2P2.x, arc2P2.y, arc2P3.x, arc2P3.y, arc2P4.x, arc2P4.y);

	//treca linija
	painter->MoveTo(line3[0]);
	painter->LineTo(line3[1]);

	//treci luk
	painter->Arc(arc3P1.x, arc3P1.y, arc3P2.x, arc3P2.y, arc3P3.x, arc3P3.y, arc3P4.x, arc3P4.y);

	//cetvrta linija
	painter->MoveTo(line4[0]);
	painter->LineTo(line4[1]);

	//peta linija
	painter->MoveTo(line5[0]);
	painter->LineTo(line5[1]);

	painter->EndPath();

	painter->StrokePath();
	painter->SelectObject(oldPen);
	pen.DeleteObject();

	pen.CreatePen(PS_SOLID, width / 100, RGB(255, 255, 255));
	brush.CreateSolidBrush(RGB(0, 0, 0));

	oldPen = painter->SelectObject(&pen);
	oldBrush = painter->SelectObject(&brush);

	int pola_sirine = (prozor.left + prozor.right) / 2;
	int pola_visine = (prozor.top + prozor.bottom) / 2;

	painter->Ellipse(pola_sirine - 1, pola_visine, pola_sirine + 1, pola_visine);

	painter->SelectObject(oldBrush);
	painter->SelectObject(oldPen);
	
	brush.DeleteObject();
	pen.DeleteObject();

	MF = MetaDC.CloseEnhanced();
	MetaDC.DeleteDC();

	return MF;
}

HENHMETAFILE CGLab1View::createPlaneNeedle(CDC* painter, CRect prozor)
{
	CMetaFileDC MetaDC;
	MetaDC.CreateEnhanced(painter, CString("PlaneNeedle.emf"), prozor, CString("Plane"));

	HENHMETAFILE MF;

	double width = prozor.Width();
	double height = prozor.Height();
	int left = prozor.left;
	int right = prozor.right;
	int top = prozor.top;
	int bottom = prozor.bottom;
	int centerX = prozor.CenterPoint().x;
	int centerY = prozor.CenterPoint().y;

	CPen pen, *oldPen = NULL;
	pen.CreatePen(PS_SOLID, width / 100, RGB(255, 0, 0));

	CPoint p1 = CPoint(left + width / 2, top);
	CPoint p2 = CPoint(centerX + 0.125 * width, top + 0.3 * height);
	CPoint p3 = CPoint(right, top + 0.5 * height);
	CPoint p4 = CPoint(p3.x, p3.y + 0.1 * height);
	CPoint p5 = CPoint(p2.x, p3.y + abs(p3.y - p4.y) / 2);
	CPoint p6 = CPoint((centerX + p5.x) / 2, bottom - height / 4);
	CPoint p7 = CPoint(left + 0.75 * width, bottom - 0.075 * height);
	CPoint p8 = CPoint(p7.x, bottom);
	CPoint p9 = CPoint(p5.x, p7.y);
	CPoint p10 = CPoint(left + width / 2, bottom);

	CPoint p9P = CPoint(1.999*left + width - p9.x, p9.y);
	CPoint p8P = CPoint(1.999*left + width - p8.x, p8.y);
	CPoint p7P = CPoint(1.999*left + width - p7.x, p7.y);
	CPoint p6P = CPoint(1.999*left + width - p6.x, p6.y);
	CPoint p5P = CPoint(1.999*left + width - p5.x, p5.y);
	CPoint p4P = CPoint(1.999*left + width - p4.x, p4.y);
	CPoint p3P = CPoint(1.999*left + width - p3.x, p3.y);
	CPoint p2P = CPoint(1.999*left + width - p2.x, p2.y);

	CPoint line[] = { p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p9P, p8P, p7P, p6P, p5P, p4P, p3P, p2P, p1 };

	painter->SelectObject(&pen);
	painter->Polygon(line, 20);
	painter->SelectObject(oldPen);
	pen.DeleteObject();

	MF = MetaDC.CloseEnhanced();
	MetaDC.DeleteDC();

	return MF;
}

// CGLab1View diagnostics

#ifdef _DEBUG
void CGLab1View::AssertValid() const
{
	CView::AssertValid();
}

void CGLab1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGLab1Doc* CGLab1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGLab1Doc)));
	return (CGLab1Doc*)m_pDocument;
}
#endif //_DEBUG


// CGLab1View message handlers


void CGLab1View::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	TRACE("Pozicija: %d,%d\n", point.x, point.y);
}


void CGLab1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call defeault
	startPoint.SetPoint(point.x,point.y);
	//CView::OnLButtonDown(nFlags, point);
}
bool calculate(CPoint p1,CPoint p2,long fontLen)
{
	// pow((p2.x - p1.x),2) + pow((p2.y - p1.y))^2)
	float distance = sqrt((float)(pow((float)p2.x - p1.x,2) + pow((float)p2.y - p1.y,2)));
	long floor = (long)distance;
	if(floor < fontLen)
		return false;
	else
		return true;
}

void CGLab1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CDC* painter = this->GetDC();
	painter->MoveTo(startPoint);
	painter->LineTo(point);
	int ugao;
	double koeficijentUgla = (double)(point.y-startPoint.y) / (double)(point.x - startPoint.x);
	ugao = radian_u_stepen(atan(koeficijentUgla));
	CFont font = CFont();
	CFont pomerenFont = CFont();
	painter->SetBkMode(TRANSPARENT);
	CPen * oldPen, * newOne;
	newOne = new CPen(PS_SOLID,1,RGB(0,0,130));
	oldPen = painter->SelectObject(newOne);
	font.CreateFont(20,0,0,0,400,0,0,0,0,0,0,0,0,CString("Times New Roman"));
	CFont * oldFont = painter->SelectObject(&font);
	
	CString tekst = CString("Testing domaci.");
	CSize textSize = painter->GetTextExtent(tekst);
	
	
	if(calculate(startPoint,point,textSize.cx))
	{
		
		this->MessageBox(CString("Tekst je taman."));
		pomerenFont.CreateFont(20,0,ugao*10*-1,0,400,0,0,0,0,0,0,0,0,CString("Times New Roman"));
		painter->SelectObject(&pomerenFont);
		painter->SetTextAlign(TA_BASELINE);
		bool rightToLeftPositiveStroke = startPoint.x > point.x && startPoint.y > point.y;
		bool rightToLeftNegativeStroke = startPoint.x > point.x && startPoint.y < point.y;
		if(rightToLeftPositiveStroke || rightToLeftNegativeStroke)
		{
			painter->TextOut(point.x,point.y,tekst);
		}
		else
		{
			painter->TextOut(startPoint.x,startPoint.y,tekst);
		}
		
		
	}
	else
	{
		this->MessageBox(CString("Tekst je predug."));
	}

	painter->DeleteDC();
	//CView::OnLButtonUp(nFlags, point);
}
