#pragma once


// CMyTabCtrl

class CMyTabCtrl : public CTabCtrl
{
	DECLARE_DYNAMIC(CMyTabCtrl)

public:
	CMyTabCtrl();
	virtual ~CMyTabCtrl();
	void Init();
	CDialog *m_tabPages[2];
	int m_tabCurrent;
	int m_nNumberOfPages;

protected:
	DECLARE_MESSAGE_MAP()
public:
	void SetRectangle(void);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};