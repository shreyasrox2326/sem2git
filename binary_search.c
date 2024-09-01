#include <stdio.h>
int search(int n, int array[100], int start, int end)
{
    int len = end - start;
    if (len == 1)
    {
        if (array[start] == n)
            return start;
        else
            return -1;
    }
    else
    {
        int mid = (end + start) / 2;
        if (array[mid] > n)
        {
            return (search(n, array, start, mid));
        }
        else if (array[mid] < n)
        {
            return (search(n, array, mid, end));
        }
        else if (array[mid] == n)
        {
            if (search(n, array, start, mid) == -1)
                return mid;
            else
                return search(n, array, start, mid);
        }
    }
}
int main(void)
{

    int nums[100], n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("element %d: ", i);
        scanf("%d", &nums[i]);
    }
    while (1)
    {
        printf("Enter target: ");
        scanf("%d", &target);
        printf("%d\n", search(target, nums, 0, n));
        if (search(target, nums, 0, n) == -1)
            break;
    }
    return 0;
}
