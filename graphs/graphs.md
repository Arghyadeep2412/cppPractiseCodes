# Concepts
1. Undirected Graph - edges are undirected
2. Directed Graph - all the edges are directed
3. nodes/vertex
4. edge
   1. undirected edge
   2. directed edge - can only go along the 
5. cycles in a graph
   1. start on a node and reach back on the same node
6. path - 
   1. contains multiple nodes
   2. each node must appear once
   3. all the nodes are reachable
7. degrees of a node in a undirected graph - no. of edges attached with a node
8. total degree of a graph - sum of all individual node's degree
9. total degree of an undirected graph = 2 * (total number of edges)
10. For directed graph -
    1.  indegree - number of incoming edges
    2.  outdegree - number of outgoing edges
11. edge weight - a significant number for each weight
    1.  if not assigned any weight - default - consider it to be 1
12. if the graph has multiple components -- we would be using a visited array to traverse all the nodes

# QUESTIONS
## Question 1: [BFS of graph](https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?leftPanelTab=0)

### Statement:
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

### Solution
```c++
vector<int> graphBfs(int v, int startVertex, vector<vector<int>>& adjList, vector<bool>& visited) {
    vector<int> res;
    queue<int> q;
    //vector<int> res;
    for(int i = 0; i < v; i++) {
        if(visited[i]) {
            continue;
        }
        q.push(i);
        while(!q.empty()) {
            int lvlSize = q.size();
            for(int j = 0; j < lvlSize; j++) {
                int frontNode = q.front();
                q.pop();

                if(!visited[frontNode]) {
                    res.push_back(frontNode);
                }
                visited[frontNode] = true;
                for(int k = 0; k < adjList[frontNode].size(); k++) {
                    if(!visited[adjList[frontNode][k]]) {
                        q.push(adjList[frontNode][k]);
                    }
                }
            }
        }
    }
    return res;
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> res;
    vector<vector<int>> adjList(vertex, vector<int>());
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for(int i = 0; i < adjList.size(); i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }
    vector<bool> visited(vertex, false);
    return graphBfs(vertex, 0, adjList, visited);
}
```

## Question 2 :[DFS of graph](https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1)

### Statement:
You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use a recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.

### Solution:
```c++
void helper(int curr, vector<int> adj[], vector<bool>& visited, vector<int>& res) {
   if(visited[curr]) {
      return;
   }
   res.push_back(curr);
   visited[curr] = true;
   for(int i = 0; i < adj[curr].size(); i++) {
         helper(adj[curr][i], adj, visited, res);
   }
}
vector<int> dfsOfGraph(int v, vector<int> adj[]) {
   // Code here
   vector<int> res;
   vector<bool> visited(v, false);
   for(int i = 0; i < v; i++) { // for all disconnected components
      helper(i, adj, visited, res);
   }
   return res;
}
```

## Question 3: [Number of Provinces](https://practice.geeksforgeeks.org/problems/number-of-provinces/1)

### Statement:
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Input:
```
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]
```
Output: 2

### Solution:
```c++
int getProvinces(int sv, int v, vector<vector<int>>& adjList, vector<bool>& visited) {
   int count = 0;
   queue<int> q;
   for(int i = 0; i < v; i++) {
      if(visited[i]) {
            continue;
      }
      q.push(i);
      count++;
      while(!q.empty()) {
            int lvlSize = q.size();
            for(int j = 0; j < lvlSize; j++) {
               int frontNode = q.front();
               q.pop();

               if(!visited[frontNode]) {
                  //res.push_back(frontNode);
               }
               visited[frontNode] = true;
               for(int k = 0; k < adjList[frontNode].size(); k++) {
                  if(!visited[adjList[frontNode][k]]) {
                        q.push(adjList[frontNode][k]);
                  }
               }
            }
      }
   }
   return count;
}
int numProvinces(vector<vector<int>> adj, int v) {
   // code here
   vector<vector<int>> adjList(v, vector<int>());
   for(int i = 0; i < v; i++) {
      for(int j = 0; j < v; j++) {
            if(i == j) {
               continue;
            }
            if(adj[i][j] == 1) {
               adjList[i].push_back(j);
            }
      }
   }
   vector<bool> visited(v, false);
   return getProvinces(0, v, adjList, visited);
}
```

## Question 4: [Find the number of islands](https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1)

### Statement:
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}

Output:
1

Explanation:
The grid is-
```
0 1
1 0
1 1
1 0
```
All lands are connected.

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
```
0 1 1 1 0 0 0
0 0 1 1 0 1 0
```
There are two islands :- one is colored in blue 
and other in orange

