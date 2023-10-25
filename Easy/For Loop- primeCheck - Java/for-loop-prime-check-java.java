//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {

        // taking input using Scanner class
        Scanner sc = new Scanner(System.in);

        // take testcases
        int t = sc.nextInt();
        while (t-- > 0) {
            // taking the number
            int n = sc.nextInt();
            Geeks obj = new Geeks();

            // caling isPrime method
            // with n as argument
            obj.isPrime(n);
        }
    }
}

// Position this line where user code will be pasted.

// } Driver Code Ends


// User function Template for Java

class Geeks {
    static void isPrime(int n) {
        if(n<=1){
            System.out.println("No");
            return ;
        }
        if(n==2 || n==3){
            System.out.println("Yes");
            return;
        }
        if(n%2 == 0){
            System.out.println("No");
            return;
        }
        boolean flag = true;
        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            // Your code here
            if(n%i == 0){
                flag = false;
                break;
            }
        }
        if(flag){
        System.out.println("Yes");
            
        }else{
            System.out.println("No");
        }
        
    }
}