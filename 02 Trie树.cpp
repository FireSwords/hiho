#include <cstdio>
#include <cstring>
#define N 26

typedef struct Trie
{
	int flag;
	int cnt;
	Trie *next[N];	
	Trie() {
		flag = 0;
		cnt = 0;
		memset(next, NULL, sizeof(next));
	}
};

Trie *root = new Trie();
char str[100005];

void build(char* str)
{
	int i;
	Trie* pointer = root;
	pointer->cnt += 1;
	for (i=0; str[i]; ++i)
	{
		int p = str[i]-'a';
		if (pointer->next[p]==NULL)
		{
			Trie* child = new Trie();
			pointer->next[p] = child;
		}
		pointer = pointer->next[p];
		pointer->cnt += 1;
	}
	pointer->flag = 1;
}

int quiry(char* str)
{
	int i;
	Trie* pointer = root;
	for (i=0; str[i]; ++i)
	{
		int p = str[i]-'a';
		if (pointer->next[p]==NULL)
			return 0;
		pointer = pointer->next[p];
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
