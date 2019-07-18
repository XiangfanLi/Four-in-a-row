#pragma once

#include<vector>
#include<iostream>
#include"judge.h"
using namespace std;
vector<vector<int>> transToLine(int** board, const int M, const int N, int noX, int noY);



//

long long getValue(int cnt, int blk);

long long machineEvaluateLine(vector<int> line);

long long userEvaluateLine(vector<int> line);

long long machineEvaluate(vector<vector<int>> lines);

long long userEvaluate(vector<vector<int>> lines);

long long evaluate(int** board, const int M, const int N, int noX, int noY);

long long alpha_beta(int& ansx, int& ansy, int h, const int M, const int N, int x, int y, int** board, int* top, int player, long long alpha, long long beta, int noX, int noY);

