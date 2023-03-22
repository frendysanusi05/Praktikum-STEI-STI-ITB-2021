# Nama: Frendy Sanusi
# NIM: 16521124

# Program Konversi Suhu
# Mengonversi suhu dari satuan Celcius ke satuan lain, yaitu Fahreinheit, Reamur, atau Kelvin

# KAMUS
# t : int
# k : char
# konversi : float

# ALGORITMA
t = float(input()) # celcius
k = input() # 'R', 'F', atau 'K'

if (k == 'R'):
    konversi = 4/5 * t
elif (k == 'F'):
    konversi = (9/5)*t + 32
else: # k == 'K'
    konversi = 273.15 + t

print('{:.2f}'.format(konversi))