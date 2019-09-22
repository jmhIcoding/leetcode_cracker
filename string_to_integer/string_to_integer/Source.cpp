#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		long long int int_min =2147483648;
		long long int int_max = 2147483648 - 1;
		long long  rst = 0;
		int_min *= -1;
		int l = str.length();
		int flags = 1;
		bool s = false;
		for (int i = 0; i < l; i++)
		{
			if (str[i] == '+' && s==false)
			{
				flags = 1;
				s = true;
				continue;
			}
			else if (str[i] == '-' && s==false)
			{
				flags = -1;
				s = true;
				continue;
			}
			if ((str[i] - '0')<0 || (str[i] - '0')>9)
			{
				if (s == true)
					//结束
				{
					break;
				}
				else if (str[i] ==' ')
				{
					continue;
				}
				else
				{
					break;
				}
			}
			if ((str[i] - '0')>=0 || (str[i] - '0')<=9)
			{
				s = true;
				
				if ((rst * 10 + str[i] - '0')*flags <= int_min)
				{
					rst = int_min*flags;
					break;
				}
				if ((rst * 10 + str[i] - '0')*flags >= int_max)
				{
					rst = int_max*flags;
					break;
				}
				rst = rst * 10 + str[i] - '0';
			}
		}
		rst *= flags;
		if (rst <= int_min)
		{
			return int_min;
		}
		if (rst>=int_max)
		{
			return int_max;
		}
		rst=rst*flags;
		return (rst) * flags;
	}
};
int main()
{
	int a = 0x80000000;
	long long num1 = 2147483648;
	//2147483648 叫做 decimal整数字面量,如何确定一个整数字面量的类型?
	//c90
	//对于decimal 整数字面量,依次使用int,long,long long去匹配，使用第一个能表示这个数的类型，当然int 和long表示范围一致
	//int能表示的最大范围是2147483647, 2147483648 就超出了这个范围。于是把2147483648 这个字面量解析成了long long
	//在64位的long long上，2147483648的二进制为0x00000000 80000000
	long long num2 = -2147483648;
	//-2147483648 是 int 所能表示的最小值，于是刚好就能用int表示，所以把-2147483648的类型当作了int
	//-2147483648 作为int在内存中的表示为 0x80000000
	//long long num2 = -2147483648;其实还有一个隐式类型转换的过程，它等价于：long long num2 = (long long)-2147483648;
	//先把右边的int转换为long long ,再初始化,此时再初始化的时候就是直接把值拷贝过去了
	long long num3 = (unsigned int)-1;
	char c = -128;
	int cc = c;
	printf("%lld,%lld,%d\n", num1,num2,num1 == num2);
	system("pause");
	return 0;
}