#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//
// 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
//
//在「杨辉三角」中，每个数是它左上方和右上方的数的和。
//
//

int* getRow(int rowIndex, int* returnSize) {
	int** ret = (int**)malloc(8 * 34);
	int row = 0;
	int col = 0;
	for (row = 0; row <= rowIndex; row++)
	{
		ret[row] = (int*)malloc(4 * (row + 1));
	}
	for (row = 0; row <= rowIndex; row++)
	{
		for (col = 0; col <= row; col++)
		{
			if (col == 0)
			{
				ret[row][col] = 1;
			}
			else if (col == row)
			{
				ret[row][col] = 1;
			}
			else
			{
				ret[row][col] = ret[row - 1][col] + ret[row-1][col - 1];
			}
		}
	}
	*returnSize = rowIndex + 1;
	int* returnNum = (int*)malloc(sizeof(int) * (rowIndex + 1));
	memmove(returnNum, ret[rowIndex], sizeof(int)*(rowIndex+1));
	for (row = 0; row <= rowIndex; row++)
	{
		free(ret[row]);
	}
	free(ret);
	ret = NULL;
	return returnNum;
}



int main()
{
	int rowIndex = 5,returnSize = 0;
	int* ret = getRow(rowIndex, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", ret[i]);
	}
	return 0;
}