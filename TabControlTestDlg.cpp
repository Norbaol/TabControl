
// TabControlTestDlg.cpp : implementation file
//
#include "SaveTree.h"
#include "stdafx.h"
#include "TabControlTest.h"
#include "TabControlTestDlg.h"
#include "afxdialogex.h"
#include "Menu.h"
#include "TabOne.h"
#include "TabTwo.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CTabControlTestDlg dialog

extern Hamburger Ham;
extern Steak a_steak;
extern Soda _Soda;
extern Beer _Beer;
int Lv = -1;
int amount = -1;
int chosenfood = -1;
int chosendrink = -1;



CTabControlTestDlg::CTabControlTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTabControlTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	TotalSum = 0;
}

void CTabControlTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_TAB, m_tab);
	DDX_Control(pDX, IDC_OrderList, OrderList);
	DDX_Text(pDX, IDC_EDIT2, TotalSum);
}

BEGIN_MESSAGE_MAP(CTabControlTestDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ORDER, &CTabControlTestDlg::OnBnClickedOrder)
	ON_BN_CLICKED(IDC_DELETE, &CTabControlTestDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_FINALIZE, &CTabControlTestDlg::OnBnClickedFinalize)
	ON_BN_CLICKED(IDC_SAVE, &CTabControlTestDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_LOAD, &CTabControlTestDlg::OnBnClickedLoad)
	ON_BN_CLICKED(IDC_New_Order, &CTabControlTestDlg::OnBnClickedNewOrder)
END_MESSAGE_MAP()


// CTabControlTestDlg message handlers

BOOL CTabControlTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	m_tab.m_tabPages[0] = new CTabFood;
	m_tab.m_tabPages[1] = new CTabDrink;

	m_tab.m_nNumberOfPages = 2;

	Imgl = new CImageList;
	Imgl->Create(IDB_BITMAP1, 32, 0, RGB(255, 255, 255));

	m_tab.Init();

	m_tab.SetImageList(Imgl);

	MenueR = OrderList.InsertItem(_T("ALL ORDERS"), NULL, NULL);
	FoodR = OrderList.InsertItem(_T("FOOD"), MenueR, NULL);
	DrinkR = OrderList.InsertItem(_T("DRINKS"), MenueR, NULL);
	OrderList.Expand(MenueR, TVE_EXPAND);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTabControlTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTabControlTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CTabControlTestDlg::~CTabControlTestDlg()
{
	delete Imgl;
	delete OrderList;
}

void CTabControlTestDlg::OnBnClickedOrder()
{
	if (m_tab.m_tabCurrent == 0)
	{
		// current tab is food
		if (chosenfood == -1)
			MessageBox(_T("Please choose a meal to order"));
		else
		{
			if (Lv == -1)
				MessageBox(_T("Please choose a degree of doneness"));
			else
			{
				if (chosenfood == 0)
				{
					Ham.SetLVofDone(Lv);
					if (MessageBox(Ham.AskConfirmation(), L"Confirm Order", MB_YESNO | MB_TASKMODAL) == IDYES)
					{
						HamburgerR = OrderList.InsertItem(_T("Hamburger"), FoodR, HamburgerR);
						SideR = OrderList.InsertItem(Ham.GetLVofDone(), HamburgerR, NULL);
						SideR = OrderList.InsertItem(Ham.GetOnionState(), HamburgerR, SideR);
						SideR = OrderList.InsertItem(Ham.GetTomatoState(), HamburgerR, SideR);
						SideR = OrderList.InsertItem(Ham.GetLettuceState(), HamburgerR, SideR);
						TotalSum += Ham.GetPrice();
						UpdateData(FALSE);
					}
				}
				else
				{
					a_steak.SetLVofDone(Lv);
					if (MessageBox(a_steak.AskConfirmation(), L"Confirm Order", MB_YESNO | MB_TASKMODAL) == IDYES)
					{
						SteakR = OrderList.InsertItem(_T("Steak"), FoodR, SteakR);
						SideR = OrderList.InsertItem(a_steak.GetLVofDone(), SteakR, NULL);
						TotalSum += a_steak.GetPrice();
						UpdateData(FALSE);
					}
				}
			}
		}
	}
	else
	{
		if (chosendrink == -1)
			MessageBox(_T("Please choose a beverage to order"));
		else
		{
			if (chosendrink <= 1)
			{
				_Soda.SetTypeOfDrink(chosendrink);
				if (MessageBox(_Soda.AskConfirmation(), L"Confirm Order", MB_YESNO | MB_TASKMODAL) == IDYES)
				{
					SodaR = OrderList.InsertItem(_Soda.GetTypeofDrink(), DrinkR, SodaR);
					TotalSum += _Soda.GetPrice();
					UpdateData(FALSE);
				}
			}
			else
			{
				_Beer.SetLiofBeer(amount);
				_Beer.SetTypeOfDrink(chosendrink);
				if(_Beer.GetLiofBeer()!=NULL)
				{
					if (MessageBox(_Beer.AskConfirmation(), L"Confirm Order", MB_YESNO | MB_TASKMODAL) == IDYES)
					{
						BeerR = OrderList.InsertItem(_Beer.GetTypeofDrink(), DrinkR, BeerR);
						OrderList.InsertItem(_Beer.GetLiofBeer(), BeerR, NULL);
						TotalSum += _Beer.GetPrice();
						UpdateData(FALSE);
					}
				}
				else
					MessageBox(_T("Please choose size"));
			}
			
		}
	}
	OrderList.Invalidate();
}


