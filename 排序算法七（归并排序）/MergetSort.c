#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

void Mege(int array[], int left, int mid, int right, int exar[])//�ϲ����������С����
{
	int left_index = left;
	int right_index = mid;
	int exar_index = left;
	while (left_index < mid&&right_index < right)
	{
		if (array[left_index] <= array[right_index])
			exar[exar_index++] = array[left_index++];
		else
			exar[exar_index++] = array[right_index++];
	}
	while (left_index < mid)
		exar[exar_index++] = array[left_index++];
	while (right_index < right)
		exar[exar_index++] = array[right_index++];
	//ע������Ǵ�left��ʼ�ģ�����д�ɴ�0��ʼ������ṹ�����ֵ
	for (int i = left; i < right; i++)
	{
		array[i] = exar[i];
	}
}

void _MergeSort(int array[], int left, int right,int exar[])//�ݹ�ʵ�ֹ鲢����
{
	if (left + 1 == right)
		return;//�������˵��ֻ��һ��Ԫ��,˵��С�����Ѿ����򣬵ݹ����
	if (left >= right)
		return;//�������˵��û��Ԫ��
	int mid = left + (right - left) / 2;
	_MergeSort(array, left, mid, exar);//ע���ʱ������Ϊ����ҿ���[left,mid)
	_MergeSort(array, mid, right,exar);//[mid,right)���mid���ü�һ
	//�ϲ����������С����
	Mege(array, left, mid, right, exar);//exar�Ƕ���ĸ����ռ�
}

void MergeSort(int array[], int size)//���������ⲿ��������������ʱ���������
{
	int *exar = (int *)malloc(4*size);
	_MergeSort(array, 0, size, exar);
	free(exar);
}

void test()
{
	int array[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int size = sizeof(array) / sizeof(array[0]);
	MergeSort(array, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}

int main()
{
	test();
	system("pause");
	return 0;
}