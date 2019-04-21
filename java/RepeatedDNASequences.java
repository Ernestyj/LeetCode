package leetcode181_190;

import java.util.*;

/**All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
 Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
 For example, Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 Return: ["AAAAACCCCC", "CCCCCAAAAA"].
 * Created by eugene on 16/3/24.
 */
public class RepeatedDNASequences {

    //简洁
    public List<String> findRepeatedDnaSequences(String s) {
        HashSet seen = new HashSet(), repeated = new HashSet();
        for (int i = 0; i+10<=s.length(); i++) {
            String ten = s.substring(i, i+10);
            if (!seen.add(ten))
                repeated.add(ten);
        }
        return new ArrayList(repeated);
    }

    public List<String> findRepeatedDnaSequences1(String s) {
        List<String> result = new ArrayList<>();
        if (s.length()<10) return result;
        Map<String, Integer> map = new HashMap<>();
        for (int i=0; i<=s.length()-10; i++){
            String window = s.substring(i, i+10);
            if (!map.containsKey(window)) map.put(window, 1);
            else {
                int c = map.get(window);
                if (c==1) result.add(window);
                map.put(window, c+1);
            }
        }
        return result;
    }

}
