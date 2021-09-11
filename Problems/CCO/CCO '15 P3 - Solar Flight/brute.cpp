//#define ONLINE_JUDGE
//
//#include <bits/stdc++.h>
//#define gc getchar_unlocked()
//#define pc(x) putchar_unlocked(x)
//template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
//template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
//template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
//template<typename T> void print(T n){printn(n);pc(10);}
//template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}
//
//using namespace std;
//using ll = long long;
//using ld = long double;
//using pii = pair<int, int>;
//const int MM = 2002, MN = 800002;
//
//struct sparse_table{
//    int n; ll sp[12][MM];
//    vector<ld> vec;
//    ll query(int a, int b){
//        a = upper_bound(vec.begin(), vec.end(), a) - 1 - vec.begin(); //take last value
//        b = upper_bound(vec.begin(), vec.end(), b) - 1 - vec.begin();
//        int k = 31-__builtin_clz(b-a+1);
//        return max(sp[k][a], sp[k][b-(1<<k)+1]);
//    }
//    void build(int _n){
//        n = _n;
//        for(int k = 1; k <= 31-__builtin_clz(n+1); k++)
//            for(int i = 0; i+(1<<k) <= n; i++)
//                sp[k][i] = max(sp[k-1][i], sp[k-1][i+(1<<(k-1))]);
//    }
//    void clear(){
//        memset(sp, 0, sizeof sp);
//        vec.clear();
//    }
//} rmq;
//
//int x, k, n, q, a[MM], b[MM], c[MM];
//vector<pair<ld, ll>> dif[MM];
//// x, value
//map<int, ll, greater<int>> mp;
//ll ans[MN];
//vector<pii> qu[MM];
//
//int main(){
//
//    scan(x, k, n, q);
//
//    for(int i = 0; i < n; i++){
//        scan(a[i], b[i], c[i]);
//        mp[a[i]] += c[i];
//    }
//
//    ll sum = 0;
//    for(auto &i: mp){
//        sum += i.second;
//        i.second = sum-i.second;
//    }
//
//    for(int i = 0; i < n; i++)
//        dif[i].emplace_back(0, mp[a[i]]);
//
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < i; j++){
//            ld inter = ld(a[j]-a[i])*x/(b[i]-a[i]-b[j]+a[j]);
//            if(inter >= x || inter <= 0) continue;
//            //i overtakes j
//            if(a[i] > a[j]){
//                dif[j].emplace_back(inter, -c[i]);
//                dif[i].emplace_back(inter, c[j]);
//            }
//            else{
//                dif[j].emplace_back(inter, c[i]);
//                dif[i].emplace_back(inter, -c[j]);
//            }
//        }
//    }
//
//    for(int i = 0,l,s; i < q; i++){
//        scan(l, s);
//        qu[l-1].emplace_back(s, i);
//    }
//
//    for(int i = 0; i < n; i++){
//        sort(dif[i].begin(), dif[i].end());
//        rmq.clear();
//        int nj = 0;
//        for(int j = 0; j < dif[i].size(); j++){
//            if(j) dif[i][j].second += dif[i][j-1].second;
//            if(j < dif[i].size()-1 && dif[i][j].first == dif[i][j+1].first)
//                continue;
//            rmq.sp[0][nj] = dif[i][j].second;
//            rmq.vec.emplace_back(dif[i][j].first);
//            nj++;
//        }
//        rmq.build(dif[i].size());
//        for(auto p: qu[i]){
//            ans[p.second] = rmq.query(p.first, p.first+k);
//        }
//    }
//
//    for(int i = 0; i < q; i++)
//        print(ans[i]);
//
//    return 0;
//}
//#include <bits/stdc++.h>
//using namespace std;
//#define f first
//#define s second
//#define lc (rt<<1)
//#define rc (rt<<1|1)
//#define pb push_back
//#define cl(a, b) memset(a, b, sizeof(a))
//typedef long long ll;
//typedef pair<int, int> pi;
//typedef pair<int, pi> pii;
//typedef vector<int> vi;
//typedef vector<pi> vii;
//const int inf = 0x3F3F3F3F;
//const ll infl = 0x3F3F3F3F3F3F3F3FLL;
//double eps = 1e-6; const int MM = 2002, MQ = 8e5+2;
//ll X, K, N, Q, solar, p, s, a[MM], b[MM], c[MM], rmq[13][MM], ans[MQ];
//vector<pair<double, ll> > cross[MM]; vii q[MM];
//ll RMQ(int l, int r){
//    int lvl = log2(r-l+1);
//    return max(rmq[lvl][l], rmq[lvl][r-(1<<lvl)+1]);
//}
//int main(){
//    //freopen("test.txt", "r", stdin);
//    scanf("%lld %lld %lld %lld", &X, &K, &N, &Q);
//    for(int i=1; i<=N; i++)
//        scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
//    for(int i=1, id, x; i<=Q; i++){
//        scanf("%d %d", &id, &x); q[id].pb({x, i});
//    }
//    for(int i=1; i<=N; i++){
//        cross[i].pb({0, 0});
//        for(int j=1; j<=N; j++){
//            if(i == j) continue;
//            if(a[i] < a[j]) cross[i][0].s += c[j];
//            if(a[i] > a[j] && b[i] < b[j]){
//                double x = (double)(a[i]-a[j])*X/((a[i] - a[j]) + (b[j] - b[i]));
//                if(x < X) cross[i].pb({x, c[j]});
//            }else if(a[i] < a[j] && b[i] > b[j]){
//                double x = (double)(a[j]-a[i])*X/((a[j] - a[i]) + (b[i] - b[j]));
//                if(x < X) cross[i].pb({x, -c[j]});
//            }
//        }
//        sort(cross[i].begin(), cross[i].end());
//        for(int j=1; j<cross[i].size(); j++){
//            if(abs(cross[i][j].f - cross[i][j-1].f) < eps){
//                cross[i][j].s += cross[i][j-1].s; cross[i][j-1] = cross[i][0];
//            }
//        }
//        sort(cross[i].begin(), cross[i].end());
//        int len = unique(cross[i].begin(), cross[i].end()) - cross[i].begin();
//        for(int j=0; j<len; j++){
//            if(j > 0) cross[i][j].s += cross[i][j-1].s;
//            rmq[0][j] = cross[i][j].s;
//        }
////        cout << "airplane " << i << ": ";
////        for(auto e: cross[i]) cout << "(" << e.f << ", " << e.s << ") ";
////        cout << endl;
//        for(int lvl=1; lvl<13; lvl++)
//            for(int j=0; j+(1<<lvl)-1<len; j++)
//                rmq[lvl][j] = max(rmq[lvl-1][j], rmq[lvl-1][j+(1<<(lvl-1))]);
//        for(pi &e: q[i]){
//            int pos = e.f, id = e.s;
//            int rr = lower_bound(cross[i].begin(), cross[i].begin()+len, make_pair((double)pos+K, infl)) - cross[i].begin() - 1;
//            int ll = upper_bound(cross[i].begin(), cross[i].begin()+len, make_pair((double)pos, infl)) - cross[i].begin() - 1;
//            ans[id] = RMQ(ll, rr);
//        }
//    }
//    for(int i=1; i<=Q; i++) cout << ans[i] << "\n";
//}
//#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
//using namespace std;using namespace __gnu_pbds;
//#define pb push_back
//#define eb emplace_back
//#define mp make_pair
//#define f first
//#define s second
//#define all(a) (a).begin(),(a).end()
//#define For(i,a,b) for(auto i=(a);i<(b);i++)
//#define FOR(i,b) For(i,0,b)
//#define Rev(i,a,b) for(auto i=(a);i>(b);i--)
//#define REV(i,a) Rev(i,a,-1)
//#define FORE(i,a) for(auto&&i:a)
//template<class C>constexpr int sz(const C&c){return int(c.size());}
//using ll=long long;using ld=long double;using uint=unsigned int;using ull=unsigned long long;
//using pii=pair<int,int>;using pll=pair<ll,ll>;using pill=pair<int,ll>;using plli=pair<ll,int>;using pdd=pair<double,double>;using pld=pair<ld,ld>;
//constexpr const char nl='\n',sp=' ';constexpr const int INT_INF=0x3f3f3f3f;constexpr const ll LL_INF=0x3f3f3f3f3f3f3f3f;
//constexpr const double D_INF=numeric_limits<double>::infinity();constexpr const ld LD_INF=numeric_limits<ld>::infinity();
//template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;}template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;}
//template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
//template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
//template<class T,class...Ts>void MIN(T&x,const Ts&...xs){x=_min(x,xs...);}template<class T,class...Ts>void MAX(T&x,const Ts&...xs){x=_max(x,xs...);}
//template<class T>constexpr const T&_clamp(const T&v,const T&lo,const T&hi){return v<lo?lo:hi<v?hi:v;}template<class T>void CLAMP(T&v,const T&lo,const T&hi){v=_clamp(v,lo,hi);}
//template<class T,class...Args>unique_ptr<T>_make_unique(Args&&...args){return unique_ptr<T>(new T(forward<Args>(args)...));}
//template<class T,class...Args>shared_ptr<T>_make_shared(Args&&...args){return shared_ptr<T>(new T(forward<Args>(args)...));}
//#define min(...) _min(__VA_ARGS__)
//#define max(...) _max(__VA_ARGS__)
//#define clamp(...) _clamp(__VA_ARGS__)
//#define make_unique _make_unique
//#define make_shared _make_shared
//seed_seq seq {
//        (uint64_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
//        (uint64_t)__builtin_ia32_rdtsc(),(uint64_t)(uintptr_t)make_unique<char>().get()
//};
//mt19937 rng(seq);mt19937_64 rng64(seq);const size_t RANDOM=uniform_int_distribution<size_t>(0,(numeric_limits<size_t>::max)())(rng64);
//template<class T,class H=hash<T>>struct rand_hash{
//    static uint64_t splitmix64(uint64_t x){x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
//    size_t operator()(const T&x)const{return splitmix64(H{}(x)+RANDOM);}
//};
//template<class K,class H=rand_hash<K>,class...Ts>using hashset=gp_hash_table<K,null_type,H,Ts...>;
//template<class K,class V,class H=rand_hash<K>,class...Ts>using hashmap=gp_hash_table<K,V,H,Ts...>;
//template<class K,class C=less<K>,class...Ts>using treeset=tree<K,null_type,C,rb_tree_tag,tree_order_statistics_node_update,Ts...>;
//template<class K,class V,class C=less<K>,class...Ts>using treemap=tree<K,V,C,rb_tree_tag,tree_order_statistics_node_update,Ts...>;
//template<class K,class H=rand_hash<K>,class...Ts>using uset=unordered_set<K,H,Ts...>;template<class K,class V,class H=rand_hash<K>,class...Ts>using umap=unordered_map<K,V,H,Ts...>;
//template<class T>using minpq=std::priority_queue<T,vector<T>,greater<T>>;template<class T>using maxpq=std::priority_queue<T,vector<T>,less<T>>;
//template<class T>using minpairingheap=__gnu_pbds::priority_queue<T,greater<T>,pairing_heap_tag>;template<class T>using maxpairingheap=__gnu_pbds::priority_queue<T,less<T>,pairing_heap_tag>;
//template<class T1,class T2,class H1=rand_hash<T1>,class H2=rand_hash<T2>>struct pair_hash{size_t operator()(const pair<T1,T2>&p)const{return 31*H1{}(p.first)+H2{}(p.second);}};
//template<class T>struct is_iterator {
//    template<class U,typename enable_if<!is_convertible<U,const char*>::value,int>::type=0>constexpr static auto has_indirection(int)->decltype(*declval<U>(),bool()){return true;}
//    template<class>constexpr static bool has_indirection(long){return false;}constexpr static bool value=has_indirection<T>(0);
//};
//
//#define INTERACTIVE_INPUT 0
//constexpr const int _bufferSize=4096,_maxNumLength=128;
//char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_sign,*_tempInputBuf=nullptr,_numBuf[_maxNumLength],_tempOutputBuf[_maxNumLength],_fill=' ';
//FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=6,_width=0,_tempOutputPtr=0,_cnt;ull _precisionBase=1000000;
//#if INTERACTIVE_INPUT
//#define _getchar() getchar()
//#else
//#define _peekchar() (*_inputPtr?*_inputPtr:(_inputBuffer[fread(_inputPtr=_inputBuffer,1,_bufferSize,_input)]='\0',*_inputPtr))
//#define _getchar() (*_inputPtr?*_inputPtr++:(_inputBuffer[fread(_inputPtr=_inputBuffer,1,_bufferSize,_input)]='\0',*_inputPtr++))
//#define _hasNext() (*_inputPtr||!feof(_input))
//bool hasNext(){while(_hasNext()&&_peekchar()<=' ')_getchar();return _hasNext();}bool hasNextLine(){while(_hasNext()&&_peekchar()=='\r')_getchar();return _hasNext();}
//#endif
//#define _readSignAndNum(x) do{(x)=_getchar();}while((x)<=' ');_sign=(x)=='-';if(_sign)(x)=_getchar();for((x)-='0';(_c=_getchar())>='0';(x)=(x)*10+_c-'0')
//#define _readFloatingPoint(x,T) for(T _div=1.0;(_c=_getchar())>='0';(x)+=(_c-'0')/(_div*=10))
//#define rc(x) do{do{(x)=_getchar();}while((x)<=' ');}while(0)
//#define ri(x) do{_readSignAndNum(x);if(_sign)(x)=-(x);}while(0)
//#define rd(x) do{_readSignAndNum(x);if(_c=='.')_readFloatingPoint(x,double);if(_sign)(x)=-(x);}while(0)
//#define rld(x) do{_readSignAndNum(x);if(_c=='.')_readFloatingPoint(x,ld);if(_sign)(x)=-(x);}while(0)
//#define rcs(x) do{_cur=0;do{_c=_getchar();}while(_c<=' ');do{(x)[_cur++]=_c;}while((_c=_getchar())>' ');(x)[_cur]='\0';}while(0)
//#define rs(x) do{if(!_tempInputBuf)assert(0);rcs(_tempInputBuf);(x)=string(_tempInputBuf,_cur);}while(0)
//#define rcln(x) do{_cur=0;while((_c=_getchar())!='\n'){if(_c!='\r')(x)[_cur++]=_c;}(x)[_cur]='\0';}while(0)
//#define rln(x) do{if(!_tempInputBuf)assert(0);rcln(_tempInputBuf);(x)=string(_tempInputBuf,_cur);}while(0)
//void setLength(int x){if(_tempInputBuf)delete[](_tempInputBuf);_tempInputBuf=new char[x+1];}
//void read(int&x){ri(x);}void read(uint&x){ri(x);}void read(ll&x){ri(x);}void read(ull&x){ri(x);}void read(double&x){rd(x);}void read(ld&x){rld(x);}
//void read(char&x){rc(x);}void read(char*x){rcs(x);}void read(string&x){rs(x);}void readln(char*x){rcln(x);}void readln(string&x){rln(x);}
//template<class T1,class T2>void read(pair<T1,T2>&x){read(x.first);read(x.second);}template<class T>void read(complex<T>&x){T _re,_im;read(_re);read(_im);x.real(_re);x.imag(_im);}
//template<class T>void read(T&x);template<class T,class...Ts>void read(T&x,Ts&&...xs);
//template<class It>typename enable_if<is_iterator<It>::value>::type read(It st,It en){for(It _i=st;_i!=en;_i++)read(*_i);}
//template<class It,class...Ts>typename enable_if<is_iterator<It>::value>::type read(It st,It en,Ts&&...xs){read(st,en);read(forward<Ts>(xs)...);}
//template<class T>void read(T&x){for(auto&&_i:x)read(_i);}template<class T,class...Ts>void read(T&x,Ts&&...xs){read(x);read(forward<Ts>(xs)...);}
//
//void setInput(FILE*file){*_inputPtr='\0';_input=file;}void setInput(const char*s){*_inputPtr='\0';_input=fopen(s,"r");}void setInput(const string&s){*_inputPtr='\0';_input=fopen(s.c_str(),"r");}
//#define _flush() do{_flushBuf();fflush(_output);}while(0)
//#define _flushBuf() (fwrite(_outputBuffer,1,_outputPtr,_output),_outputPtr=0)
//#define _putchar(x) (_outputBuffer[_outputPtr==_bufferSize?_flushBuf():_outputPtr]=(x),_outputPtr++)
//#define _writeTempBuf(x) (_tempOutputBuf[_tempOutputPtr++]=(x))
//#define _writeOutput() for(int _i=0;_i<_tempOutputPtr;_putchar(_tempOutputBuf[_i++]));_tempOutputPtr=0
//#define _writeNum(x,T,digits) _cnt=0;for(T _y=(x);_y;_y/=10,_cnt++)_numBuf[_numPtr++]='0'+_y%10;for(;_cnt<digits;_cnt++)_numBuf[_numPtr++]='0';_flushNumBuf();
//#define _writeFloatingPoint(x,T) ull _I=(ull)(x);ull _F=((x)-_I)*_precisionBase+(T)(0.5);if(_F>=_precisionBase){_I++;_F=0;}_writeNum(_I,ull,1);_writeTempBuf('.');_writeNum(_F,ull,_precision)
//#define _checkFinite(x) if(std::isnan(x)){wcs("NaN");}else if(std::isinf(x)){wcs("Inf");}
//#define _flushNumBuf() for(;_numPtr;_writeTempBuf(_numBuf[--_numPtr]))
//#define _fillBuf(x) for(int _i=0;_i<(x);_i++)_putchar(_fill)
//#define _flushTempBuf() int _tempLen=_tempOutputPtr;_fillBuf(_width-_tempLen);_writeOutput();_fillBuf(-_width-_tempLen)
//#define wb(x) do{if(x)_writeTempBuf('1');else _writeTempBuf('0');_flushTempBuf();}while(0)
//#define wc(x) do{_writeTempBuf(x); _flushTempBuf();}while(0)
//#define wi(x) do{if((x)<0){_writeTempBuf('-');_writeNum(-(x),uint,1);}else{_writeNum(x,uint,1);}_flushTempBuf();}while(0)
//#define wll(x) do{if((x)<0){_writeTempBuf('-');_writeNum(-(x),ull,1);}else{_writeNum(x,ull,1);}_flushTempBuf();}while(0)
//#define wd(x) do{_checkFinite(x)else if((x)<0){_writeTempBuf('-');_writeFloatingPoint(-(x),double);}else{_writeFloatingPoint(x,double);}_flushTempBuf();}while(0)
//#define wld(x) do{_checkFinite(x)else if((x)<0){_writeTempBuf('-');_writeFloatingPoint(-(x),ld);}else{_writeFloatingPoint(x,ld);}_flushTempBuf();}while(0)
//#define wcs(x) do{int _slen=strlen(x);_fillBuf(_width-_slen);for(const char*_p=(x);*_p;_putchar(*_p++));_fillBuf(-_width-_slen);}while(0)
//#define ws(x) do{_fillBuf(_width-int((x).length()));for(int _i=0;_i<int((x).length());_putchar(x[_i++]));_fillBuf(-_width-int((x).length()));}while(0)
//void setPrecision(int x){_precision=x;_precisionBase=1;for(int _i=0;_i<x;_i++,_precisionBase*=10);}void setWidth(int x){_width=x;}void setFill(char x){_fill=x;}
//void setDelimiter(const char*x){_delimiter=x;}void setDelimiter(const string&x){_delimiter=x.c_str();}
//void writeDelimiter(){for(const char*_p=_delimiter;*_p;_putchar(*_p++));}
//void write(const bool&x){wb(x);}void write(const int&x){wi(x);}void write(const uint&x){wi(x);}void write(const ll&x){wll(x);}void write(const ull&x){wll(x);}
//void write(const double&x){wd(x);}void write(const ld&x){wld(x);}void write(const char&x){wc(x);}void write(const char*x){wcs(x);}void write(const string&x){ws(x);}
//template<class T1,class T2>void write(const pair<T1,T2>&x){write(x.first);writeDelimiter();write(x.second);}
//template<class T>void write(const complex<T>&x){write(x.real());writeDelimiter();write(x.imag());}
//template<class T>void write(const T&x);template<class T,class...Ts>void write(const T&x,Ts&&...xs);
//template<class It>typename enable_if<is_iterator<It>::value>::type write(It st,It en){bool _first=1;for(It _i=st;_i!=en;_i++){if(_first)_first=0;else writeDelimiter();write(*_i);}}
//template<class It,class...Ts>typename enable_if<is_iterator<It>::value>::type write(It st,It en,Ts&&...xs){write(st,en);writeDelimiter();write(forward<Ts>(xs)...);}
//template<class T>void write(const T&x){bool _first=1;for(auto&&_i:x){if(_first)_first=0;else writeDelimiter();write(_i);}}
//template<class T,class...Ts>void write(const T&x,Ts&&...xs){write(x);writeDelimiter();write(forward<Ts>(xs)...);}
//void writeln(){_putchar('\n');}template<class...Ts>void writeln(Ts&&...xs){write(forward<Ts>(xs)...);_putchar('\n');}
//void flush(){_flush();}class IOManager{public:~IOManager(){flush();if(_tempInputBuf)delete[](_tempInputBuf);}};unique_ptr<IOManager>iomanager=make_unique<IOManager>();
//void setOutput(FILE*file){flush();_output=file;}void setOutput(const char*s){flush();_output=fopen(s,"w");}void setOutput(const string&s){flush();_output=fopen(s.c_str(),"w");}
//template<class...Ts>void debug(const Ts&...xs){FILE*_temp=_output;setOutput(_error);write(xs...);setOutput(_temp);}
//template<class...Ts>void debugln(const Ts&...xs){FILE*_temp=_output;setOutput(_error);writeln(xs...);setOutput(_temp);}
//void setError(FILE*file){flush();_error=file;}void setError(const char*s){flush();_error=fopen(s,"w");}void setError(const string&s){flush();_error=fopen(s.c_str(),"w");}
//
//template <const int MAXN, const int MAXLGN, class T> struct RMQSparseTable {
//    T A[MAXN]; int ST[MAXLGN][MAXN];
//    int maxInd(int l, int r) { return A[l] > A[r] ? l : r; }
//    void init(int N) {
//        int lg = 32 - __builtin_clz(N); assert(lg < MAXLGN); iota(ST[0], ST[0] + N, 0);
//        for (int i = 0; i < lg - 1; i++) for (int j = 0; j + (1 << i) < N; j++)
//                ST[i + 1][j] = maxInd(ST[i][j], ST[i][j + (1 << i)]);
//    }
//    int query(int l, int r) { // zero-indexed, inclusive
//        int i = 31 - __builtin_clz(r - l + 1);
//        return maxInd(ST[i][l], ST[i][r - (1 << i) + 1]);
//    }
//};
//
//const int MAXN = 2005, MAXLGN = 14;
//const double EPS = 1e-9;
//
//double X, K, A[MAXN], B[MAXN];
//ll C[MAXN];
//int N, Q;
//RMQSparseTable<MAXN, MAXLGN, ll> ST[MAXN];
//vector<double> important[MAXN];
//
//double f(int i, double x) {
//    return A[i] + x * (B[i] - A[i]) / X;
//}
//
//int main() {
//    // setInput("in.txt");
//    // setOutput("out.txt");
//    // setError("err.txt");
//    cin>>X>>K>>N>>Q;
//    FOR(i, N)cin>>A[i]>>B[i]>>C[i];
//    FOR(i, N) {
//        vector<pair<double, int>> temp;
//        FOR(j, N) if (i != j && ((A[i] < A[j]) ^ (B[i] < B[j]))) temp.eb(X * (A[i] - A[j]) / ((B[j] - A[j]) - (B[i] - A[i])), j);
//        sort(all(temp));
//        ll cur = 0;
//        FOR(j, N) if (i != j && A[i] < A[j]) cur += C[j];
//        ST[i].A[sz(important[i])] = cur;
//        int j = 0;
//        for (int j = 0; j < sz(temp); j++) {
//            important[i].pb(temp[j].f);
//            int k = temp[j].s;
//            if (A[i] < A[k]) cur -= C[k];
//            else cur += C[k];
//            while (j + 1 < sz(temp) && abs(temp[j].f - temp[j + 1].f) <= EPS) {
//                k = temp[++j].s;
//                if (A[i] < A[k]) cur -= C[k];
//                else cur += C[k];
//            }
//            ST[i].A[sz(important[i])] = cur;
//        }
//        ST[i].init(sz(important[i]) + 1);
//    }
//    FOR(i, Q) {
//        int p;
//        double s;
//        cin>>p>>s;
//        p--;
//        writeln(ST[p].A[ST[p].query(upper_bound(all(important[p]), s + EPS) - important[p].begin(), lower_bound(all(important[p]), s + K - EPS) - important[p].begin())]);
//    }
//    return 0;
//}
#pragma region
#include <bits/stdc++.h>
using namespace std;
// Common Type shorteners and int128
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<ll, ll>;
template <typename T> using vec = vector<T>;
template <typename K, typename V> using umap = unordered_map<K, V>; template <typename K> using uset = unordered_set<K>;
using vi = vec<int>; using vl = vec<ll>; using vpi = vec<pii>; using vpl = vec<pll>;
#ifdef __SIZEOF_INT128__
using int128 = __int128_t; using uint128 = __uint128_t;
#endif
template<typename I> string intStr(I x) { string ret; while (x > 0) { ret += (x % 10) + '0'; x /= 10; } reverse(ret.begin(), ret.end()); return ret; } // Int to string
// Shorthand Macros
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define mpr make_pair
#define mtup make_tuple
#define pb push_back
#define popcount __builtin_popcount
#define clz __builtin_clz
#define ctz __builtin_ctz
#define finline __attribute__((always_inline))
// Shorthand Function Macros
#define sz(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (__typeof(a) i = a; i < b; i++)
#define reprev(i, a, b) for (__typeof(a) i = a; i > b; i--)
#define repi(a, b) rep(i, a, b)
#define repj(a, b) rep(j, a, b)
#define repk(a, b) rep(k, a, b)
#define Cmplt(type) bool operator<(const type &o) const
#define Cmpgt(type) bool operator>(const type &o) const
#define Cmpfn(name, type) bool name(const type &a, const type &b)
#define Inop(type) istream& operator>>(istream& in, type &o)
#define Outop(type) ostream& operator<<(ostream& out, type o)
#define Pow2(x) (1LL << (x))
#define scn(type, ...) type __VA_ARGS__; scan(__VA_ARGS__) // scn -> Short for SCan New
// Shorthand Functions
template<typename T> inline void maxa(T& st, T v) { st = max(st, v); }
template<typename T> inline void mina(T& st, T v) { st = min(st, v); }
inline void setprec(ostream& out, int prec) { out << setprecision(prec) << fixed; }
// Out operators and printing for arrays and vectors
template <typename T> ostream& operator<<(ostream& out,vector<T> iter){out<<"[";for(auto t:iter){out<<t<<", ";}out<<"]";return out;}
template <typename T> string arrayStr(T *arr,int sz){string ret = "[";for(int i=0;i<sz;i++){ret+=to_string(arr[i])+", "; } return ret + "]";}
template <typename T> void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}
// I/O Operations
inline void scan(){}
template<typename F, typename... R> inline void scan(F &f,R&... r){cin>>f;scan(r...);}
template <typename F> inline void println(F t){cout<<t<<'\n';}
template<typename F, typename... R> inline void println(F f,R... r){cout<<f<<" ";println(r...);}
inline void print(){}
template<typename F, typename... R> inline void print(F f,R... r){cout<<f;print(r...);}
// Debugging
#define db(x) cout << (#x) << ": " << (x) << ", "
#define dblb(s) cout << "[" << (s) << "] "
#define dba(alias, x) cout << (alias) << ": " << (x) << ", "
template<typename F> inline string __generic_tostring(F f) { stringstream ss; ss << f; return ss.str(); }
template<typename F> inline string __join_comma(F f) {return __generic_tostring(f);}
template<typename F, typename... R> string __join_comma(F f, R... r) { return __generic_tostring(f) + ", " + __join_comma(r...); }
#define dbp(alias, ...) cout << (alias) << ": (" << __join_comma(__VA_ARGS__) << "), "
#define dbbin(x, n) cout << (#x) << ": " << bitset<n>(x) << ", "
#define dbarr(x, n) cout << (#x) << ": " << arrayStr((x), (n)) << ", "
#define dbln cout << endl;
#pragma endregion

