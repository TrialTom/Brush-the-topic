#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//����һ������Ϊ n ���������� nums ������ nums �������������ڷ�Χ[1, n] �ڣ�
// ��ÿ���������� һ�� �� ���� ��
// �����ҳ����г��� ���� ������������������ʽ���ء�
//
//�������Ʋ�ʵ��һ��ʱ�临�Ӷ�Ϊ O(n) �ҽ�ʹ�ó�������ռ���㷨��������⡣

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const int* e1, const int* e2)
{
	return *e1 - *e2;
}

int* findDuplicates(int* nums, int numsSize, int* returnSize) {
	qsort(nums, numsSize, 4, cmp);
	int i = 0;
	for (i = 1; i < numsSize; i++)
	{
		if (nums[i] == nums[i - 1])
			(*returnSize)++;
	}
	int* ret = (int*)calloc(*returnSize,4);
	if (ret == NULL)
		assert(ret);
	int* ret1 = ret;
	for (i = 1; i < numsSize; i++)
	{
		if (nums[i] == nums[i - 1])
		{
			*ret = *(nums+i);
			ret++;
		}
	}
	return ret1;
}

int main()
{
	int nums[] = {4,3,2,7,8,2,3,1};
	int returnSize = 0;
	int* ret = findDuplicates(nums, sizeof(nums) / sizeof(nums[0]), &returnSize);
	int i = 0;
	for (i = 0; i < returnSize; i++)
	{
		printf("%d\n", *ret++);
	}
	return 0;
}