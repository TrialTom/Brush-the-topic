#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

//
// 给你一个非负整数数组 nums ，你最初位于数组的第一个位置。

//数组中的每个元素代表你在该位置可以跳跃的最大长度。

//你的目标是使用最少的跳跃次数到达数组的最后一个位置。

//假设你总是可以到达数组的最后一个位置。
//

int End1(int* first, int* end)
{
    int last = 0;
    int sum = 0;
    for (int i = 0; i <= (end - first); i++)
    {
        if (first[i] + i > sum)
        {
            sum = first[i] + i;
            last = i;
        }
    }
    return last;
}
int jump(int* nums, int numsSize) {
    int border = 0;
    int k = 0;
    if (numsSize == 1)
        return 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] + i > border && i == 0)
        {
            border = nums[i] + i;
            k++;
            if (border >= numsSize - 1)
                return k;
        }
        int end = End1(nums + i, nums + border);
        if (nums[i + end] + i + end > border)
        {
            border = nums[i + end] + i + end;
            k++;
            i = i + end;
            if (border >= numsSize - 1)
                return k;
        }
    }
    return k;
}

int main()
{
    int nums[] = { 5,2,1,2,5,2,6,8,1,9,3,5,8,0,2 };
    int space = jump(nums, sizeof(nums)/sizeof(nums[1]));
    printf("%d\n", space);
	return 0;
}