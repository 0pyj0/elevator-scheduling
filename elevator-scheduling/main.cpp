#include<iostream>
#include<fstream>
#include<math.h>
#include"elevator.cpp"
using namespace std;
int main()
{
	int a[10000],b[10000],c[10000],i,j,n,s=0;
	dianti dt[1000];
	ifstream infile("input.txt");
	ofstream outfile("output.txt");
	infile>>n;
	for(i=0;i<n;i++)
	{
		infile>>a[i];
		infile>>b[i];
		infile>>c[i];
	}
	s=a[0]+b[0];//将第一个请求的起始楼层输出
	outfile<<s<<" "<<b[0]<<endl;
	for(i=1;i<n;i++)
	{
		s=s+1+dt[i].time(b[i-1],c[i-1]);
		if(s>=a[i])//当电梯完成上一个请求之前，下一个请求已经开始的时候
		{
			s=s+1+dt[i].time(b[i],c[i-1]);
			b[i+1]=c[i];
			outfile<<s-1<<" "<<b[i]<<endl;
		}
		else//当上一个请求结束了以后，下一个请求还没出现，先向下一个地点走，当s=a时，再接着计时
		{
			if(dt[i].time(b[i],c[i])>(s-a[i]))
			s=a[i]+1+(dt[i].time(b[i],c[i-1])-s+a[i]);
			else
			s=s+a[i]+1;
			b[i+1]=c[i];
			outfile<<s-1<<" "<<c[i]<<endl;
		}
	}
	return 0;
}
