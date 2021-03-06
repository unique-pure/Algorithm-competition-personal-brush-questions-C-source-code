# A. Eshag Loves Big Arrays

* **题目大意**

  给你一串序列，你可以去掉任何大于子序列平均数的数。问你能去除最多的数量是多少？

* **解题思路**

  易知，子序列我们可以只选择一个，其平均数就是最小值本身，那么最后去除的即是所有大于最小值的数，所以我们易知答案即为$n- num_{min}$。

* **AC代码**

# B. Sifid and Strange Subsequences

* **题目大意**

  给你一串序列，你需要选取一个长度尽可能大的子序列，其中需要满足， $1≤i<j,|a_i-a_j|≥MAX$，$MAX$为序列中的最大值。

* **解题思路**

  我们需要知道，$MAX$即为序列中的值，也就是说，我们关心的实际上就是$MAX$进行操作之后会不会小于$MAX$，仅考虑这个我们发现实际上所有的非正数都满足条件，这两个正数是绝对不满足的，因为它们相减得到的值是小于$MAX$的，那么我们可能可以选择一个正数，那么选择的依据是什么呢？ ==我们可以对整个序列进行排序，那么我们选取的正数肯定是越小越好，同时一定要满足相邻之差大于等于$MAX$，$MAX$即我们选取的整数，所以我们可以保存选取的非正数的最小相邻之差，以这个为标准去选取符合条件的正数即可得到答案。== 

# C. Parsa's Humongous Tree

* **题目大意**

  给你一棵树，树上的每个节点$i$都有一个值域$[l_i,r_i]$，我们需要从值域中确定一个值$a_i\in [l_i,r_i]$，而$(u,v)$边权值则为$|a_u-a_v|$。我们的目的就是要让所有的边权值之和最大。求出最大权值之和。

* **解题思路**

  我们知道当只有两个点$(i,j)$的时候选择边界一定是最优的，即$max(|r_j - l_i|,|r_i - l_j|)$。

  而有三个点$(i,j,k)$的时候，这里连接顺序为$i — j — k$，设边为$w_{ij}$和$w_{jk}$，我们目的是使得使得$w_{ij}+w_{kj}$最大，其中我们分析一下几种情况。

  * 当$\frac{l_i+r_i}{2}\leq l_j\leq r_j \leq \frac{l_k+r_k}{2}$，则易知此时最优的选择是$a_i=l_i,a_j$取$[l_j,r_j]$任何一个值都可以，这里同样是可以取边界，$a_k=r_k$；
  * 当$l_j \leq \frac{l_i+r_i}{2}\leq r_j \leq \frac{l_k+r_k}{2}$，则此时的最优选择就是$a_i = r_i,a_j= l_j,a_k=r_k$；
  * 当$\frac{l_i+r_i}{2}\leq l_j\leq \frac{l_k+r_k}{2} \leq r_j$，则此时的最优选择就是$a_i=l_i,a_j=r_j,a_k=l_k$；
  * 当$l_j \leq \frac{l_i+r_i}{2}\leq\frac{l_k+r_k}{2}\leq r_j $，则此时的最优选择是$a_i=r_i,a_j=l_j,a_k=r_k$。

  分析可知，==顶点权选择边界一定是最优的，这对更多点的情况依然适用== ，所以我们实际上就是枚举每个顶点究竟该选择哪个边界，这应该就要想到树形$DP$，我们假设$dp[i][0]$为选取左边界，以它为根节点所构成的子树获取的最大边权值之和，而$dp[i][1]$则为选取有边界，以它为根节点所构成的子树获取的最大边权值之和。设当前节点为$i$，孩子节点为$j$，则状态转移方程易知：

  $dp[i][0]+=max(dp[j][0]+|l_i-l_j|,dp[j][1]+|l_i-r_j|)$

  $dp[i][1]+=max(dp[j][0]+|r_i-l_j|,dp[j][1]+|r_i-r_j|)$

  存储树结构我们使用链式前向星，注意，这是一颗无向树，所以我们选取任意一点为根节点都可以，这里选取$1$作为根节点。==这里会卡输入，建议使用scanf和printf输入输出，或者开启IOS==。

# D. Kavi on Pairing Duty

* **题目大意**

  在数轴上有$2n$各点，分别是$1,...,2n$，良好配对数为选择的点对构成的区间$A,B$，其中$A$的长度等于$B$的长度，或者$A$包含$B$。问这最大的配对数。

* **解题思路**

  我们设$dp[i]$表示这$[1,2i]$区间最大的良好配对数目。则易知$dp[n]$就是答案。题目中良好配对存在两种，一种是包含情况，一种是等长情况。

  * 对于包含情况，我们知道对于区间$[i,2i]$，我们将两边点按等长选择上以后，中间的点就可以随便选取了，即如果我们选取$(i,2i)$那么之间的点对一定包含在这个点对里，即$dp[i-1]$，同理,$dp[i-2],...dp[1]$都在其中。
  * 而对于等长情况，区间长度能被点对长度整除，就能选择，即$i$的正约数的集合。

  则我们的状态转移方程易知：$dp[i] = \sum_{k= 1}^idp[k]+v[k]$，其中$v[k]$即为$k$的正约数集合。

* **AC代码**

  
