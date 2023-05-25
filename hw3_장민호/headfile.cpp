#include "headfile.h"


// function = startInterface
// Description = �˻��� �����ϴ� ������ ���� selectOptions �Լ��� �����Ѵ�
// Author = �ֻ���
void SearchUI::startInterface(Search* search) {
	fout << "4.2 �˻��ϱ�" << "\n";
	selectOptions(search);
}

// function = selectOptions
// Description = Search ��Ʈ�ѷ� �Ѿ�� showAbleCompany() �Լ��� �����Ѵ�
// Author = �ֻ���
void SearchUI::selectOptions(Search* search) {
	search->showAbleCompany();
}

// function = Search
// Description = ������ ���һӸ� �ƴ϶� startInterface�� �ڽ��� ��ü�� �����Ѵ�
// Author = �ֻ���
Search::Search() {
	SearchUI* searchui = new SearchUI();
	searchui->startInterface(this);
}

// function = showAbleCompany
// Description = ȸ���̸��� ���� ȸ���̸�, ����, �ο���, ��û ������ ������ ����Ѵ�
// Author = �ֻ���
void Search::showAbleCompany() {
	string comname;
	fin >> comname;
	for (int i = 0; i < 50; i++) {
		if (recruitlist->getRecruitByIdx(i)->getCompanyName() == comname) {
			//ȸ���̸�, ����, �ο���, ��û ������
			fout << recruitlist->getRecruitByIdx(i)->getCompanyName() << " ";
			fout << recruitlist->getRecruitByIdx(i)->getDepart() << " ";
			fout << recruitlist->getRecruitByIdx(i)->getPersonel() << " ";
			fout << recruitlist->getRecruitByIdx(i)->getDeadline() << " ";
		}
	}
}

// function = startInterface
// Description = �����ϱ� ������ ����ϰ� apply �Լ��� �Ű������� �Ѱ��ְ� ȣ���Ѵ�
// Author = �ֻ���
void ApplyUI::startInterface(Apply* app) {
	fout << "4.3 �����ϱ�" << "\n";
	apply(app);
}

// function = apply
// Description = ���� �Ű����� ���� applyAdd�Լ��� ȣ���Ѵ�
// Author = �ֻ���
void ApplyUI::apply(Apply* app) {
	app->applyAdd();
}

// function = Apply
// Description = �����ڷ�, �ڱ� ��ü�� startInterface�� �Ѱ��ְ� ȣ���Ѵ�
// Author = �ֻ���
Apply::Apply() {
	ApplyUI* applyui = new ApplyUI();
	applyui->startInterface(this);
}

// function = applyAdd
// Description = ���� ����� ��ȣ�� addApplyList�� �Ѱ��ش�
// Author = �ֻ���
void Apply::applyAdd() {
	string businessnum;
	fin >> businessnum;
	for (int i = 0; i < 1000; i++)
	{
		if (clientlist->getMyInstance(i)->getCheckLog() == true) {
			clientlist->getMyInstance(i)->addApplyList(businessnum);
			break;
		}
	}
}