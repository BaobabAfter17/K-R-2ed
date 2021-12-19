/* reverse: reverse string s inplace, recursively */
void reverse(char s[])
{
    void reverser(char s[], int i, int j);

    reverser(s, 0, strlen(s));
}

void reverser(char s[], int i, int len)
{
    int j, c;

    j = len - i - 1;
    if (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverser(s, ++i, len);
    }
}