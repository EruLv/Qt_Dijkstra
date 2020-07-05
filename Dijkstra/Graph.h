#pragma once
#include"qstring.h"
//��¼��㵽ÿ����������·������Ϣ
struct Dis {
	int value;
	bool visit;
	QString path;
	Dis() {
		visit = false;
		value = 0;
		path = "";
	}
};

class Graph {
public:
	int vexnum;	//ͼ�������
	int edge;	//ͼ�ߵĸ���
	int **arc;   //�ڽӾ��� 
	Dis * dis;	//��¼�����������·������Ϣ 
public:
	Graph(int v);
	~Graph();
	bool check_edge_value(int start, int end, int weight);// �ж�����ÿ������ĵıߵ���Ϣ�Ƿ�Ϸ�
	void createGraph(QString s);	 //����ͼ
	void show();	//��ӡ�ڽӾ���
	void dijkstra(int begin);	//�����·��
	void print_path(int); 	//��ӡ���·�� 
	int getDis(int v1, int v2);
};



