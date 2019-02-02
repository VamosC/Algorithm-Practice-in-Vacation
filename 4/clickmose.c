double median(int* nums1, int* nums2, int nums1Size, int nums2Size, int mid, int flag)
{
    int i = 0, j = 0;
    int start = 0;
    if(flag == 1){
        if(nums1Size == 0)
            return (double)nums2[mid];
        else if(nums2Size == 0)
            return (double)nums1[mid];
    }
    else{
        int collect[2];
        if(nums1Size == 0){
            collect[0] = nums2[mid-1];
            collect[1] = nums2[mid];
        }
        else if(nums2Size == 0){
            collect[0] = nums1[mid-1];
            collect[1] = nums1[mid];
        return ((double)(collect[0]+collect[1]))/2;
        }
    }
    int* nums = (int*)malloc(sizeof(int)*(nums1Size+nums2Size));
    while(1){
        while(i < nums1Size){
            if(nums1[i] <= nums2[j])
                nums[start++] = nums1[i++];
            else
                break;
        }
        if(i == nums1Size)
            break;
        while(j < nums2Size){
            if(nums1[i] > nums2[j])
                nums[start++] = nums2[j++];
            else
                break;
        }  
        if(j == nums2Size)
            break;
    }
    while(i < nums1Size)
        nums[start++] = nums1[i++];
    while(j < nums2Size)
        nums[start++] = nums2[j++];
    if(flag == 1)
        return (double)nums[mid];
    else
        return ((double)(nums[mid-1]+nums[mid]))/2;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int sum = nums1Size + nums2Size;
    int mid = sum / 2;
    double midNum;
    if(sum % 2 == 0)
        midNum = median(nums1, nums2, nums1Size, nums2Size, mid, 0); //even
    else
        midNum = median(nums1, nums2, nums1Size, nums2Size, mid, 1); //odd
    return midNum;
}
