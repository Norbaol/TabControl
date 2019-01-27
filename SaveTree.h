#pragma once
#include "afxcmn.h"
#include "afx.h"

class SaveTree : public CObject
{
public:
	DECLARE_SERIAL(SaveTree);

	SaveTree(void);
	virtual ~SaveTree(void);
	void SetTreeName(CString);


	void Serialize(CArchive& archive);
	CString Text;

};

