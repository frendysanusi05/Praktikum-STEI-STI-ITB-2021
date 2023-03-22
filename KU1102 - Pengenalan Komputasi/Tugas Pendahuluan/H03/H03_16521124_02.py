# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 3 November 2021
# Deskripsi : Problem 2 - Program MenentukanAnagram

# Program MenentukanAnagram
# Memeriksa apakah array B merupakan anagram dari array A

# KAMUS
# arr_A, arr_B: array [0..10] of int - dengan index 0 sampai dengan 10
# A, a, elemenA, B, b, elemenB, i: int
# anagram: bool

# ALGORITMA
# Membuat array berukuran 11 dengan isi 0
arr_A = [0 for a in range(11)]
arr_B = [0 for b in range(11)]

A = int(input('Masukkan banyaknya elemen A: ')) # Input
for a in range(A):
    elemenA = int(input(f'Masukkan elemen A ke-{a+1}: ')) # input
    arr_A[elemenA] += 1

B = int(input('Masukkan banyaknya elemen B: ')) # Input
for b in range(B):
    elemenB = int(input(f'Masukkan elemen B ke-{b+1}: ')) # Input
    arr_B[elemenB] += 1

anagram = True
for i in range(11):
    if (arr_A[i] != arr_B[i]):
        anagram = False # artinya bukan anagram karena frekuensi elemen tidak sesuai

if anagram: # anagram == True
    print('B adalah anagram dari A') # Output
else: # anagram == False
    print('B bukan anagram dari A') # Output