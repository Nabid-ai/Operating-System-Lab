#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], pr[20], ct[20];
    int tat[20], wt[20], done[20] = {0};
    int min, highest;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter AT, BT and Priority of P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }

    while(completed < n)
    {
        min = 9999;
        highest = -1;

        // Find highest priority arrived process
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && done[i] == 0)
            {
                if(pr[i] < min)
                {
                    min = pr[i];
                    highest = i;
                }
            }
        }

        // CPU idle
        if(highest == -1)
        {
            time++;
            continue;
        }

        // Execute process
        time += bt[highest];

        ct[highest] = time;
        tat[highest] = ct[highest] - at[highest];
        wt[highest] = tat[highest] - bt[highest];

        done[highest] = 1;
        completed++;

        avg_wt += wt[highest];
        avg_tat += tat[highest];
    }

    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
        i + 1, at[i], bt[i], pr[i],
        ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
