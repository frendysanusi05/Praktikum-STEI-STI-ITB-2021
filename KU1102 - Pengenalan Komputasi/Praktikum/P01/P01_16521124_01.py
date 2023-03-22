# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 6 Oktober 2021
# Deskripsi : Problem 1 - Program menghitung besar pajak

# Program menghitung besar pajak
# Menghitung pajak yang harus dibayarkan berdasarkan penghasilannya

# KAMUS
# income, pajak: int

# ALGORITMA
# Masukkan nominal penghasilan Tuan Ric
income = int(input('Masukkan penghasilan Tuan Ric: '))

if income < 50000000:
    pajak = int((5/100) * income)
elif income >= 50000000 and income <= 249999999:
    pajak = int((15/100) * income)
elif income >= 250000000 and income <= 499999999:
    pajak = int((25/100) * income)
else: # income > 499999999
    pajak = int((30/100) * income)

print(f'Pajak yang harus dibayar Tuan Ric sebesar {pajak} rupiah.')