
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
// Description : ȸ������ boundary class
// Author : �ڽÿ�
class SignUpUI
{
private:
public:
	void startInterface(SignUp* signUp, int type);
	void createClient(SignUp* signUp, int type);
};

// Class : SignUp
// Description : ȸ������ control class
// Author : �ڽÿ�
class SignUp
{
private:
public:
	SignUp();
	void addClient(int type);
};

// Class : SignOutUI
// Description : ȸ��Ż�� �ٿ���� Ŭ����
// Author : �ڽÿ�
class SignOutUI
{
private:
public:
	void startInterface(SignOut* signOut);
	void deleteClient(SignOut* signOut);
};

// Class : SignOut
// Description : ȸ��Ż�� ��Ʈ�� Ŭ����
// Author : �ڽÿ�
class SignOut
{
private:
public:
	SignOut();
	void removeClient();
};

// Class : LogInUI
// Description : �α��� �ٿ���� Ŭ����
// Author : �ڽÿ�
class LogInUI
{
private:
public:
	void startInterface(LogIn* logIn);
	void requestLogIn(LogIn* logIn);
};

// Class : LogIn
// Description : �α��� ��Ʈ�� Ŭ����
// Author : �ڽÿ�
class LogIn
{
private:
public:
	LogIn();
	void logIn();
};

// Class : LogOutUI
// Description : �α׾ƿ� �ٿ���� Ŭ����
// Author : �ڽÿ�
class LogOutUI
{
private:
public:
	void startInterface(LogOut* logOut);
	void requestLogOut(LogOut* logOut);
};

// Class : LogOut
// Description : �α׾ƿ� ��Ʈ�� Ŭ����
// Author : �ڽÿ�
class LogOut
{
private:
public:
	LogOut();
	void logOut();
};



class EnrollRecruitUI
{
public:
	void startInterface(EnrollRecruit* enrollRecruit);
	void selectRecruitEnroll(EnrollRecruit* enrollRecruit);
};

class EnrollRecruit
{
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
	void startInterface(Search* search);
	void selectOptions(Search* search);// ȸ�� �̸� �Է¹ޱ�
};


class Search {
public:
	Search();
	void showAbleCompany();
};


class ApplyUI {
public:
	void startInterface(Apply* app);
	void apply(Apply* app);
};

class Apply {
private:
	Recruit* recruit;
public:
	Apply();
	void applyAdd();
};


// Class : ShowApplyInfoUI
// Description : �Ϲ�ȸ���� �ڽ��� ��������(ȸ���̸�, ����, �ο���, ��û ������)�� ��ȸ. �̶� ȸ���̸��� ������������ �����Ͽ� ����Ѵ�.  
// Created : 2022/6/1 9:42 pm
// Author : ���ȣ

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

// Class : Client
// Description :Client
// Author : �ڽÿ�
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
// Author : �ڽÿ�
class CompanyClient : public Client
{
private:
	string companyName;
	string businessNumber;	//�̺κ� string���� ��ħ0524

public:
	CompanyClient(string id, string password, string companyName, string businessNumber);
	virtual string getCompanyName();
	virtual string getBusinessNum();
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
	virtual string getCompanyName();
	virtual string getBusinessNum();
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
	string depart;	//����	
	int personel;	//�ο� ��
	string deadline;//������
	string company_name;	//ȸ���̸�
	string business_num;	//����ڹ�ȣ

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

class RecruitList
{
private:
	Recruit* recruit[50];
	int index = 0;
public:

	void addnewRecruit(Recruit* newrecruit);
	Recruit* getRecruitByIdx(int i);
	//void getMyApplyList();
};


