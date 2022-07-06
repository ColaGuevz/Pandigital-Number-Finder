#include <iostream>

using namespace std;

int findPandigital(int i);

int main()
{
    int lowerBound;
    int upperBound;
    int pandigitalCtr;

    cout<<"Enter the lower limit: ";
    cin>>lowerBound;

    cout<<"Enter the upper limit: ";
    cin>>upperBound;

    for(int index = lowerBound; index <= upperBound; index++)
    {
        if(findPandigital(index) != 0)
        {
            pandigitalCtr++;
        }
    }

    cout<<"\nThere are "<<pandigitalCtr<<" pandigital number from "<<lowerBound<<" to "<<upperBound<<'.'<<endl;
}

int findPandigital(int i)
{
    int temp, ctr, s, pandigitalCtr;
    ctr = 0, pandigitalCtr = 0;

    if(i > 10)
    {
        int num = i;
        temp = i;

        while (temp != 0)
        {
            temp /= 10;
            ctr++;
        }

        s = ctr;
        int arrayOfDigits[ctr];

        while(i != 0)
        {
            arrayOfDigits[--ctr] = i % 10;
            i /= 10;
        }

        int tempo;
        for(int k = 0; k < s; k++)
        {
            for(int j = k + 1 ; j < s; j++)
            {
                if ( arrayOfDigits[k] > arrayOfDigits[j])
                {
                    tempo  = arrayOfDigits[k];
                    arrayOfDigits[k] = arrayOfDigits[j];
                    arrayOfDigits[j] = tempo;
                }
            }
        }

        for (int index = 0; index < s; index++)
        {
            for (int i = index + 1; i < s; i++)
            {
                if (arrayOfDigits[ctr++] - arrayOfDigits[ctr] == 1)
                {
                    pandigitalCtr++;
                }
            }
        }


        if(pandigitalCtr == s)
        {
            return pandigitalCtr;
        }
    }
}
