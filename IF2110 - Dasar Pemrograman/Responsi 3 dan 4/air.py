# Program Air
# Menerima masukan temperatur (T) air dalam derajat Celcius untuk kondisi tekanan 1 atm
# Menuliskan ketergantungan kondisi air dengan temperatur

# KAMUS
# T: int

# ALGORITMA
T = int(input())

if (T < 0):
    print("PADAT")
elif (0 < T < 100):
    print("CAIR")
elif (T > 100):
    print("GAS")
elif (T == 0):
    print("ANTARA PADAT-CAIR")
elif (T == 100):
    print("ANTARA CAIR-GAS")