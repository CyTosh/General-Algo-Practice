// Java program to find an element x in a 
// sorted array using exponential search.
class ExponentialSearch
{
	int binarySearch(int arr[],int ,int ,int);

	// Returns position of first occurenc of
	// x in array
	int exponentialSearch(int arr[],int n,int x)	
	{
	   // If x is present at first location itself
	   if(arr[0]==x)
	     return 0;

	     // Find the range for binary search by
	     // repeated douling
          int i=1;
          while(i<n&&arr[i]<=x)
           i=i*2;

           // Call binary search for found range.
           return binarySearch(arr,i/2,min(i,n),x);

	}
	// A recursive binary search function.It returns
	//location of x in given array arr[l..r] is
	// present otherwise -1
	int binarySearch(int arr[],int l,int r,int x)
	{
	   if(r>=l)
	   {
	       int mid =l+(r-l)/2;

	       //If the element is present at the middle
	       // itself
	       if(arr[mid]==x)
	          return mid;

	       // If element is smaller than mid,then it
	       // can only be present n left subarray
	       if(arr[mid]>x)
	         return binarySearch(arr,l,mid-1,x);

	         //Else the element can only be present
	         // in right subarray
	         return binarySearch(arr,mid+1,r,x);

	   }
	   // We reached here when element is not present
	   // in array
	   return -1;
	}

	// Driver code
	public  static void main(String args[])
	{   
		ExponentialSearch ob=new ExponentialSearch();
	   int arr[]={2,3,4,40,55,5444,66565};
	   int n=arr.length;
	   int x=40;
	   int result = ob.binarySearch(arr,0,n-1,x);
	   if(result==-1)
	   System.out.println("element is not present in array");
	   System.out.printf("element is present at index %d",result);
	   
	}
}