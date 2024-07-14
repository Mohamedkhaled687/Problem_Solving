class Solution {
private:
    unordered_map<int , Employee> id_to_emp;
public:
    int getImportance(vector<Employee*> employees, int id) {
        for(auto &i : employees){
            id_to_emp[i->id] = *i;
        }

        return dfs(id);
    }

    int dfs(int id){
        auto i = id_to_emp[id];
        int sum = i.importance;

        for(auto &negihbours : i.subordinates){
            sum += dfs(negihbours);
        }
        return sum;
    }

};
