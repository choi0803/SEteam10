#include "headfile.h"


// Function : startInterface
// Description : 회원가입을 출력하고 control class 호출
// Author : 박시영
void SignUpUI::startInterface(SignUp* signUp, int type) {
    fout << "1.1 회원가입" <<endl;
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
    SignUpUI* signUpUI = new SignUpUI();
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
        string businessNumber;
        fin>> companyName >> businessNumber>>id >> password;
        
        
        Client* newClient = new CompanyClient(companyName, businessNumber, id, password );
       
        clientlist->addClientList(newClient);
        fout <<"> " << companyName << " " << businessNumber << " " << id << " " << password << endl;
        
    }
    else if (type == 2) {
        string id, password, name;
        int citizenId;
        fin  >> name >> citizenId >> id >> password;
        Client* newClient = new GeneralClient(id, password, name, citizenId);
        clientlist->addClientList(newClient);
        fout << "> " << name << " " << citizenId << " " << id << " " << password << endl;
    }
}

// Function : startInterface
// Description : 회원 탈퇴 출력하고 control class 호출
// Author : 박시영
void SignOutUI::startInterface(SignOut* signOut) {
    fout << "1.2 회원탈퇴"<<endl;
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
    SignOutUI* signOutUI = new SignOutUI();
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
    fout << "2.1 로그인" <<endl;
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
    LogInUI* logInUI = new LogInUI();
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
            fout << "> " << clientlist->getMyInstance(i)->getId() <<" "<< clientlist->getMyInstance(i)->getPassword() << endl;
            clientlist->getMyInstance(i)->setCheckLogTrue();
            break;
        }
    }
}

// Function : startInterface
// Description : 로그아웃 출력 후 컨트롤 클래스 호출
// Author : 박시영
void LogOutUI::startInterface(LogOut* logOut) {
    fout << "2.2 로그아웃"<< endl;
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
    LogOutUI* logOutUI = new LogOutUI();
    logOutUI->startInterface(this);
}

// Function : logOut
// Description : list에서 로그인 상태인 것을 찾아 로그아웃 시킴
// Author : 박시영
void LogOut::logOut() {
    for (int i = 0; i < 1000; i++) {
        if (clientlist->getMyInstance(i)->getCheckLog() == true) {
            fout << "> " << clientlist->getMyInstance(i)->getId() << endl;
            clientlist->getMyInstance(i)->setCheckLogFalse();
            break;
        }
    }
}


// function = startInterface
// Description = 검색을 시작하는 문구를 띄우며 selectOptions 함수를 실행한다
// Author = 최상혁
void SearchUI::startInterface(Search* search) {
    fout << "4.1 채용 정보 검색" << endl;
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
            fout << "> " << recruitlist->getRecruitByIdx(i)->getCompanyName() << " "<< recruitlist->getRecruitByIdx(i)->getDepart() << " "<<recruitlist->getRecruitByIdx(i)->getPersonel() << " "<<recruitlist->getRecruitByIdx(i)->getDeadline() << endl;
            break;
        }
    }
}

// function = startInterface
// Description = 지원하기 문구를 출력하고 apply 함수를 매개변수를 넘겨주고 호출한다
// Author = 최상혁
void ApplyUI::startInterface(Apply* apply) {
    fout << "4.2 채용 지원" << endl;
    applys(apply);
}

// function = apply
// Description = 받은 매개변수 내의 applyAdd함수를 호출한다
// Author = 최상혁
void ApplyUI::applys(Apply* apply) {
    apply->applyAdd();
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


// function : startInterface
// Description : startInterface
// Author : 장민호
void EnrollRecruitUI::startInterface(EnrollRecruit* enrollRecruit)
{
    fout << "3.1 채용정보 등록" << endl;
    this->selectRecruitEnroll(enrollRecruit);
}


// function : selectRecruitEnroll
// Description : selectRecruitEnroll
// Author : 장민호
void EnrollRecruitUI::selectRecruitEnroll(EnrollRecruit* enrollRecruit)
{
    enrollRecruit->enrollRecruit();
}



// function : Constructor
// Description : Constructor
// Author : 장민호
EnrollRecruit::EnrollRecruit()
{
    EnrollRecruitUI* enrollRecruitUI = new EnrollRecruitUI();
    enrollRecruitUI->startInterface(this);
}


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
            fout << "> "<< depart << " " << person << " " << deadline << endl;
            break;
        }
    }
}


// function : startInterface
// Description : startInterface
// Author : 장민호
void ListUPUI::startInterface(ListUP* listUP)
{
    fout << "3.2 등록된 채용 정보 조회" << endl;
    this->showMyRecruitList(listUP);
}


