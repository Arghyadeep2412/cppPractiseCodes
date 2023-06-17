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
13. Bipartite graph
    1.  if we can color the graph with two different colors such that, no adjacent two nodes have the same color - then it is a bipartite graph
    2. Linear graph with no cycles are always bipartite
    3. Any graph with even cycle length (count of edges) - is bipartite
    4. Any graph with odd cycle length (count of edges) - is bipartite
 14. Topological sorting
     1.  exists only for Directed Acyclic graph
     2.  a linear order of nodes such that - if there exists an edge from u to v - u appears before v

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

## Question 10: [Number of Enclaves](https://practice.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves)

### Statement
You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Input:
grid[][] = 
```
{{0, 0, 0, 0},
{1, 0, 1, 0},
{0, 1, 1, 0},
{0, 0, 0, 0}}
```
Output:
3

Explanation:
```
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0
```
The highlighted cells represents the land cells.

### Solution
```c++
void doDFS(int ri, int ci, vector<int>& nr, vector<int>& nc, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
   if(grid[ri][ci] == 0 || visited[ri][ci]) {
      return;
   }
   int rows = grid.size();
   int cols = grid[0].size();
   visited[ri][ci] = true;
   for(int k = 0; k < 4; k++) {
      int nri = ri + nr[k];
      int nci = ci + nc[k];
      if(nri < 0 || nri >= rows || nci < 0 || nci >= cols || grid[nri][nci] == 0 || visited[nri][nci]) {
            continue;
      }
      doDFS(nri, nci, nr, nc, grid, visited);
   }
}

int numberOfEnclaves(vector<vector<int>> &grid) {
   
   // Code here
   vector<int> nr{-1, 1, 0, 0};
   vector<int> nc{0, 0, -1, 1};
   int rows = grid.size();
   int cols = grid[0].size();
   // vector<vector<char>> res(n, vector<char>(m, 'X'));
   int count = 0;
   vector<vector<bool>> visited(rows, vector<bool>(cols, false));
   for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
            if(i == 0 || j == 0 || i == rows-1 || j == cols-1) {
               if(grid[i][j] == 1) {
                  doDFS(i, j, nr, nc, grid, visited);
               }
            }
      }
   }
   
   for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 1 && !visited[i][j]) {
               count++;
            }
      }
   }
   return count;
}
```

## Question 11: [Number of Distinct islands](https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands)

### Statement: 
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Input:
grid[][] = 
```
{{1, 1, 0, 0, 0},
{1, 1, 0, 0, 0},
{0, 0, 0, 1, 1},
{0, 0, 0, 1, 1}}
```
Output:
1
Explanation:
grid[][] = 
```
{{1, 1, 0, 0, 0}, 
{1, 1, 0, 0, 0}, 
{0, 0, 0, 1, 1}, 
{0, 0, 0, 1, 1}}
```
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.

### Solution
#### Explanation
1. Given is a grid of 0s and 1s
2. A group of 1s refers to an island
3. Consider an (i, j) which has 1 and is not visited yet
   1. travers in all 4 directions till we hit a cell with 0
   2. while traversing - keep all the cells indices in a list
   3. after traversal is complete - normalize all the nodes in the above list
   4. keep the above list in a set
4. Continue this process until we have covered all the cells in grid
5. Get the size of the set -- answer

```c++
void doDfs(int ri, int ci, vector<int>& nr, vector<int>& nc, vector<vector<int>> &grid, vector<vector<bool>> &visited, 
vector<pair<int, int>>& nodes) {
   if(grid[ri][ci] == 0 || visited[ri][ci]) {
      return;
   }
   visited[ri][ci] = true;
   nodes.push_back(make_pair(ri, ci));
   int rows = grid.size();
   int cols = grid[0].size();
   for(int k = 0; k < 4; k++) {
      int nri = ri + nr[k];
      int nci = ci + nc[k];
      if(nri < 0 || nri >= rows || nci < 0 || nci >= cols || grid[nri][nci] == 0 || visited[nri][nci]) {
            continue;
      }
      doDfs(nri, nci, nr, nc, grid, visited, nodes);
   }
}

void normalizeNodes(vector<pair<int, int>>& nodes) {
   int n = nodes.size();
   int rc = nodes[0].first;
   int cc = nodes[0].second;
   for(int i = 0; i < n; i++) {
      nodes[i].first -= rc;
      nodes[i].second -= cc;
   }
}

int countDistinctIslands(vector<vector<int>>& grid) {
   
   // code here
   vector<int> nr{-1, 1, 0, 0};
   vector<int> nc{0, 0, -1, 1};
   int rows = grid.size();
   int cols = grid[0].size();
   set<vector<pair<int, int>>> diffIslands;
   // vector<vector<char>> res(n, vector<char>(m, 'X'));
   int count = 0;
   vector<vector<bool>> visited(rows, vector<bool>(cols, false));
   for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 1 && !visited[i][j]) {
               vector<pair<int, int>> thisRes;
               doDfs(i, j, nr, nc, grid, visited, thisRes);
               normalizeNodes(thisRes);
               diffIslands.insert(thisRes);
            }
      }
   }
   return diffIslands.size();
}
```

## Question 12: [Bipartite graph](https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph)

