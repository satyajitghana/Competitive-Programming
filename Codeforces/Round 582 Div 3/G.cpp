    #include<bits/stdc++.h>
    using namespace std;
     
    #define int long long
    #define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define cps CLOCKS_PER_SEC
    #define mod (long long)1000000007
    #define f first
    #define s second
    #define debug1(x) cerr<<x<<"\n"
    #define debug2(x,y) cerr<<x<<" "<<y<<"\n"
    #define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
    #define nl cerr<<"\n";
    #define pq priority_queue
    #define inf 0x3f3f3f3f
    #define test cerr<<"abcd\n";
    #define pi pair<int,int>
    #define pii pair<int,pi>
    #define pb push_back
    #define mxn 500005
     
    int id[mxn],sz[mxn];
     
    int curr=0;
     
    void init(int n){
        for(int i=0; i<=n; ++i)
            id[i]=i,sz[i]=1;
    }
     
    int root(int i){
        while(i!=id[i]){
            id[i]=id[id[i]];
            i=id[i];
        }
        return i;
    }
     
    void unn(int p,int q){
        p=root(p);
        q=root(q);
        if(p==q)
            return;
        if(sz[p]<sz[q])
            swap(p,q);
        id[q]=p;
        curr+=1LL*sz[p]*sz[q];
        sz[p]+=sz[q];
        sz[q]=0;
    }
     
    int ans[mxn];
     
    int32_t main(){
    sp;
        int n,q;
        cin>>n>>q;
        init(n);
        vector<pii> v;
        for(int i=1; i<n; ++i){
            int x,y,w;
            cin>>x>>y>>w;
            v.push_back({w,{x,y}});
        }
        vector<pi> v1;
        for(int i=0; i<q; ++i){
            int w;
            cin>>w;
            v1.push_back({w,i});
        }
        sort(v.begin(),v.end());
        sort(v1.begin(),v1.end());
        int i=0;
        for(int j=0; j<q; ++j){
            while(i<v.size()&&v[i].first<=v1[j].first){
                unn(v[i].s.f,v[i].s.s);
                ++i;
            }
            ans[v1[j].second]=curr;
        }
        for(int i=0; i<q; ++i)
            cout<<ans[i]<<" ";
     
        return 0;
    }