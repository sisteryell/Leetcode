class Solution {
    int cross(const vector<int>& o,const vector<int>& a,const vector<int>& b){
        return (a[0]-o[0])*(b[1]-o[1])-(a[1]-o[1])*(b[0]-o[0]);
    }
    double area(vector<int>& a, vector<int>& b, vector<int>& c){
        return abs(a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1]))/2.0;
    }
    vector<vector<int>> convexHull(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const vector<int>& a, const vector<int>& b){
            return a[0]<b[0] or (a[0]==b[0] && a[1]<b[1]);
        });
        vector<vector<int>>hull;
        for(const auto& p:points){
            while(hull.size()>=2 and cross(hull[hull.size()-2],hull[hull.size()-1],p)<=0){
                hull.pop_back();
            }
            hull.push_back(p);
        }
        int lowerSize=hull.size();
        for(int i=points.size()-2;i>=0;i--){
            while(hull.size()>lowerSize and cross(hull[hull.size()-2],hull[hull.size()-1],points[i])<=0){
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }
        hull.pop_back();
        return hull;
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        vector<vector<int>> hull = convexHull(points);
        double maxArea=0;
        int n=hull.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    maxArea=max(maxArea,area(hull[i],hull[j],hull[k]));
                }
            }
        }
        return maxArea;
    }
};