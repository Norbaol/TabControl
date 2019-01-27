#pragma once
#include "TabControlTest.h"

// CTabFood dialog

class CTabFood : public CDialog
{
	DECLARE_DYNAMIC(CTabFood)

public:
	CTabFood(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTabFood();

// Dialog Data
	enum { IDD = IDD_Food };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedHamburger();
	afx_msg void OnBnClickedSteak();
	afx_msg void OnBnClickedRa();
	afx_msg void OnBnClickedMr();
	afx_msg void OnBnClickedMed();
	afx_msg void OnBnClickedMw();
	afx_msg void OnBnClickedWd();
	BOOL AddOnOnion;
	BOOL AddOnTomato;
	BOOL AddOnLettuce;
	afx_msg void OnBnClickedLettuce();
	afx_msg void OnBnClickedTomatos();
	afx_msg void OnBnClickedOnions();
};
