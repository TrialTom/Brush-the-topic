#define _CRT_SECURE_NO_WARNINGS

//
// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//
//请注意 ，必须在不复制数组的情况下原地对数组进行操作。
//

#include <stdio.h>

void moreZeroes(int* nums, int numsSize)
{
	int i = numsSize-1;
	int j = 0;
	for (i; i >= 0; i--)
	{
		if (nums[i] == 0)
		{
			j = i;
			while (j < numsSize - 1)
			{
				nums[j] = nums[j + 1];
				j++;
			}
			nums[numsSize - 1] = 0;
		}
	}
}

int main()
{
	int i = 0;
	int nums[] = { 0,1,0,3,12 };
	moreZeroes(nums,sizeof(nums)/sizeof(nums[0]));
	for (i = 0; i < sizeof(nums) / sizeof(nums[0]);i++)
	{
		printf("%d\n", nums[i]);
	}
	return 0;
}