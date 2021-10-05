class Solution {
    public boolean validMountainArray(int[] arr) {
        int n=arr.length;
        int[] diff=new int[n-1];
        int inc=0;
        int dec=0;
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            diff[i]=arr[i+1]-arr[i];
            if(diff[i]==0)
                return false;
            if(diff[i]>0 && dec==1)
                return false;
            else if(diff[i]>0 && inc==1)
                return false;
            else if(diff[i]>0)
                count++;
            if(diff[i]<0)
            {
                inc=1;
                dec=1;
                
            }
        }
        if(dec==1 && count>0)
            return true;
        return false;
        
    }
}
