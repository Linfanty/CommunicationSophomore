

[a, b];

//int maxn = inf



bool check(int x)
{
    if(  )
        return true;
    else return false;
}

int low = a;
int high = b;
while( low <= high )
{
    int mid = (low+high) >> 1;
    if( check(mid) )
    {
        low = mid + 1;
        ans = mid;
    }
    else high = mid - 1;
}
