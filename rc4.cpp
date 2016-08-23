#include<stdio.h>
#include<string.h>

/*initialization*/
void rc4_init(unsigned char*s, unsigned char*key, unsigned long Len)
{
    int i = 0, j = 0;
    char k[256] = { 0 };
    unsigned char tmp = 0;
    for (i = 0; i<256; i++)
    {
        s[i] = i;
        k[i] = key[i%Len];
    }
    for (i = 0; i<256; i++)
    {
        j = (j + s[i] + k[i]) % 256;
        tmp = s[i];
        s[i] = s[j];//switch s[i] and s[j]
        s[j] = tmp;
    }
}


void rc4_crypt(unsigned char*s, unsigned char*Data, unsigned long Len)
{
    int i = 0, j = 0, t = 0;
    unsigned long k = 0;
    unsigned char tmp;
    for (k = 0; k<Len; k++)
    {
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;
        tmp = s[i];
        s[i] = s[j];//switch s[i] and s[j]
        s[j] = tmp;
        t = (s[i] + s[j]) % 256;
        Data[k] ^= s[t];
    }
}

int main()
{
    unsigned char s[256] = { 0 }, s2[256] = { 0 };//S-box
    char key[256] = { "justfortest" };
    char pData[512] = "this is a Data for encrypt";
    unsigned long len = strlen(pData);
    int i;

    printf("pData=%s\n", pData);
    printf("key=%s,length=%d\n\n", key, strlen(key));

    rc4_init(s, (unsigned char*)key, strlen(key));//initialization done

    printf("the S-box is:\n");
    for (i = 0; i<256; i++)
    {
        printf("%02X", s[i]);
        if (i && (i + 1) % 32 == 0)  printf("\n"); //putchar('\n');
    }
    printf("\n");

    for (i = 0; i<256; i++)//let s2[i] the same as s[i]
    {
        s2[i] = s[i];
    }
    printf("encryption:\n");
    rc4_crypt(s, (unsigned char*)pData, len);
    printf("pData=%s\n", pData);

    printf("decryption:\n");
    rc4_crypt(s2, (unsigned char*)pData, len);
    printf("pData=%s\n", pData);
    return 0;
}



