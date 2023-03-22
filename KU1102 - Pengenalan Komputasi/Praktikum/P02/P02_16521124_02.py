# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 27 Oktober 2021
# Deskripsi : Problem 2 - Program menghitung banyaknya ember x dan ember y yang digunakan untuk mengisi kolam z

# Program menghitung banyaknya ember x dan ember y yang digunakan untuk mengisi kolam z

# KAMUS
# x, y, z, i, count_x, count_y: int
# bool: boolean
# Asumsi x, y, z bilangan asli

# ALGORITMA
# Input
x = int(input('Masukkan x: '))
y = int(input('Masukkan y: '))
z = int(input('Masukkan z: '))

# Proses
if (x >= 0) and (y >= 0) and (z >= 0): # Asumsi x, y, z bilangan asli
    bool = True
    for i in range(z):
        if ((z - i*x) % y == 0) and (bool == True):
            count_x = int(i)
            count_y = int((z - (i*x))/y)
            print(f'{count_x} kali ember x, {count_y} kali ember y') # Output
            bool = False

    if (bool == True):
        print('Tidak mungkin') # Output