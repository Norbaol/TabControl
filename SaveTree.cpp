#include "StdAfx.h"
#include "SaveTree.h"
#include "string.h"

IMPLEMENT_SERIAL(SaveTree, CObject, 1)

SaveTree::SaveTree(void)
{
}


SaveTree::~SaveTree(void)
{
}

void SaveTree::SetTreeName(CString tempS)
{
	Text=tempS;
}

void SaveTree::Serialize( CArchive& archive )
{
    CObject::Serialize(archive);

    if( archive.IsStoring() )

        archive << Text;
    else
        archive >> Text;

}