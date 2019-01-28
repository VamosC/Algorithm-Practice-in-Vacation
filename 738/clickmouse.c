#define INFINITY 10000
int networkDelayTime(int** times, int timesRowSize, int timesColSize, int N, int K) {
    int* dis = (int*)malloc(sizeof(int)*(N+1));
    int* Known = (int*)malloc(sizeof(int)*(N+1));
    int i, j;
    int max = 0;
    int min_index = -1;
    int min = INFINITY;
    for(i = 1; i <= N; i++){
        Known[i] = 0;
        dis[i] = INFINITY;
    }
    dis[K] = 0;
    while(1){
        for(i = 1; i <= N; i++)
            if(dis[i] < min && Known[i]!=1){
                min_index = i;
                min = dis[i];
            }
        if(min_index == -1)
            break;
        Known[min_index] = 1;
        for(i = 0; i < timesRowSize; i++)
            if(times[i][0] == min_index){
                if(times[i][2]+dis[min_index] < dis[times[i][1]] )
                    dis[times[i][1]] = times[i][2]+dis[min_index];
            }
        min_index = -1;
        min = INFINITY;
    }
    for(i = 1; i<=N; i++)
        if(dis[i]==INFINITY)
            return -1;
        else if(max < dis[i])
            max = dis[i];
    return max;
}
