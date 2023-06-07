import java.util.ArrayList;

public class SimpleWordCountServer {
    // nWorkers menyatakan jumlah maximum threads yang tersedia pada server a.k.a thread pool
    private int nWorkers;

    SimpleWordCountServer(int nWorkers) {
        // Please provide your solution in the space below
		this.nWorkers = nWorkers;
    }

    public Integer[] processRequests(String[] requests) throws InterruptedException {
        // processRequests akan membuat threads dan memetakan elemen-elemen requests kepada threads tersebut
        // setiap thread kemudian memanggil method countWords
        // main thread (thread yang invoked method ini) akan menunggu semua thread selesai
        // terakhir main thread akan mengembalikan hasil penghitungan kata untuk setiap elemen requests
        // Please provide your solution in the space below
		int len = requests.length;
		int res = requests.length;
		
		ArrayList<Thread> ts = new ArrayList<Thread>(len);
		ArrayList<Integer> arrCnt = new ArrayList<Integer>(len);
		
		for (String i : requests) {
			Thread t = new Thread(new Runnable() {
				public void run() {
					arrCnt.add(countWords(i));
				}
			});
			t.start();
			ts.add(t);
			res++;
		}
		
		for (Thread t : ts) {
			try {
				t.join();
			}
			catch (InterruptedException e) {
				throw e;
			}
		}
		
		Integer[] arr = new Integer[len];
		for (int i = 0; i < len; i++) {
			arr[i] = arrCnt.get(i);
		}
		
		return arr;
    }

    protected int countWords(String request) {
        // Please provide your solution in the space below
		int cnt = 0;
		for (int i = 0; i < request.length(); i++) {
			if (request.charAt(i) == ' ') {
				cnt++;
			}
		}
		return cnt + 1;
    }
}
