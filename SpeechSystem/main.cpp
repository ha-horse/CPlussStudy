#include <iostream>
#include "speechManager.h"
using namespace std;

int main()
{
	SpeechManager sm;
	
	for (map<int,Speaker>::iterator it = sm.m_speaker.begin(); it != sm.m_speaker.end();it++)
	{
		cout << "ѡ�ֱ�ţ�" << it->first << "������" << it->second.m_name 
			<<"������" << it->second.m_score[0] << endl;
	}

	int choice = 0;//�洢�û���ѡ��

	while (true)
	{
		sm.ShowMenu();
		cout << "����������ѡ��: " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1://��ʼ����
			break;
		case 2://�鿴�����¼
			break;
		case 3://��ձ�����¼
			break;
		case 0://�˳���������
			sm.ExitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
