
#include <stdio.h>
#include <string.h>
#include "headfile.h"
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
FILE* in_fp, * out_fp;
void doTask();
void program_exit();

int main() {
    FILE* in_fp = fopen(INPUT_FILE_NAME, "r+");
    FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");
	doTask();
}

void doTask() {
	int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;
    while (!is_program_exit)
    {
        // �Է����Ͽ��� �޴� ���� 2���� �б�
        fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);


        // �޴� ���� �� �ش� ���� ����
        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
                case 1:   // "1.1. ȸ�����ԡ� �޴� �κ�
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
        }
        case 2:
        {
            switch (menu_level_2)
            {
                case 1:   // "2.1. �α��Ρ� �޴� �κ�
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
         }
        case 3:
        {
            switch (menu_level_2)
            {
                case 1:   // "3.1. ä�� ���� ��ϡ� �޴� �κ�
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
        }
        case 4:
        {
            switch (menu_level_2)
            {
                case 1:   // "4.1. ä�� ���� �˻��� �޴� �κ�
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
        }
        case 6:
            {
                switch (menu_level_2)
                {
                    case 1:   // "6.1. ���ᡰ �޴� �κ�
                    {
                         program_exit();
                         is_program_exit = 1;
                         break;
                    }
                }

            }

           
        }

    }

}

void program_exit() {
	fout << "6.1 ����";
}
