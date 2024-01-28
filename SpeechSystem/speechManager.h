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

	//չʾ�˵�
	void ShowMenu();
	//�˳�ϵͳ
	void ExitSystem();
	//��ʼ������
	void InitSpeaker();
	//����12��ѡ��
	void CreateSpeaker();

	~SpeechManager();

	//��Ա����
	vector<int> v1;
	vector<int> v2;
	vector<int> victory;
	map<int, Speaker> m_speaker;

	int m_index;
};