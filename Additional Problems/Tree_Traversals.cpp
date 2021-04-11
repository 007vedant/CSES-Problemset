#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; 
using namespace __gnu_pbds; 

typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> Tree;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define INF    0x3f3f3f3f3f3f3f3fLL


const int MOD = 1e9+7;
const int N = 1e5+5;

int n;
vi in(N), pre(N);
map<int, int> mp;

struct Node
{
	int val;
	Node* left;
	Node* right;
};

Node* newNode(int num)
{
	Node* node = new Node;
	node->val = num;
	node->left = node->right = NULL;
	return node;

};

Node* build(int st, int ed) {
	static int preI = 0;
	if(st > ed) return NULL;

	int curr = pre[preI++];
	Node* tnode = newNode(curr);

	if(st == ed) return tnode;

	int inI = mp[curr];
	tnode->left = build(st, inI-1);
	tnode->right = build(inI+1, ed);

	return tnode;
}

void post(Node* node, vi &ans) {
	if(node == NULL) return;
	post(node->left, ans);
	post(node->right, ans);

	ans.pb(node->val);
}


int main() {
	FASTIO;
	cin >> n;
	rep(i, 0, n) cin >> pre[i];
	rep(i, 0, n) {
		cin >> in[i];
		mp[in[i]] = i;
	}

	Node* head = build(0, n-1);
	vi ans;

	post(head, ans);

	for(int x: ans) cout << x << " ";
	

return 0;
}