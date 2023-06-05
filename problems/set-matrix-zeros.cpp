class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        int col0 = 1;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (j == 0)
                        col0 = 0;
                    else
                    {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        for (int i = 1; i < r; i++)
        {
            for (int j = 1; j < c; j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
        for (int j = 0; j < c; j++)
        {
            if (matrix[0][0] == 0)
                matrix[0][j] = 0;
        }
        for (int i = 0; i < r; i++)
        {
            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};