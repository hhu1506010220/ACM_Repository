#include <cstdio>
using namespace std;
 
const int SIZE=26;
 
char A[]="QAZWSXEDCRFVTGBYHNUJMIKOLP";
char B[]="QWERTYUIOPASDFGHJKLZXCVBNM";
char C[]="QETUOADGJLZCBMWRYIPSFHKXVN";
char R[]="ZYXWVUTSRQPONMLKJIHGFEDCBA";
 
char key[7],txt[6669],*AA,*BB,*CC;
int pa,pb,pc,ppa,ppb,ppc;
 
void reset()
{
    if (key[0]=='A')
    {
        AA=A;
    }
    else if (key[0]=='B')
    {
        AA=B;
    }
    else
    {
        AA=C;
    }
     
    if (key[1]=='A')
    {
        BB=A;
    }
    else if (key[1]=='B')
    {
        BB=B;
    }
    else
    {
        BB=C;
    }
     
    if (key[2]=='A')
    {
        CC=A;
    }
    else if (key[2]=='B')
    {
        CC=B;
    }
    else
    {
        CC=C;
    }
     
    for (pa=0;pa<SIZE;++pa)
    {
        if (AA[pa]==key[3])
        {
            break;
        }
    }
    for (pb=0;pb<SIZE;++pb)
    {
        if (BB[pb]==key[4])
        {
            break;
        }
    }
    for (pc=0;pc<SIZE;++pc)
    {
        if (CC[pc]==key[5])
        {
            break;
        }
    }
    ppa=pa;
    ppb=pb;
    ppc=pc;
    return;
}
 
char work(char ch)
{
    ch=AA[(pa+ch-'A')%SIZE];
    ch=BB[(pb+ch-'A')%SIZE];
    ch=CC[(pc+ch-'A')%SIZE];
    ch=R[ch-'A'];
     
    for (int i=0;i<SIZE;i++)
    {
        if (ch==CC[i])
        {
            ch='A'+i-pc;
            if (ch<'A')
            {
                ch+=SIZE;
            }
            break;
        }
    }
    for (int i=0;i<SIZE;i++)
    {
        if (ch==BB[i])
        {
            ch='A'+i-pb;
            if (ch<'A')
            {
                ch+=SIZE;
            }
            break;
        }
    }
    for (int i=0;i<SIZE;i++)
    {
        if (ch==AA[i])
        {
            ch='A'+i-pa;
            if (ch<'A')
            {
                ch+=SIZE;
            }
            break;
        }
    }
    ++pa;
    pa%=SIZE;
    if (pa==ppa)
    {
        ++pb;
        pb%=SIZE;
        if (pb==ppb)
        {
            ++pc;
            pc%=SIZE;
        }
    }
    return ch;
}
 
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%s",&key);
        scanf("%s",&txt);
        reset();
        for (int i=0;txt[i]!=0;++i)
        {
            txt[i]=work(txt[i]);
        }
        printf("%s\n",txt);
    }
    return 0;
}