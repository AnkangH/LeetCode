/*
给定n个货物，每个货物有重量和价值两个属性。给定一个重量为m的箱子，在不超过箱子重量的前提下，求所装物品的最大价值。
*/


//使用二维数组进行递推
vector<int> maxValueOf01Bag1(int n, vector<pair<int, int>> goods)
{
	int m = goods.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));//dp[i][j] 前i件物品重量为j时的最大价值 因为有0 所以从1到m和n
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			//cout << "i=" << i << ",j=" << j << endl;
			if (goods[i - 1].second <= j)//货物序号和数组索引对齐 goods[i-1]代表第i个货物
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - goods[i - 1].second] + goods[i - 1].first);
			else
				dp[i][j] = dp[i - 1][j];
		}
	return dp[m];
}


//使用两个一维数组递推
vector<int> maxValueOf01Bag2(int n, vector<pair<int, int>> goods)//使用两个一维数组递推
{
	int m = goods.size();
	vector<int> pre(n + 1, 0);//递推的上一行
	vector<int> res = pre;//递推的当前行
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (goods[i - 1].second <= j)
				res[j] = max(pre[j], pre[j - goods[i - 1].second] + goods[i - 1].first);
			else
				res[j] = pre[j];
		}
		pre = res;//更新上一行
	}
	return res;
}


//使用一个一维数组进行递推
vector<int> maxValueOf01Bag3(int n, vector<pair<int, int>> goods)
{
	int m = goods.size();
	vector<int> res(n + 1, 0);
	for (int i = 1; i <= m; i++)//前i个货物
		for (int j = n; j >= 1; j--)//箱子总重量为j时的最大价值
			if (goods[i - 1].second <= j)//初始时 res[j]即dp[i-1][j] 使用res[j-k]更新 所以从后向前更新 使未更新的值保持上个状态 
				res[j] = max(res[j], res[j - goods[i - 1].second] + goods[i - 1].first);//使用第i个货物和不使用第 
	return res;
}
