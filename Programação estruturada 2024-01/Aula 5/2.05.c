// função recursiva para somar o n primeiros elementos de Vet, para encontrar o maior elemento de Vet e para inverter Vet
#include <stdio.h>

#define MAX 10

int VetSoma(int A[], int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else
    {
        return A[n - 1] + VetSoma(A, n - 1);
    }
}

int VetMaior(int A[], int n)
{
    if (n == 1)
    {
        return A[0];
    }
    else
    {
        int maior = VetMaior(A, n - 1);
        return (A[n - 1] > maior) ? A[n - 1] : maior;
    }
}

void VetInv(int A[], int inic, int fim)
{
    if (inic < fim)
    {
        int temp = A[inic];
        A[inic] = A[fim];
        A[fim] = temp;
        VetInv(A, inic + 1, fim - 1);
    }
}

int main()
{
    int Vet[MAX];
    int n;

    printf("Informe os %d numeros do vetor:\n", MAX);
    for (int i = 0; i < MAX; ++i)
    {
        scanf("%d", &Vet[i]);
    }

    printf("Quantos elementos deseja somar? ");
    scanf("%d", &n);
    printf("Soma dos primeiros %d elementos: %d\n", n, VetSoma(Vet, n));

    printf("Maior elemento: %d\n", VetMaior(Vet, MAX));

    printf("Vetor original: ");
    for (int i = 0; i < MAX; ++i)
    {
        printf("%d ", Vet[i]);
    }
    printf("\n");

    VetInv(Vet, 0, MAX - 1);

    printf("Vetor invertido: ");
    for (int i = 0; i < MAX; ++i)
    {
        printf("%d ", Vet[i]);
    }
    printf("\n");

    return 0;
}
