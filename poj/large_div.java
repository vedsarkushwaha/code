import java.math.BigInteger;
import java.io.*;
import java.util.Scanner;
class large_div {
	public static void main(String str[]) {
		int num=0,N;
		Scanner sc=new Scanner(System.in);
		N=sc.nextInt();
		if(N==0)
			System.exit(0);
		while(!chk_div(Integer.toBinaryString(num),N)) {
			num++;
		}
		System.out.println(Integer.toBinaryString(num));
	}
	static boolean chk_div(String str,int N) {
		BigInteger a=new BigInteger(str);
		BigInteger b=new BigInteger(String.valueOf(N));
		BigInteger c=new BigInteger("0");
		System.out.println("0");
		if(a.mod(b)==c)
			return true;
		else
			return false;
	}
}