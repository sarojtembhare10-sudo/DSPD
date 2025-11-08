#include <stdio.h>

int main() {
    int n, i;
    int Esum = 0, Osum = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (i % 2 == 0)
            Esum += arr[i];
        else
            Osum += arr[i];
    }

    printf("\nSum of even index elements = %d", Esum);
    printf("\nSum of odd index elements  = %d\n", Osum);

    return 0;
}