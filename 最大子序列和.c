int maxsubsum(const verctor<int> &a)//任何负的子序列不可能是最优子序列的前缀
{
	int maxSum=0, thisSum=0;
	for(int i=0; i<a.size(); i++)
	{
		thisSum+=a[i];
		if(thisSum>maxSum) maxSum=thisSum;
		else if(thisSum<0) thisSum=0;
	}
	return maxSum;
}
