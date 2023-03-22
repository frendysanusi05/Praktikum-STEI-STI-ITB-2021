# Nama: Frendy Sanusi
# NIM: 16521124
# Tanggal: 18 Maret 2022

# Program Bilangan
# Menerima masukan sebuah integer positif N dan sebuah integer X dan menghasilkan output sesuai dengan validasi yang dijalankan program

# KAMUS
# N, X, i : input
# arr : array of integer

# Prosedur MencariX
def MencariX(X):
    # KAMUS LOKAL
    # count, i : int

    # ALGORITMA
    count = 0
    if (X == 0):
        for i in range(N):
            if (arr[i] == 0):
                print(i+1)
                break
            else:
                count += 1
        if (count == N):
            print("Tidak ada 0")
    
    elif (X == -1):
        for i in range(N):
            if (arr[i] < 0):
                CetakHasil(i)
                break
            else:
                count += 1
        if (count == N):
            print("Tidak ada negatif")
    
    elif (X == 1):
        for i in range(N):
            if (arr[i] > 0):
                CetakHasil(i)
                break
            else:
                count += 1
        if (count == N):
            print("Tidak ada positif")
    
    else:
        print("Tidak diproses")

# Prosedur CetakHasil
def CetakHasil(x):
    # KAMUS LOKAL
    # ALGORITMA
    print(x+1, arr[x])

# ALGORITMA PROGRAM UTAMA
N = int(input())

while (N <= 0 or N > 100):
    print("Masukan salah. Ulangi!")
    N = int(input())

arr = [0 for i in range(N)]

for i in range(N):
    arr[i] = int(input())

X = int(input())
MencariX(X)