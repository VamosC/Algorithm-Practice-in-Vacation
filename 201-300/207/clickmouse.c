bool canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int *prerequisitesColSizes) {
    int* Degree = (int*)malloc(sizeof(int)*numCourses);
    int* Mark = (int*)malloc(sizeof(int)*numCourses);
    int i, count = 0;
    int vertice;
    int* Queue = (int*)malloc(sizeof(int)*numCourses);
    int Front = 0;
    int Rear = -1;
    int size = 0;
    if(numCourses == 0)
    	return true;
    for(i = 0; i < numCourses; i++){
    	Mark[i] = 0;
        Degree[i] = 0;
    }
    for(i = 0; i < prerequisitesRowSize; i++)
    	Degree[prerequisites[i][0]]++;
    for(i = 0; i < numCourses; i++)
    	if(Degree[i] == 0)
    		break;
    if(i == numCourses)
    	return false;
    else{
    	Queue[++Rear] = i;
    	size++;
    	Mark[i] = 1;
    }
    while(size != 0){
    	vertice = Queue[Front++];
    	size--;
    	count++;
	    for(i = 0; i < prerequisitesRowSize; i++)
	    	if(prerequisites[i][1] == vertice)
	    		--Degree[prerequisites[i][0]];
	    for(i = 0; i < numCourses; i++)
	    	if(Degree[i] == 0 && Mark[i] == 0){
	    		Queue[++Rear] = i;
    			size++;
    			Mark[i] = 1;
	    	}
	}
	if(count < numCourses)
		return false;
	else
		return true;
}
