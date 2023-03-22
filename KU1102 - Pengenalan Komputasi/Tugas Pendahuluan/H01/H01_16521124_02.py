# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 6 Oktober 2021
# Deskripsi : Program membuat kalkulator sederhana

# Program Problem 2
# Membuat kalkulator sederhana
# Input: a, b, operation
# Output: cetak hasil operasi

# KAMUS
# a, b, result: int
# operation: string

# ALGORITMA
# Masukkan angka pertama
a = int(input('Masukkan angka pertama: '))
# Masukkan angka kedua
b = int(input('Masukkan angka kedua: '))
# Masukkan operator
operation = input('Masukkan operator: ')

if operation == '+': # Jika meng-input penjumlahan
    result = a + b
elif operation == '-': # Jika meng-input pengurangan
    result = a - b
elif operation == '*': # Jika meng-input perkalian
    result = a * b
elif operation == '/': # Jika meng-input pembagian yang dibulatkan ke bawah
    result = a // b
elif operation == '%': # Jika meng-input sisa bagi
    result = a % b

# Cetak hasil operasi
print(f'{a} {operation} {b} = {result}')