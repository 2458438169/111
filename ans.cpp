#include <bits/stdc++.h>
using namespace std;

struct PII
{
	int first;
	int second;
};

const int N = 30;
int n = 0;
int rol[N];
int col[N];
bool flag[N][N];
vector<PII> res;

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

bool PD(int x, int y)
{ // 边界检查
	if (flag[x][y] == 1)
	{
		return 0;
	}
	else if (x < 1)
	{
		return 0;
	}
	else if (x > n)
	{
		return 0;
	}
	else if (y < 1)
	{
		return 0;
	}
	else if (y > n)
	{
		return 0;
	}
	else if (rol[x] <= 0)
	{
		return 0;
	}
	else if (col[x] <= 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

bool check(int x, int y)
{
	if (x == n && y == n)
	{ // 到达终点
		for (int i = 1; i <= n; i++)
		{ // 检查行上是否有剩余
			if (col[i] != 0 || rol[i] != 0)
			{
				return false;
			}
		}
		for (int i = 0; i < res.size(); i++)
		{ // 输出路径
			int x = res[i].first;
			int y = res[i].second;
			int sum = n * (x - 1) + y - 1;
			cout << sum << " ";
		}
		cout << endl;
		return false;
	}
	return true;
}

void DFS(int x, int y)
{
	if (!check(x, y))
	{ // 检查终止条件
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{ // 四个方向进行搜索
			int xt = dx[i] + x;
			int yt = dy[i] + y;
			if (!PD(xt, yt))
			{ // 检查是否可以移动
				continue;
			}
			else
			{
				flag[xt][yt] = true;
				col[xt]--;
				rol[yt]--;
				res.push_back({xt, yt});
				DFS(xt, yt);

				// 回溯
				res.pop_back();
				flag[xt][yt] = false;
				col[xt]++;
				rol[yt]++;
			}
		}
	}
}

int main()
{
	// 输入
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> rol[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> col[i];
	}

	// 初始位置
	flag[1][1] = true;
	rol[1]--;
	col[1]--;
	res.push_back({1, 1});
	DFS(1, 1);
	return 0;
}
