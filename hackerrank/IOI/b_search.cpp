int bin_search(int *arr,int low,int high,int ele) {
	int mid;
	while(low<=high) {
		mid=(low+high)/2;
		if(arr[mid]==ele)
			return mid;
		else if(ele<arr[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}
