# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 17 November 2021
# Deskripsi : Problem 2 - Program MenghitungBanyaknyaKataBerbeda

# Program MenghitungBanyaknyaKataBerbeda
# Menghitung banyaknya kemungkinan kata berbeda pada masukan yang diberikan

# KAMUS
# N, tidak_sama, freq, i, j, penyebut: int
# string: str
# arr: array of str
# count: array of int

# ALGORITMA
def factorial(x):
    # Membuat fungsi factorial untuk menghitung nilai faktorial suatu masukan
    
    # KAMUS LOKAL
    # x, fact, i: int
    
    # ALGORITMA
    fact = 1
    for i in range(1, x+1):
        fact *= i
    return fact

# Input
N = int(input('Masukkan panjang string: '))
string = input('Masukkan string: ')

arr = ['' for i in range(N)] # Deklarasi array kosong dengan jumlah elemen = N
count = [1 for j in range(N)] # Deklarasi aray count dengan jumlah elemen = N
tidak_sama = 0
for i in range(N):
    for k in range(N):
        if (string[i] != arr[k]): # Jika tidak terdapat karakter yang sama
            tidak_sama += 1 # Menghitung frekuensi karakter yang tidak sama
                            # untuk satu karakter pada string
    
    if (tidak_sama == N):   # artinya tidak ada karakter yang sama sehingga
                            # karakter tersebut dimasukkan ke dalam arr 
        arr[i] = string[i]
    else:
        freq = N - tidak_sama # Menghitung frekuensi karakter yang sama
        for k in range(N):
            if (string[i] == arr[k]):
                # Menambahkan frekuensi ke karakter yang sama
                count[k] += freq
    # tidak_sama dibuat ke 0 lagi untuk menghitung frekuensi karakter yang lain
    tidak_sama = 0

penyebut = 1
for j in range(N):
    if (count[j] != 1):
        penyebut *= factorial(count[j]) # Menghitung hasil faktorial penyebut

# Memanggil fungsi factorial sekaligus menampilkan hasil perhitungan ke layar
print(f'String tersebut dapat membentuk {int(factorial(N)/penyebut)} kata berbeda.')