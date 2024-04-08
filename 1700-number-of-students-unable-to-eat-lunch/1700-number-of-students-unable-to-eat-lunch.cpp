class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        queue<int> st;
        for(int i=0; i<students.size(); i++){
            st.push(students[i]);
        }

        int i=0;
        while(i < sandwiches.size()){

            if(st.front() == sandwiches[i]){
                st.pop();
                i++;
                continue;
            }

            int temp = sandwiches[i];
            int count = 0;

            while(st.front() != temp){
                int top = st.front();
                st.pop();
                st.push(top);
                count++;

                if(count >= st.size()) return st.size();
            }
        }

        return st.size();
    }
};