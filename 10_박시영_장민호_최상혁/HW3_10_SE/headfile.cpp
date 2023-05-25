#include "headfile.h"


// Function : startInterface
// Description : ȸ�������� ����ϰ� control class ȣ��
// Author : �ڽÿ�
void SignUpUI::startInterface(SignUp* signUp, int type) {
    fout << "1.1 ȸ������" <<endl;
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
// Description : ȸ�� Ż�� ����ϰ� control class ȣ��
// Author : �ڽÿ�
void SignOutUI::startInterface(SignOut* signOut) {
    fout << "1.2 ȸ��Ż��"<<endl;
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
    fout << "2.1 �α���" <<endl;
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
            fout << "> " << clientlist->getMyInstance(i)->getId() <<" "<< clientlist->getMyInstance(i)->getPassword() << endl;
            clientlist->getMyInstance(i)->setCheckLogTrue();
            break;
        }
    }
}

// Function : startInterface
// Description : �α׾ƿ� ��� �� ��Ʈ�� Ŭ���� ȣ��
// Author : �ڽÿ�
void LogOutUI::startInterface(LogOut* logOut) {
    fout << "2.2 �α׾ƿ�"<< endl;
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
            fout << "> " << clientlist->getMyInstance(i)->getId() << endl;
            clientlist->getMyInstance(i)->setCheckLogFalse();
            break;
        }
    }
}


// function = startInterface
// Description = �˻��� �����ϴ� ������ ���� selectOptions �Լ��� �����Ѵ�
// Author = �ֻ���
void SearchUI::startInterface(Search* search) {
    fout << "4.1 ä�� ���� �˻�" << endl;
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
            fout << "> " << recruitlist->getRecruitByIdx(i)->getCompanyName() << " "<< recruitlist->getRecruitByIdx(i)->getDepart() << " "<<recruitlist->getRecruitByIdx(i)->getPersonel() << " "<<recruitlist->getRecruitByIdx(i)->getDeadline() << endl;
            break;
        }
    }
}

// function = startInterface
// Description = �����ϱ� ������ ����ϰ� apply �Լ��� �Ű������� �Ѱ��ְ� ȣ���Ѵ�
// Author = �ֻ���
void ApplyUI::startInterface(Apply* apply) {
    fout << "4.2 ä�� ����" << endl;
    applys(apply);
}

// function = apply
// Description = ���� �Ű����� ���� applyAdd�Լ��� ȣ���Ѵ�
// Author = �ֻ���
void ApplyUI::applys(Apply* apply) {
    apply->applyAdd();
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


// function : startInterface
// Description : startInterface
// Author : ���ȣ
void EnrollRecruitUI::startInterface(EnrollRecruit* enrollRecruit)
{
    fout << "3.1 ä������ ���" << endl;
    this->selectRecruitEnroll(enrollRecruit);
}


// function : selectRecruitEnroll
// Description : selectRecruitEnroll
// Author : ���ȣ
void EnrollRecruitUI::selectRecruitEnroll(EnrollRecruit* enrollRecruit)
{
    enrollRecruit->enrollRecruit();
}



// function : Constructor
// Description : Constructor
// Author : ���ȣ
EnrollRecruit::EnrollRecruit()
{
    EnrollRecruitUI* enrollRecruitUI = new EnrollRecruitUI();
    enrollRecruitUI->startInterface(this);
}


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
            fout << "> "<< depart << " " << person << " " << deadline << endl;
            break;
        }
    }
}


// function : startInterface
// Description : startInterface
// Author : ���ȣ
void ListUPUI::startInterface(ListUP* listUP)
{
    fout << "3.2 ��ϵ� ä�� ���� ��ȸ" << endl;
    this->showMyRecruitList(listUP);
}


// function : showMyRecruitList
// Description : showMyRecruitList
// Author : ���ȣ
void ListUPUI::showMyRecruitList(ListUP* listUP)
{
    listUP->showRecruits();
}


// function : Constructor
// Description : Constructor
// Author : ���ȣ
ListUP::ListUP()
{
    ListUPUI* listUpUI = new ListUPUI();
    listUpUI->startInterface(this);
}


// function : showRecruits
// Description : showRecruits
// Author : ���ȣ
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
// Author : ���ȣ
void ShowApplyInfoUI::showApplyList(ShowApplyInfo* showApplyInfo)
{
    showApplyInfo->applyList();
}


// function : startInterface
// Description : startInterface
// Author : ���ȣ
void ShowApplyInfoUI::startInterface(ShowApplyInfo* showApplyInfo)
{
    fout << "4.3 �������� ��ȸ" << endl;
    this->showApplyList(showApplyInfo);
}


// function : Constructor
// Description : Constructor
// Author : ���ȣ
ShowApplyInfo::ShowApplyInfo()
{

    ShowApplyInfoUI* showApplyInfoUI=new ShowApplyInfoUI();
    showApplyInfoUI->startInterface(this);
}


// function : applyList
// Description : applyList
// Author : ���ȣ
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
// Description : ������
// Author : ���ȣ
Client::Client(string id, string password) {
    this->id = id;
    this->password = password;
}

// Function : removeClient
// Description : id����ϰ� ������ ����
// Author : ���ȣ
void Client::removeClient() {
    fout <<"> "<< id << endl;
    delete this;
}

// Function : getId
// Description : return id 
// Author : ���ȣ
string Client::getId() {
    return this->id;
}

