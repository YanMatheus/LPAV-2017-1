/*Selection sort will sort the vectors in ascending order*/
void selSort(vector<int>& v)
{
        int temp, min;

        for( int i = 0; i < v.size(); i++){
                min = i;
                for (int j = 1; j < v.size(); j++){
                        if (v[j] < v[min])
                        min = j;
                }
                temp = v[i];
                v[i] = v[min];
                v[min] = temp;
        }
}//end selection sort