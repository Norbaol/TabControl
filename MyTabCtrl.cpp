// MyTabCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "TabControlTest.h"
#include "MyTabCtrl.h"

#include "TabOne.h"
#include "TabTwo.h"

// CMyTabCtrl
extern int chosenfood;

IMPLEMENT_DYNAMIC(CMyTabCtrl, CTabCtrl)

CMyTabCtrl::CMyTabCtrl()
{

}

CMyTabCtrl::~CMyTabCtrl()
{
	for(int nCount=0;nCount<m_nNumberOfPages;nCount++)
	{
		delete m_tabPages[nCount];
	}
}

void CMyTabCtrl::Init()
{
	InsertItem(0, _T("Food"), 0);
	InsertItem(1, _T("Drink"), 1);

	m_tabCurrent = 0;

	m_tabPages[0]->Create(IDD_Food, this);
	m_tabPages[1]->Create(IDD_Drink, this);

	m_tabPages[0]->ShowWindow(SW_SHOW);
	m_tabPages[1]->ShowWindow(SW_HIDE);

	SetRectangle();
}


BEGIN_MESSAGE_MAP(CMyTabCtrl, CTabCtrl)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CMyTabCtrl message handlers

void CMyTabCtrl::SetRectangle(void)
{
	CRect tabRect, itemRect;
	int nX, nY, nXc, nYc;

	GetClientRect(&tabRect);
	GetItemRect(0,&itemRect);

	nX=itemRect.left;
	nY=itemRect.bottom+25;
	nXc=tabRect.right-itemRect.left;
	nYc=tabRect.bottom-nY;

	m_tabPages[0]->SetWindowPos(&wndTop, nX, nY, nXc, nYc, SWP_SHOWWINDOW);
	for(int nCount=1;nCount<m_nNumberOfPages;nCount++)
	{
		m_tabPages[nCount]->SetWindowPos(&wndTop, nX, nY, nXc, nYc, SWP_HIDEWINDOW);
	}
}


void CMyTabCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CTabCtrl::OnLButtonDown(nFlags, point);

	if(m_tabCurrent != GetCurFocus())
	{
		chosenfood = -1;
		m_tabPages[m_tabCurrent]->ShowWindow(SW_HIDE);
		m_tabCurrent=GetCurFocus();
		m_tabPages[m_tabCurrent]->ShowWindow(SW_SHOW);
		m_tabPages[m_tabCurrent]->SetFocus();
	}
}