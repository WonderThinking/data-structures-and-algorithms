/********************
Author:		  Wang Xinqi
Date:		  2018-3-18
Description:  ����������ö�̬�滮�����(Dynamic Programming��
			  ˼·Դ��DD��ţ�ġ������Ž���,������������
			  0/1��������       ��ȫ��������        ���ر�������
			  ������ֱ�������  ��ά���õı�������  ���鱳������
			  �������ı�������  ������Ʒ�ı�������  ���������ʷ��仯--����Ž⡢��K�Ž�		  
*********************/

#include<iostream>
#include<vector>
#include"Knapsack1.h"
#include"Knapsack2.h"
#include"Knapsack3.h"
#include"Knapsack4.h"
#include"Knapsack5.h"
#include"Knapsack6.h"
#include"Knapsack7.h"
#include"Knapsack8.h"
#include"Knapsack9.h"
using namespace std;

int main()
{
	////һЩ��������
	//int v[] = { 1,2,3,4,5 };
	//int w[] = { 5,4,3,2,1 };
	//int c = 10;
	//int n = 5;
	//cout << "����ֵ " << Knapsack2_1(v, w, c, n) << endl;
	//cout << "\n����ֵ " << Knapsack2_2(v, w, c, n) << endl;

	//int v[] = { 2,2,3,4,5 };
	//int w[] = { 5,4,3,2,1 };
	//int N[] = { 2,2,1,2,1 };
	//int c = 10;
	//int n = 5;
	//cout << "����ֵ " << Knapsack3(v, w, N, c, n) << endl;
	//cout << "����ֵ " << Knapsack4(v, w, N, c, n) << endl;

	//int v[] = { 120,240,310,220 };
	//int w[] = { 160,80,220,40 };
	//int q[] = { 40,110,70,400 };
	//int cw = 320;
	//int cq = 350;
	//int n = 4;
	//cout << "����ֵ " << Knapsack5(v, w, q, cw, cq, n) << endl;

	//int g = 2;
	//vector<vector<int> > v = { {1,2},{1,3} };
	//vector<vector<int> > w = { {1,2},{1,2} };
	//vector<int>  m = { 2,2 };
	//int c = 2;
	//cout << "����ֵ " << Knapsack6(v, w, m, c, g) << endl;

	//vector<vector<int> > v = { {50,80},{130},{70,40,60} };
	//vector<vector<int> > w = { {30,25},{50},{40,30,35} };
	//vector<int> W = { 300,600,400 };
	//vector<int> m = { 2,1,3 };
	//int c = 800;
	//int n = 3;
	//cout << "����ֵ " << Knapsack7(v, w, W, m, c, n) << endl;

	int v[] = { 1,2,3,4,5 };
	int w[] = { 5,4,3,2,1 };
	int c = 10;
	int n = 5;
	int K = 2;
	cout << "��" << K << "��ֵ " << Knapsack9(v, w, c, n, K) << endl;
	system("pause");
	return 0;
}