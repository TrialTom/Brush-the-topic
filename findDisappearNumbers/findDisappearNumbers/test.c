#define _CRT_SECURE_N0_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间[1, n] 内。
//请你找出所有在[1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。



int cmp(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2) 
        return 1;
    return 0;
}
//修正：
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int i = 0;
    int temp = 0;
    int* ret = NULL;
    *returnSize = 0;
    qsort(nums, numsSize, 4, cmp);
    //计算returnSize 的个数
    //由于全排，而数组中元素的值取值范围为[1,n]，若产生错误，一定会有相同的数。
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i - 1])
            *returnSize += 1;
    }
    int* returnNumber = (int*)malloc(*returnSize * sizeof(int));
    ret = returnNumber;
    //两种特殊情况：首尾元素被替换
    if (nums[0] != 1)
    {
        *returnNumber = 1;
        returnNumber++;
        temp = 1;
        i = nums[0];
        while (nums[0] - temp > 1)
        {
            *returnNumber = ++temp;
            returnNumber++;
        }
    }
    if (nums[numsSize - 1] != numsSize)
    {
        *returnNumber = numsSize;
        returnNumber++;
        temp = numsSize;
        i = numsSize - 1;
        while (temp - nums[i] > 1)
        {
            *returnNumber = --temp;
            returnNumber++;
        }
    }
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] - nums[i - 1] > 1)
        {
            temp = nums[i - 1];
            while (nums[i] - temp > 1)
            {
                *returnNumber = ++temp;
                returnNumber++;
            }
        }
    }

    return ret;
}



    //问题代码：
//    *returnSize = 0;
//    if (numsSize == 1)
//        return NULL;
//    else
//    {
//        for (i = 1; i < numsSize; i++)
//        {
//            if (nums[i] - nums[i - 1] > 1 || nums[i] == nums[i-1] && (i != 1 || i != numsSize-1))
//                *returnSize += 1;
//        }
//        int* ret = (int*)malloc(*returnSize * sizeof(nums[0]));
//        int* ret1 = ret;
//#       //数组中要有n个数，而数的取值范围为：1~n
//        //则可以分为两种情况讨论
//        // 第一种是:缺失的是最大值或者最小值
//        // 第二种情况是缺失的数大于1小于n
//        if (nums[0] != 1)
//        {
//            *ret = 1;
//            ret++;
//            *returnSize += 1;
//        }
//        for (i = 1; i < numsSize; i++)
//        {
//            if (nums[i] - nums[i - 1] != 1)
//            {
//                temp = nums[i - 1];
//                if (nums[i] == nums[i - 1])
//                {
//                    *ret = nums[i] + 1;
//                    ret++;
//                }
//                else if (nums[i] - nums[i - 1] > 1)
//                {
//                    while (nums[i] - temp == 1)
//                    {
//                        *ret = ++temp;
//                        ret++;
//                    }
//                }
//            }
//        }
//        if (nums[numsSize - 1] != numsSize)
//        {
//            *ret = numsSize;
//            *returnSize += 1;
//        }
//        return ret1;
        //for (i = 1; i < numsSize; i++)
        //{
        //    //if (nums[i]- nums[i - 1] !=  1)
        //    //{
        //    //    temp = nums[i - 1];
        //    //    if (nums[i] > temp)
        //    //    {
        //    //        *ret = ++temp;
        //    //        ret++;
        //    //    }
        //    //    else if (nums[i] == temp)
        //    //    {
        //    //        *ret = ++temp;
        //    //        ret++;
        //    //    }
        //    }
        //}
    //

int main()
{
    int nums[] = { 5, 4, 6, 7, 9, 3, 10, 9, 5, 6 };
    int returnSize = 0;
    int i = 0;
    int* ret = findDisappearedNumbers(nums, sizeof(nums)/sizeof(nums[0]), &returnSize);
    for (i = 0; i < returnSize; i++)
    {
        printf("%d\n", *(ret + i));
    }
	return 0;
}