
int max(int num1, int num2);
int jump(int* arr, int n)
{
    int last=0;
    int flag=0;
    int s=0;
    if(n == 0)
    {
        return 0;
    }
    if( arr[0]== 0)
    {
        return 0;
    }
    for (int i = 0;i< n-1; i++) 
    {
        s = max(s,arr[i]+i);
        if (i == last) 
        {
			flag = flag+1;
			last = s;
        }
	}
    return flag;
}
int max(int num1, int num2)
{
    return (num1 >= num2 ) ? num1 : num2;
}