### Statement
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.

### Solution
#### Explanation
1. Any neighbor node which is already colored but is not having the opposite color of current node - then it is not bipartite

```c++
int getOppColor(int inputColor) {
   if(inputColor == 0) {
      return 1;
   }
   return 0;
}

bool isBipartiteBFS(int v, vector<int>adj[]) {
   vector<int> colors(v, -1);
   queue<int> q;
   for(int i = 0; i < v; i++) {
      if(colors[i] > -1) {
            continue;
      }
      q.push(i);
      colors[i] = 0;
      while(!q.empty()) {
            int lvlSize = q.size();
            for(int j = 0; j < lvlSize; j++) {
               
               int node = q.front();
               q.pop();
               
               int adjSize = adj[node].size();
               
               for(int k = 0; k < adjSize; k++) {
                  int thisAdjNode = adj[node][k];
                  
                  if(colors[thisAdjNode] == -1) {
                        colors[thisAdjNode] = getOppColor(colors[node]);
                        q.push(thisAdjNode);
                  } else {
                        if(colors[thisAdjNode] != getOppColor(colors[node])) {
                           return false;
                        }
                  }
               }
            }
      }
   }
   return true;
}

bool isBipartiteDFS(int node, int v, vector<int>adj[], vector<int>& colors) {
   int adjSize = adj[node].size();
   for(int k = 0; k < adjSize; k++) {
      int thisAdjNode = adj[node][k];
      
      if(colors[thisAdjNode] == -1) {
            colors[thisAdjNode] = getOppColor(colors[node]);
            
            if(!isBipartiteDFS(thisAdjNode, v, adj, colors)) {
               return false;
            }
            
      } else {
            
            if(colors[thisAdjNode] != getOppColor(colors[node])) {
               return false;
            }
      }
   }
   return true;
}

bool isBipartite(int v, vector<int>adj[]){
   // Code here
   // return isBipartiteBFS(v, adj);
   
   vector<int> colors(v, -1);
   for(int i = 0; i < v; i++) {
      if(colors[i] > -1) {
            continue;
      }
      //q.push(i);
      colors[i] = 0;
      if(!isBipartiteDFS(i, v, adj, colors)) {
            return false;
      }
   }
   return true;
}
```

## Question 13: [Detect cycle in a directed graph](https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph)

### Statement:
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

### Solution:
#### Explanation
1. We cannot use the algorithm of detecting cycle in undirected graphs
2. We need to figure out a way to check that - the neighbour node is visited and is on the same dfs call stack
```c++
bool checkCycleDirectedDFS(vector<int> adj[], vector<int>& visited, 
vector<int>& dfsCallStack, int curr) {
   dfsCallStack[curr] = true;
   visited[curr] = true;
   for(auto i : adj[curr]) {
      if(!visited[i]) {
            bool res = checkCycleDirectedDFS(adj, visited, dfsCallStack, i);
            if(res) {
               return true;
            }
      } else {
            if(dfsCallStack[i]) {
               return true;
            }
      }
   }
   dfsCallStack[curr] = false;
   return false;
}

bool checkCycleDirectedBFS(int v, vector<int> adj[]) {
   vector<int> res;
   vector<int> inDegree(v, 0);
   for(int i = 0; i < v; i++) {
      for(auto x: adj[i]) {
         inDegree[x]++;
      }
   }
   
   queue<int> q;
   for(int i = 0; i < v; i++) {
      if(inDegree[i] == 0) {
         q.push(i);
      }
   }
   
   while(!q.empty()) {
      int thisNode = q.front();
      q.pop();
      res.push_back(thisNode);
      for(auto x: adj[thisNode]) {
         inDegree[x]--;
         if(inDegree[x] == 0) {
               q.push(x);
         }
      }
   }
   if(res.size() == v) {
      return false;
   }
   return true;
}

bool isCyclic(int v, vector<int> adj[]) {
   // code here
   vector<int> visited(v, false);
   vector<int> dfsCallStack(v, false);
   for(int i = 0; i < v; i++) {
      if(!visited[i]) {
            if(checkCycleDirectedDFS(adj, visited, dfsCallStack, i)) {
               return true;
            }
      }
   }
   return false;
}
```

## Question 14: [Eventual Safe States](https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states)

### Statement:
A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

### Solution:
#### Explanation
1. We can use the alogrithm to find cycles in directed graphs
2. basically - anything which is a part of a cycle or is connected to a cycle
3. if such cases - the node is marked as visited and also marked in dfsCall stack array
4. need to list such items
5. For BFS - We need to use Kahn's algo
6. but we cannot use it directly on the given graph
7. Reverse all the edges of the graph
8. then use the Kahn's algo on reverse-edged graph


