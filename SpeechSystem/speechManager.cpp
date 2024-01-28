#include "speechManager.h"

SpeechManager::SpeechManager()
{
	this->InitSpeaker();
	this->CreateSpeaker();
}

void SpeechManager::ShowMenu()
{
	cout << "******************************************" << endl;
	cout << "*************欢迎参加演讲比赛*************" << endl;
	cout << "**************1.开始演讲比赛**************" << endl;
	cout << "**************2.查看往届记录**************" << endl;
	cout << "**************3.清空比赛记录**************" << endl;
	cout << "**************0.退出比赛程序**************" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}

void SpeechManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

SpeechManager::~SpeechManager()
{}

void SpeechManager::InitSpeaker()
{
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->m_speaker.clear();

	this->m_index = 1;
}

void SpeechManager::CreateSpeaker()
{
	string name_seed = "ABCDEFGHIJKL";
	for (int i = 0; i < name_seed.size(); i++)
	{
		string name = "选手"; 
		name += name_seed[i];

		Speaker sp;
		sp.m_name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}

		this->v1.push_back(i + 10001);
		this->m_speaker.insert(make_pair(i + 10001, sp));
	}
}
