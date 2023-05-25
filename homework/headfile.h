
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

extern ifstream fin;
extern ofstream fout;
extern ClientList* clientlist;
extern RecruitList* recruitlist;


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


// Class : EnrollRecruitUI
// Description : 채용 정보 등록 바운더리 클래스
// Author : 장민호
class EnrollRecruitUI
{
public:
	void startInterface(EnrollRecruit* enrollRecruit);
	void selectRecruitEnroll(EnrollRecruit* enrollRecruit);
};

// Class : EnrollRecruit
// Description : 채용 정보 등록 컨트롤 클래스
// Author : 장민호
class EnrollRecruit
{
public:
	EnrollRecruit();
	void enrollRecruit();
};

// Class : ListUPUI
// Description : 채용 정보 리스트 조회 바운더리 클래스
// Author : 장민호
class ListUPUI
{
public:
	void startInterface(ListUP* listUP);
	void showMyRecruitList(ListUP* listUP);
};

// Class : ListUP
// Description : 채용 정보 리스트 조회 컨트롤 클래스
// Author : 장민호
class ListUP
{
public:
	ListUP();
	void showRecruits();
};

// Class : SearchUI
// Description : 채용 정보 검색 바운더리 클래스
// Author : 최상혁
class SearchUI {
private:
	
public:
	void startInterface(Search* search);
	void selectOptions(Search* search);// 회사 이름 입력받기
};

// Class : Search
// Description : 채용 정보 검색 컨트롤 클래스
// Author : 최상혁
class Search {
public:
	Search();
	void showAbleCompany();
};

// Class : ApplyUI
// Description : 채용 지원 바운더리 클래스
// Author : 최상혁
class ApplyUI {
public:
	void startInterface(Apply* apply);
	void applys(Apply* apply);
};

// Class : Apply
// Description : 채용 지원 컨트롤 클래스
// Author : 최상혁
class Apply {
public:
	Apply();
	void applyAdd();
};


// Class : ShowApplyInfoUI
// Description : 바운더리 클래스= 일반회원이 자신의 지원정보(회사이름, 업무, 인원수, 신청 마감일)을 조회. 이때 회사이름의 오름차순으로 정렬하여 출력한다.  
// Created : 2022/6/1 9:42 pm
// Author : 장민호

class ShowApplyInfoUI
{
public:
	void showApplyList(ShowApplyInfo* showApplyInfo);
	void startInterface(ShowApplyInfo* showApplyInfo);
};

// Class : ShowApplyInfo
// Description : 컨트롤 클래스= 일반회원이 자신의 지원정보(회사이름, 업무, 인원수, 신청 마감일)을 조회. 이때 회사이름의 오름차순으로 정렬하여 출력한다.  
// Created : 2022/6/1 9:42 pm
// Author : 장민호
class ShowApplyInfo
{
private:

public:
	ShowApplyInfo();
	void applyList();
};

// Class : Client
// Description : Client 클래스를 선언함
// Author : 장민호
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
// Description : CompanyClient를 선언함
// Author : 박시영
class CompanyClient : public Client
{
private:
	string companyName;
	string businessNumber;	//이부분 string으로 고침0524

public:
	CompanyClient( string companyName, string businessNumber, string id, string password );
	virtual string getCompanyName();
	virtual string getBusinessNum();
	void addRecruit();
	virtual void addApplyList(string comNumber);
	virtual RecruitList* getMyApplyList();
};

// Class : GeneralClient
// Description : GeneralClient 클래스를 선언함
// Author : 최상혁
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
	virtual string getCompanyName();
	virtual string getBusinessNum();
};

// Class : ClientList
// Description : ClientList 클래스를 선언함
// Author : 박시영
class ClientList
{
private:
	int index = 0;
	Client* client[1000];

public:
	
	Client* getMyInstance(int i);
	void addClientList(Client *newClient);
	void removeClientList();
};

// Class : Recruit
// Description : Recruit 클래스를 선언함
// Author : 장민호
class Recruit
{
private:
	string depart;	//업무	
	int personel;	//인원 수
	string deadline;//마감일
	string company_name;	//회사이름
	string business_num;	//사업자번호

public:
	Recruit(string dep, int per, string dead, string name, string num);
	int getPersonel();
	string getDeadline();
	string getCompanyName();
	string getBusinessNumber();
	string getDepart();
	string* getInfo();
	array<string, 4>* getfourInfo();
};

// Class : RecruitList
// Description : RecruitList 클래스를 선언함
// Author : 최상혁
class RecruitList
{
private:
	Recruit* recruit[50];
	int index = 0;
public:
	int getIndex();
	void addnewRecruit(Recruit* newrecruit);
	Recruit* getRecruitByIdx(int i);
};


