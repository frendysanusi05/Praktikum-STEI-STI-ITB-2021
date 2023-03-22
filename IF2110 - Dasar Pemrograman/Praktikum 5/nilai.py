# Program Nilai
# Menerima masukan sebuah nilai mahasiswa (dalam bentuk angka) sampai masukan bernilai -999 (-999 tidak diproses).
# Masukan harus divalidasi, yaitu 0= < N <= 100. Jika ada data salah, data tersebut diabaikan.
# Menuliskan banyaknya mahasiswa, berapa banyak yang lulus (nilai >=  40), berapa yang tidak lulus (nilai <  40), dan rata-rata nilai untuk data-data yang valid.
# Jika tidak ada data yang valid, maka akan mengeluarkan 0 (menunjukkan banyaknya mahasiswa).

# KAMUS
# N, jlh_lulus, jlh_tidak_lulus, nilai : int
# Sum : float

# ALGORITMA
N = 0
data_non_valid = 0
jumlah_data = 0
Sum = 0
jlh_lulus = 0
jlh_tidak_lulus = 0
nilai = int(input())

while (nilai != -9999):
    jumlah_data += 1
    if (0 <= nilai <= 100):
        N += 1
        if (nilai >= 40):
            jlh_lulus += 1
        else: # nilai < 40
            jlh_tidak_lulus += 1
        Sum += nilai
    else:
        data_non_valid += 1
    nilai = int(input())

if (N == 0):
    if (jumlah_data == data_non_valid) and (data_non_valid > 0):
        print(N)
    else:
        print("Data nilai kosong")
else:
    print(N)
    print(jlh_lulus)
    print(jlh_tidak_lulus)
    print("%.2f"%(Sum/N))