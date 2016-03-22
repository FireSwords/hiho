#include <cstdio>
#include <cstring>
#define N 26

typedef struct Trie {
	int flag;
	Trie *next[N];
	Trie *prev;
	Trie() {
		flag = 0;
		memset(next, NULL, sizeof(next));
		prev = NULL; 
	}
};

Trie *root = new Trie();

void build(char* str) {
	int i;
	Trie* pointer = root;
	for (i=0; str[i]; ++i)
	{
		int p = str[i]-'a';
		if (pointer->next[p]==NULL)
		{
			Trie* child = new Trie();
			pointer->next[p] = child;
		}
		pointer = pointer->next[p];
	}
	pointer->flag = 1;
}

int graph(Trie* curr)
{
	for (i=0; i<N; ++i)
	{
		if (curr->next[i]==NULL)
			curr->next[i] = (root->next) + i;
		else
	}
	return pointer->cnt;
}

int main()
{
	int n,m;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", str);
		build(str);
	}
	
	scanf("%d", &m);
	while (m--)
	{
		scanf("%s", str);
		printf("%d\n", quiry(str));
	}
	return 0;
}
