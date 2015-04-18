// Create vertical histogram of word lengths
#include <stdio.h>
#define MWN 100
int main()
{
    int c;
    int hh, hl, nc;                                 // histogram hight, length and letter counter
    int i, j;
    int word[MWN];
    
    hl = 0;
    hh = 0;
    nc = 0;
    
    for (i = 0; i < MWN; ++i)                       // initialize array to 0
        word[i]=0;
                                            
                                                    // this part adds values to array
    while ((c=getchar()) != EOF){
        ++nc;
        if (c == ' ' || c == '\n' || c == '\t'){
            nc = nc - 1;
            word[nc]= word[nc] + 1;                 // adds +1 to array(letter number of the word -blank space)
            if (word[nc] > hh){
                hh = word[nc];                      // determens height of histogram
            }
            if (nc > hl){                           // determines length of histogram
                hl = nc + 1;
            }
            nc=0;                                   // resets counter for next word
        }
    }
    
    printf("\n\n");                 
    
    
                                                    // this part prints the histogram
    for (i = hh; i >= 1; --i){                      // go from highest value in array to 1
        printf("%3d |", i);                         // prints vertical part of histogram
        for (j = 1; j < hl; ++j){
            if (i <= word[j])                       // if the value in array is equal or bigger than
                printf(" X ");                      // 'i' - print X
            else                                    // else print blank characters
                printf("   ");
        }
        
        putchar('\n');
            
    }                                               // this part prints horizontal border of the histagram
    printf("    +");
    for (i=1;i<=hl-1; ++i)
        printf("---");
    putchar('\n');
    printf("    ");
    for (i=1; i<=hl-1; ++i)
        printf("%3d",i);
}
