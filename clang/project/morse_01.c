#include <stdio.h>

#define DASH = '-'
#define DOT = '.'

/**
* -----------------------------
* 
* @ author : Tay Oh
* @ date : 29th April 2023
* @ description : A project allowing the user to do send morse code
*                 and recieve it and translate it.
* 
* ------------------------------
*
* function list:
* - main : allows the user to select the main choices
* - translate_letter: translates given morse code to a letter
*/


struct MorseLetter{
    int morseNum;
    char morseArr[6];
};

int len(char* str);
int copyStr(char* pre, char* post);
int input( char* msg, char* source, int size);
int inputMorse(struct MorseLetter *morse);
int translate_1mtot(struct MorseLetter *morse, struct MorseLetter *alphabet);

int main(){

    // A
    struct MorseLetter a;
    a.morseNum = 2;
    copyStr(".-", a.morseArr);

    // B
    struct MorseLetter b;
    b.morseNum = 4;
    copyStr("-...", b.morseArr);

    // C
    struct MorseLetter c;
    c.morseNum = 4;
    copyStr("-.-.", c.morseArr);

    // D
    struct MorseLetter d;
    d.morseNum = 3;
    copyStr("-..", d.morseArr);

    // E
    struct MorseLetter e;
    e.morseNum = 1;
    copyStr(".", e.morseArr);

    // F
    struct MorseLetter f;
    f.morseNum = 4;
    copyStr("..-.", f.morseArr);

    // G
    struct MorseLetter g;
    g.morseNum = 3;
    copyStr(".-", g.morseArr);

    // H
    struct MorseLetter h;
    h.morseNum = 4;
    copyStr("....", h.morseArr);

    // I
    struct MorseLetter i;
    i.morseNum = 2;
    copyStr("..", i.morseArr);

    // J
    struct MorseLetter j;
    j.morseNum = 4;
    copyStr(".---", j.morseArr);

    // K
    struct MorseLetter k;
    k.morseNum = 3;
    copyStr("-.-", k.morseArr);

    // L
    struct MorseLetter l;
    l.morseNum = 4;
    copyStr(".-..", l.morseArr);

    // M
    struct MorseLetter m;
    m.morseNum = 2;
    copyStr("--", m.morseArr);

    // N
    struct MorseLetter n;
    n.morseNum = 2;
    copyStr("-.", n.morseArr);

    // O
    struct MorseLetter o;
    o.morseNum = 3;
    copyStr("---", o.morseArr);

    // P
    struct MorseLetter p;
    p.morseNum = 4;
    copyStr(".--.", p.morseArr);

    // Q
    struct MorseLetter q;
    q.morseNum = 4;
    copyStr("--.-", q.morseArr);

    // R
    struct MorseLetter r;
    r.morseNum = 3;
    copyStr(".-.", r.morseArr);

    // S
    struct MorseLetter s;
    s.morseNum = 3;
    copyStr("...", s.morseArr);

    // T
    struct MorseLetter t;
    t.morseNum = 1;
    copyStr("-", t.morseArr);

    // U
    struct MorseLetter u;
    u.morseNum = 3;
    copyStr("..-", u.morseArr);

    // V
    struct MorseLetter v;
    v.morseNum = 4;
    copyStr("...-", v.morseArr);

    // W
    struct MorseLetter w;
    w.morseNum = 3;
    copyStr(".--", w.morseArr);

    // X
    struct MorseLetter x;
    x.morseNum = 4;
    copyStr("-..-", x.morseArr);

    // Y
    struct MorseLetter y;
    y.morseNum = 4;
    copyStr("-.--", y.morseArr);

    // Z
    struct MorseLetter z;
    z.morseNum = 4;
    copyStr("--..", z.morseArr);

    struct MorseLetter alphabet[26] = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};

    return 0;
}

int input( char* msg, char* source, int size){
    char ch;
    char buffer[size];

    int idx = 0;

    printf( "%s", msg );

    while(idx < size-1 & (ch = getchar()) != '\n'){
        buffer[idx++] = ch;
    }

    buffer[idx] = '\0';

    for(int jdx = 0; jdx < idx+1; jdx++){
        *(source + jdx) = buffer[jdx];
    }

    return 0;
}

int len(char* str){
    int length = 0;
    while( (*str) !='\0'){
        length++;
        str++;
    }

    return length+1;
}

int copyStr(char* pre, char* post){
    for(int pos = 0; pos < len(pre); pos++){
        post[pos] = pre[pos];
    }
    return 1;
}

int inputMorse(struct MorseLetter *morse){
    input("letter: [", morse->morseArr, 5);
    printf("]");

    morse->morseNum = len(morse->morseArr);

    return 1;    
}

int translate_1mtot(struct MorseLetter *morse, struct MorseLetter *alphabet){
    for(int pos = 0; pos < 26; pos++){
        if( len((alphabet[pos]).morseArr) != len(morse->morseArr)){
            break;
        }
        int flag = 1;
        for(int mpos = 0; mpos< (morse->morseNum); mpos++){


            if(morse->morseArr[mpos] != alphabet[pos].morseArr[mpos])
        }
    }

}