### Solution:

#### Explanation
1. Traver the matrix as DFS of BFS
2. start from (0, 0)
3. go in all the 8 directions
4. keep marking them as 2, so that we won't visit it again

```c++
void dfsTraverse(vector<vector<char>>& grid, vector<int>& r, vector<int>& c, int i, int j) {
   int n = grid.size();
   int m = grid[0].size();
   if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1') {
      return;
   }
   grid[i][j] = '2';
   for(int k = 0; k < 8; k++) {
      dfsTraverse(grid, r, c, i+r[k], j+c[k]);
   }
}
int numIslands(vector<vector<char>>& grid) {
   int n = grid.size();
   int m = grid[0].size();
   vector<int> r{-1, -1, -1, 0, 1, 1, 1, 0};
   vector<int> c{-1, 0, 1, 1, 1, 0, -1, -1};
   int count = 0;
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
            if(grid[i][j] == '1') {
               dfsTraverse(grid, r, c, i, j);
               count++;
            }
      }
   }
   return count;
}

int numIslandsbfs(vector<vector<char>>& grid) {
   // Code here
   int n = grid.size();
   int m = grid[0].size();
   queue<pair<int, int> > q;
   pair<int, int> currPos;
   int resIslands = 0;
   //cout << n << m << endl;
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
            if(grid[i][j] == '1') {
               
               resIslands++;
               currPos = make_pair(i, j);
               q.push(currPos);
               //cout << i << " " << j << endl;
               while(!q.empty()) {
                  pair<int, int> front = q.front();
                  q.pop();
                  int ri = front.first;
                  int ci = front.second;
                  grid[ri][ci] = '2';
                  if((ci-1) >= 0 && (ri-1) >= 0 && grid[ri-1][ci-1] == '1') {
                        pair<int, int> nextPos = make_pair(ri-1, ci-1);
                        q.push(nextPos);
                  }
                  if((ri-1) >= 0 && grid[ri-1][ci] == '1') {
                        pair<int, int> nextPos = make_pair(ri-1, ci);
                        q.push(nextPos);
                  }
                  if((ci+1) < m && (ri-1) >= 0 && grid[ri-1][ci+1] == '1') {
                        pair<int, int> nextPos = make_pair(ri-1, ci+1);
                        q.push(nextPos);
                  }
                  if((ci-1) >= 0 && grid[ri][ci-1] == '1') {
                        pair<int, int> nextPos = make_pair(ri, ci-1);
                        q.push(nextPos);
                  }
                  if((ci+1) < m && grid[ri][ci+1] == '1') {
                        pair<int, int> nextPos = make_pair(ri, ci+1);
                        q.push(nextPos);
                  } 
                  if((ci-1) >= 0 && (ri+1) < n && grid[ri+1][ci-1] == '1') {
                        pair<int, int> nextPos = make_pair(ri+1, ci-1);
                        q.push(nextPos);
                  }
                  if((ri+1) < n && grid[ri+1][ci] == '1') {
                        pair<int, int> nextPos = make_pair(ri+1, ci);
                        q.push(nextPos);
                  }
                  if((ri+1) < n && (ci+1) < m && grid[ri+1][ci+1] == '1') {
                        pair<int, int> nextPos = make_pair(ri+1, ci+1);
                        q.push(nextPos);
                  }
               }
            }
            
      }
   }
   return resIslands;
}
```
## Question 5: [Flood fill algorithm](https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1)

### Statement
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

Example 1:

Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.

Output: {{2,2,2},{2,2,0},{2,0,1}}

Explanation: From the center of the image 
(with position (sr, sc) = (1, 1)), all 
pixels connected by a path of the same color
as the starting pixel are colored with the new 
color.Note the bottom corner is not colored 2, 
because it is not 4-directionally connected to 
the starting pixel.

### Solution
```c++
void helper(vector<vector<int>>& image, int sr, int sc, int newColor, int prevColor) {
   //cout << sr << " " << sc << endl;
   if(image[sr][sc] == prevColor) {
      image[sr][sc] = newColor;
   }
   if((sr-1) >= 0 && image[sr-1][sc] == prevColor) {
      helper(image, sr-1, sc, newColor, prevColor);
   }
   if((sr+1) < image.size() && image[sr+1][sc] == prevColor) {
      helper(image, sr+1, sc, newColor, prevColor);
   }
   if((sc-1) >= 0 && image[sr][sc-1] == prevColor) {
      helper(image, sr, sc-1, newColor, prevColor);
   }
   if((sc+1) < image[sr].size() && image[sr][sc+1] == prevColor) {
      helper(image, sr, sc+1, newColor, prevColor);
   }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
   // Code here 
   if(newColor == image[sr][sc]) {
      return image;
   }
   helper(image, sr, sc, newColor, image[sr][sc]);
   return image;
}
```

