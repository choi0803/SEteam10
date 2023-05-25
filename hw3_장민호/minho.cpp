#include "headfile.h"

// Class : EnrollRecruitUI
// function : startInterface
// Description : startInterface
// Author : ���ȣ
void EnrollRecruitUI::startInterface(EnrollRecruit* enrollRecruit)
{
	fout << "3.1 ä������ ���(ȸ��ȸ��)" << endl;
	this->selectRecruitEnroll(enrollRecruit);
}

// Class : EnrollRecruitUI
// function : selectRecruitEnroll
// Description : selectRecruitEnroll
// Author : ���ȣ
void EnrollRecruitUI::selectRecruitEnroll(EnrollRecruit* enrollRecruit)
{
	enrollRecruit->enrollRecruit();
}


// Class : EnrollRecruit
// function : Constructor
// Description : Constructor
// Author : ���ȣ
EnrollRecruit::EnrollRecruit()
{
	EnrollRecruitUI* enrollRecruitUI = new EnrollRecruitUI();
	enrollRecruitUI->startInterface(this);
}

// Class : EnrollRecruit
// function : enrollRecruit
// Description : enrollRecruit
// Author : ���ȣ
void EnrollRecruit::enrollRecruit()
{
	string depart;
	int person;
	string deadline;
	fin >> depart >> person >> deadline;

	for (int i = 0; i < 1000; i++)
	{
		if (clientlist->getMyInstance(i)->getCheckLog() == true) {
			Recruit* recruit = new Recruit(depart, person, deadline, clientlist->getMyInstance(i)->getCompanyName(), clientlist->getMyInstance(i)->getBusinessNum());
			recruitlist->addnewRecruit(recruit);
			break;
		}
	}
}


// Class : ListUPUI
// function : startInterface
// Description : startInterface
// Author : ���ȣ
void ListUPUI::startInterface(ListUP* listUP)
{
	fout << "4.1 ä������ �˻�(ȸ��ȸ��)" << endl;
	this->showMyRecruitList(listUP);
}

// Class : ListUPUI
// function : showMyRecruitList
// Description : showMyRecruitList
// Author : ���ȣ
void ListUPUI::showMyRecruitList(ListUP* listUP)
{
	listUP->showRecruits();
}

// Class : ListUP
// function : Constructor
// Description : Constructor
// Author : ���ȣ
ListUP::ListUP()
{
	ListUPUI* listUpUI = new ListUPUI();
	listUpUI->startInterface(this);
}

// Class : ListUP
// function : showRecruits
// Description : showRecruits
// Author : ���ȣ
void ListUP::showRecruits()
{

	string companyName;
	fin >> companyName;
	for (int i = 0; i < 50; i++)
	{
		if (recruitlist->getRecruitByIdx(i)->getCompanyName() == companyName)
		{
			string* info = recruitlist->getRecruitByIdx(i)->getInfo();
			fout << info[0] << info[1] << info[2] << info[3] << info[4] << endl;
		}
	}
}


// Class : ShowApplyInfoUI
// function : showApplyList
// Description : showApplyList
// Author : ���ȣ
void ShowApplyInfoUI::showApplyList(ShowApplyInfo* showApplyInfo)
{
	showApplyInfo->applyList();
}

// Class : ShowApplyInfoUI
// function : startInterface
// Description : startInterface
// Author : ���ȣ
void ShowApplyInfoUI::startInterface(ShowApplyInfo* showApplyInfo)
{
	fout << "4.3 �������� ��ȸ" << endl;
	this->showApplyList(showApplyInfo);
}

// Class : ShowApplyInfo
// function : Constructor
// Description : Constructor
// Author : ���ȣ
ShowApplyInfo::ShowApplyInfo()
{

	ShowApplyInfoUI showApplyInfoUI;
	showApplyInfoUI.startInterface(this);
}

// Class : ShowApplyInfo
// function : applyList
// Description : applyList
// Author : ���ȣ
void ShowApplyInfo::applyList()
{
	for (int i = 0; i < 1000; i++)
	{
		vector<array<string, 4>> my_apply_list_info;

		if (clientlist->getMyInstance(i)->getCheckLog() == true) {
			RecruitList* my_apply_list = clientlist->getMyInstance(i)->getMyApplyList();
			for (int j = 0; j < sizeof(my_apply_list); j++)
			{
				my_apply_list_info.push_back(*my_apply_list->getRecruitByIdx(j)->getfourInfo());

			}

			// ������������ ����
			sort(my_apply_list_info.begin(), my_apply_list_info.end(),
				[](const array<string, 4>& a, const array<string, 4>& b) {
					return a[0] < b[0];
				});

			// ���ĵ� ��� ���
			for (const auto& info : my_apply_list_info) {
				fout << "ȸ���̸�: " << info[0] << ", ����: " << info[1] << ", �ο� ��: " << info[2] << ", ������: " << info[3] << endl;
			}
		}
	}
}