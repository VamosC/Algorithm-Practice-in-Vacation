int MaxSum(int* nums, int left, int right)
{
	if(left == right)
		return nums[left];
	int i;
	int leftsum, rightsum;
	int leftBoardSum = 0, rightBoardSum = 0;
	int maxBoardLeft , maxBoardRight;
	int center = (left + right)/2;
	leftsum = MaxSum(nums, left, center);
	rightsum = MaxSum(nums, center+1, right);
	maxBoardLeft = nums[center];
	for(i = center; i >= left; i--){
		leftBoardSum += nums[i];
		if(leftBoardSum > maxBoardLeft)
			maxBoardLeft = leftBoardSum;
	}
	maxBoardRight = nums[center+1];
	for(i = center+1; i <= right; i++){
		rightBoardSum += nums[i];
		if(rightBoardSum > maxBoardRight)
			maxBoardRight = rightBoardSum;
	}
	return max3(leftsum, rightsum, maxBoardLeft+maxBoardRight);
}
int max3(int a, int b, int c)
{
	if(a > b){
		if(a > c)
			return a;
		else 
			return c;
	}
	else{
		if(b > c)
			return b;
		else
			return c;
	}
}
int maxSubArray(int* nums, int numsSize) {
    return MaxSum(nums, 0, numsSize-1);
}
