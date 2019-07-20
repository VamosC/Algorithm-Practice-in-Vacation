/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    *returnSize = digitsSize;
    int* Array;
    int i;
    int carry = 0;
    int flag = 0;
    int loop = 0;
    if(++digits[digitsSize-1] == 10){
        if(digitsSize == 1)
            flag = 1;
        digits[digitsSize-1] -= 10;
        loop = 1;
        carry = 1;
    }
    if(loop == 1){
        for(i = digitsSize-2; i >= 0; i--){
            digits[i] += carry;
            carry = 0;
            if(digits[i] == 10){
                digits[i] -= 10;
                if(i != 0)
                    carry = 1;
                else
                    flag = 1;
            }
            else
                break;
        }
    }
    if(flag == 1){
        Array = (int*)malloc(sizeof(int)*(digitsSize+1));
        Array[0] = 1;
        for(i = 1; i <= digitsSize; i++)
            Array[i] = digits[i-1];
        *returnSize += 1;
    }
    else{
        Array = (int*)malloc(sizeof(int)*(digitsSize));
        for(i = 0; i < digitsSize; i++)
            Array[i] = digits[i];
    }
    return Array;
}
