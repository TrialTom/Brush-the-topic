#define _CRT_SRCURE_NO_WARNINGS

#include <stdio.h>
//给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
int firstMissingPositive(int* nums, int numsSize) {
    int i = 0;
    int temp;
    for (i = 0; i < numsSize; i++)
    {
        while (nums[i] > 0 && nums[i] <= numsSize && nums[i] != nums[nums[i]-1])
        {
            temp = nums[i];
            nums[i] = nums[temp - 1];
            nums[temp - 1] = temp;
        }
    }
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
        else if (nums[i] == numsSize)
            return numsSize + 1;
    }
    return numsSize;
}

int main()
{
    int nums[] = { 3,4,-1 ,1};
    int ret = firstMissingPositive(nums, sizeof(nums)/sizeof(nums[0]));
    printf("%d\n", ret);
	return 0;
}
