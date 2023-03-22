# Program NilaiEkstrim
# Menerima masukan integer N (0 < N <= 100) dan membaca N buah integer yang kemudian disimpan ke dalam suatu array.
# Menerima masukan integer X dan mengecek apakah X merupakan nilai ekstrim pada array.

# KAMUS
# N, i, X, count, count_max, count_min : int
# arr : array of int

# ALGORITMA
# Fungsi maksimum
def maksimum(arr):
    # Mengembalikan nilai maksimum pada arr

    # KAMUS LOKAL
    # Max : int

    # ALGORITMA
    Max = arr[0]
    for i in range(N):
        if (arr[i] > Max):
            Max = arr[i]
    return Max

# Fungsi minimum
def minimum(arr):
    # Mengembalikan nilai minimum pada arr

    # KAMUS LOKAL
    # Min : int

    # ALGORITMA
    Min = arr[0]
    for i in range(N):
        if (arr[i] < Min):
            Min = arr[i]
    return Min

N = int(input())
arr = [0 for i in range(N)]
for i in range(N): 
    arr[i] = int(input())

X = int(input())
count = 0
count_max = 0
count_min = 0
for i in range(N):
    if (arr[i] == X):
        if (X == maksimum(arr)):
            count_max += 1
        if (X == minimum(arr)):
            count_min += 1
    else:
        count += 1

if (count_max >= 1):
    print("maksimum")
if (count_min >= 1):
    print("minimum")
if (count_max == 0) and (count_min == 0):
    if (count == N):
        print(X, "tidak ada")
    else:    
        print("N#A")