```c++
bool checkCycleDirectedDFS(vector<int> adj[], vector<bool>& visited, vector<bool>& dfsCallStack, int curr) {
   dfsCallStack[curr] = true;
   visited[curr] = true;
   for(auto i : adj[curr]) {
      if(!visited[i]) {
            bool res = checkCycleDirectedDFS(adj, visited, dfsCallStack, i);
            if(res) {
               return true;
            }
      } else {
            if(dfsCallStack[i]) {
               return true;
            }
      }
   }
   dfsCallStack[curr] = false;
   return false;
}

void reverAdjList(int v, vector<int> orgAdj[], vector<int>revAdj[]) {
   for(int i = 0; i < v; i++) {
      for(auto x: orgAdj[i]) {
            revAdj[x].push_back(i);
      }
   }
}

vector<int> getTopologicalSortBFS(int v, vector<int> adj[]) {
   vector<int> res;
   vector<int> inDegree(v, 0);
   for(int i = 0; i < v; i++) {
      for(auto x: adj[i]) {
            inDegree[x]++;
      }
   }
   
   queue<int> q;
   for(int i = 0; i < v; i++) {
      if(inDegree[i] == 0) {
            q.push(i);
      }
   }
   
   while(!q.empty()) {
      int thisNode = q.front();
      q.pop();
      res.push_back(thisNode);
      for(auto x: adj[thisNode]) {
            inDegree[x]--;
            if(inDegree[x] == 0) {
               q.push(x);
            }
      }
   }
   sort(res.begin(), res.end());
   return res;
}

vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
   // code here
   vector<int> revAdj[v];
   reverAdjList(v, adj, revAdj);
   return getTopologicalSortBFS(v, revAdj);
   
   vector<bool> visited(v, false);
   vector<bool> dfsCallStack(v, false);
   for(int i = 0; i < v; i++) {
      if(!visited[i]) {
            checkCycleDirectedDFS(adj, visited, dfsCallStack, i);
      }
   }
   vector<int> res;
   for(int i = 0; i < v; i++) {
      if(visited[i] && !dfsCallStack[i]) {
            res.push_back(i);
      }
   }
   return res;
}
```

## Question 15: [Topological sort](https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort)

### Statement:
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

### Solution:
#### Explanation
1. Follow the DFS traversal, and keep storing the nodes in a stack when DFS is complete for a given node
2. BFS traversal - is called Kahn's algo

```c++
void doDfs(int node, vector<int> adj[], vector<bool>& visited, stack<int>& stk) {
   if(visited[node]) {
      return;
   }
   visited[node] = true;
   for(auto x: adj[node]) {
      doDfs(x, adj, visited, stk);
   }
   stk.push(node);
}

// BFS algo - also known as Kahn's algo
vector<int> doBFSTopologicalSort(int v, vector<int> adj[]) {
   vector<int> res;
   vector<int> inDegree(v, 0);
   for(int i = 0; i < v; i++) {
      for(auto x: adj[i]) {
         inDegree[x]++;
      }
   }
   
   queue<int> q;
   for(int i = 0; i < v; i++) {
      if(inDegree[i] == 0) {
         q.push(i);
      }
   }
   
   while(!q.empty()) {
      int thisNode = q.front();
      q.pop();
      res.push_back(thisNode);
      for(auto x: adj[thisNode]) {
         inDegree[x]--;
         if(inDegree[x] == 0) {
               q.push(x);
         }
      }
   }
   return res;
}

vector<int> topoSort(int v, vector<int> adj[]) 
{
   // code here
   vector<int> res;
   stack<int> nodeStk;
   vector<bool> visited(v, false);
   for(int i = 0; i < v; i++) {
      doDfs(i, adj, visited, nodeStk);
   }
   while(!nodeStk.empty()) {
      res.push_back(nodeStk.top());
      nodeStk.pop();
   }
   return res;
}
```

## Question 16: [Prerequisite Tasks](https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks)

### Statement:
There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

Input: 
N = 4, P = 3
prerequisites = {{1,0},{2,1},{3,2}}

Output:
Yes

Explanation:
To do task 1 you should have completed
task 0, and to do task 2 you should 
have finished task 1, and to do task 3 you 
should have finished task 2. So it is possible.

### Solution:

#### Explanation:
1. Given is a vector of pairs
2. (1, 0) - means that - one has to complete course_0 to be able to finish course_1
3. so basically this relationship can be shown as a directed edge from 0 to 1
4. So, create an adjancency list for a directed graph
5. Check for topological order for this directed graph
   1. if topological order is valid - true - all courses can be completed
   2. if topological order is not valid - false - all courses cannot be completed


```c++
bool isTopologicalOrderValid(int n, vector<vector<int>>& adjList) {
   vector<int> res;
   vector<int> inDegree(n, 0);
   for(int i = 0; i < n; i++) {
      for(auto x: adjList[i]) {
            inDegree[x]++;
      }
   }
   
   queue<int> q;
   for(int i = 0; i < n; i++) {
      if(inDegree[i] == 0) {
            q.push(i);
      }
   }
   
   while(!q.empty()) {
      int thisNode = q.front();
      q.pop();
      res.push_back(thisNode);
      for(auto x: adjList[thisNode]) {
            inDegree[x]--;
            if(inDegree[x] == 0) {
               q.push(x);
            }
      }
   }
   
   if(res.size() == n) {
      return true;
   }
   return false;
}

bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
   // Code here
   vector<vector<int>> adjList(n);
   int totalPairs = prerequisites.size();
   for(int i = 0; i < totalPairs; i++) {
      pair<int, int> thisPair = prerequisites[i];
      int u = thisPair.second;
      int v = thisPair.first;
      adjList[u].push_back(v);
   }
   
   return isTopologicalOrderValid(n, adjList);
}
```

