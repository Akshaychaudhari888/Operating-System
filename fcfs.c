#include <stdio.h>
int main() 
{
    int i, j, temp, btemp, at[6], bt[6], wt[6], tt[6], sum = 0, num, proc[6];
    float avrg, avg;

    printf("Enter the number of processes: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        printf("Enter the process number: ");
        scanf("%d", &proc[i]);
        printf("Enter the arrival time for process %d: ", proc[i]);
        scanf("%d", &at[i]);
        printf("Enter the burst time for process %d: ", proc[i]);
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (at[i] > at[j]) {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                btemp = bt[i];
                bt[i] = bt[j];
                bt[j] = btemp;
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }

    printf("\nAfter sorting by arrival time:\n");
    printf("Process\tArrival Time\tBurst Time\n");
    for (i = 0; i < num; i++) {
        printf("P%d\t%d\t%d\n", proc[i], at[i], bt[i]);
    }

    wt[0] = 0;
    for (i = 0; i < num; i++) {
        wt[i + 1] = wt[i] + bt[i];
        sum += (wt[i] - at[i]);
    }

    printf("\nThe total waiting time is: %d\n", sum);
    avrg = (float)sum / num;
    printf("The average waiting time is: %f\n", avrg);

    sum = 0;
    for (i = 0; i < num; i++) {
        tt[i] = wt[i + 1] - at[i];
        sum += tt[i];
    }

    printf("The total turnaround time is: %d\n", sum);
    avg = (float)sum / num;
    printf("The average turnaround time is: %f\n", avg);

    printf("\nGANTT CHART\n");
    printf("------------------------------------------------------------------------------------\n");
    for (i = 0; i < num; i++) {
        printf("| P%d ", proc[i]);
    }
    printf("|\n------------------------------------------------------------------------------------\n");

    for (i = 0; i <=num; i++) {
        printf("%d  ", wt[i]);
    }

    return 0;
}
