bool isAnagram(char* s, char* t) {
        int A[26] = {0};
        int i;
        for(i = 0; s[i] != '\0'; i++)
            A[s[i]-'a']++;
        for(i = 0; t[i] != '\0'; i++)
            A[t[i]-'a']--;
        for(i = 0; i < 26; i++)
            if(A[i] != 0)
                break;
        if(i < 26)
            return false;
        else
            return true;
}
