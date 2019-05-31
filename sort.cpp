
//希尔
void shellSort(int *a, int length)
{
    int i, j;
    int increment = length;
    int insertnum;
    while (increment > 1)
    {
        increment = increment / 3 + 1;
        for (i = increment; i < length; i++)
        {
            insertnum = a[i];
            //插入排序。
            j = i;
            while (j - increment >= 0 && insertnum < a[j - increment])
            {
                a[j] = a[j - increment];
                j = j - increment;
            }
            a[j] = insertnum;
        }
    }
}

//快排
void quickSort(int *a, const int start, const int end)
{
    if (start >= end)
        return;
    int start_point = start;
    int end_point = end;
    int key = a[start];
    while (start_point < end_point)
    {
        while (a[end_point] >= key&& end_point > start_point)
        {
            end_point--;
        }
        while (a[start_point] < key&&end_point>start_point)
        {
            start_point++;
        }
        if (end_point > start_point)
        {
            int temp = a[start_point];
            a[start_point] = a[end_point];
            a[end_point] = temp;
        }
    }
    if (start_point == end_point)
    {
        int temp = a[start_point];
        a[start_point] = a[start];
        a[start] = temp;
    }

    if (start_point)
        quickSort(a, 0, start_point - 1);
    quickSort(a, start_point + 1, end);
}

//二叉查找
int bSearch(int *a, int length, int num)
{
    int left = 0;
    int right = length - 1;
    int middle = -1;
    while (left <= right)
    {
        middle = (right - left) / 2 + left;
        if (num == a[middle])
            return middle;
        else
        {
            if (num > a[middle])
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
    }
    return -1;
}

//冒泡
void bubbleSort(int *a, int length)
{
    for (int i = 0; i < length - 1; i++)
        for (int j = 0; j < length - i - 1; j++)
        {
            //如果前面的数比后面大，进行交换
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
}

//插入
void insertSort(int *a, int length)
{
    if (length <= 1)
        return;
    int temp;
    for (int i = 1; i < length; i++)
    {
        temp = a[i];
        int j = i;
        while (j>0 && a[j - 1] > temp)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
    }
}

//选择
void selectSort(int *a, int length)
{
    for (int i = 0; i < length; i++)
    {
        int key = i;
        for (int j = i + 1; j < length; j++) 
        {
            if (a[j] < a[key]) {
                key = j;
            }
        }
        if (key != i)
        {
            int temp = a[key];
            a[key] = a[i];
            a[i] = temp;
        }
    }
}

//归并
void merge(int *a, int left, int mid, int right)
{
    int length = right - left + 1;
    int *temp = new int[length];
    int k = 0;
    int i = left;
    int j = mid + 1;
    for (int n = 0; n < length; n++)
    {
        if (i <= mid && j <= right)
        {
            if (a[i] <= a[j])
            {
                temp[k++] = a[i];
                i++;
            }
            else
            {
                temp[k++] = a[j];
                j++;
            }
        }
        else if (i <= mid)
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    for (int n = 0; n < length; n++)
    {
        a[left+n] = temp[n];
    }
}

// 递归实现的归并排序
void mergeSort(int *a, int left, int right)
{
    if (left == right)
        return;
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}


//堆排序--构建大根堆
void heapAdjust(int *a, int parent, int length) 
{
    int temp = a[parent];
    int child = 2 * parent + 1;

    while (child < length) {
        if (child + 1 < length && a[child] < a[child + 1]) 
        {
            child++;
        }
        if (temp >= a[child])
            break;
        else
        {
            a[parent] = a[child];
            parent = child;
            child = 2 * child + 1;
        }
    }
    a[parent] = temp;
}

void heapSort(int * a, int length) 
{
    // 循环建立初始堆
    for (int i = length / 2; i >= 0; i--) 
    {
        heapAdjust(a, i, length);
    }

    for (int i = length - 1; i > 0; i--) 
    {
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        heapAdjust(a, 0, i);
    }
}

int main()
{
    int a[9] = { 5, 2, 4, 6, 3, 10, 9, 8, 7 };
    //bubbleSort(a, 9);
    //selectSort(a, 9);
    //insertSort(a, 9);
    //heapSort(a, 9);
    //mergeSort(a, 0, 8);
    //shellSort(a, 9);
    quickSort(a, 0, 8);
    int b[6] = { 1, 3, 5, 7, 8, 10 };
    int key = bSearch(b, 6, 10);
    return 0;
}
