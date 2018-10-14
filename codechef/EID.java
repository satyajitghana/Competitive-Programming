import java.util.*;
class qsort{
	 int partition(int arr[], int low, int high)
	    {
	        int pivot = arr[high]; 
	        int i = (low-1); 
	        for (int j=low; j<high; j++)
	        {
	            
	            if (arr[j] <= pivot)
	            {
	                i++;
	                int temp = arr[i];
	                arr[i] = arr[j];
	                arr[j] = temp;
	            }
	        }
	        int temp = arr[i+1];
	        arr[i+1] = arr[high];
	        arr[high] = temp;
	 
	        return i+1;
	    }
	    void sort(int arr[], int low, int high)
	    {
	        if (low < high)
	        {
	            
	            int pi = partition(arr, low, high);
	            sort(arr, low, pi-1);
	            sort(arr, pi+1, high);
	        }
	    }
}

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
			Scanner s=new Scanner(System.in);
			qsort qs=new qsort();
				int t=s.nextInt();
				for(int i=0;i<t;i++){
				    int n=s.nextInt();
				    int arr[]=new int[n];
				    for(int j=0;j<n;j++){
				        arr[j]=s.nextInt(); 
				    }
				    qs.sort(arr,0,n-1);
				    int mini=Math.abs(arr[0]-arr[1]);
				    for(int j=0;j<=n-2;j++){
				    	if(mini>Math.abs(arr[j]-arr[j+1])) {
				        mini=Math.min(mini,Math.abs(arr[j]-arr[j+1]));}
				    }
				    if(mini>Math.abs(arr[0]-arr[n-1])) {mini=Math.abs(arr[0]-arr[n-1]);}
				    System.out.println(mini);
				    }
	}
}
