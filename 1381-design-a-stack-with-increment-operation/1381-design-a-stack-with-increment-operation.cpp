class CustomStack {
public:
    int* a;
    int start;
    int capacity;
    CustomStack(int maxSize) {
        a=new int[maxSize];  //initialise the stack by using pointer
        start=0;
        capacity=maxSize;
    }
    
    void push(int x) {
        if(start<capacity){
            a[start]=x;        //push in the stack
            start++;
        }
    }
    
    int pop() {
        if(start==0){
            return -1;                 //pop in the stack
        }
        start--;
        return a[start];
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,start);i++){     //increment in the stack ny certain value
            a[i]+=val;
        }
    }
};