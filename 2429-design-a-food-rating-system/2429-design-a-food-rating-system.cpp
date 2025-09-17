class FoodRatings {
    unordered_map<string,string>foods;
    unordered_map<string,int>cuisines;
    map<string,set<pair<int,string>>>ratings;;
public:
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        for(int i=0;i<f.size();i++){
            string food=f[i];
            string cuisine=c[i];
            int rating=r[i];
            this->foods[food]=cuisine;
            this->cuisines[food]=rating;
            this->ratings[cuisine].insert({-rating,food});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine=foods[food];
        int oldRating=cuisines[food];
        ratings[cuisine].erase({-oldRating,food});
        ratings[cuisine].insert({-newRating,food});
        cuisines[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        return ratings[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */