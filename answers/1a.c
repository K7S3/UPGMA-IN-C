#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define minimum(a,b) (a>b)?b:a
typedef struct species{
	char ID[50];
	char genus[100];
	char species[100];
	char bs[50];
	char seq[1000];
}species;

double matrix[50][50];
int main()
{
	int count=0,i,j,k,l;
	species s[50];
	FILE *fptr;
	FILE *fout;
	fout= fopen("./Ndistance.txt", "w+");
   	if ((fptr = fopen("./Nucleotide.txt","r")) == NULL)
   	{
       printf("Error! opening file");
      // Program exits if the file pointer returns NULL.
       exit(1);
   	}
   	else
   	{
   		while(!feof(fptr))
   		{
   			fscanf(fptr,"%s %s %s %[^\n]",s[count].ID,s[count].genus,s[count].species,s[count].bs);
   			long long i=0;
 
   			while(!feof(fptr))
   			{

   				char character;
   				fscanf(fptr,"%c",&character);
   				if(character=='A'||character=='T'||character=='G'||character=='C')
   				{
   					s[count].seq[i]=character;
   					i++;
   				}
   				else if(character=='>')
   					break;
   				else
   					continue;
   			}			
   			count++;	//Number of species
   		}
   		
 		for(i=0;i<count;i++)
 		{
 			for(j=0;j<count;j++)
 			{ 
   				if(i<j)
 				{long long no_of_mismatches=0;
 				long long length1=strlen(s[i].seq);
 				long long length2=strlen(s[j].seq);
 //				printf("%lld %lld\n",length1,length2 );
 				long long min_length=minimum(length1,length2);
 				long long min_mismatch=min_length;
 				if(length1>length2)
 				for(l=0;l<=length1-length2;l++)
 				{
 					no_of_mismatches=0;
 					for(k=0;k<min_length;k++)
 					{
 						if(s[i].seq[k+l]!=s[j].seq[k])
 							no_of_mismatches++;
 //						printf("%c",s[i].seq[k+l]);
 					}
 //					printf("\n%lld\n",no_of_mismatches);	
 					if(no_of_mismatches<min_mismatch)
 						min_mismatch=no_of_mismatches;
 				}
 				else
 				for(l=0;l<=length2-length1;l++)
 				{
 					no_of_mismatches=0;
 					for(k=0;k<min_length;k++)
 					{
 						if(s[i].seq[k]!=s[j].seq[k+l])
 							no_of_mismatches++;
 //						printf("%c",s[j].seq[k+l]);
 					}
//printf("\n%lld\n",no_of_mismatches);	
 					if(no_of_mismatches<min_mismatch)
 						min_mismatch=no_of_mismatches;
 				}
 				double Value_entered=(double)min_mismatch/(double)min_length;
 				matrix[i][j]=Value_entered;
 				matrix[j][i]=Value_entered;			//Symmetric Matrix
 			}}
 		}
 		

 		fprintf(fout,"* ");
 		for(i=0;i<count;i++)
 		fprintf(fout,"%s %s,",s[i].genus,s[i].species);
 		fprintf(fout,"\n");
  		for(i=0;i<count;i++)
 		{
 			fprintf(fout,"%s %s,",s[i].genus,s[i].species);
 			for(j=0;j<count ;j++)
 				{
          if(j==i)
            fprintf(fout,"%f",matrix[i][j]);
         else
          fprintf(fout,"%f,", matrix[i][j] );
        }
 			fprintf(fout,"\n");
 		}

   	}
	return 0;
}