// Function : getPassword
// Description : return password 
// Author : ���ȣ
string Client::getPassword() {
    return this->password;
}

// Function : setCheckLogTrue
// Description : �α��λ��� true 
// Author : ���ȣ
void Client::setCheckLogTrue() {
    this->checkLog = true;
}

// Function : setCheckLogFalse
// Description : �α��λ��� false
// Author : ���ȣ
void Client::setCheckLogFalse() {
    this->checkLog = false;
}

// Function : getCheckLog
// Description : return �α��λ���
// Author : ���ȣ
bool Client::getCheckLog() {
    return this->checkLog;
}

// Function : CompanyClient
// Description : ������ 
// Author : �ڽÿ�
CompanyClient::CompanyClient(string companyName, string businessNumber, string id, string password) : Client(id, password) {
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
// Description : Recruit ����, recruit����Ʈ�� �߰�
// Author : �ڽÿ�
void CompanyClient::addRecruit()
{
    string depart, deadline;
    int personel;
    fin >> depart >> personel >> deadline;
    Recruit* recruit = new Recruit(depart, personel, deadline, this->getCompanyName(), this->getBusinessNum());
    recruitlist->addnewRecruit(recruit);
}

// Function : addApplyList
// Description : virtual ���� �Լ�
// Author : �ڽÿ�
void CompanyClient::addApplyList(string comNumber)
{
    return;
}
// Function : getMyApplyList
// Description : RecruitList ��ü�� ��ȯ��
// Author : �ڽÿ�
RecruitList* CompanyClient::getMyApplyList()
{
    return new RecruitList();
}

// Function : GeneralClient
// Description : ������
// Author : �ֻ���
GeneralClient::GeneralClient(string id, string password, string name, int citizenId) : Client(id, password) {
    this->name = name;
    this->citizenId = citizenId;
    this->myApplyList = new RecruitList;
}

// Function : getCompanyName
// Description : virtual�� ���� �Լ�
// Author : �ֻ���
string GeneralClient::getCompanyName()
{
    return "";
}

// Function : getBusinessNum
// Description : virtual�� ���� �Լ�
// Author : �ֻ���
string GeneralClient::getBusinessNum()
{
    return "";
}

// Function : addApplyList
// Description : ���� ȸ�� ���� ��� ��, ���� ��������Ʈ �߰�
// Author : �ֻ���
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
// Author : �ڽÿ�
RecruitList* GeneralClient::getMyApplyList()
{
    return myApplyList;
}

// Function : getMyInstance
// Description : clinet[i] ��ȯ
// Author : �ڽÿ�
Client* ClientList::getMyInstance(int i) {
    return client[i];
}

// Function : addClientList
// Description : clientList�� client�� newclient �߰�
// Author : �ڽÿ�
void ClientList::addClientList(Client* newClient) {

    client[index++] = newClient;
}


// Function : removeClientList
// Description : list���� �α��� ���� Ŭ���̾�Ʈ ��� ���� 
// Author : �ڽÿ�
void ClientList::removeClientList() {
    for (int i = 0; i < 1000; i++) {
        if (client[i]->getCheckLog() == true) {
            client[i]->removeClient();  // client 1        
            break;             
        }
    }
}

// Function : Recruit
// Description : ������ 
// Author : ���ȣ
Recruit::Recruit(string dep, int per, string dead, string name, string num)
{
    depart = dep;
    personel = per;
    deadline = dead;
    company_name = name;
    business_num = num;
}

// Function : getPersonel
// Description : personel ���� ��ȯ
// Author : ���ȣ
int Recruit::getPersonel() {
    return personel;
}

// Function : getDeadline
// Description : deadline ���� ��ȯ
// Author : ���ȣ
string Recruit::getDeadline() {
    return deadline;
}

// Function : getCompanyName
// Description : company_name ���� ��ȯ
// Author : ���ȣ
string Recruit::getCompanyName()
{
    return company_name;
}

// Function : getBusinessNumber
// Description : business_num ���� ��ȯ
// Author : ���ȣ
string Recruit::getBusinessNumber()
{
    return business_num;
}

// Function : getDepart
// Description : depart ���� ��ȯ
// Author : ���ȣ
string Recruit::getDepart()
{
    return depart;
}

// Function : getInfo
// Description : �� ��������� ��ȯ��
// Author : ���ȣ
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
// Description : ������� ��, 4���� array�� ��ȯ��
// Author : ���ȣ
array<string, 4>* Recruit::getfourInfo() {
    array<string, 4>* info = \
        new array<string, 4>{this->company_name, this->depart, to_string(this->personel), this->deadline};
    return info;
}


// Function : addnewRecruit
// Description : RecruitList�� recruit������ �� ��ü�� �߰���
// Author : �ֻ���
void RecruitList::addnewRecruit(Recruit* newrecruit)
{
    recruit[index++] = newrecruit;
    // clientlist->addClientList(newClient);
}

// Function : getRecruitByIdx
// Description : RecruitList�� recruit �迭 ��, �Ű������� �ش��ϴ� ���� ��ȯ��
// Author : �ֻ���
Recruit* RecruitList::getRecruitByIdx(int i)
{
    return this->recruit[i];
}

// Function : getIndex
// Description : RecruitList�� index ���� ��ȯ
// Author : �ֻ���
int RecruitList::getIndex() {
    return index;
}