## Question 6: [Rotten oranges](https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1)

### Statement
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time.

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}

Output: 1

Explanation: The grid is-
```
0 1 2
0 1 2
2 1 1
```
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.

### Solution
#### Explanation
1. We need to get the minimum time to rot an orange
2. From a single orange's prespective - 
   1. We need to check for a rotten orange at the nearest level
   2. we can do this if we traverse breadth wise
3. Hence we will be doing a BFS on the grid
4. Traverse the grid and look for 1's
5. From a cell marked 1, start BFS to look for 2 at nearest level
6. if not found, then this cell cannot be rotten - hence output (-1)

```c++
int orangesRotting(vector<vector<int>>& grid) {
   // Code here
   int minTime = -1;
   //queue<pair<int, int>> q;
   int rows = grid.size();
   int cols = grid[0].size();
   vector<int> nr{-1, 1, 0, 0};
   vector<int> nc{0, 0, -1, 1};
   bool isPossible = true;
   
   for(int i = 0; i < rows; i++) {
      if(!isPossible) {
            break;
      }
      for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 1) {
               queue<pair<int, int>> q;
               q.push(make_pair(i, j));
               bool found2 = false;
               int level = -1;
               while(!found2 && !q.empty()) {
                  level++;
                  int lvlSize = q.size();
                  for(int i = 0; i < lvlSize; i++) {
                        pair<int, int> front = q.front();
                        q.pop();
                        int r = front.first;
                        int c = front.second;
                        if(grid[r][c] == 2) {
                           found2 = true;
                           break;
                        }
                        for(int i = 0; i < 4; i++) {
                           int nextRow = r + nr[i];
                           int nextCol = c + nc[i];
                           if((nextRow >= 0 && nextRow < rows) && (nextCol >= 0 && nextCol < cols)) {
                              if(grid[nextRow][nextCol] != 0) {
                                    q.push(make_pair(nextRow, nextCol));
                              }
                              
                           }
                        }
                  
                  }
                  minTime = max(minTime, level);
               }
               if(!found2) {
                  minTime = -1;
                  isPossible = false;
                  break;
               }
            }
      }
   }
   return minTime;
}
```

## Question 7: [Detect cycle in an undirected graph](https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)

### Statement:
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.
Input:  
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 

Output: 1

Explanation: 
1->2->3->4->1 is a cycle.

### Solution:
#### Explanation
1. The concept is that - 
   1. if we find a neighbour node - which is already visited and is not the parent of the current node -- *then we have a cycle*

```c++
bool isCycleDFS(int nodeVal, int parent, vector<int> adj[], vector<bool>& visited) {
   visited[nodeVal] = true;
   for(int j = 0; j < adj[nodeVal].size(); j++) {
      int thisChildNode = adj[nodeVal][j];
      if(visited[thisChildNode]) {
            if(parent > -1 && parent != thisChildNode) {
               return true;
            }
      } else {
            if(isCycleDFS(thisChildNode, nodeVal, adj, visited)) {
               return true;
            }
      }
   }
}

bool isCycle(int v, vector<int> adj[]) {
   vector<bool> visited(v, false);
   for(int i = 0; i < v; i++) {
      if(visited[i]) {
            continue;
      }
      if(isCycleDFS(i, -1, adj, visited)) {
            return true;
      }
   }
   return false;
}

bool isCycleBFS(int v, vector<int> adj[]) {
   // Code here
   vector<bool> visited(v, false);
   for(int i = 0; i < v; i++) {
      if(visited[i]) {
            continue;
      }
      queue<pair<int, int>> q;
      q.push(make_pair(i, -1));
      while(!q.empty()) {
            int lvlSize = q.size();
            for(int i = 0; i < lvlSize; i++) {
               pair<int, int> front = q.front();
               q.pop();
               int nodeVal = front.first;
               int parent = front.second;
               if(!visited[nodeVal]) {
                  visited[nodeVal] = true;
               }
               for(int j = 0; j < adj[nodeVal].size(); j++) {
                  int thisChildNode = adj[nodeVal][j];
                  if(visited[thisChildNode]) {
                        if(parent > -1 && parent != thisChildNode) {
                           return true;
                        }
                  } else {
                        q.push(make_pair(thisChildNode, nodeVal));
                  }
               }
            }
      }
   }
   return false;
}
```

