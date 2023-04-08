# Concepts:
1. Binary trees - each node can have at max of 2 childs
2. root node
3. child node
4. leaf node
5. subtree -- node and its decendants
6. ancestors
7. Types of binary trees - 
   1. Full binary tree - every node will have 0 or 2 children
   2. Complete binary tree - 
      1. all levels are completely filled except the last level (completely filing the last level is optional)
      2. the last level has all the nodes as left as possible - if not completely filled
   3. Perfect binary tree - all leaf nodes are at the same level
   4. balanced binary tree - height can be at max - log(n) - where n = number of nodes
   5. degenerate tree -- skew tree -- all nodes appear to be in a same single line
8. Traversals in trees
   1. Depth first search
      1. Inorder - left - root - right
      2. PreOrder - root - left - right
      3. PostOrder - left right root
   2. Breadth first search - level order traversal



# Questions

## Question-1: [Reverse Level Order Traversal](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118521/offering/1380977)

### Statement
You have been given a Binary Tree of integers. You are supposed to return the reverse of the level order traversal.

### Solution

```c++
vector<int> reverseLevelOrder(TreeNode<int> *root){
    // Write your code here.
    vector<int> res;
    if(root == NULL) {
        return res;
    }
    queue<TreeNode<int>*> nodesQueue;
    nodesQueue.push(root);
    while(!nodesQueue.empty()) {
        TreeNode<int>* front = nodesQueue.front();
        nodesQueue.pop();
        res.push_back(front -> val);
        if(front -> left != NULL) {
            nodesQueue.push(front -> left);
        }
        if(front -> right != NULL) {
            nodesQueue.push(front -> right);
        }
    }
    int n = res.size();
    int start = 0, end = n-1;
    while(start < end) {
        int temp = res[start];
        res[start] = res[end];
        res[end] = temp;
        start++; end--;
    }
    return res;
}
```

## Question 2: [Boundary Traversal of binary tree](https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1)

### Statement
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
```
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
```
   
Output: 1 2 4 8 9 6 7 3

### Solution
#### Explanation
- Basically we divide this into three parts (in this order)
  - First, traverse the left side
    - If for a node - left node is NULL, then we need to go into the right child
  - Traverse the leaf nodes (left -> right)
  - Traverse the right side (right most nodes should appear first)
    - If for a node - right node is NULL, then we need to go into the left child


```c++
void leftTraversal(Node* node, vector<int>& res) {
    if(node == NULL) {
        return;
    }
    if(node -> left == NULL && node -> right == NULL) {
        return;
    }
    res.push_back(node -> data);
    if(node -> left != NULL) {
        leftTraversal(node -> left, res);
    } else {
        leftTraversal(node -> right, res);
    }
}

void leafTraversal(Node* node, vector<int>& res) {
    if(node == NULL) {
        return;
    }
    if(node -> left == NULL && node -> right == NULL) {
        res.push_back(node -> data);
    }
    leafTraversal(node -> left, res);
    leafTraversal(node -> right, res);
}

void rightTraversal(Node* node, vector<int>& res) {
    if(node == NULL) {
        return;
    }
    if(node -> left == NULL && node -> right == NULL) {
        return;
    }
    
    if(node -> right != NULL) {
        rightTraversal(node -> right, res);
    } else {
        rightTraversal(node -> left, res);
    }
    res.push_back(node -> data);
}

vector <int> boundary(Node *root)
{
    //Your code here
    vector<int> res;
    res.push_back(root -> data);
    leftTraversal(root -> left, res);
    if(root -> left != NULL || root -> right != NULL) {
        leafTraversal(root, res);
    }
    rightTraversal(root -> right, res);
    return res;
}
```
## Question 3: [Preorder Traversal](https://practice.geeksforgeeks.org/problems/preorder-traversal/1)

### Statement
Given a binary tree, find its preorder traversal.
Input:
```
        1      
      /          
    4    
  /    \   
4       2
```
Output: 1 4 4 2 

### Solution

```c++
void helperRec(Node* root, vector<int>& output) {
    if(root == NULL) {
        return;
    }
    output.push_back(root -> data);
    helper(root -> left, output);
    helper(root -> right, output);
}

vector<int> helperIterate(Node* root) {
    stack<Node*> nodeStk;
    vector<int> res;
    Node* node = root;
    while(node != NULL) {
        res.push_back(node -> data);
        nodeStk.push(node);
        node = node -> left;
    }
    while(!nodeStk.empty()) {
        node = nodeStk.top();
        nodeStk.pop();
        Node* rightNode = node -> right;
        while(rightNode != NULL) {
            res.push_back(rightNode -> data);
            nodeStk.push(rightNode);
            rightNode = rightNode -> left;
        }
    }
    return res;
}

vector <int> preorder(Node* root) {
    return helperIterate(root);
    vector<int> output;
    helper(root, output);
    return output;
}
```
## Question 4: [Inorder Traversal](https://practice.geeksforgeeks.org/problems/inorder-traversal/1)

