#include "headfile_siyoung.h"

ifstream fin;
ofstream fout;
ClientList* clientlist;

// Function : startInterface
// Description : 회원가입을 출력하고 control class 호출
// Author : 박시영
void SignUpUI::startInterface(SignUp* signUp, int type) {
    fout << "1. 1 회원가입 \n";
	createClient(signUp, type);
}

// Function : createClient
// Description : signUp의 addClient호출
// Author : 박시영
void SignUpUI::createClient(SignUp* signUp, int type)
{
	signUp->addClient(type);
}

// Function : SignUp
// Description : 생성자
// Author : 박시영
SignUp::SignUp() 
{
	SignUpUI* signUpUI;
	int type;
	fin >> type;
	signUpUI->startInterface(this, type);
}

// Function : addClient
// Description : type에따라 회원 나뉘어 생성
// Author : 박시영
void SignUp::addClient(int type)
{
	if (type == 1) {
		string id, password, companyName;
		int businessNumber;
		fin >> id >> password >> companyName >> businessNumber;
		Client* newClient = new CompanyClient(id, password, companyName, businessNumber);
		clientlist->addClientList(newClient);
		fout << id << password << companyName << businessNumber;
	}
	else if (type == 2) {
		string id, password, name;
		int citizenId;
		fin >> id >> password >> name >> citizenId;
		Client* newClient = new GeneralClient(id, password, name, citizenId);
		clientlist->addClientList(newClient);
		fout << id << password << name << citizenId;
	}
}

// Function : startInterface
// Description : 회원 탈퇴 출력하고 control class 호출
// Author : 박시영
void SignOutUI::startInterface(SignOut* signOut) {
	fout << "1. 2 회원탈퇴 \n";
	deleteClient(signOut);
}
// Function : deleteClient
// Description : signOut의 removeClient호출
// Author : 박시영
void SignOutUI::deleteClient(SignOut* signOut) {
	signOut->removeClient();
}

// Function : SignOut
// Description : 생성자
// Author : 박시영
SignOut::SignOut() {
	SignOutUI* signOutUI;
	signOutUI->startInterface(this);
}

// Function : removeClient
// Description : list에서 클라이언트 목록 삭제
// Author : 박시영
void SignOut::removeClient() {
	clientlist->removeClientList();
}

// Function : startInterface
// Description : 로그인 출력하고 컨트롤 클래스 호출
// Author : 박시영
void LogInUI::startInterface(LogIn* logIn) {
	fout << "2. 1 로그인\n";
	requestLogIn(logIn);
}

// Function : requestLogIn
// Description : 컨트롤 클래스의 login호출
// Author : 박시영
void LogInUI::requestLogIn(LogIn* logIn) {
	logIn->logIn();
}

// Function : LogIn
// Description : 생성자
// Author : 박시영
LogIn::LogIn() {
	LogInUI* logInUI;
	logInUI->startInterface(this);
}

// Function : logIn
// Description : list에서 Id, pw 비교해서 맞으면 로그인상태로 변경
// Author : 박시영
void LogIn::logIn() {
	string id, pw;
	fin >> id >> pw;
	for (int i = 0; i < 1000; i++) {
		if ((clientlist->getMyInstance(i)->getId() == id) && (clientlist->getMyInstance(i)->getPassword() == pw)) {
			fout << clientlist->getMyInstance(i)->getId() << clientlist->getMyInstance(i)->getPassword();
			clientlist->getMyInstance(i)->setCheckLogTrue();
			break;
		}
	}
}

// Function : startInterface
// Description : 로그아웃 출력 후 컨트롤 클래스 호출
// Author : 박시영
void LogOutUI::startInterface(LogOut* logOut) {
	fout << "2. 2 로그아웃\n";
	requestLogOut(logOut);
}
// Function : reqeustLogOut
// Description : 컨트롤 클래스의 logOut호출
// Author : 박시영
void LogOutUI::requestLogOut(LogOut* logOut) {
	logOut->logOut();
}

// Function : LogOut
// Description : 생성자
// Author : 박시영
LogOut::LogOut() {
	LogOutUI* logOutUI;
	logOutUI->startInterface(this);
}

