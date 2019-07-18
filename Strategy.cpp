#include <iostream>
#include<algorithm>
#include "Point.h"

#include "Judge.h"
#include "Strategy.h"
#include"Evaluate.h"


using namespace std;

/*
���Ժ����ӿ�,�ú������Կ�ƽ̨����,ÿ�δ��뵱ǰ״̬,Ҫ�����������ӵ�,�����ӵ������һ��������Ϸ��������ӵ�,��Ȼ�Կ�ƽ̨��ֱ����Ϊ��ĳ�������

input:
Ϊ�˷�ֹ�ԶԿ�ƽ̨ά����������ɸ��ģ����д���Ĳ�����Ϊconst����
M, N : ���̴�С M - ���� N - ���� ����0��ʼ�ƣ� ���Ͻ�Ϊ����ԭ�㣬����x��ǣ�����y���
top : ��ǰ����ÿһ���ж���ʵ��λ��. e.g. ��i��Ϊ��,��_top[i] == M, ��i������,��_top[i] == 0
_board : ���̵�һά�����ʾ, Ϊ�˷���ʹ�ã��ڸú����տ�ʼ���������Ѿ�����ת��Ϊ�˶�ά����board
��ֻ��ֱ��ʹ��board���ɣ����Ͻ�Ϊ����ԭ�㣬�����[0][0]��ʼ��(����[1][1])
board[x][y]��ʾ��x�С���y�еĵ�(��0��ʼ��)
board[x][y] == 0/1/2 �ֱ��Ӧ(x,y)�� ������/���û�����/�г������,�������ӵ㴦��ֵҲΪ0
lastX, lastY : �Է���һ�����ӵ�λ��, ����ܲ���Ҫ�ò�����Ҳ������Ҫ�Ĳ������ǶԷ�һ����
����λ�ã���ʱ��������Լ��ĳ����м�¼�Է������ಽ������λ�ã�����ȫȡ�������Լ��Ĳ���
noX, noY : �����ϵĲ������ӵ�(ע:��ʵ���������top�Ѿ����㴦���˲������ӵ㣬Ҳ����˵���ĳһ��
������ӵ�����ǡ�ǲ������ӵ㣬��ôUI�����еĴ�����Ѿ������е�topֵ�ֽ�����һ�μ�һ������
��������Ĵ�����Ҳ���Ը�����ʹ��noX��noY��������������ȫ��Ϊtop������ǵ�ǰÿ�еĶ�������,
��Ȼ�������ʹ��lastX,lastY�������п��ܾ�Ҫͬʱ����noX��noY��)
���ϲ���ʵ���ϰ����˵�ǰ״̬(M N _top _board)�Լ���ʷ��Ϣ(lastX lastY),��Ҫ���ľ�������Щ��Ϣ�¸������������ǵ����ӵ�
output:
������ӵ�Point
*/
extern "C" __declspec(dllexport) Point* getPoint(const int M, const int N, const int* top, const int* _board,
	const int lastX, const int lastY, const int noX, const int noY) {
	/*
	��Ҫ������δ���
	*/
	int x = -1, y = -1;//���ս�������ӵ�浽x,y��
	int** board = new int*[M];
	for (int i = 0; i < M; i++) {
		board[i] = new int[N];
		for (int j = 0; j < N; j++) {
			board[i][j] = _board[i * N + j];
		}
	}

	/*
	�������Լ��Ĳ������������ӵ�,Ҳ���Ǹ�����Ĳ�����ɶ�x,y�ĸ�ֵ
	�ò��ֶԲ���ʹ��û�����ƣ�Ϊ�˷���ʵ�֣�����Զ����Լ��µ��ࡢ.h�ļ���.cpp�ļ�
	*/
	//Add your own code below

	//a naive example
	/*for (int i = N-1; i >= 0; i--) {
	if (top[i] > 0) {
	x = top[i] - 1;
	y = i;
	break;
	}
	}*/
	

	/*int restStep=0;
	for (int i = 0; i < N; ++i)
	{
		restStep += top[i];
		if (i == noY&&noX < top[i])
			restStep--;
	}
	int step = min(restStep, 4);
	int* _top = new int[N];
	for (int i = 0; i < N; ++i)
		_top[i] = top[i];
	GameTreeNode* root = buildTree(board, _top, M, N, noX, noY, 2, 0, step);
	evaluateTreeVal(root, M, N, noX, noY);
	y = getY(root, N);
	x = top[y] - 1;*/
	int* _top = new int[N];
	for (int i = 0; i < N; ++i)
		_top[i] = top[i];
	long long alpha = -9223372036854775805;
	long long beta = 9223372036854775807;

	long long ll=alpha_beta(x, y, 0, M, N, lastX, lastY, board, _top, 2, alpha, beta, noX, noY);

	delete[] _top;


	/*
	��Ҫ������δ���
	*/
	clearArray(M, N, board);
	return new Point(x, y);
}


/*
getPoint�������ص�Pointָ�����ڱ�dllģ���������ģ�Ϊ��������Ѵ���Ӧ���ⲿ���ñ�dll�е�
�������ͷſռ䣬����Ӧ�����ⲿֱ��delete
*/
extern "C" __declspec(dllexport) void clearPoint(Point* p) {
	delete p;
	return;
}

/*
���top��board����
*/
void clearArray(int M, int N, int** board) {
	for (int i = 0; i < M; i++) {
		delete[] board[i];
	}
	delete[] board;
}


/*
�������Լ��ĸ�������������������Լ����ࡢ�����������µ�.h .cpp�ļ�������ʵ������뷨
*/