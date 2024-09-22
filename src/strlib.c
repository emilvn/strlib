
// gets length of a string
int str_length(const char *s)
{
    const char *p = s;
    int len = 0;
    while(*p != '\0'){
        p++;
        len++;
    }
    return len;
}

// returns a char at a specific index in a string as a string
char *str_at(int index, const char *src, char *dest)
{
    const char *psrc = src;
    int i = 0;
    while(*psrc != '\0' && i < index){
        psrc++;
        i++;
    }
    dest[0] = *psrc;
    dest[1] = '\0';
    return dest;
}

// returns the character at a specific index in a string
char str_char_at(int index, const char* s)
{
    const char *p = s;
    int i = 0;
    while(*p != '\0' && i < index){
        p++;
        i++;
    }
    return *p;
}

// concatenates two strings
char *str_concat(const char *src, char *dest)
{
    int dest_len = str_length(dest);
    const char *psrc = src;
    // start from the end of dest
    int i = dest_len;
    while(*psrc != '\0'){
        dest[i] = *psrc;
        psrc++;
        i++;
    }
    dest[i] = '\0';
    return dest;
}

// checks if a string ends with another string
int str_ends_with(const char *src, const char *end)
{
    int src_len = str_length(src);
    int end_len = str_length(end);
    if(src_len < end_len){
        return 0;
    }
    // psrc points to the character in src that is the same distance from the end as the length of end
    const char *psrc = src + src_len - end_len;
    const char *pend = end;
    while(*pend != '\0'){
        if(*psrc != *pend){
            return 0;
        }
        psrc++;
        pend++;
    }
    return 1;
}

// checks if a string includes a substring
int str_includes(const char *src, const char *substr)
{
    const char *psrc = src;
    const char *psubstr = substr;
    while(*psrc != '\0'){
        if(*psrc == *psubstr){
            const char *psrc2 = psrc;
            const char *psub2 = psubstr;
            // iterating through src and substr until we reach the end of substr or we find a mismatch
            while(*psrc2 != '\0' && *psub2 != '\0' && *psrc2 == *psub2){
                psrc2++;
                psub2++;
            }
            // if we reached the end of the substring with this loop, the substring is included in the string
            if(*psub2 == '\0'){
                return 1;
            }
        }
        psrc++;
    }
    return 0;
}

// returns the index of the first occurrence of a substring in a string
int str_index_of(const char *src, const char *substr)
{
    const char *psrc = src;
    const char *psubstr = substr;
    int index = 0;
    while(*psrc != '\0'){
        if(*psrc == *psubstr){
            const char *psrc2 = psrc;
            const char *psub2 = psubstr;
            // iterating through src and substr until we reach the end of substr or we find a mismatch
            while(*psrc2 != '\0' && *psub2 != '\0' && *psrc2 == *psub2){
                psrc2++;
                psub2++;
            }
            // if we reached the end of the substring with this loop, we have the correct index
            if(*psub2 == '\0'){
                return index;
            }
        }
        psrc++;
        index++;
    }
    return -1;
}

// returns the index of the last occurrence of a substring in a string
int str_last_index_of(const char *src, const char *substr)
{
    const char *psrc = src;
    const char *psubstr = substr;
    int index = 0;
    int last_index = -1;
    while(*psrc != '\0'){
        if(*psrc == *psubstr){
            const char *psrc2 = psrc;
            const char *psub2 = psubstr;
            // iterating through src and substr until we reach the end of substr or we find a mismatch
            while(*psrc2 != '\0' && *psub2 != '\0' && *psrc2 == *psub2){
                psrc2++;
                psub2++;
            }
            // if we reached the end of the substring with this loop, we have a correct index, and we update last_index
            if(*psub2 == '\0'){
                last_index = index;
            }
        }
        psrc++;
        index++;
    }
    // if we never found the substring, last_index will still be -1, otherwise it will be the last one found
    return last_index;
}

// compares two strings
int str_locale_compare(const char *s1, const char *s2)
{
    const char *ps1 = s1;
    const char *ps2 = s2;
    while(*ps1 != '\0' && *ps2 != '\0'){
        if(*ps1 < *ps2){
            return -1;
        }else if(*ps1 > *ps2){
            return 1;
        }
        ps1++;
        ps2++;
    }
    if(*ps1 == '\0' && *ps2 == '\0'){
        return 0;
    }else if(*ps1 == '\0'){
        return -1;
    }else{
        return 1;
    }
}

