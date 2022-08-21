#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void remove_vogais(char * s, int * v);
int LerString(char * str);
int a;
int main()
{
    char s[256];
    int v[5];
    v[0] = v[1] = v[2] = v[3] = v[4] = 0;
    a = LerString(s);
    remove_vogais(s, v);
    return 0;
}

int LerString(char * str)
{
    char c;
    int i = 0;
    while (1)
    {
        scanf("%c", &c);
        if (c!='\n') 
        {
            str[i] = c;
            i++;
        }
        else
        {
            break;
        }
    }
    return i;
}
void remove_vogais(char * s, int * v)
{
    int i = 0;
    for (i = 0; i < a; i++)
    {
        if (s[i] == 65 || s[i] == 97)
        {
            v[0] = v[0]+1;
        }
        else
        {
            if (s[i] == 69 || s[i] == 101)
            {
                v[1] = v[1]+1;
            }
            else
            {
                if (s[i] == 73 || s[i] == 105)
                {
                    v[2] = v[2]+1;
                }
                else
                {
                    if (s[i] == 79 || s[i] == 111)
                    {
                        v[3] = v[3]+1;
                    }
                    else
                    {
                        if (s[i] == 85 || s[i] == 117)
                        {
                            v[4] = v[4]+1;
                        }
                        else
                        {
                            if (s[i] != '\n')
                            {
                                printf("%c", s[i]);
                            }
                        }
                    }
                }
            }
        }
    }
    printf("\na: %d\n", v[0]);
    printf("e: %d\n", v[1]);
    printf("i: %d\n", v[2]);
    printf("o: %d\n", v[3]);
    printf("u: %d\n", v[4]);
}