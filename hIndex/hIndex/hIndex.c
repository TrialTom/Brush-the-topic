#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//需求：给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数。计算并返回该研究者的 h 指数。
//
//根据维基百科上 h 指数的定义：h 代表“高引用次数”，一名科研人员的 h指数是指他（她）的 （n 篇论文中）总共有 h 篇论文分别被引用了至少 h 次。且其余的 n - h 篇论文每篇被引用次数 不超过 h 次。
//
//如果 h 有多种可能的值，h 指数 是其中最大的那个。
int cmp(int* e1, int* e2)
{
	return *e2 - *e1;
}

int hIndex(int* citations, int citationsSize)
{
	qsort(citations, citationsSize, 4, cmp);
	int i = 0;
	int ret = 0;
	while (i < citationsSize)
	{
		if (citations[i] > i)
		{
			i++;
			ret++;
		}
		else
			break;
	}
	return ret;
}

int main()
{
	int citations[] = { 3,0,6,1,5 };
	int sz = sizeof(citations) / sizeof(citations[0]);
	int ret = hIndex(citations, sz);

	printf("%d\n", ret);
	return 0;
}