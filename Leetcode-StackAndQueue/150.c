int evalRPN(char** tokens, int tokensSize) {
    long ans[5000];
    int a = -1;
    for(int i = 0; i < tokensSize; i++)
    {
        if((tokens[i][0] != '+') && ((tokens[i][0] != '-') || (tokens[i][1] >= '0')) && (tokens[i][0] != '*') && (tokens[i][0] != '/'))
        {   
            ans[++a] = atoi(tokens[i]);
        }
        else
        {
            long b = 0;
            if(tokens[i][0] == '+')
            b = ans[a-1]+ans[a];
            else if(tokens[i][0] == '-')
            b = ans[a-1]-ans[a];
            else if(tokens[i][0] == '*')
            b = ans[a-1]*ans[a];
            else if(tokens[i][0] == '/')
            b = ans[a-1]/ans[a];
            ans[a-1] = b;
            a--;
        }
    }
    int t = (int)ans[0];
    return t;
}