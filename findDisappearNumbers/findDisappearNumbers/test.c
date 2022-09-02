#define _CRT_SECURE_N0_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//����һ���� n ������������ nums ������ nums[i] ������[1, n] �ڡ�
//�����ҳ�������[1, n] ��Χ�ڵ�û�г����� nums �е����֣������������ʽ���ؽ����



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
//������
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int i = 0;
    int temp = 0;
    int* ret = NULL;
    *returnSize = 0;
    qsort(nums, numsSize, 4, cmp);
    //����returnSize �ĸ���
    //����ȫ�ţ���������Ԫ�ص�ֵȡֵ��ΧΪ[1,n]������������һ��������ͬ������
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i - 1])
            *returnSize += 1;
    }
    int* returnNumber = (int*)malloc(*returnSize * sizeof(int));
    ret = returnNumber;
    //���������������βԪ�ر��滻
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



    //������룺
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
//#       //������Ҫ��n������������ȡֵ��ΧΪ��1~n
//        //����Է�Ϊ�����������
//        // ��һ����:ȱʧ�������ֵ������Сֵ
//        // �ڶ��������ȱʧ��������1С��n
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