#ifdef REFERENCE
#include "solution.hpp"
#else
#include "starter.hpp"
#endif
#include "../../tests/check.hpp"
int main(){
try {
Graph g{{{1,5},{2,1}}, {}, {{1,1}}, {}};auto d=shortest_costs(g,0);CHECK(d[0]==0&&d[1]==2&&d[2]==1&&d[3]==std::numeric_limits<std::int64_t>::max());
CHECK(shortest_costs(Graph{{{0,0}}},0)[0]==0);THROWS(shortest_costs(Graph{{{0,-1}}},0),std::invalid_argument);THROWS(shortest_costs(g,9),std::invalid_argument);
THROWS(shortest_costs(Graph{{},{{3,1}}},0),std::invalid_argument);Graph h{{{1,1000000}},{{2,1000000}}, {}};CHECK(shortest_costs(h,0)[2]==2000000);
// Compare with Floyd-Warshall on deterministic dense graphs.
for(int n=1;n<=8;++n) {
    Graph graph(static_cast<std::size_t>(n));
    const std::int64_t inf=1000000000;
    std::vector<std::vector<std::int64_t>> expected(n,std::vector<std::int64_t>(n,inf));
    for(int u=0;u<n;++u) {
        expected[u][u]=0;
        for(int v=0;v<n;++v) if(u!=v && (u*7+v*3)%4!=0) {
            int weight=(u*11+v*5)%9;
            graph[u].push_back({v,weight});expected[u][v]=weight;
        }
    }
    for(int via=0;via<n;++via)for(int u=0;u<n;++u)for(int v=0;v<n;++v)
        expected[u][v]=std::min(expected[u][v],expected[u][via]+expected[via][v]);
    for(int source=0;source<n;++source) {
        auto actual=shortest_costs(graph,source);
        for(int v=0;v<n;++v)CHECK(actual[v]==(expected[source][v]>=inf?std::numeric_limits<std::int64_t>::max():expected[source][v]));
    }
}
return finish();
} catch(const std::exception& e){std::cerr << "Uncaught exception: " << e.what() << '\n';return 1;}
}
