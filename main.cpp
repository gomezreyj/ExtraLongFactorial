
#include <iostream>
#include <vector>

using namespace std;

vector<int> readNums(int n)
{
    int remainder = n % 10;
    int quotient = n;

    vector<int> num;

    while ( quotient > 0)
    {
       remainder = quotient % 10;
       num.push_back(remainder);
       quotient = quotient / 10;
    }
    //num.push_back(remainder);

    return num;
}

vector<int> resultMult(vector<int> num1, vector<int> num2)
{

    int indexNum2 = 0;
    int multCarryon = 0;
    int multRes = 0;
    int addCarryon = 0;
    int remainder = 0;
    int updateResult = 0;
    int updateIndex = 0;

    vector<int> result(num1.size() + num2.size(),0);

    while ( indexNum2 < num2.size())
    {
        multCarryon = 0;

        int indexNum1 = 0;
        updateIndex = indexNum2; 

        while ( indexNum1 < num1.size() )
        {
            multRes = num2[indexNum2] * num1[indexNum1] + multCarryon;
            
            if ( multRes >= 10 )
            {
                remainder = multRes % 10;
                multCarryon = multRes / 10;

                   updateResult = result[updateIndex] + remainder + addCarryon;
                   if ( updateResult >= 10 )
                   {
                     result[updateIndex] = updateResult % 10;
                     addCarryon = updateResult / 10;
                   }
                   else
                   {
                     result[updateIndex] = updateResult;
                     addCarryon = 0;
                   }
                   updateIndex++;   
            }
            else  // multRes < 10
            {
               
                   updateResult = result[updateIndex] + multRes + addCarryon;
                   if ( updateResult >= 10 )
                   {
                     result[updateIndex] = updateResult % 10;
                     addCarryon = updateResult / 10;
                   }
                   else
                   {
                     result[updateIndex] = updateResult;
                     addCarryon = 0;
                   }
                   updateIndex++;
                
                multCarryon = 0;
            }

            indexNum1++;

        } // inner while
        // if ( multCarryon > 0)
        //    result.push_back(multCarryon);

        indexNum2++;
    }

    return result;
}




int main()
{
    vector<int> num1, num2, num3, num4, result;

    result = readNums(1);
    
    int factorialOf = 45;

    for ( factorialOf > 1; factorialOf--; )
    {
        result = resultMult(result,readNums(factorialOf));
    }
    int cont = result.size() - 1;

    while ( result[cont] == 0)
          cont--;

    cout << "Factorial of : " <<  factorialOf << endl;
         
    while ( cont >= 0 )
      cout << result[cont--];
    
    cout << endl;


    // int a = 100;
    // int b = 100;
    // int c = 98;
    // int d = 97;

    // num1 = readNums(a);
    // num2 = readNums(b);
    // num3 = readNums(c);
    // num4 = readNums(d);

    // result = resultMult(num1,num2);

    // result = resultMult(result,num3);

    // result = resultMult(result,num4);

    // int cont = result.size() - 1;
    

    // while ( result[cont] == 0)
    //       cont--;

    // while ( cont >= 0 )
    //   cout << result[cont--];
    



    // int indexNum2 = 0;
    // int multCarryon = 0;
    // int multRes = 0;
    // int addCarryon = 0;
    // int remainder = 0;
    // int updateResult = 0;
    // int updateIndex = 0;

    // while ( indexNum2 < num2.size())
    // {
    //     multCarryon = 0;

    //     int indexNum1 = 0;
    //     updateIndex = indexNum2; 

    //     while ( indexNum1 < num1.size() )
    //     {
    //         multRes = num2[indexNum2] * num1[indexNum1] + multCarryon;
            
    //         if ( multRes >= 10 )
    //         {
    //             remainder = multRes % 10;
    //             multCarryon = multRes / 10;

    //             //Update partial result of the addition
    //              if ( updateIndex > 0 && updateIndex < result.size() )
    //              {
    //             //   updateIndex = indexNum2;  
    //                updateResult = result[updateIndex] + remainder + addCarryon;
    //                if ( updateResult >= 10 )
    //                {
    //                  result[updateIndex] = updateResult % 10;
    //                  addCarryon = updateResult / 10;
    //                }
    //                else
    //                {
    //                  result[updateIndex] = updateResult;
    //                  addCarryon = 0;
    //                }
    //                updateIndex++;
    //              }
    //              else
    //                result.push_back(remainder);
    //         }
    //         else  // multRes < 10
    //         {
    //             //Update partial result of the addition
    //              if ( updateIndex > 0 && updateIndex < result.size())
    //              {
    //             //   updateIndex = indexNum2;  
    //                updateResult = result[updateIndex] + multRes + addCarryon;
    //                if ( updateResult >= 10 )
    //                {
    //                  result[updateIndex] = updateResult % 10;
    //                  addCarryon = updateResult / 10;
    //                }
    //                else
    //                {
    //                  result[updateIndex] = updateResult;
    //                  addCarryon = 0;
    //                }
    //                updateIndex++;
    //              }
    //              else
    //                result.push_back(multRes + addCarryon);


    //             multCarryon = 0;
    //         }
    //         indexNum1++;
    //     } // inner while
    //     if ( multCarryon > 0)
    //        result.push_back(multCarryon);

    //     indexNum2++;
    // }

    // int cont = result.size() - 1;
    // while (cont >= 0  )
    // {
    //       cout << result[cont];
    //       cont--;
    // }
    

    return 1;
}