#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

		一维数组传参
void test1(int arr[])
{}
void test1(int arr[10])
{}
void test1(int* arr[10])
{}		//  全部正确
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
void test3(int arr[3][])	//  二维数组只能省略行，不能省略列 
{}

void test4(int* arr)
{}	// arr传过来首元素地址，首元素是第一行的数组，int*存放整型指针的地址，不能存放一维数组的地址

void test5(int **arr)
{}	// 二级指针存放一级指针的地址，arr传递来的是一个数组的地址（第一行的数组）
void test6(int (*arr)[5])
{}	// *arr - 指针存放地址，[5]指向数组，数组5个元素是int类型
int main()
{
	int arr[3][5] = { 0 };
	test6(arr);
	return 0;
}

			一	级	指	针	传	参
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

		二	级	指	针	传	参


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
	test(arr);	// 指针数组也可以，传**的是int*

	return 0;
}

  数组指针 - 存放数组地址的指针 - 指向数组
  函数指针 - 存放函数地址的指针 - 指向函数
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
	 &函数名 - 函数名  都是函数的地址

	int(*pa)(int, int) = Add;
 (*pa)说明是指针，(int,int)说明是函数，函数参数类型是int，开头int说明返回类型是int
	(*pa)(5, 5);
	(*pa) 调用函数。(5,5)传参
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
 void 空类型，(*p) (char*)-参数类型
	 (*p)(str);
 (*p)找到函数，(str)调用时传的参数
	return 0;
}
int main()
{
	(  *(void (*)()) 0  ) ();
		(void (*)())	  - 函数指针类型
	  (void (*)()) 0    - 将0强制类型转换为函数指针类型
	 *(void (*)()) 0	  - 解引用强制类型转换后的0
	 *(void (*)()) 0 () - 调用 0 地址处的，参数为(空)无参，返回类型为void的函数
	return 0;
}