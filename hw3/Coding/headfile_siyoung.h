
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream fin;
ofstream fout;
ClientList* clientlist1;
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

/////////////////

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
};

class CompanyClient : public Client
{
private:
	string companyName;
	string businessNumber;	
public:
	CompanyClient(string id, string password, string companyName, int businessNumber);
	string getCompanyName();
	string getBusinessNum();
	void addRecruit();
};

class GeneralClient : public Client
{
private:
	string name;
	int citizenId;
	RecruitList* myApplyList;
public:
	GeneralClient(string id, string password, string name, int citizenId);
	void addApplyList(string comNumber);
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

///
class Recruit
{
private:
	string depart;	
	int personel;	
	string deadline;
	string company_name;
	string business_num;
public:
	Recruit(string dep, int per, string dead, string name, string num);
	int getPersonel();
	string getDeadline();
	string getCompanyName();
	string getBusinessNumber();
	string getDepart();
	string* getInfo();
	string* getfourInfo();
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

