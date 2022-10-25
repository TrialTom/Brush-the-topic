#include <stdio.h>
#include <string.h>
#include <string>


//������������12��Ӳ�ң��ֱ���A~L��ʾ������ǡ����һ���ٱң��ٱҵ�������ͬ����ң�������ҵ�������ͬ��

using namespace std;

//�ٶ����еıҶ�Ϊ��ң�w[i]=0
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
	printf("�ٱ�Ϊ��%c\n", x);
	if (y > 0)
		printf("�ٱұ�����ء�\n");
	if (y < 0)
		printf("�ٱұ�����ᡣ\n");
	return 0;
}