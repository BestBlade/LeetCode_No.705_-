/* ------------------------------------------------------------------|
不使用任何内建的哈希表库设计一个哈希集合（HashSet）。

实现 MyHashSet 类：

void add(key) 向哈希集合中插入值 key 。
bool contains(key) 返回哈希集合中是否存在这个值 key 。
void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
 
示例：

输入：
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
输出：
[null, null, null, true, false, null, true, null, false]

解释：
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // 返回 True
myHashSet.contains(3); // 返回 False ，（未找到）
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // 返回 True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // 返回 False ，（已移除）
 

提示：

0 <= key <= 106
最多调用 104 次 add、remove 和 contains 。
 

进阶：你可以不使用内建的哈希集合库解决此问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-hashset
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*  
*
*	执行用时：104 ms, 在所有 C++ 提交中击败了78.96%的用户
*	内存消耗：40.8 MB, 在所有 C++ 提交中击败了59.43%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class MyHashSet {
private:
    vector<list<int>> l;
    static const int hashkey = 727;
    static int hash(int &num) {
        return num % hashkey;
    }
public:
    /** Initialize your data structure here. */
    MyHashSet() :l(hashkey) {}

    void add(int key) {
        int tmp = hash(key);
        for (auto iter = l[tmp].begin(); iter != l[tmp].end(); ++iter) {
            if ((*iter) == key) {
                return;
            }
        }
        l[tmp].push_back(key);
    }

    void remove(int key) {
        int tmp = hash(key);
        for (auto iter = l[tmp].begin(); iter != l[tmp].end(); ++iter) {
            if ((*iter) == key) {
                l[tmp].erase(iter);
                return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int tmp = hash(key);
        for (auto iter = l[tmp].begin(); iter != l[tmp].end(); ++iter) {
            if ((*iter) == key) {
                return true;
            }
        }
        return false;
    }
};