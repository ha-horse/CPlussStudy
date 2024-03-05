#include "speechManager.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>

SpeechManager::SpeechManager(){
	this->InitSpeaker();
	this->CreateSpeaker();//创建12位比赛选手
}

void SpeechManager::ShowMenu(){
	cout << "******************************************" << endl;
	cout << "*************欢迎参加演讲比赛*************" << endl;
	cout << "**************1.开始演讲比赛**************" << endl;
	cout << "**************2.查看往届记录**************" << endl;
	cout << "**************3.清空比赛记录**************" << endl;
	cout << "**************0.退出比赛程序**************" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}

void SpeechManager::ExitSystem(){
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

SpeechManager::~SpeechManager(){}

void SpeechManager::InitSpeaker(){
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->m_speaker.clear();

	this->m_index = 1;
}

void SpeechManager::CreateSpeaker(){
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

void SpeechManager::SpeechDraw(){
	cout << "第 " << this->m_index << " 轮选手正在抽签" << endl;
	cout << "-------------------------------------" << endl;
	cout << "抽签后的演讲顺序如下：" << endl;
	if (this->m_index == 1){
		random_shuffle(v1.begin(), v1.end());
		for ( vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	if (this->m_index == 2){
		random_shuffle(v2.begin(), v2.end());
		for ( vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "--------------------------------------" << endl;
	system("pause");
	cout << endl;
}

void SpeechManager::SpeechContest(){
	cout << "----------------------第" << this->m_index << "轮正式开始比赛开始：----------------" << endl;
	//multimap 是一个关联容器，它可以存储键值对，其中每个键可以与多个值关联。
	//但主要区别在于 map 中一个键只能关联一个值，不同的选手可能出现同分的情况，故这里用的multimap
	multimap<double, int, greater<double>> groupScore; //临时容器保存key分数 value选手编号
	int num = 0;//记录人员数，6个为一组

	vector <int> v_Src; //比赛的人员容器

	if (this->m_index == 1) v_Src = v1;
	if (this->m_index == 2) v_Src = v2;

	for(vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++){
		num++;
		//10个评委打分
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.0f;
			// cout << score << " ";
			d.push_back(score);
		}
		// cout << endl;

		//排序
		sort(d.begin(), d.end(), greater<double>());
		//去掉最高分
		d.pop_front();
		// 去掉最低分
		d.pop_back();
		//获取总分
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		// 获取平均分
		double avg = sum / (double)d.size();

		//每个人的平均分
		this->m_speaker[*it].m_score[this->m_index - 1] = avg;

		//6个人一组，用临时容器保存
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << " 姓名：" << this->m_speaker[it->second].m_name 
				<< "成绩：" << this->m_speaker[it->second].m_score[this->m_index - 1] << endl;
			}
			
			int count = 0;
			//取前三名
			for(multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++){
				if (this->m_index == 1) v2.push_back((*it).second);
				if (this->m_index == 2) victory.push_back((*it).second);
				
			}
			groupScore.clear();
			cout << endl;
		}
	}
	cout << "--------------------第" << this->m_index << "轮比赛完毕！--------------" << endl;
}

void SpeechManager::ShowScore(){
	cout << "--------------------第" << this->m_index << "轮晋级选手信息如下：--------------" << endl;
	for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++){
		cout << "编号：" << *it << "选手：" << this->m_speaker[*it].m_name 
		<< "分数：" << this->m_speaker[*it].m_score[this->m_index - 1] << endl;
	}
}

void SpeechManager::StartSpeech(){
	//第一轮开始比赛
	// 抽签
	this->SpeechDraw();
	// 比赛
	this->SpeechContest();
	// 显示晋级结果
	this->ShowScore();

	// 第二轮比赛
	// 抽签
	this->SpeechDraw();
	// 比赛
	this->SpeechContest();
	// 显示最终结果
	this->ShowScore();
	// 保存分数
}
