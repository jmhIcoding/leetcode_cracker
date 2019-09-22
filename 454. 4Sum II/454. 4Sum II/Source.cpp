#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int rst = 0;
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		sort(C.begin(), C.end());
		sort(D.begin(), D.end());
		
		for (int i = 0; i < A.size(); i++)
		{
			int ABCD = 0;
			for (int j = 0; j < B.size(); j++)
			{
				int BCD = 0;
				int left = 0;
				int right = D.size() - 1;
				int sum = 0;
				while (left<C.size() && right >= 0)
				{
					sum = A[i] + B[j] + C[left] + D[right];
					if (sum < 0)
					{
						left++;
					}
					else if (sum>0)
					{
						right--;
					}
					else
					{
						int last_left = C[left], last_right = D[right],lp=0,rp=0;
						while (left<C.size() && C[left]==last_left)
						{
							left++;
							lp++;
						}
						while (right >= 0 && D[right] == last_right)
						{
							right--;
							rp++;
						}
						rst += rp*lp;
						BCD += rp *lp;
						ABCD += rp *lp;
					}
				}
				while ((j+1) < B.size() && B[j]==B[j+1])
				{
					j++;
					rst += BCD;
					ABCD += BCD;
				}
			}
			while ((1+i)<A.size() && A[i]==A[i+1])
			{
				i++;
				rst += ABCD;
			}
		}
		return rst;
	}
};
int main()
{
	Solution sol;
	vector<int> A = { 0,1,-1}, B = { -1, 1,0 }, C = { 0,0,1 }, D = { -1,1,1 };
	printf("%d\n", sol.fourSumCount(A,B,C,D));
	system("pause");
	return 0;
}