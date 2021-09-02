int isPalindrome(string S)
{   
    string S1=S;
    reverse(S.begin(),S.end());
    if(S==S1)return 1;
    else return 0;
}