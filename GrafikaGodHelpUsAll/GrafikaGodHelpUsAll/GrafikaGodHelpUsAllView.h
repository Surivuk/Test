
// GrafikaGodHelpUsAllView.h : interface of the CGrafikaGodHelpUsAllView class
//

#pragma once


class CGrafikaGodHelpUsAllView : public CView
{
protected: // create from serialization only
	CGrafikaGodHelpUsAllView();
	DECLARE_DYNCREATE(CGrafikaGodHelpUsAllView)

// Attributes
public:
	CGrafikaGodHelpUsAllDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	void BezMappiranja(CDC * pDC);
	void IzotropniMapping(CDC * pDC);
	void Kruzni(CDC* pDC,int x1,int y1,int x2,int y2,COLORREF color);
	void Prozori(CDC* pDC, CRect rect, CPoint* points, int length, COLORREF color);
	void InstrumentTabla(CDC* pDC, CRect rect, COLORREF color);
	void Pravougaonik(CDC* pDC, CRect rect, COLORREF color);
	void ZaobljeniPravougaonik(CDC* pDC, CRect wall, COLORREF color);
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CGrafikaGodHelpUsAllView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GrafikaGodHelpUsAllView.cpp
inline CGrafikaGodHelpUsAllDoc* CGrafikaGodHelpUsAllView::GetDocument() const
   { return reinterpret_cast<CGrafikaGodHelpUsAllDoc*>(m_pDocument); }
#endif

