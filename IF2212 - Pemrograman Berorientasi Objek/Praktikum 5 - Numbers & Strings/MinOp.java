import java.util.ArrayList;

public class MinOp {

    public static int minimumOperationsNeeded(Number[] arrNum) {
        // mengembalikan operasi minimum untuk mencapai array yang diinginkan
        int len = arrNum.length;
        Number[] temp = new Number[len];
        Integer[] benar = new Integer[len];
        int cnt = 0;
        int cntkali = 0;
        
        for (int i = 0; i < len; i++) {
			temp[i] = 0;
			benar[i] = 0;
		}
		
		boolean selesai = false;
        
        while (!selesai) {
			for (int i = 0; i < len; i++) {
				if (temp[i].intValue() * 2 == arrNum[i].intValue()) benar[i] = 1;
			}
			
			for (int i = 0; i < len; i++) {
				if (benar[i].intValue() != 1) {
					temp[i] = temp[i].intValue() + 1;
				} else {
					temp[i] = temp[i].intValue() * 2;
					cntkali++;
				}
				cnt++;
			}
			
			int a = 0;
			for (int i = 0; i < len; i++) {
				if (temp[i] == arrNum[i]) {
					a++;
				}
			}
			
			if (a == len) selesai = true;
		}
		
		return cnt - cntkali/2;
    }
    
    public static void main(String[] args) {
		Number[] arr = new Number[2];
		
		arr[0] = 4;
		arr[1] = 2;
		
		System.out.println(minimumOperationsNeeded(arr));
	}
}
