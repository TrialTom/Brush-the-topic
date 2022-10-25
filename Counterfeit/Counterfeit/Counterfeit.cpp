#include <stdio.h>
#include <string.h>
#include <string>


//问题描述：有12个硬币，分别用A~L表示，其中恰好有一个假币，假币的重量不同于真币，所有真币的重量相同。

using namespace std;

//假定所有的币都为真币，w[i]=0
int w[12];
string a[3] = { "ABCD","ABCI","ABIJ" };
string b[3] = { "EFGH","EFJK","EFGH" };
string c[] = { "even","up","even" };

bool Balance()
{

	for (int i = 0; i < 3; i++)
	{
		int leftc = 0;
		int rightc = 0;
		for (int j = 0; j < a[i].size(); j++)
		{
			leftc += w[a[i][j] - 'A'];
			rightc += w[b[i][j] - 'A'];
		}
		if (leftc == rightc && c[i] != "even")
			return false;
		if (leftc > rightc && c[i] != "up")
			return false;
		if (leftc < rightc && c[i] == "even")
			return false;
	}
	return true;
}

void solve(int& x, int& y)
{
	y = 0;
	x = 0;
	for (int z = 0; z < sizeof(w); z++)
	{
		w[z] = 1;
		if (Balance())
		{
			x = 'A'+z;
			y = 1;
		}
		w[z] = -1;
		if (Balance())
		{
			x = 'A'+z;
			y = -1;
		}

	}
}

int main()
{
	memset(w, 0, sizeof(w));
	int x, y;
	solve(x, y);
	printf("假币为：%c\n", x);
	if (y > 0)
		printf("假币比真币重。\n");
	if (y < 0)
		printf("假币比真币轻。\n");
	return 0;
}