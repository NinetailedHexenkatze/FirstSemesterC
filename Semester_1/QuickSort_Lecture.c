#define Less(x, y) x<y
#define Swap(x, y) { int t = x; x = y; y = t;}

void SelectionSortLecture(int a[], int size)
{
    int k = 0;
    for (int i = 0; i < size - 1; i++)
    {
        k = i;
        for (int j = i + 1; j < size; j++)
        {
            if (Less(a[j], a[k]))
            {
                k = j;
            }
            Swap(a[i], a[k]);
        }
    }
}

void QuickSortLecture(int a[], int l, int r)
{
    int i = l;
    int j = r;
    int p = a[(l+r)/2];
    while (Less(a[i], p))
    {
        i++;
    }
    while (Less(p, a[j]))
    {
        j--;
    }
    if (i <= j)
    {
        Swap(a[i], a[j]);
        i++;
        j--;
    }
}
