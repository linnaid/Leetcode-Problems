class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle)
    : Begin(rectangle)
    {}
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        End.push_back({row1, col1, row2, col2, newValue});
    }
    
    int getValue(int row, int col) {
        for(int i = End.size() - 1; i >= 0; i--) {
            if(End[i][0] <= row && row <= End[i][2] 
               && End[i][1] <= col && col <= End[i][3]) {
                return End[i][4];
            }
        }
        return Begin[row][col];
    }
private:
    vector<vector<int>> Begin;
    vector<vector<int>> End;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */