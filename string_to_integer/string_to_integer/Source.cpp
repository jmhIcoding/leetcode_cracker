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
					//����
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
	//2147483648 ���� decimal����������,���ȷ��һ������������������?
	//c90
	//����decimal ����������,����ʹ��int,long,long longȥƥ�䣬ʹ�õ�һ���ܱ�ʾ����������ͣ���Ȼint ��long��ʾ��Χһ��
	//int�ܱ�ʾ�����Χ��2147483647, 2147483648 �ͳ����������Χ�����ǰ�2147483648 �����������������long long
	//��64λ��long long�ϣ�2147483648�Ķ�����Ϊ0x00000000 80000000
	long long num2 = -2147483648;
	//-2147483648 �� int ���ܱ�ʾ����Сֵ�����Ǹպþ�����int��ʾ�����԰�-2147483648�����͵�����int
	//-2147483648 ��Ϊint���ڴ��еı�ʾΪ 0x80000000
	//long long num2 = -2147483648;��ʵ����һ����ʽ����ת���Ĺ��̣����ȼ��ڣ�long long num2 = (long long)-2147483648;
	//�Ȱ��ұߵ�intת��Ϊlong long ,�ٳ�ʼ��,��ʱ�ٳ�ʼ����ʱ�����ֱ�Ӱ�ֵ������ȥ��
	long long num3 = (unsigned int)-1;
	char c = -128;
	int cc = c;
	printf("%lld,%lld,%d\n", num1,num2,num1 == num2);
	system("pause");
	return 0;
}