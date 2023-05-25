#include "headfile.h"

// Class : EnrollRecruitUI
// function : startInterface
// Description : startInterface
// Author : 장민호
void EnrollRecruitUI::startInterface(EnrollRecruit* enrollRecruit)
{
	fout << "3.1 채용정보 등록(회사회원)" << endl;
	this->selectRecruitEnroll(enrollRecruit);
}

// Class : EnrollRecruitUI
// function : selectRecruitEnroll
// Description : selectRecruitEnroll
// Author : 장민호
void EnrollRecruitUI::selectRecruitEnroll(EnrollRecruit* enrollRecruit)
{
	enrollRecruit->enrollRecruit();
}


// Class : EnrollRecruit
// function : Constructor
// Description : Constructor
// Author : 장민호
EnrollRecruit::EnrollRecruit()
{
	EnrollRecruitUI* enrollRecruitUI = new EnrollRecruitUI();
	enrollRecruitUI->startInterface(this);
}

// Class : EnrollRecruit
// function : enrollRecruit
// Description : enrollRecruit
// Author : 장민호
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
// Author : 장민호
void ListUPUI::startInterface(ListUP* listUP)
{
	fout << "4.1 채용정보 검색(회사회원)" << endl;
	this->showMyRecruitList(listUP);
}

// Class : ListUPUI
// function : showMyRecruitList
// Description : showMyRecruitList
// Author : 장민호
void ListUPUI::showMyRecruitList(ListUP* listUP)
{
	listUP->showRecruits();
}

// Class : ListUP
// function : Constructor
// Description : Constructor
// Author : 장민호
ListUP::ListUP()
{
	ListUPUI* listUpUI = new ListUPUI();
	listUpUI->startInterface(this);
}

// Class : ListUP
// function : showRecruits
// Description : showRecruits
// Author : 장민호
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
// Author : 장민호
void ShowApplyInfoUI::showApplyList(ShowApplyInfo* showApplyInfo)
{
	showApplyInfo->applyList();
}

// Class : ShowApplyInfoUI
// function : startInterface
// Description : startInterface
// Author : 장민호
void ShowApplyInfoUI::startInterface(ShowApplyInfo* showApplyInfo)
{
	fout << "4.3 지원정보 조회" << endl;
	this->showApplyList(showApplyInfo);
}

// Class : ShowApplyInfo
// function : Constructor
// Description : Constructor
// Author : 장민호
ShowApplyInfo::ShowApplyInfo()
{

	ShowApplyInfoUI showApplyInfoUI;
	showApplyInfoUI.startInterface(this);
}

// Class : ShowApplyInfo
// function : applyList
// Description : applyList
// Author : 장민호
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

			// 오름차순으로 정렬
			sort(my_apply_list_info.begin(), my_apply_list_info.end(),
				[](const array<string, 4>& a, const array<string, 4>& b) {
					return a[0] < b[0];
				});

			// 정렬된 결과 출력
			for (const auto& info : my_apply_list_info) {
				fout << "회사이름: " << info[0] << ", 업무: " << info[1] << ", 인원 수: " << info[2] << ", 마감일: " << info[3] << endl;
			}
		}
	}
}