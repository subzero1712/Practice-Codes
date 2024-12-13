/* N-Forest
* * *
* * *
* * * */
void nForest(int n) {
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<"* ";
		}
		cout<<endl;
	}
}
/* N/2-Forest
*
* *
* * * */
void nForest(int n) {
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			cout<<"* ";
		}
		cout<<endl;
	}
}
/* N-Triangles
1
1 2
1 2 3 */
void nTriangle(int n) {
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<j<<" ";
		}
		cout<<endl;
	}
}
/* Triangle
1 
2 2
3 3 3 */
void triangle(int n) {
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			cout<<i<<" ";
		}
		cout<<endl;
	}
}
/* Seeding
* * *
* *
* */
void seeding(int n) {
	for(int i=n;i>0;i--){
		for(int j=i;j>0;j--){
			cout<<"* ";
		}
		cout<<endl;
	}
}
/* Reverse Number Triangle
1 2 3
1 2
1 */
void nNumberTriangle(int n) {
    for(int i=n;i>0;i--){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
/* Star Triangle
  *
 ***
***** */
void nStarTriangle(int n) {
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<2*i+1;j++){
            cout<<"*";
        }
        for(int j=0;j<n-i-1;+j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
/* Reverse Star Triangle
*****
 ***
  * */
void nStarTriangle(int n) {
    for(int i=n-1;i>=0;i--){
      for (int j=0; j<n-i-1; j++) {
        cout << " ";
      }
      for (int j=0; j<2*i+1; j++){
          cout<<"*";
      }
      for(int j=0;j<n-i-1;j++){
          cout<<" ";
      }
      cout<<endl;
    }
}
/* Star Diamond
  *
 ***
*****
*****
 ***
  *
void nStarDiamond(int n) {
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<2*i+1;j++){
            cout<<"*";
        }
        for(int j=0;j<n-i-1;+j++){
            cout<<" ";
        }
        cout<<endl;
    }
    for(int i=n-1;i>=0;i--){
      for (int j=0; j<n-i-1; j++) {
        cout << " ";
      }
      for (int j=0; j<2*i+1; j++){
          cout<<"*";
      }
      for(int j=0;j<n-i-1;j++){
          cout<<" ";
      }
      cout<<endl;
    }
}
/* Rotated Triangle
*
**
***
**
* */
void nStarTriangle(int n) {
   for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			cout<<"*";
		}
        for(int j=i+1;j<n;j++){
            cout<<" ";
        }
		cout<<endl;
	}
    for(int i=n;i>0;i--){
		for(int j=i-1;j>0;j--){
			cout<<"*";
		}
        for(int j=i+1;j<n;j++){
            cout<<" ";
        }
		cout<<endl;
	}
}
/* Binary Number Triangle
1
0 1
1 0 1 */
void nBinaryTriangle(int n) {
    for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
            if((j%2==0 && i%2==0)||(j%2!=0 && i%2!=0)){
                cout<<0<<" ";
            }
            else{
                cout<<1<<" ";
            }
		}
		cout<<endl;
	}
}






