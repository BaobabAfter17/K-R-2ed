/* reverse: reverse string s in place*/
void reverse(char s[])
{
    int i, j, temp;

    for (i = 0; s[i] != '\0'; i++) /* reach end of s */
        ;
    i--;
    for (j = 0; j < i; i--, j++)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}