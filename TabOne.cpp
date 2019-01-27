// TabOne.cpp : implementation file
//

#include "stdafx.h"
#include "TabControlTest.h"
#include "TabOne.h"
#include "afxdialogex.h"
#include "Menu.h"

extern int Lv;
extern int chosenfood;
Hamburger Ham;
Steak a_steak;
// CTabFood dialog

IMPLEMENT_DYNAMIC(CTabFood, CDialog)

CTabFood::CTabFood(CWnd* pParent /*=NULL*/)
	: CDialog(CTabFood::IDD, pParent)
	, AddOnOnion(FALSE)
	, AddOnTomato(FALSE)
	, AddOnLettuce(FALSE)
{

}

CTabFood::~CTabFood()
{
}

void CTabFood::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_Lettuce, AddOnLettuce);
	DDX_Check(pDX, IDC_Onions, AddOnOnion);
	DDX_Check(pDX, IDC_Tomatos, AddOnTomato);
}


BEGIN_MESSAGE_MAP(CTabFood, CDialog)
	ON_BN_CLICKED(IDC_Hamburger, &CTabFood::OnBnClickedHamburger)
	ON_BN_CLICKED(IDC_RA, &CTabFood::OnBnClickedRa)
	ON_BN_CLICKED(IDC_MR, &CTabFood::OnBnClickedMr)
	ON_BN_CLICKED(IDC_MED, &CTabFood::OnBnClickedMed)
	ON_BN_CLICKED(IDC_MW, &CTabFood::OnBnClickedMw)
	ON_BN_CLICKED(IDC_WD, &CTabFood::OnBnClickedWd)
	ON_BN_CLICKED(IDC_Steak, &CTabFood::OnBnClickedSteak)
	ON_BN_CLICKED(IDC_Lettuce, &CTabFood::OnBnClickedLettuce)
	ON_BN_CLICKED(IDC_Tomatos, &CTabFood::OnBnClickedTomatos)
	ON_BN_CLICKED(IDC_Onions, &CTabFood::OnBnClickedOnions)
END_MESSAGE_MAP()


// CTabFood message handlers


void CTabFood::OnBnClickedHamburger()
{
	chosenfood = 0;
	CButton* onions = (CButton*)GetDlgItem(IDC_Onions);
	CButton* tomatos = (CButton*)GetDlgItem(IDC_Tomatos);
	CButton* lettuce = (CButton*)GetDlgItem(IDC_Lettuce);
	if (!onions->IsWindowEnabled())
	{
		onions->EnableWindow(1);
		tomatos->EnableWindow(1);
		lettuce->EnableWindow(1);
	}
}

void CTabFood::OnBnClickedSteak()
{
	chosenfood = 1;
	CButton* onions = (CButton*)GetDlgItem(IDC_Onions);
	CButton* tomatos = (CButton*)GetDlgItem(IDC_Tomatos);
	CButton* lettuce = (CButton*)GetDlgItem(IDC_Lettuce);
	if (onions->IsWindowEnabled())
	{
		onions->EnableWindow(0);
		tomatos->EnableWindow(0);
		lettuce->EnableWindow(0);
	}
}


void CTabFood::OnBnClickedRa()
{
	Lv = 0;
}


void CTabFood::OnBnClickedMr()
{
	Lv = 1;
}


void CTabFood::OnBnClickedMed()
{
	Lv = 2;
}


void CTabFood::OnBnClickedMw()
{
	Lv = 3;
}


void CTabFood::OnBnClickedWd()
{
	Lv = 4;
}

void CTabFood::OnBnClickedLettuce()
{
	UpdateData(TRUE);
	Ham.SetLettuceState(AddOnLettuce);
}


void CTabFood::OnBnClickedTomatos()
{
	UpdateData(TRUE);
	Ham.SetTomatoState(AddOnTomato);
}


void CTabFood::OnBnClickedOnions()
{
	UpdateData(TRUE);
	Ham.SetOnionState(AddOnOnion);
}
