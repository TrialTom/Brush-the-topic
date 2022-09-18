#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//
//给你一个长度为 n 的整数数组，每次操作将会使 n - 1 个元素增加 1 。返回让数组所有元素相等的最小操作次数。
//
//
//思路：
// 每次操作将n-1个元素增加1可等价于一个元素减一，当将每个元素减到nums中最小值min，其操作的步数即答案
//

int more(int* nums, int numsSize)
{
	int i = 0;
	int sum = 0;
	int min = nums[0];
	for (i = 1; i < numsSize; i++)
	{
		if (nums[i] < min)
			min = nums[i];
	}
	for (i = 0; i < numsSize; i++)
	{
		sum += nums[i] - min;
	}
	return sum;
}

int main()
{
	int nums[] = { 1,2,3 };
	int ret = more(nums, sizeof(nums) / sizeof(nums[0]));
	printf("%d\n", ret);
	return 0;
}