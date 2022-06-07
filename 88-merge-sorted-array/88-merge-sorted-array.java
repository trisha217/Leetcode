class Solution {
    public void merge(int[] arr1, int m, int[] arr2, int n)
    {
        int i,j,k;
        if(m!=0 && n!=0)
        {
            for (i = 0; i < m; i++)
            {
                if (arr1[i] > arr2[0]) {
                    int temp = arr1[i];
                    arr1[i] = arr2[0];
                    arr2[0] = temp;
                }
                Arrays.sort(arr2);
            }
            for(j=m, i=0;j<m+n && i<n;j++){
                arr1[j] = arr2[i];
                i++;            
            }
        }
        else
        {
            for(j=0,i=0;j<n;j++,i++){
                arr1[i]=arr2[j];
            }
        }
    }
}