// pads a string with a character to the right
char *str_pad_end(const char *src, int len, char pad, char *dest)
{
    const char *psrc = src;
    int i = 0;
    while(*psrc != '\0'){
        dest[i] = *psrc;
        psrc++;
        i++;
    }
    while(i < len){
        dest[i] = pad;
        i++;
    }
    dest[i] = '\0';
    return dest;
}

// pads a string with a character to the left
char *str_pad_start(const char *src, int len, char pad, char *dest)
{
    int src_len = str_length(src);
    int i = 0;
    while(i < len - src_len){
        dest[i] = pad;
        i++;
    }
    const char *psrc = src;
    while(*psrc != '\0'){
        dest[i] = *psrc;
        psrc++;
        i++;
    }
    dest[i] = '\0';
    return dest;
}

// repeats a string a number of times
char *str_repeat(const char *src, int count, char *dest)
{
    const char *psrc = src;
    int i = 0;
    int j = 0;
    while(j < count){
        const char *psrc2 = psrc;
        while(*psrc2 != '\0'){
            dest[i] = *psrc2;
            psrc2++;
            i++;
        }
        j++;
    }
    dest[i] = '\0';
    return dest;
}

// returns a substring of a string
char *str_slice(const char *src, int start, int end, char *dest)
{
    const char *psrc = src + start;
    int i = 0;
    while(*psrc != '\0' && i < end - start){
        dest[i] = *psrc;
        psrc++;
        i++;
    }
    dest[i] = '\0';
    return dest;
}

// checks if a string starts with another string
int str_starts_with(const char *src, const char *start)
{
    const char *psrc = src;
    const char *pstart = start;
    while(*pstart != '\0'){
        if(*psrc != *pstart){
            return 0;
        }
        psrc++;
        pstart++;
    }
    return 1;
}

// returns a substring of a string
char *str_substring(const char *src, int start, int end, char *dest)
{
    const char *psrc = src + start;
    int i = 0;
    while(*psrc != '\0' && i < end - start){
        dest[i] = *psrc;
        psrc++;
        i++;
    }
    dest[i] = '\0';
    return dest;
}

// converts all characters in a string to lowercase
char *str_to_lower(const char *src, char *dest)
{
    const char *psrc = src;
    int i = 0;
    while(*psrc != '\0'){
        if(*psrc >= 'A' && *psrc <= 'Z'){
            dest[i] = *psrc + 32;
        }else{
            dest[i] = *psrc;
        }
        psrc++;
        i++;
    }
    dest[i] = '\0';
    return dest;
}

// converts all characters to uppercase
char *str_to_upper(const char *src, char *dest)
{
    const char *psrc = src;
    int i = 0;
    while(*psrc != '\0'){
        if(*psrc >= 'a' && *psrc <= 'z'){
            dest[i] = *psrc - 32;
        }else{
            dest[i] = *psrc;
        }
        psrc++;
        i++;
    }
    dest[i] = '\0';
    return dest;
}

// removes trailing whitespace characters
char *str_trim_end(const char *src, char *dest)
{
    const char *psrc = src;
    int i = 0;
    while(*psrc != '\0'){
        dest[i] = *psrc;
        i++;
        psrc++;
    }
    i--;
    // traverse backewards, removing all whitespace characters
    while(i >= 0 && (dest[i] == ' ' || dest[i] == '\t' || dest[i] == '\n' || dest[i] == '\r')){
        i--;
    }
    dest[i + 1] = '\0';
    return dest;
}

// removes leading whitespace characters
char *str_trim_start(const char *src, char *dest)
{
    const char *psrc = src;
    int i = 0;
    // all whitespace characters
    while(*psrc != '\0' && (*psrc == ' ' || *psrc == '\t' || *psrc == '\n' || *psrc == '\r')){
        psrc++;
    }
    while(*psrc != '\0'){
        dest[i] = *psrc;
        i++;
        psrc++;
    }
    dest[i] = '\0';
    return dest;
}

// removes leading and trailing whitespace characters
char *str_trim(const char *src, char *dest)
{
    str_trim_start(src, dest);
    str_trim_end(dest, dest);
    return dest;
}

// made this to print integer value of a string if the string is a number
// cant make it exactly like valueof in js because it needs a specific return type
int str_value_of(const char *src)
{
    const char *psrc = src;
    int value = 0;
    while(*psrc != '\0'){
        if(*psrc >= '0' && *psrc <= '9'){
            value = value * 10 + *psrc - '0';
        }else{
            return 0;
        }
        psrc++;
    }
    return value;
}
