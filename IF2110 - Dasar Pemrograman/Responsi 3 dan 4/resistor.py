# Nama: Frendy Sanusi
# NIM: 16521124
# Tanggal: 18 Maret 2022

# Program Resistor
# Menerima 3 (tiga) bilangan riil yang merepresentasikan  nilai resistor R1, R2, dan R3, berupa bilangan rill > 0, dan menghitung nilai resistansi total, tergantung dihubungkan secara serial atau paralel (asumsikan tidak ada jenis hubungan lain)

# KAMUS
# loop :bool
# R1, R2, R3: float
# pilihan : char

# ALGORITMA
def valid(R1, R2, R3, pilihan):
    # KAMUS LOKAL
    # arrPil : array of char
    # valid : bool

    # ALGORITMA
    arrPil = ['S', 's', 'P', 'p']
    valid = True
    if (R1 > 0 and R2 > 0 and R3 > 0):
        valid = True
    else:
        valid = False

    if pilihan not in arrPil:
        valid = False

    if (valid == False):
        print("Masukan salah")
    return valid

def Hambatan(R1, R2, R3, pilihan):
    # KAMUS LOKAL
    # RT : float
    
    # ALGORITMA
    if (pilihan == 's' or pilihan == 'S'): # rangkaian seri
        RT = R1 + R2 + R3
    elif (pilihan == 'p' or pilihan == 'P'): # rangkaian paralel
        RT = 1/(1/R1 + 1/R2 + 1/R3)
    print("%.2f" %RT)

loop = False
while loop == False:
    R1 = float(input())
    R2 = float(input())
    R3 = float(input())
    pilihan = input()
    loop = valid(R1, R2, R3, pilihan)

Hambatan(R1, R2, R3, pilihan)