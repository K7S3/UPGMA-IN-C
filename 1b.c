#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{

	FILE* file=fopen("Ndistance.txt","r");
	int no_of_species=0;
	char ch;
	while(fscanf(file,"%c",&ch)!=EOF)
	{
		if(ch=='\n')no_of_species++;
	}
	no_of_species--;
	fclose(file);
	FILE* file2;
	file2=fopen("Ndistance.txt","r");

	double matrix[1000][1000];
	char species[1000][1000];
	int i=-1,j=0;
	double val;
	char names[100][1000];
	int ret=1,flag=1;int l=-1,k=-1;
	int tpl;
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
			if(i==j)matrix[i][j]=1;
	}
	double min;int hi,li;
	int num=no_of_species;
//	char st[1000]="\0";
	char temp[10000];
//	char tmp[10000];
//	flag=0;
//	int added[1000]={0};
	while(--num)
	{	
		min=1;
		for(i=0;i<no_of_species;i++)
		{
			for(j=0;j<no_of_species;j++)
				{
					if(matrix[i][j]<min)
					{	
						min=matrix[i][j];
						li=i;hi=j;
					}
				}	
		}

//		printf("Low:%d High:%d\n",li,hi);

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
			matrix[hi][i]=1;
			matrix[i][hi]=1;
		}

		strcpy(temp,"(\0");
		strcat(temp,names[li]);
		strcpy(names[li],temp);
		strcat(names[li],",\0");
		strcat(names[li],names[hi]);
		strcat(names[li],")\0");

	}


	printf("%s\n",names[li]);

	return 0;
}
