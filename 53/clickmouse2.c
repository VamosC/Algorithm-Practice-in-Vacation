int maxSubArray(int* nums, int numsSize) {
    int i;
    int sum = 0;
    int max = nums[0];
    if(numsSize == 1)
    	return nums[0];
    for(i = 0; i < numsSize; i++){
    	if(nums[i] > max)
    		max = nums[i];
    	sum += nums[i];
    	if(sum < 0)
    		sum	= 0;
    	else if(sum > max)
    		max = sum;
    }
    return max;
}
