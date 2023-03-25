#include <iostream>
using namespace std;
int main()
{
    int n, f, fault = 0, hit = 0;
    cout << "Array size & F: ";
    cin >> n >> f;
    int a[n], p[f],box=n;
    cout<<"Enter data for arrays\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int j = 0, i = 0,k=0;
    while (box != 0)
    {

        if (i == f)
        {
            i = 0;
        }
        p[i] = a[j];
        i++;
        j++;
        box--;
        fault++;
        for (k = 0; k < f; k++)
        {
            if (a[j] == p[k])
            {
                hit++;
                fault--;
            }
        }
    }
    cout << "Hit: " << hit << " Fault: " << fault-f;
    return 0;
}
