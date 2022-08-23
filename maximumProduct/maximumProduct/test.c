#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
//给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
//
// 
//
//示例 1：
//
//输入：nums = [1, 2, 3]
//输出：6
//示例 2：
//
//输入：nums = [1, 2, 3, 4]
//输出：24
//示例 3：
//
//输入：nums = [-1, -2, -3]
//输出： - 6
//
//
//提示：
//
//3 <= nums.length <= 104
//- 1000 <= nums[i] <= 1000
//
//来源：力扣（LeetCode）
int cmp(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 > arg2) return -1;
    if (arg1 < arg2) return 1;
    return 0;

    // return (arg1 > arg2) - (arg1 < arg2); // 可行的简写
    // return arg1 - arg2; // 错误的简写（若给出 INT_MIN 则会失败）
}
int maximumProduct(int* nums, int numsSize) {
    int max1 = 0;
    int max2 = 0;
    if (numsSize < 3)
        return 0;
    else
    {
        qsort(nums, numsSize, sizeof(nums[0]), cmp);
        max1= nums[0] * nums[1] * nums[2];
        max2 = nums[numsSize - 1] * nums[numsSize - 2]*nums[0];
        if (max1 > max2)
            return max1;
        else
            return max2;
    }
}
int main()
{
	int nums[] = {-100,-98,-1,2,3,4};
    int sz = sizeof(nums) / sizeof(nums[0]);
    int ret = maximumProduct(nums, sz);
    printf("%d", ret);
	return 0;
}

//有待优化