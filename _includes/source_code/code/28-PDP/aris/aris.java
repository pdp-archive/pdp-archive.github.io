import java.util.Scanner;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
 
class Main {
 
 
   public static void main(String[] arguments) throws Exception {
      Scanner reader = new Scanner(new FileInputStream("aris.in"));
 
      PrintWriter out = new PrintWriter(new File("aris.out"));
 
      int N = reader.nextInt();
      int M = reader.nextInt();
      int[] counts = new int[N + 1];
      for (int i = 0; i < N; ++i) {
         int m = reader.nextInt();
         counts[m] ++;
      }  
 
      int progs = 0;
      int minCount = N;
      int maxCount = 0;    
 
      for (int m = 1; m <= M; ++m) {
         if (counts[m] > 0) {
            progs ++;
            if (counts[m] < minCount) { minCount = counts[m]; }
            if (counts[m] > maxCount) { maxCount = counts[m]; }
         }
      }
 
      out.println(progs + " " + minCount + " " + maxCount);
      out.close();
   }
}
