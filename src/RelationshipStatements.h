#ifndef __INCLUDED_RELATIONSHIPSTATEMENTS_H__
#define __INCLUDED_RELATIONSHIPSTATEMENTS_H__
#pragma once

class CDaoDatabase;
class wxTextCtrl;

#include <vector>

class CRelationships
{
	public: 
		static void Relationhips(CDaoDatabase &db, std::vector<CString> &RelationFields, const short nRelationCount);
		static void ForeignKeySupport(CDaoDatabase &db, const unsigned &nRelationCount, std::vector<CString> &TableField, std::vector<CString> &ForeignKeySupportinfo, 
			                          CString *&sTableNames, std::vector<CString> &statements, std::vector<int> &beginning, std::vector<int> &end, std::vector <CString> &InsertStatements, 
									  bool &isPossibleToAddForeignKeys, unsigned &nWarningCount, const bool &m_bForeignKeyPrimary, wxTextCtrl *PrgDlg = NULL);

    private:
		static int Findind(CString *&sTableNames, CString &sSearchedTable,const unsigned &nTreeSize);
		static void ForeignKeyPriority(const unsigned &nTreeSize, int **&tree, std::vector<int> &priority);
		static void Preparation(int **&tree, const unsigned &nTreeSize);
		static bool Repeat(int index, std::vector<int> &priority);
		static void CreatePriority(std::vector<CString> &statements, std::vector<int> &priority, CString *&sTableNames, std::vector<int> &beginning, std::vector<int> &end, 
			                       std::vector <CString> &InsertStatements);
};
#endif