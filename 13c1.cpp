#include<iostream>
#include<cstring>
#include<vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long LL;

vector<int> get_nums(string str) {
    vector<int> v;
    bool flag = false;
    string temp="",temp1="";
    for(int i=0;i<str.size();i++){
        if(isdigit(str[i])){
            if(flag){
                temp1+=str[i];
            }else{
                temp+=str[i];
            }

        }else if(str[i] == ',' ){
            if(flag){
                for(int j = stoi(temp);j <= stoi(temp1);j++){
                    v.push_back(j);
                }
                flag = false;
            }else{
                v.push_back(stoi(temp));
            }
            temp = "";temp1="";
        }else if(str[i]=='-'){
            flag = true;
        }
    }

    if(temp != ""){
        if(temp1 !="" ){
            for(int j = stoi(temp);j <= stoi(temp1);j++){
                v.push_back(j);
            }
        }else{
            v.push_back(stoi(temp));
        }
    }

    return v;
}



struct Edge {
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
            from(from), to(to), cap(cap), flow(flow), index(index) {}
};
struct PushRelabel {
    int N;
    vector<vector<Edge> > G;
    vector<LL> excess;
    vector<int> dist, active, count;
    queue<int> Q;
    PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2 * N) {}
    void AddEdge(int from, int to, int cap) {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }
    void Enqueue(int v) {
        if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); }
    }
    void Push(Edge &e) {
        int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
        if (dist[e.from] <= dist[e.to] || amt == 0) return;
        e.flow += amt;
        G[e.to][e.index].flow -= amt;
        excess[e.to] += amt;
        excess[e.from] -= amt;
        Enqueue(e.to);
    }
    void Gap(int k) {
        for (int v = 0; v < N; v++) {
            if (dist[v] < k) continue;
            count[dist[v]]--;
            dist[v] = max(dist[v], N + 1);
            count[dist[v]]++;
            Enqueue(v);
        }
    }
    void Relabel(int v) {
        count[dist[v]]--;
        dist[v] = 2 * N;
        for (int i = 0; i < G[v].size(); i++)
            if (G[v][i].cap - G[v][i].flow > 0)
                dist[v] = min(dist[v], dist[G[v][i].to] + 1);
        count[dist[v]]++;
        Enqueue(v);
    }
    void Discharge(int v) {
        for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
        if (excess[v] > 0) {
            if (count[dist[v]] == 1)
                Gap(dist[v]);
            else
                Relabel(v);
        }
    }
    LL GetMaxFlow(int s, int t) {
        count[0] = N - 1;
        count[N] = 1;
        dist[s] = N;
        active[s] = active[t] = true;
        for (int i = 0; i < G[s].size(); i++) {
            excess[s] += G[s][i].cap;
            Push(G[s][i]);
        }
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            active[v] = false;
            Discharge(v);
        }
        LL totflow = 0;
        for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
        return totflow;
    }
};



int main()
{
    int t=0;
    cin>>t;
    for(int i1=1;i1<=t;i1++)
    {
        cout << "Case #" << i1 << ": ";

        int jobs,prin,n;
        cin>>prin>>jobs;
        n=prin+jobs;
        PushRelabel G(n+2);
        string jo;
        for(int i=1;i<=prin;i++)
        {
            cin>>jo;
            if(prin>=jobs){
                vector<int> nums = get_nums(jo);
                for(int j : nums){
                    G.AddEdge(i,prin+j,1);
                }
            }

        }

        if(jobs>prin)
        {
            cout<<"no \n";
            continue;
        }
        else
        {
            for(int i=1;i<=prin;i++)
            {
                G.AddEdge(0,i,1);

            }

            for(int i=prin+1;i<=n;i++)
            {
                G.AddEdge(i,n+1,1);
            }


            n=n+1;
            int max1;
            max1= G.GetMaxFlow(0,n);
            if(max1==jobs)
            {
                cout<<"yes \n";
            }
            else
            {
                cout<<"no \n";
            }
        }

    }

    return 0;
}
