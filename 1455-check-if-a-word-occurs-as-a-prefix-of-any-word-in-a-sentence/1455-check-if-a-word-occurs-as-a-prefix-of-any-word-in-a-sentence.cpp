class Solution {
public:
    int isPrefixOfWord(string sentence, string search) {
        int count=0;
	
     if(sentence.substr(0,search.length())==search)
         return 1;

    for(int i=0;i<sentence.length();i++)
    {
        if(sentence[i]==' ' )
        {
            count++;
            if(sentence.substr(i+1,search.length())==search)
            {
                return count+1;
            }
        }
    }
    
    return -1;
    }
};