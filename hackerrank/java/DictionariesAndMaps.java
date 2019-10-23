import java.util.*;
import java.io.*;

class Solution{
    public static void main(String []argh){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, String> mymap=new HashMap<String, String>(); 
        for(int i = 0; i < n; i++){
            String name = sc.next();
            String phone = sc.next();
            mymap.put(name,phone);            
        }
        while(sc.hasNext()){
            String s = sc.next();           
            if(mymap.containsKey(s))
                System.out.println(s+"="+mymap.get(s));
            else
                System.out.println("Not found");
        }
        sc.close();
    }
}