## Question 17: [Course Schedule](https://practice.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule)

### Statement:
There are a total of n tasks you have to pick, labeled from 0 to n-1. Some tasks may have prerequisites tasks, for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
Given the total number of n tasks and a list of prerequisite pairs of size m. Find a ordering of tasks you should pick to finish all tasks.
Note: There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all tasks, return an empty array. Returning any correct order will give the output as 1, whereas any invalid order will give the output "No Ordering Possible".

Input:
n = 4, m = 4
prerequisites = {{1, 0},
                 {2, 0},
                 {3, 1},
                 {3, 2}}

Output: 1

Explanation:
There are a total of 4 tasks to pick.
To pick task 3 you should have finished
both tasks 1 and 2. Both tasks 1 and 2
should be pick after you finished task 0.
So one correct task order is [0, 1, 2, 3].
Another correct ordering is [0, 2, 1, 3].
Returning any of these order will result in
a Output of 1.

### Solution: 
Almost same as question 16

## Question 18: [Alien Dictionary](https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary)

### Statement:
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

Input: 
N = 5, K = 4

dict = {"baa","abcd","abca","cab","cad"}

Output: 1

Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

### Solution:
#### Explanation:
1. We need to figure out the ordering of characters
2. if "baa" comes before "abcd"
   1. we can say that 'b' comes before 'a'
   2. can be represented as a directed edge from 'b' to 'a'
3. if "abcd" comes before "abca"
   1. we can say that 'd' comes before 'a'
   2. can be represented as a directed edge from 'd' to 'a'
4. So, we can compare all the consecutive strings in the given sorted list, and figure out an directed graph
5. Then we can get the topological order of that graph
```c++
pair<char, char> compareStrs(string s1, string s2) {
   int n = s1.length();
   int m = s2.length();
   int i = 0, j = 0;
   pair<char, char> output;
   while(i < n && j < m) {
      if(s1[i] != s2[j]) {
            output.first = s1[i];
            output.second = s2[j];
            return output;
      }
      i++; j++;
   }
   if(i == n) {
      output.first = '\0';
      output.second = '\0';
   }
   return output;
}

vector<int> getTopoSort(vector<vector<int>>& adjList, int v) {
   queue<int> q;
   vector<int> res;
   vector<int> inDegree(v, 0);
   for(int i = 0; i < v; i++) {
      for(auto x: adjList[i]) {
            inDegree[x]++;
      }
   }
   
   for(int i = 0; i < v; i++) {
      if(inDegree[i] == 0) {
            q.push(i);
      }
   }
   
   while(!q.empty()) {
      int thisNode = q.front();
      q.pop();
      res.push_back(thisNode);
      for(auto x: adjList[thisNode]) {
            inDegree[x]--;
            if(inDegree[x] == 0) {
               q.push(x);
            }
      }
   }
   return res;
}

string findOrder(string dict[], int n, int k) {
   //code here
   unordered_map<char, int> dictChars;
   int currChar = 0;
   for(int i = 0; i < n; i++) {
      string s = dict[i];
      int len = s.length();
      for(int j = 0; j < len; j++) {
            if(dictChars.find(s[j]) ==  dictChars.end()) {
               dictChars[s[j]] = currChar;
               currChar++;
            }
      }
   }
   
   vector<vector<int>> adjList(dictChars.size());
   for(int i = 0; i < n-1; i++) {
      pair<char, char> thisRes = compareStrs(dict[i], dict[i+1]);
      if(thisRes.first == '\0') {
            continue;
      }
      adjList[dictChars[thisRes.first]].push_back(dictChars[thisRes.second]);
   }
   
   vector<int> topoSort = getTopoSort(adjList, dictChars.size());
   string res;
   for(int i = 0; i < topoSort.size(); i++) {
      unordered_map<char, int>::iterator itr;
      for(itr = dictChars.begin(); itr != dictChars.end(); itr++) {
            if(itr -> second == topoSort[i]) {
               res += itr -> first;
            }
      }
   }
   return res;
}
```

## Question 19: [Shortest path in Directed Acyclic Graph](https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph)

### Statement:
Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i, 0<=i

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

### Solution:
#### Explanation:
1. Assume we are given the adjancency list
2. Get the topological sorted order of nodes
3. make a distance array - and mark all the nodes as INT_MAX
4. mark the source node as 0
5. Get the first node from topological sorted node (currNode)
6. Calculate the distance of all the nodes connected to currNode from adjancency list
7. keep the minimum of the distances in result distance array
8. repeat 5 to 7 - for all the nodes in topological sort order

