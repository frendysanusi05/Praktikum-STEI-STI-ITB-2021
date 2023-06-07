/* Untuk mengaktifkan assertion, jalankan driver dengan flag -ea
   Contoh:
   $ javac SimpleWordCountServer.java SimpleWordCountServerDriver.java
   $ java -ea SimpleWordCountServerDriver
 */
public class SimpleWordCountServerDriver {
    public static void main(String[] args) throws InterruptedException {
       int nWorkers = 1;
       String[] req = {"computer science", "i love anime", "distributed system", "designing data intensive application","ayam ayam"};
       int nRequest = req.length;
       SimpleWordCountServer server = new SimpleWordCountServer(nWorkers);

       Integer[] expectedWordCounts = {2, 3, 2, 4, 2};
       Integer[] actualWordCounts = server.processRequests(req);
       
       for (int i = 0; i < req.length; i++) {
			System.out.printf("%d %d\n", expectedWordCounts[i], actualWordCounts[i]);
		}

       for (int i = 0; i < expectedWordCounts.length; i++) {
          assert (expectedWordCounts[i].equals(actualWordCounts[i])) == true;
       }
       System.out.println("Congrats! No Errors :)");
    }
}
