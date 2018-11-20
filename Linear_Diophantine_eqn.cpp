
//Problem: LightOJ 1306

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL ExtendGCD(LL a, LL b, LL &x, LL &y){
	if(a==0){
		x=0; y=1;
		return b;
	}
	LL x1,y1;
	LL gcd = ExtendGCD(b%a,a,x1,y1);
	x=y1-(b/a)*x1;
	y=x1;
	return gcd;
}


bool findAnySoln(LL a, LL b, LL c, LL &x0, LL &y0, LL &g){
	g=ExtendGCD(abs(a),abs(b),x0,y0);
	if(c%g) return false;
	//cout<<x0<<" "<<y0<<" "<<g<<endl;
	x0*=(c/g);
	y0*=(c/g);
	if(a<0) x0=-x0;
	if(b<0) y0=-y0;
	return true;
}

LL shifting(LL sign, LL k, LL flag){
	if(flag)
		return sign>0?++k:--k;
	else
		return sign>0?--k:++k;
}

LL findAllSoln(LL a, LL b, LL c, LL xmin, LL xmax, LL ymin, LL ymax){
	LL x,y,g;
	if(!findAnySoln(a,b,c,x,y,g)) return 0;
	LL sign_a = (a>=0?(+1):(-1));
    LL sign_b = (b>=0?(+1):(-1));

	LL lx,rx,ly,ry;
	LL tempx1,tempx2,tempy1,tempy2;

	lx=((xmin-x)*g)/b;
	tempx1=x+(lx*b)/g;
	if(tempx1<xmin){
		lx=shifting(sign_b,lx,1);
		tempx1=x+(lx*b)/g;
	}
	if(tempx1>xmax) return 0;

	rx=((xmax-x)*g)/b;
	tempx2=x+(rx*b)/g;
	if(tempx2>xmax){
		rx=shifting(sign_b,rx,0);
		tempx2=x+(rx*b)/g;
	}
	if(tempx2<xmin) return 0;

	ly=((y-ymin)*g)/a;
	tempy1=y-(ly*a)/g;
	if(tempy1<ymin){
		ly=shifting(sign_a,ly,0);
		tempy1=y-(ly*a)/g;
	}
	if(tempy1>ymax) return 0;

	ry=((y-ymax)*g)/a;
	tempy2=y-(ry*a)/g;
	//cout<<ry<<" "<<tempy2<<endl;
	if(tempy2>ymax){
		ry=shifting(sign_a,ry,1);
		tempy2=y-(ry*a)/g;
	}
	if(tempy2<ymin) return 0;



	if(lx>rx) swap(lx,rx);
	if(ly>ry) swap(ly,ry);

	if(rx<ly || ry<lx) return 0;

	return min(rx,ry)-max(lx,ly)+1;
}



/*LL shift_soln(LL k, LL flag){
	//cout<<sign<<" "<<k<<" "<<flag<<endl;
	if(flag) return ++k;
	else return --k;
}

LL findAllSoln(LL A, LL B, LL c, LL xmin, LL xmax, LL ymin, LL ymax){
	LL x,y,gcd;
	if(!findAnySoln(A,B,c,x,y,gcd)) return 0;
	LL sign_a = A>=0 ? +1 : -1;
    LL sign_b = B>=0 ? +1 : -1;
 	//cout<<gcd<<" "<<x<<" "<<y<<endl;
    LL xk1=-10e8, xk2=10e8, yk1=-10e8, yk2=10e8;
    double g=gcd, b=B, a=A;
    //determining x1
    xk1 = (xmin-x)*(g/b);
	LL x1 = x+xk1*(b/g);

	if(x1<xmin){
		xk1=sign_b*shift_soln(sign_b*xk1,1);
		x1 = x+xk1*(b/g);	
	}
	if(x1>xmax)
		return 0;
    //cout<<x1<<" "<<xk1<<endl;
	

    //determining x2
	xk2 = (xmax-x)*(g/b);
	LL x2 = x+xk2*(b/g);
	//cout<<x2<<" "<<xk2<<endl;
	
	if(x2>xmax){
		xk2=sign_b*shift_soln(sign_b*xk2,0);
		x2 = x+xk2*(b/g);
	}
	if(x2<xmin)
		return 0;
	//cout<<x2<<" "<<xk2<<endl;
		

	//determining y1
	yk1 = (-1)*(ymin-y)*(g/a);
	LL y1 = y-yk1*(a/g);
	//cout<<y1<<" "<<yk1<<endl;
	

	if(y1<ymin){
		yk1=sign_a*(-1)*shift_soln(sign_a*(-1)*yk1,1);
		y1 = y-yk1*(a/g);
	}
	if(y1>ymax)
		return 0;
	//cout<<y1<<" "<<yk1<<endl;


    //determining y2
	yk2 = (-1)*(ymax-y)*(g/a);	
	LL y2 = y-yk2*(a/g);
	//cout<<y2<<" "<<yk2<<endl;
	
	if(y2>ymax){
		yk2=sign_a*(-1)*shift_soln(sign_a*(-1)*yk2,0);
		y2 = y-yk2*(a/g);
	}
	if(y2<ymin)
		return 0;
	//cout<<y2<<" "<<yk2<<endl;
    
	if(xk1>xk2) swap(xk1,xk2);
	if(yk1>yk2) swap(yk1,yk2);



	//cout<<xk1<<" "<<xk2<<" "<<yk1<<" "<<yk2<<endl;
	if(xk2<yk1 || yk2<xk1) return 0;
	return min(xk2,yk2)-max(xk1,yk1)+1;
}
*/
int  main(){
	LL tcase;
	scanf("%lld",&tcase);
	for(LL t=1;t<=tcase;t++){
		LL a,b,c,x1,x2,y1,y2;
		scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&x1,&x2,&y1,&y2);
		LL ans;
		if(a==0 && b==0){
			if(c==0) ans=(x2-x1+1)*(y2-y1+1);
			else ans=0;
		} else if(a==0){
			LL x,y,g;
			if(!findAnySoln(a,b,(-1)*c,x,y,g)) ans=0;
			else{
				if(y1<=y&&y<=y2) ans=(x2-x1+1);
				else ans=0;
			}
		} else if(b==0){
			LL x,y,g;
			if(!findAnySoln(a,b,(-1)*c,x,y,g)) ans=0;
			else{
				if(x1<=x&&x<=x2) ans=(y2-y1+1);
				else ans=0;
			}
		}
		else
			ans=findAllSoln(a,b,(-1)*c,x1,x2,y1,y2);
		printf("Case %lld: %lld\n",t,ans);
	}
}

