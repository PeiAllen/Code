#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
using namespace std;//using namespace __gnu_pbds;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define all(a) (a).begin(),(a).end()
#define For(i,a,b) for(auto i=(a);i<(b);i++)
#define FOR(i,b) For(i,0,b)
#define Rev(i,a,b) for(auto i=(a);i>(b);i--)
#define REV(i,a) Rev(i,a,-1)
#define FORE(i,a) for(auto&&i:a)
template<class C>constexpr int sz(const C&c){return int(c.size());}
using ll=long long;using ld=long double;using uint=unsigned int;using ull=unsigned long long;
using pii=pair<int,int>;using pll=pair<ll,ll>;using pill=pair<int,ll>;using plli=pair<ll,int>;using pdd=pair<double,double>;using pld=pair<ld,ld>;
constexpr const char nl='\n',sp=' ';constexpr const int INT_INF=0x3f3f3f3f;constexpr const ll LL_INF=0x3f3f3f3f3f3f3f3f;
constexpr const double D_INF=numeric_limits<double>::infinity();constexpr const ld LD_INF=numeric_limits<ld>::infinity();
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;}template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;}
template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
template<class T,class...Ts>void MIN(T&x,const Ts&...xs){x=_min(x,xs...);}template<class T,class...Ts>void MAX(T&x,const Ts&...xs){x=_max(x,xs...);}
template<class T>constexpr const T&_clamp(const T&v,const T&lo,const T&hi){return v<lo?lo:hi<v?hi:v;}template<class T>void CLAMP(T&v,const T&lo,const T&hi){v=_clamp(v,lo,hi);}
template<class T,class...Args>unique_ptr<T>_make_unique(Args&&...args){return unique_ptr<T>(new T(forward<Args>(args)...));}
template<class T,class...Args>shared_ptr<T>_make_shared(Args&&...args){return shared_ptr<T>(new T(forward<Args>(args)...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
#define clamp(...) _clamp(__VA_ARGS__)
#define make_unique _make_unique
#define make_shared _make_shared
seed_seq seq {
		(uint64_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
		(uint64_t)__builtin_ia32_rdtsc(),(uint64_t)(uintptr_t)make_unique<char>().get()
};
mt19937 rng(seq);mt19937_64 rng64(seq);const size_t RANDOM=uniform_int_distribution<size_t>(0,(numeric_limits<size_t>::max)())(rng64);
template<class T,class H=hash<T>>struct rand_hash{
	static uint64_t splitmix64(uint64_t x){x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
	size_t operator()(const T&x)const{return splitmix64(H{}(x)+RANDOM);}
};
//template<class K,class H=rand_hash<K>,class...Ts>using hashset=gp_hash_table<K,null_type,H,Ts...>;
//template<class K,class V,class H=rand_hash<K>,class...Ts>using hashmap=gp_hash_table<K,V,H,Ts...>;
////template<class K,class C=less<K>,class...Ts>using treeset=tree<K,null_type,C,rb_tree_tag,tree_order_statistics_node_update,Ts...>;
//template<class K,class V,class C=less<K>,class...Ts>using treemap=tree<K,V,C,rb_tree_tag,tree_order_statistics_node_update,Ts...>;
template<class K,class H=rand_hash<K>,class...Ts>using uset=unordered_set<K,H,Ts...>;template<class K,class V,class H=rand_hash<K>,class...Ts>using umap=unordered_map<K,V,H,Ts...>;
template<class T>using minpq=std::priority_queue<T,vector<T>,greater<T>>;template<class T>using maxpq=std::priority_queue<T,vector<T>,less<T>>;
//template<class T>using minpairingheap=__gnu_pbds::priority_queue<T,greater<T>,pairing_heap_tag>;template<class T>using maxpairingheap=__gnu_pbds::priority_queue<T,less<T>,pairing_heap_tag>;
template<class T1,class T2,class H1=rand_hash<T1>,class H2=rand_hash<T2>>struct pair_hash{size_t operator()(const pair<T1,T2>&p)const{return 31*H1{}(p.first)+H2{}(p.second);}};
template<class T>struct is_iterator {
	template<class U,typename enable_if<!is_convertible<U,const char*>::value,int>::type=0>constexpr static auto has_indirection(int)->decltype(*declval<U>(),bool()){return true;}
	template<class>constexpr static bool has_indirection(long){return false;}constexpr static bool value=has_indirection<T>(0);
};

#define INTERACTIVE_INPUT 0
constexpr const int _bufferSize=1<<16,_maxNumLength=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_sign,*_tempInputBuf=nullptr,_numBuf[_maxNumLength],_tempOutputBuf[_maxNumLength],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=6,_width=0,_tempOutputPtr=0,_cnt;ull _precisionBase=1000000;
#ifdef _WIN32
#define getchar_unlocked getchar
#define fread_unlocked fread
#define fwrite_unlocked fwrite
#endif
#if INTERACTIVE_INPUT
#define _getchar() getchar_unlocked()
#else
#define _peekchar() (*_inputPtr?*_inputPtr:(_inputBuffer[fread_unlocked(_inputPtr=_inputBuffer,1,_bufferSize,_input)]='\0',*_inputPtr))
#define _getchar() (*_inputPtr?*_inputPtr++:(_inputBuffer[fread_unlocked(_inputPtr=_inputBuffer,1,_bufferSize,_input)]='\0',*_inputPtr++))
#define _hasNext() (*_inputPtr||!feof(_input))
bool hasNext(){while(_hasNext()&&_peekchar()<=' ')_getchar();return _hasNext();}bool hasNextLine(){while(_hasNext()&&_peekchar()=='\r')_getchar();return _hasNext();}
#endif
#define _readSignAndNum(x) do{(x)=_getchar();}while((x)<=' ');_sign=(x)=='-';if(_sign)(x)=_getchar();for((x)-='0';(_c=_getchar())>='0';(x)=(x)*10+_c-'0')
#define _readFloatingPoint(x,T) for(T _div=1.0;(_c=_getchar())>='0';(x)+=(_c-'0')/(_div*=10))
#define rc(x) do{do{(x)=_getchar();}while((x)<=' ');}while(0)
#define ri(x) do{_readSignAndNum(x);if(_sign)(x)=-(x);}while(0)
#define rd(x) do{_readSignAndNum(x);if(_c=='.')_readFloatingPoint(x,double);if(_sign)(x)=-(x);}while(0)
#define rld(x) do{_readSignAndNum(x);if(_c=='.')_readFloatingPoint(x,ld);if(_sign)(x)=-(x);}while(0)
#define rcs(x) do{_cur=0;do{_c=_getchar();}while(_c<=' ');do{(x)[_cur++]=_c;}while((_c=_getchar())>' ');(x)[_cur]='\0';}while(0)
#define rs(x) do{if(!_tempInputBuf)assert(0);rcs(_tempInputBuf);(x)=string(_tempInputBuf,_cur);}while(0)
#define rcln(x) do{_cur=0;while((_c=_getchar())!='\n'){if(_c!='\r')(x)[_cur++]=_c;}(x)[_cur]='\0';}while(0)
#define rln(x) do{if(!_tempInputBuf)assert(0);rcln(_tempInputBuf);(x)=string(_tempInputBuf,_cur);}while(0)
void setLength(int x){if(_tempInputBuf)delete[](_tempInputBuf);_tempInputBuf=new char[x+1];}
void read(int&x){ri(x);}void read(uint&x){ri(x);}void read(ll&x){ri(x);}void read(ull&x){ri(x);}void read(double&x){rd(x);}void read(ld&x){rld(x);}
void read(char&x){rc(x);}void read(char*x){rcs(x);}void read(string&x){rs(x);}void readln(char*x){rcln(x);}void readln(string&x){rln(x);}
template<class T1,class T2>void read(pair<T1,T2>&x){read(x.first);read(x.second);}template<class T>void read(complex<T>&x){T _re,_im;read(_re);read(_im);x.real(_re);x.imag(_im);}
template<class T>void read(T&x);template<class T,class...Ts>void read(T&x,Ts&&...xs);
template<class It>typename enable_if<is_iterator<It>::value>::type read(It st,It en){for(It _i=st;_i!=en;_i++)read(*_i);}
template<class It,class...Ts>typename enable_if<is_iterator<It>::value>::type read(It st,It en,Ts&&...xs){read(st,en);read(forward<Ts>(xs)...);}
template<class T>void read(T&x){for(auto&&_i:x)read(_i);}template<class T,class...Ts>void read(T&x,Ts&&...xs){read(x);read(forward<Ts>(xs)...);}
void setInput(FILE*file){*_inputPtr='\0';_input=file;}void setInput(const char*s){*_inputPtr='\0';_input=fopen(s,"r");}void setInput(const string&s){*_inputPtr='\0';_input=fopen(s.c_str(),"r");}
#define _flush() do{_flushBuf();fflush(_output);}while(0)
#define _flushBuf() (fwrite_unlocked(_outputBuffer,1,_outputPtr,_output),_outputPtr=0)
#define _putchar(x) (_outputBuffer[_outputPtr==_bufferSize?_flushBuf():_outputPtr]=(x),_outputPtr++)
#define _writeTempBuf(x) (_tempOutputBuf[_tempOutputPtr++]=(x))
#define _writeOutput() for(int _i=0;_i<_tempOutputPtr;_putchar(_tempOutputBuf[_i++]));_tempOutputPtr=0
#define _writeNum(x,T,digits) _cnt=0;for(T _y=(x);_y;_y/=10,_cnt++)_numBuf[_numPtr++]='0'+_y%10;for(;_cnt<digits;_cnt++)_numBuf[_numPtr++]='0';_flushNumBuf();
#define _writeFloatingPoint(x,T) ull _I=(ull)(x);ull _F=((x)-_I)*_precisionBase+(T)(0.5);if(_F>=_precisionBase){_I++;_F=0;}_writeNum(_I,ull,1);_writeTempBuf('.');_writeNum(_F,ull,_precision)
#define _checkFinite(x) if(std::isnan(x)){wcs("NaN");}else if(std::isinf(x)){wcs("Inf");}
#define _flushNumBuf() for(;_numPtr;_writeTempBuf(_numBuf[--_numPtr]))
#define _fillBuf(x) for(int _i=0;_i<(x);_i++)_putchar(_fill)
#define _flushTempBuf() int _tempLen=_tempOutputPtr;_fillBuf(_width-_tempLen);_writeOutput();_fillBuf(-_width-_tempLen)
#define wb(x) do{if(x)_writeTempBuf('1');else _writeTempBuf('0');_flushTempBuf();}while(0)
#define wc(x) do{_writeTempBuf(x); _flushTempBuf();}while(0)
#define wi(x) do{if((x)<0){_writeTempBuf('-');_writeNum(-(x),uint,1);}else{_writeNum(x,uint,1);}_flushTempBuf();}while(0)
#define wll(x) do{if((x)<0){_writeTempBuf('-');_writeNum(-(x),ull,1);}else{_writeNum(x,ull,1);}_flushTempBuf();}while(0)
#define wd(x) do{_checkFinite(x)else if((x)<0){_writeTempBuf('-');_writeFloatingPoint(-(x),double);}else{_writeFloatingPoint(x,double);}_flushTempBuf();}while(0)
#define wld(x) do{_checkFinite(x)else if((x)<0){_writeTempBuf('-');_writeFloatingPoint(-(x),ld);}else{_writeFloatingPoint(x,ld);}_flushTempBuf();}while(0)
#define wcs(x) do{int _slen=strlen(x);_fillBuf(_width-_slen);for(const char*_p=(x);*_p;_putchar(*_p++));_fillBuf(-_width-_slen);}while(0)
#define ws(x) do{_fillBuf(_width-int((x).length()));for(int _i=0;_i<int((x).length());_putchar(x[_i++]));_fillBuf(-_width-int((x).length()));}while(0)
void setPrecision(int x){_precision=x;_precisionBase=1;for(int _i=0;_i<x;_i++,_precisionBase*=10);}void setWidth(int x){_width=x;}void setFill(char x){_fill=x;}
void setDelimiter(const char*x){_delimiter=x;}void setDelimiter(const string&x){_delimiter=x.c_str();}
void writeDelimiter(){for(const char*_p=_delimiter;*_p;_putchar(*_p++));}
void write(const bool&x){wb(x);}void write(const int&x){wi(x);}void write(const uint&x){wi(x);}void write(const ll&x){wll(x);}void write(const ull&x){wll(x);}
void write(const double&x){wd(x);}void write(const ld&x){wld(x);}void write(const char&x){wc(x);}void write(const char*x){wcs(x);}void write(const string&x){ws(x);}
template<class T1,class T2>void write(const pair<T1,T2>&x){write(x.first);writeDelimiter();write(x.second);}
template<class T>void write(const complex<T>&x){write(x.real());writeDelimiter();write(x.imag());}
template<class T>void write(const T&x);template<class T,class...Ts>void write(const T&x,Ts&&...xs);
template<class It>typename enable_if<is_iterator<It>::value>::type write(It st,It en){bool _first=1;for(It _i=st;_i!=en;_i++){if(_first)_first=0;else writeDelimiter();write(*_i);}}
template<class It,class...Ts>typename enable_if<is_iterator<It>::value>::type write(It st,It en,Ts&&...xs){write(st,en);writeDelimiter();write(forward<Ts>(xs)...);}
template<class T>void write(const T&x){bool _first=1;for(auto&&_i:x){if(_first)_first=0;else writeDelimiter();write(_i);}}
template<class T,class...Ts>void write(const T&x,Ts&&...xs){write(x);writeDelimiter();write(forward<Ts>(xs)...);}
void writeln(){_putchar('\n');}template<class...Ts>void writeln(Ts&&...xs){write(forward<Ts>(xs)...);_putchar('\n');}
void flush(){_flush();}class IOManager{public:~IOManager(){flush();if(_tempInputBuf)delete[](_tempInputBuf);}};unique_ptr<IOManager>iomanager=make_unique<IOManager>();
void setOutput(FILE*file){flush();_output=file;}void setOutput(const char*s){flush();_output=fopen(s,"w");}void setOutput(const string&s){flush();_output=fopen(s.c_str(),"w");}
template<class...Ts>void debug(const Ts&...xs){FILE*_temp=_output;setOutput(_error);write(xs...);setOutput(_temp);}
template<class...Ts>void debugln(const Ts&...xs){FILE*_temp=_output;setOutput(_error);writeln(xs...);setOutput(_temp);}
void setError(FILE*file){flush();_error=file;}void setError(const char*s){flush();_error=fopen(s,"w");}void setError(const string&s){flush();_error=fopen(s.c_str(),"w");}

template <class T> struct MaxContiguousSubarrayData { T pre, suf, sum, maxSum; bool isNull; };
template <class T> MaxContiguousSubarrayData<T> makeData(bool isNull = true, const T &v = 0) {
	MaxContiguousSubarrayData<T> ret; ret.pre = ret.suf = ret.sum = ret.maxSum = v; ret.isNull = isNull; return ret;
}
template <class T> MaxContiguousSubarrayData<T> merge(const MaxContiguousSubarrayData<T> &l, const MaxContiguousSubarrayData<T> &r) {
	if (l.isNull) return r;
	if (r.isNull) return l;
	MaxContiguousSubarrayData<T> ret; ret.isNull = false; ret.pre = max(l.pre, l.sum + r.pre); ret.suf = max(l.suf + r.sum, r.suf);
	ret.sum = l.sum + r.sum; ret.maxSum = max(max(l.maxSum, r.maxSum), l.suf + r.pre); return ret;
}
// range assignments
template <class T> MaxContiguousSubarrayData<T> applyLazy(const MaxContiguousSubarrayData<T> &l, const pair<T, T> &r) {
	MaxContiguousSubarrayData<T> ret; ret.pre = ret.suf = ret.maxSum = max(r.first, r.second); ret.sum = r.first; ret.isNull = false; return ret;
}
// getSegmentVal returns a pair containing the range value, and the actual value
template <class T> pair<T, T> getSegmentVal(const pair<T, T> &l, int len) { return make_pair(l.first * len, l.second); }
template <class T> pair<T, T> mergeLazy(const pair<T, T> &l, const pair<T, T> &r) { return r; }

using Data = MaxContiguousSubarrayData<ll>; using Lazy = pll; const Data vdef = makeData<ll>(); const Lazy ldef = mp(LL_INF, LL_INF);
// Data merge(const Data &l, const Data &r); // to be implemented
// Lazy getSegmentVal(const Lazy &v, int k); // to be implemented
// Lazy mergeLazy(const Lazy &l, const Lazy &r); // to be implemented
// Data applyLazy(const Data &l, const Lazy &r); // to be implemented
void revData(Data &v) { swap(v.pre, v.suf); }
struct Node {
	Node *l, *r, *p; int size; Data val, sbtr; Lazy lz; bool rev;
	Node(const Data &val) : l(nullptr), r(nullptr), p(nullptr), size(1), val(val), sbtr(val), lz(ldef), rev(false) {}
	void update(); void apply(const Lazy &v); void propagate(); void rotate(Node *rootP); void splay(Node *rootP);
};
int Size(Node *x) { return x ? x->size : 0; }
Data Val(Node *x) { return x ? x->val : vdef; }
Data Sbtr(Node *x) { return x ? x->sbtr : vdef; }
void Node::update() {
	size = 1; sbtr = val;
	if (l) { size += l->size; sbtr = merge(l->sbtr, sbtr); }
	if (r) { size += r->size; sbtr = merge(sbtr, r->sbtr); }
}
void Node::apply(const Lazy &v) { val = applyLazy(val, v); sbtr = applyLazy(sbtr, getSegmentVal(v, size)); lz = mergeLazy(lz, v); }
void Node::propagate() {
	if (rev) {
		swap(l, r); rev = false;
		if (l) { l->rev = !l->rev; revData(l->sbtr); }
		if (r) { r->rev = !r->rev; revData(r->sbtr); }
	}
	if (lz != ldef) {
		if (l) l->apply(lz);
		if (r) r->apply(lz);
		lz = ldef;
	}
}
void connect(Node *ch, Node *par, bool isL) {
	if (ch) ch->p = par;
	if (par) (isL ? par->l : par->r) = ch;
}
void Node::rotate(Node *rootP) {
	Node *p = this->p, *g = p->p; bool isRootP = g == rootP, isL = this == p->l;
	connect(isL ? r : l, p, isL); connect(p, this, !isL); connect(this, g, isRootP ? false : p == g->l); p->update();
}
void Node::splay(Node *rootP) {
	while (p != rootP) {
		Node *p = this->p, *g = p->p;
		if (g != rootP) g->propagate();
		p->propagate(); propagate();
		if (g != rootP) ((this == p->l) == (p == g->l) ? p : this)->rotate(rootP);
		rotate(rootP);
	}
	propagate(); update();
}
struct LazyImplicitSplayTree {
	Node *root = nullptr; vector<Node> T;
	Node *select(Node *x, int k) {
		if (!x) return nullptr;
		x->propagate(); int t = Size(x->l);
		if (t > k) return select(x->l, k);
		else if (t < k) return select(x->r, k - t - 1);
		return x;
	}
	Node *build(int l, int r, const vector<Data> &A) {
		if (l > r) return nullptr;
		int m = l + (r - l) / 2, i = int(T.size()); T.emplace_back(A[m]);
		Node *left = build(l, m - 1, A), *right = build(m + 1, r, A), *x = &(T[i]);
		connect(left, x, true); connect(right, x, false); x->update();
		return x;
	}
	// [l, r] is at root->r->l
	void slice(int l, int r) { (root = select(root, l - 1))->splay(nullptr); select(root, r + 1)->splay(root); }
	void updateToRoot() { if (root->r->l) { root->r->l->propagate(); root->r->l->update(); } root->r->update(); root->update(); }
	// 1-indexed, inclusive
	void updateVal(int ind, const Lazy &val) { slice(ind, ind); root->r->l->apply(val); updateToRoot(); }
	void updateRange(int l, int r, const Lazy &val) {
		slice(l, r);
		if (root->r->l) root->r->l->apply(val);
		updateToRoot();
	}
	void reverseRange(int l, int r) {
		slice(l, r);
		if (root->r->l) { root->r->l->rev = !root->r->l->rev; revData(root->r->l->sbtr); }
		updateToRoot();
	}
	Data queryVal(int ind) { slice(ind, ind); return Val(root->r->l); }
	Data queryRange(int l, int r) { slice(l, r); return Sbtr(root->r->l); }
	LazyImplicitSplayTree(int N) { T.reserve(N + 2); vector<Data> A(N + 2, vdef); root = build(0, A.size() - 1, A); }
	template <class It> LazyImplicitSplayTree(It st, It en) {
		T.reserve(en - st + 2); vector<Data> A; A.push_back(vdef); A.insert(A.end(), st, en); A.push_back(vdef);
		root = build(0, A.size() - 1, A);
	}
};

const int MAXN = 1e5 + 5;

int N, Q;
MaxContiguousSubarrayData<ll> A[MAXN];
string S;

int main() {
	// setInput("in.txt");
	// setOutput("out.txt");
	// setError("err.txt");
	freopen("C:\\Users\\allen\\CLionProjects\\gen\\input.txt","w",stdout);
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<std::mt19937::result_type> dist6(1,1000000);
	setLength(MAXN);
	cin>>N>>Q;
	cout<<N<<" "<<Q<<"\n";
	FOR(i, N){
		bool te=dist6(rng)%2;
		if(te)cout<<'1';
		else cout<<'0';
		A[i] = makeData<ll>(false, te ? 1 : -INT_INF);
	}
	cout<<'\n';
	LazyImplicitSplayTree T(A, A + N);
	vector<int> ans;
	FOR(i, Q) {
		int t=dist6(rng)%2+1;
		int s=dist6(rng)%N;
		int len=dist6(rng)%(N-s)+1;
		cout<<t<<" "<<s<<" "<<len<<"\n";
		if (t == 1) T.reverseRange(s + 1, s + len);
		else ans.push_back(max(0LL, T.queryRange(s + 1, s + len).maxSum));
	}
	for(int x:ans)cout<<x<<"\n";
	return 0;
}