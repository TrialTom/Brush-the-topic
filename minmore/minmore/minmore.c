#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//
//����һ������Ϊ n ���������飬ÿ�β�������ʹ n - 1 ��Ԫ������ 1 ����������������Ԫ����ȵ���С����������
//
//
//˼·��
// ÿ�β�����n-1��Ԫ������1�ɵȼ���һ��Ԫ�ؼ�һ������ÿ��Ԫ�ؼ���nums����Сֵmin��������Ĳ�������
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