#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围[1, n] 内，
// 且每个整数出现 一次 或 两次 。
// 请你找出所有出现 两次 的整数，并以数组形式返回。
//
//你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题。

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