### Statement
Given a Binary Tree, find the In-Order Traversal of it.

Example 1:

Input:
```
       1
     /  \
    3    2
```
Output: 3 1 2

### Solution

```c++
void helper(Node* root, vector<int>& output) {
    if(root == NULL) {
        return;
    }
    helper(root -> left, output);
    output.push_back(root -> data);
    helper(root -> right, output);
}

vector<int> helperIterate(Node* root) {
    vector<int> res;
    stack<Node*> nodeStack;
    Node* node = root;
    while(node != NULL) {
        nodeStack.push(node);
        node = node -> left;
    }
    while(!nodeStack.empty()) {
        node = nodeStack.top();
        nodeStack.pop();
        res.push_back(node -> data);
        node = node -> right;
        while(node != NULL) {
            nodeStack.push(node);
            node = node -> left;
        }
    }
    return res;
}

vector<int> inOrder(Node* root) {
    // Your code here
    return helperIterate(root);
    vector<int> output;
    helper(root, output);
    return output;
}
```

## Question 5: [PostOrder traversal](https://practice.geeksforgeeks.org/problems/postorder-traversal/1)

### Statement
Given a binary tree, find the Postorder Traversal of it.
Input:
```
       19
     /    \
    10     8
  /    \
 11    13
 ```
Output: 11 13 10 8 19

### Solution
```c++
void helper(Node* root, vector<int>& output) {
    if(root == NULL) {
        return;
    }
    helper(root -> left, output);
    helper(root -> right, output);
    output.push_back(root -> data);
}

vector<int> helperIterate(Node* root) {
    vector<int> res;
    stack<Node*> nodeStack;
    while(root != NULL) {
        nodeStack.push(root);
        root = root -> left;
    }
    Node* prev = NULL;
    while(!nodeStack.empty()) {
        Node* node = nodeStack.top();
        if(node -> right == prev || node -> right == NULL) {
            res.push_back(node -> data);
            prev = node;
            nodeStack.pop();
        } else {
            Node* rightNode = node -> right;
            while(rightNode != NULL) {
                nodeStack.push(rightNode);
                rightNode = rightNode -> left;
            }
        }
    }
    return res;
}

vector <int> postOrder(Node* root)
{
    // Your code here
    return helperIterate(root);
    vector<int> output;
    helper(root, output);
    return output;
}
```

## Question 6: [LevelOrder traversal](https://practice.geeksforgeeks.org/problems/level-order-traversal/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab)

### Statement
Given a binary tree, find its level order traversal.
Input:
```
    1
  /   \ 
 3     2
 ```
Output:1 3 2

### Solution

```c++
vector<int> levelOrder(Node* node)
{
    vector<int> res;
    if(node == NULL) {
        return res;
    }
    queue<Node*> nodesQueue;
    nodesQueue.push(node);
    while(!nodesQueue.empty()) {
        Node* frontNode = nodesQueue.front();
        nodesQueue.pop();
        res.push_back(frontNode -> data);
        if(frontNode -> left != NULL) {
            nodesQueue.push(frontNode -> left);
        }
        if(frontNode -> right != NULL) {
            nodesQueue.push(frontNode -> right);
        }
    }
    return res;
}
```

## Question 7: Get preorder/postorder/inorder in one iteration

### Statement
Get preorder/postorder/inorder in one iteration

### Solution

```c++
void oneTraverse(Node* node, vector<int> preOrderList, vector<int>& postOrderList, vector<int>& inOrderList) {
    stack<pair<<Node*, int>> nodesStack;
    if(node == NULL) {
        return;
    }
    nodeStack.push(make_pair(node, 1));
    while(!nodesStack.empty()) {
        pair<Node*, int> topPair = nodesStack.top();
        nodesStack.pop();
        Node* node = topPair.first;
        int num = topPair.second;
        if(num == 1) {
            preOrderList.push_back(node -> data);
            num++;
            nodeStack.push(make_pair(node, num));
            if(node -> left != NULL) {
                nodeStack.push(make_pair(node->left, 1));
            }
        } else if(num == 2) {
            inOrderList.push_back(node -> data);
            num++;
            nodeStack.push(make_pair(node, num));
            if(node -> right != NULL) {
                nodeStack.push(make_pair(node->right, 1));
            }
        } else if(num == 3) {
            postOrderList.push_back(node -> data);
        }
    }
}
```
#### Explanation:
1. Consider a stack of pair<Node*, int>
2. Insert (root, 1)
3. Get the top pair from stack - node and num, and pop it
4. if num == 1
   1. insert the node->data in preorder list
   2. num++
   3. re-insert (node, num) pair with incremented value of num
   4. if node->left != NULL
      1. insert (node->left, 1) in stack
