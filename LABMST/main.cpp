class Solution
{
public:
    vector<int> maxOfSubarrays(vector<int> &arr, int k)
    {
        int maximum = arr[0];
        vector<int> result;

        for (int i = 0; i < k; i++)
        {
            if (arr[i] > maximum)
            {
                maximum = arr[i];
            }
        }

        result.push_back(maximum);

        for (int i = k; i < arr.size(); i++)
        {
            if (maximum == arr[i - k])
            {
                maximum = arr[i - k + 1];

                for (int j = i - k + 1; j <= i; j++)
                {
                    if (arr[j] > maximum)
                    {
                        maximum = arr[j];
                    }
                }
            }
            else if (arr[i] > maximum)
            {
                maximum = arr[i];
            }

            result.push_back(maximum);
        }

        return result;
    }
};