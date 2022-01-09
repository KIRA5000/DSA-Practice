#include <iostream>
#include <vector>
#include <map>

bool doesWordExist(std::string word, int index, std::pair<int, int> prev, std::map<char, std::vector<std::pair<int, int>>> hash, std::vector<std::vector<bool>> visited, std::vector<std::vector<char>>& board)
{
    if (index == word.size())
    {
        return true;
    }

    if (hash.find(word[index]) == hash.end())
    {
        return false;
    }
    else
    {
        for (int i = 0; i < hash[word[index]].size(); i++)
        {
            auto cord = hash[word[index]][i];

            if ((((prev.first == -1) && (prev.second == -1)) || ((std::abs(cord.first - prev.first) <= 1) && (std::abs(cord.second - prev.second) <= 1))) && (visited[cord.first][cord.second] == false))
            {
                visited[cord.first][cord.second] = true;

                bool check = doesWordExist(word, index + 1, cord, hash, visited, board);

                if (!check)
                {
                    visited[cord.first][cord.second] = false;
                }
                else
                {
                    return true;
                }
            }
        }

        return false;
    }
}

int boggleWords(std::vector<std::string> words, std::vector<std::vector<char>>& board)
{
    int count = 0;
    std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));
    std::map<char, std::vector<std::pair<int, int>>> hash;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            hash[board[i][j]].push_back({i, j});
        }
    }

    for (int i = 0; i < words.size(); i++)
    {
        if (doesWordExist(words[i], 0, {-1, -1}, hash, visited, board));
        {
            count++;
        }
    }

    return count;
}

int main()
{
    std::vector<std::string> words = {"GEEKS","FOR","QUIZ","GO"};
    std::vector<std::vector<char>> board = {{'G', 'I', 'Z'}, {'U', 'E', 'K'}, {'Q', 'S', 'E'}};

    std::cout << "Number of words possible: " << boggleWords(words, board) << std::endl;
    return 0;
}