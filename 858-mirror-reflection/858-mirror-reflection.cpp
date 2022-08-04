class Solution {
public:
    
    bool doContinue(int &point, char &drctn, int &p){
        return (drctn == 'l' && point != p ) || (drctn == 'r' && point != 0 && point != p);
    }
    
    void moveAhead(int &p, int &q, int &point, char &drctn, char &sign){
        
        if( sign == '+' ){
            if( (point+q) > p ){
                point = p - (q - (p - point));
                sign = '-';
            }
            else{
                point += q;
                sign = '+';
            }
            drctn = drctn == 'l'? 'r' : 'l';
        }
        else{
            if( point <= q ){
                point = (q - point);
                sign = '+';
            }
            else{
                point -= q;
                sign = '-';
            }
            drctn = drctn == 'l'? 'r' : 'l';
        }
    }
    
    int mirrorReflection(int p, int q) {
        char drctn = 'l', sign = '+';
        int point = 0;
        while( doContinue(point, drctn, p) ){
            moveAhead(p, q, point, drctn, sign);
        }
        if( point == 0 ) return 0;
        if( drctn == 'r' ) return 1;
        return 2;
    }
};