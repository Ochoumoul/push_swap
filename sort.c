#include <stdio.h>
#include <stdlib.h>

int biggest(int value1, int value2)
{
    if (value1 > value2)
        return (value1);
    else
        return (value2);
}

int max_value(int *arr, int size)
{
    int max;
    int i;

    i = 0;
    max = 0;
    while (i < size - 1)
    {
        if (arr[i] < arr[i + 1])
            max = arr[i + 1];
        i++;
    }
    return (max);
}

// The time complexity for the algorithm is O(n^2)

int longest_sub(int *arr, int size)
{
    int list[size];
    int i;
    int j;

    list[0] = 1;
    i = 1;
    while(i < size)
    {
        j = 0;
        list[i] = 1;
        while (j < i)
        {
            if (arr[i] > arr[j] && list[i] < list[j] + 1)
            // We could use this condition in order to decide the status
            // of the node that would be inserted
                list[i] = list[j] + 1;
            j++;
        }
        i++;
    }
    return max_value(list, size);
}

// int longest_incresing_sub(int *arr, int size)
// {
//     int list[size];

//     int i;
//     int j;


//     while (i < size)
//     {
//         j = i + 1;
//         while (j < size)
//         {
//             if (arr[i] < arr[j])
//                 list[i] = biggest(list[i], list[j]);
//             j++;
//         }
//         i++;
//     }
//     return (max_value(list));
// }

int main(int argc, char **argv)
{
    int arr[14] = {1, 2, 4, 3, 5, 8, 9, 12, 14, 17, 6, 6, 5, 100};
    int output = longest_sub(arr, 14);
    printf("Final Output: %d\n", output);
    return (0);
}