void CTabControlTestDlg::OnBnClickedDelete()
{
	HTREEITEM hItem = OrderList.GetSelectedItem();
	if (OrderList.GetItemText(OrderList.GetNextItem(hItem, TVGN_CHILD)) != L"Finalized")
	{
		CString tempS = OrderList.GetItemText(hItem);
		if (hItem == NULL)
			MessageBox(L"To Delete am Item, you must first select it", L"Nothing to Delete", MB_OK | MB_APPLMODAL | MB_ICONEXCLAMATION);
		else if (hItem == MenueR || hItem == FoodR || hItem == DrinkR)
			MessageBox(L"Can't Delete items through primary Nodes, please select an item", L"Can't let you do that", MB_OK | MB_APPLMODAL | MB_ICONEXCLAMATION);
		else
		{
			tempS = OrderList.GetItemText(hItem);
			if (tempS == L"Hamburger")
			{
				TotalSum -= Ham.GetPrice();
				OrderList.DeleteItem(hItem);
			}
			else if (tempS == L"Steak")
			{
				TotalSum -= a_steak.GetPrice();
				OrderList.DeleteItem(hItem);
			}
			else if (tempS == L"Soda1")
			{
				TotalSum -= 5;
				OrderList.DeleteItem(hItem);
			}
			else if (tempS == L"Soda2")
			{
				TotalSum -= 7;
				OrderList.DeleteItem(hItem);
			}
			else if ((tempS == L"Beer1") || (tempS == L"Beer2"))
			{
				CString tempS2 = OrderList.GetItemText(OrderList.GetChildItem(OrderList.GetSelectedItem()));
				Beer _beer;

				if (tempS == L"Beer1")
					_beer.SetTypeOfDrink(2);
				else if (tempS == L"Beer2")
					_beer.SetTypeOfDrink(3);

				if (tempS2 == L"0.330L")
					_beer.SetLiofBeer(0);
				else if (tempS2 == L"0.5L")
					_beer.SetLiofBeer(1);
				else if (tempS2 == L"1L")
					_beer.SetLiofBeer(2);
				_beer.GetTypeofDrink();
				OrderList.DeleteItem(hItem);
				TotalSum -= _beer.GetPrice();

			}
			UpdateData(FALSE);
		}
	}
	else
		MessageBox(L"This item has already been finalized", L"Can't let you do that", MB_OK | MB_APPLMODAL | MB_ICONEXCLAMATION);
}


void CTabControlTestDlg::OnBnClickedFinalize()
{
	if (MessageBox(L"You are about to Finalize your order\nonce you do it you can't delete an item\n\ncontinue?", L"Confirm Order", MB_YESNO | MB_TASKMODAL) == IDYES)
	{
		HTREEITEM hItem = MenueR;
		while (hItem != NULL)
		{
			hItem = OrderList.GetNextVisibleItem(hItem);
			CString tempS = OrderList.GetItemText(hItem);
			if ((tempS != L"ALL ORDERS") && (tempS != L"FOOD") && (tempS != L"DRINKS"))
			{
				if((tempS == "Hamburger")||(tempS == "Steak")||(tempS == "Soda1")||(tempS == "Beer1")||(tempS == "Soda2")||(tempS == "Beer2"))
					if(OrderList.GetItemText(OrderList.GetNextItem(hItem,TVGN_CHILD))!= L"Finalized")
						OrderList.InsertItem(L"Finalized", hItem, TVI_FIRST);
			}
			else
				OrderList.Expand(hItem,TVE_EXPAND);
		}	
	}
	OpenTree(MenueR);
}


