class Solution {
public:

    bool isVowel(char c)
    {
        if(c=='a' || c=='e' || c=='i'|| c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        {
            return true;
        }
        return false;
    }

    bool halvesAreAlike(string s) {
        int l=s.length();
        int count1=0;
        int count2=0;
        string s1=s.substr(0,l/2);
        string s2=s.substr(l/2);
        for(char c:s1)
        {
            if(isVowel(c))
            {
                count1++;
            }
        }
        for(char c:s2)
        {
            if(isVowel(c))
            {
                count2++;
            }
        }
        if(count1==count2)
        {
            return true;
        }
        else{
            return false;
        }
    }
};