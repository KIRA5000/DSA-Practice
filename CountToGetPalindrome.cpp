int findMin(string str, int i, int j)
{
    if (i > j)
    {
        return INT_MAX;
    }
    if (i == j)
    {
        return 0;
    }
    if (i == j - 1)
    {
        if (str[i] == str[j])
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    
    return ((str[i] == str[j]) ? findMin(str, i + 1, j - 1) : min(findMin(str, i + 1, j), findMin(str, i, j - 1)) + 1);
}

int countMin(string str)
{
    auto ret = findMin(str, 0, str.size() - 1);
    
    return ((ret == INT_MAX) ? -1 : ret);
}