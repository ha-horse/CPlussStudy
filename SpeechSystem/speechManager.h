#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "speaker.h"

class SpeechManager{
public:
	SpeechManager();

	//展示菜单
	void ShowMenu();
	//退出系统
	void ExitSystem();
	//初始化属性
	void InitSpeaker();
	//创建12名选手
	void CreateSpeaker();
	//抽签
	void SpeechDraw();
	//开始比赛
	void SpeechContest();
	//显示比赛结果
	void ShowScore();
	//保存分数
	void SaveScore();

	//演讲比赛开始控制function
	void StartSpeech();

	~SpeechManager();

	//成员属性
	vector<int> v1;//比赛选手 12人
	vector<int> v2;//第一轮晋级的选手 6人
	vector<int> victory;//胜利前三名的选手 3人
	map<int, Speaker> m_speaker;//存放编号 以及对应的具体选手

	int m_index;//存放比赛的轮数
};