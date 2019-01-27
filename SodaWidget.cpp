// SodaWidget.cpp : implementation file
//

#include "stdafx.h"
#include "TabControlTest.h"
#include "SodaWidget.h"
#include "afxdialogex.h"
#include "Menu.h"

Soda _Soda;
extern int chosendrink;

// CSodaWidget dialog

IMPLEMENT_DYNAMIC(CSodaWidget, CDialog)

CSodaWidget::CSodaWidget(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SODAWIDGET, pParent)
{

}

CSodaWidget::~CSodaWidget()
{
}

void CSodaWidget::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSodaWidget, CDialog)
	ON_BN_CLICKED(IDC_soda1, &CSodaWidget::OnBnClickedsoda1)
	ON_BN_CLICKED(IDC_WD, &CSodaWidget::OnBnClickedWd)
END_MESSAGE_MAP()


// CSodaWidget message handlers


void CSodaWidget::OnBnClickedsoda1()
{
	chosendrink = 0;
	_Soda.SetPrice(5);
	_Soda.SetTypeOfDrink(0);
}


void CSodaWidget::OnBnClickedWd()
{
	chosendrink = 1;
	_Soda.SetPrice(7);
	_Soda.SetTypeOfDrink(1);
}
