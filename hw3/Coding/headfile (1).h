
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;


class SignUpUI;
class SignUp;
class SignOutUI;
class SignOut;
class LogInUI;
class LogIn;
class LogOutUI;
class LogOut;
class EnrollRecruitUI;
class EnrollRecruit;
class ListUPUI;
class ListUP;
class SearchUI;
class Search;
class ApplyUI;
class Apply;
class ShowApplyInfoUI;
class ShowApplyInfo;
class Client;
class CompanyClient;
class GeneralClient;
class ClientList;
class Recruit;
class RecruitList;

ifstream fin;
ofstream fout;
ClientList* clientlist;
RecruitList* recruitlist;

// Class : SignUpUI
// Description : 회원가입 boundary class
// Author : 박시영
class SignUpUI
{
private:
public:
	void startInterface(SignUp* signUp, int type);
	void createClient(SignUp* signUp, int type);
};

// Class : SignUp
// Description : 회원가입 control class
// Author : 박시영
class SignUp
{
private:
public:
	SignUp();
	void addClient(int type);
};

// Class : SignOutUI
// Description : 회원탈퇴 바운더리 클래스
// Author : 박시영
class SignOutUI
{
private:
public:
	void startInterface(SignOut* signOut);
	void deleteClient(SignOut* signOut);
};

// Class : SignOut
// Description : 회원탈퇴 컨트롤 클래스
// Author : 박시영
class SignOut
{
private:
public:
	SignOut();
	void removeClient();
};

// Class : LogInUI
// Description : 로그인 바운더리 클래스
// Author : 박시영
class LogInUI
{
private:
public:
	void startInterface(LogIn* logIn);
	void requestLogIn(LogIn* logIn);
};

// Class : LogIn
// Description : 로그인 컨트롤 클래스
// Author : 박시영
class LogIn
{
private:
public:
	LogIn();
	void logIn();
};

// Class : LogOutUI
// Description : 로그아웃 바운더리 클래스
// Author : 박시영
class LogOutUI
{
private:
public:
	void startInterface(LogOut* logOut);
	void requestLogOut(LogOut* logOut);
};

// Class : LogOut
// Description : 로그아웃 컨트롤 클래스
// Author : 박시영
class LogOut
{
private:
public:
	LogOut();
	void logOut();
};

// Class : Client
// Description :Client
// Author : 박시영
class Client
{
private:
	string id;
	string password;
	bool checkLog;

public:
	Client(string id, string password);
	void removeClient();
	string getId();
	string getPassword();
	void setCheckLogTrue();
	void setCheckLogFalse();
	bool getCheckLog();
	virtual string getCompanyName() = 0;
	virtual string getBusinessNum() = 0;
	virtual void addApplyList(string comNumber) = 0;
	virtual RecruitList* getMyApplyList() = 0;
};

// Class : CompanyClient
// Description :CompanyClient
// Author : 박시영
class CompanyClient : public Client
{
private:
	string companyName;
	string businessNumber;	//이부분 string으로 고침0524

public:
	CompanyClient(string id, string password, string companyName, int businessNumber);
	virtual string getCompanyName();
	string getBusinessNum();
	void addRecruit();
	virtual void addApplyList(string comNumber);
	virtual RecruitList* getMyApplyList();
};

class GeneralClient : public Client
{
private:
	string name;
	int citizenId;
	RecruitList* myApplyList;


public:
	GeneralClient(string id, string password, string name, int citizenId);
	virtual RecruitList* getMyApplyList();
	virtual void addApplyList(string comNumber);
};

class ClientList
{
private:
	int index = 0;
	Client* client[1000];
	
public:
	Client* getMyInstance(int i);
	void addClientList(Client* newClient);
	void removeClientList();
};

class Recruit
{
private:
	string depart;	//업무	
	int personel;	//인원 수
	string deadline;//마감일
	string company_name;	//회사이름
	string business_num;	//사업자번호

public:
	Recruit(string dep, int per, string dead, string name, string num)
	{
		depart = dep;
		personel = per;
		deadline = dead;
		company_name = name;
		business_num = num;

	}

