#include <stdio.h>

    /*
        Inputs
        0 1 0
        2 0 0
        3 0 2
        2 1 1
        0 0 2

        7 5 3
        3 2 2
        9 0 2
        2 2 2
        4 3 3

        3 3 2
    */
int main()
{
    int m, n;
    printf("Processes: ");
    scanf("%d", &m);
    printf("Resources: ");
    scanf("%d",&n);
    int ins[n], pro[m][n], Max[m][n], Av[m][n], need[m][n], count[n];
    int c = 0, ne[m], ave[m], maaax[m], al[m], finish[m];
    // taking input
    printf("Instances of\n");
    for (int i = 0; i < n; i++)
    {
        printf("%c ",65+i);
    }
    puts("");
    
    for (int i = 0; i < n; i++) // ins
    {
        scanf("%d", &ins[i]);
    }
    puts("Allocations of");
    for (int i = 0; i < n; i++)
    {
        printf("%c ",65+i);
    }
    puts("");
    for (int i = 0; i < m; i++) // allocations
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &pro[i][j]);
        }
    }

    puts("Max of"); // Input max
    for (int i = 0; i < n; i++)
    {
        printf("%c ",65+i);
    }
    puts("");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &Max[i][j]);
        }
    }
    printf("Available\n");
    for (int i = 0; i < n; i++)
    {
        printf("%c ",65+i);
    }
    puts("");
    for (int j = 0; j < n; j++) // available
    {
        scanf("%d", &Av[0][j]);
        count[j] = Av[0][j];
    }
    // Find Out Need
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            need[i][j] = Max[i][j] - pro[i][j];
        }
    }
    // converting available storing it in c & instance in c
    for (int i = 0; i < n; i++) // av 7 5 3 =753
    {
        c = c * 10 + count[i];
    }
    /* 
    for (int i = 0; i < sizeof(count) / sizeof(count[0]); i++)
    { 
        d = d * 10 + ins[i];
    }
    */
    // convert need and alocation
    for (int i = 0; i < m; i++)
    {
        int num=0;
        for (int j = 0; j < n; j++)
        {
            num = num * 10 + need[i][j];
        }
        ne[i]=num;
    }
    for (int i = 0; i < m; i++)
    {   int num=0;
        for (int j = 0; j < n; j++)
        {
            num = num * 10 + pro[i][j];
        }
        al[i]=num;
    }
    

    int step=0,gant[m];
    while (step<m)
    {
        for (int i = 0; i < m; i++)
        {
            if (ne[i] <= c && finish[i]!=1 )
            {
                c = c + al[i];
                finish[i] = 1;
                gant[step]= i+1;
                step++;
   
            }
        }
        
    }

    // printf("%d  ", step);
    puts("Process Schedule Gant Chart");
    for (int i = 0; i < m; i++)
        {
            printf("[P%d] ", gant[i]);
        }
    puts("\nBoolean Value of Finish");
    for (int i = 0; i < m; i++)
        {
            printf("[ %d ]", finish[i]);
        }
        getchar();
   
    return 0;
}

 //     puts("");
    // for (int i = 0; i < 5; i++)
    //     {
    //         printf("%d ", ne[i]);
    //     }
    /* int finished = 0;
    while (finished < m)
    {
        // try to find a process that can be finished
        int found = 0;
        for (int i = 0; i < m; i++)
        {
            if (finish[i] == 0)
            {
                int can_finish = 1;
                for (int j = 0; j < n; j++)
                {
                    if (need[i][j] > count[j])
                    {
                        can_finish = 0;
                        break;
                    }
                }
                if (can_finish)
                {
                    // mark the process as finished and update available resources
                    finish[i] = 1;
                    for (int j = 0; j < n; j++)
                    {
                        count[j] += pro[i][j];
                    }
                    found = 1;
                    finished++;
                }
            }
        }
       
        if (!found)
        {
            printf("Unsafe state detected\n");
            break;
        }
    }
    */

    /*
    int d = equal(ins,count,n);
    while (d==1)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (need[i][j]<=count[j])
                {


                }


            }
        }
    }
    */
