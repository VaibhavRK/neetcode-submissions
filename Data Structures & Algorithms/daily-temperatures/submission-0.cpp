class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> st;
        vector<int> arr(n);
        
        for(int i=n-1;i>=0;i--){
            if(i == n-1){
                st.push(i);
                arr[i] = i;
                continue;
            }

            while(!st.empty() && temp[i] >= temp[st.top()]){
                st.pop();
            }

            if(st.empty()){
                cout<<"yes"<<endl;
                arr[i] = i;
            }
            else arr[i] = st.top();

            st.push(i);

            cout<<temp[i]<<" "<<arr[i]<<" "<<temp[arr[i]]<<endl;
        }

        vector<int> answer(n,-1);

        for(int i=0;i<n;i++){
            answer[i] = arr[i] - i;
        }

        return answer;
    }
};
