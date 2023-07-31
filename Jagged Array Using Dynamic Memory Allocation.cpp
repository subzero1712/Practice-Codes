

using namespace std;

int main()
{
    int row;
    int col;
    cout<<"enter row and column"<<endl;
    cin>>row>>col;
    int c[col];
    //here we  are making variable column size
    cout<<"enter column array "<<endl;;
     for(int i=0;i<col;i++){
         cin>>c[i];
     }
  

  int ** a=new int *[row];
  
  for(int i=0;i<row;i++){
      //means ith row mn ith column size jayega jaisa humne input diya hoga
         a[i]=new int [c[i]];
     }
     cout<<"enter array element "<<endl;
  for(int i=0;i<row;i++){
          for(int j=0;j<c[i];j++){
         cin>>a[i][j];
     }
    
     }
     cout<<"output"<<endl;
      for(int i=0;i<row;i++){
          for(int j=0;j<c[i];j++){
         cout<<a[i][j]<<" ";
     }
     cout<<endl;
      }
     
     

    return 0;
}
