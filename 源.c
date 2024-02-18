#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//递归函数：自身调用自身的一种函数
//int main() {
//	printf("haha\n");
//	main();     //在main函数里面打印haha，再在main函数内部调用main()函数造成死循环，达到栈区间的内存上限后会出现栈溢出的问题！  详情看平板笔记
//	return 0;
//
// }
// 
//利用递归函数，实现输出输入的数字中的每一位数的功能
//程序设计思路：1.编写一个递归函数output，实现判断传入的数是否>9(判断是否为个数)，如果大于9，就再次调用这个递归函数output，如果为个位数，则打印这个数%10（得到个位的数）
//
//void output(int n) {
//	if (n > 9)  //目前这个数不是个位数   //例如1234
//	{
//		output(n/10);    //再次调用output函数，把n/10(在c语言中，因为n的类型是整形，而且/两边均是整数，所以得出来的是商的整数部分)  1234/10=123
//		////把n=123作为实参传入output函数，再在里面进行判断
//	}
//	//  这里不能用else/else if ,if语句，打印当前的最低位，是一个每次递归调用都需要执行的语句，不能给他加上判断条件
//		printf("%d ", n % 10);   //得到的是个位   1%10=1   商是0，余数为1  
//}
//int main() {
//	int number = 0;
//	scanf("%d", &number);
//	output(number);
//
//	return 0;
//}


//利用递归函数实现查找字符串长度的功能
//1.创建临时变量，用while循环实现的做法
//int my_strlen(char* str)   //用指针变量接收第一个元素的地址
//{
//	//int count = 0;  //创建临时变量用于存放字符串的长度
//	//while (*str != '\0')  //当识别到地址中的元素不是'\0'的时候，count个数+1，存放地址的指针变量str+1
//	//{
//	//	count++;
//	//	str++;  //str++会使地址向右移动指向 i-----t-----\0
//	//}
//	//return count;
//}


//利用递归函数的做法
//int my_strlen(char* str)
//{
//	if (*str != '\0') {
//		return 1 + my_strlen(str+1);  
//	}
//	else {
//		return 0;
//	}
//}
////把大事化小
//my_strlen("bit"):
//识别到第一个地址为b的地址，b不是\0,所以至少有1的长度+my_strlen("it"):
//1+my_strlen("it")  str+1  地址右移一位变为“it”  再次调用my_strlen()函数
//1+1+my_strlen("t"):  地址右移一位变为“t”
//1+1+1+my_strlen(""):   
//1+1+1+0=3


//int main() {
//	char arr[] = "bit";
//	int len=my_strlen(arr);  //传的是数组中第一个元素的地址
//	printf("长度为：%d", len);
//	return 0;
//}

////使用递归函数实现输出输入的数字的阶乘的功能
//int fac1(int n) {  //例如n=5
//	if (n <= 1) {
//		return 1;
//	else {
//		return n * fac(n - 1);  //  5*fac(4)-->  4*fac(3) --->  3*fac(2)-->2*fac(1)-->1
//		//                          5*4*3*2*1   <--4*3*2*1      <--3*2*1   <--2*1  <--1
//	}
//	}
//}
//int main() {
//	int num = 0;
//	int ret = 0;
//	printf("请输入你要查找阶乘的数字：");
//	scanf("%d", &num);
//	ret = fac1(num);
//	return 0;
//}


//使用递归函数实现输出第n个斐波那契数的值的功能（不合适，会重复大量计算，计算速度慢！！）
//int fib(int n)   //斐波拉契数 1 1 2 3 5 8 13 21 34 55...第一和第二个数是1 1  第三个数前两个数之和
//{
//	if (n <= 2) {
//		return 1;
//	}
//	else {
//		return fib(n - 1) + fib(n - 2);
//	}
//}
//int main() {
//	int num = 0;
//	int ret = 0;  //用于存放斐波拉契函数的返回值
//	printf("请输入你要查询的第n个斐波拉契数：");
//	scanf("%d", &num);
//	ret=fib(num);
//	printf("第%d个斐波拉契数的值是%d\n", num, ret);
//	return 0;
//}


//使用循环的做法实现输出第n个斐波拉契的值的功能
//设计思路：定义一个变量a用于存放第一个斐波拉契数，变量b用于存放第二个斐波拉契数，c=a+b 
//3.a初始值=1，b初始值=1   ！！！注意：c的初始值要赋值为1！避免当n=1或2时return c=0或是别的数，一定要return 1！（因为第一个和第二个斐波拉契数的值是1）
//2.给把b的值赋给a，把c的值赋给b，c再次等于c=a+b，每循环一次  n-1：控制循环条件，避免死循环（为了当达到2时不在循环）
// 

//青蛙跳台阶游戏：青蛙每一次可以跳1个台阶或者两个台阶  计算当青蛙要跳n个台阶时，有几种跳法
//设计思路：通过上一步得出的结果，计算下一步的计算结果（动态规划）   详细看平板
//int jump(int n)
//{
//	if (n > 2) {
//	return jump(n - 1) + jump(n - 2);
//	}
//	else {
//		return n;
//	}
//}
//int main() {
//	int num = 0;
//	int method = 0;
//	printf("青蛙王子，请输入你要跳的台阶次数：");
//	scanf("%d", &num);
//	method = jump(num);
//	printf("%d个台阶有%d种跳法！",num,method);
//	return 0;
//}


//汉诺塔（将A柱子上的所有盒子移动到C柱子上，中间有B柱子，移动过程中要遵循大的盒子始终在下的原则）
// 递归思想  将大事化小，先将所有层次的汉诺塔分为最底层和最底层上面的所有层数
//如果层数只有一层，则直接将盒子从A柱子移动到C柱子（递归出口）
//如果层数大于1层，则先将n-1的所有部分从A柱（起始柱）绕过C（C柱在这里作为中间柱）柱挪到B柱（中间柱可以切换不一定是以B柱作为中间柱），再将A柱上的第一层移动到C(目标柱)
//最后再将B柱上的所有层数绕过A柱移动到C柱（目标柱）   //程序中需要绕过的原因是一次只能移动一块盒子，所以需要先将n-1中最短的部分放在目前的中间辅助柱中，再将大一点的
//放到目前的目标柱中   //利用递归去重复上述动作

void hanoi(int n, char A, char B, char C) {
	if (n == 1)   //递归出口，如果只有一层，则直接从A移动到C
	{
		printf("%c->%c\n", A, C);
	}
	else
	{
		hanoi(n - 1, A, C, B);   //把C作为中间柱，B作为目标柱
		printf("%c->%c\n", A, C);
		hanoi(n - 1, B, A, C);
	}
}

int main() {
	hanoi(4, 'A', 'B','C');   //汉诺塔层数为5 ，传入参数有三根柱子分别是A,B,C
	return 0;
}