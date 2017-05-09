class ternary
{
	int ternarySearch(int arr[],int l,int r,int x)
	{
	   if(r>=l)
	   {
	      int mid1 = l+(r-1)/3;
	      int mid2 = mid1 +(r-1)/3;

	      // If x is present at the mid1
	      if(arr[mid1]==x)  return mid1;

	      // If x is present at the mid2
	      if(arr[mid2]==x) return mid2;

	      // If x is present in left one-third
	      if(arr[mid1]>x)  return ternarySearch(arr,l,mid1-1,x);

	      //if x is present in right ont third
	      if(arr[mid2]<x)  return ternarySearch(arr,mid2+1,r,x);
 
	      // If x is present in middle one-third
          return ternarySearch(arr,mid1+1,mid2-1,x);



	   }
	   // We reach here when element is not present in array
	   return -1;
	}

	public static void main(String args[])
	{
	  ternary ob = new ternary();

	  int arr[]={5,12,34,45,67};
	  int n=arr.length;
	  int x=12;
	  int index=ob.ternarySearch(arr,0,n-1,x);

	  if(index==-1)
	    System.out.println("element not found");
	    else
	     System.out.println("\nelement found at index\n"+index);
	}
}