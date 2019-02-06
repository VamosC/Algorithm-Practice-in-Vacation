void PerCoLateDown(char* s, int i, int N){
    char X = s[i];
    int child;
    for(;2*i+1 <= N-1; i = child){
    	child = 2*i+1;
        if(child != N-1 && s[child+1] > s[child])
            child++;
        if(s[child] > X) 
            s[i] = s[child];
        else break;
    }
    s[i] = X;
}
void Sort( char* s ){
    int i;
    int N;
    for(i = 0; s[i] != '\0'; i++);
    N = i;
    for(i = N/2-1; i >= 0; i--)
        PerCoLateDown(s, i, N);
    for(i = N-1; i >= 0 ; i--){
        int temp = s[i];
        s[i] = s[0];
        s[0] = temp;
        PerCoLateDown(s, 0, i);
    }
}
bool isAnagram(char* s, char* t) {
    Sort(s);
    Sort(t);
    if(strcmp(s, t) == 0)
        return true;
    else
        return false;
}