5. if num == 2
   1. insert the node->data in inorder list
   2. num++
   3. re-insert (node, num) pair with incremented value of num
   4. if node->right != NULL
      1. insert (node->right, 1) in stack
6. if num == 3
   1. insert the node->data in postorder list
7. Repeat step 3 untill there are no further pairs in stack

## Question 8: [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/description/)

### Statement
Given a binary tree, determine if it is 
height-balanced.

Input: root = [3,9,20,null,null,15,7]
Output: true
![image1](https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg)

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
![image2](https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg)

### Solution
```c++
pair<bool, int> helperFxn(TreeNode* node) {
    pair<bool, int> output;
    if(node == NULL) {
        output.first = true;
        output.second = 0;
        return output;
    }
    pair<bool, int> leftOutput = helperFxn(node -> left);
    pair<bool, int> rightOutput = helperFxn(node -> right);
    bool isThisBalanced = false;
    if(leftOutput.first && rightOutput.first && abs(leftOutput.second - rightOutput.second) <= 1) {
        isThisBalanced = true;
    }
    int thisHeight = 1 + max(leftOutput.second, rightOutput.second);
    output.first = isThisBalanced;
    output.second = thisHeight;
    return output;
}

int solve(TreeNode* node) {
    if(node == NULL) {
        return 0;
    }
    int leftRes = solve(node -> left);
    int rightRes = solve(node -> right);
    if(leftRes == (-1) || rightRes == (-1)) {
        return -1;
    }
    if(abs(leftRes - rightRes) > 1) {
        return -1;
    }
    return 1+max(leftRes, rightRes);
}

bool isBalanced(TreeNode* root) {
    int res = solve(root);
    return (res == (-1) ? false : true);
    //return helperFxn(root).first;
}
```

## Question 9: [Diameter of a Binary Tree](https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1)

### Statement:
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).

Input:
```
 1
/ \
2  3
```
Output: 3

### Solution:
```c++
pair<int, int> diameterHeight(TreeNode* node) {
    // dia, height
    pair<int, int> output;
    if(node == NULL) {
        output.first = 0;
        output.second = 0;
        return output;
    }
    if(node -> left == NULL && node -> right == NULL) {
        output.first = 0;
        output.second = 1;
        return output;
    }
    pair<int, int> leftDiaHeight = diameterHeight(node -> left);
    pair<int, int> rightDiaHeight = diameterHeight(node -> right);
    int thisHeight = max(leftDiaHeight.second, rightDiaHeight.second) + 1;
    int thisDiameter = max(max(rightDiaHeight.first, leftDiaHeight.first), (leftDiaHeight.second + rightDiaHeight.second + 1));
    output.first = thisDiameter;
    output.second = thisHeight;
    return output;
}

int diameterOfBinaryTree(TreeNode* root) {
    int count = diameterHeight(root).first; // This is the count of nodes for the given diameter.
    // So to get the count of edges - substract 1 from nodes count
    if(count > 0) {
        return count-1;
    }
    return count;
}
```

## Question 10: [Maximum path sum from any node](https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article)

### Statement:
Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

Input:
```
     10
    /  \
   2   -25
  / \  /  \
 20 1  3  4
 ```
Output: 32
Explanation: Path in the given tree goes
like 10 , 2 , 20 which gives the max
sum as 32.

### Solution
```c++
int solve(TreeNode* root, int& maxx) {
    if(root == NULL) {
        return 0;
    }

    int leftMaxSum = solve(root -> left, maxx);
    leftMaxSum = max(leftMaxSum, 0);

    int rightMaxSum = solve(root -> right, maxx);
    rightMaxSum = max(rightMaxSum, 0);

    int uSum = root -> val + leftMaxSum + rightMaxSum; // left + currentNode + right
    maxx = max(maxx, uSum);

    int thisSum = root -> val + max(rightMaxSum, leftMaxSum);
    return thisSum;
}

int maxPathSum(TreeNode* root) {
    int maxx = INT_MIN;
    int res = solve(root, maxx);
    return max(res, maxx);
}
```
#### Explanation
1. We need to keep track of two kind of sums
   1. A "line-seg" sum
      1. either left-sum + currNode, or
      2. right-sum + currNode
   2. A "inverted U" sum
      1. left-sum + currNode + right-sum
