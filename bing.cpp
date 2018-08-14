//problem bing it on at kattis. 0.03s. Solved using wordtrie.
#include <bits/stdc++.h>

using namespace std;

struct Node{
	bool is_end;
	Node *children[26];
	int count;

	Node(){
		memset(children, 0, sizeof(children));
		count = 0;
		is_end = false;
	}
};

void insert_word(Node* node, char* s){
	if(*s){
		node->count++;
		if(!node->children[*s - 'a']) node->children[*s - 'a'] = new Node();
		insert_word(node->children[*s - 'a'], s + 1);
	}else{
		node->is_end = true;
		node->count++;
	}
}

int get_count(Node* node, char* s){
	if(*s){
		if(!node->children[*s - 'a']){
			return 0;
		}else{
			return get_count(node->children[*s - 'a'], s+ 1);
		}
	}
	else{
		return node->count;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	char word[33];
	Node* trie = new Node();
	for(int i = 0; i < N; i++){
		cin >> word;
		cout << get_count(trie, word) << "\n";
		insert_word(trie, word);
	}
	return 0;
}
