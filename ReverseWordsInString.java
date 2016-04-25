package leetcode151_160;

/**Given an input string, reverse the string word by word.
 For example,
 Given s = "the sky is blue",
 return "blue is sky the".
 * Created by eugene on 16/3/10.
 */
public class ReverseWordsInString {

    public static void main(String[] args){
        System.out.println(new ReverseWordsInString().reverseWords("a"));
    }

    public String reverseWords(String s) {
        if (s.length()==0) return "";
        String trimed = s.trim();
        if (trimed.length()==0) return "";
        String[] strings = trimed.split("\\s+");
        StringBuilder builder = new StringBuilder();
        for (int i=strings.length-1; i>=0; i--){
            builder.append(strings[i]+" ");
        }
        return builder.toString().trim();
    }

}