// function : showMyRecruitList
// Description : showMyRecruitList
// Author : 장민호
void ListUPUI::showMyRecruitList(ListUP* listUP)
{
    listUP->showRecruits();
}


// function : Constructor
// Description : Constructor
// Author : 장민호
ListUP::ListUP()
{
    ListUPUI* listUpUI = new ListUPUI();
    listUpUI->startInterface(this);
}


// function : showRecruits
// Description : showRecruits
// Author : 장민호
void ListUP::showRecruits()
{
    for(int i=0; i<1000; i++){
        if (clientlist->getMyInstance(i)->getCheckLog() == true) {
            for (int j = 0; j < 50; j++) {
                if (clientlist->getMyInstance(i)->getCompanyName() == recruitlist->getRecruitByIdx(j)->getCompanyName()) {
                    string* info = recruitlist->getRecruitByIdx(j)->getInfo();
                    fout <<"> "<< info[2] << " " << info[3] << " " << info[4] << endl;
                    break;
                }
            }
            break;
        }
    }
}



// function : showApplyList
// Description : showApplyList
// Author : 장민호
void ShowApplyInfoUI::showApplyList(ShowApplyInfo* showApplyInfo)
{
    showApplyInfo->applyList();
}


// function : startInterface
// Description : startInterface
// Author : 장민호
void ShowApplyInfoUI::startInterface(ShowApplyInfo* showApplyInfo)
{
    fout << "4.3 지원정보 조회" << endl;
    this->showApplyList(showApplyInfo);
}


// function : Constructor
// Description : Constructor
// Author : 장민호
ShowApplyInfo::ShowApplyInfo()
{

    ShowApplyInfoUI* showApplyInfoUI=new ShowApplyInfoUI();
    showApplyInfoUI->startInterface(this);
}


// function : applyList
// Description : applyList
// Author : 장민호
void ShowApplyInfo::applyList()
{
    vector<string> vec;
    for (int i = 0; i < 1000; i++)
    {
        if (clientlist->getMyInstance(i)->getCheckLog() == true) {
            RecruitList* my_apply_list = clientlist->getMyInstance(i)->getMyApplyList();
            for (int j = 0;j < my_apply_list->getIndex();j++) {
                vec.push_back(my_apply_list->getRecruitByIdx(j)->getCompanyName());
            }

            sort(vec.begin(), vec.end());

            for (int j = 0;j < vec.size();j++) {
                for (int k = 0;k < 50;k++) {
                    if (recruitlist->getRecruitByIdx(k)->getCompanyName() == vec[j]) {
                        string* info = recruitlist->getRecruitByIdx(k)->getInfo();
                        fout <<"> "<< info[0] << " " << info[1] << " " << info[2] << " " << info[3] << " " << info[4] << endl;
                        break;
                    }
                }
            }
            break;
        }
    }
}


// -------------------entity---------------

// Function : Client
// Description : 생성자
// Author : 장민호
Client::Client(string id, string password) {
    this->id = id;
    this->password = password;
}

// Function : removeClient
// Description : id출력하고 생성자 삭제
// Author : 장민호
void Client::removeClient() {
    fout <<"> "<< id << endl;
    delete this;
}

// Function : getId
// Description : return id 
// Author : 장민호
string Client::getId() {
    return this->id;
}

// Function : getPassword
// Description : return password 
// Author : 장민호
string Client::getPassword() {
    return this->password;
}

// Function : setCheckLogTrue
// Description : 로그인상태 true 
// Author : 장민호
void Client::setCheckLogTrue() {
    this->checkLog = true;
}

// Function : setCheckLogFalse
// Description : 로그인상태 false
// Author : 장민호
void Client::setCheckLogFalse() {
    this->checkLog = false;
}

// Function : getCheckLog
// Description : return 로그인상태
// Author : 장민호
bool Client::getCheckLog() {
    return this->checkLog;
}

