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
        for(int j=0;j<(2*i+1)/2;j++){
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
  * */
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
/* Number Crown
1         1
1 2     2 1
1 2 3 3 2 1 */
void numberCrown(int n) {
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        for(int j=1;j<=2*(n-1);j++){
            cout<<" ";
        }
        for(int j=i;j>=1;j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
/* Increasing Number Triangle
1
2 3
4 5 6 */
void nNumberTriangle(int n) {
    int count=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<++count<<" ";
        }
        cout<<endl;
    }
}
/* Increasing Letter Triangle
A
A B
A B C */
void nLetterTriangle(int n) {
    
    for(int i=1;i<=n;i++){
        int alpha=char(65);
        for(int j=1;j<=i;j++){
            cout<<char(alpha++)<<" ";
        }
        cout<<endl;
    }
}
/* Reverse Letter Triangle
A B C
A B
A */
void nLetterTriangle(int n) {
    for(int i=n;i>=1;i--){
        int alpha = char(65);
        for(int j=0;j<i;j++){
            cout<<char(alpha++)<<" ";
        }
        cout<<endl;
    }
}
/* Alpha-Ramp
A
B B
C C C */
void alphaRamp(int n) {
    char alpha=65;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            cout<<char(alpha)<<" ";
        }
        ++alpha;
        cout<<endl;
    }
}
/* Alpha Hill
    A
  A B A
A B C B A */
void alphaHill(int n) {
    for(int i=0;i<n;i++){
        
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        char alpha=65;
        int breakpoint=(2*i+1)/2;
        for(int j=1;j<=2*i+1;j++){
            //cout<<alpha<<" ";
            if(j<=breakpoint){
                cout<<alpha++<<" ";
                
            }
            else{
                cout<<alpha--<<" ";
            }
            
        }
        for(int j=0;j<n-i-1;+j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
/* Alpha-Triangle
C
C B 
C B A */
void alphaTriangle(int n) {
    for(int i=1;i<=n;i++){
        char alpha='A';
        for(int j=0;j<i;j++){
            cout<<char(alpha+(n-1))<<" ";
            alpha--;
        }
        cout<<endl;
    }
}
/* Symmetric Void
* * * * * * 
* *     * * 
*         * 
*         * 
* *     * * 
* * * * * * */

void symmetry(int n) {
    // Top part of the pattern
    for (int i = 0; i < n; i++) {
        // Left stars
        for (int j = 0; j < n - i; j++) {
            cout << "*" << " ";
        }
        // Spaces in the middle
        for (int j = 0; j < 2 * i; j++) {
            cout << " ";
        }
        // Right stars
        for (int j = 0; j < n - i; j++) {
            cout << "*" << " ";
        }
        cout << endl;
    }

    // Bottom part of the pattern
    for (int i = n - 1; i >= 0; i--) {
        // Left stars
        for (int j = 0; j < n - i; j++) {
            cout << "*" << " ";
        }
        // Spaces in the middle
        for (int j = 0; j < 2 * i; j++) {
            cout << " ";
        }
        // Right stars
        for (int j = 0; j < n - i; j++) {
            cout << "*" << " ";
        }
        cout << endl;
    }
}
/* Symmetry
*         *
* *     * *
* * * * * *
* *     * *
*         * */
void symmetry(int n) {
     for (int i = n-1; i >= 0; i--) {
        // Left stars
        for (int j = 0; j < n - i; j++) {
            cout << "*" << " ";
        }
        // Spaces in the middle
        for (int j = 0; j < 2 * i; j++) {
            cout << " ";
        }
        // Right stars
        for (int j = 0; j < n - i; j++) {
            cout << "*" << " ";
        }
        cout << endl;
    }

    // Bottom part of the pattern
    for (int i = 0; i < n; i++) {
        // Left stars
        for (int j = 1; j < n - i; j++) {
            cout << "*" << " ";
        }
        // Spaces in the middle
        for (int j = 1; j < 2 * i; j++) {
            cout << " ";
        }
        // Right stars
        for (int j = 1; j < n - i; j++) {
            cout << "*" << " ";
        }
        cout << endl;
    }
}
/* Ninja  And Star Pattern
****
*  *
*  *
**** */
void getStarPattern(int n) {
  for (int i = 0; i < n; i++) {
      for(int j=0;j<n;j++){
          if(i==0||j==0||i==n-1||j==n-1){
              cout<<"*";
          }
          else{
              cout<<" ";
          }
      }
      cout<<endl;
  }
}
/* Ninja And The Number Pattern
4444444
4333334
4322234
4321234
4322234
4333334
4444444 */
void getNumberPattern(int n) {
     for (int i = 0; i < 2 * n - 1; i++) {
        // Inner loop for columns
        for (int j = 0; j < 2 * n - 1; j++) {
            // Determine the minimum distance from the current position to any edge
            int top = i;
            int left = j;
            int bottom = (2 * n - 2) - i;
            int right = (2 * n - 2) - j;
            
            // Calculate the number to print
            int value = n - min(min(top, bottom), min(left, right));
            cout << value;
        }
        // Move to the next row
        cout << endl;
    }
}



