package leetcode91_100;

/**
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 For example,
 Given n = 3, there are a total of 5 unique BST's.
 * Created by eugene on 16/1/16.
 */
public class UniqueBinarySearchTrees {

    public static void main(String[] args) {
        System.out.println("*****RESULT*****");
    }


    /**参考 http://fisherlei.blogspot.in/2013/03/leetcode-unique-binary-search-trees.html
     * 基于以下原则的BST建树具有唯一性：
     以i为根节点的树，其左子树由[0, i-1]构成， 其右子树由[i+1, n]构成。
     * 一维动态规划:二叉查找树可以任意取根，只要满足中序遍历有序的要求就可以。
     从处理子问题的角度来看，选取一个结点为根，就把结点切成左右子树，
     以这个结点为根的可行二叉树数量就是左右子树可行二叉树数量的乘积，
     所以总的数量是将以所有结点为根的可行结果累加起来。
     i=0, count[0]=1 //empty tree
     i=1, count[1]=1 //one tree
     i=2, count[2]=count[0]*count[1] // 1 is root
                + count[1]*count[0] // 2 is root
     Count[i] = ∑ Count[0...k] * [ k+1....i], 0<=k<=i-1 (卡特兰数)
     * 时间上每次求解i个结点的二叉查找树数量的需要一个i步的循环，总体要求n次，
     所以总时间复杂度是O(1+2+...+n)=O(n^2)。
     空间上需要一个数组来维护，并且需要前i个的所有信息，所以是O(n)。
     * @param n
     * @return
     */
    public int numTrees(int n) {
        int[] count = new int[n+1];
        count[0] = 1;
        count[1] = 1;
        for (int i=2; i<=n; i++){
            for (int k=0; k<=i-1; k++)
                count[i] += count[k] * count[i-k-1];
        }
        return count[n];
    }

}
