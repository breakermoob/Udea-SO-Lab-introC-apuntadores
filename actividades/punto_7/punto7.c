#include <stdio.h>

void shell_sort(float a[], int n);


int main(int argc, char const *argv[]){

    float school[4][5] = {
        {1.2, 2.5, 5, 4.6, 4.8},
        {5, 5, 4.8, 4.6, 4},
        {3.5, 4.8, 4.9, 2, 5},
        {4.2, 4, 3.5, 5, 4}};

    float students[4]={0,0,0,0};
    float acum = 0;

    //Promedio de cada estudiante
    printf("%s", "Promedio de cada estudiante:  ");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            acum += school[i][j];
        }
        acum = acum / (float)4;
        printf("%f", acum);
        students[i]=acum;
        printf("%s", "  ");
        acum = 0;
    }
    printf("%s", "\n");

    //Promedio de cada asignatura
    printf("%s", "Promedio de cada asignatura:  ");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            acum += school[j][i];
        }
        printf("%f", acum / (float)4);
        printf("%s", "  ");
        acum = 0;
    }
    printf("%s", "\n");

    //Promedio de clase
    printf("%s", "Promedio de clase:  ");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            acum += school[j][i];
        }
    }
    printf("%f", acum / (float)20);
    printf("%s", "  ");
    printf("%s", "\n");


    //Estudiantes ordenados
    shell_sort(students, 4);
    printf("%s", "Estudiantes ordenados:  ");
    for (int i = 0; i < 4;i++){
        printf("%3f", students[i]);
        printf("%s", "  ");
    }
    printf("%s", "\n");


    return 0;
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
                if(tmp > a[j-increment])
                    a[j] = a[j-increment];
                else
                    break;
            }
            a[j] = tmp;
        }
    }
}
