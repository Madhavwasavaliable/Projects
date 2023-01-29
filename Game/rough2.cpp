#include<iostream>

using namespace std;

void changeArray(int [], int *);

int main() {
    int num = 0;
    int *n = &num;

    int arr[5] = {1,2,3,4,5};
+
    while (1)
    {
        if (*n > 5)
        {
            break;
        }
        
        changeArray(arr,n);
        *n = *n + 1;
    }
    
    
}

void changeArray(int arr[], int *n)
{
    cout<<arr[*n];
    cout<<"Hello";
}
