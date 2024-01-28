#include <iostream>
#include "speechManager.h"
using namespace std;

int main()
{
	SpeechManager sm;
	
	for (map<int,Speaker>::iterator it = sm.m_speaker.begin(); it != sm.m_speaker.end();it++)
	{
		cout << "选手编号：" << it->first << "姓名：" << it->second.m_name 
			<<"分数：" << it->second.m_score[0] << endl;
	}

	int choice = 0;//存储用户的选项

	while (true)
	{
		sm.ShowMenu();
		cout << "请输入您的选择: " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1://开始比赛
			break;
		case 2://查看往届记录
			break;
		case 3://清空比赛记录
			break;
		case 0://退出比赛程序
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
