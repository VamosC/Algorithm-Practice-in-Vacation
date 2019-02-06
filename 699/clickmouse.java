class KthLargest {
	private int k;
	private int[] nums;
    public KthLargest(int k, int[] nums) {
    	nums = Heap(k, nums);
    	this.k = k;
    	this.nums = nums;
    }
    
    private int[] Heap(int k, int[] nums) {
		int i;
		if(nums.length < k){
			int[] newNums = new int[k];
			System.arraycopy(nums,0,newNums,0,nums.length);
			for(i = nums.length; i < k; i++)
				newNums[i] = -1000;
			nums = newNums;
            
		}
		for(i = k/2-1; i >= 0; i--)
			PercolateDown(nums, i, k);
		for(i = k; i < nums.length; i++)
			if(nums[i] <= nums[0])
				continue;
			else{
				nums[0] = nums[i];
				PercolateDown(nums, 0, k);
			}
        return nums;
	}

    private void PercolateDown( int[]nums, int i, int N ){
    	int X = nums[i];
    	int child;
    	for(;2*i+1 <= N-1; i = child){
    		child = 2*i+1;
    		if(child != N-1 && nums[child+1] < nums[child])
    			child++;
    		if(nums[child] < X)
    			nums[i] = nums[child];
    		else
    			break;
    	}
    	nums[i] = X;
    }
    
    public int add(int val) {
        if(val > nums[0]){
        	nums[0] = val;
        	PercolateDown(nums, 0, k);
        }
        return nums[0];
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
