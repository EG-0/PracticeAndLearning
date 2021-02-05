class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int perimeter = 0;
        int gridC = grid.size();
        
        for (int i = 0; i < gridC; ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                //If square is 1 increase perimeter
                if (grid[i][j] == 1)
                {
                    perimeter += 4;
                    
                    //Checks column
                    if (j < grid[i].size() - 1)
                    {
                        //If adjacent square is 1, reduce perimeter (shared edge)
                        if (grid[i][j+1] == 1)
                            perimeter -= 2;
                    }
                    
                    //Checks row
                    if (i < gridC - 1 )
                    { 
                        //If debajo square is 1, reduce perimeter (shared edge)
                        if (grid[i+1][j] == 1)
                            perimeter -= 2;
                    }
                    
                }
            }
        }
        
        return perimeter;
    }
};
