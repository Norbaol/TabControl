// BeerWidget.cpp : implementation file
//

#include "stdafx.h"
#include "TabControlTest.h"
#include "BeerWidget.h"
#include "afxdialogex.h"
#include "Menu.h"

Beer _Beer;
extern int chosendrink;
extern int amount;
// CBeerWidget dialog

IMPLEMENT_DYNAMIC(CBeerWidget, CDialog)

CBeerWidget::CBeerWidget(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_BEERWIDGET, pParent)
	, ABA(FALSE)
{
}

CBeerWidget::~CBeerWidget()
{
}

void CBeerWidget::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBeerWidget, CDialog)
	ON_BN_CLICKED(IDC_BEER1, &CBeerWidget::OnBnClickedBeer1)
	ON_BN_CLICKED(IDC_ONE_THIRD, &CBeerWidget::OnBnClickedOneThird)
	ON_BN_CLICKED(IDC_HALF, &CBeerWidget::OnBnClickedHalf)
	ON_BN_CLICKED(IDC_LITER, &CBeerWidget::OnBnClickedLiter)
	ON_BN_CLICKED(IDC_BEER2, &CBeerWidget::OnBnClickedBeer2)
END_MESSAGE_MAP()


// CBeerWidget message handlers


void CBeerWidget::OnBnClickedBeer1()
{
	CButton *OneThird= (CButton*)GetDlgItem(IDC_ONE_THIRD);
	if (!OneThird->IsWindowEnabled())
	{
		CButton *Half = (CButton*)GetDlgItem(IDC_HALF);
		CButton *Liter = (CButton*)GetDlgItem(IDC_LITER);
		OneThird->EnableWindow(1);
		Half->EnableWindow(1);
		Liter->EnableWindow(1);
	}
	chosendrink = 2;
}


void CBeerWidget::OnBnClickedBeer2()
{
	CButton *OneThird = (CButton*)GetDlgItem(IDC_ONE_THIRD);
	if (!OneThird->IsWindowEnabled())
	{
		CButton *Half = (CButton*)GetDlgItem(IDC_HALF);
		CButton *Liter = (CButton*)GetDlgItem(IDC_LITER);
		OneThird->EnableWindow(1);
		Half->EnableWindow(1);
		Liter->EnableWindow(1);
	}
	chosendrink = 3;
}


void CBeerWidget::OnBnClickedOneThird()
{
	amount = 0;
}


void CBeerWidget::OnBnClickedHalf()
{
	amount = 1;
}


void CBeerWidget::OnBnClickedLiter()
{
	amount = 2;
}
