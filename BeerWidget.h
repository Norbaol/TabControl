#pragma once


// CBeerWidget dialog

class CBeerWidget : public CDialog
{
	DECLARE_DYNAMIC(CBeerWidget)

public:
	CBeerWidget(CWnd* pParent = NULL);   // standard constructor
	virtual ~CBeerWidget();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BEERWIDGET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBeer1();
	BOOL ABA; // to check if the Amount Buttons are Active
	afx_msg void OnBnClickedOneThird();
	afx_msg void OnBnClickedHalf();
	afx_msg void OnBnClickedLiter();
	afx_msg void OnBnClickedBeer2();
};
