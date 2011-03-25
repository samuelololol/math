#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
char blocktext[] = "FourscoreandsevenyearsagoourfaathersbroughtforthonthiscontainentanewnationconceivedinzLibertyanddedicatedtothepropositionthatallmenarecreatedequalNowweareengagedinagreahtcivilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";

int pstr(char* str,int end, int start)
{
    char* tmp = (char *)malloc(strlen(str)+1);
    bzero(tmp,strlen(str)+1);
    strncpy(tmp, str+start, end-start);
    tmp[end-start+1]='\0';
    printf("%s\n",tmp);
    free(tmp);
}

// return longest postion of the same char
int findmts(char* str){
    if (strlen(str) <= 1)
        return 0;
    int target_p = -1;
    int i;
    for (i = strlen(str) -1 ; i > 0; i--){
        if (str[i] == str[0]){
            target_p = i;
            break;
        }
    }
    return target_p;
}

int findrvs(char* str){
    int len_str = strlen(str);
    if (len_str <= 1){
        return 0;
    }
    int i,result;
    char* tmpsub = (char *)malloc(len_str+1);
    bzero(tmpsub,strlen(str)+1);
    int mts = findmts(str);
    if (mts == (len_str - 1)){
        strncpy(tmpsub, str+1, mts - 1);
        tmpsub[mts-1] = '\0';
        result = findrvs(tmpsub);
    }
    else{
        result = -1;
    }
    free(tmpsub);
    return result;
}

int search_pattern(char* str, int* end)
{
    int len_str = strlen(str);
    if (len_str <= 1){
        return 0;
    }
    int result, check;
    int mts = findmts(str);
    if (mts == -1)
        return -1;

    char* tmpsub;
    while(mts > 1)
    {
        tmpsub = (char *)malloc(len_str+1);
        bzero(tmpsub,len_str+1);
        strncpy(tmpsub, str, mts+1);
        tmpsub[mts+1] = '\0';

        result = findrvs(tmpsub);

        // not reverse-string
        // prepare next
        if (result == -1){
            tmpsub[mts-2] = '\0';
            mts = findmts(tmpsub);
            len_str = strlen(tmpsub);
            free(tmpsub);
            continue;
        }
        else if (result == 0){
                free(tmpsub);
                *end = mts;
                // nice reverse-string
                return 0;
        }
    }
    return -1;
}
int main(int argc, const char *argv[])
{
    int i,mts;
    int end=0;
    int max=0;
    int tmp=0;
    for (i = 0; i < strlen(blocktext) - 2; i++){
        if(search_pattern(blocktext+i,&end) == 0){
            if (end > max){
                printf("%c",blocktext[i]);
                pstr(blocktext+i+1,end,0);
                tmp = end;
            }
            else
                tmp = max;
            max = tmp;
        }
    }
    return 0;
}