```c++
void topoSortDFS(int node, vector<bool>& visited, stack<int>& topoSortStk, vector<vector<pair<int, int>>>& adjList) {
   if(visited[node]) {
         return;
   }
   visited[node] = true;
   for(auto edge: adjList[node]) {
         topoSortDFS(edge.first, visited, topoSortStk, adjList);
   }
   topoSortStk.push(node);
}

vector<int> getDist(int n, vector<vector<pair<int, int>>>& adjList, stack<int>& stk, int sourceNode) {
   vector<int> res(n, INT_MAX);
   res[sourceNode] = 0;
   
   while(!stk.empty()) {
         int currNode = stk.top();
         stk.pop();
         int currNodeDist = res[currNode];
         for(auto edge: adjList[currNode]) {
            int toNode = edge.first;
            int wt = edge.second;
            int finalDist = currNodeDist;
            if(finalDist != INT_MAX) {
               finalDist += wt;
            }
            res[toNode] = min(res[toNode], finalDist); // finalDist;
         }
   }
   return res;
}

vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
   // code here
   vector<int> res;
   vector<bool> visited(n, false);
                  // toNode, weight
   vector<vector<pair<int, int>>> adjList(n);
   for(int i = 0; i < m; i++) {
      int u = edges[i][0];
      int v = edges[i][1];
      int wt = edges[i][2];
      pair<int, int> thisEdge = make_pair(v, wt);
      adjList[u].push_back(thisEdge);
   }
   
   stack<int> topoSortStk;
   for(int i = 0; i < n; i++) {
      if(visited[i]) {
            continue;
      }
      topoSortDFS(i, visited, topoSortStk, adjList);
   }
   
   res = getDist(n, adjList, topoSortStk, 0);
   for(int i = 0; i < n; i++) {
      if(res[i] == INT_MAX) {
            res[i] = (-1);
      }
   }
   return res;
}
```

## Question 20: [Shortest path in Undirected Graph having unit distance](https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance)

### Statement:
You are given an Undirected Graph having unit weight, Find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

Example:

