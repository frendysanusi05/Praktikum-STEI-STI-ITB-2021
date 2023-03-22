# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 3 November 2021
# Deskripsi : Problem 3 - Program MenghitungBanyakKemunculan

# Program MenghitungBanyakKemunculan
# Menghitung berapa banyak kemunculan sebuah string sebagai sebuah substring pada string lain
# Asumsi masukan string berupa (1) huruf kecil (a-z) dan (2) string1 tidak lebih panjang dari string2
# Pada program ini hanya akan mengecek asumsi (2)

# KAMUS
# N1, N2, count, i, j: int
# string1, string2, kata: str

# ALGORITMA
# Input
N1 = int(input('Masukkan panjang string 1: '))
string1 = input('Masukkan string 1: ')
N2 = int(input('Masukkan panjang string 2: '))
string2 = input('Masukkan string 2: ')
count = 0 # Deklarasi awal count = 0

if (N1 <= N2): # asumsi string1 tidak lebih panjang dari string2
    # Misalkan string1 = fren dan string2 = frendy, dengan N1 = 4 dan N2 = 6
    # Akan ada jumlah substring sebanyak N2 - N1 + 1 = 6 - 4 + 1 = 3 substring pada string2 yang berukuran sama dengan N1
    # yaitu 'fren', 'rend', 'endy'
    for i in range(N2 - N1 + 1):
        kata = '' # membuat array of char
        for j in range(i, i + N1):
            kata += string2[j] # append string2[j] ke kata sehingga diperoleh panjang variabel kata == N1
        if (kata == string1):
            count += 1

    print(f'String 1 muncul sebanyak {count} kali.') # Output