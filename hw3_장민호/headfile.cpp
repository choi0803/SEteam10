#include "headfile.h"


// function = startInterface
// Description = 검색을 시작하는 문구를 띄우며 selectOptions 함수를 실행한다
// Author = 최상혁
void SearchUI::startInterface(Search* search) {
	fout << "4.2 검색하기" << "\n";
	selectOptions(search);
}

// function = selectOptions
// Description = Search 컨트롤로 넘어가서 showAbleCompany() 함수를 실행한다
// Author = 최상혁
void SearchUI::selectOptions(Search* search) {
	search->showAbleCompany();
}

// function = Search
// Description = 생성자 역할뿐만 아니라 startInterface에 자신의 객체를 전달한다
// Author = 최상혁
Search::Search() {
	SearchUI* searchui = new SearchUI();
	searchui->startInterface(this);
}

// function = showAbleCompany
// Description = 회사이름에 따른 회사이름, 업무, 인원수, 신청 마감일 정보를 출력한다
// Author = 최상혁
void Search::showAbleCompany() {
	string comname;
	fin >> comname;
	for (int i = 0; i < 50; i++) {
		if (recruitlist->getRecruitByIdx(i)->getCompanyName() == comname) {
			//회사이름, 업무, 인원수, 신청 마감일
			fout << recruitlist->getRecruitByIdx(i)->getCompanyName() << " ";
			fout << recruitlist->getRecruitByIdx(i)->getDepart() << " ";
			fout << recruitlist->getRecruitByIdx(i)->getPersonel() << " ";
			fout << recruitlist->getRecruitByIdx(i)->getDeadline() << " ";
		}
	}
}

// function = startInterface
// Description = 지원하기 문구를 출력하고 apply 함수를 매개변수를 넘겨주고 호출한다
// Author = 최상혁
void ApplyUI::startInterface(Apply* app) {
	fout << "4.3 지원하기" << "\n";
	apply(app);
}

// function = apply
// Description = 받은 매개변수 내의 applyAdd함수를 호출한다
// Author = 최상혁
void ApplyUI::apply(Apply* app) {
	app->applyAdd();
}

// function = Apply
// Description = 생성자로, 자기 객체를 startInterface에 넘겨주고 호출한다
// Author = 최상혁
Apply::Apply() {
	ApplyUI* applyui = new ApplyUI();
	applyui->startInterface(this);
}

// function = applyAdd
// Description = 받은 사업자 번호를 addApplyList에 넘겨준다
// Author = 최상혁
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