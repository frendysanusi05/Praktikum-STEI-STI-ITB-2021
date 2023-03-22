# Program Sort
# Menerima bilangan N dan N buah bilangan yang disimpan di sebuah array
# Mengurutkan bilangan dari besar ke kecil dengan metode selection sort
# Mencetak array yang sudah terurut

# KAMUS
# N, i : int
# arr : array of int

# ALGORITMA PROGRAM UTAMA
def get_max(arr, index_start):
    # mendapatkan maksimum array dari indeks indeks_start sampai selesai
    # KAMUS LOKAL
    # Max, i : int

    # ALGORITMA
    Max = arr[index_start]
    for i in range(index_start, len(arr)):
        if (arr[i] > Max):
            Max = arr[i]
    return Max

def get_idx(arr, number):
    # mendapatkan index dari suatu angka dalam array
    # KAMUS LOKAL
    # i : int

    # ALGORITMA
    for i in range(len(arr)):
        if (number == arr[i]):
            return i

def swap(array, indeks_1, indeks_2):
    # swap elemen array indeks 1 dengan indeks 2
    # KAMUS LOKAL
    # Temp : int

    # ALGORITMA
    Temp = array[indeks_1]
    array[indeks_1] = array[indeks_2]
    array[indeks_2] = Temp
    return array

def sort(arr):
    for i in range(len(arr)):
        maxArr = get_max(arr, i)
        maxIdx = get_idx(arr, maxArr)
        swap(arr, i, maxIdx)
    print(arr)

N = int(input())
arr = [0 for i in range(N)]
for i in range(N):
    arr[i] = int(input())

sort(arr)