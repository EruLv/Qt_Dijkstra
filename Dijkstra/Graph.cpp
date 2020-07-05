#include "Graph.h"
#include"qvector.h"


Graph::Graph(int v) {
	vexnum = v;
	arc = new int*[vexnum];	//�ڽӾ���
	dis = new Dis[vexnum];	//��¼��̾���
	for (int i = 0;i < vexnum;i++) {	//��ʼ���ڽӾ���
		arc[i] = new int[vexnum];
		for (int k = 0;k < vexnum;k++) {
			arc[i][k] = INT_MAX;
		}
	}
}

Graph::~Graph() {
	delete[] dis;
	for (int i = 0; i < vexnum; i++) {
		delete arc[i];
	}
	delete arc;
}

// �ж�����ÿ������ĵıߵ���Ϣ�Ƿ�Ϸ�
//�����1��ʼ���
bool Graph::check_edge_value(int start, int end, int weight) {
	if (start<1 || end<1 || start>vexnum || end>vexnum || weight < 0) {
		return false;
	}
	return true;
}

void Graph::createGraph(QString s) {
	
	QString temp;
	int count = 1;
	int v1, v2, w;
	for (int i = 0;i < s.size();i++) {
		if (s[i] == ' '&&count == 1) {
			v1 = temp.toInt();
			temp = "";
			count++;
		}
		else if (s[i] == ' '&&count == 2) {
			v2 = temp.toInt();
			temp = "";
			count--;
		}
		else if (s[i] == '\n' || i == s.size()-1) {
			if (i == s.size() - 1) {
				temp += s[i];
			}
			w = temp.toInt();
			arc[v1-1][v2-1] = w;
			v1 = v2 = 0;
			temp = "";
		}
		else {
			temp += s[i];
		}
	}
}

int Graph::getDis(int v1,int v2){
	if(check_edge_value(v1,v2,1))
		return arc[v1-1][v2-1];
	return -1;	
}

