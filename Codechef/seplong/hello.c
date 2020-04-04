int arr[51][51];
for (int i = 0; i < 51; ++i) arr[i][0] = 1;
for (int i = 0; i < 51; ++i) arr[i][1] = i;
for (int i = 1; i < 51; ++i)
    for (int j = 1; j < 51; ++J)
        arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
