#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//int main() {
//    std::cout << "Hello, World!" << std::endl;
//
//    float f = 10.0/3;
//    cout<< f << endl;
//    return 0;
//}