//Mejbah VAI's CODE

/*#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

int extended_euclid(int a, int b, LL &x, LL &y) {
  LL xx = y = 0;
  LL yy = x = 1;
  while (b) {
    int q = a / b;
    int t = b; b = a % b; a = t;
    t = xx; xx = x - q * xx; x = t;
    t = yy; yy = y - q * yy; y = t;
  }
  return a;
}

//Find any solution of 
//Ax + By = C

bool find_any_solution(int a, int b, int c, LL &x, LL &y, int &g) {
  g = extended_euclid(abs(a), abs(b), x, y);
  if (c % g != 0) {
    return false;
  }
  x *= c / g;
  y *= c / g;
  if (a < 0) {
    x *= -1;
  }
  if (b < 0) {
    y *= -1;
  }
  return true;
}

void shift_solution(LL &x, LL &y, int a, int b, int k) {
  x += k * 1LL * b;
  y -= k * 1LL * a;
}

LL calculate(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
  c *= -1;
  if (a == 0 && b == 0) {
    if (c == 0) {
      return (maxx - minx + 1LL) * (maxy - miny + 1LL);
    }
    return 0;
  }
  if (a == 0) {
    int z = c / b;
    if (c % b == 0 && z >= miny && z <= maxy) {
      return maxx - minx + 1;
    }
    return 0;
  }
  if (b == 0) {
    int z = c / a;
    if (c % a == 0 && z >= minx && z <= maxx) {
      return maxy - miny + 1;
    }
    return 0;
  }
  LL x, y, x0, y0;
  int g;
  if (!find_any_solution(a, b, c, x, y, g)) {
    return 0;
  }
  x0 = x, y0 = y;
  a /= g;
  b /= g;
  int sign_a = a < 0 ? -1 : 1;
  int sign_b = b < 0 ? -1 : 1;
  int kxl = (minx - x) / b;
  shift_solution(x, y, a, b, kxl);
  if (x < minx) {
    shift_solution(x, y, a, b, sign_b);
    kxl += sign_b;
  }
  if (x > maxx) {
    return 0;
  }
  x = x0, y = y0;
  int kxr = (maxx - x) / b;
  shift_solution(x, y, a, b, kxr);
  if (x > maxx) {
    shift_solution(x, y, a, b, -sign_b);
    kxr -= sign_b;
  }
  x = x0, y = y0;
  int kyl = (y - miny) / a;
  shift_solution(x, y, a, b, kyl);
  if (y < miny) {
    shift_solution(x, y, a, b, -sign_a);
    kyl -= sign_a;
  }
  if (y > maxy) {
    return 0;
  }
  x = x0, y = y0;
  int kyr = (y - maxy) / a;
  shift_solution(x, y, a, b, kyr);
  if (y > maxy) {
    shift_solution(x, y, a, b, sign_a);
    kyr += sign_a;
  }
  if (kxl > kxr) {
    swap(kxl, kxr);
  }
  if (kyl > kyr) {
    swap(kyl, kyr);
  }
  int kl = max(kxl, kyl);
  int kr = min(kxr, kyr);
  return max(0, kr - kl + 1);
}

int main() {
  int T, A, B, C, minx, miny, maxx, maxy;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d%d%d%d%d%d%d", &A, &B, &C, &minx, &maxx, &miny, &maxy);
    printf("Case %d: %lld\n", cn, calculate(A, B, C, minx, maxx, miny, maxy));
  }
}
*/