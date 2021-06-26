#include<stdio.h>
#include<stdlib.h>

void toh(int,char,char,char);

int main()
{
    int n;
    printf("Enter the number of disk:");
    scanf("%d",&n);
    toh(n,'A','B','C');
}

void toh(int n, char source , char aux , char destination)
{
    if(n==1)
    	printf("\nMove disk from %c to %c",source,destination);
    else
    {
        toh(n-1,source,destination,aux);
        toh(1,source,aux,destination);
        toh(n-1,aux,source,destination);
    }
}
