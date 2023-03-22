# Program segiempat
# Menerima masukan sebuah integer N dan dua buah karakter C1 dan C2
# Menuliskan bentuk ke layar jika N > 0 dan C1 tidak sama dengan C2
# Jika syarat tidak terpenuhi, cetak "Masukan tidak valid"

# KAMUS
# N: int
# C1, C2: char
# M: matrix of char berukuran N * N

# ALGORITMA
N = int(input())
C1 = input()
C2 = input()

M = [[0 for j in range(N)] for i in range(N)]

if (N > 0) and (C1 != C2):
    for i in range(N):
        for j in range(N):
            if (i == 0) or (j == 0) or (i == N-1) or (j == N-1):
                M[i][j] = C1
            else:
                M[i][j] = C2
            print(M[i][j], end="")
        print()

else:
    print("Masukan tidak valid")