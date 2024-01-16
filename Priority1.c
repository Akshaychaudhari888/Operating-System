//correct code
//Priority Non-Preempitive....................
#include<stdio.h>
void main()
{
    int i,j,temp,btemp,ptemp,at[6],bt[6],wt[6],tt[6],sum=0,num,proc[6],pr[6];
    float avrg,avg;
    printf("Enter No.of process:");
    scanf("%d",&num);
    for(i=0;i<num;i++)
   {
     printf("\nEnter the process No:");
     scanf("%d",&proc[i]);
     printf("\nEnter A.T:");
      scanf("%d",&at[i]);
     printf("\nEnter B.T:");
      scanf("%d",&bt[i]);
     printf("\nEnter the Priority:");
    scanf("%d",&pr[i]);
   }
  for(i=0;i<num;i++)
  {
   for(j=i+1;j<num;j++)
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
for(i=1;i<num;i++)
  {
      for(j=i+1;j<num;j++)
        {
            if(pr[i]>pr[j])
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
                   ptemp=pr[i];
                  pr[i]=pr[j];
                   pr[j]=ptemp;
              }
}
}
for(i=1;i<num;i++)
{
  for(j=i+1;j<num;j++)
{
       if(pr[i]==pr[j])
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
         proc[j]=temp;
          ptemp=pr[i];
         pr[i]=pr[j];
         pr[j]=ptemp;
      }
}
}
}
printf("\nafter Sorting an A.T\n");
 printf("Process\tA.T\tB.T\tPriority\n");
  for(i=0;i<num;i++)
 {
    printf("\nP%d\t",proc[i]);
      printf("%d\t",at[i]);
    printf("%d\t",bt[i]);
    printf("%d\t",pr[i]);
}
wt[0]=0;
for(i=0;i<num;i++)
{
      wt[i+1]=wt[i]+bt[i];
       sum+=(wt[i]-at[i]);
  }
wt[num]=wt[num-1]+bt[num-1];
 printf("\nThe W.T is \t%d",sum);
  avrg=(float)sum/(float)num;
   printf("\nThe A.W.T is \t%f",avrg);
    sum=0;
    for(i=0;i<num;i++)
{
      tt[i]=wt[i+1]-at[i];
       sum+=tt[i];
 }
printf("\nSum of turnaround time is \t%d",sum);
 avg=(float)sum/(float)num;
printf("\nThe average turnaround time is\t%f",avg);
 printf("\nGANT CHART\n");
 printf("\n------------------\n");
for(i=0;i<num;i++)
{
 printf("|P%d\t",proc[i]);
}
printf("\n-------------------------\n");
for(i=0;i<=num;i++)
{
    printf("%d\t",wt[i]);
}
}
}
                       
     