2. And get the maximum of both the sums from this.


## Question 11: [Determine if Two Trees are Identical](https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article)

### Statement:
Given two binary trees, the task is to find if both of them are identical or not.

Input:
```
     1          1
   /   \      /   \
  2     3    2     3
```
Output: Yes

### Solution:
```c++
bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    if(r1 == NULL && r2 == NULL) {
        return true;
    }
    if(r1 == NULL) {
        return false;
    } else if(r2 == NULL) {
        return false;
    }
    if(r1 -> data != r2 -> data) {
        return false;
    }
    return (isIdentical(r1 -> left, r2 -> left) && isIdentical(r1 -> right, r2 -> right));
}
```
## Question 12: [zig-zag tree traversal](https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article)

### Statement
Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

Input:
```
        1
      /   \
     2     3
    / \   /  \
   4   5 6    7
```
Output:
1 3 2 4 5 6 7

### Solution
```c++
vector <int> zigZagTraversal(Node* root)
{
    vector<int> res;
    if(root == NULL) {
        return res;
    }
    queue<Node*> nq;
    nq.push(root);
    int level = -1;
    while(!nq.empty()) {
        int size = nq.size();
        vector<int> thisRow(size, 0);
        level++;
        for(int i = 0; i < size; i++) {
            Node* node = nq.front();
            nq.pop();
            if(level & 1) {
                // odd level
                thisRow[size-1-i] = node -> data;
            } else {
                // even level
                thisRow[i] = node -> data;
            }
            if(node -> left != NULL) {
                nq.push(node -> left);
            }
            if(node -> right != NULL) {
                nq.push(node -> right);
            }
        }
        for(int i = 0; i < size; i++) {
            res.push_back(thisRow[i]);
        }
        
    }
    return res;
    // Code here
}
```

## Question 13: [Vertical Traversal of Binary Tree](https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1)

### Statement
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Input:
```
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9  
```         
Output: 
4 2 1 5 6 3 8 7 9

### Solution
```c++
vector<int> verticalOrder(Node *root)
{
    //Your code here
    map<int, vector<int> > hdNodes;
    queue<pair <Node*, int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()) {
        pair <Node*, int> frontPair = q.front();
        q.pop();
        int hd = frontPair.second;
        if(hdNodes.find(hd) == hdNodes.end()) {
            vector<int> thisRes;
            thisRes.push_back(frontPair.first -> data);
            hdNodes[hd] = thisRes;
        } else {
            hdNodes[hd].push_back(frontPair.first -> data);
        }
        if(frontPair.first -> left != NULL) {
            q.push(make_pair(frontPair.first -> left, hd-1));
        }
        if(frontPair.first -> right != NULL) {
            q.push(make_pair(frontPair.first -> right, hd+1));
        }
    }
    vector<int> res;
    map<int, vector<int> >::iterator itr;
    for(itr = hdNodes.begin(); itr != hdNodes.end(); ++itr) {
        for(int i = 0; i < itr -> second.size(); i++) {
            res.push_back(itr -> second[i]);
        }
    }
    return res;
}
```

## Question 14: [Top View of Binary Tree](https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article)

### Statement: 
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree
```
       1
    /     \
   2       3
  /  \    /   \
4    5  6      7
```
Top view will be: 4 2 1 3 7

### Solution
```c++
vector<int> topView(Node *root)
{
    //Your code here
    vector<int> res;
    if(root == NULL) {
        return res;
    }
    unordered_map<int, int> topViewNodes;
    int minHd = INT_MAX;
    queue<pair<int, Node*>> nq;
    pair<int, Node*> firstPair;
    firstPair.first = 0;
    firstPair.second = root;
    nq.push(firstPair);
    while(!nq.empty()) {
        int levelSize = nq.size();
        for(int i = 0; i < levelSize; i++) {
            pair<int, Node*> thisPair = nq.front();
            nq.pop();
            int hd = thisPair.first;
            Node* node = thisPair.second;
            if(topViewNodes.find(hd) == topViewNodes.end()) {
                topViewNodes[hd] = node -> data;
            }
            minHd = min(minHd, hd);
            if(node -> left != NULL) {
                pair<int, Node*> leftPair;
                leftPair.first = hd-1;
                leftPair.second = node -> left;
                nq.push(leftPair);
            }
            if(node -> right != NULL) {
                pair<int, Node*> rightPair;
                rightPair.first = hd+1;
                rightPair.second = node -> right;
                nq.push(rightPair);
            }
        }
    }
    while(topViewNodes.find(minHd) != topViewNodes.end()) {
        res.push_back(topViewNodes[minHd]); minHd++;
    }
    return res;
}
```

