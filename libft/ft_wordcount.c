int ft_wordcount(char const *str, char c){
    int count;
    int i;

    count = 0;
    i = 0;
    while(str[i] != '\0'){
        while(str[i] == c){
            i++;
        }
        if(str[i] != c  && str[i] != '\0'){
            count++;
        }
        while(str[i] != c  && str[i] != '\0'){
            i++;
        }
    }
    return count;
}