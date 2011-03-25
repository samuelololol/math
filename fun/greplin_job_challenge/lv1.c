#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

char blocktext[] = "FourscoreandsevenyearsagoourfaathersbroughtforthonthiscontainentanewnationconceivedinzLibertyanddedicatedtothepropositionthatallmenarecreatedequalNowweareengagedinagreahtcivilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
int len;

// check reverse, node version
int chkrvs(int pos)
{
    if ((pos == 0)||(pos == (len -1)))
        return 0;
    int ext = 1;
    while(blocktext[pos - ext] == blocktext[pos + ext])
    {
        ext++;
        if (((pos - ext) < 0) || ((pos + ext) > (len -1)))
            break;
    }
    return ext-1;
}

// print reverse string, node version
int ptrvs(int pos, int ct)
{
    int i;
    for (i = pos - ct; i < pos+ct+1; i++) {
        printf("%c", blocktext[i]);
    }
    printf("\n");
    return 0;
}

// check reverse, slot version
int chkrvss(int pos)
{
    int ft = pos;
    int rr = pos + 1;
    if ((pos == 0)||(pos == (len -1)))
        return 0;
    int ext = 0;
    while(blocktext[ft - ext] == blocktext[rr + ext])
    {
        ext++;
        if (((ft - ext) < 0) || ((rr + ext) > (len -1)))
            break;
    }
    return ext;
}

// print reverse string, slot version
int ptrvss(int pos, int ct)
{
    int i;
    for (i = pos + 1 - ct; i < pos + ct + 1; i++) {
        printf("%c", blocktext[i]);
    }
    printf("\n");
    return 0;
}

int main(int argc, const char *argv[])
{
    int i,ext,sext;
    int max=0;
    len = strlen(blocktext);

    for (i = 0; i < len; i++) {

        ext = chkrvs(i);
        if ((ext != 0)&&(ext >= max)){
            ptrvs(i,ext);
            max = ext;
        }

        sext = chkrvss(i);
        if ((sext != 0)&&(sext > max)){
            ptrvss(i,sext);
            max = ext;
        }
    }
    return 0;
}
