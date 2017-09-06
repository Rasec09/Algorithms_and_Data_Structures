import java.math.BigInteger;
import java.security.SecureRandom;
import java.io.*;
import java.util.*;

public class PollardRho {

    private final static BigInteger ZERO = new BigInteger("0");
    private final static BigInteger ONE  = new BigInteger("1");
    private final static BigInteger TWO  = new BigInteger("2");
    private final static SecureRandom random = new SecureRandom();

    static Vector<BigInteger> v = new Vector<BigInteger>();

    public static BigInteger rho(BigInteger N) {

        BigInteger divisor;
        BigInteger c  = new BigInteger(N.bitLength(), random);
        BigInteger x  = new BigInteger(N.bitLength(), random);
        BigInteger xx = x;

        if (N.mod(TWO).compareTo(ZERO) == 0) return TWO;

        do {
            x  =  x.multiply(x).mod(N).add(c).mod(N);
            xx = xx.multiply(xx).mod(N).add(c).mod(N);
            xx = xx.multiply(xx).mod(N).add(c).mod(N);
            divisor = x.subtract(xx).gcd(N);
        } while((divisor.compareTo(ONE)) == 0);

        return divisor;
    }

    public static void factor(BigInteger N) {

        if (N.compareTo(ONE) == 0) return;

        if (N.isProbablePrime(20)) {
            v.add(N);
            return;
        }

        BigInteger divisor = rho(N);
        factor(divisor);
        factor(N.divide(divisor));
    }

    public static void main(String[] args) throws Exception {

    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    	int TC = Integer.parseInt(br.readLine());

		while (TC-- > 0) {
        	long num = Long.parseLong(br.readLine());
        	BigInteger N = new BigInteger(num + "");
        	factor(N);
     
       		int sz = v.size();
       		Collections.sort(v);
       		for (int i = 0; i < sz; i++) {
       			if (i != 0) bw.write(" ");
       			bw.write(String.valueOf(v.elementAt(i)));
       		}
       		bw.newLine();
       		v.clear();
       	}
    	bw.close();
    }
}
