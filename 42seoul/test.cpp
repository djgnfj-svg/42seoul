
#include <iostream>

int sum_string(std::string *temp, int len)
{
   int sum;
   sum = 0;
   for (int i=0; i<len; i++)
   {
      sum += std::stoi(temp[i]);
   }
   return sum;
}
s
int main(void)
{
   int N;
   int temp_N = N;
   int M;
   int len;
   M= 0;
   int sum = 0;
   std::string temp[7];
   for (int i=0; i<N; i++)
   {
      while(temp_N<0)
      {
         temp_N / 10;
         len++;
      }
      std::string cut_i = std::to_string(i);
      for (int j=0; j<len; j++)
         temp[j] = cut_i[j];

      sum = i + sum_string(temp, len);
      if (sum == N)
         prub
   }
}