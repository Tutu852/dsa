#include <bits/stdc++.h>
using namespace std;

// Function to check if the cell is safe for movement
bool isSafe(int newx, int newy, vector<vector<bool>>& vis, vector<vector<int>>& arr, int n) {
    if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && vis[newx][newy] != 1 && arr[newx][newy] == 1) {
        return true;
    }
    return false;
}

// Recursive function to solve the maze and generate paths
void solve(int x, int y, vector<vector<int>>& arr, int n, vector<string>& ans, vector<vector<bool>>& vis, string path) {
    // Base case: If we have reached the destination (bottom-right corner)
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    // Mark the current cell as visited
    vis[x][y] = 1;

    // Down movement
    if (isSafe(x + 1, y, vis, arr, n)) {
        solve(x + 1, y, arr, n, ans, vis, path + 'D');
    }
    // Left movement
    if (isSafe(x, y - 1, vis, arr, n)) {
        solve(x, y - 1, arr, n, ans, vis, path + 'L');
    }
    // Right movement
    if (isSafe(x, y + 1, vis, arr, n)) {
        solve(x, y + 1, arr, n, ans, vis, path + 'R');
    }
    // Up movement
    if (isSafe(x - 1, y, vis, arr, n)) {
        solve(x - 1, y, arr, n, ans, vis, path + 'U');
    }

    // Backtrack and unmark the current cell
    vis[x][y] = 0;
}

// Function to initiate the maze-solving and return all paths
vector<string> searchMaze(vector<vector<int>>& arr, int n) {
    vector<string> ans;
    // 2D vector to mark visited cells
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";
    if(arr[0][0] == 0 ){
        return ans;
    }

    // Start solving from the top-left corner (0,0)
    solve(0, 0, arr, n, ans, visited, path);

    return ans;
}


// ---------------------------------------CODE STUDIO--------------------------------------------------