double average(int *nums, int size){
	if(!size)
		return 0;
	int sum, i;
	for(i = 0, sum = 0; i < size; i++){
		sum+=nums[i];
	}
	return (double)sum / size;
}