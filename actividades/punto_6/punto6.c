#include <stdio.h>

void shell_sort(float a[], int n);
void print(float a[]);
float mean(float a[], int n);
float median(float a[], int n);

int main(int argc, char const *argv[]) {
  float arr[3] = {3,1,2};
  shell_sort(arr, 3);

  printf("%f", mean(arr, 3));
  printf("%s", "\n");
  printf("%f", median(arr, 3));
  printf("%s", "\n");

  return 0;
}

float mean(float a[], int n) {
  float acum = 0;
  for (int i = 0; i < n; i++) {
    acum += a[i];
  }
  return acum / (float) n;
}

float median(float a[], int n) {
  return a[n/2];
}

void print(float a[]) {
  for (int i = 0; i < 7;i++) {
    printf("%f", a[i]);
    printf("%s", " ");
  }
    printf("%s", "\n");
}

/*
  Taken from https://www.programming9.com/programs/c-programs/234-c-program-for-shell-sort
*/
void shell_sort(float a[], int n) {
    int i, j, increment;
    float tmp;
    for(increment = n/2; increment > 0; increment /= 2)
    {
        for(i = increment; i < n; i++)
        {
            tmp = a[i];
            for(j = i; j >= increment; j -= increment)
            {
                if(tmp < a[j-increment])
                    a[j] = a[j-increment];
                else
                    break;
            }
            a[j] = tmp;
        }
    }
}
