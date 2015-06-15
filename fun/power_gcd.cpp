ll power(ll x,ll y) {
	ll temp;
	if(y==0)
		return 1;
	temp=power(x, y/2);
	if (y%2 == 0)
		return temp*temp;
	else
		return x*temp*temp;
}
ll gcd(ll a, ll b) {
  while (b != 0)  {
    ll t = b;
    b = a % b;
    a = t;
  }
  return a;
}
pair<int,pair<int,int> > egcd(ll a, ll b) {
	if(a==0) return make_pair(b,make_pair(0,1));
	else {
		pair<int,pair<int,int> > temp;
		temp=egcd(b%a,a);
		ll g=temp.first;
		ll y=temp.second.first;
		ll x=temo.second.second;
		return g,x-(b/a)*y,y;
	}
}
ll modinv(a,m) {
	temp=egcd(b%a,a);
	ll g=temp.first;
	ll y=temp.second.first;
	ll x=temo.second.second;
	if(g!=1) return null;
	else return x%m;
}