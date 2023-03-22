# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 27 Oktober 2021
# Deskripsi : Problem 3 - Program menentukan nilai maksimal dari perkalian bilangan

# Program menentukan nilai maksimal dari perkalian bilangan

# KAMUS
# N, min, max, result, i: int
# bool: boolean
# Menerima masukan N yang lebih besar dari 1

# ALGORITMA
# Input
N = int(input('Masukkan bilangan N: '))

# Proses
min = N//3
max = min+1

result = min
bool = True
for i in range(2, N):
    if (bool == True):
        if (i == min):
            result *= i
        elif (i >= min): # mencari nilai max, tetapi hanya satu bilangan saja yang diambil
            result *= i
            bool = False # supaya pengecekan terhentikan

if (N == 2): # Untuk N = 2, hanya ada satu kemungkinan saja, yaitu keduanya angka 1
   result = 1

print(f'Nilai maksimalnya adalah {result}') # Output