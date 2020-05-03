public class Solution {
    public static void sort(int[] l) {
        int arr[] = new int[10];
        for(int i = 0; i < l.length; i++) 
            arr[l[i]]++;
        int index = 0;
        for(int j = 9; j > -1; j--) {
            while(arr[j] > 0) {
                l[index++] = j;
                arr[j]--;
            }
        }
    }
    public static int solution(int[] l) {
        // Your code here
        Solution.sort(l);
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < l.length; i++)
            sum += l[i];
        int rem = sum % 3;
        if(rem == 0) {
            for(int i = 0; i < l.length; i++)
                ans = ans * 10 + l[i];
            
                System.out.println("Ans" + ans);
                return ans;
        }
        else if(rem == 1) {
            int brr[] = new int[3];
            brr[0] = -1; brr[1] = -1; brr[2] = -1;
            for(int i = l.length - 1; i > -1; i--) {
                if(l[i] % 3 == 1) {
                    brr[0] = i;
                    break;
                }
                if(l[i] % 3 == 2) {
                    if(brr[1] == -1)
                        brr[1] = i;
                    if(brr[2] == -1)
                        brr[2] = i;
                }
            }
            if(brr[0] != -1) {
                for(int i = 0;  i < l.length; i++) {
                    if(i == brr[0])
                        continue;
                    ans = ans * 10 + l[i];
                }
            }
            if(brr[0] == -1 && brr[1] != -1 && brr[2] != -1) {
                for(int i = 0;  i < l.length; i++) {
                    if(i == brr[1] || i == brr[2])
                        continue;
                    ans = ans * 10 + l[i];
                }
            }
            System.out.println("Ans" + ans);
            return ans;
        }
        else if(rem == 2) {
            int brr[] = new int[3];
            brr[0] = -1; brr[1] = -1; brr[2] = -1;
            for(int i = l.length - 1; i > -1; i--) {
                if(l[i] % 3 == 2) {
                    brr[0] = i;
                    break;
                }
                if(l[i] % 3 == 1) {
                    if(brr[1] == -1)
                        brr[1] = i;
                    if(brr[2] == -1)
                        brr[2] = i;
                }
            }
            if(brr[0] != -1) {
                for(int i = 0;  i < l.length; i++) {
                    if(i == brr[0])
                        continue;
                    ans = ans * 10 + l[i];
                }
            }
            if(brr[0] == -1 && brr[1] != -1 && brr[2] != -1) {
                for(int i = 0;  i < l.length; i++) {
                    if(i == brr[1] || i == brr[2])
                        continue;
                    ans = ans * 10 + l[i];
                }
            }

            System.out.println("Ans" + ans); 
            return ans;
        }
        return ans;
    }
    public static void main(String[] args) {
        int arr[] = new int[6];
        System.out.println("Hello, World"); 
        arr[0] = 3; arr[1] = 1; arr[2] = 4; arr[3] = 1; arr[4] = 5; arr[5] = 9;
        Solution.solution(arr);
    }
}