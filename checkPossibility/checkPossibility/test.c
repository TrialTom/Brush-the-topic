#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

//
// 给你一个长度为 n 的整数数组 nums ，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。
//
//我们是这样定义一个非递减数列的： 对于数组中任意的 i(0 <= i <= n - 2)，总满足 nums[i] <= nums[i + 1]。
//
//

bool checkPossibility(int* nums, int numsSize) {
	int i = 0;
	for (i = 0; i < numsSize-1; i++)
	{
		if (i + 2 == numsSize)
			return true;
		if (nums[i] > nums[i + 1])
			
		{
			if (i > 0)
			{
				if (nums[i] >= nums[i - 1] && nums[i + 1] < nums[i-1])
				{
					if (i + 2 < numsSize)
					{
						nums[i + 1] = nums[i + 2];
						break;
					}
				}
			}
			nums[i] = nums[i + 1];
			break;
		}
	}
	for (i = 0; i < numsSize -1; i++)
	{
		if (nums[i] > nums[i + 1])
			return false;
	}
	return true;
}

int main()
{
	int nums[] = {1,2,3,4,5,3};
	bool a = checkPossibility(nums, sizeof(nums) / sizeof(nums[0]));
	printf("%d\n", a);
	return 0;
}