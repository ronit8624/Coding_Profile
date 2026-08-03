class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);

        int n = boxTypes.size();
        int maxUnits = 0;

        for(int i = 0; i < n; i++) {
            int noOfBoxes = boxTypes[i][0];
            int noOfUnits = boxTypes[i][1];

            if(noOfBoxes > truckSize) {
                int units = truckSize;
                int amount = units * noOfUnits;
                maxUnits += amount;
                truckSize -= units;
                break;
            }

            truckSize -= noOfBoxes;
            int amount = noOfBoxes * noOfUnits;
            maxUnits += amount;

            if(truckSize == 0)
                break;
        }

        return maxUnits;
    }
};