void CTabControlTestDlg::OnBnClickedSave()
{
	// TODO: Add your control notification handler code here
	HTREEITEM hItem = MenueR;
	OpenTree(hItem);
	CFile file(L"FILE.$$", CFile::modeWrite | CFile::modeCreate);
	CArchive ar(&file, CArchive::store);
	hItem= OrderList.GetFirstVisibleItem();
	while (hItem != NULL)
	{
		hItem = OrderList.GetNextVisibleItem(hItem);
		CString tempS = OrderList.GetItemText(hItem);
		if ((tempS != L"FOOD") && (tempS != L"DRINKS"))
		{
			Tree.SetTreeName(tempS);
			Tree.Serialize(ar);
		}
	}
	ar.Close();
	file.Close();
}


void CTabControlTestDlg::OnBnClickedLoad()
{
	// TODO: Add your control notification handler code here
	HTREEITEM hItem = MenueR;
	OrderList.DeleteAllItems();
	TotalSum = 0;
	Beer _beer;
	static int BP = 0;
	UpdateData(FALSE);
	MenueR = OrderList.InsertItem(_T("ALL ORDERS"), NULL, NULL);
	FoodR = OrderList.InsertItem(_T("FOOD"), MenueR, NULL);
	DrinkR = OrderList.InsertItem(_T("DRINKS"), MenueR, NULL);
	OrderList.Expand(MenueR, TVE_EXPAND);

	CFile file(L"FILE.$$", CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	Tree.Serialize(ar);
	while(!ar.IsBufferEmpty())
	{
		if((Tree.Text == "Hamburger")||(Tree.Text == "Steak"))
		{
			hItem=OrderList.InsertItem(Tree.Text, FoodR);
			if(Tree.Text == "Hamburger")
				TotalSum += Ham.GetPrice();
			else
				TotalSum += a_steak.GetPrice();
		}
		else if((Tree.Text == "Soda1")||(Tree.Text == "Soda2")||(Tree.Text == "Beer1")||(Tree.Text == "Beer2"))
		{
			hItem=OrderList.InsertItem(Tree.Text, DrinkR);
			if(Tree.Text == "Soda1")
				TotalSum +=5;
			else if(Tree.Text == "Soda2")
				TotalSum +=7;
			else
			{
				if (Tree.Text == "Beer1")
					BP = 62;
				else
					BP = 58;
				
			}
		}
		else
		{
			OrderList.InsertItem(Tree.Text, hItem);
			if (Tree.Text == L"0.330L")
			{
				_beer.SetLiofBeer(0);
				_beer.SetPrice(BP);
				TotalSum += _beer.GetPrice();
			}
			else if (Tree.Text == "0.5L")
			{
				_beer.SetLiofBeer(1);
				_beer.SetPrice(BP);
				TotalSum += _beer.GetPrice();
			}
			else if (Tree.Text == "1L")
			{
				_beer.SetLiofBeer(2);
				_beer.SetPrice(BP);
				TotalSum += _beer.GetPrice();
			}
		}
		Tree.Serialize(ar);
		UpdateData(FALSE);
	}
	ar.Close();
	file.Close();
	OpenTree(hItem = MenueR);
	OrderList.Invalidate(); 
}

void CTabControlTestDlg::OpenTree(HTREEITEM hItem){
	
	hItem= OrderList.GetFirstVisibleItem();
	while (hItem != NULL)
	{
		OrderList.Expand(hItem,TVE_EXPAND);
		hItem= OrderList.GetNextItem(hItem, TVGN_NEXTVISIBLE);
	}
}

void CTabControlTestDlg::OnBnClickedNewOrder()
{
	// TODO: Add your control notification handler code here
	if(MessageBox(L"Are you sure you want to start a new Menu?\nonce you do, all your current progress will be deleted" , L"Confirm Order", MB_YESNO | MB_TASKMODAL) == IDYES)
	{
		HTREEITEM hItem = MenueR;
		OrderList.DeleteAllItems();
		TotalSum = 0;
		MenueR = OrderList.InsertItem(_T("ALL ORDERS"), NULL, NULL);
		FoodR = OrderList.InsertItem(_T("FOOD"), MenueR, NULL);
		DrinkR = OrderList.InsertItem(_T("DRINKS"), MenueR, NULL);
		OrderList.Expand(MenueR, TVE_EXPAND);
		UpdateData(FALSE);

	}
}
