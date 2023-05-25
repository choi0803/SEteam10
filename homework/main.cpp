#define _CRT_SECURE_NO_WARNINGS
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
#include "headfile.h"

FILE* in_fp; 
FILE* out_fp;
void doTask();
void program_exit();


ifstream fin;
ofstream fout;
ClientList* clientlist = new ClientList;
RecruitList* recruitlist = new RecruitList;

// function : main함수
// Description : 메인 함수로 프로그램을 실행한다
// Author : 박시영,장민호,최상혁
int main() {
    
    fin.open(INPUT_FILE_NAME);
    fout.open(OUTPUT_FILE_NAME);
    
	doTask();
    fin.close();
    fout.close();
}

// function : doTask
// Description : 실행 함수로 프로그램을 실행한다
// Author : 박시영,장민호,최상혁
void doTask() {
   
	int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;
    
    while (!is_program_exit)
    {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        
        fin >> menu_level_1;
        fin >> menu_level_2;
        
        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
                case 1:   // "1.1. 회원가입“ 메뉴 부분
                {
                    SignUp* signup = new SignUp();
                    break;
                }
                case 2:
                {  
                    SignOut* signout = new SignOut();
                    break;
                }
            }
            break;
        }
        case 2:
        {
            switch (menu_level_2)
            {
                case 1:   // "2.1. 로그인“ 메뉴 부분
                {
                    LogIn* login = new LogIn();
                    break;
                }
                case 2:
                {
                   
                    LogOut* logout = new LogOut();
                    break;
                }
            }
            break;
         }
        case 3:
        {
            switch (menu_level_2)
            {
                case 1:   // "3.1. 채용 정보 등록“ 메뉴 부분
                {
                    EnrollRecruit* enrollrecruit = new EnrollRecruit();
                    break;
                }
                case 2:
                {
                    ListUP* listup = new ListUP();
                    break;
                }
            }
            break;
        }
        case 4:
        {
            switch (menu_level_2)
            {
                case 1:   // "4.1. 채용 정보 검색“ 메뉴 부분
                {
                    Search* search = new Search();
                    break;
                }
                case 2:
                {
                    Apply* apply = new Apply();
                    break;
                }
                case 3:
                {
                    ShowApplyInfo* showapplyinfo = new ShowApplyInfo();
                    break;
                }
            }
            break;
        }
        case 6:
            {
                switch (menu_level_2)
                {
                    case 1:   // "6.1. 종료“ 메뉴 부분
                    {
                         program_exit();
                         is_program_exit = 1;
                         break;
                    }
                }

            }
            break;
           
        }
        fout << endl;
    }

}

// function : program_exit
// Description : 종료 함수로 프로그램을 종료한다
// Author : 박시영,장민호,최상혁
void program_exit() {
	fout << "6.1 종료";
}
