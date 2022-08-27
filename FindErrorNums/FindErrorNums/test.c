#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//题目需求如下：
//集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且 有一个数字重复 。
//
//给定一个数组 nums 代表了集合 S 发生错误后的结果。
//
//请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。




//int* findErrorNums(int* nums, int numsSize, int* returnSize) {
//    int i = 0,j = 0;
//    int value = 0;
//    int* returnSize1 = NULL;
//    assert(nums);
//    returnSize1 = (int*)malloc(8);
//    if (returnSize1 == NULL)
//    {
//        printf("%s\n", strerror(errno));
//        assert(returnSize1);
//    }
//    else
//        returnSize = returnSize1;
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[i] != i + 1)
//        {
//            for (j = 0; nums[j] < i; j++)
//            {
//                if (nums[i] == nums[j])
//                {
//                    returnSize[0] = nums[i];
//                    returnSize[1] = i+1;
//                }
//            }
//        }
//    }
//    return returnSize;
//}
int cmp(int* e1, int* e2)
{
    return *e1 - *e2;
}
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    int* returnSize1 = (int*)malloc(8);
    int i = 0;
    if (returnSize1 == NULL)
    {
        assert(returnSize1);
    }
    else
        returnSize = returnSize1;
    //找重复的数字
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i - 1] == nums[i])
        {
            *returnSize = nums[i];
        }
    }
    //找删除的数字
    
    //被删的数字是1或n
    if (nums[0] != 1)
    {
        *(returnSize + 1) = 1;
    }
    else if (nums[numsSize - 1] != numsSize)
        *(returnSize + 1) = numsSize;
    else
    {
        for (i = 1; i < numsSize; i++)
        {
            //如果被删除的数大于1小于n
            if (nums[i] - nums[i - 1] == 2)
            {
                *(returnSize + 1) = (nums[i] + nums[i - 1]) / 2;
            }
        }
    }
    return returnSize;
}

int main()
{
    int nums[] = { 2,2 };
    int numsSize = sizeof(nums) / sizeof(nums[1]);
    int* returnSize = NULL;
    returnSize = findErrorNums(nums, numsSize, returnSize);
    printf("%d", *returnSize);
    printf("%d", *(returnSize+1));
	return 0;

}