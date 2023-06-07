import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        // Hint 1: Untuk mendapatkan input dari user, umumnya bisa dengan memasukkan parameter System.in
        // ke dalam konstruktor Scanner.
        Scanner x = new Scanner(System.in);
        String kata = x.nextLine();
        Email email = new Email(kata);
        
        try {
			System.out.println(email.validateEmail());
			System.out.println("Email validated.");
		}
		catch (InvalidEmailException e) {
			System.out.println("InvalidEmailException! " + e.getMessage());
			System.out.println("Email string error!");
		}
		catch (InvalidDomainException e) {
			System.out.println("InvalidDomainException! " + e.getMessage());
			System.out.println("Email string error!");
		}
		
		x.close();
		System.out.println("Operation finished.");
    }
    
}
