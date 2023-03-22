# Program CariCharacter
# Menerima masukan integer positif N, kemudian divalidasi hingga N benar (0 < N <= 100). Jika masukan N salah, dituliskan pesan "Masukan salah, Ulangi!"
# Jika N sudah benar, program membaca masukan N buah character dan menghasilkan urutan pertama ditemukan karakter tersebut dan hurufnya.

# KAMUS
# N, i : int
# arr : array of char
# CC : char
# cek : bool

# ALGORITMA
N = int(input())
while (N <= 0 or N > 100):
    print("Masukan salah. Ulangi!")
    N = int(input())

arr = [0 for i in range(N)]
for i in range(N):
    arr[i] = input()

CC = input()
cek = True
i = 0
while (i < N) and cek:
    if (CC == 'S' or CC == 's'):
        if (97 <= ord(arr[i]) <= 122):
            cek = False
    elif (CC == 'L' or CC == 'l'):
        if (65 <= ord(arr[i]) <= 90):
            cek = False
    elif (CC == 'X' or CC == 'x'):
        if (ord(arr[i]) < 97 or ord(arr[i]) > 122) and (ord(arr[i]) < 65 or ord(arr[i]) > 90):
            cek = False
    i = i + 1

if cek:
    if (CC == 'S' or CC == 's'):
        print("Tidak ada huruf kecil")
    elif (CC == 'L' or CC == 'l'):
        print("Tidak ada huruf besar")
    elif (CC == 'X' or CC == 'x'):
        print("Semua huruf")
    else:
        print("Tidak diproses")
else:
    print(i, arr[i-1])