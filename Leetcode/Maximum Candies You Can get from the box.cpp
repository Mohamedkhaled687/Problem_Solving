// link : https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/description/


// Code

class Solution {
    int result = 0;
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int nodes = status.size();
            queue<int> q;
            vector<bool> visited(nodes , false);
            vector<bool> suspended_key(nodes ,false);
             vector<bool> suspended_box(nodes ,false);


        for(int i = 0 ; i < initialBoxes.size() ; i++){
                int cur_box = initialBoxes[i];
                if(status[cur_box]){
                    result += candies[cur_box];
                    visited[cur_box] = true;
                    q.push(cur_box);
                }
                else
                    suspended_box[cur_box] = true;
            }

            for(int level = 0 , sz = q.size(); !q.empty() ; sz = q.size() , level++){
                while(sz--){
                    int cur = q.front();
                    q.pop();
                    auto contained_boxes = containedBoxes[cur];
                    auto keys_boxes = keys[cur];

                    for(int i = 0 ; i < keys_boxes.size() ; i++){
                        int key = keys_boxes[i];
                        suspended_key[key] = true;
                        if(suspended_box[key] && suspended_key[key]){
                              if(!visited[key]){
                                result += candies[key];
                                q.push(key);
                                visited[key] = true;
                            }
                        }
                    }

                    for(int i = 0 ; i < contained_boxes.size() ; i++){
                        int neighbour_box = contained_boxes[i];

                        if(!status[neighbour_box])
                            suspended_box[neighbour_box] = true;

                        if(status[neighbour_box] || suspended_box[neighbour_box] && suspended_key[neighbour_box]){
                            if(!visited[neighbour_box]){
                                result += candies[neighbour_box];
                                q.push(neighbour_box);
                                visited[neighbour_box] = true;
                            }
                        }
                    }
                }
            }

            return result;
    }
};
