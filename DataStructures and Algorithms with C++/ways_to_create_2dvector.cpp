#include <iostream>
#include <vector>

template<typename T>
void Print2DVector(std::vector<std::vector<T>> const&);

int main()
{
   // creating a sized vector
   std::vector<int> aVec(5);
   std::cout << aVec.size() << '\n';

   for (int itr = 0; itr < aVec.size(); itr++)
   {
      std::cout << aVec[itr] << ' ';
   }
   std::cout << "\n\n";

   // creating a sized vector filled with a value other than zero
   std::vector<int> aVec2(5, 100);
   std::cout << aVec2.size() << '\n';

   for (auto itr : aVec2)
   {
      std::cout << itr << ' ';
   }
   std::cout << "\n\n";

   std::cout << "Creating a 2-dimensional vector, enter row size: ";
   int row_size;
   std::cin >> row_size;

   std::cout << "Enter column size: ";
   int col_size;
   std::cin >> col_size;

   std::cout << "\n";

   // create a 2 dimensional int vector with known dimensions
   std::vector<std::vector<int>> aVector(row_size, std::vector<int>(col_size));

   // initialize the vector with some values other than zero
   for (int row_loop = 0; row_loop < row_size; row_loop++)
   {
      for (int col_loop = 0; col_loop < col_size; col_loop++)
      {
         aVector[row_loop][col_loop] = (((row_loop + 1) * 100) + col_loop + 1);
      }
   }

   // let's display the filled 2D vector
   Print2DVector(aVector);
}

template<typename T>
void Print2DVector(std::vector<std::vector<T>> const& aVec)
{
   int row_size = aVec.size();
   int col_size = aVec[0].size();

   for (int row_loop = 0; row_loop < row_size; row_loop++)
   {
      for (int col_loop = 0; col_loop < col_size; col_loop++)
      {
         // let's display the filled 2D vector
         std::cout << aVec[row_loop][col_loop] << ' ';
      }
      std::cout << '\n';
   }
}


/*

output : - 

5
0 0 0 0 0

5
100 100 100 100 100

Creating a 2-dimensional vector, enter row size: 3
Enter column size: 5

101 102 103 104 105
201 202 203 204 205
301 302 303 304 305
*/