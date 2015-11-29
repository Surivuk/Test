
// GLab1View.h : interface of the CGLab1View class
//

#pragma once


class CGLab1View : public CView
{
protected: // create from serialization only
	CGLab1View();
	DECLARE_DYNCREATE(CGLab1View)

// Attributes
public:
	CGLab1Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	//--- Metode za iscrtavanje kokpita ---

	//LAB 1
	void nacrtajPozadinu(CDC* painter,CRect prozor);
	void nacrtajLeviProzor(CDC* painter,CRect prozor);
	void nacrtajCentralniProzor(CDC* painter,CRect prozor);
	void nacrtajDesniProzor(CDC* painter,CRect prozor);
	void nacrtajKontrolnuTablu(CDC* painter,CRect prozor);
	void nacrtajEkrane(CDC* painter, CRect tabla);

	//LAB2 
	void testing(CDC* pDC,CRect prozor);

	void nacrtajSat(CDC* painter, CRect prozor, CRect sat, int brPodeoka, CString vrednosti[], int brVrednosti, double pocetniUgao, double krajnjiUgao, int tipKazaljke, double ugaoKazaljke);
	void nacrtajZiroskop(CDC* painter, CRect prozor, CRect sat, double ugao);
	
	void nacrtajElZaGorivo(CDC* painter, CRect prozor, CRect sat, int brPodeoka, double startUgao, double krajUgao, double proporcija[], int deloviSkale, COLORREF bojeSkale[], double ugaoKazaljke);

	void nacrtajStrelicu(CDC* painter, const CRect prozor, const CRect sat, double ugao, int tipStrelice);
	void nacrtajVrednosti(CDC* painter, CRect prozor, int brPodeoka, CString vrednosti[], int brVrednosti, int brMedjuPodeoka, double pocetniUgao, double krajnjiUgao);
	void nacrtajPodeoke(CDC* painter, CRect prozor, int brPodeoka,int brMedjuPodeoka, double pocetniUgao, double krajnjiUgao);

	HENHMETAFILE createClassicNeedle(CDC* painter, CRect prozor);
	HENHMETAFILE createCircularNeedle(CDC* painter, CRect prozor);
	HENHMETAFILE createPlaneNeedle(CDC* painter, CRect prozor);

	//lab3
	void nacrtajNebo(CDC* painter,int n,CPoint poly[]);
	static void nacrtajAvion(CDC* painter,CRect prozor,CString putanjaSlike);
	//--- pomocne metode ---

	double radian_u_stepen(double radian);
	double stepen_u_radian(double stepen);
	double scaleValue(double value, double oldMin, double oldMax, double newMin, double newMax);

protected:

// Implementation
public:
	virtual ~CGLab1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in GLab1View.cpp
inline CGLab1Doc* CGLab1View::GetDocument() const
   { return reinterpret_cast<CGLab1Doc*>(m_pDocument); }
#endif