## Question 8: [Distance of nearest cell having 1](https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1)

### Statement
Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.

Assume that there will always be atleast one 1 in the entire grid.

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}

Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}

Explanation: The grid is-
```
0 1 1 0 
1 1 0 0 
0 0 1 1
``` 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.

### Solution
```c++
pair<int, int> getNearest1(int ri, int ci, vector<int>& nr, vector<int>& nc, vector<vector<int>>& grid) {
   queue<pair<int, int>> q;
   q.push(make_pair(ri, ci));
   pair<int, int> output;
   int rows = grid.size();
   int cols = grid[0].size();
   while(!q.empty()) {
      int lvlSize = q.size();
      for(int i = 0; i < lvlSize; i++) {
            pair<int, int> front = q.front();
            q.pop();
            int ri = front.first;
            int ci = front.second;
            if(grid[ri][ci] == 1) {
               output.first = ri; output.second = ci;
               return output;
            }
            for(int i = 0; i < 4; i++) {
               int nri = ri + nr[i];
               int nci = ci + nc[i];
               if(nri < 0 || nri >= rows || nci < 0 || nci >= cols) {
                  continue;
               }
               q.push(make_pair(nri, nci));
            }
      }
   }
   output.first = -1; output.second = -1;
   return output;
}

vector<vector<int>>nearest(vector<vector<int>>grid)
{
   // Code here
   vector<int> nr{-1, 1, 0, 0};
   vector<int> nc{0, 0, -1, 1};
   int rows = grid.size();
   int cols = grid[0].size();
   vector<vector<int>> res;
   for(int i = 0; i < rows; i++) {
      vector<int> thisRes;
      for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 1) {
               thisRes.push_back(0);
            } else {
               pair<int, int> thisOpt = getNearest1(i, j, nr, nc, grid);
               int ans = INT_MAX;
               if(thisOpt.first > -1 && thisOpt.second > -1) {
                  ans = abs(i-thisOpt.first) + abs(j-thisOpt.second);
               }
               thisRes.push_back(ans);
            }
      }
      res.push_back(thisRes);
   }
   return res;
}
```

## Question 9: [Replace O's with X's](https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs)

### Statement
Given a matrix mat of size N x M where every element is either O or X.
Replace all O with X that are surrounded by X.
A O (or a set of O) is considered to be surrounded by X if there are X at locations just below, just above, just left and just right of it.

Input: n = 5, m = 4
mat = ```
{{'X', 'X', 'X', 'X'},
{'X', 'O', 'X', 'X'}, 
{'X', 'O', 'O', 'X'}, 
{'X', 'O', 'X', 'X'}, 
{'X', 'X', 'O', 'O'}}
       ```
Output: ans = {{'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'O', 'O'}}
Explanation: Following the rule the above 
matrix is the resultant matrix. 

### Solution:
#### Explanation
1. Any 'O' at the boundary or connected to an 'O' (which is at the boundary) will not be converted
2. Other than that, all other 'O' will be converted to 'X'
3. Pick a boundary 'O' and start doing DFS
4. Only iterate through other 'O' and mark them
5. In result matrix, these will not be replaced by 'X'

```c++
void doDFS(int ri, int ci, vector<int>& nr, vector<int>& nc, vector<vector<bool>>& visited, vector<vector<char>>& mat) {
   visited[ri][ci] = true;
   
   int rows = mat.size();
   int cols = mat[0].size();
   
   for(int k = 0; k < 4; k++) {
      int nri = ri + nr[k];
      int nci = ci + nc[k];
      if(nri < 0 || nri >= rows || nci < 0 || nci >= cols || mat[nri][nci] == 'X' || visited[nri][nci]) {
            continue;
      }
      doDFS(nri, nci, nr, nc, visited, mat);
   }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
   // code here
   vector<int> nr{-1, 1, 0, 0};
   vector<int> nc{0, 0, -1, 1};
   
   vector<vector<char>> res(n, vector<char>(m, 'X'));
   vector<vector<bool>> visited(n, vector<bool>(m, false));
   
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
            if(i == 0 || j == 0 || i == n-1 || j == m-1) {
               if(mat[i][j] == 'O') {
                  doDFS(i, j, nr, nc, visited, mat);
               }
            }
      }
   }
   
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
            if(visited[i][j]) {
               res[i][j] = 'O';
            }
      }
   }
   return res;
}
```