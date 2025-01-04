
bool judgeCircle(string moves) {
    int x = 0, y = 0;
    for(auto c: moves){
        if(c == 'U') y += 1;
        if(c == 'D') y -= 1;
        if(c == 'L') x -= 1;
        if(c == 'R') x += 1;
    }
    
    return (x == 0) && (y == 0);
}