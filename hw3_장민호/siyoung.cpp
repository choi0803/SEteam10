#include "headfile.h"


// Function : startInterface
// Description : ȸ�������� ����ϰ� control class ȣ��
// Author : �ڽÿ�
void SignUpUI::startInterface(SignUp* signUp, int type) {
    fout << "1. 1 ȸ������ \n";
    //fout.flush();
    createClient(signUp, type);
}

// Function : createClient
// Description : signUp�� addClientȣ��
// Author : �ڽÿ�
void SignUpUI::createClient(SignUp* signUp, int type)
{
    signUp->addClient(type);
}

// Function : SignUp
// Description : ������
// Author : �ڽÿ�
SignUp::SignUp()
{
    SignUpUI* signUpUI = new SignUpUI();
    int type;
    fin >> type;
    signUpUI->startInterface(this, type);
}

// Function : addClient
// Description : type������ ȸ�� ������ ����
// Author : �ڽÿ�
void SignUp::addClient(int type)
{
    if (type == 1) {
        string id, password, companyName;
        string businessNumber;
        fin >> companyName >> businessNumber >> id >> password;
        Client* newClient = new CompanyClient(id, password, companyName, businessNumber);
        clientlist->addClientList(newClient);
        fout<< type << companyName << businessNumber << id << password << endl;
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
// Description : ȸ�� Ż�� ����ϰ� control class ȣ��
// Author : �ڽÿ�
void SignOutUI::startInterface(SignOut* signOut) {
    fout << "1. 2 ȸ��Ż�� \n";
    deleteClient(signOut);
}
// Function : deleteClient
// Description : signOut�� removeClientȣ��
// Author : �ڽÿ�
void SignOutUI::deleteClient(SignOut* signOut) {
    signOut->removeClient();
}

// Function : SignOut
// Description : ������
// Author : �ڽÿ�
SignOut::SignOut() {
    SignOutUI* signOutUI = new SignOutUI();
    signOutUI->startInterface(this);
}

// Function : removeClient
// Description : list���� Ŭ���̾�Ʈ ��� ����
// Author : �ڽÿ�
void SignOut::removeClient() {
    clientlist->removeClientList();
}

// Function : startInterface
// Description : �α��� ����ϰ� ��Ʈ�� Ŭ���� ȣ��
// Author : �ڽÿ�
void LogInUI::startInterface(LogIn* logIn) {
    fout << "2. 1 �α���\n";
    requestLogIn(logIn);
}

// Function : requestLogIn
// Description : ��Ʈ�� Ŭ������ loginȣ��
// Author : �ڽÿ�
void LogInUI::requestLogIn(LogIn* logIn) {
    logIn->logIn();
}

// Function : LogIn
// Description : ������
// Author : �ڽÿ�
LogIn::LogIn() {
    LogInUI* logInUI = new LogInUI();
    logInUI->startInterface(this);
}

// Function : logIn
// Description : list���� Id, pw ���ؼ� ������ �α��λ��·� ����
// Author : �ڽÿ�
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
// Description : �α׾ƿ� ��� �� ��Ʈ�� Ŭ���� ȣ��
// Author : �ڽÿ�
void LogOutUI::startInterface(LogOut* logOut) {
    fout << "2. 2 �α׾ƿ�\n";
    requestLogOut(logOut);
}
// Function : reqeustLogOut
// Description : ��Ʈ�� Ŭ������ logOutȣ��
// Author : �ڽÿ�
void LogOutUI::requestLogOut(LogOut* logOut) {
    logOut->logOut();
}

// Function : LogOut
// Description : ������
// Author : �ڽÿ�
LogOut::LogOut() {
    LogOutUI* logOutUI = new LogOutUI();
    logOutUI->startInterface(this);
}

// Function : logOut
// Description : list���� �α��� ������ ���� ã�� �α׾ƿ� ��Ŵ
// Author : �ڽÿ�
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
// Description : ������
// Author : �ڽÿ�
Client::Client(string id, string password) {
    this->id = id;
    this->password = password;
}

// Function : removeClient
// Description : id����ϰ� ������ ����
// Author : �ڽÿ�
void Client::removeClient() {
    fout << id << "\n";
    delete this;
}

// Function : getId
// Description : return id 
// Author : �ڽÿ�
string Client::getId() {
    return this->id;
}

// Function : getPassword
// Description : return password 
// Author : �ڽÿ�
string Client::getPassword() {
    return this->password;
}

// Function : setCheckLogTrue
// Description : �α��λ��� true 
// Author : �ڽÿ�
void Client::setCheckLogTrue() {
    this->checkLog = true;
}

// Function : setCheckLogFalse
// Description : �α��λ��� false
// Author : �ڽÿ�
void Client::setCheckLogFalse() {
    this->checkLog = false;
}

// Function : getCheckLog
// Description : return �α��λ���
// Author : �ڽÿ�
bool Client::getCheckLog() {
    return this->checkLog;
}

// Function : CompanyClient
// Description : ������ 
// Author : �ڽÿ�
CompanyClient::CompanyClient(string id, string password, string companyName, string businessNumber) : Client(id, password) {
    this->companyName = companyName;
    this->businessNumber = businessNumber;
}

// Function : getCompanyName
// Description : return companyName 
// Author : �ڽÿ�   
string CompanyClient::getCompanyName()
{
    return this->companyName;
}

// Function : getBusinessNum
// Description : return businessNumber 
// Author : �ڽÿ�
string CompanyClient::getBusinessNum()
{
    return this->businessNumber;
}

// Function : addRecruit
// Description : Recruit ����, ����Ʈ����Ʈ�� �߰�
// Author : �ڽÿ�
void CompanyClient::addRecruit()
{
    string depart, deadline;
    int personel;
    fin >> depart >> personel >> deadline;
    Recruit* recruit = new Recruit(depart, personel, deadline, this->getCompanyName(), this->getBusinessNum());
    recruitlist->addnewRecruit(recruit);
}

void CompanyClient::addApplyList(string comNumber)
{
    return;
}

RecruitList* CompanyClient::getMyApplyList()
{
    return new RecruitList();
}

// Function : GeneralClient
// Description : ������
// Author : �ڽÿ�
GeneralClient::GeneralClient(string id, string password, string name, int citizenId) : Client(id, password) {
    this->name = name;
    this->citizenId = citizenId;
    this->myApplyList = nullptr;
}

string GeneralClient::getCompanyName()
{
    return "";
}

string GeneralClient::getBusinessNum()
{
    return "";
}

// Function : addApplyList
// Description : ���� ȸ�� ���� ��� ��, ���� ����������Ʈ ���� 
// Author : �ڽÿ�
void GeneralClient::addApplyList(string comNumber)
{
    for (int i = 0; i < 50; i++) {
        if (recruitlist->getRecruitByIdx(i)->getBusinessNumber() == comNumber) {
            fout << recruitlist->getRecruitByIdx(i)->getCompanyName() << ""\
                << recruitlist->getRecruitByIdx(i)->getBusinessNumber() << ""\
                << recruitlist->getRecruitByIdx(i)->getDepart();
            this->myApplyList->addnewRecruit(recruitlist->getRecruitByIdx(i));
            break;
        }
    }
}

RecruitList* GeneralClient::getMyApplyList()
{
    return myApplyList;
}
// Function : getMyInstance
// Description : return clinet[i] 
// Author : �ڽÿ�
Client* ClientList::getMyInstance(int i) {
    return this->client[i];
}

// Function : addClientList
// Description : clientList�� ���ο� client �߰�
// Author : �ڽÿ�
void ClientList::addClientList(Client* newClient) {
    this->client[index++] = newClient;
}

// Function : removeClientList
// Description : list���� �α��� ���� Ŭ���̾�Ʈ ��� ���� 
// Author : �ڽÿ�
void ClientList::removeClientList() {
    for (int i = 0; i < 1000; i++) {
        if (client[i] == nullptr) continue;
        if (client[i]->getCheckLog() == true) {
            client[i]->removeClient();  // client 1        
            client[i] = nullptr;        // clientlist 1        
        }
    }
}

Recruit::Recruit(string dep, int per, string dead, string name, string num)
{
    depart = dep;
    personel = per;
    deadline = dead;
    company_name = name;
    business_num = num;
}

int Recruit::getPersonel() {
    return personel;
}
string Recruit::getDeadline() {
    return deadline;
}
string Recruit::getCompanyName()
{
    return company_name;
}

string Recruit::getBusinessNumber()
{
    return business_num;
}

string Recruit::getDepart()
{
    return depart;
}
string* Recruit::getInfo()
{
    string* info = new string[5];
    info[0] = this->company_name;
    info[1] = this->business_num;
    info[2] = this->depart;
    info[3] = this->personel;
    info[4] = this->deadline;
    return info;
}
array<string, 4>* Recruit::getfourInfo() {
    array<string, 4>* info = \
        new array<string, 4>{this->company_name, this->depart, to_string(this->personel), this->deadline};
    return info;
}



void RecruitList::addnewRecruit(Recruit* newrecruit)
{
    this->recruit[index++] = newrecruit;
}
Recruit* RecruitList::getRecruitByIdx(int i)
{
    return this->recruit[i];
}
/*
void RecruitList::getMyApplyList()
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
*/
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
