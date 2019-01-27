#pragma once


// CSodaWidget dialog

class CSodaWidget : public CDialog
{
	DECLARE_DYNAMIC(CSodaWidget)

public:
	CSodaWidget(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSodaWidget();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SODAWIDGET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedsoda1();
	afx_msg void OnBnClickedWd();
};
