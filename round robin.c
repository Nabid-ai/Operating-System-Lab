#include <stdio.h>

int main()
{
    int n, tq, i, time = 0, completed = 0;
    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20];
    int visited[20] = {0};
    int queue[1000], front = 0, rear = 0;
    int p;

    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Arrival Time and Burst Time of P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);

        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    // Add processes arriving at time 0
    for(i = 0; i < n; i++)
    {
        if(at[i] == 0)
        {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while(completed < n)
    {
        // CPU idle condition
        if(front == rear)
        {
            time++;

            for(i = 0; i < n; i++)
            {
                if(at[i] <= time && visited[i] == 0)
                {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        // Select process from queue
        p = queue[front++];

        // Execute process
        if(rt[p] > tq)
        {
            time += tq;
            rt[p] -= tq;
        }
        else
        {
            time += rt[p];
            rt[p] = 0;

            ct[p] = time;
            completed++;

            tat[p] = ct[p] - at[p];
            wt[p] = tat[p] - bt[p];

            avg_tat += tat[p];
            avg_wt += wt[p];
        }

        // Add newly arrived processes
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        // Add unfinished process to end of queue
        if(rt[p] > 0)
        {
            queue[rear++] = p;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}

#include <stdio.h>

int main()
{
    int n, tq, i, time = 0, completed = 0;
    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20];
    int visited[20] = {0};
    int queue[1000], front = 0, rear = 0;
    int p;

    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Arrival Time and Burst Time of P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);

        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    // Add processes arriving at time 0
    for(i = 0; i < n; i++)
    {
        if(at[i] == 0)
        {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while(completed < n)
    {
        // CPU idle condition
        if(front == rear)
        {
            time++;

            for(i = 0; i < n; i++)
            {
                if(at[i] <= time && visited[i] == 0)
                {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        // Select process from queue
        p = queue[front++];

        // Execute process
        if(rt[p] > tq)
        {
            time += tq;
            rt[p] -= tq;
        }
        else
        {
            time += rt[p];
            rt[p] = 0;

            ct[p] = time;
            completed++;

            tat[p] = ct[p] - at[p];
            wt[p] = tat[p] - bt[p];

            avg_tat += tat[p];
            avg_wt += wt[p];
        }

        // Add newly arrived processes
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        // Add unfinished process to end of queue
        if(rt[p] > 0)
        {
            queue[rear++] = p;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}