## Question 15: [Bottom View of Binary Tree](https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article)

### Statement:
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.
```
                      20
                    /   \
                  8      22
                /   \      \
              5      3      25
                    / \      
                  10  14
```
For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.
```
                      20
                    /    \
                  8       22
                /   \     /  \
              5      3   4    25
                     /   \      
                 10      14
```
For the above tree the output should be 5 10 4 14 25.

### Solution:
```c++
vector<int> bottom1View(BinaryTreeNode<int> *root)
{
    //Your code here
    vector<int> res;
    if(root == NULL) {
        return res;
    }
    unordered_map<int, int> topViewNodes;
    int minHd = INT_MAX;
    queue<pair<int, BinaryTreeNode<int>*>> nq;
    pair<int, BinaryTreeNode<int>*> firstPair;
    firstPair.first = 0;
    firstPair.second = root;
    nq.push(firstPair);
    while(!nq.empty()) {
        int levelSize = nq.size();
        for(int i = 0; i < levelSize; i++) {
            pair<int, BinaryTreeNode<int>*> thisPair = nq.front();
            nq.pop();
            int hd = thisPair.first;
            BinaryTreeNode<int>* node = thisPair.second;
            topViewNodes[hd] = node -> data;
            minHd = min(minHd, hd);
            if(node -> left != NULL) {
                pair<int, BinaryTreeNode<int>*> leftPair;
                leftPair.first = hd-1;
                leftPair.second = node -> left;
                nq.push(leftPair);
            }
            if(node -> right != NULL) {
                pair<int, BinaryTreeNode<int>*> rightPair;
                rightPair.first = hd+1;
                rightPair.second = node -> right;
                nq.push(rightPair);
            }
        }
    }
    while(topViewNodes.find(minHd) != topViewNodes.end()) {
        res.push_back(topViewNodes[minHd]); minHd++;
    }
    return res;
}
```

## Question 16: [Left View of Binary Tree](https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article)

### Statement:
Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.
```
          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8
```

### Solution:
```c++
vector<int> leftView(TreeNode<int> *root)
{
    //Your code here
    vector<int> res;
    if(root == NULL) {
        return res;
    }
    unordered_map<int, int> leftViewNodes;
    int minVd = 0;
    queue<pair<int, TreeNode<int>*>> nq;
    pair<int, TreeNode<int>*> firstPair;
    firstPair.first = 0;
    firstPair.second = root;
    nq.push(firstPair);
    while(!nq.empty()) {
        int levelSize = nq.size();
        for(int i = 0; i < levelSize; i++) {
            pair<int, TreeNode<int>*> thisPair = nq.front();
            nq.pop();
            int vd = thisPair.first;
            TreeNode<int>* node = thisPair.second;
            if(i == 0 && leftViewNodes.find(vd) == leftViewNodes.end()) {
                leftViewNodes[vd] = node -> data;
            }
            if(node -> left != NULL) {
                pair<int, TreeNode<int>*> leftPair;
                leftPair.first = vd+1;
                leftPair.second = node -> left;
                nq.push(leftPair);
            }
            if(node -> right != NULL) {
                pair<int, TreeNode<int>*> rightPair;
                rightPair.first = vd+1;
                rightPair.second = node -> right;
                nq.push(rightPair);
            }
        }
    }
    while(leftViewNodes.find(minVd) != leftViewNodes.end()) {
        res.push_back(leftViewNodes[minVd]); minVd++;
    }
    return res;
}
```

## Question 17: [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/description/)

