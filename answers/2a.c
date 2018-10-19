#include<stdio.h>
#include <limits.h>
#include<math.h>
#include<stdlib.h>
long long int arr[26][26],num;
char protein[26];
long long int check(char ch)
{
	long long int val=(long long int)ch;
	if(val>=65 && val<=90)
		return 1;
	return 0;
}

long long int funct(char a,char b)
{
	long long int aa,bb;
	for(int i=0;i<num;i++)
	{
		if(protein[i]==a)
			aa=i;
		if(protein[i]==b)
			bb=i;
	}
	return arr[aa][bb];
}
long long int main()
{
	FILE *file1=fopen("BLOSUM62.txt","r");
	char c;
	long long int i=0,j=0,varcheck=0;
	while(fscanf(file1,"%c",&c)!=EOF)
	{
		if(!varcheck)
		{
			if(check(c)!=0)
			{
				protein[i]=c;
				i++;
			}
		}
		if(varcheck==0 && c=='\n')
		{
			varcheck=1;
			num=i;
			i=0;
		}
		else if(varcheck==1)
		{
			fscanf(file1,"%lld",&arr[i][j++]);
			if(j==num)
			{
				while(c!='\n')
				{
					fscanf(file1,"%c",&c);
				}
				i++;
				j=0;
			}
			if(i==num)
				break;
		}
	}
	fclose(file1);
	FILE *file2=fopen("Protein.txt","r");
	char seq[100][1000],names[100][100];
	long long int len[100];
	i=-1;
	j=0;
int var1=0;
var1++;
	varcheck=0;
	while(fscanf(file2,"%c",&c)!=EOF)
	{
		if(c=='>')
		{	
			if(i>=0)
				len[i]=j;
			varcheck=1;
			i++;
		}
		else if(varcheck==1 && c=='[')
		{
			j=0;
			while(c!=']')
			{
				fscanf(file2,"%c",&c);
				names[i][j]=c;
				++j;
			}
			names[i][j-1]='\0';
		}
		else if(varcheck==1 && c=='\n')
		{
			varcheck=0;

			j=0;
		
		}
		else if(varcheck==0)
		{
			if(check(c))
			{
				seq[i][j++]=c;

			}
		}
	}
	len[i]=j;
	long long int numbers=i+1,values[100][100],sl,ll,max=0,k,p,q,value;
	for(i=0;i<numbers;i++)
	{
		for(j=0;j<numbers;j++)
		{
			max=INT_MIN;
			if(len[i]<len[j]){
				for(k=0;k<=(len[j]-len[i]);k++)
				{
					value=0;
					for(p=0,q=k;p<len[i];p++,q++)
					{
						value+=funct(seq[i][p],seq[j][q]);
					}
					if(max<value)
					{
						max=value;
					}
				}
			}
			else{
				for(k=0;k<=(len[i]-len[j]);k++)
				{
					value=0;
					for(p=0,q=k;p<len[j];p++,q++)
					{
						value+=funct(seq[j][p],seq[i][q]);
					}
					if(value>max)max=value;
				}
			}
			values[i][j]=max;
		}
	}
	printf("X,");
	for(i=0;i<numbers;i++)
	{
		if(i==numbers-1){printf("%s",names[i]);continue;}
		printf("%s,",names[i]);
	}
	printf("\n");	
	for(i=0;i<numbers;i++)
	{
		printf("%s,",names[i]);
		for(j=0;j<numbers;j++)
		{
			if(j==numbers-1){printf("%lld",values[i][j]);continue;}
			printf("%lld,",values[i][j]);
		}
		printf("\n");
	}
	return 0;
}
