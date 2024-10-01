#include <iostream>
#include <bitset>
#define SIZE 10

using namespace std;

int CalculatePower(int num, int power)
{
    int product = num;
    for (int i = 0; i < power-1; i++)
    {
         product *= num;
    }
    return product;
}

int SumDiapazone(int d1, int d2)
{
    int sum = 0;
    if (d1 > d2) {
        for (int i = d2; i < d1; i++)
        {
            sum += i;
        }
    }
    else {
        for (int i = d1; i < d2; i++)
        {
            sum += i;
        }
    }
    return sum;
}
void FindDNum(int d1, int d2)
{
    int sum = 0;
    if (d1 > d2) {
        for (int i = d2; i < d1; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (i % j == 0) {
                    sum += j;
                }
            }
            if (sum == i) {
                cout << i << " is perfect number" << endl;
            }
            sum = 0;
        }
    }
    else {
        for (int i = d1; i < d2; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (i % j == 0) {
                    sum += j;
                }
            }
            if (sum == i) {
                cout << i << " is perfect number" << endl;
            }
            sum = 0;
        }
    }
}
void ShowSuit(int num)
{
    char heart = '\u2665';
    char diamond = '\u2666';
    char club = '\u2663';    
    char spade = '\u2660';  
    if (num == 1)
    {
        cout << spade << endl;
    }
    else if (num == 2)
    {
        cout << club << endl;
    }
    else if (num == 3)
    {
        cout << heart << endl;
    }
    else if (num == 4)
    {
        cout << diamond << endl;
    }
    else {
        cout << "There are not that choice" << endl;
    }
}

int isHappyNum(float num)
{
    int num2;
    for (int num_1 = 0; num_1 <= 9; num_1++)
    {
        for (int num_2 = 0; num_2 <= 9; num_2++)
        {
            for (int num_3 = 0; num_3 <= 9; num_3++)
            {
                for (int num_4 = 0; num_4 <= 9; num_4++)
                {
                    for (int num_5 = 0; num_5 <= 9; num_5++)
                    {
                        for (int num_6 = 0; num_6 <= 9; num_6++)
                        {
                            num2 = num_1 * 100000 + num_2 * 10000 + num_3 * 1000 + num_4 * 100 + num_5 * 10 + num_6;
                            if (num == num2) {
                                if (num_1 == num_6 && num_2 == num_5 && num_3 == num_4)
                                {
                                    return true;
                                }
                                else {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
void FindPositionInArr(int key, int arr[SIZE])
{
    bool isFind = false;
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] == key) {
            cout << "Your num is on " << i << " position in array"<<endl;
            isFind = true;
        }
    }
    if (isFind == false) {
        cout << "There are not num like your in this array"<<endl;
    }

}
void FindBinInArr(int num, bitset<8> arr[SIZE])
{
    bool isFind = false;
    bitset<8> key = num;
    bitset<8> binary_num = bitset<8>(num);
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] == bitset<8>(num))
        {
            cout << "Your num is on " << i << " position in array" << endl;
            isFind = true;
        }
    }
    if (isFind == false) {
        cout << "There are not num like your in this array" << endl;
    }
}

int TransformBinIntoNum(bitset<8> bin)
{
    int num = static_cast<int>(bin.to_ulong());
    return num;
}


int main()
{
    srand(time(NULL));
    int arr[SIZE] = { 12,31,432,123,43,12,41,9,3,19 };
    bitset<8> binaryArr[SIZE];
    int num = 0;
    cout<<CalculatePower(15, 2)<<endl;
    cout << SumDiapazone(1, 5) << endl;
    FindDNum(6, 12);
    
    cout << "Chose:\n1)Spades\n2)Clubs\n3)Hearts\n4)Diamonds\n";
    cin >> num;
    ShowSuit(num);
    cout << "Enter num -> ";
    cin >> num;
    if (isHappyNum(num) == true) {
        cout << "This num is happy" << endl;
    }
    else {
        cout << "This num isn`t happy"<<endl;
    }
    cout << "Enter num -> ";
    cin >> num;
    FindPositionInArr(num, arr);
    for (int i = 0; i < SIZE; i++)
    {
        num = rand() % 10;
        binaryArr[i] = bitset<8>(num);
    }
    FindBinInArr(num,binaryArr);
    bitset<8> bin_num;
    cout << "Enter your bin --> ";
    cin >> bin_num;
    cout << TransformBinIntoNum(bin_num);
}