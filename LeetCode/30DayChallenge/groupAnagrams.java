import java.util.*; 

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap <HashMap <Character, Integer>, ArrayList <String>> map = new HashMap <HashMap <Character, Integer>, ArrayList <String>>();
        
        for(String str : strs) {
            HashMap <Character, Integer> freq = new HashMap <Character, Integer>();
            for(int i = 0; i < str.length(); i++) {
                if(freq.containsKey(str.charAt(i))) {
                    int x = freq.get(str.charAt(i));
                    freq.put(str.charAt(i), ++x);
                }
                else 
                    freq.put(str.charAt(i), 1);
            }
            if(map.containsKey(freq)){
                ArrayList<String> s = map.get(freq);
                s.add(str);
            }
            else {
                ArrayList<String> s = new ArrayList<String>();
                s.add(str);
                map.put(freq, s);
            }
        }
        List<List<String>> ans = new ArrayList<List<String>>();
        for(HashMap<Character, Integer> key : map.keySet()) {
            ArrayList<String> s = map.get(key);
            ans.add(s);
        }
        return ans;
    
    }
}