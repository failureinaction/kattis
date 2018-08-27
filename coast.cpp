//coast at kattis.
#include <bits/stdc++.h>

using namespace std;

bool flood_fill(const vector<vector<bool>>& grid, int row, int col, int height, int width){
	if(row < 0 || col < 0 || row >= height + 2|| col >= width + 2 || grid[row][col]) return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	//We add an extra row and column of water to each side. Thus we do not need to worry about lakes when we use floodfill.
	vector<vector<bool>> grid(n + 2, vector<bool> (m + 2, false));
	vector<vector<bool>> visited(n + 2, vector<bool> (m + 2, false));
	string inp;
	for(int i = 1; i <= n; i++){
		cin >> inp;
		for(int j = 0; j < m; j++){
			if(inp[j] == '1') grid[i][j+1] = true;
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	int xcoord, ycoord;
	while(!q.empty()){
		xcoord = q.front().first; ycoord = q.front().second;
		q.pop();

		if(visited[xcoord][ycoord]) continue;
		visited[xcoord][ycoord] = true;

		//make children aka floodfill in this case.
		if(flood_fill(grid, xcoord + 1, ycoord, n, m)) q.push(make_pair(xcoord + 1, ycoord));
		if(flood_fill(grid, xcoord, ycoord + 1, n, m)) q.push(make_pair(xcoord, ycoord + 1));
		if(flood_fill(grid, xcoord - 1, ycoord, n, m)) q.push(make_pair(xcoord - 1, ycoord));
		if(flood_fill(grid, xcoord, ycoord - 1, n, m)) q.push(make_pair(xcoord, ycoord - 1));
	}

	//calculate the coastline
	int coastline = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(visited[i][j]) continue;
			if(visited[i + 1][j]) coastline++;
			if(visited[i - 1][j]) coastline++;
			if(visited[i][j+1]) coastline++;
			if(visited[i][j-1]) coastline++;
		}
	}
	cout << coastline << "\n";

	return 0;
}

