#define Less(x, y) x<y
#define Swap(x, y) { int t = x; x = y; y = t;}

void BubbleSort(int a[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = size - 1; j > i; j--)
        {
            if (Less(a[j], a[j + 1]))
            {
                Swap(a[j], a[j+1]);
            }
        }
    }
}