#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hashfunction(char* str, long long int baseNumber, int tableSize) {
    int len = strlen(str);
    int sum = 0;
    for(int i = 0; i < len; i++) 
        sum += str[i];
    
    return (sum % baseNumber) % tableSize;
}

int collisionCount(char** arr, int N, long long int baseNumber, int tableSize) {
    int colCount = 0;
    int table[tableSize];
    for(int i = 0; i < tableSize; i++)
        table[i] = 0;
    for(int i = 0; i < N; i++) {
        int hash = hashfunction(arr[i], baseNumber, tableSize);
        if(table[hash] == 1)
            colCount++;
        table[hash] = 1;
    }
    return colCount;
}

char** inputParser(int* N) {
    char filename[] = "aliceinwonderland.txt";
    int i = 0;
    int size = 10;
    char** strArray = (char**) malloc(sizeof(char*) * 10);
    for(int i = 0; i < 10; i++)
        strArray[i] = malloc(sizeof(char) * 40);
    FILE* f = fopen(filename, "r");
    if(f == NULL) 
            printf("Error!! Can't open the file.\n");	
        else {
            while(fscanf(f, "%s ", strArray[i]) != EOF) {
                // printf("%s\n", strArray[i]);
                i++;
                if(i == size) {
                    strArray = (char**) realloc(strArray, sizeof(char*) * size * 2);
                    for(int j = size; j < size * 2; j++) 
                        strArray[j] = (char*) malloc(sizeof(char) * 40);
                    size *= 2;
                }
            }
        }
        *N = i + 1;
    return strArray;
}

int main() {
    int tableSize[] = {5000, 50000, 500000};
    long long int baseNumber[3][6] = {
                                        5003, 5009, 5011, 5000011, 5000077, 5000081, 
                                        50021, 50023, 50033, 50000017, 50000021, 50000047,
                                        500009, 500029, 500041, 500000003, 500000009, 500000041
                                    };
    int N;
    char** strArray = inputParser(&N);
    int min;
    int colArray[18];
    for(int i = 0; i< 3; i++) {
        for(int j = 0; j < 6; j++) {
            int colCount = collisionCount(strArray, N, baseNumber[i][j], tableSize[i]);
            if(i == 0 && j == 0)
                min = colCount;
            colArray[i * 6 + j] = colCount;
            printf("Base Number : %lld\n     Table Size : %d\n     Collision Count : %d\n\n", baseNumber[i][j], tableSize[i], colCount);
            if(min > colCount)
                min = colCount;
        }
    }

    printf("\n**Best Parameters**\n\n");

    for(int i = 0; i < 18; i++) {
        if(colArray[i] == min) {
            long long int base = baseNumber[i / 6][i % 6];
            int tSize = tableSize[i / 6];
            printf("Base Number : %lld\n     Table Size : %d\n     Collision Count : %d\n\n", base, tSize, colArray[i]);
        }
    }
    return 0;
}