Input:
n = 9, m= 10
edges=[[0,1],[0,3],[3,4],[4 ,5]
,[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
src=0

Output: 0 1 2 1 2 3 3 4 4

### Solution:
#### Explanation:
1. Assume we are given the adjancency list
2. make a distance array - and mark all the nodes as INT_MAX
3. mark the source node as 0
4. push the source node with dist = 0, into the queue
5. do a BFS traversal
6. Figure out the distance of the adjacent nodes based on the current node distance
   1. if it is lesser than what we have in distance array for that adjacent node - update it and push it in the queue
```c++
vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
   // code here
   vector<vector<int>> adjList(n);
   for(int i = 0; i < m; i++) {
      int u = edges[i][0];
      int v = edges[i][1];
      adjList[u].push_back(v);
      adjList[v].push_back(u);
   }
   
   vector<int> res(n, INT_MAX);
   res[src] = 0;
   pair<int, int> thisNode = make_pair(src, 0);
   // node, dist
   queue<pair<int, int>> q;
   q.push(thisNode);
   while(!q.empty()) {
      int lvlSize = q.size();
      for(int i = 0; i < lvlSize; i++) {
            thisNode = q.front();
            q.pop();
            int node = thisNode.first;
            int dist = thisNode.second;
            for(auto x: adjList[node]) {
               int finalDist = dist+1;
               if(finalDist < res[x]) {
                  res[x] = finalDist;
                  q.push(make_pair(x, finalDist));
               }
            }
      }
   }
   
   for(int i = 0; i < n; i++) {
      if(res[i] == INT_MAX) {
            res[i] = -1;
      }
   }
   
   return res;
}
```

## Question 21: [Word Ladder I](https://practice.geeksforgeeks.org/problems/word-ladder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder)

### Statement
Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList
The second part of this problem can be found here.

Note: If no possible way to transform sequence from startWord to targetWord return 0

Example 1:

Input:
wordList = {"des","der","dfr","dgt","dfs"}
startWord = "der", targetWord= "dfs",

Output: 3

Explanation:
The length of the smallest transformation
sequence from "der" to "dfs" is 3
i,e "der" -> "dfr" -> "dfs".

Example 2:

Input:
wordList = {"geek", "gefk"}
startWord = "gedk", targetWord= "geek", 

Output: 2

Explanation:
gedk -> geek

Example 3:

Input: 
wordList = {"poon", "plee", "same", "poie","plea","plie","poin"}
startWord = "toon", targetWord= "plea"

Output: 7 

Explanation:
toon -> poon -> poin -> poie -> plie -> plee -> plea 

### Solution

#### Explanation:
1. Check if the start word is present in the given list or not
   1. if not, add it to the word list
2. Check if the target word is present in the given list or not
   1. if not, return 0 -- as not possible
3. Create a map - assign each string a number from [0, n-1]
4. Create the adjacency list according to the given situation
   1. Consider the graph edges to be undirected with edge weight = 1
5. Get the shortest distance array for this graph for given source node
6. return answer accordingly
```c++
bool canTransform(string s1, string s2) {
   int n = s1.length();
   int m = s2.length();
   int i = 0, j = 0;
   int diffCount = 0;
   while(i < n && j < m) {
      if(s1[i] != s2[j]) {
            diffCount++;
      }
      if(diffCount > 1) {
            return false;
      }
      i++; j++;
   }
   if(diffCount == 1) {
      return true;
   }
   return false;
}

void getAdjList(int n, vector<string>& wordList, vector<vector<int>>& adjList,
unordered_map<string, int>& strMap) {
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
            if(i == j) {
               continue;
            }
            if(canTransform(wordList[i], wordList[j])) {
               int u = strMap[wordList[i]];
               int v = strMap[wordList[j]];
               adjList[u].push_back(v);
               adjList[v].push_back(u);
            }
      }
   }
}

vector<int> getDist(int n, vector<vector<int>>& adjList, int srcNode) {
   vector<int> res(n, INT_MAX);
   res[srcNode] = 0;
   // node, dist
   pair<int, int> thisPair = make_pair(srcNode, 0);
   queue<pair<int, int>> q;
   q.push(thisPair);
   while(!q.empty()) {
      int lvlSize = q.size();
      for(int i = 0; i < lvlSize; i++) {
         thisPair = q.front();
         q.pop();
         int node = thisPair.first;
         int dist = thisPair.second;
         for(auto x: adjList[node]) {
            int finalDist = dist + 1;
            if(finalDist < res[x]) {
               res[x] = finalDist;
               q.push(make_pair(x, finalDist));
            }
         }
      }
   }
   return res;
}

int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
   // Code here
   bool startWordPresentInList = false;
   bool endWordPresentInList = false;
   int n = wordList.size();
   for(int i = 0; i < n; i++) {
      if(wordList[i] == startWord) {
            startWordPresentInList = true;
      }
      if(wordList[i] == targetWord) {
            endWordPresentInList = true;
      }
   }
   if(!endWordPresentInList) {
      return 0;
   }
   if(!startWordPresentInList) {
      wordList.push_back(startWord);
   }
   n = wordList.size();
   unordered_map<string, int> strMap;
   for(int i = 0; i < n; i++) {
      strMap[wordList[i]] = i;
   }
   
   vector<vector<int>> adjList(n);
   getAdjList(n, wordList, adjList, strMap);
   
   vector<int> resDist = getDist(n, adjList, strMap[startWord]);
   if(resDist[strMap[targetWord]] == INT_MAX) {
      return 0;
   }
   return resDist[strMap[targetWord]]+1;
}
```

## Question 22: [Word Ladder II](https://practice.geeksforgeeks.org/problems/word-ladder-ii/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder-ii)

### Statement:
Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.
Keep the following conditions in mind:

1. A word can only consist of lowercase characters.
2. Only one letter can be changed in each transformation.
3. Each transformed word must exist in the wordList including the targetWord.
4. startWord may or may not be part of the wordList.
5. Return an empty list if there is no such transformation sequence.

Example 1:

Input:
startWord = "der", targetWord = "dfs",
wordList = {"des","der","dfr","dgt","dfs"}

Output:
der dfr dfs
der des dfs

Explanation:
The length of the smallest transformation is 3.
And the following are the only two ways to get
to targetWord:-
"der" -> "des" -> "dfs".
"der" -> "dfr" -> "dfs".
Example 2:

Input:
startWord = "gedk", targetWord = "geek", 
wordList = {"geek", "gefk"}

Output:
"gedk" -> "geek"

### Solution
#### Explanation:
1. Check if the start word is present in the given list or not
   1. if not, add it to the word list
2. Check if the target word is present in the given list or not
   1. if not, return 0 -- as not possible
3. Create two maps - assign each string a number from [0, n-1]
   1. One will be string->int map
   2. one will be int -> string map
4. Create the adjacency list according to the given situation
   1. Consider the graph edges to be undirected with edge weight = 1
5. Now we need to do a BFS on the graph
   1. queue - it will be a queue of list
   2. pop the front item in queue
   3. get the last node from the above list
   4. check if this is the last node needed
      1. if yes, add it to res
         1. also, we do not need to proceed futher for next levels, as we want the shortest transformation paths
      2. if no, check all its adjacent nodes and add it in the queue accordingly for next level processing
   5. after each level, keep track of all the new nodes encountered
      1. need to mark them as absent - so that they are not considered once we move on to next level
      2. to avoid back-tracking paths
```c++
bool canTransform(string s1, string s2) {
   int n = s1.length();
   int m = s2.length();
   int i = 0, j = 0;
   int diffCount = 0;
   while(i < n && j < m) {
      if(s1[i] != s2[j]) {
            diffCount++;
      }
      if(diffCount > 1) {
            return false;
      }
      i++; j++;
   }
   if(diffCount == 1) {
      return true;
   }
   return false;
}

void getAdjList(int n, vector<string>& wordList, vector<vector<int>>& adjList,
unordered_map<string, int>& strMap) {
   for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
            // if(i == j) {
            //   continue;
            // }
            if(canTransform(wordList[i], wordList[j])) {
               int u = strMap[wordList[i]];
               int v = strMap[wordList[j]];
               adjList[u].push_back(v);
               adjList[v].push_back(u);
            }
      }
   }
}

vector<vector<int>> getSeq(int n, vector<vector<int>>& adjList, int start, int end) {
   vector<int> isPresent(n, true);
   bool foundEnd = false;
   vector<vector<int>> res;
   
   queue<vector<int>> q;
   
   vector<int> currRow;
   currRow.push_back(start);
   isPresent[start] = false;
   
   q.push(currRow);
   
   while(!q.empty()) {
      
      int lvlSize = q.size();
      vector<int> nodesToDel;
      
      for(int i = 0; i < lvlSize; i++) {
            
         currRow = q.front();
         q.pop();
         
         int lastNode = currRow.back();
         
         if(lastNode == end) {
            foundEnd = true;
            res.push_back(currRow);
         } else {
            for(auto x: adjList[lastNode]) {
               if(!isPresent[x]) {
                     continue;
               }
               vector<int> newRow = currRow; // deep copies the vector
               newRow.push_back(x);
               q.push(newRow);
               nodesToDel.push_back(x);
            }
         }
      }
      for(auto nd: nodesToDel) {
         isPresent[nd] = false;
      }
      if(foundEnd) {
         break;
      }
   }
   return res;
}

vector<vector<string>> findSequences(string startWord, string endWord, vector<string>& wordList) {
   // code here
   bool startWordPresentInList = false;
   bool endWordPresentInList = false;
   vector<vector<string>> res;
   int n = wordList.size();
   for(int i = 0; i < n; i++) {
      if(wordList[i] == startWord) {
            startWordPresentInList = true;
      }
      if(wordList[i] == endWord) {
            endWordPresentInList = true;
      }
   }
   if(!endWordPresentInList) {
      return res;
   }
   if(!startWordPresentInList) {
      wordList.push_back(startWord);
   }
   n = wordList.size();
   unordered_map<string, int> strMap;
   unordered_map<int, string> intToStrMp;
   for(int i = 0; i < n; i++) {
      strMap[wordList[i]] = i;
      intToStrMp[i] = wordList[i];
   }
   
   vector<vector<int>> adjList(n);
   getAdjList(n, wordList, adjList, strMap);
   
   vector<vector<int>> resInt = getSeq(n, adjList, strMap[startWord], strMap[endWord]);
   
   for(int i = 0; i < resInt.size(); i++) {
      vector<string> thisRes;
      for(auto j: resInt[i]) {
         thisRes.push_back(intToStrMp[j]);
      }
      res.push_back(thisRes);
   }
   return res;
}
```
## Question 23: [Implementing Dijkstra Algorithm](https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix)

### Statement:
Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.
 

Note: The Graph doesn't contain any negative weight cycle.

### Solution:
#### Explanation:
1. Keep a distance array - initially - all has INT_MAX
2. update the source = 0
3. create a min priority queue
4. insert pair<dist, node> in the min pq
   1. It gives the pair with min distance first
   2. if there are > 1 pairs with same min distance - it gives the one with least node value
5. push (0, sourceNode) in the min pq
6. get the top of the pq
7. for each neighbour of currNode (top of pq)
   1. check the new distance
   2. if newDist < distance array
      1. Update the distance array value
      2. add a new pair in the pq
8. Keep doing this till pq is empty
9. Why do we use PQ or set instead of queue
   1.  Using queue will also work for us, but it is like an brute force approach
   2.  By using PQ/Set, we want to cover only the minimal paths first - kind of an greedy approach
```c++

vector<int> dijkstraSet(int v, vector<vector<int>> adj[], int s) {
   vector<int> res(v, INT_MAX);
   res[s] = 0;
   
   set<pair<int,int>> nodeSet;
   nodeSet.insert(make_pair(0, s));
   
   while(!nodeSet.empty()) {
      for(auto thisPair: nodeSet) {
         int currDist = thisPair.first;
         int currNode = thisPair.second;
         nodeSet.erase(thisPair);
         
         for(auto neighbours: adj[currNode]) {
            for(int i = 0; i < neighbours.size(); i+=2) {
               int newDist = currDist + neighbours[i+1];
               if(newDist < res[neighbours[i]]) {
                     res[neighbours[i]] = newDist;
                     nodeSet.insert(make_pair(newDist, neighbours[i]));
               }
            }
         }
      }
   }
   return res;
}

vector <int> dijkstra(int v, vector<vector<int>> adj[], int s) {
   // return dijkstraSet(v, adj, s);
   vector<int> res(v, INT_MAX);
   res[s] = 0;
   
   priority_queue< pair<int,int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;
   pq.push(make_pair(0, s));
   while(!pq.empty()) {
      pair<int, int> top = pq.top();
      pq.pop();
      int currNode = top.second;
      int currDist = top.first;
      for(auto neighbours: adj[currNode]) {
            for(int i = 0; i < neighbours.size(); i+=2) {
               int newDist = currDist + neighbours[i+1];
               if(newDist < res[neighbours[i]]) {
                  res[neighbours[i]] = newDist;
                  pq.push(make_pair(newDist, neighbours[i]));
               }
            }
      }
   }
   return res;
}

vector <int> dijkstraUsingMaxPQ(int v, vector<vector<int>> adj[], int s)
{
   // Code here
   vector<int> res(v, INT_MAX);
   res[s] = 0;
   //                 dist, node
   priority_queue<pair<int, int> > pq;
   pq.push(make_pair(0, s));
   while(!pq.empty()) {
      pair<int, int> top = pq.top();
      pq.pop();
      top.first *= (-1);
      int currNode = top.second;
      int currDist = top.first;
      for(auto nbs : adj[currNode]) {
            for(int i = 0; i < nbs.size(); i+=2) {
               int newDist = currDist + nbs[i+1];
               if(newDist < res[nbs[i]]) {
                  res[nbs[i]] = newDist;
                  pq.push(make_pair(newDist*(-1), nbs[i]));
               }
            }
      }
   }
   return res;
}
```

## Question 24: [Shortest Path in Weighted undirected graph](https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph)

### Statement:

You are given a weighted undirected graph having n+1 vertices numbered from 0 to n and m edges describing there are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1.

Example:

Input:
n = 5, m= 6
edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]

Output: 1 4 3 5

Explaination:
Shortest path from 1 to n is by the path 1 4 3 5

### Solution:
#### Explanation:
1. Use the djsktra algorithm - a bit modified
2. We will have a parent array
3. intially, a node will be its own parent
4. proceed with djkstra's algo
5. as we insert in the priority queue for new lesser distances, update the parent array also
6. iterate over the parent array from dest node, untill we find a node which is it's own parent
```c++
void getAdjList(int n, int m, vector<vector<int>>& edges, vector<vector<pair<int,int>>>& adjList) {
   for(int i = 0; i < m; i++) {
      vector<int> thisEdge = edges[i];
      int u = thisEdge[0];
      int v = thisEdge[1];
      int wt = thisEdge[2];
      adjList[u].push_back(make_pair(v, wt));
      adjList[v].push_back(make_pair(u, wt));
   }
}

void dijsktraModified(int n, vector<vector<pair<int,int>>>& adjList, vector<int>& dist, vector<int>& parent, int src, int dest) {
   dist[src] = 0;
   // dist, node
   priority_queue< pair<int,int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;
   pq.push(make_pair(0, src));
   while(!pq.empty()) {
      pair<int, int> thisPair = pq.top();
      pq.pop();
      int currNode = thisPair.second;
      int currDist = thisPair.first;
      for(auto neighbours: adjList[currNode]) {
         pair<int, int> nextPair = neighbours;
         int newDist = currDist + nextPair.second;
         if(newDist < dist[nextPair.first]) {
            dist[nextPair.first] = newDist;
            pq.push(make_pair(newDist, nextPair.first));
            parent[nextPair.first] = currNode;
         }
      }
   }
}

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
   // Code here
   vector<int> res;
   vector<int> dist(n+1, INT_MAX);
   vector<int> parent(n+1, 0);
   for(int i = 0; i <= n; i++) {
      parent[i] = i;
   }
   vector<vector<pair<int,int>>> adjList(n+1);
   getAdjList(n+1, m, edges, adjList);
   dijsktraModified(n+1, adjList, dist, parent, 1, n);
   
   stack<int> resStk;
   int currNode = n;
   while(parent[currNode] != currNode) {
      resStk.push(currNode);
      currNode = parent[currNode];
   }
   
   if(dist[n] == INT_MAX) {
      res.push_back(-1);
   } else {
      resStk.push(currNode);
      while(!resStk.empty()) {
         int tp = resStk.top();
         resStk.pop();
         res.push_back(tp);
      }
   }
   return res;
}
```

## Question 25: [Shortest Distance in a Binary Maze](https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze)

### Statement
Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing.

Example 1:

Input:
grid[][] = 
```
{{1, 1, 1, 1},
{1, 1, 0, 1},
{1, 1, 1, 1},
{1, 1, 0, 0},
{1, 0, 0, 1}}
```
source = {0, 1}
destination = {2, 2}

Output: 3

Explanation:
1 1 1 1
1 1 0 1
1 1 1 1
1 1 0 0
1 0 0 1
The highlighted part in the matrix denotes the 
shortest path from source to destination cell.

Example 2:

Input:
grid[][] = 
```
{{1, 1, 1, 1, 1},
{1, 1, 1, 1, 1},
{1, 1, 1, 1, 0},
{1, 0, 1, 0, 1}}
```
source = {0, 0}
destination = {3, 4}

Output: -1

Explanation:
The path is not possible between source and 
destination, hence return -1.

### Solution
```c++
int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
   int n = grid.size();
   int m = grid[0].size();
   vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
   dist[source.first][source.second] = 0;
   vector<int> nr{-1, 1, 0, 0};
   vector<int> nc{0, 0, -1, 1};
   
   priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>> >, greater<pair<int, pair<int,int>>> > pq;
   // dist, row, col
   pair<int, pair<int,int>> thisPair;
   thisPair.first = 0;
   thisPair.second = source;
   pq.push(thisPair);
   while(!pq.empty()) {
      thisPair = pq.top();
      pq.pop();
      int currDist = thisPair.first;
      pair<int, int> currNode = thisPair.second;
      for(int i = 0; i < 4; i++) {
         int nextRow = currNode.first + nr[i];
         int nextCol = currNode.second + nc[i];
         if(nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= m || grid[nextRow][nextCol] == 0) {
            continue;
         }
         int newDist = currDist + 1;
         if(newDist < dist[nextRow][nextCol]) {
            dist[nextRow][nextCol] = newDist;
            pair<int, pair<int,int>> nextPair;
            nextPair.first = newDist;
            nextPair.second = make_pair(nextRow, nextCol);
            pq.push(nextPair);
         }
      }
   }
   int res = dist[destination.first][destination.second];
   if(res == INT_MAX) {
      return -1;
   }
   return res;
}
```
