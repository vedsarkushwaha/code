    #include<cstdio>
    #include<set>
    using namespace std;
    typedef long long i64;
    int main()
    {
    int kk=2;
   	int jj=0;
    i64 N,x[2001],y[2001],i,j,x1,y1,x2,y2,x3,y3,x4,y4,min;
    set<pair<i64,i64> > M;
    set<pair<i64,i64> >::iterator flag1,flag2;
    for(scanf("%lld",&N),i=1;i<=N;++i)
    {
    scanf("%lld%lld",&x[i],&y[i]);
    M.insert(make_pair(2*x[i],2*y[i]));
    }
    if(N==0)
    printf("4");
    else if(N==1)
    printf("3");
    else if(N==2)
    printf("2");
    else
    {
    kk=2;
   	jj=0;
    for(i=1;i<N;++i)
    {
    for(j=i+1;j<=N;++j)
    {
    x1=2*x[i];y1=2*y[i];
    x2=2*x[j];y2=2*y[j];
    x3=(x1+x2-y1+y2)/2;
    y3=(y1+y2+x1-x2)/2;
    x4=(x1+x2+y1-y2)/2;
    y4=(y1+y2-x1+x2)/2;
    flag1=M.find(make_pair(x3,y3));
    flag2=M.find(make_pair(x4,y4));
    /*if(flag1!=M.end()&&flag2!=M.end())
    {
    printf("0");
    return 0;
    }
    else if(flag1!=M.end()||flag2!=M.end())
    {
    //min=min<1?min:1;
    min=1;
    }
    else
    {
    min=min<2?min:2;
    }
    }
    }
    printf("%lld",min);
    }*/
    if(flag1!=M.end()) {
    	kk=1;
    	jj=1;
    }
    if(flag2!=M.end()) {
    	if(jj==1) {
    		printf("0");
    		return 0;
    	}
    	kk=1;jj=0;
    }
    }
    }
    }
    printf("%d",kk);
    return 0;
    }
