
// Java program for implementation of Insertion Sort
class InsertionSort
{
	/*Function to sort array using insertion sort*/
	void sort(int arr[])
	{
	    int n=arr.length;
	    for(int i=1;i<n;++i)
	    {
	       int key =arr[i];
	       int j=i-1;

	       /* Move elements of arr[0...i-1], that are greater than key, to one postion ahead of their currnt position */

	     while(j>=0 && arr[j]>key)
	     {
	        arr[j+1]=arr[j];
	        j=j-1;
	     }  
	     arr[j+1]=key;
	    }
	}

	/* A utilty function to  print array of size n*/
	static void printArray(int arr[])
	{
	   int n = arr.length;
	   for(int i=0;i<n;++i)
	       System.out.println(arr[i]+"");

	    System.out.println();
	       
	}

	// Driver method

	public static void main(String args[])
	{
	   int arr[]={12,13,11,3,45};

	   InsertionSort ob=new InsertionSort();
	   ob.sort(arr);

	   printArray(arr);

	}
}