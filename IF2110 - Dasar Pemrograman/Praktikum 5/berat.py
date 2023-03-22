# Program Berat
# Membaca masukan berat tubuh mahasiswa (dalam bentuk angka) sampai masukan berupa -999 (-999 tidak diproses)
# Masukan harus diperiksa, yaitu harus berada dalam range 30-200 (30 dan 200 termasuk). Jika tidak, data tersebut diabaikan
# Menuliskan banyaknya jumlah mahasiswa, banyaknya mahasiswa dengan berat <= 50 kg, banyaknya mahasiswa dengan berat >= 100 kg, dan rata-rata berat mahasiswa

# KAMUS
# N, jlh_kecil_50, jlh_besar_100, berat : int
# Sum : float
# masukan : bool

# ALGORITMA
N = 0
Sum = 0
jlh_kecil_50 = 0
jlh_besar_100 = 0
berat = int(input())

while (berat != -999):
    if (30 <= berat <= 200):
        N += 1
        if (berat <= 50):
            jlh_kecil_50 += 1
        elif (berat >= 100):
            jlh_besar_100 += 1
        Sum += berat
    berat = int(input())
    
if (N == 0):
    print("Data kosong")
else:
    print(N)
    print(jlh_kecil_50)
    print(jlh_besar_100)
    print(Sum//N)