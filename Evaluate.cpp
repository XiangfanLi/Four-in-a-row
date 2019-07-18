#include<vector>
#include<iostream>
#include"Evaluate.h"
using namespace std;

vector<vector<int>> transToLine(int** board, const int M, const int N, int noX, int noY)
{
	vector<vector<int>> ans;
	vector<int> tmp;
	for (int i = 0; i < M; ++i)
	{
		if (i == noX)
		{
			//tmp.clear();
			tmp.push_back(-1);
			for (int j = 0; j < noY; j++)
				tmp.push_back(board[i][j]);
			tmp.push_back(-1);
			ans.push_back(tmp);
			tmp.clear();
			tmp.push_back(-1);
			for (int j = noY + 1; j < N; ++j)
				tmp.push_back(board[i][j]);
			tmp.push_back(-1);
			ans.push_back(tmp);
			tmp.clear();
		}
		else
		{
			//tmp.clear();
			tmp.push_back(-1);
			for (int j = 0; j < N; ++j)
				tmp.push_back(board[i][j]);
			tmp.push_back(-1);
			ans.push_back(tmp);
			tmp.clear();
		}
	}

	for (int j = 0; j < N; ++j)
	{
		if (j == noY)
		{
			//tmp.clear();
			tmp.push_back(-1);
			for (int i = 0; i < noX; ++i)
			{
				tmp.push_back(board[i][j]);
			}
			tmp.push_back(-1);
			ans.push_back(tmp);
			tmp.clear();
			tmp.push_back(-1);
			for (int i = noX + 1; i < M; ++i)
			{
				tmp.push_back(board[i][j]);
			}
			tmp.push_back(-1);
			ans.push_back(tmp);
			tmp.clear();
		}

		else {
			//tmp.clear();
			tmp.push_back(-1);
			for (int i = 0; i < M; ++i)
				tmp.push_back(board[i][j]);
			tmp.push_back(-1);
			ans.push_back(tmp);
			tmp.clear();
		}
	}

	for (int i = 0; i < M; ++i)
	{
		if (i - noX != noY)
		{
			int ii = i;
			int jj = 0;
			//tmp.clear();
			tmp.push_back(-1);
			while (ii >= 0 && jj < N)
			{
				tmp.push_back(board[ii][jj]);
				ii--;
				jj++;
			}
			tmp.push_back(-1);
			ans.push_back(tmp);
			tmp.clear();
		}

		else
		{
			int ii = i;
			int jj = 0;
			//tmp.clear();
			tmp.push_back(-1);
			while (ii >= 0 && jj < noY)
			{
				tmp.push_back(board[ii][jj]);
				ii--;
				jj++;
			}
			tmp.push_back(-1);
			ans.push_back(tmp);
			tmp.clear();
			tmp.push_back(-1);
			ii--;
			jj++;
			while (ii >= 0 && jj < N)
			{
				tmp.push_back(board[ii][jj]);
				ii--;
				jj++;
			}
			tmp.push_back(-1);
			ans.push_back(tmp);
			tmp.clear();

		}
	}

	for (int j = 1; j < N; ++j)
	{
		if (noY - j != M - 1 - noX)
		{
			//tmp.clear();
			tmp.push_back(-1);
			int ii = M - 1;
			int jj = j;
			while (ii >= 0 && jj < N)
			{
				tmp.push_back(board[ii][jj]);
				ii--;
				jj++;
			}
			tmp.push_back(-1);
			ans.push_back(tmp);
			tmp.clear();
		}
		else
		{
			//tmp.clear();
			tmp.push_back(-1);
			int ii = M - 1;
			int jj = j;
			while (ii >= 0 && jj < noY)
			{
				tmp.push_back(board[ii][jj]);
				ii--;
				jj++;
			}
			tmp.push_back(-1);
			ans.push_back(tmp);
			tmp.clear();
			tmp.push_back(-1);
			ii--;
			jj++;
			while (ii >= 0 && jj < N)
			{
				tmp.push_back(board[ii][jj]);
				ii--;
				jj++;
			}
			tmp.push_back(-1);
			ans.push_back(tmp);
			tmp.clear();
		}
	}

	for (int j = 0; j < N; ++j)
	{
		if (noY - j != noX)
		{
			int ii = 0;
			int jj = j;
			//tmp.clear();
			tmp.push_back(-1);
			while (ii < M&&jj < N)
			{
				tmp.push_back(board[ii][jj]);
				ii++;
				jj++;
			}
			tmp.push_back(-1);
			ans.push_back(tmp);
			tmp.clear();
		}
		else
		{
			int ii = 0;
			int jj = j;
			//tmp.clear();
			tmp.push_back(-1);
			while (ii < noX&&jj < noY)
			{
				tmp.push_back(board[ii][jj]);
				ii++;
				jj++;
			}
			tmp.push_back(-1);
			ans.push_back(tmp);
			tmp.clear();
			tmp.push_back(-1);
			ii++;
			jj++;
			while (ii < M&&jj < N)
			{
				tmp.push_back(board[ii][jj]);
				ii++;
				jj++;
			}
			tmp.push_back(-1);
			ans.push_back(tmp);
			tmp.clear();
		}
	}

	for (int i = 1; i < M; ++i)
	{
		if (noX - i != noY)
		{
			//tmp.clear();
			tmp.push_back(-1);
			int ii = i;
			int jj = 0;
			while (ii < M&&jj < N)
			{
				tmp.push_back(board[ii][jj]);
				ii++;
				jj++;
			}
			tmp.push_back(-1);
			ans.push_back(tmp);
			tmp.clear();
		}
		else
		{
			//tmp.clear();
			tmp.push_back(-1);
			int ii = i;
			int jj = 0;
			while (ii < noX&&jj < noY)
			{
				tmp.push_back(board[ii][jj]);
				ii++;
				jj++;
			}
			tmp.push_back(-1);
			ans.push_back(tmp);
			tmp.clear();
			tmp.push_back(-1);
			ii++;
			jj++;
			while (ii < M&&jj < N)
			{
				tmp.push_back(board[ii][jj]);
				ii++;
				jj++;
			}
			tmp.push_back(-1);
			ans.push_back(tmp);
			tmp.clear();
		}
	}
	return ans;
}



