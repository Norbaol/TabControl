#pragma once
#include "SodaWidget.h"
#include "BeerWidget.h"

// CTabDrink dialog

class CTabDrink : public CDialog
{
	DECLARE_DYNAMIC(CTabDrink)

public:
	CTabDrink(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTabDrink();

// Dialog Data
	enum { IDD = IDD_Drink };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CSodaWidget SodaSelect;
	CBeerWidget BeerSelect;
	afx_msg void OnBnClickedSoda();
	afx_msg void OnBnClickedBeer();
};
