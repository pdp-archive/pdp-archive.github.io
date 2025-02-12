import java.math.BigInteger;
import java.util.ArrayList;   
import java.util.Scanner;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
 
class Main {
 
   public static void main(String[] arguments) throws Exception {
      Scanner sc = new Scanner(new FileInputStream("polybox.in"));
 
      PrintWriter out = new PrintWriter(new File("polybox.out"));
      
      int subtask = sc.nextInt();
      int N = sc.nextInt();
      ArrayList<BigInteger> w = new ArrayList<>(), h = new ArrayList<>();
      for (int i = 0; i < N; ++i) {
         w.add(sc.nextBigInteger());
         h.add(sc.nextBigInteger());
      }
      
      //υπολόγισε στη μεταβλητή ans την πιο πάνω και την πιο κάτω πλευρά της στοίβας
      BigInteger ans = w.get(0).add(w.get(N-1));
      //πρόσθεσε στη ans όλα τα ενδιάμεσα εκτεθημένα τμήματα
      for(int i=0;i<N-1;i++)
         ans = ans.add(w.get(i).subtract(w.get(i+1)).abs());
      //πρόσθεσε τα ύψη όλων των κουτιών
      BigInteger two = new BigInteger("2");
      for(int i=0;i<N;i++)
        ans = ans.add(h.get(i).multiply(two));
 
      out.println(ans);
      out.close();
   }
}
