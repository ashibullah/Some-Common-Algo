#include <stdio.h>

int main()
{
    int m, n,p,rick=0;
    printf("Processes: ");
    scanf("%d", &m);
    printf("Resources: ");
    scanf("%d",&n);
    int req[n], ins[n], pro[m][n], Max[m][n], Av[m][n], need[m][n], count[n];
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
    puts("Process Number and Request: ");
    scanf("%d",&p);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&req[i]);
    }
    for (int i = 0; i < n; i++)
    {
        rick= rick*10 +req[i];
    }
    if (rick <= ne[p-1] && rick <=c)
    {
        c= c-rick;
        al[p-1] = al[p-1]+rick;
        ne[p-1] = ne[p-1]-rick;
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
                gant[step]= i;
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