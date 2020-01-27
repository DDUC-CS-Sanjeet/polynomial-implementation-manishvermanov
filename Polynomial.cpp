#include<iostream>
using namespace std;

class Polynomial
{
	private:
    // Variables to store information about polynomial
    
	int * array;
	int degree;
    
  public:
    Polynomial()
    {
      // Behavior of default constructor
      array=new int [10];
    }

    Polynomial(int deg)
    {
      // Behavior of constructor with arguments
      degree=deg;
      array=new int [degree+1];
      
    }
  
    ~Polynomial()
    {
      // Behavior of destructor
      delete [] array;
    }
  
    //  Overload copy constructor, +, - and = operators
    
    
  Polynomial operator + (Polynomial p)
    {
    	Polynomial temp;
    	
		if(degree>p.degree)
    	{
    		temp.degree=degree;
    		temp.array=new int [temp.degree+1];
    		
    		int diff,j;
    		
    	
			diff=degree-p.degree;
    		
    		for(j=0;j<diff;j++)
    		{
    			temp.array[j]=array[j];
			}
    		
    		for(int i=diff,q=0;i<degree+1;i++,q++)
    		{
    			temp.array[i]=array[i]+p.array[q];
			}	
		}
		else
		{
			temp.degree=p.degree;
    		temp.array=new int [temp.degree+1];
    		
    		int diff,j;
			diff=p.degree-degree;
				
			for(j=0;j<diff;j++)
    		{
    			temp.array[j]=p.array[j];
			}
			for(int i=diff,q=0;i<p.degree+1;i++,q++)
    		{
    			temp.array[i]=array[q]+p.array[i];
			}
		}
		return temp;
	}
  
  Polynomial operator - (Polynomial p)
    {
    	Polynomial temp;
    	
		if(degree>p.degree)
    	{
    		temp.degree=degree;
    		temp.array=new int [temp.degree+1];
    		
    		int diff,j;
    		
    	
			diff=degree-p.degree;
    		
    		for(j=0;j<diff;j++)
    		{
    			temp.array[j]=array[j];
			}
    		
    		for(int i=diff,q=0;i<degree+1;i++,q++)
    		{
    			temp.array[i]=array[i]-p.array[q];
			}	
		}
		else
		{
			temp.degree=p.degree;
    		temp.array=new int [temp.degree+1];
    		
    		int diff,j;
			diff=p.degree-degree;
				
			for(j=0;j<diff;j++)
    		{
    			temp.array[j]=p.array[j];
			}
			for(int i=diff,q=0;i<p.degree+1;i++,q++)
    		{
    			temp.array[i]=array[q]-p.array[i];
			}
		}
		return temp;
	}
  void operator = (Polynomial cpy )
  {
  	degree=cpy.degree;
  	array=new int [cpy.degree+1];
  	
  for(int i=cpy.degree;i>=0;i--)
		{
			array[i]=cpy.array[i];
		}
  }
  
 Polynomial(const Polynomial & cpy)
  {
  	degree=cpy.degree;
  	array=new int[degree+1];
  		
	  for(int i=cpy.degree;i>=0;i--)
  	{
  		array[i]=cpy.array[i];
	}
  }
    void storePolynomial()
    { 
      //  Code to enter and store polynomial
      for(int i=0;i<degree+1;i++)
      {
      	cout<<"Enter coefficient of x^("<<degree-i<<")  : ";
      	cin>>array[i];
      	cout<"\n";
	  }
    }
    void display()
    {
      //  Code to print the polynomial in readable format
       
	   for(int i=0;i<degree;i++)
      {
      	cout<<array[i]<<"x^("<<degree-i<<") + " ;
	  }
	  cout<<array[degree];
    } 
};

int main()
{
  int degFirst, degSecond;
  // Ask user to input the values of degFirst and degSecond 
  
  cout<<"Enter the degree of the first polynomial : ";
  cin>>degFirst;
  
  cout<<"Enter the degree of the second polynomial : ";
  cin>>degSecond;
  
  Polynomial firstPolynomial(degFirst);
  Polynomial secondPolynomial(degSecond);
  Polynomial thirdPolynomial;
  
  cout<<"\nFIRST POLYNOMIAL    \n\n";
  firstPolynomial.storePolynomial();
  
  cout<<"\nSECOND POLYNOMIAL    \n\n";
  secondPolynomial.storePolynomial();
  
 	thirdPolynomial=firstPolynomial+secondPolynomial;
  Polynomial fourthPolynomial=firstPolynomial-secondPolynomial;
  
  cout<<"\n\nFirst polynomial is : ";
  firstPolynomial.display();
  cout<<"\n\nSecond polynomial is : ";
  secondPolynomial.display();
 
 cout<<"\n\nPolynomial after addition : ";
  thirdPolynomial.display();
  cout<<"\n\nPolynomial after subtraction : ";
  fourthPolynomial.display();
}


