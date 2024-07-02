#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>add(vector<int>&a,vector<int>&b)
{
	//这题不能只处理最低位 因为进位可能引起一连串反应 
	//得处理最高位 
if(a.size()<b.size())return add(b,a);
vector<int>ans;
int t=0;
for(int i=0;i<a.size();i++)
{
	int c=t+a[i];
	if(i<b.size())c+=b[i];
	ans.push_back(c%10);
	t=c/10;
}
if(t)ans.push_back(t);
reverse(ans.begin(),ans.end());
return ans;
}
bool cmp(vector<int>&a,vector<int>&b)
{
if(a.size()!=b.size())return a.size()>b.size();
 for(int i=0;i<a.size();i++)
 if(a[i]!=b[i])return a[i]>b[i];
 return 0;
}
vector<int>sub(vector<int>&a,vector<int>&b)
{
vector<int>ans;
for(int i=0;i<a.size();i++)
{
	    int c=a[i];
	    if(i<b.size())c-=b[i];
	      	if(c<0)a[i+1]--,c+=10;
	      	ans.push_back(c);
}            
while(ans.size()>1&&ans.back()==0)//没有进位 只用删0 
ans.pop_back();
reverse(ans.begin(),ans.end());
return ans; 
}
vector<int>mul(vector<int>&a,int b)
{
vector<int>ans;int t=0;
for(int i=0;i<a.size()||t;i++)
{
	if(i<a.size())t=t+a[i]*b;
	ans.push_back(t%10);
	t/=10;
}
//while(ans.size()>1&&ans.back()==0)ans.pop_back();
reverse(ans.begin(),ans.end());
return ans;
}
vector<int>div_(vector<int>&a,int b)//保证除得尽 所以不用||r 
{
vector<int>ans;int r=0;
for(int i=0;i<a.size();i++)
{
	r=r*10+a[i];
    ans.push_back(r/b);
    r%=b;
}
reverse(ans.begin(),ans.end());
while(ans.size()>1&&ans.back()==0)ans.pop_back();
return ans;
}
int main()
{
	vector<int>a,b;
string s1,s2;
//cin>>s1>>s2;
int c;
cin>>s1>>c;
int flag=0;vector<int>ans;
for(int i=0;i<s1.length();i++)a.push_back(s1[i]-'0');
//for(int i=0;i<s2.length();i++)b.push_back(s2[i]-'0');
//flag=cmp(a,b);vector<int>ans;
//要reverse a b 才能算 
//reverse(a.begin(),a.end());//reverse(b.begin(),b.end()); 
/*if(flag||a==b)//a>=b都不输出符号 
{
	ans=sub(a,b);for(auto t:ans)cout<<t;
}
else {
	cout<<'-';
	ans=sub(b,a);for(auto t:ans)cout<<t;
}*/
ans=div_(a,c);
for(int i=ans.size()-1;i>=0;i--)cout<<ans[i];
}
