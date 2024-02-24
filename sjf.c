#include <stdio.h>

// Structure to represent a process
struct Process 
{
    int id;             // Process ID
    int burst_time;     // Burst time of the process
    int arrival_time;   // Arrival time of the process
    int executed;       // Flag to track if process has been executed
};

int main() 
{
    int n, i, total_burst_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input details for each process
    for (i = 0; i < n; i++) 
    {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].id = i + 1;
        processes[i].executed = 0;
        total_burst_time += processes[i].burst_time;
    }

    int current_time = 0;
    printf("\nGantt Chart:\n");
    while (current_time < total_burst_time) 
    {
        int shortest_job = -1;
        int shortest_burst = 9999; // Initializing with a large value

        // Find the shortest job available at current time
        for (i = 0; i < n; i++) 
        {
            if (processes[i].arrival_time <= current_time && processes[i].executed == 0) 
            {
                if (processes[i].burst_time < shortest_burst) 
                {
                    shortest_burst = processes[i].burst_time;
                    shortest_job = i;
                }
            }
        }

        if (shortest_job == -1) 
        {
            printf("CPU idle at time %d\n", current_time);
            current_time++;
        } else 
        {
            // Execute the shortest job
            printf("P%d ", processes[shortest_job].id);
            processes[shortest_job].burst_time--;
            current_time++;

            // Mark the process as executed if it has completed
            if (processes[shortest_job].burst_time == 0) 
            {
                processes[shortest_job].executed = 1;
            }
        }
    }
    printf("\n");

    return 0;
}