### Statement:
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
![Alt text](https://assets.leetcode.com/uploads/2021/02/14/tree.jpg)

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

### Solution:
```c++
vector<int> rightView(TreeNode *root)
{
    //Your code here
    vector<int> res;
    if(root == NULL) {
        return res;
    }
    unordered_map<int, int> leftViewNodes;
    int minVd = 0;
    queue<pair<int, TreeNode*>> nq;
    pair<int, TreeNode*> firstPair;
    firstPair.first = 0;
    firstPair.second = root;
    nq.push(firstPair);
    while(!nq.empty()) {
        int levelSize = nq.size();
        for(int i = 0; i < levelSize; i++) {
            pair<int, TreeNode*> thisPair = nq.front();
            nq.pop();
            int vd = thisPair.first;
            TreeNode* node = thisPair.second;
            if(i == levelSize-1 && leftViewNodes.find(vd) == leftViewNodes.end()) {
                leftViewNodes[vd] = node -> val;
            }
            if(node -> left != NULL) {
                pair<int, TreeNode*> leftPair;
                leftPair.first = vd+1;
                leftPair.second = node -> left;
                nq.push(leftPair);
            }
            if(node -> right != NULL) {
                pair<int, TreeNode*> rightPair;
                rightPair.first = vd+1;
                rightPair.second = node -> right;
                nq.push(rightPair);
            }
        }
    }
    while(leftViewNodes.find(minVd) != leftViewNodes.end()) {
        res.push_back(leftViewNodes[minVd]); minVd++;
    }
    return res;
}
```
## Question 18: [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/description/)

### Statement:
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Input: root = [1,2,2,3,4,4,3]
Output: true

![Alt text](https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg)

### Solution:
```c++
bool solve(TreeNode* node1, TreeNode* node2) {
    if(node1 == NULL && node2 == NULL) {
        return true;
    }
    if(node1 == NULL || node2 == NULL) {
        return false;
    }
    if(node1 -> val != node2 -> val) {
        return false;
    }
    bool res1 = solve(node1 -> left, node2 -> right);
    bool res2 = solve(node1 -> right, node2 -> left);
    return res1 && res2;
}
bool isSymmetric(TreeNode* root) {
    //bool res = false;
    if(root == NULL) {
        return true;
    }
    return solve(root -> left, root -> right);
}
```

## Question 19: [Path in a tree](https://www.codingninjas.com/codestudio/problems/path-in-a-tree_3843990?leftPanelTab=0)

### Statement:
You are given a binary tree with ‘N’ number of nodes and a node ‘X’. Your task is to print the path from the root node to the given node ‘X’.
A binary tree is a hierarchical data structure in which each node has at most two children.

Sample Input 1 : 
```
2
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
7
3 2 1 -1 -1 -1 -1
1
```
Sample Output 1 :
```
1 3 7
3 1
```

### Solution
```c++
bool solve(TreeNode<int>* node, int x, vector<int>& res) {
	if(node == NULL) {
		return false;
	}
	if(node -> data == x) {
		res.push_back(node -> data);
		return true;
	}
	if(solve(node -> left, x, res)) {
		res.push_back(node -> data);
		return true;
	} else if(solve(node -> right, x, res)) {
		res.push_back(node -> data);
		return true;
	}
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> res;
	bool foundx = solve(root, x, res);
	int h = res.size()-1;
	int l = 0;
	while(l <= h) {
		int temp = res[l];
		res[l] = res[h];
		res[h] = temp;
		l++; h--;
	}
	return res;
}
```
## Question 20: [Lowest Common Ancestor Of Binary Tree](https://www.codingninjas.com/codestudio/problems/lca-of-binary-tree_920541?leftPanelTab=0)

### Statement:
Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

Input:
n1 = 2 , n2 = 3  
```
       1 
      / \ 
     2   3
```
Output: 1

### Solution:

```c++
TreeNode<int>* solve(TreeNode<int>* root, int x, int y) {
    if(root == NULL) {
        return root;
    }
    if(root -> data == x || root -> data == y) {
        return root;
    }
    TreeNode<int>* leftRes = solve(root -> left, x, y);
    TreeNode<int>* rightRes = solve(root -> right, x, y);
    if(leftRes != NULL && rightRes != NULL) {
        return root;
    }
    return (leftRes == NULL) ? rightRes : leftRes;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    return solve(root, x, y) -> data;
}
```

## Question 21: [Maximum Width of Tree](https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article)

### Statement
Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes at any level.
For example, 
the maximum width of the following tree is 4 as there are 4 nodes at the 3rd level.
```
          1
       /     \
     2        3
   /    \    /    \
  4    5   6    7
    \
      8
```

### Solution
```c++
int getMaxWidth(Node* root) {

    // Your code here
    int maxWidth = 0;
    queue<Node*> nq;
    nq.push(root);
    while(!nq.empty()) {
        int lvlSize = nq.size();
        maxWidth = max(maxWidth, lvlSize);
        for(int i = 0; i < lvlSize; i++) {
            Node* front = nq.front();
            nq.pop();
            if(front -> left != NULL) {
                nq.push(front -> left);
            }
            if(front -> right != NULL) {
                nq.push(front -> right);
            }
        }
    }
    return maxWidth;
}
```

## Question 22: [Check children sum property](https://practice.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article)

### Statement:
Given a Binary Tree. Check whether all of its nodes have the value equal to the sum of their child nodes.

Input:
```
     10
    /
  10
```
Output: 1

### Solution:
```c++
pair<bool, int> helper(Node* root) {
    pair<bool, int> res;
    res.first = true; res.second = 0;
    if(root == NULL) {
        return res;
    }
    if(!root -> left && !root -> right) {
        res.second = root -> data;
        return res;
    }
    pair<bool, int> leftRes = helper(root -> left);
    pair<bool, int> rightRes = helper(root -> right);
    int allChildSum = leftRes.second + rightRes.second;
    if(leftRes.first && rightRes.first && root -> data == allChildSum) {
        res.first = true;
    } else {
        res.first = false;
    }
    res.second = root -> data; // + allChildSum;
    return res;
}
int isSumProperty(Node *root)
{
    pair<bool, int> res = helper(root);
    return res.first;
    // Add your code here
}
```

## Question 23: [Children sum property - edit tree](https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?leftPanelTab=0)

### Statement:
Given a binary tree of nodes 'N', you need to modify the value of its nodes, such that the tree holds the Children sum property.

A binary tree is said to follow the children sum property if, for every node of that tree, the value of that node is equal to the sum of the value(s) of all of its children nodes( left child and the right child).

input - 
![alt-image](https://files.codingninjas.in/screenshot-from-2020-10-09-12-55-59-5133.png)

output - 
![alt-image-output](https://files.codingninjas.in/screenshot-from-2020-10-09-12-56-05-5132.png)

### Solution:
```c++
void solve(BinaryTreeNode < int > * root) {
    if(root == NULL) {
        return;
    }
    if(root -> left == NULL && root -> right == NULL) {
        return;
    }
    int childSum = 0;
    if(root -> left != NULL) {
        childSum += root -> left -> data;
    }
    if(root -> right != NULL) {
        childSum += root -> right -> data;
    }
    if(childSum < root -> data) {
        if(root -> left != NULL) {
            root -> left -> data = root ->data;
        }
        if(root -> right != NULL) {
            root -> right -> data = root ->data;
        }
    } else {
        root -> data = childSum;
    }
    solve(root -> left);
    solve(root -> right);

    int finalRes = 0;
    if(root -> left != NULL) {
        finalRes += root -> left -> data;
    }
    if(root -> right != NULL) {
        finalRes += root -> right -> data;
    }
    root -> data = finalRes;

}
```

## Question 24: [Nodes at given distance in binary tree](https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article)

### Statement
Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. No parent pointers are available.
Note: You have to return list in sorted order.

Input:      
```
          20
        /    \
      8       22 
    /   \
   4    12 
       /   \
      10    14
```
Target Node = 8
K = 2

Output: 10 14 22

### Solution
#### Explanation
1. Get a parent mapping and a visited mapping
2. Get the target node
3. Get the nodes at distance k
   1. While going through each child and parent - subtract 1 from k
   2. when k == 0 -- this is the node we want in our answer
   3. in this process, skip those which were already visited

```c++
void getParentsAndVisited(Node* node, unordered_map<int, Node*>& parentMap, unordered_map<int, bool>& visited) {
    if(node == NULL) {
        return;
    }
    if(node -> left != NULL) {
        parentMap[node -> left -> data] = node;
    }
    if(node -> right != NULL) {
        parentMap[node -> right -> data] = node;
    }
    visited[node -> data] = false;
    getParentsAndVisited(node -> left, parentMap, visited);
    getParentsAndVisited(node -> right, parentMap, visited);
}

Node* getNode(Node* root, int target) {
    if(root == NULL) {
        return NULL;
    }
    if(root -> data == target) {
        return root;
    }
    Node* leftRes = getNode(root -> left, target);
    if(leftRes != NULL) {
        return leftRes;
    }
    
    Node* rightRes = getNode(root -> right, target);
    if(rightRes != NULL) {
        return rightRes;
    }
    return NULL;
}

void getNodesAtK(Node* node, int k, unordered_map<int, Node*>& parentMap, unordered_map<int, bool>& visited, vector<int>& res) {
    if(node == NULL || k < 0 || visited[node -> data]) {
        return;
    }
    
    if(k == 0) {
        visited[node -> data] = true;
        res.push_back(node -> data);
        return;
    }
    visited[node -> data] = true;
    
    getNodesAtK(node -> left, k-1, parentMap, visited, res);
    getNodesAtK(node -> right, k-1, parentMap, visited, res);
    
    if(parentMap.find(node -> data) != parentMap.end()) {
        getNodesAtK(parentMap[node -> data], k-1, parentMap, visited, res);
    }
}

vector <int> KDistanceNodes(Node* root, int target , int k)
{
    vector<int> res;
    unordered_map<int, Node*> parentMap;
    unordered_map<int, bool> visited;
    
    getParentsAndVisited(root, parentMap, visited);
    
    Node* targetNode = getNode(root, target);
    if(targetNode == NULL) {
        return res;
    }
    
    getNodesAtK(targetNode, k, parentMap, visited, res);
    
    sort(res.begin(), res.end());
    return res;
}
```

## Question 25: [Burning Tree](https://practice.geeksforgeeks.org/problems/burning-tree/1)

### Statement:
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.

Input:    
```
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
```
Target Node = 8

Output: 7

Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.

### Solution
#### Explanation
1. Get the parent and visited mapping
2. Get the target node
3. Do a BFS traverse the tree in 3 directions
   1. left child
   2. right child
   3. parent
4. Get the last level -- this is our answer

```c++
void getParentAndVisited(Node* node, unordered_map<int, Node*>& parentMap, unordered_map<int, bool>& visited) {
    if(node == NULL) {
        return;
    }
    visited[node -> data] = false;
    if(node -> left != NULL) {
        parentMap[node -> left -> data] = node;
    }
    if(node -> right != NULL) {
        parentMap[node -> right -> data] = node;
    }
    getParentAndVisited(node -> left, parentMap, visited);
    getParentAndVisited(node -> right, parentMap, visited);
}

Node* getTargetNode(Node* node, int target) {
    if(node == NULL) {
        return node;
    }
    if(node -> data == target) {
        return node;
    }
    Node* leftRes = getTargetNode(node -> left, target);
    if(leftRes != NULL) {
        return leftRes;
    }
    Node* rightRes = getTargetNode(node -> right, target);
    return rightRes;
}

int BFS(Node* node, unordered_map<int, Node*>& parentMap, unordered_map<int, bool>& visited) {
    if(node == NULL) {
        return 0;
    }
    queue<Node*> q;
    q.push(node);
    int lvl = -1;
    while(!q.empty()) {
        lvl++;
        int lvlSize = q.size();
        for(int i = 0; i < lvlSize; i++) {
            Node* front = q.front();
            q.pop();
            visited[front -> data] = true;
            
            if(front -> left != NULL && !visited[front -> left -> data]) {
                q.push(front -> left);
            }
            if(front -> right != NULL && !visited[front -> right -> data]) {
                q.push(front -> right);
            }
            
            Node* parent = NULL;
            if(parentMap.find(front -> data) != parentMap.end()) {
                parent = parentMap[front->data];
            }
            if(parent != NULL && !visited[parent -> data]) {
                q.push(parent);
            }
        }
        //cout << lvl;
    }
    return lvl;
}

int minTime(Node* root, int target) 
{
    unordered_map<int, bool> visited;
    unordered_map<int, Node*> parentMap;
    getParentAndVisited(root, parentMap, visited);
    
    Node* targetNode = getTargetNode(root, target);
    //return targetNode -> data;
    return BFS(targetNode, parentMap, visited);
}
```

## Question 26: [Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/description/)

### Statement:
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

Input: root = [1,2,3,4,5,6]

![Alt text](https://assets.leetcode.com/uploads/2021/01/14/complete.jpg)

Output: 6

### Solution:
1. Given is that this is a complete binary tree
2. For a given node
   1. Get the left height - by traversing only left childs
   2. Get the right height - by traversing only right childs
   3. if leftHeight == rightHeight
      1. get the total count of nodes as ```(2^height)-1```
   4. if not equal
      1. Then get the count of left sub tree and right sub tree individually
      2. total count = ```1 + solve(root -> left) + solve(root -> right)```
```c++
int getLeftHeight(TreeNode* node) {
    if(node == NULL) {
        return 0;
    }
    return 1 + getLeftHeight(node -> left);
}

int getRightHeight(TreeNode* node) {
    if(node == NULL) {
        return 0;
    }
    return 1 + getRightHeight(node -> right);
}

int solve(TreeNode* root) {
    if(root == NULL) {
        return NULL;
    }
    int leftHeight = getLeftHeight(root);
    int rightHeight = getRightHeight(root);

    if(leftHeight == rightHeight) {
        return pow(2, leftHeight)-1;
    }

    return 1 + solve(root -> left) + solve(root -> right);
}

int countNodes(TreeNode* root) {
    return solve(root);
}
```