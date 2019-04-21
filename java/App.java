package leetcode21_30;

import java.io.IOException;
import java.util.Arrays;

/**
 * Created by Jian on 2015/7/28.
 */
public class App {
    public static void main(String[] args){
        System.out.println("*****RESULT*****");

        try {
            test();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static void test() throws IOException {
        int[] nums = {-1, 2, 1, -4};

        Arrays.sort(nums);
        for (int i : nums) System.out.print(i + " ");
    }

    private static void test(final String inputString) throws IOException {
    }

    private static class User{
        private String name;

        public User(String name) {
            this.name = name;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }
    }


}