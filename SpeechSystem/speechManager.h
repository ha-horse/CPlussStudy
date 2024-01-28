#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "speaker.h"


class SpeechManager
{
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

	~SpeechManager();

	//成员属性
	vector<int> v1;
	vector<int> v2;
	vector<int> victory;
	map<int, Speaker> m_speaker;

	int m_index;
};