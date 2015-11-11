
// CockpitView.h : interface of the CCockpitView class
//

#pragma once


class CCockpitView : public CView
{
protected: // create from serialization only
	CCockpitView();
	DECLARE_DYNCREATE(CCockpitView)

// Attributes
public:
	CCockpitDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual void DrawBezier(CDC* pDC, CRect rect, CPoint* points, int length, COLORREF color);
	virtual void DrawRectangle(CDC* pDC, CRect rect, COLORREF color);
	virtual void DrawInstrumenTable(CDC* pDC, CRect rect, COLORREF color);
	virtual void DrawRoundRect(CDC* pDC, CRect wall, COLORREF color);

	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CCockpitView();
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

#ifndef _DEBUG  // debug version in CockpitView.cpp
inline CCockpitDoc* CCockpitView::GetDocument() const
   { return reinterpret_cast<CCockpitDoc*>(m_pDocument); }
#endif

