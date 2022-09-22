#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void exchange(int* a, int* b)
{
	int t = *b;
	*b = *a;
	*a = t;
}

void moveZeroes(int* nums, int numsSize) {
	int left = 0;
	int right = 0;
	while (right < numsSize)
	{
		if (nums[right])
		{
			exchange(nums + left, nums + right);
			left++;
		}
		right++;
	}
	//´íÎóË¼Â·£º
	//int indexNow = 1;
	//int indexNum = 0;
	//while (indexNow < numsSize)
	//{
	//	if (nums[indexNow] != 0)
	//	{
	//		nums[indexNum++] = nums[indexNow++];
	//		continue;
	//	}
	//	indexNow++;
	//}
	//while (indexNum < numsSize)
	//{
	//	nums[indexNum++] = 0;
	//}
}

int main()
{
	int nums[] = {1, 0 };
	moveZeroes(nums,sizeof(nums)/sizeof(nums[0]));
	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
	{
		printf("%d\n", nums[i]);
	}
	return 0;
}