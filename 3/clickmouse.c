typedef struct QueueNode
{
   	int Front;
    int Rear;
    int size;
    int Array[127];
} *Queue;

int Hash(char letter)
{
	return (letter)%127;
}

void Initialize(Queue q)
{
	q->Front = 0;
	q->Rear = -1;
	q->size = 0;
}

void Enque( Queue q, char letter )
{
	if(q->Rear < 126){
		q->Array[++q->Rear] = letter;
		q->size++;
	}
	else{
		q->Rear = 0;
		q->Array[q->Rear] = letter;
		q->size++; 
	}
}

char Deque( Queue q )
{
	if(q->Front < 126){
		q->size--;
		return q->Array[q->Front++];
	}
	else{
		q->Front = 0;
		q->size--;
		return q->Array[126];
	}
}

int lengthOfLongestSubstring(char* s) {
    int i = 0;
    int pos;
    char back;
    int maxLength = 0;
    int length = 0;
    int mark = 1;
    int alphabet[127] = {0};
    Queue q = (Queue)malloc(sizeof(struct QueueNode));
    Initialize( q );
    while( s[i] != 0 ){
    	Enque( q, s[i] );
    	pos = Hash(s[i]);
    	if(alphabet[pos] != mark){
    		alphabet[pos] = mark;
    		length++;
            if(length > maxLength)
                maxLength = length;
    	}
    	else{
    		if(length > maxLength)
    			maxLength = length;
    		while(1){
    			back = Deque(q);
    			if(back == s[i])
    				break;
    			alphabet[Hash(back)] = 0;
    		}
    		length = q->size;
    	}
    	i++;
    }
    return maxLength;
}