// Function : logOut
// Description : list에서 로그인 상태인 것을 찾아 로그아웃 시킴
// Author : 박시영
void LogOut::logOut() {
	for (int i = 0; i < 1000; i++) {
		if (clientlist->getMyInstance(i)->getCheckLog() == true) {
			fout << clientlist->getMyInstance(i)->getId() << "\n";
			clientlist->getMyInstance(i)->setCheckLogFalse();
			break;
		}
	}
}

// -------------------entity---------------

// Function : Client
// Description : 생성자
// Author : 박시영
Client::Client(string id, string password) {
	this->id = id;
	this->password = password;
}

// Function : removeClient
// Description : id출력하고 생성자 삭제
// Author : 박시영
void Client::removeClient() {
	fout << id << "\n";
	delete this;
}

// Function : getId
// Description : return id 
// Author : 박시영
string Client::getId() {
	return this->id;
}

// Function : getPassword
// Description : return password 
// Author : 박시영
string Client::getPassword() {
	return this->password;
}

// Function : setCheckLogTrue
// Description : 로그인상태 true 
// Author : 박시영
void Client::setCheckLogTrue() {
	this->checkLog = true;
}

// Function : setCheckLogFalse
// Description : 로그인상태 false
// Author : 박시영
void Client::setCheckLogFalse() {
	this->checkLog = false;
}

// Function : getCheckLog
// Description : return 로그인상태
// Author : 박시영
bool Client::getCheckLog() {
	return this->checkLog;
}

// Function : CompanyClient
// Description : 생성자 
// Author : 박시영
CompanyClient::CompanyClient(string id, string password, string companyName, int businessNumber) : Client(id, password) {
	this->companyName = companyName;
	this->businessNumber = businessNumber;
}

// Function : getCompanyName
// Description : return companyName 
// Author : 박시영	
string CompanyClient::getCompanyName()
{
	return this->companyName;
}

// Function : getBusinessNum
// Description : return businessNumber 
// Author : 박시영
string CompanyClient::getBusinessNum()
{
	return this->businessNumber;
}

// Function : addRecruit
// Description : Recruit 생성, 리쿠르트리스트에 추가
// Author : 박시영
void CompanyClient::addRecruit()
{
	string depart, deadline;
	int personel;
	fin >> depart >> personel >> deadline;
	Recruit* recruit = new Recruit(depart, personel, deadline, this->getCompanyName(), this->getBusinessNum());
	recruitlist->addnewRecruit(recruit);
}

// Function : GeneralClient
// Description : 생성자
// Author : 박시영
GeneralClient::GeneralClient(string id, string password, string name, int citizenId) : Client(id, password) {
	this->name = name;
	this->citizenId = citizenId;
	this->myApplyList = nullptr;
}

// Function : addApplyList
// Description : 지원 회사 정보 출력 후, 본인 지원서리스트 증가 
// Author : 박시영
void GeneralClient::addApplyList(string comNumber)
{
	for (int i = 0; i < 1000; i++) {
		if (recruitlist->recruit[i]->getBusinessNumber() == comNumber) {
			fout << recruitlist->recruit[i]->getCompanyName() << ""\
				<< recruitlist->recruit[i]->getBusinessNumber() << ""\
				<< recruitlist->recruit[i]->getDepart();
			this->myApplyList->addnewRecruit(recruitlist->recruit[i]);
			break;
		}
	}
}

// Function : getMyInstance
// Description : return clinet[i] 
// Author : 박시영
Client* ClientList::getMyInstance(int i) {
    return this->client[i];
}

// Function : addClientList
// Description : clientList에 새로운 client 추가
// Author : 박시영
void ClientList::addClientList(Client* newClient) {
	client[index++] = newClient;
}

// Function : removeClientList
// Description : list에서 로그인 중인 클라이언트 목록 삭제 
// Author : 박시영
void ClientList::removeClientList() {
	for (int i = 0; i < 1000; i++) {
		if (client[i] == nullptr) continue;
		if (client[i]->getCheckLog() == true) {
			client[i]->removeClient();  // client 1�� �����
			client[i] = nullptr;        // clientlist 1�� �����
		}
	}
}
