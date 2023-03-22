# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 6 Oktober 2021
# Deskripsi : Problem 2 - Program menentukan harga tiket pesawat

# Program menentukan harga tiket pesawat
# Menentukan harga tiket berdasarkan pembagian kursi

# KAMUS
# harga: int
# posisi: char
# nomor, kelas: string

# ALGORITMA
# Masukkan nomor kursi
nomor = input('Tentukan Nomor Kursi: ')

# Masukkan posisi kursi
posisi = input('Tentukan Posisi Kursi: ')

if nomor >= '001' and nomor <= '020' or nomor >= '051' and nomor <= '060':
    kelas = 'Hot Seat'
    if posisi == 'A' or posisi == 'F':
        harga = 1600000
    elif posisi == 'B' or posisi == 'E':
        harga = 1550000
    elif posisi == 'C' or posisi == 'D':
        harga = 1500000

elif nomor >= '021' and nomor <= '050' or nomor >= '061' and nomor <= '100':
    kelas = 'Regular'
    if posisi == 'A' or posisi == 'F':
        harga = 1000000
    elif posisi == 'B' or posisi == 'E':
        harga = 950000
    elif posisi == 'C' or posisi == 'D':
        harga = 900000

print(f'Tuan Kil memilih kursi {kelas} dengan harga {harga}.')