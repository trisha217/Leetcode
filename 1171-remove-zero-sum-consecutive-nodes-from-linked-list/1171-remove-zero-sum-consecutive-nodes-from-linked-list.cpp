//https://hyper-meta.blogspot.com/
auto _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
typedef ListNode* v_type;
typedef int k_type;
#define SIGNED_KEY 1
class Hash{
    static const size_t N=3691;
    k_type keys[N]={0};
    v_type values[N];
    const char v_def=0;
public:
    Hash(){
        memset(values,v_def,sizeof(values));
    }
    void clear(){
        memset(values,v_def,sizeof(values));
    }
    v_type& operator[](int key){
        #if SIGNED_KEY
        int t=key%N,idx=t+(t<0)*N,cnt=1;
        #else
        int idx=key%N,cnt=1;
        #endif
        while(keys[idx]!=key && values[idx]!=nullptr){
            idx=(idx+cnt*cnt)%N;
            cnt++;
        }
        keys[idx]=key;
        return values[idx];
    }
};
Hash m;
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        m.clear();
        auto l=head;
        int s=0;
        m[0]=head;
        while(l){
            s+=l->val;
            l=l->next;
            m[s]=l;
        }
        if(s==0) return 0;
        s=0;
        l=head=m[0];
        while(l){
            s+=l->val;
            auto nxt=m[s];
            if(nxt!=l) l->next=nxt;
            l=l->next;
        }
        return head;
    }
};