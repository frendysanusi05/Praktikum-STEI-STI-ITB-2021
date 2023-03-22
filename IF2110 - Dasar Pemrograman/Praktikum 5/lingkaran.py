# Program Lingkaran
# Menghitung luas lingkaran tergantung masukan jari-jari (integer).
# Jari-jari harus divalidasi sehingga selalu > 0. Jika tidak, maka program akan mengeluarkan pesan error.

# KAMUS
# r : int

# ALGORITMA
r = int(input())

if (r <= 0):
    print("Jari-jari harus > 0") 
else:
    print("%.2f" %(3.1415*r**2))