//sjf correct code
#include<stdio.h>
void main()
{
	int i,j,temp,btemp,at[6],bt[6],wt[6],tt[6],sum=0,num,proc[6];
	float avrg,avg;
	printf("\nenter the number of process");
	scanf("%d",&num);
	for(i=0;i<num;i++)
     {
		printf("\n Enter the process number:");
		scanf("%d",&proc[i]);
		printf("\n Enter the process arrival time:");
		scanf("%d",&at[i]);
		printf("\n Enter the process burst time:");
		scanf("%d",&bt[i]);
	 }
    for(i=0;i<num;i++)
    {
	  if(at[i]==0)
	    {
				temp=at[i];
				at[i]=at[j];
				at[j]=temp;
				btemp=bt[i];
				bt[i]=bt[j];
				bt[j]=btemp;
				temp=proc[i];
				proc[i]=proc[j];
				proc[j]=temp;
	    }
	}

     for(i=1;i<num;i++)
     {
     	for(j=i+1;j<num;j++)
	   {
		 if(bt[i]==bt[j])
		{
			if(at[i]>at[j])
			{
				temp=at[i];
				at[i]=at[j];
				at[j]=temp;
				btemp=bt[i];
				bt[i]=bt[j];
				bt[j]=btemp;
				temp=proc[i];
				proc[i]=proc[j];
				proc[j]=temp;
			}
		}
        else
		{
			if(bt[i]>bt[j])
		{
				temp=at[i];
				at[i]=at[j];
				at[j]=temp;
				btemp=bt[i];
				bt[i]=bt[j];
				bt[j]=btemp;
				temp=proc[i];
				proc[i]=proc[j];
				proc[j]=temp;
		}
	}
}
}
    printf("\n After sorting arrival time\n");
	printf("process\t arrival time\t burst time\n");
	for(i=0;i<num;i++)
	{
		printf("\nP%d\t",proc[i]);	
		printf("%d\t",at[i]);
		printf("%d\t",bt[i]);
	}
	wt[0]=0;
	for(i=0;i<num;i++)
	{
		wt[i+1]=wt[i]+bt[i];
		sum+=(wt[i]-at[i]);
	}
	wt[num]=wt[num-1]+bt[num-1];
	printf("\n the waiting is \t%d",sum);
	avrg=(float)sum/(float)num;
	printf("\n the waiting time is \t%f",avrg);
	sum=0;
	for(i=0;i<num;i++)
	{
		tt[i]=wt[i+1]-at[i];
		sum+=tt[i];
	}
	printf("\n the sum of turnaround time is \t%d",sum);
	avg=(float)sum/(float)num;
	printf("\n the avrg turnaround time is \t%f",avg);
	printf("n GANTT CHART \n");
	printf("\n------------------------------------------------------------------------------------\n");
	for(i=0;i<num;i++)
	{
		printf("|p%d\t",proc[i]);
	}
	printf("\n------------------------------------------------------------------------------------\n");
	for(i=0;i<=num;i++)
	{
		printf("%d\t",wt[i]);
	}
}

