import java.util.Scanner;
import java.util.*;
class countNo{
   static int count(int arr[],int n,int x)
   {
   int res=0;
   for(int i=0;i<n;i++)

     if(arr[i]==x)
     res++;
     return res;

   }

   public static void main(String args[])
   {
   Scanner sc=new Scanner(System.in);
   int n=sc.nextInt();
   int arr[]=new int[n];

   for(int i=0;i<n;i++)
   {
     arr[i]=sc.nextInt();

   }
   int x=sc.nextInt();
   System.out.println(count( arr, n, x ));
   }
}