struct Eq {
    ld m, b, endy;
    ld inter(Eq &o) {
        return -(o.b - b) / (o.m - m);
    }
};

struct Qu {
    int x, idx;
    Cmplt(Qu) { return x < o.x; }
};

const int MN = 2001, MQ = 800001;
int N, Q, K, X;
vec<pair<ld, int>> inter[MN];
vec<Qu> qus[MN];
ll val[MN], ans[MQ];
Eq eqs[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(X, K, N, Q);
    repi(0, N) {
        int a, b, cost;
        scan(a, b, cost);

        val[i] = cost;
        eqs[i] = {(ld)(b - a) / X, (ld)a, (ld)b};
    }
    repi(0, Q) {
        int idx, st;
        scan(idx, st);
        qus[idx - 1].pb({st, i});
    }
    repi(0, N)
        sort(all(qus[i]));

    // getting intersections and querying
    ld eps = numeric_limits<ld>::epsilon() * 1e5; // EPS
    repi(0, N) {
        // initialize variables and get initial values
        map<ld, ll> tmpInter;
        ll tmpTot = 0;
        repj(0, N)
            if (eqs[j].b > eqs[i].b)
                tmpTot += val[j];
        tmpInter[0] += tmpTot;

        // get intersections
        repj(0, N) {
            if (j == i) continue;
            ld xv = eqs[i].inter(eqs[j]);
            if (xv < 0) continue; // we don't care about these
            ll deltaInter = 0, deltaPost = 0;

            if (eqs[i].endy > eqs[j].endy) { // Originally higher
                if (xv > 0)
                    deltaInter -= val[j];
            }
            else {
                deltaPost += val[j];
            }

            tmpInter[xv] += deltaInter;
            tmpInter[xv + eps] += deltaPost;
        }

        // answering queries

        // init
        deque<int> dq;
        vec<pair<ld, ll>> inter(all(tmpInter));
        int sz = inter.size();
        repj(1, sz)
            inter[j].second += inter[j - 1].second;

        // answer them!!!
        int ptr = 0;
        for (auto &qu : qus[i]) {
            // advance pointer + move sliding window deque forward
            while (ptr < sz && inter[ptr].first <= qu.x + K) {
                while (!dq.empty() && inter[dq.back()].second <= inter[ptr].second)
                    dq.pop_back();
                dq.pb(ptr);
                ptr++;
            }
            auto lb = --tmpInter.upper_bound(qu.x);
            while (!dq.empty() && inter[dq[0]].first < lb->first)
                dq.pop_front();
            // db(qu.x); db(qu.idx); db(lb->first); db(lb->second); dbln;

            // sliding window maximum
            ans[qu.idx] = inter[dq[0]].second;
        }
    }

    // output
    repi(0, Q)
        println(ans[i]);

    return 0;
}