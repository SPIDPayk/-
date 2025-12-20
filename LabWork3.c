#include<stdio.h>
#include <stdlib.h>

void print_arr(int** arr, int N, int M){
    printf("\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

}


int main(int argc, char* argv[]){
    int S = 0; //sum

    if (argc <= 1) {printf("File name not given"); return 1;}

    FILE* fp = fopen(argv[1],"r+");
    if (fp == NULL) {
    printf("Error occured while opening file");
    return 1;
    }

    int N, M;
    if (fscanf(fp, "%d %d", &N, &M) != 2) {
        printf("Two integers expexted\n");
        fclose(fp);
        return 1;
    }
    printf("The size of matrix is: %d%c%d",N,'x',M);

    int **arr = (int**)malloc(N *sizeof(int));
    for (int i = 0;i < N; i++){
        arr[i] = (int*)malloc(M*sizeof(int));
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (fscanf(fp, "%d", &arr[i][j]) != 1) {
                
                for (int k = 0; k < N; k++) {
                    free(arr[k]);
                }
                free(arr);
                fclose(fp);
                return 1;
            }
        }
    }
    
    print_arr(arr,N,M);

    int min;
    if(M == N){min = M;} else if (N < M){min = N;} else { min = M;}
    
    for (int i = 0; i < min; ++i){
        S += arr[i][i];
    }
    printf("The sum is: %d", S);
    

    int max = 0;
    int indx = 0;
    for (int i = 0; i < M; ++i){
        if (arr[2][i] > max) {max = arr[2][i]; indx = i; }
    }
    int tmp = S;
    S = arr[2][indx];
    arr[2][indx] = tmp;

    print_arr(arr,N,M);

    

    return 0;
}