// Function : CompanyClient
// Description : 생성자 
// Author : 박시영
CompanyClient::CompanyClient(string companyName, string businessNumber, string id, string password) : Client(id, password) {
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
// Description : Recruit 생성, recruit리스트에 추가
// Author : 박시영
void CompanyClient::addRecruit()
{
    string depart, deadline;
    int personel;
    fin >> depart >> personel >> deadline;
    Recruit* recruit = new Recruit(depart, personel, deadline, this->getCompanyName(), this->getBusinessNum());
    recruitlist->addnewRecruit(recruit);
}

// Function : addApplyList
// Description : virtual 위한 함수
// Author : 박시영
void CompanyClient::addApplyList(string comNumber)
{
    return;
}
// Function : getMyApplyList
// Description : RecruitList 객체를 반환함
// Author : 박시영
RecruitList* CompanyClient::getMyApplyList()
{
    return new RecruitList();
}

// Function : GeneralClient
// Description : 생성자
// Author : 최상혁
GeneralClient::GeneralClient(string id, string password, string name, int citizenId) : Client(id, password) {
    this->name = name;
    this->citizenId = citizenId;
    this->myApplyList = new RecruitList;
}

// Function : getCompanyName
// Description : virtual을 위한 함수
// Author : 최상혁
string GeneralClient::getCompanyName()
{
    return "";
}

// Function : getBusinessNum
// Description : virtual을 위한 함수
// Author : 최상혁
string GeneralClient::getBusinessNum()
{
    return "";
}

// Function : addApplyList
// Description : 지원 회사 정보 출력 후, 본인 지원리스트 추가
// Author : 최상혁
void GeneralClient::addApplyList(string comNumber)
{
    for (int i = 0; i < 50; i++) {
        if (recruitlist->getRecruitByIdx(i)->getBusinessNumber() == comNumber) {
            fout <<"> "<< recruitlist->getRecruitByIdx(i)->getCompanyName() << " " << recruitlist->getRecruitByIdx(i)->getBusinessNumber() << " " << recruitlist->getRecruitByIdx(i)->getDepart() << endl;
            this->myApplyList->addnewRecruit(recruitlist->getRecruitByIdx(i));
            break;
        }
    }
}

// Function : getMyApplyList
// Description : return myApplyList
// Author : 박시영
RecruitList* GeneralClient::getMyApplyList()
{
    return myApplyList;
}

// Function : getMyInstance
// Description : clinet[i] 반환
// Author : 박시영
Client* ClientList::getMyInstance(int i) {
    return client[i];
}

// Function : addClientList
// Description : clientList의 client에 newclient 추가
// Author : 박시영
void ClientList::addClientList(Client* newClient) {

    client[index++] = newClient;
}


// Function : removeClientList
// Description : list에서 로그인 중인 클라이언트 목록 삭제 
// Author : 박시영
void ClientList::removeClientList() {
    for (int i = 0; i < 1000; i++) {
        if (client[i]->getCheckLog() == true) {
            client[i]->removeClient();  // client 1        
            break;             
        }
    }
}

// Function : Recruit
// Description : 생성자 
// Author : 장민호
Recruit::Recruit(string dep, int per, string dead, string name, string num)
{
    depart = dep;
    personel = per;
    deadline = dead;
    company_name = name;
    business_num = num;
}

// Function : getPersonel
// Description : personel 변수 반환
// Author : 장민호
int Recruit::getPersonel() {
    return personel;
}

// Function : getDeadline
// Description : deadline 변수 반환
// Author : 장민호
string Recruit::getDeadline() {
    return deadline;
}

// Function : getCompanyName
// Description : company_name 변수 반환
// Author : 장민호
string Recruit::getCompanyName()
{
    return company_name;
}

// Function : getBusinessNumber
// Description : business_num 변수 반환
// Author : 장민호
string Recruit::getBusinessNumber()
{
    return business_num;
}

// Function : getDepart
// Description : depart 변수 반환
// Author : 장민호
string Recruit::getDepart()
{
    return depart;
}

// Function : getInfo
// Description : 각 멤버변수를 반환함
// Author : 장민호
string* Recruit::getInfo()
{
    string* info = new string[5];
    info[0] = this->company_name;
    info[1] = this->business_num;
    info[2] = this->depart;
    info[3] = to_string(this->personel);
    info[4] = this->deadline;
    return info;
}

// Function : getfourInfo
// Description : 멤버변수 중, 4개를 array로 반환함
// Author : 장민호
array<string, 4>* Recruit::getfourInfo() {
    array<string, 4>* info = \
        new array<string, 4>{this->company_name, this->depart, to_string(this->personel), this->deadline};
    return info;
}


// Function : addnewRecruit
// Description : RecruitList의 recruit변수에 새 객체를 추가함
// Author : 최상혁
void RecruitList::addnewRecruit(Recruit* newrecruit)
{
    recruit[index++] = newrecruit;
    // clientlist->addClientList(newClient);
}

// Function : getRecruitByIdx
// Description : RecruitList의 recruit 배열 중, 매개변수에 해당하는 값을 반환함
// Author : 최상혁
Recruit* RecruitList::getRecruitByIdx(int i)
{
    return this->recruit[i];
}

// Function : getIndex
// Description : RecruitList의 index 값을 반환
// Author : 최상혁
int RecruitList::getIndex() {
    return index;
}