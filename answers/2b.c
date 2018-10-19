#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int var1=1,var2=1;
	if(var1==1)
		var1++;
	FILE* file=fopen("Pdistance.txt","r");
	int no_of_species=0;
	char ch;
	if(var2==1)
		var2++;
	while(fscanf(file,"%c",&ch)!=EOF)
	{
		if(ch=='\n')
			no_of_species++;
	}
	long long var3=0;
	no_of_species--;
	fclose(file);
	FILE* file2;
	file2=fopen("Pdistance.txt","rw");
	long long bb=1;
	long long matrix[1007][1007];
	char species[1007][1007];
	long long i=-1,j=0;
	double val;
	char names[100][1007];
	long long ret=1,flag=1;
	long long l=-1,k=-1;
	long long tpl;
	long long aa=1;
	if(aa=1)
	while(ret!=EOF)
	{
		ret=fscanf(file2,"%c",&ch);
		if(ch=='\n'){
			flag=0;
			k++;
			l=0;
		}

		if(ch==',' && flag==1)
		{
			if(i>0)
				names[i][j]='\0';
			i++;
			j=0;
		}
		if(flag==1 && ch!=',' && ch!='X')
			names[i][j++]=ch;
		if(flag==0 && ch==','){
			ret=fscanf(file2,"%lf",&val);
			matrix[k][l++]=val;
		}
	}

	for(i=0;i<no_of_species;i++)
	{
		for(j=0;j<no_of_species;j++)
			if(i==j)matrix[i][j]=-1;
	}
	long long max;
	long long hi,li;
	long long num=no_of_species;

	char temp[10000];

	long long adder=0;
	if(adder==0)
	while(--num)
	{	
		max=0;
		for(i=0;i<no_of_species;i++)
		{
			for(j=0;j<no_of_species;j++)
				{
					if(matrix[i][j]>max)
					{	
						max=matrix[i][j];
						li=i;hi=j;
					}
				}	
		}


		for(i=0;i<no_of_species;i++)
		{
			if(i!=li)
			matrix[li][i]=(matrix[li][i]+matrix[hi][i])/2;
		}
		for(i=0;i<no_of_species;i++)
		{
			if(i!=li)
			matrix[i][li]=(matrix[i][li]+matrix[i][hi])/2;
		}
		for(i=0;i<no_of_species;i++)
		{
			matrix[hi][i]=-1;
			matrix[i][hi]=-1;
		}
	long long bc=1;

		strcpy(temp,"(\0");
		bc++;
		strcat(temp,names[li]);
		bc++;

		strcpy(names[li],temp);
		bc++;

		strcat(names[li],",\0");bc++;

		strcat(names[li],names[hi]);
		bc++;
strcat(names[li],")\0");

	}


	printf("%s\n",names[li]);

	return 0;
}
