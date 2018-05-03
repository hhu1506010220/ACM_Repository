import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.function.IntPredicate;
import java.util.stream.Stream;
 
public class Main {
 
    static int cnts[] = new int[27];
    public static void main(String[] args) {
         
        //ReDirtectInput.reDirectionInput();
         
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String str = sc.next();
        for (char ch:str.toCharArray()){
            cnts[ch-'A']++;
        }
        BigInteger res = new BigInteger(""+n);
        for(int i = 1; i < n; i++){
            res = res.multiply(new BigInteger(""+i));
        }
         
        for(int i = 0; i < 27; i++){
            if(cnts[i] > 1){
                BigInteger d = new BigInteger(""+cnts[i]);
                for(int j = 1; j < cnts[i]; j++){
                    d = d.multiply(new BigInteger(""+j));
                }
                res = res.divide(d);
            }
             
        }
        System.out.printf("1/%s\n", res.toString());
        sc.close();
    }
}
