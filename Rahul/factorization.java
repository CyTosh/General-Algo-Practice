
 import java.lang.*;
import java.util.*;
import java.util.Scanner;
import java.util.Arrays;
class factorization {
  public static void primeFactors(int n) {
    while (n % 2 == 0) {
      System.out.println(2 + " ");
      n = n / 2;

    }
    for (int i = 3; i < Math.sqrt(n); i++) {
      while (n % i == 0) {
        System.out.println(i + " ");
        n = n / i;
      }
    }

    if (n > 2)
      System.out.println(n);
      return;

  }


  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    primeFactors(n);

  }


}