	int getPersonel() {
		return personel;
	}
	string getDeadline() {
		return deadline;
	}
	string getCompanyName()
	{
		return company_name;
	}

	string getBusinessNumber()
	{
		return business_num;
	}

	string getDepart()
	{
		return depart;
	}
	string* getInfo()
	{
		string* info = new string[5];
		info[0] = this->company_name;
		info[1] = this->business_num;
		info[2] = this->depart;
		info[3] = this->personel;
		info[4] = this->deadline;
		return info;
	}
	array<string, 4>* getfourInfo() {
		array<string, 4>* info =\
			new array<string, 4>{this->company_name, this->depart, to_string(this->personel), this->deadline};
	
		return info;
	}
};

class RecruitList
{
private:
	Recruit* recruit[50];
	int index = 0;
public:

	void addnewRecruit(Recruit* newrecruit)
	{
		this->recruit[index++] = newrecruit;
	}
	Recruit* getRecruitByIdx(int i)
	{
		return this->recruit[i];
	}
	void getMyApplyList()
	{
		for (int i = 0; i < index; i++)
		{
			string* tmp = recruit[i]->getInfo();
			for (int j = 0; j < 5; j++)
			{

				fout << tmp[j] << " ";
			}
			fout << "\n";
		}
	}
};

class EnrollRecruitUI
{
public:
	void startInterface(EnrollRecruit* enrollRecruit);
	void selectRecruitEnroll(EnrollRecruit* enrollRecruit);
};

class EnrollRecruit
{
private:


public:
	EnrollRecruit();
	void enrollRecruit();

};

class ListUPUI
{
public:
	void startInterface(ListUP* listUP);
	void showMyRecruitList(ListUP* listUP);
};

class ListUP
{
public:
	ListUP();
	void showRecruits();
};

class SearchUI {
private:
	
public:
	void startInterface(Search* search) {
		fout << "4.2 검색하기" << "\n";
		selectOptions(search);
	}
	void selectOptions(Search* search) {
		search->showAbleCompany();
	} //회사 이름 입력받기
};


class Search {
private:
	
public:
	Search() {
		SearchUI* searchui;
		searchui->startInterface(this);
	}
	void showAbleCompany() {
		string comname;
		fin >> comname;
		for (int i = 0; i < 50; i++) {
			if (recruitlist->getRecruitByIdx(i)->getCompanyName() == comname) {
				//회사이름, 업무, 인원수, 신청 마감일
				fout << recruitlist->getRecruitByIdx(i)->getCompanyName() <<" ";
				fout << recruitlist->getRecruitByIdx(i)->getDepart() << " ";
				fout << recruitlist->getRecruitByIdx(i)->getPersonel() << " ";
				fout << recruitlist->getRecruitByIdx(i)->getDeadline() << " ";
			}
		}
	}
};


class ApplyUI {
private:

public:
	void startInterface(Apply* app) {
		fout << "4.3 지원하기" << "\n";
		apply(app);
	}
	void apply(Apply* app) {
		app->applyAdd();
	}
};


class Apply {
private:
	Recruit* recruit;
public:
	Apply() {
		ApplyUI* applyui;
		applyui->startInterface(this);
	}
	void applyAdd() {
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
};


// Class : ShowApplyInfoUI
// Description : 일반회원이 자신의 지원정보(회사이름, 업무, 인원수, 신청 마감일)을 조회. 이때 회사이름의 오름차순으로 정렬하여 출력한다.  
// Created : 2022/6/1 9:42 pm
// Author : 장민호

class ShowApplyInfoUI
{
public:
	void showApplyList(ShowApplyInfo* showApplyInfo);
	void startInterface(ShowApplyInfo* showApplyInfo);
};

class ShowApplyInfo
{
private:

public:
	ShowApplyInfo();
	void applyList();
};
