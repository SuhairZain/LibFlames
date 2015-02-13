#include <iostream>
#include <stdlib.h>

using namespace std;

namespace LibFlames
{

#define A_a_DIFFERENCE 32

class FlamesStatus
{
public:
    enum Status
    {
        Success,
        PerfectMatch,
        NameEmptyError,
        NoOptionsError
    };
};

class Flames
{
    int occurances[26];
    int resultIndex;

    void strip(string &name)
    {
        for(unsigned int i=0; i<name.length(); ++i)
        {
            if(name[i]>='A' && name[i]<='Z')
            {
                name[i] = name[i] + A_a_DIFFERENCE;
            }
            else if(name[i]<'a' || name[i]>'z')
            {
                for(unsigned int j=i; j<name.length(); ++j)
                    name[j] = name[j+1];
                name.resize(name.length()-1);
                --i;
            }
        }
    }

public:
    int result()
    {
        return resultIndex;
    }

    int calculate(string name1, string name2)
    {
        return calculate(name1, name2, 6);
    }

    int calculate(string name1, string name2, int nOptions)
    {
        if(nOptions<1)
            return FlamesStatus::NoOptionsError;

        strip(name1);
        strip(name2);

        if(name1.length()==0 || name2.length()==0)
            return FlamesStatus::NameEmptyError;

        for(int i=0; i<26; i++)
            occurances[i] = 0;

        for(unsigned int i=0; i<name1.length(); ++i)
            ++occurances[name1[i] - 'a'];

        for(unsigned int i=0; i<name2.length(); ++i)
            --occurances[name2[i] - 'a'];

        int nDifferentChars = 0;
        for(int i=0; i<26; ++i)
            nDifferentChars += abs(occurances[i]);

        if(nDifferentChars==0)
            return FlamesStatus::PerfectMatch;

        int *options = new int[nOptions];
        for(int i=0; i<nOptions; ++i)
            options[i] = i;

        int current = 0;
        for(int i=0; i<nOptions-1; ++i)
        {
            current = (current + nDifferentChars - 1) % (nOptions - i);
            for(int j=current; j<nOptions-i-1; ++j)
                options[j] = options[j+1];
        }
        resultIndex = options[0];
        delete options;

        return FlamesStatus::Success;
    }

};

}

int main()
{
    cout<<"LibFlames by Suhair Zain\n";
    cout<<"To use, create an instance of LibFlames::Flames and call calculate() with the names and use a switch to analyze the results\n";
    cout<<"calculate() returns a status message, stating Success, Perfect Match, Empty Name or Invalid number of options\n";
    cout<<"result() returns the actual result, the index of the option, or -1 in case of an error\n";
    cout<<"@param FirstName, @param SecondName - Convenience function, uses FLAMES(6) by default\n";
    cout<<"@param FirstName, @param SecondName, @param @nOptions - Use this if you want to use a non-default number of options\n";
    cout<<"This example calls calculate() with the names \"Suhair\" and \"Rahul\" whose result is 0, indicating Friend in FLAMES\n";


    LibFlames::Flames flamesChecker;

    //Returns 0, meaning that the calculation was a success and we can proceed to display the results
    cout<<"\n\nCalculation status: ";
    switch(flamesChecker.calculate("Suhair", "Rahul"))
    {
    case LibFlames::FlamesStatus::Success:
        cout<<"Success";
        break;
    case LibFlames::FlamesStatus::PerfectMatch:
        cout<<"It is a perfect match";
        break;
    case LibFlames::FlamesStatus::NameEmptyError:
        cout<<"One or both of the names were empty";
        break;
    case LibFlames::FlamesStatus::NoOptionsError:
        cout<<"There must be at least one possible relation";
        break;
    }

    //The actual result, which is 0, indicating F for Friend in FLAMES
    cout<<"\nThe result is: "<<flamesChecker.result();


    cout<<"\n\nWhen you use this library, simply remove or comment out this main() function";
    return 0;
}
