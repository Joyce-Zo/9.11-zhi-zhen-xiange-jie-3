#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

		һά���鴫��
void test1(int arr[])
{}
void test1(int arr[10])
{}
void test1(int* arr[10])
{}		//  ȫ����ȷ
void test1(int* arr)
{}

void test2(int *arr2[20])
{}
void test2(int**arr2)
{}

int main()
{
	int arr[10] = { 0 };
	int* arr2[20] = { 0 };
	test1(arr);
	test2(arr2);
	return 0;
}

void test1(int arr[3][5])
{}
void test2(int arr[][5])
{}
void test3(int arr[3][])	//  ��ά����ֻ��ʡ���У�����ʡ���� 
{}

void test4(int* arr)
{}	// arr��������Ԫ�ص�ַ����Ԫ���ǵ�һ�е����飬int*�������ָ��ĵ�ַ�����ܴ��һά����ĵ�ַ

void test5(int **arr)
{}	// ����ָ����һ��ָ��ĵ�ַ��arr����������һ������ĵ�ַ����һ�е����飩
void test6(int (*arr)[5])
{}	// *arr - ָ���ŵ�ַ��[5]ָ�����飬����5��Ԫ����int����
int main()
{
	int arr[3][5] = { 0 };
	test6(arr);
	return 0;
}

			һ	��	ָ	��	��	��
void test1(int* p)
{}

void test2(char* ch)
{}

int main()
{
	int a = 10;
	int* p1 = &a;
	test1(&a);
	test1(p1);

	char ch = 'c';
	char* pc = &ch;
	test2(pc);
	test2(&ch);

	return 0;
}
void print(int* p, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(p + i));
	}
}

int main()
{
	int arr[10] = { 1,2,3,4,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* p = arr;
	print(p, sz);
	return 0;
}

		��	��	ָ	��	��	��


void test(int** pp)
{}
int main()
{
	int n = 10;
	int* p = &n;
	int** pp = &p;
	test(pp);
	test(&p);

	int* arr[5];
	test(arr);	// ָ������Ҳ���ԣ���**����int*

	return 0;
}

  ����ָ�� - ��������ַ��ָ�� - ָ������
  ����ָ�� - ��ź�����ַ��ָ�� - ָ����
int Add(int a, int b)
{
	return a + b;
}
int main()
{
	int a = 10;
	int b = 20;
	printf("%d ", Add(a, b));
	/*printf("%p\n", &Add);
	printf("%p\n", Add);*/
	 &������ - ������  ���Ǻ����ĵ�ַ

	int(*pa)(int, int) = Add;
 (*pa)˵����ָ�룬(int,int)˵���Ǻ�������������������int����ͷint˵������������int
	(*pa)(5, 5);
	(*pa) ���ú�����(5,5)����
	printf("%d ", (*pa)(a, b));
	return 0;
}

void Print(char* str)
{
	printf("%s\n", str);
}
int main()
{
	 char str[20] = "Hello66";
	 Print(str);
	 void (*p)(char*) = Print;
 void �����ͣ�(*p) (char*)-��������
	 (*p)(str);
 (*p)�ҵ�������(str)����ʱ���Ĳ���
	return 0;
}
int main()
{
	(  *(void (*)()) 0  ) ();
		(void (*)())	  - ����ָ������
	  (void (*)()) 0    - ��0ǿ������ת��Ϊ����ָ������
	 *(void (*)()) 0	  - ������ǿ������ת�����0
	 *(void (*)()) 0 () - ���� 0 ��ַ���ģ�����Ϊ(��)�޲Σ���������Ϊvoid�ĺ���
	return 0;
}