long long getValue(int me, int oppo)
{
	if (me == 0 || oppo != 0)
		return 0;
	if (me == 1)
		return 1;
	else if (me == 2)
		return 10;
	else if (me == 3)
		return 1000;
	else if (me == 4)
		return 100000;
}


long long machineEvaluateLine(vector<int> line)
{
	long long ans=0;
	if (int(line.size()) < 6)
		return 0;
	int me = 0;
	int oppo = 0;
	
	for (int i = 1; i < 5; ++i)
	{
		
		if (line[i] == 2)
			++me;
		else if (line[i] == 1)
			++oppo;
	}
	ans += getValue(me, oppo);
	int front = 1;
	int back = 4;
	while (back<int(line.size()) - 2)
	{
		if (line[front] == 2)
			me--;
		else if (line[front] == 1)
			oppo--;
		front++;
		back++;
		if (line[back] == 2)
			me++;
		else if (line[back] == 1)
			oppo++;
		ans += getValue(me, oppo);
	}
	return ans;
}



long long userEvaluateLine(vector<int> line)
{
	long long ans = 0;
	if (int(line.size()) < 6)
		return 0;
	int me = 0;
	int oppo = 0;

	for (int i = 1; i < 5; ++i)
	{

		if (line[i] == 1)
			++me;
		else if (line[i] == 2)
			++oppo;
	}
	ans += getValue(me, oppo);
	int front = 1;
	int back = 4;
	while (back<int(line.size()) - 2)
	{
		if (line[front] == 1)
			me--;
		else if (line[front] == 2)
			oppo--;
		front++;
		back++;
		if (line[back] == 1)
			me++;
		else if (line[back] == 2)
			oppo++;
		ans += getValue(me, oppo);
	}
	return ans;
}


long long machineEvaluate(vector<vector<int>> lines)
{
	long long ans = 0;
	for (int i = 0; i<int(lines.size()); ++i)
	{
		ans += machineEvaluateLine(lines[i]);
	}
	return ans;
}



long long userEvaluate(vector<vector<int>> lines)
{
	long long ans = 0;
	for (int i = 0; i<int(lines.size()); ++i)
	{
		ans += userEvaluateLine(lines[i]);
	}
	return ans;
}



long long evaluate(int** board, const int M, const int N, int noX, int noY)
{
	vector<vector<int>> lines = transToLine(board, M, N, noX, noY);
	long long ans = machineEvaluate(lines) - userEvaluate(lines);
	lines.clear();
	return ans;
}


long long alpha_beta(int& ansx, int& ansy, int h, const int M, const int N, int x, int y, int** board, int* top, int player, long long alpha, long long beta, int noX, int noY)
{


	if (x != -1 && y != -1 && machineWin(x, y, M, N, board))
	{
		return 922337203685477580;
	}

	if (x != -1 && y != -1 && userWin(x, y, M, N, board))
	{
		return (-922337203685477580);
	}

	if (x != -1 && y != -1 && isTie(N, top))
	{
		return 0;
	}

	if (x != -1 && y != -1 && h == 5)
	{
		return evaluate(board, M, N, noX, noY);
	}
	//int i;
	if (player == 2)
	{
		for (int i = 0; i < N; ++i)
		{
			if (top[i] > 0)
			{
				int nextX = top[i] - 1;
				int nextY = i;
				board[top[i] - 1][i] = 2;
				if (top[i] - 2 == noX&&i == noY)
					top[i] -= 2;
				else
					top[i] -= 1;
				long long ans = alpha_beta(ansx, ansy, h + 1, M, N, nextX, nextY, board, top, player % 2 + 1, alpha, beta, noX, noY);
				board[nextX][nextY] = 0;
				if (top[i] == noX&&i == noY)
					top[i] += 2;
				else
					top[i] += 1;
				if (ans > alpha) {
					alpha = ans;
					if (h == 0)
					{
						ansx = nextX;
						ansy = nextY;
					}
				}

				if (alpha >= beta)
				{
					return alpha;
				}
			}
		}
		return alpha;
	}
	else {
		for (int i = 0; i < N; ++i)
		{
			if (top[i] > 0)
			{
				int nextX = top[i] - 1;
				int nextY = i;
				board[top[i] - 1][i] = 1;
				if (top[i] - 2 == noX&&i == noY)
					top[i] -= 2;
				else
					top[i] -= 1;
				long long ans = alpha_beta(ansx, ansy, h + 1, M, N, nextX, nextY, board, top, player % 2 + 1, alpha, beta, noX, noY);
				board[nextX][nextY] = 0;
				if (top[i] == noX&&i == noY)
					top[i] += 2;
				else
					top[i] += 1;
				if (ans < beta) {
					beta = ans;
					if (h == 0)
					{
						ansx = nextX;
						ansy = nextY;
					}
				}

				if (alpha >= beta)
				{
					return beta;
				}
			}
		}
		return beta;
	}

}
