// TabTwo.cpp : implementation file
//

#include "stdafx.h"
#include "TabControlTest.h"
#include "TabTwo.h"
#include "afxdialogex.h"
#include "SodaWidget.h"

extern int chosendrink;
extern int amount;

// CTabDrink dialog

IMPLEMENT_DYNAMIC(CTabDrink, CDialog)

CTabDrink::CTabDrink(CWnd* pParent /*=NULL*/)
	: CDialog(CTabDrink::IDD, pParent)
{

}

CTabDrink::~CTabDrink()
{
}

void CTabDrink::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabDrink, CDialog)
	ON_BN_CLICKED(IDC_Soda, &CTabDrink::OnBnClickedSoda)
	ON_BN_CLICKED(IDC_Beer, &CTabDrink::OnBnClickedBeer)
END_MESSAGE_MAP()


// CTabDrink message handlers


void CTabDrink::OnBnClickedSoda()
{
	chosendrink = -1;
	SodaSelect.DestroyWindow();
	BeerSelect.DestroyWindow();
	SodaSelect.Create(IDD_SODAWIDGET, this);
	SodaSelect.SetWindowPos(GetDlgItem(IDD_SODAWIDGET), -1, 225, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE);
}


void CTabDrink::OnBnClickedBeer()
{
	amount = -1;
	chosendrink = -1;
	SodaSelect.DestroyWindow();
	BeerSelect.DestroyWindow();
	BeerSelect.Create(IDD_BEERWIDGET, this);
	BeerSelect.SetWindowPos(GetDlgItem(IDD_BEERWIDGET), -1, 225, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE);
}
