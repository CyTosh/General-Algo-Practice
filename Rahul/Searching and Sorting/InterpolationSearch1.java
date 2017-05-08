
 class InterpolationSearch1
{
	 int search(int  sortedArray[], int toFind)
	{


	   final int NOT_FOUND =-1;
	   int low=0;
       int high =sortedArray.length-1;
       int mid;


       while(sortedArray[low] < toFind &&sortedArray[high] >=toFind  )
       {
       mid = low +((toFind -sortedArray[low])*(high -low))/(sortedArray[high]-sortedArray[low]);


         if(sortedArray[mid]<toFind)
           
            low=mid+1;
            else if(sortedArray[mid]>toFind)
            high=mid-1;
            else
            return mid;
    }
       
       if(sortedArray[low]==toFind)
          return low;
          else
             return NOT_FOUND;
     
     


	}
	public static void main(String args[])
	{  
		InterpolationSearch1 ob=new InterpolationSearch1();


	   int sortedArray[] ={20,12,23,45,5};
	   int high=sortedArray.length-1;
	   int toFind=5;
	   int index = ob.search(sortedArray , toFind);

 
	   if(index==-1)
	      System.out.println("Element not found. ");
	        else
       System.out.println("\nElement found at index\n"+index);
    
}
	}
