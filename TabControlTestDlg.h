
// TabControlTestDlg.h : header file
//

#pragma once

#include "SaveTree.h"
#include "MyTabCtrl.h"
#include "afxcmn.h"
#include "Menu.h"

// CTabControlTestDlg dialog
class CTabControlTestDlg : public CDialog
{
// Construction
public:
	CTabControlTestDlg(CWnd* pParent = NULL);	// standard constructor
	CTypedPtrArray< CObArray, CTreeCtrl*> tree;
	CMyTabCtrl m_tab;
	CImageList * Imgl;
	~CTabControlTestDlg();
// Dialog Data
	enum { IDD = IDD_RestoProject};

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOrder();
	CTreeCtrl OrderList;
	HTREEITEM MenueR, FoodR, DrinkR, HamburgerR, SteakR, SodaR, BeerR, SideR;
	int TotalSum;
	void OpenTree(HTREEITEM);
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedFinalize();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedLoad();
private:
	SaveTree Tree;
public:
	afx_msg void OnBnClickedNewOrder();
};
