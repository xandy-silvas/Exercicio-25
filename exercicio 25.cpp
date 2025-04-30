#include <stdio.h>

int busca_binaria(int arr[], int baixo, int alto, int x) {
    if (baixo > alto)
        return -1;
    
    int meio = baixo + (alto - baixo) / 2;
    
    if (arr[meio] == x)
        return meio;
    
    if (arr[meio] > x)
        return busca_binaria(arr, baixo, meio - 1, x);
    
    return busca_binaria(arr, meio + 1, alto, x);
}

int main() {
    int n, i, elemento;
    
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Digite os %d elementos do array EM ORDEM CRESCENTE:\n", n);
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
        
        if (i > 0 && arr[i] < arr[i-1]) {
            printf("Os elementos devem estar em ordem crescente!\n");
            return 1;
        }
    }
    
    printf("Digite o elemento a buscar: ");
    scanf("%d", &elemento);
    
    int indice = busca_binaria(arr, 0, n - 1, elemento);
    
    if (indice != -1)
        printf("O elemento %d foi encontrado no indice %d.\n", elemento, indice);
    else
        printf("O elemento %d nao foi encontrado no array.\n", elemento);
    
    return 0;
}
